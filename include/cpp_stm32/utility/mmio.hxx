/**
 * @Date:   2019-12-31T01:12:00+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: mmio.hxx
 * @Last modified time: 2019-12-31T01:13:48+08:00
 */

#pragma once

#include <cstdint>

#include "cpp_stm32/utility/utility.hxx"

template <typename T>
constexpr decltype(auto) MMIO(std::uint32_t addr, const std::uint16_t offset) noexcept {
	return *reinterpret_cast<volatile T*>(addr + offset);
}

constexpr auto MMIO32 = MMIO<std::uint32_t>;
constexpr auto MMIO16 = MMIO<std::uint16_t>;
constexpr auto MMIO8	= MMIO<std::uint8_t>;

enum class Access { Word = 0b100, HalfWord = 0b010, Byte = 0b001 };
constexpr auto operator|(Access const& lhs, Access const& rhs) {
	return Access{to_underlying(lhs) | to_underlying(rhs)};
}
