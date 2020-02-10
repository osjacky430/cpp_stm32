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

#include <array>
#include <functional>
#include <iterator>
#include <utility>

/**
 * @namespace 	cpp_stm32::detail
 * @brief				Detail implementation namespace
 *
 * @note 				DO NOT USE DETAIL NAMESPACE
 */
namespace cpp_stm32::detail {

template <class ForwardIt, class Generator>
constexpr void generate(ForwardIt first, ForwardIt last, Generator g) {
	while (first != last) {
		*first++ = g();
	}
}

template <class T, std::size_t Size>
constexpr auto array_count(std::array<T, Size> const& t_arr, T const& t_val) {
	int ret = 0;
	for (int i = 0; i < Size; ++i) {
		if (t_arr[i] == t_val) {
			ret++;
		}
	}

	return ret;
}

template <class InputIt, class T>
constexpr auto count(InputIt first, InputIt last, const T& value) {
	typename std::iterator_traits<InputIt>::difference_type ret = 0;
	for (; first != last; ++first) {
		if (*first == value) {
			ret++;
		}
	}
	return ret;
}

template <class InputIt, class T>
constexpr InputIt find(InputIt first, InputIt last, const T& value) {
	for (; first != last; ++first) {
		if (*first == value) {
			return first;
		}
	}
	return last;
}

template <class InputIt, class UnaryPredicate>
constexpr InputIt find_if(InputIt first, InputIt last, UnaryPredicate p) {
	for (; first != last; ++first) {
		if (p(*first)) {
			return first;
		}
	}
	return last;
}

template <class InputIt, class UnaryPredicate>
constexpr bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
	return std::find_if_not(first, last, p) == last;
}

template <class ForwardIt>
constexpr ForwardIt unique(ForwardIt first, ForwardIt last) {
	if (first == last) return last;

	ForwardIt result = first;
	while (++first != last) {
		if (!(*result == *first) && ++result != first) {
			*result = std::move(*first);
		}
	}
	return ++result;
}

template <class ForwardIt, class T>
constexpr void fill(ForwardIt first, ForwardIt last, T const& value) {
	for (; first != last; ++first) {
		*first = value;
	}
}

template <class InputIt, class OutputIt>
constexpr OutputIt copy(InputIt first, InputIt last, OutputIt d_first) {
	while (first != last) {
		*d_first++ = *first++;
	}
	return d_first;
}

/**
 * @ref https://tristanbrindle.com/posts/a-more-useful-compile-time-quicksort
 */
template <class InputIt, class UnaryPredicate>
constexpr InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate q) {
	for (; first != last; ++first) {
		if (!q(*first)) {
			return first;
		}
	}
	return last;
}

template <class ForwardIt1, class ForwardIt2>
constexpr void iter_swap(ForwardIt1 a, ForwardIt2 b) {
	auto temp = std::move(*a);
	*a				= std::move(*b);
	*b				= std::move(temp);
}

template <class ForwardIt, class UnaryPredicate>
constexpr ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p) {
	first = detail::find_if_not(first, last, p);
	if (first == last) return first;

	for (ForwardIt i = first + 1; i != last; ++i) {
		if (p(*i)) {
			detail::iter_swap(i, first);
			++first;
		}
	}
	return first;
}

template <class RAIt, class Compare = std::less<>>
constexpr void quick_sort(RAIt first, RAIt last, Compare cmp = Compare{}) {
	auto const N = last - first;
	if (N <= 1) return;
	auto const pivot	 = *(first + N / 2);
	auto const middle1 = detail::partition(first, last, [=](auto const& elem) { return cmp(elem, pivot); });
	auto const middle2 = detail::partition(middle1, last, [=](auto const& elem) { return !cmp(pivot, elem); });
	quick_sort(first, middle1, cmp);
	quick_sort(middle2, last, cmp);
}

template <typename Range, class Compare = std::less<>>
constexpr auto sort(Range&& range, Compare cmp = Compare{}) {
	quick_sort(std::begin(range), std::end(range), cmp);
	return range;
}

/**
 * @ref https://github.com/llvm-mirror/libcxx/blob/a12cb9d211019d99b5875b6d8034617cbc24c2cc/include/algorithm#L2177
 */
template <class BinaryPredicate, class InputIt, class OutputIt>
constexpr OutputIt unique_copy(InputIt first, InputIt last, OutputIt result, BinaryPredicate pred) {
	if (first != last) {
		typename std::iterator_traits<InputIt>::value_type t(*first);
		*result = t;
		++result;
		while (++first != last) {
			if (!pred(t, *first)) {
				t				= *first;
				*result = t;
				++result;
			}
		}
	}
	return result;
}

}	 // namespace cpp_stm32::detail
