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

#include <cmath>
#include <cstddef>
#include <tuple>

#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/detail/tuple.hxx"

namespace cpp_stm32::detail {

/**
 * [to_number description]
 * @param  c [description]
 * @return   [description]
 */
constexpr int to_number(char c) noexcept { return static_cast<int>(c) - static_cast<int>('0'); }

/**
 * [decimal_pow description]
 * @return [description]
 */
template <int Pow>
constexpr int decimal_pow() noexcept {
	if constexpr (Pow == 0) {
		return 1;
	} else {
		return decimal_pow<Pow - 1>() * 10;
	}
}

/**
 * [str_to_int description]
 * @param  Idx [description]
 * @return     [description]
 * @todo modify this, this should have same implementation detail with str_to_float
 * @todo consider binary-like input of hexadecimal-like input scenario
 */
template <std::size_t... Idx>
constexpr auto str_to_int(std::array<char, sizeof...(Idx)> const& str, std::index_sequence<Idx...> const&) noexcept {
	return ((to_number(std::get<Idx>(str)) * decimal_pow<sizeof...(Idx) - Idx - 1>()) + ...);
}

/**
 * [str_to_float description]
 * @param  str [description]
 * @return     [description]
 */
template <std::size_t N>
constexpr auto str_to_float(std::array<char, N> const& str) noexcept {
	auto const decimal_point_pos = detail::find(str.begin(), str.end(), '.') - str.begin();
	auto const exponent_pos =
		detail::find_if(str.begin(), str.end(), [](auto const& t_chr) { return t_chr == 'e' || t_chr == 'E'; }) -
		str.begin();

	float ret_val = 0.0f;
	float exp			= 0.0f;
	auto base			= 1.0;

	for (int i = 0; i < decimal_point_pos; ++i) {
		ret_val += to_number(str[decimal_point_pos - i - 1]) * base;
		base *= 10;
	}

	base = 0.1;
	for (int i = decimal_point_pos + 1; i < exponent_pos; ++i) {
		ret_val += to_number(str[i]) * base;
		base *= 0.1;
	}

	base = 1;
	for (int i = N - 1; i > exponent_pos; --i) {
		exp += to_number(str[i]) * base;
		base *= 10;
	}

	return ret_val * std::pow(10.0f, exp);
}

/**
 * [str_is_float description]
 * @param  t_str [description]
 * @return       [description]
 */
template <std::size_t N>
constexpr bool str_is_float(std::array<char, N> const& t_str) noexcept {
	auto const is_valid_input = detail::all_of(t_str.begin(), t_str.end(), [](auto const& t_val) {
		return '0' <= t_val && t_val <= '9' || t_val == '.' || t_val == 'e' || t_val == 'E';
	});

	auto const has_dec_pt = detail::find(t_str.begin(), t_str.end(), '.') != t_str.end();
	auto const has_exp		= detail::find_if(t_str.begin(), t_str.end(),
																				[](auto const& t_in) { return t_in == 'e' || t_in == 'E'; }) != t_str.end();

	return is_valid_input && (has_dec_pt || has_exp);
}

/**
 * [str_to_num description]
 * @param  digit [description]
 * @return       [description]
 */
template <char... digit>
constexpr auto str_to_num() noexcept {
	if constexpr (constexpr auto str = std::array{digit...}; str_is_float(str)) {
		return str_to_float(str);
	} else {
		return str_to_int(str, std::make_index_sequence<sizeof...(digit)>{});
	}
}

}	// namespace cpp_stm32::detail
