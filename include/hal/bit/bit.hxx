/**
 * @Date:   2019-12-11T18:51:06+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: bit.hxx
 * @Last modified time: 2019-12-15T19:57:41+08:00
 */

#pragma once

#include <cstdint>
#include <type_traits>

#include "include/utility/strongly_typed.hxx"

using BitPos_t		= StrongType<std::uint32_t, struct BitPosition>;
using BitLength_t = StrongType<std::uint32_t, struct BitLength>;

template <std::uint32_t L, typename DataType = bool>
class Bit {
 public:
	using AbstractType = DataType;

	static constexpr auto LENGTH = L;
	std::uint32_t const pos;
	std::uint32_t const mask;

 public:
	constexpr Bit(BitPos_t const t_pos) : pos(t_pos.get()), mask(((1U << LENGTH) - 1U) << pos) {}

	constexpr auto operator()(DataType const& t_val) const noexcept {
		if constexpr (std::is_enum_v<DataType>) {
			return (to_underlying(t_val) & mask) << pos;
		} else if constexpr (std::is_integral_v<DataType>) {
			return (t_val & mask) << pos;
		} else {
			return (t_val.get() & mask) << pos;
		}
	}
};
