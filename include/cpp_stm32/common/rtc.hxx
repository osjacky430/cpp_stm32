/**
 * @file  common/rtc.hxx
 * @brief	common definition of rtc
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

#include <chrono>
#include <cstdint>

#include "cpp_stm32/utility/strongly_typed.hxx"

namespace cpp_stm32::rtc {

enum class HourFormat : std::uint8_t { Twelve, TwentyFour };
enum class TimeFormat : std::uint8_t { Am, Pm };

enum class Month : std::uint8_t { Jan = 1, Feb, Mar, Apr, May, June, July, Aug, Sep, Oct, Nov, Dec };
enum class Weekday : std::uint8_t { Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun };

struct Hour_t {
	std::chrono::hours const hour;
	TimeFormat const timeFormat;
};

using Year_t	 = StrongType<std::uint16_t, struct Year>;
using Date_t	 = StrongType<std::uint8_t, struct Date>;
using Minute_t = std::chrono::minutes;
using Second_t = std::chrono::seconds;

template <char... num>
constexpr auto operator""_Am() noexcept {
	constexpr auto hour = detail::str_to_int(std::tuple{num...}, std::make_index_sequence<sizeof...(num)>{});
	static_assert(hour < 12);
	return Hour_t{std::chrono::hours{hour}, TimeFormat::Am};
}

template <char... num>
constexpr auto operator""_Pm() noexcept {
	constexpr auto hour = detail::str_to_int(std::tuple{num...}, std::make_index_sequence<sizeof...(num)>{});
	static_assert(hour < 12);
	return Hour_t{std::chrono::hours{hour}, TimeFormat::Pm};
}

}	 // namespace cpp_stm32::rtc
