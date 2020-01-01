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
#include <type_traits>

constexpr auto operator"" _MHz(std::uint64_t freq) noexcept { return freq * 1000000ULL; }
constexpr auto operator"" _KHz(long double freq) noexcept { return freq * 1000ULL; }
constexpr auto operator"" _KHz(std::uint64_t freq) noexcept { return freq * 1000ULL; }
constexpr auto operator"" _MBaud(std::uint64_t Baud) noexcept { return Baud * 1000000ULL; }
