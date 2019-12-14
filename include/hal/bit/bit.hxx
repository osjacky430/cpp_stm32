/**
 * @Date:   2019-12-11T18:51:06+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: bit.hxx
 * @Last modified time: 2019-12-14T00:43:36+08:00
 */

#pragma once

#include <cstdint>

#include "include/utility/strongly_typed.hxx"

using BitPos_t		= StrongType<std::uint32_t, struct BitPosition>;
using BitLength_t = StrongType<std::uint32_t, struct BitLength>;

template <std::uint32_t L>
class Bit {
 public:
	static constexpr auto LENGTH = L;
	std::uint32_t const pos;
	std::uint32_t const mask;

 public:
	constexpr Bit(BitPos_t const t_pos) : pos(t_pos.get()), mask(((1U << LENGTH) - 1U) << pos) {}
};
