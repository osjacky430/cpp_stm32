/**
 * @file  stm32/f4/define/spi.hxx
 * @brief	Spi class and enum define.
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

#include <array>
#include <cstdint>

#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/detail/lookup_table.hxx"

namespace cpp_stm32::spi {

enum class Port : std::uint8_t { SPI1, SPI2, SPI3, SPI4 };

enum class TransferMode : std::uint8_t { FullDuplex, TxHalfDuplex, RxHalfDuplex, TxSimplex, RxSimplex };
enum class SlaveSelectMode : std::uint8_t { Software, InputHardware, OutputHardware };
enum class DataFrameFormat : std::uint8_t { Byte, Halfword };
enum class Mode : std::uint8_t { Mode0, Mode1, Mode2, Mode3 };
enum class Status : std::uint8_t {
	RXNE,		/*!< Receive buffer not empty*/
	TXE,		/*!< Transmit buffer empty*/
	CHSIDE, /*!< Channel side*/
	UDR,		/*!< Underrun flag*/
	CRCERR, /*!< CRC error flag*/
	MODF,		/*!< Mode fault*/
	OVR,		/*!< Overrun flag*/
	BSY,		/*!< Busy flag*/
	TIFRFE, /*!< TI frame format error*/
};

enum class InterruptFlag : std::uint8_t { ERRIE, RXNEIE, TXEIE };

/**
 *  @class  Baurdrate_t
 *  @brief  Utility class used to check whether baudrate prescaler is reasonable
 */
using Baudrate_t = detail::KeyValTable<struct CPP_STM32_LUT_SPI_BAUD, /**/
																			 PAIR(2, 0b00), PAIR(4, 0b01), PAIR(8, 0b10), PAIR(16, 0b11), PAIR(32, 0b100),
																			 PAIR(64, 0b101), PAIR(128, 0b110), PAIR(256, 0b111)>;
}	// namespace cpp_stm32::spi
