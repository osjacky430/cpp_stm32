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

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"
#include "cpp_stm32/target/stm32/f4/memory/memory_map.hxx"

namespace cpp_stm32::pwr {

enum class VoltageScale;

}

namespace cpp_stm32::pwr::reg {

static constexpr auto BASE_ADDR = memory_at(PeriphAddr::Apb1Base, 0x7000U);

/**
 * @defgroup  CR_GROUP		Power Control Register Group
 * @{
 */

SETUP_REGISTER_INFO(PwrCrInfo, /**/
										Bit<2, VoltageScale>{BitPos_t{14}}, Binary<>{BitPos_t{16}}, Binary<>{BitPos_t{17}})

enum class CrBit {
	Vos,
	OdEn,
	OdSwEn,
};

static constexpr Register<PwrCrInfo, CrBit> CR{BASE_ADDR, 0x00U};

/**@}*/

/**
 * @defgroup  CSR_GROUP		Power Control Status Register Group
 * @{
 */

SETUP_REGISTER_INFO(PwrCsrInfo, /**/
										StatusBit<1>{BitPos_t{14}}, StatusBit<1>{BitPos_t{16}}, StatusBit<1>{BitPos_t{17}})

enum class CsrBit { VosRdy, OdrRdy, OdrSwRdy };

static constexpr Register<PwrCsrInfo, CsrBit> CSR{BASE_ADDR, 0x04U};
/**@}*/

}	 // namespace cpp_stm32::pwr::reg
