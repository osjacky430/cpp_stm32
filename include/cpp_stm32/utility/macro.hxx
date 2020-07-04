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

#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/utility/integral_constant.hxx"

// @todo this is the best solution I can think of so far...
#define PAIR(x, y) (x), (y)

namespace cpp_stm32 {

// @todo replace macro above with this LookUpTable class
template <typename Tag, std::uint32_t Lower, std::uint32_t Upper>
struct LookUpTable {
	std::uint32_t const m_value;

	static constexpr auto MAX = Upper;
	static constexpr auto MIN = Lower;

	template <std::uint32_t Val>
	explicit constexpr LookUpTable(cpp_stm32::uint32_c<Val> const /*unused*/) noexcept : m_value(Val) {
		static_assert(MIN <= Val && Val <= MAX);
	}

	[[nodiscard]] constexpr auto operator()() const noexcept { return m_value; }
	[[nodiscard]] constexpr auto get() const noexcept { return m_value; }
};

template <typename Key, typename Val>
struct Pair {
	Key const key;
	Val const val;

	explicit constexpr Pair(Key&& t_key, Val&& t_val) noexcept : key(t_key), val(t_val) {}
};

template <typename Tag, auto... All>
class KeyValTable {
 private:
	template <auto Key, auto Val, auto... Rest>
	struct KeyValGetter {
		static constexpr std::tuple KVP{std::tuple_cat(std::tuple{Pair{Key, Val}}, KeyValGetter<Rest...>::KVP)};
	};

	template <auto Key, auto Val>
	struct KeyValGetter<Key, Val> {
		static constexpr std::tuple KVP{Pair{Key, Val}};
	};

	std::uint32_t const m_val;

 public:
	static constexpr auto KEY_VAL_MAP = KeyValGetter<All...>::KVP;
	static constexpr auto KV_NUM			= sizeof...(All) / 2;

 private:
	template <auto Key, std::size_t... idx>
	static constexpr auto HAVE_KEY(std::index_sequence<idx...> const) noexcept {
		return ((std::get<idx>(KEY_VAL_MAP).key == Key) || ...);
	}

	template <auto Key, std::size_t... idx>
	static constexpr auto GET_VALUE(std::integral_constant<decltype(Key), Key> const,
																	std::index_sequence<idx...> const) noexcept {
		constexpr std::array is_key_arr{std::get<idx>(KEY_VAL_MAP).key == Key...};
		constexpr std::size_t val_idx = *detail::find(is_key_arr.begin(), is_key_arr.end(), true);
		return std::get<val_idx>(KEY_VAL_MAP).val;
	}

	template <auto Key, std::size_t... idx>
	static constexpr auto UPPER_BOUND(std::index_sequence<idx...> const) noexcept {
		constexpr std::array is_greater_arr{std::get<idx>(KEY_VAL_MAP).key < Key...};
		constexpr std::size_t val_idx = *detail::find(is_greater_arr.begin(), is_greater_arr.end(), true);
		return std::get<val_idx>(KEY_VAL_MAP);
	}

 public:
	template <auto Val>
	static constexpr auto have_key() noexcept {
		return HAVE_KEY<Val>(std::make_index_sequence<KV_NUM>{});
	}

	template <auto Val>
	static constexpr auto upper_bound() noexcept {
		return UPPER_BOUND<Val>(std::make_index_sequence<KV_NUM>{});
	}

	template <auto Val>
	explicit constexpr KeyValTable(std::integral_constant<decltype(Val), Val> const t_v) noexcept
		: m_val(GET_VALUE(t_v, std::make_index_sequence<KV_NUM>{})) {
		static_assert(HAVE_KEY<Val>(std::make_index_sequence<KV_NUM>{}));
	}

	[[nodiscard]] constexpr auto get() const noexcept { return m_val; }
	[[nodiscard]] constexpr auto operator()() const noexcept { return m_val; }
};

}	 // namespace cpp_stm32

/**
 * @def 	 SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(ClassName, ...)
 * @param  ClassName 	Class name
 * @param  VARARGS    division factor - register value pair
 */
#define SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(ClassName, ...)                                                \
	struct ClassName {                                                                                        \
		std::uint32_t const m_value;                                                                            \
		static constexpr std::array AVAIL_DIVISION_FACTOR{__VA_ARGS__};                                         \
                                                                                                            \
		template <std::uint32_t Val>                                                                            \
		static constexpr auto findDivisionFactor = []() {                                                       \
			constexpr auto iter_pos = detail::find_if(AVAIL_DIVISION_FACTOR.begin(), AVAIL_DIVISION_FACTOR.end(), \
																								[](auto const& t_pair) { return t_pair.first == Val; });    \
			static_assert(iter_pos != AVAIL_DIVISION_FACTOR.end());                                               \
			return iter_pos->second;                                                                              \
		};                                                                                                      \
                                                                                                            \
		template <std::uint32_t Val>                                                                            \
		explicit constexpr ClassName(std::integral_constant<std::uint32_t, Val> const&) noexcept                \
			: m_value(findDivisionFactor<Val>()) {}                                                               \
                                                                                                            \
		[[nodiscard]] constexpr auto operator()() const noexcept { return m_value; }                            \
		[[nodiscard]] constexpr auto get() const noexcept { return m_value; }                                   \
	}

