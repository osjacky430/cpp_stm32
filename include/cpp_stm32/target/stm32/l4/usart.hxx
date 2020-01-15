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

#include <cstdint>
#include <type_traits>

#include "cpp_stm32/common/usart_common.hxx"
#include "cpp_stm32/target/stm32/l4/memory/usart_reg.hxx"
#include "cpp_stm32/target/stm32/l4/sys_init.hxx"

namespace cpp_stm32::usart {

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
enum class DataBit : std::uint8_t { DataBit8, DataBit9, DataBit7 };

enum class HardwareFlowControl : std::uint8_t { None, CTS, RTS, Both };
enum class Mode : std::uint8_t { RxOnly = 1, TxOnly, TxRx };
enum class Parity : std::uint8_t { Even, Odd, None };
enum class Stopbit : std::uint8_t { Bit1, Bit0f5, Bit2, Bit1f5 };

}	 // namespace cpp_stm32::usart

namespace cpp_stm32::stm32::l4 {

template <usart::Stopbit StopBit>
using StopBit_t = std::integral_constant<decltype(StopBit), StopBit>;

template <usart::Stopbit StopBit>
static constexpr StopBit_t<StopBit> StopBit_v{};

template <UsartNum Port>
constexpr auto set_baudrate(usart::Baudrate_t const& t_baud) noexcept {
	constexpr auto clk_freq = (Port == UsartNum::Usart1 ? APB2_CLK_FREQ : APB1_CLK_FREQ);

	std::uint16_t const usart_div =
		(clk_freq + t_baud.get() / 2) / t_baud.get();	 // round (avoiding floating point arithmetic)

	USART_BRR<Port>.template setBit<UsartBrrBit::Brr>(usart_div);
}

template <UsartNum Port>
constexpr void set_databit(usart::DataBit const& t_d_bit) noexcept {
	std::uint8_t const m1 = (to_underlying(t_d_bit) & 0b10) != 0;
	std::uint8_t const m0 = (to_underlying(t_d_bit) & 0b01);

	auto const val_to_write = BitGroup{m1, m0};
	USART_CR1<Port>.template setBit<UsartCr1Bit::M1, UsartCr1Bit::M0>(val_to_write);
}

template <UsartNum Port>
constexpr void set_hardware_flow_ctl(usart::HardwareFlowControl const& t_flow_ctl) noexcept {
	// @todo : static_assert (UART4 and UART5)
	using usart::HardwareFlowControl;
	// maybe we can set these two bits to t_flow_ctl, as long as we assign special enum value
	// so that t_flow_ctl & mask = 1 when t_flow_ctl = cts or rts, and t_flow_ctl & mask = 0 when
	// t_flow_ctl = none, e.g. ctl = 1, rts = 3, none = 4
	std::uint8_t const cts	= (to_underlying(t_flow_ctl) & to_underlying(HardwareFlowControl::CTS)) != 0;
	std::uint8_t const rts	= (to_underlying(t_flow_ctl) & to_underlying(HardwareFlowControl::RTS)) != 0;
	auto const val_to_write = BitGroup{rts, cts};
	USART_CR3<Port>.template setBit<UsartCr3Bit::RTSE, UsartCr3Bit::CTSE>(val_to_write);
}

template <UsartNum Port>
constexpr void set_transfer_mode(usart::Mode const& t_mode) noexcept {
	using usart::Mode;

	std::uint8_t const txe	= (to_underlying(t_mode) & to_underlying(Mode::TxOnly)) != 0;
	std::uint8_t const rxe	= (to_underlying(t_mode) & to_underlying(Mode::RxOnly)) != 0;
	auto const val_to_write = BitGroup{txe, rxe};
	USART_CR1<Port>.template setBit<UsartCr1Bit::TE, UsartCr1Bit::RE>(val_to_write);
}

template <UsartNum Port>
constexpr void set_parity(usart::Parity const& t_parity) noexcept {
	using usart::Parity;

	std::uint8_t const pe		= (t_parity != Parity::None);
	auto const val_to_write = BitGroup{pe, t_parity};
	USART_CR1<Port>.template setBit<UsartCr1Bit::PCE, UsartCr1Bit::PS>(val_to_write);
}

template <UsartNum Port, usart::Stopbit StopBit>
constexpr void set_stopbit(StopBit_t<StopBit> const& /*unused*/) noexcept {
	// static_assert()
	USART_CR2<Port>.template setBit<UsartCr2Bit::Stop>(StopBit);
}

template <UsartNum Port>
constexpr void send(std::uint8_t const& t_data) noexcept {
	USART_TDR<Port>.template setBit<UsartTDrBit::TDr>(t_data);
}

template <UsartNum Port>
constexpr auto receive() noexcept {
	return get<0>(USART_RDR<Port>.template readBit<UsartRDrBit::RDr>(ValueOnly));
}

template <UsartNum Port>
constexpr auto is_tx_empty() noexcept {
	// 0: data is not transferred to shift register
	// 1: data is transferred to shift register
	return get<0>(USART_ISR<Port>.template readBit<UsartISrBit::TxE>(ValueOnly)) != 0;
}

template <UsartNum Port>
constexpr auto is_rx_empty() noexcept {
	return get<0>(USART_ISR<Port>.template readBit<UsartISrBit::RxNE>(ValueOnly)) == 0;
}

template <UsartNum Port>
constexpr auto wait_rx_not_empty() noexcept {
	while (is_rx_empty<Port>()) {
	}
}

template <UsartNum Port>
constexpr void wait_tx_rdy() noexcept {
	while (!is_tx_empty<Port>()) {
	}
}

template <UsartNum Port>
constexpr auto send_blocking(std::uint8_t const& t_data) noexcept {
	send<Port>(t_data);
	wait_tx_rdy<Port>();
}

template <UsartNum Port>
constexpr void enable() noexcept {
	USART_CR1<Port>.template setBit<UsartCr1Bit::UE>();
}

template <UsartNum Port, usart::Stopbit Stop>
constexpr void set_dps(usart::DataBit const& t_d, usart::Parity const& t_p,
											 StopBit_t<Stop> const& /*unused*/) noexcept {
	using usart::Parity;

	std::uint8_t const pe = (t_p != Parity::None);
	std::uint8_t const d1 = (to_underlying(t_d) & 0b10) != 0;
	std::uint8_t const d0 = (to_underlying(t_d) & 0b01);

	auto const val_to_write = BitGroup{d1, d0, pe, t_p};
	USART_CR1<Port>.template setBit<UsartCr1Bit::M1, UsartCr1Bit::M0, UsartCr1Bit::PCE, UsartCr1Bit::PS>(val_to_write);
	USART_CR2<Port>.template setBit<UsartCr2Bit::Stop>(Stop);
}

template <UsartNum Port>
constexpr void enable_txe_irq() noexcept {
	USART_CR1<Port>.template setBit<UsartCr1Bit::TxEIE>();
}

template <UsartNum Port, UsartIcrBit flag>
constexpr void clear_flag() noexcept {
	USART_ICR<Port>.template setBit<flag>();
}

}	 // namespace cpp_stm32::stm32::l4
