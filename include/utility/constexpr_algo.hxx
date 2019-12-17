/**
 * @Date:   2019-12-16T15:38:08+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: constexpr_algo.hxx
 * @Last modified time: 2019-12-16T16:31:13+08:00
 */

#pragma once

template <class InputIt, class T>
constexpr InputIt constexpr_std_find(InputIt first, InputIt last, const T& value) {
	for (; first != last; ++first) {
		if (*first == value) {
			return first;
		}
	}
	return last;
}

template <class InputIt, class UnaryPredicate>
constexpr InputIt constexpr_std_find_if(InputIt first, InputIt last, UnaryPredicate p) {
	for (; first != last; ++first) {
		if (p(*first)) {
			return first;
		}
	}
	return last;
}
