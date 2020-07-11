/**
 * @file  hal/bit.hxx
 * @brief	Abstraction of bits in special function registers
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

#include <cstdint>
#include <tuple>
#include <type_traits>
#include <utility>

#include "cpp_stm32/utility/strongly_typed.hxx"
#include "cpp_stm32/utility/utility.hxx"

namespace cpp_stm32 {

/**
 * [Bit description]
 * @param  t_pos [description]
 * @return       [description]
 *
 * @note 		Settable  (Writing 1 is meaningful): WrOnly, RdWr, RdSet, RdClrWr1
 * 					Clearable (Writing 0 is meaningful): WrOnly, RdWr
 * 					Writable (Writing 0/1 is meaningful): WrOnly, RdWr, RdSet, RdClrWr1
 *
 * @todo 		is this right?
 */
enum class BitMod {
	RdOnly	 = 0x100, /*!< Software can only read this bit. */
	WrOnly	 = 0x010, /*!< Software can only write to this bit. Reading this bit returns the reset value. */
	RdWr		 = 0x110, /*!< Software can read and write to this bit. */
	RdSet		 = 0x111, /*!< Software can read as well as set this bit. Writing 0 has no effect on the bit value.*/
	RdClrWr1 = 0x112, /*!< Software can read as well as clear this bit by writing 1.
												 Writing 0 has no effect on the bit value.*/

};

/**
 * [Bit description]
 *
 */
template <std::uint32_t L, typename DataType = std::uint8_t, BitMod Mod = BitMod::RdWr>
struct Bit {
	static_assert(L <= 32);	//	bit length should never be greater than 32
	static constexpr auto MOD		 = Mod;
	static constexpr auto LENGTH = L;
	std::uint32_t const pos;
	std::uint32_t const mask;

	explicit constexpr Bit(BitPos_t const& t_pos)
		: pos(t_pos.get()), mask(static_cast<std::uint32_t>(((1ULL << LENGTH) - 1U) << pos)) {}

	// currently support only integral type and struct that implement get() method
	// @todo change get() to operator() so that it supports lambda(?)
	[[nodiscard]] constexpr auto operator()(DataType const& t_val) const noexcept {
		if constexpr (std::is_enum_v<DataType>) {
			// this will issue sign conversion warning, investigate it later
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
	[[nodiscard]] static constexpr auto toDataType(ValueType const& t_val) noexcept {
		return static_cast<DataType>(t_val);
	}
};

template <BitMod Mod = BitMod::RdWr>
using Binary = Bit<1, std::uint8_t, Mod>;

template <std::uint32_t L, typename DataType = std::uint8_t>
using StatusBit = Bit<L, DataType, BitMod::RdOnly>;

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
