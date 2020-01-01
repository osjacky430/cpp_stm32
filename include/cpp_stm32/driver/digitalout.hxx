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

// @todo gpio.hxx and rcc.hxx include should change to hal/gpio.hxx, hal/rcc.hxx respectively
#include "cpp_stm32/driver/gpio_base.hxx"
#include "cpp_stm32/target/stm32/f4/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"
#include "cpp_stm32/utility/utility.hxx"

template <PinName... PinNames>
class DigitalOut {
 private:
 public:
	constexpr DigitalOut() {
		GpioUtil<PinNames...>::enableAllGpioClk();
		GpioUtil<PinNames...>::modeSetup(GpioMode::Output, GpioPupd::None);
	}

	constexpr void toggle() const noexcept { GpioUtil<PinNames...>::toggle(); }
};
