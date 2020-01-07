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

#include "cpp_stm32/utility/bit.hxx"
#include "cpp_stm32/utility/constexpr_algo.hxx"
#include "cpp_stm32/utility/register.hxx"

namespace cpp_stm32::stm32::l4 {

static constexpr auto RCC_BASE = memory_at(PeriphAddr::Ahb1Base, 0x1000U);

// @todo I think this can be put in common
template <std::uint32_t Val>
using DivisionFactor_t = std::integral_constant<std::uint32_t, Val>;

template <std::uint32_t Val>
static constexpr auto DivisionFactor_v = DivisionFactor_t<Val>{};

enum class RccOsc : std::uint32_t;

/**
 * @defgroup	RCC_AHB2RST_GROUP		RCC AHB2 Reset Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccAhb2RstInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(13)}, Bit<1>{BitPos_t(18)})

enum class RccAhb2RstBit { GpioARst, GpioBRst, GpioCRst, GpioHRst, AdcRst, RngRst };

static constexpr Register<RccAhb2RstInfo, RccAhb2RstBit> RCC_AHB2RST{RCC_BASE, 0x2CU};

/**@}*/

/**
 * @defgroup	RCC_AHB2ENR_GROUP		RCC AHB2 Enable Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccAhb2EnrInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(13)}, Bit<1>{BitPos_t(18)})

enum class RccAhb2EnrBit { GpioAEnr, GpioBEnr, GpioCEnr, GpioHEnr, AdcEnr, RngEnr };

static constexpr Register<RccAhb2EnrInfo, RccAhb2EnrBit> RCC_AHB2RST{RCC_BASE, 0x4CU};

/**@}*/

}	 // namespace cpp_stm32::stm32::l4
