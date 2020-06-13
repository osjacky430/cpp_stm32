/**
 * @file  stm32/f4/register/exti.hxx
 * @brief	Exti registers of stm32f4
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

#include "cpp_stm32/target/stm32/f4/define/exti.hxx"

namespace cpp_stm32::exti::reg {

static constexpr auto BASE_ADDR = 0x40013c00U;

SETUP_REGISTER_INFO(ExtiBitList, CREATE_LIST_OF_BITS<Binary<>>(detail::IdxRange<0, 22>{}))

/**
 * @defgroup	EXTI_IMR_GROUP		Interrupt mask register (EXTI_IMR) group
 *
 * @{
 */

static constexpr Register<ExtiBitList, Line> IMR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	EXTI_EMR_GROUP		Event mask register (EXTI_EMR) group
 *
 * @{
 */

static constexpr Register<ExtiBitList, Line> EMR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	EXTI_RTSR_GROUP		Rising Trigger selection register (EXTI_RTSR) group
 *
 * @{
 */

static constexpr Register<ExtiBitList, Line> RTSR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	EXTI_FTSR_GROUP		Falling Trigger selection register (EXTI_FTSR) group
 *
 * @{
 */

static constexpr Register<ExtiBitList, Line> FTSR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	EXTI_SWIER_GROUP		Software interrupt event register (EXTI_SWIER) group
 *
 * @{
 */

static constexpr Register<ExtiBitList, Line> SWIER{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	EXTI_PR_GROUP		Pending register (EXTI_PR) group
 *
 * @{
 */

SETUP_REGISTER_INFO(PRBitList, CREATE_LIST_OF_BITS<Binary<BitMod::RdClrWr1>>(detail::IdxRange<0, 22>{}))

static constexpr Register<PRBitList, Line> PR{BASE_ADDR, 0x14U};
/**@}*/

}	 // namespace cpp_stm32::exti::reg
