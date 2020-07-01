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
#include "cpp_stm32/redirect/sys_call.hxx"
#include "gpio.hxx"

namespace Gpio	 = cpp_stm32::gpio;
namespace Driver = cpp_stm32::driver;

Driver::DigitalOut<Gpio::PinName::PB_3> const led;

static bool end = false;

int main() {
	while (1) {
		constexpr auto SOME_INTERVAL = 100000;
		for (int i = 0; i < SOME_INTERVAL; ++i) {
			__asm("nop");
		}

		led.toggle();

		if (end) {
			_exit(0);
		}
	}
}
