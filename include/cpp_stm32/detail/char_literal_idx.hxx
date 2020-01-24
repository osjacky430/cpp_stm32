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

namespace cpp_stm32::detail {

constexpr int to_number(char c) noexcept { return static_cast<int>(c) - static_cast<int>('0'); }

template <int Pow>
constexpr int decimal_pow() noexcept {
	if constexpr (Pow == 0) {
		return 1;
	} else {
		return decimal_pow<Pow - 1>() * 10;
	}
}

template <typename... num, std::size_t... Idx>
constexpr auto str_to_num(std::tuple<num...> const& str, std::index_sequence<Idx...> const&) noexcept {
	return ((to_number(std::get<Idx>(str)) * decimal_pow<sizeof...(Idx) - Idx - 1>()) + ...);
}

}	// namespace cpp_stm32::detail
