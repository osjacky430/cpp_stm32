/**
 * @file  example/gpio_output/ll_driver.cpp
 * @brief	Gpio output example using low level gpio api
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

#include "cpp_stm32/target/stm32/f4/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"

constexpr void setup_led_gpio() noexcept {
	using namespace cpp_stm32::gpio;
	using namespace cpp_stm32::rcc;

	enable_periph_clk<PeriphClk::GpioA>();
	mode_setup<Port::PortA, Pin::Pin5>(Mode::Output, Pupd::None);
}

int main() {
	using namespace cpp_stm32::gpio;

	while (1) {
		constexpr auto SOME_INTERVAL = 100000;
		for (int i = 0; i < SOME_INTERVAL; ++i) {
			__asm("nop");
		}

		toggle<Port::PortA, Pin::Pin5>();
	}
}
