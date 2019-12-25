/**
 * @Date:   2019-11-20T17:34:25+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: utility.hpp
 * @Last modified time: 2019-12-25T02:07:08+08:00
 */

#pragma once

#include <cstdint>
#include <type_traits>

template <typename T>
constexpr decltype(auto) MMIO(std::uint32_t addr, const std::uint16_t offset) noexcept {
	return *reinterpret_cast<volatile T*>(addr + offset);
}

constexpr auto MMIO32 = MMIO<std::uint32_t>;
constexpr auto MMIO16 = MMIO<std::uint16_t>;
constexpr auto MMIO8	= MMIO<std::uint8_t>;

template <typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
constexpr auto to_underlying(Enum t_e) noexcept {
	return static_cast<std::underlying_type_t<Enum>>(t_e);
}

constexpr auto operator"" _MHz(std::uint64_t freq) noexcept { return freq * 1000000ULL; }
constexpr auto operator"" _KHz(long double freq) noexcept { return freq * 1000ULL; }
constexpr auto operator"" _KHz(std::uint64_t freq) noexcept { return freq * 1000ULL; }
constexpr auto operator"" _MBaud(std::uint64_t Baud) noexcept { return Baud * 1000000ULL; }
