/**
 * @Date:   2019-12-19T02:54:22+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: gpio_reg.hxx
 */

#pragma once

#include "include/hal/bit/bit.hxx"
#include "include/hal/memory_map.hxx"
#include "include/hal/peripheral/memory/utility.hxx"
#include "include/hal/register/register.hxx"

enum class GpioPort { PortA, PortB, PortC, Total };

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
	PIn15,
	Total
};

enum class GpioMode { Input, Output, AltFunc, Analog };
enum class GpioPupd { None, PullUp, PullDown };
enum class GpioOutType { PushPull, OpenDrain };
enum class GpioOutSpeed { Low2M, Medium25M, Fast50M, High100M };
enum class GpioAltFunc { AF0, AF1, AF2, AF3 };

constexpr auto GPIO_BASE(const GpioPort t_port) {
	return memory_at(MemoryMap::Ahb1Base, 0x0400U * to_underlying(t_port));
}

/**
 * @defgroup GPIO_MODER_GROUP
 * @{
 */

SETUP_REGISTER_INFO(GpioModerInfo, /**/
										Bit<2, GpioMode>{BitPos_t(0)}, Bit<2, GpioMode>{BitPos_t(2)}, Bit<2, GpioMode>{BitPos_t(4)},
										Bit<2, GpioMode>{BitPos_t(6)}, Bit<2, GpioMode>{BitPos_t(8)}, Bit<2, GpioMode>{BitPos_t(10)},
										Bit<2, GpioMode>{BitPos_t(12)}, Bit<2, GpioMode>{BitPos_t(14)}, Bit<2, GpioMode>{BitPos_t(16)},
										Bit<2, GpioMode>{BitPos_t(18)}, Bit<2, GpioMode>{BitPos_t(20)}, Bit<2, GpioMode>{BitPos_t(22)},
										Bit<2, GpioMode>{BitPos_t(24)}, Bit<2, GpioMode>{BitPos_t(26)}, Bit<2, GpioMode>{BitPos_t(28)},
										Bit<2, GpioMode>{BitPos_t(30)})

template <GpioPort Port>
static constexpr Register<GpioModerInfo, GpioPin> GPIO_MODER{GPIO_BASE(Port), 0x00U};

/**@}*/

/**
 * @defgroup GPIO_PUPD_GROUP
 * @{
 */
SETUP_REGISTER_INFO(GpioPupdInfo, /**/
										Bit<2, GpioPupd>{BitPos_t(0)}, Bit<2, GpioPupd>{BitPos_t(2)}, Bit<2, GpioPupd>{BitPos_t(4)},
										Bit<2, GpioPupd>{BitPos_t(6)}, Bit<2, GpioPupd>{BitPos_t(8)}, Bit<2, GpioPupd>{BitPos_t(10)},
										Bit<2, GpioPupd>{BitPos_t(12)}, Bit<2, GpioPupd>{BitPos_t(14)}, Bit<2, GpioPupd>{BitPos_t(16)},
										Bit<2, GpioPupd>{BitPos_t(18)}, Bit<2, GpioPupd>{BitPos_t(20)}, Bit<2, GpioPupd>{BitPos_t(22)},
										Bit<2, GpioPupd>{BitPos_t(24)}, Bit<2, GpioPupd>{BitPos_t(26)}, Bit<2, GpioPupd>{BitPos_t(28)},
										Bit<2, GpioPupd>{BitPos_t(30)})

template <GpioPort Port>
static constexpr Register<GpioPupdInfo, GpioPin> GPIO_PUPDR{GPIO_BASE(Port), 0x0CU};

/**@}*/

/**
 * @defgroup GPIO_ODR_GROUP
 * @{
 */

SETUP_REGISTER_INFO(GpioOdrInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(3)},
										Bit<1>{BitPos_t(4)}, Bit<1>{BitPos_t(5)}, Bit<1>{BitPos_t(6)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(8)}, Bit<1>{BitPos_t(9)}, Bit<1>{BitPos_t(10)}, Bit<1>{BitPos_t(11)},
										Bit<1>{BitPos_t(12)}, Bit<1>{BitPos_t(13)}, Bit<1>{BitPos_t(14)}, Bit<1>{BitPos_t(15)})

template <GpioPort Port>
static constexpr Register<GpioOdrInfo, GpioPin> GPIO_ODR{GPIO_BASE(Port), 0x14U};

/**@}*/

/**
 * @defgroup GPIO_BSRR_GROUP
 * @{
 */

SETUP_REGISTER_INFO(GpioBsrInfo, /**/
										BinaryBit<BitMod::WriteOnly>{BitPos_t(0)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(1)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(2)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(3)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(4)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(5)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(6)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(7)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(8)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(9)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(10)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(11)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(12)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(13)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(14)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(15)})

template <GpioPort Port>
static constexpr Register<GpioBsrInfo, GpioPin> GPIO_BSR{GPIO_BASE(Port), 0x18U};

SETUP_REGISTER_INFO(GpioBrrInfo, /**/
										BinaryBit<BitMod::WriteOnly>{BitPos_t(16)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(17)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(18)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(19)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(20)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(21)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(22)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(23)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(24)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(25)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(26)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(27)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(28)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(29)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(30)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(31)})

template <GpioPort Port>
static constexpr Register<GpioBrrInfo, GpioPin> GPIO_BRR{GPIO_BASE(Port), 0x18U};

SETUP_REGISTER_INFO(GpioBsrrInfo, /**/
										BinaryBit<BitMod::WriteOnly>{BitPos_t(0)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(1)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(2)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(3)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(4)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(5)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(6)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(7)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(8)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(9)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(10)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(11)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(12)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(13)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(14)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(15)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(16)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(17)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(18)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(19)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(20)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(21)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(22)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(23)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(24)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(25)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(26)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(27)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(28)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(29)},
										BinaryBit<BitMod::WriteOnly>{BitPos_t(30)}, BinaryBit<BitMod::WriteOnly>{BitPos_t(31)})

template <GpioPort Port>
static constexpr Register<GpioBsrrInfo, GpioPin> GPIO_BSRR{GPIO_BASE(Port), 0x18U};

/**@}*/
