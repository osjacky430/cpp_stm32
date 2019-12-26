/**
 * @Date:   2019-12-16T15:38:08+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: constexpr_algo.hxx
 * @Last modified time: 2019-12-26T02:55:30+08:00
 */

#pragma once

#include <functional>
#include <iterator>
#include <utility>

namespace cstd {
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
	first = cstd::find_if_not(first, last, p);
	if (first == last) return first;

	for (ForwardIt i = first + 1; i != last; ++i) {
		if (p(*i)) {
			cstd::iter_swap(i, first);
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
	auto const middle1 = cstd::partition(first, last, [=](auto const& elem) { return cmp(elem, pivot); });
	auto const middle2 = cstd::partition(middle1, last, [=](auto const& elem) { return !cmp(pivot, elem); });
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

}	 // namespace cstd
