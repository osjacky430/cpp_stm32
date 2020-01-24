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
#include <utility>

#include "cpp_stm32/detail/char_literal_idx.hxx"
#include "cpp_stm32/utility/integral_constant.hxx"

namespace cpp_stm32 {

constexpr auto operator"" _MHz(long double t_freq) noexcept { return t_freq * 1000000ULL; }
constexpr auto operator"" _MHz(std::uint64_t t_freq) noexcept { return t_freq * 1000000ULL; }
constexpr auto operator"" _KHz(long double t_freq) noexcept { return t_freq * 1000ULL; }
constexpr auto operator"" _KHz(std::uint64_t t_freq) noexcept { return t_freq * 1000ULL; }

template <char... num>
constexpr auto operator"" _ic() noexcept {
	constexpr auto idx = detail::str_to_num(std::tuple{num...}, std::make_index_sequence<sizeof...(num)>{});
	return size_c<idx>{};
}

}	// namespace cpp_stm32
