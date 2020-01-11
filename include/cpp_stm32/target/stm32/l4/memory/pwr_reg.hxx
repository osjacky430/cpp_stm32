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

#include "cpp_stm32/target/stm32/l4/memory/memory_map.hxx"
#include "cpp_stm32/utility/bit.hxx"
#include "cpp_stm32/utility/register.hxx"

namespace cpp_stm32::stm32::l4 {

/*!< */
static constexpr auto PWR_BASE = memory_at(PeriphAddr::Apb1Base, 0x7000U);

/**
 * @defgroup  PWR_CR_GROUP		Power Control Register Group
 * @{
 */

enum class VoltageScale;

SETUP_REGISTER_INFO(PwrCrInfo, /**/
										Bit<2, VoltageScale>{BitPos_t{9}})

enum class PwrCrBit {
	Vos,
};

static constexpr Register<PwrCrInfo, PwrCrBit> PWR_CR{PWR_BASE, 0x00U};

/**@}*/

}	// namespace cpp_stm32::stm32::l4
