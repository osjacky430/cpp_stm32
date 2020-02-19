/**
 * @file  stm32/f4/i2c.hxx
 * @brief	I2C setup API for stm32f4
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

}	 // namespace cpp_stm32::i2c
