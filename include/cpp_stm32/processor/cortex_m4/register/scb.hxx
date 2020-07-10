/**
 * @file  stm32/f4/register/scb.hxx
 * @brief	Scb registers of cortex m4
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

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::scb::reg {

static constexpr auto SCB_BASE = 0xE000ED00;

/**
 * @defgroup 	SCB_MMFSR_GROUP 	MemManage Status Register group
 *
 * @{
 */
SETUP_REGISTER_INFO(MMFSRBitList,						/**/
										Binary<>{BitPos_t{0}},	// IACCVIOL
										Binary<>{BitPos_t{1}},	// DACCVIOL
										Binary<>{BitPos_t{3}},	// MUNSTKERR
										Binary<>{BitPos_t{4}},	// MSTKERR
										Binary<>{BitPos_t{5}},	// MLSPERR
										Binary<>{BitPos_t{7}}		// MMARVALID
)

enum class MMFSRField {
	IACCVIOL,	/*!< Instruction fetch access violation*/
	DACCVIOL,	/*!< Data access violation*/
	MUNSTKERR, /*!< MemManage fault occurred on exception return*/
	MSTKERR,	 /*!< MemManage fault occurred on exception entry*/
	MLSPERR,	 /*!< MemManage fault occurred during FP lazy state preservation*/
	MMARVALID, /*!< MMFAR has valid contents*/
};

static constexpr Register<MMFSRBitList, MMFSRField> MMFSR{SCB_BASE, 0x28};

/**@}*/
}	// namespace cpp_stm32::scb::reg
