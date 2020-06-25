#pragma once

#include "cpp_stm32/detail/index_range.hxx"
#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"
#include "cpp_stm32/processor/cortex_m4/memory/bit_banding.hxx"
#include "cpp_stm32/target/stm32/l4/define/gpio.hxx"
#include "cpp_stm32/target/stm32/l4/register/memory_map.hxx"

namespace cpp_stm32::gpio::reg {

constexpr auto BASE_ADDR(Port const t_port) noexcept {
	return memory_at(PeriphAddr::Ahb2Base, 0x0400U * to_underlying(t_port));
}

template <typename BitList, bool Atomicity, Access IoOp = Access::Word>
using GpioReg = Register<BitList, Pin, IoOp, Atomicity>;

/**
 * @defgroup MODER_GROUP		GPIO Mode Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioModerInfo, /**/
										CREATE_LIST_OF_BITS<Bit<2, Mode>>(detail::IdxRange<0, 30, 2>{}));

template <gpio::Port Port>
static constexpr GpioReg<GpioModerInfo, atomicity(BASE_ADDR(Port) + 0x00U)> MODER{BASE_ADDR(Port), 0x00U};

/**@}*/

/**
 * @defgroup PUPD_GROUP		GPIO Pullup Pulldown Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioPupdInfo, /**/
										CREATE_LIST_OF_BITS<Bit<2, gpio::Pupd>>(detail::IdxRange<0, 30, 2>{}));

template <gpio::Port Port>
static constexpr GpioReg<GpioPupdInfo, atomicity(BASE_ADDR(Port) + 0x0CU)> PUPDR{BASE_ADDR(Port), 0x0CU};

/**@}*/

/**
 * @defgroup ODR_GROUP		GPIO Output Data Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioOdrInfo, /**/
										CREATE_LIST_OF_BITS<Bit<1>>(detail::IdxRange<0, 15>{}));

template <gpio::Port Port>
static constexpr GpioReg<GpioOdrInfo, atomicity(BASE_ADDR(Port) + 0x14U)> ODR{BASE_ADDR(Port), 0x14U};

/**@}*/

/**
 * @defgroup BSRR_GROUP		Gpio Bit Set/Reset Register declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioBsrrInfo, /**/
										CREATE_LIST_OF_BITS<Binary<BitMod::WrOnly>>(detail::IdxRange<0, 31>{}));

template <gpio::Port Port>
static constexpr GpioReg<GpioBsrrInfo, atomicity(BASE_ADDR(Port) + 0x18U)> BSRR{BASE_ADDR(Port), 0x18U};

/**@}*/

/**
 * @defgroup AFRH_AFRL_GROUP		GPIO Alternate Function Register High/Low declaration
 * @{
 */

SETUP_REGISTER_INFO(GpioAfrInfo, /**/
										CREATE_LIST_OF_BITS<Bit<4, gpio::AltFunc>>(detail::IdxRange<0, 28, 4>{}));

template <gpio::Port Port>
static constexpr GpioReg<GpioAfrInfo, atomicity(BASE_ADDR(Port) + 0x20U)> AFRL{BASE_ADDR(Port), 0x20U};

template <gpio::Port Port>
static constexpr GpioReg<GpioAfrInfo, atomicity(BASE_ADDR(Port) + 0x24U)> AFRH{BASE_ADDR(Port), 0x24U};

/**@}*/

/**
 * @defgroup BRR_GROUP		GPIO Bit Reset Register declaration
 *
 * @note @ref STM32F302xx, STM32F303xx and STM32F313xx advanced ARM-based 32-bit MCUs.pdf
 * @{
 */

class GpioBrrInfo;

template <gpio::Port Port>
static constexpr GpioReg<GpioBrrInfo, atomicity(BASE_ADDR(Port) + 0x28U)> BRR{BASE_ADDR(Port), 0x28U};

}	 // namespace cpp_stm32::gpio::reg
