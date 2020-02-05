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
#include <tuple>
#include <type_traits>
#include <utility>

#include "cpp_stm32/utility/strongly_typed.hxx"
#include "cpp_stm32/utility/utility.hxx"

namespace cpp_stm32 {

enum class BitMod {
	RdOnly	 = 0x100,
	WrOnly	 = 0x010,
	RdWr		 = 0x110,
	RdSet		 = 0x111,
	RdClrWr1 = 0x112,
};

template <std::uint32_t L, typename DataType = std::uint8_t, BitMod Mod = BitMod::RdWr>
class Bit {
 public:
	static constexpr auto MOD		 = Mod;
	static constexpr auto LENGTH = L;
	std::uint32_t const pos;
	std::uint32_t const mask;

 public:
	constexpr Bit(BitPos_t const& t_pos) : pos(t_pos.get()), mask(((1ULL << LENGTH) - 1U) << pos) {}

	// currently support only integral type and struct that implement get() method
	// @todo change get() to operator() so that it support lambda(?)
	constexpr auto operator()(DataType const& t_val) const noexcept {
		if constexpr (std::is_enum_v<DataType>) {
			return (to_underlying(t_val) << pos) & mask;
		} else if constexpr (std::is_integral_v<DataType>) {
			return (t_val << pos) & mask;
		} else {
			return (t_val.get() << pos) & mask;
		}
	}

	template <typename ValueType>
	[[nodiscard]] static constexpr auto isTypeAvailable() noexcept {
		return std::is_same_v<ValueType, DataType>;
	}
	[[nodiscard]] static constexpr auto isWritable() noexcept { return (Mod & BitMod::WrOnly) == BitMod::WrOnly; }
	[[nodiscard]] static constexpr auto isReadable() noexcept { return (Mod & BitMod::RdOnly) == BitMod::RdOnly; }

	template <typename ValueType>
	[[nodiscard]] constexpr auto toDataType(ValueType const& t_val) const noexcept {
		return static_cast<DataType>(t_val);
	}
};

template <BitMod Mod = BitMod::RdWr>
using Binary = Bit<1, std::uint8_t, Mod>;

template <std::uint32_t L, typename DataType = std::uint8_t>
using StatusBit = Bit<L, DataType, BitMod::RdOnly>;

template <typename... Args>
class BitGroup {
	// to somehow suppress strange warning
	template <std::size_t Idx>
	friend constexpr std::tuple_element_t<Idx, std::tuple<Args...>> get(BitGroup<Args...> const& t_bit_group) noexcept {
		return std::get<Idx>(t_bit_group.m_tup);
	}

	template <typename... BitGroups>
	friend constexpr auto bit_group_cat(BitGroups&&... t_bit_groups) noexcept;

 private:
	std::tuple<Args...> m_tup;

	template <std::size_t Idx>
	constexpr auto is_nand_operable() const noexcept {
		if constexpr (auto const tup_elem = std::get<Idx>(m_tup); std::is_integral_v<decltype(tup_elem)>) {
			return static_cast<decltype(tup_elem)>(~tup_elem);
		} else {
			return tup_elem;
		}
	}

	template <std::size_t... Idx>
	constexpr auto nand_op(std::index_sequence<Idx...> /*unused*/) const noexcept {
		return std::tuple{is_nand_operable<Idx>()...};
	}

 public:
	constexpr BitGroup(Args&&... t_args) noexcept : m_tup{t_args...} {}
	constexpr BitGroup(Args const&... t_args) noexcept : m_tup{t_args...} {}
	constexpr BitGroup(std::tuple<Args...> const& t_tup) noexcept : m_tup{t_tup} {}

	constexpr auto operator~() const noexcept {
		return BitGroup<Args...>{nand_op(std::make_index_sequence<sizeof...(Args)>{})};
	}
};

template <std::size_t Idx, typename... Args>
[[nodiscard]] static constexpr std::tuple_element_t<Idx, std::tuple<Args...>> get(
	BitGroup<Args...> const& t_bit_group) noexcept {
	return std::get<Idx>(t_bit_group.m_tup);
}

template <typename... BitGroups>
static constexpr auto bit_group_cat(BitGroups&&... t_bit_groups) noexcept {
	auto const tup = std::tuple_cat((t_bit_groups.m_tup)...);
	return BitGroup{tup};
}

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
[[nodiscard]] constexpr auto CREATE_LIST_OF_BITS(BitPosSeq_t<Pos...> const& /*unused*/) noexcept {
	return std::tuple{T{BitPos_t{Pos}}...};
}

}	// namespace cpp_stm32
