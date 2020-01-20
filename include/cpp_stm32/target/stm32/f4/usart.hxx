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

#include "cpp_stm32/common/usart.hxx"
#include "cpp_stm32/target/stm32/f4/memory/usart_reg.hxx"

#include "sys_info.hpp"

namespace cpp_stm32::usart {

template <Port InputPort>
constexpr auto set_baudrate(Baudrate_t const& t_baud) noexcept {
	constexpr auto clk_freq = (InputPort == Port::Usart1 || InputPort == Port::Usart6 ? APB2_CLK_FREQ : APB1_CLK_FREQ);

	auto const usart_div = (clk_freq + t_baud.get() / 2) / t_baud.get();	// round (avoiding floating point arithmetic)
	std::uint16_t const mantissa = usart_div >> 4;
	std::uint8_t const fraction	 = usart_div & 0xF;

	reg::BRR<InputPort>.template setBit<reg::BrrBit::DivFraction, reg::BrrBit::DivMantissa>(fraction, mantissa);
}

template <Port InputPort>
constexpr void set_databit(DataBit const& t_d_bit) noexcept {
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::M>(t_d_bit);
}

template <Port InputPort>
constexpr void set_hardware_flow_ctl(HardwareFlowControl const& t_flow_ctl) noexcept {
	// @todo : static_assert (UART4 and UART5)
	// maybe we can set these two bits to t_flow_ctl, as long as we assign special enum value
	// so that t_flow_ctl & mask = 1 when t_flow_ctl = cts or rts, and t_flow_ctl & mask = 0 when
	// t_flow_ctl = none, e.g. ctl = 1, rts = 3, none = 4
	std::uint8_t const cts = (to_underlying(t_flow_ctl) & to_underlying(HardwareFlowControl::CTS)) != 0;
	std::uint8_t const rts = (to_underlying(t_flow_ctl) & to_underlying(HardwareFlowControl::RTS)) != 0;

	reg::CR3<InputPort>.template setBit<reg::Cr3Bit::RTSE, reg::Cr3Bit::CTSE>(cts, rts);
}

template <Port InputPort>
constexpr void set_transfer_mode(Mode const& t_mode) noexcept {
	std::uint8_t const tx_en = (to_underlying(t_mode) & to_underlying(Mode::TxOnly)) != 0;
	std::uint8_t const rx_en = (to_underlying(t_mode) & to_underlying(Mode::RxOnly)) != 0;

	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::TE, reg::Cr1Bit::RE>(tx_en, rx_en);
}

template <Port InputPort>
constexpr void set_parity(Parity const& t_parity) noexcept {
	std::uint8_t const pe = (t_parity != Parity::None);
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::PCE, reg::Cr1Bit::PS>(pe, t_parity);
}

template <Port InputPort, Stopbit StopBit>
constexpr void set_stopbit(StopBit_t<StopBit> const& /*unused*/) noexcept {
	// static_assert()
	reg::CR2<InputPort>.template setBit<reg::Cr2Bit::Stop>(StopBit);
}

template <Port InputPort>
constexpr void send(std::uint8_t const& data) noexcept {
	reg::DR<InputPort>.template setBit<reg::DrBit::Dr>(data);
}

template <Port InputPort>
constexpr auto receive() noexcept {
	return get<0>(reg::DR<InputPort>.template readBit<reg::DrBit::Dr>(ValueOnly));
}

template <Port InputPort>
constexpr auto is_tx_empty() noexcept {
	// 0: data is not transferred to shift register
	// 1: data is transferred to shift register
	return get<0>(reg::SR<InputPort>.template readBit<reg::SrBit::TxE>(ValueOnly)) != 0;
}

template <Port InputPort>
constexpr auto is_rx_empty() noexcept {
	return get<0>(reg::SR<InputPort>.template readBit<reg::SrBit::RxNE>(ValueOnly)) == 0;
}

template <Port InputPort>
constexpr void enable() noexcept {
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::UE>();
}

template <Port InputPort>
constexpr void wait_tx_rdy() noexcept {
	while (!is_tx_empty<InputPort>()) {
	}
}

template <Port InputPort>
constexpr void wait_rx_not_empty() noexcept {
	while (is_rx_empty<InputPort>()) {
	}
}

template <Port InputPort>
constexpr void send_blocking(std::uint8_t const& t_data) noexcept {
	send<InputPort>(t_data);
	wait_tx_rdy<InputPort>();
}

// @todo this should be sfinae instead of static assert?
// @todo the interface should unify, StopBit_t here makes it hard to do so.
template <Port InputPort, usart::Stopbit Stop>
constexpr void set_dps(DataBit const& t_d, Parity const& t_p, StopBit_t<Stop> const& /*unused*/) noexcept {
	std::uint8_t const pe = (t_p != Parity::None);
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::M, reg::Cr1Bit::PCE, reg::Cr1Bit::PS>(t_d, pe, t_p);
	reg::CR2<InputPort>.template setBit<reg::Cr2Bit::Stop>(Stop);
}

template <Port InputPort>
constexpr void enable_txe_irq() noexcept {
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::TxEIE>();
}

}	 // namespace cpp_stm32::usart
