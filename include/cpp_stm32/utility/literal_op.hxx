/**
 * @Date:   2019-11-20T17:34:25+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: utility.hpp
 * @Last modified time: 2019-12-31T01:13:51+08:00
 */

#pragma once

#include <cstdint>
#include <type_traits>

constexpr auto operator"" _MHz(std::uint64_t freq) noexcept { return freq * 1000000ULL; }
constexpr auto operator"" _KHz(long double freq) noexcept { return freq * 1000ULL; }
constexpr auto operator"" _KHz(std::uint64_t freq) noexcept { return freq * 1000ULL; }
constexpr auto operator"" _MBaud(std::uint64_t Baud) noexcept { return Baud * 1000000ULL; }
