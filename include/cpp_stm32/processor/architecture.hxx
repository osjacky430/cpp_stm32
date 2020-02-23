/**
 * @file  processor/architecture.hxx
 * @brief	This file contains architecture tags in order to generate correct vector table entry.
 *
 * @todo  Implement
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

namespace cpp_stm32 {

/**
 * @struct  ARMv6_M
 * @brief   Cortex-M0 / M0+ / M1 architecture
 */
struct ARMv6_M {};

/**
 * @struct  ARMv7_M
 * @brief   Cortex-M3 architecture
 *          Cortex-M4 / Cortex-M7 architecture  (ARMv7E_M = ARMv7_M with DSP extension)
 */
struct ARMv7_M {};

}	 // namespace cpp_stm32
