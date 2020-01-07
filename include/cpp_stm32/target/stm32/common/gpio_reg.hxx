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

#include "cpp_stm32/common/gpio_common.hxx"
#include "cpp_stm32/processor/cortex_m4/memory/bit_banding.hxx"
#include "cpp_stm32/utility/bit.hxx"
#include "cpp_stm32/utility/register.hxx"

namespace cpp_stm32::stm32 {

template <typename BitList, typename BitIdx, std::uint32_t BaseAddr, std::uint32_t OffsetAddr,
					Access IoOp = Access::Word, typename = std::enable_if_t<have_atomic_op(BaseAddr + OffsetAddr)>>
using AtomicReg = cpp_stm32::AtomicReg<BitList, BitIdx, IoOp>;

/**
 * @defgroup GPIO_MODER_GROUP		GPIO Mode Register declaration
 * @{
 */

class GpioModerInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr AtomicReg<GpioModerInfo, common::GpioPin, BaseAddr, OffsetAddr> BASE_GPIO_MODER{BaseAddr, OffsetAddr};

/**@}*/

/**
 * @defgroup GPIO_PUPD_GROUP		GPIO Pullup Pulldown Register declaration
 * @{
 */

class GpioPupdInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr AtomicReg<GpioPupdInfo, common::GpioPin, BaseAddr, OffsetAddr> BASE_GPIO_PUPDR{BaseAddr, OffsetAddr};

/**@}*/

/**
 * @defgroup GPIO_ODR_GROUP		GPIO Output Data Register declaration
 * @{
 */

class GpioOdrInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr AtomicReg<GpioOdrInfo, common::GpioPin, BaseAddr, OffsetAddr> BASE_GPIO_ODR{BaseAddr, OffsetAddr};

/**@}*/

/**
 * @defgroup GPIO_BSRR_GROUP		Gpio Bit Set/Reset Register declaration
 * @{
 */

class GpioBsrrInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr AtomicReg<GpioBsrrInfo, common::GpioPin, BaseAddr, OffsetAddr> BASE_GPIO_BSRR{BaseAddr, OffsetAddr};

/**@}*/

/**
 * @defgroup GPIO_AFRH_AFRL_GROUP		GPIO Alternate Function Register High/Low declaration
 * @{
 */

class GpioAfrInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr AtomicReg<GpioAfrInfo, common::GpioPin, BaseAddr, OffsetAddr> BASE_GPIO_AFRL{BaseAddr, OffsetAddr};

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr AtomicReg<GpioAfrInfo, common::GpioPin, BaseAddr, OffsetAddr> BASE_GPIO_AFRH{BaseAddr, OffsetAddr};

/**@}*/

/**
 * @defgroup GPIO_BRR_GROUP		GPIO Bit Reset Register declaration
 *
 * @note @ref STM32F302xx, STM32F303xx and STM32F313xx advanced ARM-based 32-bit MCUs.pdf
 * @{
 */

class GpioBrrInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr AtomicReg<GpioBrrInfo, common::GpioPin, BaseAddr, OffsetAddr> BASE_GPIO_BRR{BaseAddr, OffsetAddr};

/**@}*/

}	 // namespace cpp_stm32::stm32
