/**
 * @file  stm32/f4/memory/gpio_reg.hxx
 * @brief	This file contains gpio registers.
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
#include "cpp_stm32/processor/cortex_m4/memory/bit_banding.hxx"
#include "cpp_stm32/target/stm32/f4/memory/memory_map.hxx"

#include "cpp_stm32/detail/index_interval.hxx"

namespace cpp_stm32::gpio {

enum class Port { PortA, PortB, PortC, PortD, PortE, PortF, PortG, PortH, Total };

enum class Pin {
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7,
	Pin8,
	Pin9,
	Pin10,
	Pin11,
	Pin12,
	Pin13,
	Pin14,
	Pin15,
	Total
};

/**
 * @enum 	Mode
 * @brief	Gpio Mode
 */
enum class Mode {
	Input,	 /*!< Input mode */
	Output,	 /*!< Output mode */
	AltFunc, /*!< Alternate Function mode*/
	Analog	 /*!< Analog mode*/
};

enum class Pupd { None, PullUp, PullDown };
enum class OutputType { PushPull, OpenDrain };
enum class OutputSpeed { Low, Medium, Fast, High };
enum class AltFunc { AF0, AF1, AF2, AF3, AF4, AF5, AF6, AF7, AF8, AF9, AF10, AF11, AF12, AF13, AF14, AF15 };

/**
 * @enum  PinName
 */
enum class PinName { PA_1, PA_2, PA_3, PA_5, PB_1, PB_2, PB_3, Total, NC };

}	 // namespace cpp_stm32::gpio

namespace cpp_stm32::gpio::reg {

constexpr auto BASE_ADDR(Port const& t_port) noexcept {
	return memory_at(PeriphAddr::Ahb1Base, 0x0400U * to_underlying(t_port));
}

template <typename BitList, bool Atomicity, Access IoOp = Access::Word>
using GpioReg = Register<BitList, gpio::Pin, IoOp, Atomicity>;

/**
 * @defgroup MODER_GROUP		GPIO Mode Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioModerInfo, /**/
										CREATE_LIST_OF_BITS<Bit<2, Mode>>(detail::Interval<0, 30, 2>{}));

template <Port GPIO>
static constexpr GpioReg<GpioModerInfo, atomicity(BASE_ADDR(GPIO) + 0x00U)> MODER{BASE_ADDR(GPIO), 0x00U};

/**@}*/

/**
 * @defgroup	GPIOA_OTYPER_GROUP		GPIO port output type register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OTYPERBitList, /**/
										CREATE_LIST_OF_BITS<Bit<1, OutputType>>(detail::Interval<0, 15, 1>{}))

template <Port GPIO>
static constexpr GpioReg<OTYPERBitList, atomicity(BASE_ADDR(GPIO) + 0x04U)> OTYPER{BASE_ADDR(GPIO), 0x04U};
/**@}*/

/**
 * @defgroup	GPIOA_OSPEEDR_GROUP		GPIO port output speed register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OSPEEDRBitList, /**/
										CREATE_LIST_OF_BITS<Bit<2, OutputSpeed>>(detail::Interval<0, 30, 2>{}))

template <Port GPIO>
static constexpr GpioReg<OSPEEDRBitList, atomicity(BASE_ADDR(GPIO) + 0x08U)> OSPEEDR{BASE_ADDR(GPIO), 0x08U};
/**@}*/

/**
 * @defgroup PUPD_GROUP		GPIO Pullup Pulldown Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioPupdInfo, /**/
										CREATE_LIST_OF_BITS<Bit<2, Pupd>>(detail::Interval<0, 30, 2>{}));

template <Port GPIO>
static constexpr GpioReg<GpioPupdInfo, atomicity(BASE_ADDR(GPIO) + 0x0CU)> PUPDR{BASE_ADDR(GPIO), 0x0CU};

/**@}*/

/**
 * @defgroup ODR_GROUP		GPIO Output Data Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioOdrInfo, /**/
										CREATE_LIST_OF_BITS<Bit<1>>(detail::Interval<0, 15>{}));

template <Port GPIO>
static constexpr GpioReg<GpioOdrInfo, atomicity(BASE_ADDR(GPIO) + 0x14U)> ODR{BASE_ADDR(GPIO), 0x14U};

/**@}*/

/**
 * @defgroup BSRR_GROUP		Gpio Bit Set/Reset Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioBsrrInfo, /**/
										CREATE_LIST_OF_BITS<Binary<BitMod::WrOnly>>(detail::Interval<0, 31>{}));

template <Port GPIO>
static constexpr GpioReg<GpioBsrrInfo, atomicity(BASE_ADDR(GPIO) + 0x18U)> BSRR{BASE_ADDR(GPIO), 0x18U};

/**@}*/

/**
 * @defgroup AFRH_AFRL_GROUP		GPIO Alternate Function Register High/Low declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioAfrInfo, /**/
										CREATE_LIST_OF_BITS<Bit<4, AltFunc>>(detail::Interval<0, 28, 4>{}));

template <Port GPIO>
static constexpr GpioReg<GpioAfrInfo, atomicity(BASE_ADDR(GPIO) + 0x20U)> AFRL{BASE_ADDR(GPIO), 0x20U};

template <Port GPIO>
static constexpr GpioReg<GpioAfrInfo, atomicity(BASE_ADDR(GPIO) + 0x24U)> AFRH{BASE_ADDR(GPIO), 0x24U};

/**@}*/

}	 // namespace cpp_stm32::gpio::reg
