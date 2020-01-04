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

#include "cpp_stm32/utility/bit.hxx"
#include "cpp_stm32/utility/register.hxx"

namespace cpp_stm32::stm32 {

enum class GpioPort;
enum class GpioPin;
enum class GpioMode;
enum class GpioPupd;
enum class GpioOutType;
enum class GpioOutSpeed;
enum class GpioAltFunc;

/**
 * @defgroup GPIO_MODER_GROUP
 * @{
 */

class GpioModerInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr Register<GpioModerInfo, GpioPin> BASE_GPIO_MODER{BaseAddr, OffsetAddr};

/**@}*/

/**
 * @defgroup GPIO_PUPD_GROUP
 * @{
 */

class GpioPupdInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr Register<GpioPupdInfo, GpioPin> BASE_GPIO_PUPDR{BaseAddr, OffsetAddr};

/**@}*/

/**
 * @defgroup GPIO_ODR_GROUP
 * @{
 */

class GpioOdrInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr Register<GpioOdrInfo, GpioPin> BASE_GPIO_ODR{BaseAddr, OffsetAddr};

/**@}*/

/**
 * @defgroup GPIO_BSRR_GROUP
 * @{
 */

class GpioBsrrInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr Register<GpioBsrrInfo, GpioPin> BASE_GPIO_BSRR{BaseAddr, OffsetAddr};

/**@}*/

/**
 * @defgroup GPIO_AFRH_ARGL_GROUP
 * @{
 */

class GpioAfrInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr Register<GpioAfrInfo, GpioPin> BASE_GPIO_AFRL{BaseAddr, OffsetAddr};

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr Register<GpioAfrInfo, GpioPin> BASE_GPIO_AFRH{BaseAddr, OffsetAddr};

/**@}*/

/**
 * @defgroup GPIO_BRR_GROUP
 * @note @ref STM32F302xx, STM32F303xx and STM32F313xx advanced ARM-based 32-bit MCUs.pdf
 * @{
 */

class GpioBrrInfo;

template <std::uint32_t BaseAddr, std::uint32_t OffsetAddr>
static constexpr Register<GpioBrrInfo, GpioPin> BASE_GPIO_BRR{BaseAddr, OffsetAddr};

/**@}*/

}	 // namespace cpp_stm32::stm32
