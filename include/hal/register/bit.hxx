/**
 * @Date:   2019-12-11T18:51:06+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: bit.hxx
 * @Last modified time: 2019-12-11T20:35:22+08:00
 */

#pragma once

#include <cstdint>

class Bit {
 private:
	std::uint32_t const m_pos;
	std::uint32_t const m_length;
	std::uint32_t const m_mask;

	static constexpr auto CALC_MASK = []() { return ((1U << m_length) - 1U) << m_pos; };

 public:
	constexpr Bit(std::uint32_t const t_pos, std::uint32_t const t_length)
		: m_pos(t_pos), m_length(t_length), m_mask(CALC_MASK()) {}
};
