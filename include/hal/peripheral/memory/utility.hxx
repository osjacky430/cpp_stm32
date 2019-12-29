/**
 * @Date:   2019-12-19T02:54:43+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: utility.hxx
 */

#pragma once

#include "include/utility/constexpr_algo.hxx"
#include "include/utility/strongly_typed.hxx"
#include "include/utility/utility.hxx"

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
