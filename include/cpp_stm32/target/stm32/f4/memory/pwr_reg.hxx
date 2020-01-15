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
#include <tuple>

#include "cpp_stm32/target/stm32/f4/memory/memory_map.hxx"
#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::stm32::f4 {

static constexpr auto PWR_BASE = memory_at(PeriphAddr::Apb1Base, 0x7000U);

/**
 * @defgroup  PWR_CR_GROUP		Power Control Register Group
 * @{
 */

enum class VoltageScale;

SETUP_REGISTER_INFO(PwrCrInfo, /**/
										Bit<2, VoltageScale>{BitPos_t{14}}, Binary<>{BitPos_t{16}}, Binary<>{BitPos_t{17}})

enum class PwrCrBit {
	Vos,
	OdEn,
	OdSwEn,
};

static constexpr Register<PwrCrInfo, PwrCrBit> PWR_CR{PWR_BASE, 0x00U};

/**@}*/

/**
 * @defgroup  PWR_CSR_GROUP		Power Control Status Register Group
 * @{
 */

SETUP_REGISTER_INFO(PwrCsrInfo, /**/
										StatusBit<1>{BitPos_t{14}}, StatusBit<1>{BitPos_t{16}}, StatusBit<1>{BitPos_t{17}})

enum class PwrCsrBit { VosRdy, OdrRdy, OdrSwRdy };

static constexpr Register<PwrCsrInfo, PwrCsrBit> PWR_CSR{PWR_BASE, 0x04U};
/**@}*/

}	 // namespace cpp_stm32::stm32::f4
