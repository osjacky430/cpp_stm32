/**
 * @file  stm32/f4/scb.hxx
 * @brief	Scb setup API for stm32f4
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

namespace cpp_stm32::scb {

class [[gnu::packed]] ExceptionStackFrame {
	std::uint32_t r0;
	std::uint32_t r1;
	std::uint32_t r2;
	std::uint32_t r3;
	std::uint32_t r4;
	std::uint32_t r12;
	std::uint32_t lr;
	std::uint32_t pc;
	std::uint32_t xpsr;
};

// @todo finish this
constexpr void set_priority_grouping() noexcept {}

}	 // namespace cpp_stm32::scb
