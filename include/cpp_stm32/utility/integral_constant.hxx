/**
 * @file  utility/integral_constant.hxx
 * @brief	Utility struct and typedef
 *
 * @todo  Consider rename
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

#include <cmath>
#include <tuple>
#include <utility>

namespace cpp_stm32 {

template <int Val>
using int_c = std::integral_constant<int, Val>;

template <std::size_t Val>
using size_c = std::integral_constant<std::size_t, Val>;

template <std::uint32_t Val>
using uint32_c = std::integral_constant<std::uint32_t, Val>;

template <std::uint8_t Val>
using uint8_c = std::integral_constant<std::uint8_t, Val>;

template <std::uint8_t BC>
struct ByteCount {};

// not sure
template <std::uint32_t Q>
struct Unit {
	static constexpr auto value = Q;
	constexpr auto operator()() const noexcept { return value; }
};

template <std::uint32_t Sec>
struct Second : Unit<Sec> {};

template <std::uint32_t Hz>
struct Frequency : Unit<Hz> {};

}	 // namespace cpp_stm32
