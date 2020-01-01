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

#include <string_view>
#include <tuple>
#include <utility>

#include "cpp_stm32/driver/gpio_base.hxx"
#include "cpp_stm32/processor/cortex_m4/nvic.hxx"	 // @todo change
#include "cpp_stm32/target/stm32/f4/interrupt.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/usart.hxx"
#include "cpp_stm32/utility/callback.hxx"
#include "cpp_stm32/utility/constexpr_algo.hxx"
#include "cpp_stm32/utility/serial.hxx"

class UsartPinMap {
 private:
	using UsartAltFuncGroup = std::tuple<UsartNum, GpioAltFunc, RccPeriph, IrqNum>;

	// this is not the best way of doing it
	static constexpr auto TX_PIN_MAP = std::array{
		std::pair{PinName::PA_2,
							UsartAltFuncGroup{UsartNum::Usart2, GpioAltFunc::AF7, RccPeriph::Usart2, IrqNum::Usart2Global}},
	};

	static constexpr auto RX_PIN_MAP = std::array{
		std::pair{PinName::PA_3,
							UsartAltFuncGroup{UsartNum::Usart2, GpioAltFunc::AF7, RccPeriph::Usart2, IrqNum::Usart2Global}},
	};

	static constexpr auto USART_PIN_MAP = std::tuple{TX_PIN_MAP, RX_PIN_MAP};

 public:
	enum class PinInfo { Tx, Rx };

	template <PinName Pin, PinInfo Idx>
	static constexpr auto getPinInfo() noexcept {
		constexpr auto PIN_MAP = std::get<to_underlying(Idx)>(USART_PIN_MAP);
		const auto iter_pos =
			cstd::find_if(PIN_MAP.begin(), PIN_MAP.end(), [](auto const& t_pair) { return (t_pair.first == Pin); });

		return iter_pos->second;
	};
};

template <PinName TX>
struct UsartTx {
	static constexpr auto TX_USART_NUM = std::get<0>(UsartPinMap::getPinInfo<TX, UsartPinMap::PinInfo::Tx>());
	static constexpr auto TX_AF				 = std::get<1>(UsartPinMap::getPinInfo<TX, UsartPinMap::PinInfo::Tx>());
	static constexpr auto TX_USART_RCC = std::get<2>(UsartPinMap::getPinInfo<TX, UsartPinMap::PinInfo::Tx>());
	static constexpr auto TX_IRQ			 = std::get<3>(UsartPinMap::getPinInfo<TX, UsartPinMap::PinInfo::Tx>());
};

template <PinName TX>
static constexpr auto UsartTx_v = UsartTx<TX>{};

template <PinName RX>
struct UsartRx {
	static constexpr auto RX_USART_NUM = std::get<0>(UsartPinMap::getPinInfo<RX, UsartPinMap::PinInfo::Rx>());
	static constexpr auto RX_AF				 = std::get<1>(UsartPinMap::getPinInfo<RX, UsartPinMap::PinInfo::Rx>());
	static constexpr auto RX_USART_RCC = std::get<2>(UsartPinMap::getPinInfo<RX, UsartPinMap::PinInfo::Rx>());
	static constexpr auto RX_IRQ			 = std::get<3>(UsartPinMap::getPinInfo<RX, UsartPinMap::PinInfo::Rx>());
};

template <PinName RX>
static constexpr auto UsartRx_v = UsartRx<RX>{};

template <PinName TX, PinName RX, PinName CTS = PinName::NC, PinName RTS = PinName::NC>
class Usart {
 private:
	static_assert(UsartTx<TX>::TX_USART_NUM == UsartRx<RX>::RX_USART_NUM);

	static constexpr auto USART_PORT		= UsartTx<TX>::TX_USART_NUM;
	static constexpr auto USART_RCC			= UsartTx<TX>::TX_USART_RCC;
	static constexpr auto USART_GPIO_AF = UsartTx<TX>::TX_AF;
	static constexpr auto USART_IRQ_NUM = UsartTx<TX>::TX_IRQ;

 public:
	explicit constexpr Usart(std::uint64_t const& t_baud) noexcept {}

	explicit constexpr Usart(UsartTx<TX> const& /*unused*/, UsartRx<RX> const& /*unused*/,
													 std::uint64_t const& t_baud) noexcept {
		rcc_enable_periph_clk<USART_RCC>();
		//
		GpioUtil<TX, RX>::enableAllGpioClk();
		GpioUtil<TX, RX>::modeSetup(GpioMode::AltFunc, GpioPupd::None);
		GpioUtil<TX, RX>::alternateFuncSetup(USART_GPIO_AF);

		usart_set_baudrate<USART_PORT>(t_baud);
		usart_set_dps<USART_PORT>(DataBit::DataBit8, UsartParity::None, StopBit_v<UsartStopbit::Bit1>);

		usart_set_transfer_mode<USART_PORT>(UsartMode::TxRx);
		usart_set_hardware_flow_ctl<USART_PORT>(HardwareFlowControl::None);

		// small overhead here, to eliminate this overhead, change to this line
		//
		// USART_CR1<USART_PORT>.template setBit<UsartCr1Bit::TE, UsartCr1Bit::RE,
		//                                       UsartCr1Bit::UE, UsartCr1Bit::M,
		//                                       UsartCr1Bit::PCE, UsartCr1Bit::PS>(val_to_set);

		usart_enable<USART_PORT>();
	}

	constexpr auto operator<<(char const& t_val) const noexcept {
		usart_send<USART_PORT>(static_cast<std::uint8_t>(t_val));

		return *this;
	}

	constexpr auto operator<<(std::string_view const& t_str) const noexcept {
		for (auto const& val : t_str) {
			usart_send_blocking<USART_PORT>(static_cast<std::uint8_t>(val));
		}

		return *this;
	}

	template <typename T>
	constexpr auto operator<<(Serializable<T> const& t_struct) const noexcept {
		for (auto const& val : t_struct.serialize()) {
			usart_send_blocking<USART_PORT>(static_cast<std::uint8_t>(val));
		}

		return *this;
	}

	constexpr auto setTxeInterrupt() const noexcept {
		if (nvic_is_irq_enabled<USART_IRQ_NUM>()) {
			nvic_disable_irq<USART_IRQ_NUM>();
		}

		constexpr Callback<IRQ_FUNC_HANDLER[to_underlying(USART_IRQ_NUM)]> cb;
		Interrupt<USART_IRQ_NUM>::attach(cb);
		nvic_enable_irq<USART_IRQ_NUM>();
		usart_enable_txe_irq<USART_PORT>();
	}

	template <auto F>
	constexpr auto setTxeInterrupt(Callback<F> const& t_cb) const noexcept {
		if (nvic_is_irq_enabled<USART_IRQ_NUM>()) {
			nvic_disable_irq<USART_IRQ_NUM>();
		}

		Interrupt<USART_IRQ_NUM>::attach(t_cb);
		nvic_enable_irq<USART_IRQ_NUM>();
		usart_enable_txe_irq<USART_PORT>();
	}
};
