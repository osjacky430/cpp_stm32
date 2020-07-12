/**
 * @file  hal/mmio.hxx
 * @brief	Abstraction of memory mapped io operation
 */

/** Copyright (c) 2020 by osjacky430.
 * All Rights Reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstdint>

#include "cpp_stm32/utility/utility.hxx"

namespace cpp_stm32 {

// use enum class and self defined operator can deal with the problem easily
template <typename T>
constexpr decltype(auto) MMIO(std::uint32_t addr, std::uint32_t const offset) noexcept {
	return *reinterpret_cast<volatile T*>(addr + offset);
}

static constexpr auto const MMIO32 = MMIO<std::uint32_t>;
static constexpr auto const MMIO16 = MMIO<std::uint16_t>;
static constexpr auto const MMIO8	= MMIO<std::uint8_t>;

}	// namespace cpp_stm32
