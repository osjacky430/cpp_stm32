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

#include "cpp_stm32/detail/index_interval.hxx"
#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"
#include "cpp_stm32/processor/cortex_m4/memory/internal_periph.hxx"

namespace cpp_stm32 {

enum class IrqNum : std::uint8_t;

}	 // namespace cpp_stm32

namespace cpp_stm32::nvic::reg {

static constexpr auto NVIC_BASE = to_underlying(Scs::NvicBase);

static constexpr auto NVIC_GROUP_OFFSET(IrqNum const& IRQn) { return 0x04U * (to_underlying(IRQn) / 32U); }
static constexpr auto NVIC_IP_GROUP_OFFSET(IrqNum const& IRQn) { return 0x04U * (to_underlying(IRQn) / 4U); }
static constexpr auto NVIC_IRQ_BIT_POS(IrqNum const& IRQn) {
	enum class NvicIdx : std::uint32_t {};

	return NvicIdx{to_underlying(IRQn) % 32U};
}

using NvicIdxType = decltype(NVIC_IRQ_BIT_POS(IrqNum{0}));

/**
 *  @defgroup NVIC_ISER_GROUP		NVIC Iterrupt Set Enable Register Group
 *  @{
 */
SETUP_REGISTER_INFO(NvicIserInfo, CREATE_LIST_OF_BITS<Binary<BitMod::RdSet>>(detail::Interval<0, 31>{}));

template <IrqNum IRQn>
static constexpr Register<NvicIserInfo, NvicIdxType> NVIC_ISER{NVIC_BASE, NVIC_GROUP_OFFSET(IRQn)};

/**@}*/

/**
 * @defgroup NVIC_ICER_GROUP		NVIC Interrupt Clear Enable Register Group
 * @{
 */
SETUP_REGISTER_INFO(NvicIcerInfo, CREATE_LIST_OF_BITS<Binary<BitMod::RdClrWr1>>(detail::Interval<0, 31>{}))

template <IrqNum IRQn>
static constexpr Register<NvicIcerInfo, NvicIdxType> NVIC_ICER{NVIC_BASE, 0x80U + NVIC_GROUP_OFFSET(IRQn)};

/**@}*/

/**
 * @defgroup  NVIC_ISPR_GROUP		NVIC Interrupt Set Pending Register Group
 * @{
 */
SETUP_REGISTER_INFO(NvicIsprInfo, CREATE_LIST_OF_BITS<Binary<BitMod::RdSet>>(detail::Interval<0, 31>{}))

template <IrqNum IRQn>
static constexpr Register<NvicIsprInfo, NvicIdxType> NVIC_ISPR{NVIC_BASE, 0x100U + NVIC_GROUP_OFFSET(IRQn)};
/**@}*/

/**
 * @defgroup  NVIC_ICPR_GROUP		NVIC Interrupt Clear Pending Regsiter Group
 * @{
 */
SETUP_REGISTER_INFO(NvicIcprInfo, CREATE_LIST_OF_BITS<Binary<BitMod::RdClrWr1>>(detail::Interval<0, 31>{}))

template <IrqNum IRQn>
static constexpr Register<NvicIcprInfo, NvicIdxType> NVIC_ICPR{NVIC_BASE, 0x180U + NVIC_GROUP_OFFSET(IRQn)};
/**@}*/

/**
 * @defgroup  NVIC_IABR_GROUP		NVIC Interrupt Active Bit Register Group
 * @{
 */
SETUP_REGISTER_INFO(NvicIabrInfo, CREATE_LIST_OF_BITS<Binary<BitMod::RdClrWr1>>(detail::Interval<0, 31>{}))

template <IrqNum IRQn>
static constexpr Register<NvicIabrInfo, NvicIdxType> NVIC_IABR{NVIC_BASE, 0x200U + NVIC_GROUP_OFFSET(IRQn)};
/**@}*/

/**
 * @defgroup NVIC_IPR_GROUP		NVIC Interrupt Priority Register Group
 * @{
 */
SETUP_REGISTER_INFO(NvicIprInfo, Bit<8, std::uint8_t>{BitPos_t{0}})

enum class NvicIprBit { Ip };

template <IrqNum IRQn>
static constexpr Register<NvicIprInfo, NvicIprBit, Access::Byte> NVIC_IPR{NVIC_BASE,
																																					0x300U + NVIC_IP_GROUP_OFFSET(IRQn)};
/**@}*/

/**
 * @defgroup NVIC_STIR_GROUP		NVIC Software Trigger Interrupt Register Group
 * @{
 */

SETUP_REGISTER_INFO(NvicStirInfo, Bit<9, std::uint16_t, BitMod::WrOnly>{BitPos_t{0}})

enum class NvicStirBit { IntId };

// this is rather special cause nvic register is separated to two parts
static constexpr Register<NvicStirInfo, NvicStirBit> NVIC_STIR{NVIC_BASE, 0xD00};
/**@}*/

}	 // namespace cpp_stm32::nvic::reg
