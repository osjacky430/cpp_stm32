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

#include "cpp_stm32/utility/strongly_typed.hxx"

/**
 *	@namespace	common
 */
namespace cpp_stm32::usart {

/**
 * @defgroup BAUDRATE_DEF_GGROUP		Baudrate related declaration
 * @{
 */

/**
 * @brief		Create strong type for baudrate
 */
using Baudrate_t = StrongType<std::uint64_t, struct Baudrate>;

/**
 * @defgroup 		BAUD_LITERAL_OP_GROUP		Baudrate related literal operators
 * @brief				These literal operators create ::Baudrate_t instance according to input baudrate
 * @param 			t_baud input baudrate
 * @return 			see ::Baudrate_t
 *
 * @{
 */
constexpr auto operator"" _Baud(std::uint64_t t_baud) noexcept { return Baudrate_t{t_baud}; }

constexpr auto operator"" _KBaud(long double t_baud) noexcept {
	return Baudrate_t{static_cast<std::uint64_t>(t_baud) * 1000ULL};
}

constexpr auto operator"" _KBaud(std::uint64_t t_baud) noexcept { return Baudrate_t{t_baud * 1000ULL}; }

constexpr auto operator"" _MBaud(long double t_baud) noexcept {
	return Baudrate_t{static_cast<std::uint64_t>(t_baud) * 1000000ULL};
}

constexpr auto operator"" _MBaud(std::uint64_t t_baud) noexcept { return Baudrate_t{t_baud * 1000000ULL}; }

/**@}*/

enum class DataBit : std::uint8_t;
enum class HardwareFlowControl : std::uint8_t;
enum class OverSampling : std::uint8_t;
enum class Mode : std::uint8_t;
enum class Parity : std::uint8_t;
enum class Stopbit : std::uint8_t;

template <Stopbit StopBit>
using StopBit_t = std::integral_constant<decltype(StopBit), StopBit>;

template <Stopbit StopBit>
static constexpr StopBit_t<StopBit> StopBit_v{};

}	 // namespace cpp_stm32::usart
