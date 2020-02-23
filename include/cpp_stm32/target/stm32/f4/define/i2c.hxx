/**
 * @file  stm32/f4/define/i2c.hxx
 * @brief	This file contains I2C class and enum define.
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

#include <cstdint>

#include "cpp_stm32/utility/strongly_typed.hxx"

namespace cpp_stm32::i2c {

enum class Port : std::uint8_t { I2C3, I2C2, I2C1 };

enum class SlaveAddressMode : std::uint8_t { SevenBits, TenBits };

enum class MasterMode : std::uint8_t { SM, FM };

enum class InterruptFlag : std::uint8_t {
	SB,				/*!< Start bit (Master mode)*/
	ADDR,			/*!< Address sent (master mode)/matched (slave mode)*/
	BTF,			/*!< Byte transfer finished*/
	ADD10,		/*!< 10-bit header sent (Master mode)*/
	STOPF,		/*!< Stop detection (slave mode)*/
	RxNE,			/*!< Data register not empty (receivers)*/
	TxE,			/*!< Data register empty (transmitters)*/
	BERR,			/*!< Bus error*/
	ARLO,			/*!< Arbitration lost (master mode)*/
	AF,				/*!< Acknowledge failure*/
	OVR,			/*!< Overrun/Underrun*/
	PECERR,		/*!< PEC Error in reception*/
	TIMEOUT,	/*!< Timeout or Tlow error*/
	SMBALERT, /*!< SMBus alert*/
};

// @todo rename it
enum class Status : std::uint8_t {
	MSL,				/*!< Master/slave*/
	BUSY,				/*!< Bus busy*/
	TRA,				/*!< Transmitter/receiver*/
	GENCALL,		/*!< General call address (Slave mode)*/
	SMBDEFAULT, /*!< SMBus device default address (Slave mode)*/
	SMBHOST,		/*!< SMBus host header (Slave mode)*/
	DUALF,			/*!< Dual flag (Slave mode)*/
	PEC,				/*!< Packet error checking register*/
};

/**
 * @brief   Maximum t_rise for Fast mode and Slow mode
 * @ref     https://www.nxp.com/docs/en/user-guide/UM10204.pdf
 */
constexpr auto FM_MAX_TRISE = 300;	 // ns
constexpr auto SM_MAX_TRISE = 1000;	 // ns

/**
 * @enum
 */
enum class DutyCycle { OneToTwo, NineToSixteen };

/**
 *
 */
template <MasterMode Mode>
constexpr auto CHECK_DNF(std::uint32_t const t_fplck, std::uint8_t const t_DNF) noexcept {
	if constexpr (Mode == MasterMode::FM) {
		if (40 < t_fplck && t_fplck <= 50) {
			return t_DNF <= 15;
		} else if (30 < t_fplck && t_fplck <= 40) {
			return t_DNF <= 13;
		} else if (20 < t_fplck && t_fplck <= 30) {
			return t_DNF <= 7;
		} else if (10 < t_fplck && t_fplck <= 20) {
			return t_DNF <= 1;
		} else if (2 <= t_fplck && t_fplck <= 10) {
			return t_DNF <= 0;
		}
	} else {
		if (10 < t_fplck && t_fplck <= 50) {
			return t_DNF <= 15;
		} else if (5 < t_fplck && t_fplck <= 10) {
			return t_DNF <= 12;
		} else if (2 <= t_fplck && t_fplck <= 5) {
			return t_DNF <= 2;
		}
	}
}

/**
 *
 */
using SlaveAddr7_t	= StrongType<std::uint8_t, struct SlaveAddr7Bit>;
using SlaveAddr10_t = StrongType<std::uint16_t, struct SlaveAddr10Bit>;

enum class Command : std::uint8_t { Write = 0, Read = 1, ReadAfterWrite };

}	 // namespace cpp_stm32::i2c
