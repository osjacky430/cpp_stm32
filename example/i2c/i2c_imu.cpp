/**
 * @file  example/i2c/i2c_imu.cpp
 * @brief	I2C example with IMU, LSM9DS0
 *
 * @note  Still Under Construction
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
#include "cpp_stm32/target/stm32/f4/i2c.hxx"
#include "cpp_stm32/target/stm32/f4/nvic.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/sys_init.hxx"

namespace Rcc	 = cpp_stm32::rcc;
namespace Gpio = cpp_stm32::gpio;
namespace Nvic = cpp_stm32::nvic;
namespace I2c	 = cpp_stm32::i2c;
namespace Sys	 = cpp_stm32::sys;

using cpp_stm32::operator"" _kHz;

constexpr auto I2C = I2c::Port::I2C1;

constexpr void setup_i2c() noexcept {
	Rcc::enable_periph_clk<Rcc::PeriphClk::I2c1>();
	Rcc::enable_periph_clk<Rcc::PeriphClk::GpioB>();

	Gpio::mode_setup<Gpio::Port::PortB, Gpio::Pin::Pin8, Gpio::Pin::Pin9>(Gpio::Mode::AltFunc, Gpio::Pupd::None);
	Gpio::set_alternate_function<Gpio::Port::PortB, Gpio::Pin::Pin8, Gpio::Pin::Pin9>(Gpio::AltFunc::AF4);

	I2c::config_scl_clock<I2C, I2c::MasterMode::FM>(400_kHz);
	I2c::write_periph_clk_freq<I2C>();
	I2c::write_max_rising_time<I2C, I2c::MasterMode::FM>();
	I2c::set_digital_noise_filter<I2C, I2c::MasterMode::FM, 15>();
	I2c::enable<I2C>();
}

int main() {
	Sys::Clock::init<Rcc::ClkSrc::Hse>();

	setup_i2c();

	while (true) {
	}
}
