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
#include <type_traits>

#include "cpp_stm32/target/stm32/common/macro.hxx"
#include "cpp_stm32/target/stm32/l4/memory/memory_map.hxx"
#include "cpp_stm32/utility/bit.hxx"
#include "cpp_stm32/utility/register.hxx"

namespace cpp_stm32::stm32::l4 {

;
static constexpr auto FLASH_BASE = memory_at(PeriphAddr::Ahb1Base, 0x2'000U);

struct FlashLatency;

template <std::uint8_t Val>
using CpuWaitState_t = std::integral_constant<std::uint8_t, Val>;

template <std::uint8_t Val>
static constexpr auto CpuWaitState_v = CpuWaitState_t<Val>{};

/**
 * @defgroup FLASH_ACR_GROUP    Flash Access Control Register Group
 * @{
 */

SETUP_FLASH_LATENCY(0, 4);

SETUP_REGISTER_INFO(FlashAcrInfo, /**/
										Bit<3, FlashLatency>{BitPos_t{0}}, Binary<>{BitPos_t{8}}, Binary<>{BitPos_t{9}},
										Binary<>{BitPos_t{10}}, Binary<>{BitPos_t{11}}, Binary<>{BitPos_t{12}})

enum class FlashAcrBit {
	Latency,
	PrftEn,
	ICEn,
	DCEn,
	ICRst,
	DCRst,
};

static constexpr Register<FlashAcrInfo, FlashAcrBit> FLASH_ACR{FLASH_BASE, 0x00U};

/**@}*/

}	// namespace cpp_stm32::stm32::l4
