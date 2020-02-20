/**
 * @file  stm32/f4/i2c.hxx
 * @brief	I2C setup API for stm32f4
 *
 * @ref   https://www.nxp.com/docs/en/user-guide/UM10204.pdf
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

#include "cpp_stm32/target/stm32/f4/register/i2c.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

#include "sys_info.hpp"

namespace cpp_stm32::i2c {

/**
 * @brief   This function disables I2C peripheral
 * @tparam  I2C @ref i2c::Port
 */
template <Port I2C>
constexpr void disable() noexcept {
	reg::CR1<I2C>.template clearBit<reg::CR1Field::PE>();
}

/**
 * @brief   This function enables I2C peripheral
 * @tparam  I2C @ref i2c::Port
 */
template <Port I2C>
constexpr void enable() noexcept {
	reg::CR1<I2C>.template setBit<reg::CR1Field::PE>();
}

/**
 * @brief   This function resets I2C peripheral
 * @tparam  I2C @ref i2c::Port
 *
 * @note    This bit can be used to reinitialize the peripheral after an error or a locked state. As an example, if the
 *          BUSY bit is set and remains locked due to a glitch on the bus, the SWRST bit can be used to exit from this
 *          state.
 */
template <Port I2C>
constexpr void reset() noexcept {
	disable<I2C>();

	reg::CR1<I2C>.template setBit<reg::CR1Field::SWRST>();
}

/**
 * @brief   This function generate start condition
 * @tparam  I2C @ref i2c::Port
 *
 * @note    In Master Mode:
 *            - 0: No Start generation
 *            - 1: Repeated start generation
 *          In Slave mode:
 *            - 0: No Start generation
 *            - 1: Start generation when the bus is free
 */
template <Port I2C>
constexpr void generate_start_condition() noexcept {
	reg::CR1<I2C>.template setBit<reg::CR1Field::START>();
}

/**
 * @brief   This function terminates start condition
 * @tparam  I2C @ref i2c::Port
 */
template <Port I2C>
constexpr void terminate_start_condition() noexcept {
	reg::CR1<I2C>.template clearBit<reg::CR1Field::START>();
}

/**
 * @brief   This function generates stop condition
 * @tparam  I2C @ref i2c::Port
 *
 * @note    In Master Mode:
 *            - 0: No Stop generation.
 *            - 1: Stop generation after the current byte transfer or after the current Start condition is sent.
 *          In Slave mode:
 *            - 0: No Stop generation.
 *            - 1: Release the SCL and SDA lines after the current byte transfer.
 */
template <Port I2C>
constexpr void generate_stop_condition() noexcept {
	reg::CR1<I2C>.template setBit<reg::CR1Field::STOP>();
}

/**
 * @brief   This function terminates stop condition
 * @tparam  I2C @ref i2c::Port
 */
template <Port I2C>
constexpr void terminate_stop_condition() noexcept {
	reg::CR1<I2C>.template clearBit<reg::CR1Field::STOP>();
}

/**
 * @brief   This function sets own address
 * @tparam  I2C @ref i2c::Port
 * @tparam  AM  @ref i2c::SlaveAddressMode
 *
 * @param   t_addr Address
 */
template <Port I2C, SlaveAddressMode AM,
					typename AddressData_t = std::conditional_t<AM == SlaveAddressMode::TenBits, std::uint16_t, std::uint8_t>>
constexpr void set_own_address(AddressData_t const t_addr) noexcept {
	reg::OAR1<I2C, AM>.template writeBit<reg::OAR1Field::ADD, reg::OAR1Field::ADDMODE>(t_addr, AM);
}

/**
 * @brief   This function sets own address for dual address mode
 * @tparam  I2C @ref i2c::Port
 *
 * @oaram   t_addr_1  Address 1
 * @param   t_addr_2  Address 2
 */
template <Port I2C>
constexpr void set_own_address(std::uint8_t const t_addr_1, std::uint8_t const t_addr_2) noexcept {
	using reg::OAR1Field, reg::OAR2Field;
	constexpr auto am = SlaveAddressMode::SevenBits;
	reg::OAR1<I2C, am>.template writeBit<OAR1Field::ADD, OAR1Field::ADDMODE>(t_addr_1, am);
	reg::OAR2<I2C>.template writeBit<OAR2Field::ADD2, OAR2Field::ENDUAL>(t_addr_2, std::uint8_t{1});
}

/**
 * @brief   This function disables dual address mode
 * @tparam  I2C @ref i2c::Port
 *
 * @note    0: Only OAR1 is recognized in 7-bit addressing mode
 *          1: Both OAR1 and OAR2 are recognized in 7-bit addressing mode
 */
template <Port I2C>
constexpr void disable_dual_address() noexcept {
	reg::OAR2<I2C>.template clearBit<reg::OAR2Field::ENDUAL>();
}

/**
 * @brief   This function writes the perihperal clock frequency to the register
 * @tparam  I2C @ref i2c::Port
 *
 * @note    I2C1 ~ I2C3 all belong to APB1
 * @note    The peripheral input clock frequency must be at least:
 *            - 2 MHz in Sm mode
 *            - 4 MHz in Fm mode
 */
template <Port I2C>
constexpr void write_periph_clk_freq() noexcept {
	if constexpr (COMPILE_TIME_CLOCK_CONFIG) {
		constexpr std::uint8_t frq = APB1_CLK_FREQ / 1000000;
		reg::CR2<I2C>.template writeBit<reg::CR2Field::FREQ>(frq);
	} else {
		// @todo finish this
	}
}

/**
 * @brief   This function writes byte to data register
 * @tparam  I2C @ref i2c::Port
 * @param   t_data  Data to transmit
 *
 * @todo    handle transfer process
 */
template <Port I2C>
constexpr void send(std::uint8_t const t_data) noexcept {
	reg::DR<I2C>.template writeBit<reg::DRField::DR>(t_data);
}

/**
 * @brief   This function reads byte from data register
 * @tparam  I2C @ref i2c::Port
 * @return  received byte
 *
 * @todo    handle receive process
 */
template <Port I2C>
constexpr auto receive() noexcept {
	return reg::DR<I2C>.template readBit<reg::DRField::DR>(ValueOnly);
}

/**
 * @brief   This function configures SCL of I2C
 * @tparam  I2C   @ref i2c::Port
 * @tparam  Mode  @ref i2c::MasterMode
 * @tparam  Hz    SCL clock frequency
 *
 * @note    f_PCLK must be at least 2 MHz to achieve Sm mode I2C frequencies. It must be at least 4 MHz to achieve Fm
 *          mode I2C frequencies. It must be a multiple of 10MHz to reach the 400 kHz maximum I2C Fm mode clock.
 *
 * @note    t_{high} + t_{low} \approx t_{SCL} = 1 / f_{SCL}, where:
 *
 *          t_{high} = C_{high} * CCR * t_{pclk},
 *          t_{low} = C_{low} * CCR * t_{pclk},
 *
 *          \therefore CCR = t_{SCL} / ((C_{high} + C_{low}) * t_{pclk}).
 */
template <Port I2C, MasterMode Mode, std::uint32_t Hz>
constexpr void config_scl_clock(Frequency<Hz> const /* unused */) noexcept {
	using namespace reg;
	// static_assert
	constexpr std::uint8_t duty = (Hz == 400_k);
	if constexpr (COMPILE_TIME_CLOCK_CONFIG) {
		constexpr std::uint16_t t_ccr = []() {
			constexpr auto t_SCL = 1000000000 / Hz;	 // to nano second
			if constexpr (constexpr auto t_pclk = 1000000000 / APB1_CLK_FREQ; Mode == MasterMode::FM) {
				if constexpr (duty == 1) {
					return t_SCL / (25 * t_pclk);
				} else {
					return t_SCL / (3 * t_pclk);
				}
			} else if constexpr (Mode == MasterMode::SM) {
				return t_SCL / (2 * t_pclk);
			}
		}();

		CCR<I2C>.template writeBit<CCRField::CCR, CCRField::DUTY, CCRField::F_S>(t_ccr, duty, Mode);
	} else {
		// @todo finish this
	}
}

/**
 * @brief   This function sets the maximum rising time of SCL
 * @tparam  I2C  @ref i2c::Port
 * @tparam  Mode @ref i2c::MasterMode
 *
 * @note    Maximum trise for FM mode and SM mode, @see i2c::FM_MAX_TRISE and @ref i2c::SM_MAX_TRISE
 */
template <Port I2C, MasterMode Mode>
constexpr void write_max_rising_time() noexcept {
	if constexpr (COMPILE_TIME_CLOCK_CONFIG) {
		constexpr std::uint8_t t_rise = []() {
			if constexpr (constexpr auto t_pclk = 1000000000 / APB1_CLK_FREQ; Mode == MasterMode::FM) {
				return FM_MAX_TRISE / t_pclk + 1;
			} else {
				return SM_MAX_TRISE / t_pclk + 1;
			}
		}();

		reg::TRISE<I2C>.template writeBit<reg::TRISEField::TRISE>(t_rise);
	} else {
		// @todo finish this
	}
}

/**
 * @brief   This function sets the noise filter capability of digital noise filter
 * @tparam  I2C   @ref i2c::Port
 * @tparam  Mode  @ref i2c::MasterMode
 * @tparam  DNF   Digital noise filter
 *
 * @note    In Fm mode, the I2C standard requires that spikes are suppressed to a length of 50 ns on SDA and SCL lines.
 * @note    For each frequency range, the constraint is given based on the worst case which is the minimum frequency of
 *          the range. Greater DNF values can be used if the system can support maximum hold time violation.
 */
template <Port I2C, MasterMode Mode, std::uint8_t DNF>
constexpr void set_digital_noise_filter() noexcept {
	if constexpr (COMPILE_TIME_CLOCK_CONFIG) {
		constexpr auto f_pclk = APB1_CLK_FREQ / 1000000;
		static_assert(CHECK_DNF<Mode>(f_pclk, DNF));

		reg::FLTR<I2C>.template writeBit<reg::FLTRField::DNF>(DNF);
	} else {
		// @todo finish in the future
	}
}

/**
 * @brief   This function enables analog noise filter, this is enabled by default
 * @tparam  I2C @ref i2c::Port
 */
template <Port I2C>
constexpr void enable_analog_noise_filter() noexcept {
	reg::FLTR<I2C>.template clearBit<reg::FLTRField::ANOFF>();
}

/**
 * @brief   This function disables analog noise filter, this is enabled by default
 * @tparam  I2C @ref i2c::Port
 */
template <Port I2C>
constexpr void disable_analog_noise_filter() noexcept {
	reg::FLTR<I2C>.template setBit<reg::FLTRField::ANOFF>();
}

/**
 * @brief   This function enables I2C SCL clock stretch
 * @tparam  I2C @ref i2c::Port
 */
template <Port I2C>
constexpr void enable_clock_stretch() noexcept {
	reg::CR1<I2C>.template clearBit<reg::CR1Field::NOSTRETCH>();
}

/**
 * @brief   This function disables I2C SCL clock stretch
 * @tparam  I2C @ref i2c::Port
 */
template <Port I2C>
constexpr void disable_clock_stretch() noexcept {
	reg::CR1<I2C>.template setBit<reg::CR1Field::NOSTRETCH>();
}

/**
 * @brief   This function enables I2C to return acknowledge after a byte is received
 * @tparam  I2C @ref i2c::Port
 */
template <Port I2C>
constexpr void enable_ack() noexcept {
	reg::CR1<I2C>.template setBit<reg::CR1Field::ACK>();
}

/**
 * @brief   This function disables acknowledging after a byte is received
 * @tparam  I2C @ref i2c::Port
 */
template <Port I2C>
constexpr void disable_ack() noexcept {
	reg::CR1<I2C>.template clearBit<reg::CR1Field::ACK>();
}

/**
 * @brief   This function sets acknowledge for second byte received in 2 byte receive mode
 * @tparam  I2C @ref i2c::Port
 *
 * @note    The POS bit must be used only in 2-byte reception configuration in master mode. It must be configured before
 *          data reception starts
 */
// template <Port I2C>
// constexpr void set_2nd_byte_ack() noexcept {
// 	reg::CR1<I2C>.template setBit<reg::CR1Field::POS>();
// }

/**
 * @brief   This function enables interrupt according to interrupt flags
 * @tparam  I2C   @ref i2c::Port
 * @tparam  Flags @ref i2c::InterruptFlag
 */
template <Port I2C, InterruptFlag... Flags>
constexpr void enable_irq() noexcept {
	constexpr auto is_buffer_event = [](auto const t_flag) {
		return t_flag == InterruptFlag::TxE || t_flag == InterruptFlag::RxNE;
	};

	constexpr auto have_event_flag = []() {
		return ((to_underlying(Flags) <= to_underlying(InterruptFlag::TxE)) || ...);
	};

	constexpr auto have_error_flag = []() { return ((to_underlying(InterruptFlag::TxE) < to_underlying(Flags)) || ...); };

	if constexpr (have_event_flag()) {
		if constexpr ((is_buffer_event(Flags) || ...)) {
			reg::CR2<I2C>.template setBit<reg::CR2Field::ITBUFEN>();
		}

		reg::CR2<I2C>.template setBit<reg::CR2Field::ITEVTEN>();
	} else if constexpr (have_error_flag()) {
		reg::CR2<I2C>.template setBit<reg::CR2Field::ITERREN>();
	}
}

/**
 * @brief   This function disables interrupt according to interrupt flags
 * @tparam  I2C   @ref i2c::Port
 * @tparam  Flags @ref i2c::InterruptFlag
 */
template <Port I2C, InterruptFlag... Flags>
constexpr void disable_irq() noexcept {
	constexpr auto is_buffer_event = [](auto const t_flag) {
		return t_flag == InterruptFlag::TxE || t_flag == InterruptFlag::RxNE;
	};

	constexpr auto have_event_flag = []() {
		return ((to_underlying(Flags) <= to_underlying(InterruptFlag::TxE)) || ...);
	};

	constexpr auto have_error_flag = []() { return ((to_underlying(InterruptFlag::TxE) < to_underlying(Flags)) || ...); };

	if constexpr (have_event_flag()) {
		if constexpr ((is_buffer_event(Flags) || ...)) {
			reg::CR2<I2C>.template clearBit<reg::CR2Field::ITBUFEN>();
		}

		reg::CR2<I2C>.template clearBit<reg::CR2Field::ITEVTEN>();
	} else if constexpr (have_error_flag()) {
		reg::CR2<I2C>.template clearBit<reg::CR2Field::ITERREN>();
	}
}

/**
 * @brief   This function enables dma request
 *
 * @note    DMA request enabled when TxE=1 or RxNE =1
 */
template <Port I2C>
constexpr void enable_dma() noexcept {
	reg::CR2<I2C>.template setBit<reg::CR2Field::DMAEN>();
}

/**
 * @brief   This function disables dma request
 *
 * @note    DMA request enabled when TxE=1 or RxNE =1
 */
template <Port I2C>
constexpr void disable_dma() noexcept {
	reg::CR2<I2C>.template clearBit<reg::CR2Field::DMAEN>();
}

/**
 * [set_dma_last_transfer description]
 *
 * @todo maybe add dma namespace here, and put this function inside dma namespace
 */
// template <Port I2C>
// constexpr void set_dma_last_transfer() noexcept {
//
// }

}	 // namespace cpp_stm32::i2c
