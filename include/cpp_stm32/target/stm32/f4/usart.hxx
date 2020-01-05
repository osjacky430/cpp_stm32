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

#include "cpp_stm32/common/usart_common.hxx"
#include "cpp_stm32/target/stm32/f4/memory/usart_reg.hxx"
#include "cpp_stm32/target/stm32/f4/sys_init.hxx"

namespace cpp_stm32::common {

/**
 * @enum OverSampling
 */
enum class OverSampling : std::uint8_t {
	OverSampling16,
	OverSampling8,
};

/**
 * @enum 	DataBit
 */
enum class DataBit : std::uint8_t { DataBit8, DataBit9 };

enum class HardwareFlowControl : std::uint8_t { None, CTS, RTS, Both };
enum class UsartMode : std::uint8_t { RxOnly = 1, TxOnly, TxRx };
enum class UsartParity : std::uint8_t { Even, Odd, None };
enum class UsartStopbit : std::uint8_t { Bit1, Bit0f5, Bit2, Bit1f5 };

}	 // namespace cpp_stm32::common

namespace cpp_stm32::stm32::f4 {

template <common::UsartStopbit StopBit>
using StopBit_t = std::integral_constant<decltype(StopBit), StopBit>;

template <common::UsartStopbit StopBit>
static constexpr StopBit_t<StopBit> StopBit_v{};

template <UsartNum Port>
constexpr auto usart_set_baudrate(common::Baudrate_t const& t_baud) noexcept {
	constexpr auto clk_freq = (Port == UsartNum::Usart1 || Port == UsartNum::Usart6 ? APB2_CLK_FREQ : APB1_CLK_FREQ);

	auto const usart_div = (clk_freq + t_baud.get() / 2) / t_baud.get();	// round (avoiding floating point arithmetic)
	std::uint16_t const mantissa = usart_div >> 4;
	std::uint8_t const fraction	 = usart_div & 0xF;
	auto const val_to_write			 = BitGroup{fraction, mantissa};
	USART_BRR<Port>.template setBit<UsartBrrBit::DivFraction, UsartBrrBit::DivMantissa>(val_to_write);
}

template <UsartNum Port>
constexpr void usart_set_databit(common::DataBit const& t_d_bit) noexcept {
	USART_CR1<Port>.template setBit<UsartCr1Bit::M>(t_d_bit);
}

template <UsartNum Port>
constexpr void usart_set_hardware_flow_ctl(common::HardwareFlowControl const& t_flow_ctl) noexcept {
	// @todo : static_assert (UART4 and UART5)
	using common::HardwareFlowControl;
	// maybe we can set these two bits to t_flow_ctl, as long as we assign special enum value
	// so that t_flow_ctl & mask = 1 when t_flow_ctl = cts or rts, and t_flow_ctl & mask = 0 when
	// t_flow_ctl = none, e.g. ctl = 1, rts = 3, none = 4
	std::uint8_t const cts	= (to_underlying(t_flow_ctl) & to_underlying(HardwareFlowControl::CTS)) != 0;
	std::uint8_t const rts	= (to_underlying(t_flow_ctl) & to_underlying(HardwareFlowControl::RTS)) != 0;
	auto const val_to_write = BitGroup{rts, cts};
	USART_CR3<Port>.template setBit<UsartCr3Bit::RTSE, UsartCr3Bit::CTSE>(val_to_write);
}

template <UsartNum Port>
constexpr void usart_set_transfer_mode(common::UsartMode const& t_mode) noexcept {
	using common::UsartMode;

	std::uint8_t const txe	= (to_underlying(t_mode) & to_underlying(UsartMode::TxOnly)) != 0;
	std::uint8_t const rxe	= (to_underlying(t_mode) & to_underlying(UsartMode::RxOnly)) != 0;
	auto const val_to_write = BitGroup{txe, rxe};
	USART_CR1<Port>.template setBit<UsartCr1Bit::TE, UsartCr1Bit::RE>(val_to_write);
}

template <UsartNum Port>
constexpr void usart_set_parity(common::UsartParity const& t_parity) noexcept {
	using common::UsartParity;

	std::uint8_t const pe		= (t_parity != UsartParity::None);
	auto const val_to_write = BitGroup{pe, t_parity};
	USART_CR1<Port>.template setBit<UsartCr1Bit::PCE, UsartCr1Bit::PS>(val_to_write);
}

template <UsartNum Port, common::UsartStopbit StopBit>
constexpr void usart_set_stopbit(StopBit_t<StopBit> const& /*unused*/) noexcept {
	// static_assert()
	USART_CR2<Port>.template setBit<UsartCr2Bit::Stop>(StopBit);
}

template <UsartNum Port>
constexpr void usart_send(std::uint8_t const& data) noexcept {
	USART_DR<Port>.template setBit<UsartDrBit::Dr>(data);
}

template <UsartNum Port>
constexpr auto usart_receive() noexcept {
	return get<0>(USART_DR<Port>.template readBit<UsartDrBit::Dr>(ValueOnly));
}

template <UsartNum Port>
constexpr auto usart_is_tx_empty() noexcept {
	// 0: data is not transferred to shift register
	// 1: data is transferred to shift register
	return get<0>(USART_SR<Port>.template readBit<UsartSrBit::TxE>(ValueOnly)) != 0;
}

template <UsartNum Port>
constexpr auto usart_is_rx_empty() noexcept {
	return get<0>(USART_SR<Port>.template readBit<UsartSrBit::RxNE>(ValueOnly)) == 0;
}

template <UsartNum Port>
constexpr void usart_enable() noexcept {
	USART_CR1<Port>.template setBit<UsartCr1Bit::UE>();
}

template <UsartNum Port>
constexpr void usart_wait_tx_rdy() noexcept {
	while (!usart_is_tx_empty<Port>()) {
	}
}

template <UsartNum Port>
constexpr void usart_wait_rx_not_empty() noexcept {
	while (usart_is_rx_empty<Port>()) {
	}
}

template <UsartNum Port>
constexpr void usart_send_blocking(std::uint8_t const& t_data) noexcept {
	usart_send<Port>(t_data);
	usart_wait_tx_rdy<Port>();
}

// @todo this should be sfinae instead of static assert?
// @todo the interface should unify, StopBit_t here makes it hard to do so.
template <UsartNum Port, common::UsartStopbit Stop>
constexpr void usart_set_dps(common::DataBit const& t_d, common::UsartParity const& t_p,
														 StopBit_t<Stop> const& /*unused*/) noexcept {
	using common::UsartParity;

	std::uint8_t const pe		= (t_p != UsartParity::None);
	auto const val_to_write = BitGroup{t_d, pe, t_p};
	USART_CR1<Port>.template setBit<UsartCr1Bit::M, UsartCr1Bit::PCE, UsartCr1Bit::PS>(val_to_write);
	USART_CR2<Port>.template setBit<UsartCr2Bit::Stop>(Stop);
}

template <UsartNum Port>
constexpr void usart_enable_txe_irq() noexcept {
	USART_CR1<Port>.template setBit<UsartCr1Bit::TxEIE>();
}

}	 // namespace cpp_stm32::stm32::f4
