/**
 * @file  example/exti/blue_button.cpp
 * @brief	Exti example using user button (blue button on the board)
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

#include "cpp_stm32/target/stm32/f4/exti.hxx"
#include "cpp_stm32/target/stm32/f4/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/nvic.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/syscfg.hxx"

namespace Rcc		 = cpp_stm32::rcc;
namespace Gpio	 = cpp_stm32::gpio;
namespace Exti	 = cpp_stm32::exti;
namespace SysCfg = cpp_stm32::syscfg;
namespace Nvic	 = cpp_stm32::nvic;

constexpr void setup_led() noexcept {
	Rcc::enable_periph_clk<Rcc::PeriphClk::GpioA>();
	Gpio::mode_setup<Gpio::Port::PortA, Gpio::Pin::Pin5>(Gpio::Mode::Output, Gpio::Pupd::None);
}

constexpr void setup_user_button_exti() noexcept {
	Nvic::enable_irq<cpp_stm32::IrqNum::Exti10_15>();
	Rcc::enable_periph_clk<Rcc::PeriphClk::GpioC>();
	Rcc::enable_periph_clk<Rcc::PeriphClk::SysCfg>();

	Gpio::mode_setup<Gpio::Port::PortC, Gpio::Pin::Pin13>(Gpio::Mode::Input, Gpio::Pupd::None);
	SysCfg::config_exti_source<Gpio::Port::PortC, Gpio::Pin::Pin13>();

	Exti::set_trigger_type<Exti::Line::Line13>(Exti::TriggerType::Fall);
	Exti::enable<Exti::Line::Line13>();
}

int main() {
	setup_led();
	setup_user_button_exti();

	while (true) {
		constexpr auto SOME_PERIOD = 1000000;
		for (int i = 0; i < SOME_PERIOD; ++i) {
			__asm("nop");
		}
	}
}

void cpp_stm32::interrupt::exti10_15() noexcept {
	if (get<0>(Exti::is_active<Exti::Line::Line13>())) {
		Gpio::toggle<Gpio::Port::PortA, Gpio::Pin::Pin5>();
		Exti::clear_active_flag<Exti::Line::Line13>();
	}
}
