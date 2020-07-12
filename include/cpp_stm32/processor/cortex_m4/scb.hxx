/**
 * @file  cortex_m4/scb.hxx
 * @brief	Scb API for cortex m4
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

#include "cpp_stm32/processor/cortex_m4/define/scb.hxx"
#include "cpp_stm32/processor/cortex_m4/register/scb.hxx"

namespace cpp_stm32::scb {

constexpr void enable_mem_fault_handler() noexcept { reg::MMFSR.setBit<reg::MMFSRField::MMARVALID>(); }

constexpr void enable_vfp_coprocessor() noexcept {
	reg::CPACR.writeBit<reg::CPACRField::CP10, reg::CPACRField::CP11>(Access::Full);
}

}	// namespace cpp_stm32::scb
