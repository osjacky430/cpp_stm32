/**
 * @file  stm32/f4/define/exti.hxx
 *@brief	This file contains exti class and enum define.
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

namespace cpp_stm32::exti {

enum class Line : std::uint8_t {
	Line0,
	Line1,
	Line2,
	Line3,
	Line4,
	Line5,
	Line6,
	Line7,
	Line8,
	Line9,
	Line10,
	Line11,
	Line12,
	Line13,
	Line14,
	Line15,
	Line16,
	Line17,
	Line18,
	Line19,
	Line20,
	Line21,
	Line22,
};

enum class TriggerType : std::uint8_t { Rise, Fall, Both };

}	 // namespace cpp_stm32::exti
