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

#include "cpp_stm32/target/stm32/common/gpio.hxx"
#include "cpp_stm32/target/stm32/l4/memory/memory_map.hxx"
#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::stm32 {

constexpr auto GPIO_BASE(gpio::Port const& t_port) noexcept {
	return memory_at(PeriphAddr::Ahb2Base, 0x0400U * to_underlying(t_port));
}

template <typename BitList, bool Atomicity, Access IoOp = Access::Word>
using GpioReg = Register<BitList, gpio::Pin, IoOp, Atomicity>;

constexpr auto GPIO_BASE(gpio::Port const&) noexcept;

/**
 * @defgroup GPIO_MODER_GROUP		GPIO Mode Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioModerInfo, /**/
										CREATE_LIST_OF_BITS<Bit<2, gpio::Mode>>(Interval<0, 30, 2>{}));

template <gpio::Port Port>
static constexpr GpioReg<GpioModerInfo, atomicity(GPIO_BASE(Port) + 0x00U)> GPIO_MODER{GPIO_BASE(Port), 0x00U};

/**@}*/

/**
 * @defgroup GPIO_PUPD_GROUP		GPIO Pullup Pulldown Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioPupdInfo, /**/
										CREATE_LIST_OF_BITS<Bit<2, gpio::Pupd>>(Interval<0, 30, 2>{}));

template <gpio::Port Port>
static constexpr GpioReg<GpioPupdInfo, atomicity(GPIO_BASE(Port) + 0x0CU)> GPIO_PUPDR{GPIO_BASE(Port), 0x0CU};

/**@}*/

/**
 * @defgroup GPIO_ODR_GROUP		GPIO Output Data Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioOdrInfo, /**/
										CREATE_LIST_OF_BITS<Bit<1>>(Interval<0, 15>{}));

template <gpio::Port Port>
static constexpr GpioReg<GpioOdrInfo, atomicity(GPIO_BASE(Port) + 0x14U)> GPIO_ODR{GPIO_BASE(Port), 0x14U};

/**@}*/

/**
 * @defgroup GPIO_BSRR_GROUP		Gpio Bit Set/Reset Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioBsrrInfo, /**/
										CREATE_LIST_OF_BITS<Binary<BitMod::WrOnly>>(Interval<0, 31>{}));

template <gpio::Port Port>
static constexpr GpioReg<GpioBsrrInfo, atomicity(GPIO_BASE(Port) + 0x18U)> GPIO_BSRR{GPIO_BASE(Port), 0x18U};

/**@}*/

/**
 * @defgroup GPIO_AFRH_AFRL_GROUP		GPIO Alternate Function Register High/Low declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioAfrInfo, /**/
										CREATE_LIST_OF_BITS<Bit<4, gpio::AltFunc>>(Interval<0, 28, 4>{}));

template <gpio::Port Port>
static constexpr GpioReg<GpioAfrInfo, atomicity(GPIO_BASE(Port) + 0x20U)> GPIO_AFRL{GPIO_BASE(Port), 0x20U};

template <gpio::Port Port>
static constexpr GpioReg<GpioAfrInfo, atomicity(GPIO_BASE(Port) + 0x24U)> GPIO_AFRH{GPIO_BASE(Port), 0x24U};

/**@}*/

/**
 * @defgroup GPIO_BRR_GROUP		GPIO Bit Reset Register declaration
 *
 * @note @ref STM32F302xx, STM32F303xx and STM32F313xx advanced ARM-based 32-bit MCUs.pdf
 * @{
 */

class GpioBrrInfo;

template <gpio::Port Port>
static constexpr GpioReg<GpioBrrInfo, atomicity(GPIO_BASE(Port) + 0x28U)> BASE_GPIO_BRR{GPIO_BASE(Port), 0x28U};

}	 // namespace cpp_stm32::stm32
