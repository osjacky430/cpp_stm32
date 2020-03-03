/**
 * @file  src/main.cpp
 * @brief	user file
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

#include "cpp_stm32/driver/digitalout.hxx"
#include "cpp_stm32/target/stm32/f4/sys_init.hxx"

namespace Rcc	 = cpp_stm32::rcc;
namespace Gpio = cpp_stm32::gpio;
namespace Sys	 = cpp_stm32::sys;

namespace Driver = cpp_stm32::driver;

Driver::DigitalOut<Gpio::PinName::PA_5> const led;

int main() {
	Sys::Clock::init<Rcc::ClkSrc::Hse>();

	while (true) {
		constexpr auto SOME_INTERVAL = 1000000;
		for (int i = 0; i < SOME_INTERVAL; ++i) {
			__asm("nop");
		}

		led.toggle();
	}
}
