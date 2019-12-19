/**
 * @Date:   2019-12-11T18:51:06+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: bit.hxx
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
	constexpr Bit(BitPos_t const& t_pos) : pos(t_pos.get()), mask(((1U << LENGTH) - 1U) << pos) {}

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
};
