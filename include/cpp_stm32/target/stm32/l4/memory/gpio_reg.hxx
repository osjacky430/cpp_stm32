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

#include "cpp_stm32/target/stm32/common/gpio_reg.hxx"
#include "cpp_stm32/target/stm32/l4/memory/memory_map.hxx"
#include "cpp_stm32/utility/bit.hxx"
#include "cpp_stm32/utility/register.hxx"

namespace cpp_stm32::common {

enum class GpioPort { PortA, PortB, PortC, PortD, PortE, PortF, PortH, Total };

enum class GpioPin {
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

enum class GpioMode {
	Input,	 /*!< Input mode */
	Output,	 /*!< Output mode */
	AltFunc, /*!< Alternate Function mode*/
	Analog	 /*!< Analog mode*/
};

enum class GpioPupd { None, PullUp, PullDown };
enum class GpioOutType { PushPull, OpenDrain };
enum class GpioOutSpeed { Low2M, Medium25M, Fast50M, High100M };
enum class GpioAltFunc { AF0, AF1, AF2, AF3, AF4, AF5, AF6, AF7 };

}	 // namespace cpp_stm32::common

namespace cpp_stm32::stm32 {

constexpr auto GPIO_BASE(common::GpioPort const& t_port) noexcept {
	return memory_at(PeriphAddr::Ahb2Base, 0x0400U * to_underlying(t_port));
}

/**
 * @ingroup GPIO_MODER_GROUP
 * @{
 */

SETUP_REGISTER_INFO(GpioModerInfo, /**/
										Bit<2, common::GpioMode>{BitPos_t(0)}, Bit<2, common::GpioMode>{BitPos_t(2)},
										Bit<2, common::GpioMode>{BitPos_t(4)}, Bit<2, common::GpioMode>{BitPos_t(6)},
										Bit<2, common::GpioMode>{BitPos_t(8)}, Bit<2, common::GpioMode>{BitPos_t(10)},
										Bit<2, common::GpioMode>{BitPos_t(12)}, Bit<2, common::GpioMode>{BitPos_t(14)},
										Bit<2, common::GpioMode>{BitPos_t(16)}, Bit<2, common::GpioMode>{BitPos_t(18)},
										Bit<2, common::GpioMode>{BitPos_t(20)}, Bit<2, common::GpioMode>{BitPos_t(22)},
										Bit<2, common::GpioMode>{BitPos_t(24)}, Bit<2, common::GpioMode>{BitPos_t(26)},
										Bit<2, common::GpioMode>{BitPos_t(28)}, Bit<2, common::GpioMode>{BitPos_t(30)});

template <common::GpioPort Port>
static constexpr auto GPIO_MODER = BASE_GPIO_MODER<GPIO_BASE(Port), 0x00U>;

/**@}*/

/**
 * @ingroup GPIO_PUPD_GROUP
 * @{
 */

SETUP_REGISTER_INFO(GpioPupdInfo, /**/
										Bit<2, common::GpioPupd>{BitPos_t(0)}, Bit<2, common::GpioPupd>{BitPos_t(2)},
										Bit<2, common::GpioPupd>{BitPos_t(4)}, Bit<2, common::GpioPupd>{BitPos_t(6)},
										Bit<2, common::GpioPupd>{BitPos_t(8)}, Bit<2, common::GpioPupd>{BitPos_t(10)},
										Bit<2, common::GpioPupd>{BitPos_t(12)}, Bit<2, common::GpioPupd>{BitPos_t(14)},
										Bit<2, common::GpioPupd>{BitPos_t(16)}, Bit<2, common::GpioPupd>{BitPos_t(18)},
										Bit<2, common::GpioPupd>{BitPos_t(20)}, Bit<2, common::GpioPupd>{BitPos_t(22)},
										Bit<2, common::GpioPupd>{BitPos_t(24)}, Bit<2, common::GpioPupd>{BitPos_t(26)},
										Bit<2, common::GpioPupd>{BitPos_t(28)}, Bit<2, common::GpioPupd>{BitPos_t(30)});

template <common::GpioPort Port>
static constexpr auto GPIO_PUPDR = BASE_GPIO_PUPDR<GPIO_BASE(Port), 0x0CU>;

/**@}*/

/**
 * @ingroup GPIO_ODR_GROUP
 * @{
 */

SETUP_REGISTER_INFO(GpioOdrInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(3)},
										Bit<1>{BitPos_t(4)}, Bit<1>{BitPos_t(5)}, Bit<1>{BitPos_t(6)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(8)}, Bit<1>{BitPos_t(9)}, Bit<1>{BitPos_t(10)}, Bit<1>{BitPos_t(11)},
										Bit<1>{BitPos_t(12)}, Bit<1>{BitPos_t(13)}, Bit<1>{BitPos_t(14)}, Bit<1>{BitPos_t(15)});

template <common::GpioPort Port>
static constexpr auto GPIO_ODR = BASE_GPIO_ODR<GPIO_BASE(Port), 0x14U>;

/**@}*/

/**
 * @ingroup GPIO_BSRR_GROUP
 * @{
 */

SETUP_REGISTER_INFO(
	GpioBsrrInfo, /**/
	Binary<BitMod::WrOnly>{BitPos_t(0)}, Binary<BitMod::WrOnly>{BitPos_t(1)}, Binary<BitMod::WrOnly>{BitPos_t(2)},
	Binary<BitMod::WrOnly>{BitPos_t(3)}, Binary<BitMod::WrOnly>{BitPos_t(4)}, Binary<BitMod::WrOnly>{BitPos_t(5)},
	Binary<BitMod::WrOnly>{BitPos_t(6)}, Binary<BitMod::WrOnly>{BitPos_t(7)}, Binary<BitMod::WrOnly>{BitPos_t(8)},
	Binary<BitMod::WrOnly>{BitPos_t(9)}, Binary<BitMod::WrOnly>{BitPos_t(10)}, Binary<BitMod::WrOnly>{BitPos_t(11)},
	Binary<BitMod::WrOnly>{BitPos_t(12)}, Binary<BitMod::WrOnly>{BitPos_t(13)}, Binary<BitMod::WrOnly>{BitPos_t(14)},
	Binary<BitMod::WrOnly>{BitPos_t(15)}, Binary<BitMod::WrOnly>{BitPos_t(16)}, Binary<BitMod::WrOnly>{BitPos_t(17)},
	Binary<BitMod::WrOnly>{BitPos_t(18)}, Binary<BitMod::WrOnly>{BitPos_t(19)}, Binary<BitMod::WrOnly>{BitPos_t(20)},
	Binary<BitMod::WrOnly>{BitPos_t(21)}, Binary<BitMod::WrOnly>{BitPos_t(22)}, Binary<BitMod::WrOnly>{BitPos_t(23)},
	Binary<BitMod::WrOnly>{BitPos_t(24)}, Binary<BitMod::WrOnly>{BitPos_t(25)}, Binary<BitMod::WrOnly>{BitPos_t(26)},
	Binary<BitMod::WrOnly>{BitPos_t(27)}, Binary<BitMod::WrOnly>{BitPos_t(28)}, Binary<BitMod::WrOnly>{BitPos_t(29)},
	Binary<BitMod::WrOnly>{BitPos_t(30)}, Binary<BitMod::WrOnly>{BitPos_t(31)});

template <common::GpioPort Port>
static constexpr auto GPIO_BSRR = BASE_GPIO_BSRR<GPIO_BASE(Port), 0x18U>;

/**@}*/

}	 // namespace cpp_stm32::stm32
