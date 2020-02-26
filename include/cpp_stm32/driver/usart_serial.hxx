// Copyright (c) 2020 by osjacky430.
// All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the Lesser GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// Lesser GNU General Public License for more details.
//
// You should have received a copy of the Lesser GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <array>
#include <charconv>
#include <string_view>
#include <tuple>
#include <utility>

#include "cpp_stm32/common/usart.hxx"
#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/driver/gpio_base.hxx"
#include "cpp_stm32/hal/callback.hxx"
#include "cpp_stm32/utility/macro.hxx"
#include "cpp_stm32/utility/serial.hxx"

// target specific include
#include "device.hxx"

/**
 * @namespace 	cpp_stm32::driver
 */
namespace cpp_stm32::driver {

/**
 * @class 	UsartTx
 * @brief		This class is used for static checking to check whether the input pin is available or not
 */
template <gpio::PinName TX>
struct UsartTx {
	static constexpr auto TX_USART_NUM = std::get<0>(usart::PinMap::getTxPinData<TX>());
	static constexpr auto TX_AF				 = std::get<1>(usart::PinMap::getTxPinData<TX>());
	static constexpr auto TX_USART_RCC = std::get<2>(usart::PinMap::getTxPinData<TX>());
	static constexpr auto TX_IRQ			 = std::get<3>(usart::PinMap::getTxPinData<TX>());
};

template <gpio::PinName TX>
static constexpr auto UsartTx_v = UsartTx<TX>{};

/**
 * @class 	UsartRx
 * @brief		This class is used for static checking to check whether the input pin is available or not
 */
template <gpio::PinName RX>
struct UsartRx {
	static constexpr auto RX_USART_NUM = std::get<0>(usart::PinMap::getRxPinData<RX>());
	static constexpr auto RX_AF				 = std::get<1>(usart::PinMap::getRxPinData<RX>());
	static constexpr auto RX_USART_RCC = std::get<2>(usart::PinMap::getRxPinData<RX>());
	static constexpr auto RX_IRQ			 = std::get<3>(usart::PinMap::getRxPinData<RX>());
};

template <gpio::PinName RX>
static constexpr auto UsartRx_v = UsartRx<RX>{};

/**
 *
 */
template <gpio::PinName TX, gpio::PinName RX, gpio::PinName CTS = gpio::PinName::NC,
					gpio::PinName RTS = gpio::PinName::NC>
class Usart {
 private:
	static_assert(UsartTx<TX>::TX_USART_NUM == UsartRx<RX>::RX_USART_NUM);

	static constexpr auto USART_PORT		= UsartTx<TX>::TX_USART_NUM;
	static constexpr auto USART_RCC			= UsartTx<TX>::TX_USART_RCC;
	static constexpr auto USART_GPIO_AF = UsartTx<TX>::TX_AF;
	static constexpr auto USART_IRQ_NUM = UsartTx<TX>::TX_IRQ;

	static constexpr void USART_IRQ() noexcept {}

	// static inline auto USART_CB_ARRAY = std::array<int, 2 /*tx & rx*/>{};

	/**
	 * @brief   	This function convert arithmetic type to string and output to usart
	 * @param 		t_val Value to print
	 *
	 * @note  		floating point is not supported due to gcc hasn't implemented yet
	 */
	template <typename T>
	constexpr void printValAsStr(T const t_val) const noexcept {
		constexpr auto BUFFER_SIZE = 10;
		std::array<char, BUFFER_SIZE> str{};

		if (auto [p, ec] = std::to_chars(str.data(), str.data() + str.size(), t_val); ec == std::errc()) {
			for (auto const& val : std::string_view(str.data(), p - str.data())) {
				usart::send_blocking<USART_PORT>(static_cast<std::uint8_t>(val));
			}
		}
	}

 public:
	explicit constexpr Usart(usart::Baudrate_t const& t_baud) noexcept {}

	explicit constexpr Usart(UsartTx<TX> const /*unused*/, UsartRx<RX> const /*unused*/,
													 usart::Baudrate_t const t_baud) noexcept {
		using gpio::Pupd;
		using usart::StopBit_v, usart::DataBit, usart::Parity, usart::HardwareFlowControl, usart::Stopbit;

		rcc::enable_periph_clk<USART_RCC>();

		GpioUtil<TX, RX>::enableAllGpioClk();
		GpioUtil<TX, RX>::modeSetup(gpio::Mode::AltFunc, Pupd::PullUp);
		GpioUtil<TX, RX>::alternateFuncSetup(USART_GPIO_AF);

		usart::set_baudrate<USART_PORT>(t_baud);
		usart::set_dps<USART_PORT>(DataBit::DataBit8, Parity::None, StopBit_v<Stopbit::Bit1>);

		usart::set_transfer_mode<USART_PORT>(usart::Mode::TxRx);
		usart::set_hardware_flow_ctl<USART_PORT>(HardwareFlowControl::None);

		usart::enable<USART_PORT>();
	}

	constexpr auto sendable() const noexcept { return usart::is_tx_empty<USART_PORT>(); }

	constexpr auto receivable() const noexcept { return usart::is_rx_empty<USART_PORT>(); }

	template <std::uint8_t BC = 1, bool Wait = false>
	[[nodiscard]] constexpr auto receive([[maybe_unused]] ByteCount<BC> const& t_bc	 = 1_byte,
																			 [[maybe_unused]] Waiting_t<Wait> const& t_w = Waiting<false>) const noexcept {
		std::array<std::uint8_t, BC> ret_val{};
		detail::generate(ret_val.begin(), ret_val.end(),
										 []() { return Wait ? usart::receive_blocking<USART_PORT>() : usart::receive<USART_PORT>(); });
		return ret_val;
	}

	template <typename T, typename = std::enable_if_t<!std::is_pointer_v<T>>>
	constexpr void send(T const t_val) const noexcept {
		if constexpr (std::is_same_v<T, char>) {
			usart::send_blocking<USART_PORT>(static_cast<std::uint8_t>(t_val));
		} else {
			printValAsStr(t_val);
		}
	}

	constexpr void send(std::string_view const t_str) const noexcept {
		for (auto const& val : t_str) {
			usart::send_blocking<USART_PORT>(static_cast<std::uint8_t>(val));
		}
	}

	template <typename T>
	constexpr void send(Serializable<T> const t_val) const noexcept {
		for (auto const& val : t_val.serialize()) {
			usart::send_blocking<USART_PORT>(static_cast<std::uint8_t>(val));
		}
	}

	template <typename T, typename = std::enable_if_t<!std::is_pointer_v<T>>>
	constexpr auto operator<<(T const t_val) const noexcept {
		if constexpr (std::is_same_v<T, char>) {
			usart::send_blocking<USART_PORT>(static_cast<std::uint8_t>(t_val));
		} else {
			printValAsStr(t_val);
		}

		return *this;
	}

	constexpr auto operator<<(std::string_view const t_str) const noexcept {
		for (auto const& val : t_str) {
			usart::send_blocking<USART_PORT>(static_cast<std::uint8_t>(val));
		}

		return *this;
	}

	template <typename T>
	constexpr auto operator<<(Serializable<T> const t_struct) const noexcept {
		for (auto const& val : t_struct.serialize()) {
			usart::send_blocking<USART_PORT>(static_cast<std::uint8_t>(val));
		}

		return *this;
	}

	template <auto F>
	constexpr void attachTxeIRQ(Callback<F> const& t_cb) const noexcept {
		nvic::enable_irq<USART_IRQ_NUM>(Callback<USART_IRQ>{});
		usart::enable_txe_irq<USART_PORT>();
		// register callback to callback array
	}
};

}	 // namespace cpp_stm32::driver
