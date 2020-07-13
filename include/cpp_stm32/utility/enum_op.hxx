/**
 * @file  utility/enum_op.hxx
 * @brief	Contains some often used enum class operators
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

#include <utility>

namespace cpp_stm32 {

/**
 *
 */
template <class T>
static constexpr bool is_scoped_enum = !std::is_convertible_v<T, std::underlying_type_t<T>> && std::is_enum_v<T>;

/**
 *
 */
template <typename Enum, typename = std::enable_if_t<is_scoped_enum<Enum>>>
constexpr auto to_underlying(Enum t_e) noexcept {
	return static_cast<std::underlying_type_t<Enum>>(t_e);
}

/**
 * @brief		This function handles AND operator of #Access
 * @param  	lhs		Left hand side
 * @param 	rhs 	Right hand side
 * @return 	Numeric value of AND operation of lhs and rhs
 */
template <typename Enum, typename = std::enable_if_t<is_scoped_enum<Enum>>>
constexpr auto operator&(Enum const& lhs, Enum const& rhs) noexcept {
	return Enum{static_cast<std::underlying_type_t<Enum>>(to_underlying(lhs) & to_underlying(rhs))};
}

/**
 * @brief		This function handles OR operator of #Access
 * @param  	lhs		Left hand side
 * @param 	rhs 	Right hand side
 * @return 	Numeric value of OR operation of lhs and rhs
 */
template <typename Enum, typename = std::enable_if_t<is_scoped_enum<Enum>>>
constexpr auto operator|(Enum const& lhs, Enum const& rhs) noexcept {
	return Enum{to_underlying(lhs) | to_underlying(rhs)};
}

/**
 * @brief		This function handles OR operator of #Access
 * @param  	lhs		Left hand side
 * @param 	rhs 	Right hand side
 * @return 	Numeric value of OR operation of lhs and rhs
 */
template <typename Enum, typename = std::enable_if_t<is_scoped_enum<Enum>>>
constexpr Enum& operator|=(Enum& lhs, Enum rhs) noexcept {
	lhs = lhs | rhs;
	return lhs;
}

}	// namespace cpp_stm32
