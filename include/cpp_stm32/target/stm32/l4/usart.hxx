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

#include "cpp_stm32/common/usart.hxx"
#include "cpp_stm32/target/stm32/l4/memory/usart_reg.hxx"
#include "cpp_stm32/target/stm32/l4/sys_init.hxx"

namespace cpp_stm32::usart {

/**
 * [set_baudrate description]
 * @param  t_baud [description]
 * @return        [description]
 */
template <Port InputPort>
constexpr auto set_baudrate(usart::Baudrate_t const& t_baud) noexcept {
	constexpr auto clk_freq = (InputPort == Port::Usart1 ? APB2_CLK_FREQ : APB1_CLK_FREQ);

	std::uint16_t const usart_div =
		(clk_freq + t_baud.get() / 2) / t_baud.get();	 // round (avoiding floating point arithmetic)

	reg::BRR<InputPort>.template setBit<reg::BrrBit::Brr>(usart_div);
}

template <Port InputPort>
constexpr void set_databit(usart::DataBit const& t_d_bit) noexcept {
	std::uint8_t const m1 = (to_underlying(t_d_bit) & 0b10) != 0;
	std::uint8_t const m0 = (to_underlying(t_d_bit) & 0b01);

	auto const val_to_write = BitGroup{m1, m0};
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::M1, reg::Cr1Bit::M0>(val_to_write);
}

template <Port InputPort>
constexpr void set_hardware_flow_ctl(usart::HardwareFlowControl const& t_flow_ctl) noexcept {
	// @todo : static_assert (UART4 and UART5)
	using usart::HardwareFlowControl;
	// maybe we can set these two bits to t_flow_ctl, as long as we assign special enum value
	// so that t_flow_ctl & mask = 1 when t_flow_ctl = cts or rts, and t_flow_ctl & mask = 0 when
	// t_flow_ctl = none, e.g. ctl = 1, rts = 3, none = 4
	std::uint8_t const cts	= (to_underlying(t_flow_ctl) & to_underlying(HardwareFlowControl::CTS)) != 0;
	std::uint8_t const rts	= (to_underlying(t_flow_ctl) & to_underlying(HardwareFlowControl::RTS)) != 0;
	auto const val_to_write = BitGroup{rts, cts};
	reg::CR3<InputPort>.template setBit<reg::Cr3Bit::RTSE, reg::Cr3Bit::CTSE>(val_to_write);
}

template <Port InputPort>
constexpr void set_transfer_mode(usart::Mode const& t_mode) noexcept {
	using usart::Mode;

	std::uint8_t const txe	= (to_underlying(t_mode) & to_underlying(Mode::TxOnly)) != 0;
	std::uint8_t const rxe	= (to_underlying(t_mode) & to_underlying(Mode::RxOnly)) != 0;
	auto const val_to_write = BitGroup{txe, rxe};
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::TE, reg::Cr1Bit::RE>(val_to_write);
}

template <Port InputPort>
constexpr void set_parity(usart::Parity const& t_parity) noexcept {
	using usart::Parity;

	std::uint8_t const pe		= (t_parity != Parity::None);
	auto const val_to_write = BitGroup{pe, t_parity};
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::PCE, reg::Cr1Bit::PS>(val_to_write);
}

template <Port InputPort, usart::Stopbit StopBit>
constexpr void set_stopbit(StopBit_t<StopBit> const& /*unused*/) noexcept {
	// static_assert()
	reg::CR2<InputPort>.template setBit<reg::Cr2Bit::Stop>(StopBit);
}

template <Port InputPort>
constexpr void send(std::uint8_t const& t_data) noexcept {
	reg::TDR<InputPort>.template setBit<reg::TDrBit::TDr>(t_data);
}

template <Port InputPort>
constexpr auto receive() noexcept {
	return get<0>(reg::RDR<InputPort>.template readBit<reg::RDrBit::RDr>(ValueOnly));
}

template <Port InputPort>
constexpr auto is_tx_empty() noexcept {
	// 0: data is not transferred to shift register
	// 1: data is transferred to shift register
	return get<0>(reg::ISR<InputPort>.template readBit<reg::ISrBit::TxE>(ValueOnly)) != 0;
}

template <Port InputPort>
constexpr auto is_rx_empty() noexcept {
	return get<0>(reg::ISR<InputPort>.template readBit<reg::ISrBit::RxNE>(ValueOnly)) == 0;
}

template <Port InputPort>
constexpr auto wait_rx_not_empty() noexcept {
	while (is_rx_empty<InputPort>()) {
	}
}

template <Port InputPort>
constexpr void wait_tx_rdy() noexcept {
	while (!is_tx_empty<InputPort>()) {
	}
}

template <Port InputPort>
constexpr auto send_blocking(std::uint8_t const& t_data) noexcept {
	send<InputPort>(t_data);
	wait_tx_rdy<InputPort>();
}

template <Port InputPort>
constexpr void enable() noexcept {
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::UE>();
}

template <Port InputPort, usart::Stopbit Stop>
constexpr void set_dps(usart::DataBit const& t_d, usart::Parity const& t_p,
											 StopBit_t<Stop> const& /*unused*/) noexcept {
	using usart::Parity;

	std::uint8_t const pe = (t_p != Parity::None);
	std::uint8_t const d1 = (to_underlying(t_d) & 0b10) != 0;
	std::uint8_t const d0 = (to_underlying(t_d) & 0b01);

	auto const val_to_write = BitGroup{d1, d0, pe, t_p};
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::M1, reg::Cr1Bit::M0, reg::Cr1Bit::PCE, reg::Cr1Bit::PS>(
		val_to_write);
	reg::CR2<InputPort>.template setBit<reg::Cr2Bit::Stop>(Stop);
}

template <Port InputPort>
constexpr void enable_txe_irq() noexcept {
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::TxEIE>();
}

template <Port InputPort, reg::IcrBit flag>
constexpr void clear_flag() noexcept {
	reg::ICR<InputPort>.template setBit<flag>();
}

}	 // namespace cpp_stm32::usart
