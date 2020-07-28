/**
 * @file  stm32/f4/usart.hxx
 * @brief	Usart setup API for stm32f4
 */

/** Copyright (c) 2020 by osjacky430.
 * All Rights Reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "cpp_stm32/common/usart.hxx"
#include "cpp_stm32/target/stm32/f4/register/usart.hxx"

#include "project_config.hxx"

namespace cpp_stm32::usart {

/**
 * @brief	 This function sets the baudrate of USART
 * @tparam InputPort	@ref usart::Port
 * @param  t_baud 		@ref usart::Baudrate_t
 */
template <Port InputPort>
constexpr void set_baudrate(Baudrate_t const t_baud) noexcept {
	constexpr auto clk_freq = (InputPort == Port::Usart1 || InputPort == Port::Usart6 ? APB2_FREQ : APB1_FREQ);

	auto const usart_div = (clk_freq + t_baud.get() / 2) / t_baud.get();	// round (avoiding floating point arithmetic)

	std::uint16_t const mantissa = usart_div >> 4;
	std::uint8_t const fraction	= usart_div & 0xF;

	reg::BRR<InputPort>.template writeBit<reg::BrrBit::DivFraction, reg::BrrBit::DivMantissa>(fraction, mantissa);
}

/**
 * @brief		This function sets data bit of USART
 * @tparam	InputPort @ref usart::Port
 * @param 	t_d_bit 	@ref usart::DataBit
 */
template <Port InputPort>
constexpr void set_databit(DataBit const t_d_bit) noexcept {
	reg::CR1<InputPort>.template writeBit<reg::Cr1Bit::M>(t_d_bit);
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
	std::uint8_t const cts = (to_underlying(t_flow_ctl) & to_underlying(HardwareFlowControl::CTS)) != 0;
	std::uint8_t const rts = (to_underlying(t_flow_ctl) & to_underlying(HardwareFlowControl::RTS)) != 0;

	reg::CR3<InputPort>.template writeBit<reg::Cr3Bit::RTSE, reg::Cr3Bit::CTSE>(cts, rts);
}

/**
 * @brief 	This function sets transfer mode of USART
 * @tparam	InputPort @ref usart::Port
 * @param 	t_mode		@ref usart::TransferMode
 */
template <Port InputPort>
constexpr void set_transfer_mode(TransferMode const t_mode) noexcept {
	std::uint8_t const tx_en = (to_underlying(t_mode) & to_underlying(TransferMode::TxOnly)) != 0;
	std::uint8_t const rx_en = (to_underlying(t_mode) & to_underlying(TransferMode::RxOnly)) != 0;

	reg::CR1<InputPort>.template writeBit<reg::Cr1Bit::TE, reg::Cr1Bit::RE>(tx_en, rx_en);
}

/**
 * @brief 	This function sets parity of USART
 * @tparam	InputPort @ref usart::Port
 * @param 	t_parity	@ref usart::Parity
 */
template <Port InputPort>
constexpr void set_parity(Parity const t_parity) noexcept {
	std::uint8_t const pe = (t_parity != Parity::None);
	reg::CR1<InputPort>.template writeBit<reg::Cr1Bit::PCE, reg::Cr1Bit::PS>(pe, t_parity);
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
	reg::CR2<InputPort>.template writeBit<reg::Cr2Bit::Stop>(StopBit);
}

/**
 * @brief		This function write data to USART data register
 * @tparam	InputPort  @ref usart::Port
 * @param 	data	 8 bits data
 */
template <Port InputPort>
constexpr void send(std::uint8_t const data) noexcept {
	reg::DR<InputPort>.template writeBit<reg::DrBit::Dr>(data);
}

/**
 * @brief		This function read data from USART data register
 * @tparam	InputPort  @ref usart::Port
 * @return  8 bits data
 */
template <Port InputPort>
[[nodiscard]] constexpr auto receive() noexcept {
	return std::get<0>(reg::DR<InputPort>.template readBit<reg::DrBit::Dr>(ValueOnly));
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
constexpr auto is_tx_empty() noexcept {
	return std::get<0>(reg::SR<InputPort>.template readBit<InterruptFlag::TXE>(ValueOnly)) != 0;
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
constexpr auto is_rx_empty() noexcept {
	return std::get<0>(reg::SR<InputPort>.template readBit<InterruptFlag::RXNE>(ValueOnly)) == 0;
}

/**
 * @brief 	This function enabels USART
 * @tparam	InputPort  @ref usart::Port
 */
template <Port InputPort>
constexpr void enable() noexcept {
	reg::CR1<InputPort>.template setBit<reg::Cr1Bit::UE>();
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
constexpr void send_blocking(std::uint8_t const t_data) noexcept {
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
	return std::get<0>(reg::DR<InputPort>.template readBit<reg::DrBit::Dr>(ValueOnly));
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
template <Port InputPort, usart::Stopbit Stop>
constexpr void set_dps(DataBit const t_d, Parity const t_p, StopBit_t<Stop> const /*unused*/) noexcept {
	std::uint8_t const pe = (t_p != Parity::None);
	reg::CR1<InputPort>.template writeBit<reg::Cr1Bit::M, reg::Cr1Bit::PCE, reg::Cr1Bit::PS>(t_d, pe, t_p);
	reg::CR2<InputPort>.template writeBit<reg::Cr2Bit::Stop>(Stop);
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

	if constexpr (Flag == InterruptFlag::CTS) {
		reg::CR3<InputPort>.template setBit<reg::Cr3Bit::CTSIE>();
	} else if constexpr (Flag == InterruptFlag::LBD) {
		reg::CR2<InputPort>.template setBit<reg::Cr2Bit::LBDIE>();
	} else if constexpr (is_error_irq()) {
		reg::CR3<InputPort>.template setBit<reg::Cr3Bit::EIE>();
	} else {
		reg::CR1<InputPort>.template setBit<reg::Cr1Bit{Flag}>();
	}
}

/**
 * @brief 	This function enables DMA to transfer data to data register
 * @tparam	InputPort  		@ref usart::Port
 */
template <Port InputPort>
constexpr void enable_tx_dma() noexcept {
	reg::CR3<InputPort>.template setBit<reg::Cr3Bit::DMAT>();
}

/**
 * @brief 	This function enables DMA to receive data from data register
 * @tparam	InputPort  		@ref usart::Port
 */
template <Port InputPort>
constexpr void enable_rx_dma() noexcept {
	reg::CR3<InputPort>.template setBit<reg::Cr3Bit::DMAR>();
}

/**
 * @brief 	This function enables USART IDLE interrupt
 * @tparam	InputPort  		@ref usart::Port
 */
template <Port InputPort>
constexpr auto enable_idle_irq = enable_irq<InputPort, InterruptFlag::IDLE>;

/**
 * @brief 	This function enables USART tx shift register empty interrupt
 * @tparam	InputPort  		@ref usart::Port
 */
template <Port InputPort>
constexpr auto enable_txe_irq = enable_irq<InputPort, InterruptFlag::TXE>;

/**
 * @brief 	This function enables USART half duplex
 * @tparam	InputPort  		@ref usart::Port
 */
template <Port InputPort>
constexpr void enable_half_duplex() noexcept {
	reg::CR3<InputPort>.template setBit<reg::Cr3Bit::HDSel>();
}

/**
 * @brief 	This function disables USART half duplex
 * @tparam	InputPort  		@ref usart::Port
 */
template <Port InputPort>
constexpr void disable_half_duplex() noexcept {
	reg::CR3<InputPort>.template clearBit<reg::Cr3Bit::HDSel>();
}

/**
 * @brief 	This function returns USART interrupt flag status
 * @tparam	InputPort  	@ref usart::Port
 * @tparam 	Flags 			@ref usart::InterruptFlag
 *
 * @todo 		maybe variadic template is not a good idea
 */
template <Port InputPort, InterruptFlag... Flags>
constexpr auto get_interrupt_flag() noexcept {
	return reg::SR<InputPort>.template readBit<Flags...>(ValueOnly);
}

/**
 * @brief 	This function clears USART interrupt flag status
 * @tparam	InputPort  	@ref usart::Port
 * @tparam 	Flags       @ref usart::InterruptFlag
 */
template <Port InputPort, InterruptFlag Flag>
constexpr auto clear_interrupt_flag() noexcept {
	if constexpr (Flag != InterruptFlag::LBD || Flag != InterruptFlag::CTS) {
		if constexpr (Flag == InterruptFlag::PE) {
			wait_rx_not_empty<InputPort>();
		}
		[[gnu::unused]] auto const sr = std::get<0>(reg::SR<InputPort>.template readBit<InterruptFlag::IDLE>(ValueOnly));
		[[gnu::unused]] auto const dr = std::get<0>(reg::DR<InputPort>.template readBit<reg::DrBit::Dr>(ValueOnly));
	} else {
		// @TODO finish in the future
	}
}

/**
 *	@class 	UsartBuilder
 *	@brief	Provide an alternative way to setup usart
 *
 * @todo finish in the future
 */
template <Port InputPort>
class UsartBuilder {};

}	// namespace cpp_stm32::usart
