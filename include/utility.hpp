/**
 * @Date:   2019-11-20T17:34:25+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: utility.hpp
 * @Last modified time: 2019-11-21T15:29:27+08:00
 */

#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <cstdint>
#include <type_traits>

template <typename T>
constexpr decltype(auto) MMIO(std::uint32_t addr, const std::uint16_t offset) noexcept {
	return *reinterpret_cast<volatile T*>(addr + offset);
}

constexpr auto MMIO32 = MMIO<std::uint32_t>;
constexpr auto MMIO16 = MMIO<std::uint16_t>;
constexpr auto MMIO8 = MMIO<std::uint8_t>;

template <typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
constexpr auto to_underlying(Enum t_e) noexcept {
	return static_cast<std::underlying_type_t<Enum>>(t_e);
}

template <typename EnumA, typename EnumB>
constexpr auto operator+(EnumA t_a, EnumB t_b) {
	return to_underlying(t_a) + to_underlying(t_b);
}

#endif
