/**
 * @file  stm32/f4/define/usart.hxx
 * @brief	Usart class and enum define.
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

namespace cpp_stm32::usart {

enum class Port { Usart1, Usart2, Usart3, Uart4, Uart5, Usart6 };

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
enum class TransferMode : std::uint8_t { RxOnly = 1, TxOnly, TxRx };
enum class Parity : std::uint8_t { Even, Odd, None };
enum class Stopbit : std::uint8_t { Bit1, Bit0f5, Bit2, Bit1f5 };

enum class InterruptFlag : std::uint8_t { PE, FE, NF, ORE, IDLE, RXNE, TC, TXE, LBD, CTS };

}	 // namespace cpp_stm32::usart
