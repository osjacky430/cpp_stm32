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
	Pin15,
	Total
};

enum class GpioMode { Input, Output, AltFunc, Analog };
enum class GpioPupd { None, PullUp, PullDown };
enum class GpioOutType { PushPull, OpenDrain };
enum class GpioOutSpeed { Low2M, Medium25M, Fast50M, High100M };
enum class GpioAltFunc { AF0, AF1, AF2, AF3, AF4, AF5, AF6, AF7 };

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

SETUP_REGISTER_INFO(GpioBsrrInfo, /**/
										Binary<BitMod::WriteOnly>{BitPos_t(0)}, Binary<BitMod::WriteOnly>{BitPos_t(1)},
										Binary<BitMod::WriteOnly>{BitPos_t(2)}, Binary<BitMod::WriteOnly>{BitPos_t(3)},
										Binary<BitMod::WriteOnly>{BitPos_t(4)}, Binary<BitMod::WriteOnly>{BitPos_t(5)},
										Binary<BitMod::WriteOnly>{BitPos_t(6)}, Binary<BitMod::WriteOnly>{BitPos_t(7)},
										Binary<BitMod::WriteOnly>{BitPos_t(8)}, Binary<BitMod::WriteOnly>{BitPos_t(9)},
										Binary<BitMod::WriteOnly>{BitPos_t(10)}, Binary<BitMod::WriteOnly>{BitPos_t(11)},
										Binary<BitMod::WriteOnly>{BitPos_t(12)}, Binary<BitMod::WriteOnly>{BitPos_t(13)},
										Binary<BitMod::WriteOnly>{BitPos_t(14)}, Binary<BitMod::WriteOnly>{BitPos_t(15)},
										Binary<BitMod::WriteOnly>{BitPos_t(16)}, Binary<BitMod::WriteOnly>{BitPos_t(17)},
										Binary<BitMod::WriteOnly>{BitPos_t(18)}, Binary<BitMod::WriteOnly>{BitPos_t(19)},
										Binary<BitMod::WriteOnly>{BitPos_t(20)}, Binary<BitMod::WriteOnly>{BitPos_t(21)},
										Binary<BitMod::WriteOnly>{BitPos_t(22)}, Binary<BitMod::WriteOnly>{BitPos_t(23)},
										Binary<BitMod::WriteOnly>{BitPos_t(24)}, Binary<BitMod::WriteOnly>{BitPos_t(25)},
										Binary<BitMod::WriteOnly>{BitPos_t(26)}, Binary<BitMod::WriteOnly>{BitPos_t(27)},
										Binary<BitMod::WriteOnly>{BitPos_t(28)}, Binary<BitMod::WriteOnly>{BitPos_t(29)},
										Binary<BitMod::WriteOnly>{BitPos_t(30)}, Binary<BitMod::WriteOnly>{BitPos_t(31)})

template <GpioPort Port>
static constexpr Register<GpioBsrrInfo, GpioPin> GPIO_BSRR{GPIO_BASE(Port), 0x18U};

/**@}*/

SETUP_REGISTER_INFO(GpioAfrInfo, /**/
										Bit<4, GpioAltFunc>{BitPos_t{0}}, Bit<4, GpioAltFunc>{BitPos_t{4}},
										Bit<4, GpioAltFunc>{BitPos_t{8}}, Bit<4, GpioAltFunc>{BitPos_t{12}},
										Bit<4, GpioAltFunc>{BitPos_t{16}}, Bit<4, GpioAltFunc>{BitPos_t{20}},
										Bit<4, GpioAltFunc>{BitPos_t{24}}, Bit<4, GpioAltFunc>{BitPos_t{28}})

template <GpioPort Port>
static constexpr Register<GpioAfrInfo, GpioPin> GPIO_AFRL{GPIO_BASE(Port), 0x20U};

template <GpioPort Port>
static constexpr Register<GpioAfrInfo, GpioPin> GPIO_AFRH{GPIO_BASE(Port), 0x24U};
