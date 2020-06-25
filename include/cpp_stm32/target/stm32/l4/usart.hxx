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
#include <tuple>
#include <type_traits>

#include "cpp_stm32/common/usart.hxx"
#include "cpp_stm32/target/stm32/l4/define/usart.hxx"
#include "cpp_stm32/target/stm32/l4/register/usart.hxx"
#include "cpp_stm32/target/stm32/l4/sys_init.hxx"
#include "cpp_stm32/utility/enum_op.hxx"

namespace cpp_stm32::usart {

/**
 * @brief	 This function sets the baudrate of USART
 * @tparam InputPort	@ref usart::Port
 * @param  t_baud 		@ref usart::Baudrate_t
 *
 */
template <Port InputPort>
constexpr void set_baudrate(Baudrate_t const t_baud) noexcept {
	constexpr auto clk_freq = InputPort == Port::Usart1 ? APB2_CLK_FREQ : APB1_CLK_FREQ;

	std::uint16_t const usart_div =
		(clk_freq + t_baud.get() / 2) / t_baud.get();	 // round (avoiding floating point arithmetic)

	reg::BRR<InputPort>.template writeBit<reg::BRRField::BRR>(usart_div);
}

/**
 * @brief		This function sets data bit of USART
 * @tparam	InputPort @ref usart::Port
 * @param 	t_d_bit 	@ref usart::DataBit
 */
template <Port InputPort>
constexpr void set_databit(DataBit const t_d_bit) noexcept {
	std::uint8_t const m1 = (to_underlying(t_d_bit) & 0b10) != 0;
	std::uint8_t const m0 = (to_underlying(t_d_bit) & 0b01);

	reg::CR1<InputPort>.template writeBit<reg::CR1Field::M1, reg::CR1Field::M0>(m1, m0);
}

/**
 * @brief 	This function sets hardware flow control of USART
 * @tparam	InputPort		@ref usart::Port
 * @param 	t_flow_ctl 	@ref usart::HardwareFlowControl
 *
 * @todo 	  static_assert (UART4 and UART5)
 * @note 	  Maybe we can set these two bits to t_flow_ctl, as long as we assign special enum value so that t_flow_ctl
 * 					mask = 1 when t_flow_ctl = cts or rts, and t_flow_ctl  mask = 0 when t_flow_ctl = none, e.g. ctl = 1, rts =
 * 					3, none = 4
 */
template <Port InputPort>
constexpr void set_hardware_flow_ctl(HardwareFlowControl const t_flow_ctl) noexcept {
	std::uint8_t const cts = (to_underlying(t_flow_ctl & HardwareFlowControl::CTS)) != 0;
	std::uint8_t const rts = (to_underlying(t_flow_ctl & HardwareFlowControl::RTS)) != 0;

	reg::CR3<InputPort>.template writeBit<reg::CR3Field::RTSE, reg::CR3Field::CTSE>(rts, cts);
}

/**
 * @brief 	This function sets transfer mode of USART
 * @tparam	InputPort @ref usart::Port
 * @param 	t_mode		@ref usart::TransferMode
 */
template <Port InputPort>
constexpr void set_transfer_mode(TransferMode const t_mode) noexcept {
	std::uint8_t const txe = to_underlying(t_mode & TransferMode::TxOnly) != 0;
	std::uint8_t const rxe = to_underlying(t_mode & TransferMode::RxOnly) != 0;

	reg::CR1<InputPort>.template writeBit<reg::CR1Field::TE, reg::CR1Field::RE>(txe, rxe);
}

/**
 * @brief 	This function sets parity of USART
 * @tparam	InputPort @ref usart::Port
 * @param 	t_parity	@ref usart::Parity
 */
template <Port InputPort>
constexpr void set_parity(Parity const t_parity) noexcept {
	std::uint8_t const pe = (t_parity != Parity::None);

	reg::CR1<InputPort>.template writeBit<reg::CR1Field::PCE, reg::CR1Field::PS>(pe, t_parity);
}

/**
 * @brief 	This function sets stopbit of USART
 * @tparam	InputPort   @ref usart::Port
 * @param 	StopBit_t		@ref usart::StopBit_t
 *
 * @todo 		static_assert	UART StopBit
 */
template <Port InputPort, Stopbit StopBit>
constexpr void set_stopbit(StopBit_t<StopBit> const /*unused*/) noexcept {
	reg::CR2<InputPort>.template writeBit<reg::CR2Field::Stop>(StopBit);
}

/**
 * @brief		This function write data to USART data register
 * @tparam	InputPort  @ref usart::Port
 * @param 	data	 8 bits data
 */
template <Port InputPort>
constexpr void send(std::uint8_t const t_data) noexcept {
	reg::TDR<InputPort>.template writeBit<reg::TDRField::TDr>(t_data);
}

/**
 * @brief		This function read data from USART data register
 * @tparam	InputPort  @ref usart::Port
 * @return  8 bits data
 */
template <Port InputPort>
[[nodiscard]] constexpr auto receive() noexcept {
	return std::get<0>(reg::RDR<InputPort>.template readBit<reg::RDRField::RDr>(ValueOnly));
}

/**
 * @brief 	This function checks if tx data register is empty
 * @tparam	InputPort  @ref usart::Port
 * @return 	true if empty, false otherwise
 *
 * @note		0: data is not transferred to shift register
 * 					1: data is transferred to shift register
 */
template <Port InputPort>
[[nodiscard]] constexpr auto is_tx_empty() noexcept {
	return std::get<0>(reg::ISR<InputPort>.template readBit<reg::ISRField::TxE>(ValueOnly)) != 0;
}

/**
 * @brief 	This function checks if rx data register is empty
 * @tparam	InputPort  @ref usart::Port
 * @return	true if empty, false otherwise
 *
 * @note 		0: data is not received (empty)
 * 					1: data is received (not empty)
 */
template <Port InputPort>
[[nodiscard]] constexpr auto is_rx_empty() noexcept {
	return std::get<0>(reg::ISR<InputPort>.template readBit<reg::ISRField::RxNE>(ValueOnly)) == 0;
}

/**
 * @brief 	This function enabels USART
 * @tparam	InputPort  @ref usart::Port
 */
template <Port InputPort>
constexpr void enable() noexcept {
	reg::CR1<InputPort>.template setBit<reg::CR1Field::UE>();
}

/**
 * @brief  	This function polls for transfer readiness
 * @tparam	InputPort  @ref usart::Port
 */
template <Port InputPort>
constexpr void wait_tx_rdy() noexcept {
	while (!is_tx_empty<InputPort>()) {
	}
}

/**
 * @brief 	This function polls for reception readiness
 * @tparam	InputPort  @ref usart::Port
 */
template <Port InputPort>
constexpr void wait_rx_not_empty() noexcept {
	while (is_rx_empty<InputPort>()) {
	}
}

/**
 * @brief 	This function polls for transmit readiness then send the data
 * @tparam	InputPort  @ref usart::Port
 * @param 	t_data 8 bits data
 */
template <Port InputPort>
constexpr void send_blocking(std::uint8_t const& t_data) noexcept {
	send<InputPort>(t_data);
	wait_tx_rdy<InputPort>();
}

/**
 * @brief 	This function polls for reception readiness then receive the data
 * @tparam	InputPort  @ref usart::Port
 * @param 	t_data 8 bits data
 */
template <Port InputPort>
constexpr auto receive_blocking() noexcept {
	wait_rx_not_empty<InputPort>();
	return std::get<0>(reg::RDR<InputPort>.template readBit<reg::RDRField::RDr>(ValueOnly));
}

/**
 * @brief   This function sets databit, parity, and stopbit of USART
 * @tparam	InputPort  @ref usart::Port
 * @param 	t_d    @ref usart::DataBit
 * @param 	t_p    @ref usart::Parity
 * @param 	@ref usart::StopBit_t
 *
 * @todo 		All strong type or all scoped enum is preferred
 */
template <Port InputPort, Stopbit Stop>
constexpr void set_dps(DataBit const t_d, Parity const t_p, StopBit_t<Stop> const /*unused*/) noexcept {
	std::uint8_t const pe = (t_p != Parity::None);
	std::uint8_t const d1 = (to_underlying(t_d) & 0b10) != 0;
	std::uint8_t const d0 = (to_underlying(t_d) & 0b01);

	reg::CR1<InputPort>.template writeBit<reg::CR1Field::M1, reg::CR1Field::M0, reg::CR1Field::PCE, reg::CR1Field::PS>(
		d1, d0, pe, t_p);
	reg::CR2<InputPort>.template writeBit<reg::CR2Field::Stop>(Stop);
}

/**
 * @brief 	This function enables USART interrupt
 * @tparam	InputPort  		@ref usart::Port
 * @tparam 	InterruptFlag	@ref usart::InterruptFlag
 */
template <Port InputPort, InterruptFlag Flag>
constexpr void enable_irq() noexcept {
	constexpr auto is_error_irq = []() {
		return Flag == InterruptFlag::FE || Flag == InterruptFlag::ORE || Flag == InterruptFlag::NF;
	};

	if constexpr (Flag == InterruptFlag::TCBGT) {
		reg::CR3<InputPort>.template setBit<reg::CR3Field::TCBGTIE>();
	} else if constexpr (Flag == InterruptFlag::WUF) {
		reg::CR3<InputPort>.template setBit<reg::CR3Field::WuSIE>();
	} else if constexpr (Flag == InterruptFlag::CTSIF) {
		reg::CR3<InputPort>.template setBit<reg::CR3Field::CTSIE>();
	} else if constexpr (is_error_irq()) {
		reg::CR3<InputPort>.template setBit<reg::CR3Field::EIE>();
	} else if constexpr (Flag == InterruptFlag::LBDF) {
		reg::CR2<InputPort>.template setBit<reg::CR2Field::LBDIE>();
	} else {
		reg::CR1<InputPort>.template setBit<reg::CR1Field{Flag}>();
	}
}

/**
 */
template <Port InputPort>
constexpr auto enable_txe_irq = enable_irq<InputPort, InterruptFlag::TXE>;

/**
 * @brief 	This function returns USART interrupt flag status
 * @tparam	InputPort  	@ref usart::Port
 * @tparam 	Flags 			@ref usart::InterruptFlag
 *
 * @todo  Finish this in the future
 */
template <Port InputPort, InterruptFlag... Flags>
[[nodiscard]] constexpr auto get_interrupt_flag() noexcept {}

/**
 * @brief 	This function clears USART interrupt flag status
 * @tparam	InputPort  	@ref usart::Port
 * @tparam 	Flags 			@ref usart::InterruptFlag
 *
 * @todo  Finish this in the future
 */
template <Port InputPort, InterruptFlag Flag>
constexpr void clear_interrupt_flag() noexcept {}

}	 // namespace cpp_stm32::usart
