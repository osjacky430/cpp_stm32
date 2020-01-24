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

#include <utility>

namespace cpp_stm32 {

/**
 *
 */
template <typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
constexpr auto to_underlying(Enum t_e) noexcept {
	return static_cast<std::underlying_type_t<Enum>>(t_e);
}

/**
 * @brief		This function handles AND operator of #Access
 * @param  	lhs		Left hand side
 * @param 	rhs 	Right hand side
 * @return 	Numeric value of AND operation of lhs and rhs
 */
template <typename Enum>
constexpr auto operator&(Enum const& lhs, Enum const& rhs) noexcept {
	return Enum{to_underlying(lhs) & to_underlying(rhs)};
}

}	// namespace cpp_stm32
