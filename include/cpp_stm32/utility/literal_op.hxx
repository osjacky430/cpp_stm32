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
#include "cpp_stm32/utility/unit.hxx"

namespace cpp_stm32 {

constexpr auto operator"" _k(long double t_freq) noexcept { return t_freq * 1000; }
constexpr auto operator"" _k(std::uint64_t t_quan) noexcept { return t_quan * 1000; }
constexpr auto operator"" _M(long double t_freq) noexcept { return t_freq * 1000000; }
constexpr auto operator"" _M(std::uint64_t t_quan) noexcept { return t_quan * 1000000; }

template <char... num>
constexpr auto operator"" _Hz() noexcept {
	constexpr auto freq = detail::str_to_num<num...>();

	return Frequency<freq>{};
}

template <char... num>
constexpr auto operator"" _MHz() noexcept {
	constexpr auto freq = detail::str_to_num<num...>() * 1000000;

	return Frequency<freq>{};
}

template <char... num>
constexpr auto operator"" _kHz() noexcept {
	constexpr auto freq = detail::str_to_num<num...>() * 1000;

	return Frequency<freq>{};
}

template <char... num>
constexpr auto operator"" _ns() noexcept {
	// this needs additional care, not complete yet
	constexpr auto Sec = detail::str_to_int(std::array{num...}, std::make_index_sequence<sizeof...(num)>{});
	return Second<Sec>{};
}

template <char... num>
constexpr auto operator"" _ic() noexcept {
	constexpr auto idx = detail::str_to_int(std::array{num...}, std::make_index_sequence<sizeof...(num)>{});
	return size_c<idx>{};
}

template <char... num>
constexpr auto operator"" _byte() noexcept {
	constexpr auto idx = detail::str_to_int(std::array{num...}, std::make_index_sequence<sizeof...(num)>{});
	return ByteCount<idx>{};
}

template <char... num>
constexpr auto operator"" _halfword() noexcept {
	constexpr auto idx = detail::str_to_int(std::array{num...}, std::make_index_sequence<sizeof...(num)>{});
	return HalfWordCount<idx>{};
}

}	// namespace cpp_stm32
