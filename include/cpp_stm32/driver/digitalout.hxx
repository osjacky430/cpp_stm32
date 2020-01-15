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

#include "cpp_stm32/common/gpio.hxx"
#include "cpp_stm32/driver/gpio_base.hxx"
#include "cpp_stm32/utility/utility.hxx"

#include "device.hxx"

/**
 * @namespace   cpp_stm32::driver
 * @brief       contains advance control class over peripheral
 */
namespace cpp_stm32::driver {

/**
 * @class   DigitalOut
 * @brief   This class is a specialization of GpioUtil, it provides advance GPIO output control
 */
template <gpio::PinName... PinNames>
class DigitalOut {
 public:
	/**
	 * @brief  Default constructor, it enables rcc peripheral clock, and setup gpio mode to output, no pull
	 */
	constexpr DigitalOut() noexcept {
		using gpio::Mode, gpio::Pupd;

		GpioUtil<PinNames...>::enableAllGpioClk();
		GpioUtil<PinNames...>::modeSetup(Mode::Output, Pupd::None);
	}

	/**
	 * @brief   Toggle the input pin name
	 * @todo    This can be extended to only toggle certain pins in input pin list
	 */
	constexpr void toggle() const noexcept { GpioUtil<PinNames...>::toggle(); }
};

}	// namespace cpp_stm32::driver
