/**
 * @Date:   2019-12-19T02:54:43+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: utility.hxx
 */

#pragma once

#include <array>
#include <tuple>
#include <type_traits>

#include "include/utility/constexpr_algo.hxx"
#include "include/utility/strongly_typed.hxx"

/**
 *
 */
template <std::size_t start, std::size_t seq, std::size_t... end>
struct IdxIntervalImpl {
	using IdxIntervalType = typename IdxIntervalImpl<start, seq - 1, seq, end...>::IdxIntervalType;
};

template <std::size_t start, std::size_t... seq>
struct IdxIntervalImpl<start, start, seq...> {
	using IdxIntervalType = std::index_sequence<start, seq...>;
};

template <std::size_t start, std::size_t end>
struct IdxInterval {
	using IdxIntervalType = typename IdxIntervalImpl<start, end - 1, end>::IdxIntervalType;
};

template <std::size_t start, std::size_t end>
using Interval = typename IdxInterval<start, end>::IdxIntervalType;

/**
 *
 */
template <std::size_t N, typename... Args>
using NthType = std::tuple_element_t<N, std::tuple<Args...>>;

template <std::size_t N, typename T, typename... Args>
static constexpr auto IsNthTypeSame = std::is_same_v<NthType<N, Args...>, T>;

/**
 *
 */
template <std::size_t... Pos>
using BitPosSeq_t = std::index_sequence<Pos...>;

template <std::size_t... Pos>
static constexpr auto BitPosSeq = BitPosSeq_t<Pos...>{};

/**
 *
 */
template <typename T, std::size_t... Pos>
constexpr auto SETUP_BIT_LIST(BitPosSeq_t<Pos...> const& /*unused*/) noexcept {
	return std::tuple{T{BitPos_t{Pos}}...};
}

#define SETUP_REGISTER_INFO(Name, ...)                 \
	class Name {                                         \
		template <typename BitList, std::size_t Idx>       \
		friend constexpr auto get_bit() noexcept;          \
                                                       \
	 private:                                            \
		static constexpr std::tuple BIT_LIST{__VA_ARGS__}; \
	};
