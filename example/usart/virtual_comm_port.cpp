/**
 * @file  example/gpio_output/digitalout.cpp
 * @brief	Gpio output example using cpp_stm32::driver
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
#include "cpp_stm32/driver/usart_serial.hxx"
#include "sys_init.hxx"

int main() {
	using cpp_stm32::usart::operator""_Baud;
	using namespace cpp_stm32::driver;
	using namespace cpp_stm32::sys;
	using namespace cpp_stm32::rcc;
	using cpp_stm32::gpio::PinName;

	Clock::init<ClkSrc::Msi>();

	Usart pc{UsartTx_v<PinName::PA_2>, UsartRx_v<PinName::PA_3>, 115200_Baud};
	DigitalOut<PinName::PB_3> led;

	while (1) {
		constexpr auto SOME_INTERVAL = 10000000;
		for (int i = 0; i < SOME_INTERVAL; ++i) {
			__asm("nop");
		}

		pc << "1\n\r";
		led.toggle();
	}
}
