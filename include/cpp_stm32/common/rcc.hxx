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

#include "cpp_stm32/utility/integral_constant.hxx"

namespace cpp_stm32::rcc {

template <std::uint32_t Val>
using Frequency_t = uint32_c<Val>;

template <std::uint32_t Val>
static constexpr auto Frequency_v = Frequency_t<Val>{};

template <std::uint32_t Val>
using DivisionFactor_t = uint32_c<Val>;

template <std::uint32_t Val>
static constexpr auto DivisionFactor_v = DivisionFactor_t<Val>{};

}	 // namespace cpp_stm32::rcc
