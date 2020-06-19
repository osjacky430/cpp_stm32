/**
 * @file  detail/index_interval.hxx
 * @brief	implementation of indexing method with given start, end, and interval
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

namespace cpp_stm32::detail {

template <std::size_t interval, std::size_t start, std::size_t seq, std::size_t... end>
struct RangeImpl {
	static_assert(static_cast<int>(seq) - static_cast<int>(interval) >= 0);
	using RangeSeq = typename RangeImpl<interval, start, seq - interval, seq, end...>::RangeSeq;
};

template <std::size_t interval, std::size_t start, std::size_t... seq>
struct RangeImpl<interval, start, start, seq...> {
	using RangeSeq = std::index_sequence<start, seq...>;
};

template <std::size_t start, std::size_t end, std::size_t interval>
struct Range_ {
	// static_assert((end - start + 1) % interval == 0);
	using RangeSeq = typename RangeImpl<interval, start, end - interval, end>::RangeSeq;
};

template <std::size_t start, std::size_t interval>
struct Range_<start, start, interval> {
	using RangeSeq = std::index_sequence<start>;
};

template <std::size_t start, std::size_t end, std::size_t interval = 1>
using IdxRange = typename Range_<start, end, interval>::RangeSeq;

}	 // namespace cpp_stm32::detail
