/**
 * @file  example/i2c/i2c_imu.cpp
 * @brief	I2C example with IMU, LSM9DS0
 *
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

#include <charconv>

#include "cpp_stm32/driver/usart_serial.hxx"

#include "gpio.hxx"
#include "i2c.hxx"
#include "rcc.hxx"
#include "sys_init.hxx"

namespace Rcc		= cpp_stm32::rcc;
namespace Gpio	= cpp_stm32::gpio;
namespace I2c		= cpp_stm32::i2c;
namespace Sys		= cpp_stm32::sys;
namespace Usart = cpp_stm32::usart;

namespace Driver = cpp_stm32::driver;

using cpp_stm32::operator"" _kHz;
using cpp_stm32::operator"" _byte;
using Usart::operator"" _Baud;

Driver::Usart const pc{Driver::UsartTx_v<Gpio::PinName::PA_2>, Driver::UsartRx_v<Gpio::PinName::PA_3>, 115200_Baud};

constexpr auto I2C = I2c::Port::I2C1;

/* IMU defines */
constexpr auto XM_SAD = 0b0011110, GYRO_SAD = 0b1101010;

enum class RegisterMap {
	WHO_AM_I = 0xF,
	/* GYRO Register map */

	/* Accelerometer Register map */

};

/* setup led */
constexpr void setup_led() noexcept {
	Rcc::enable_periph_clk<Rcc::PeriphClk::GpioA>();
	Gpio::mode_setup<Gpio::Port::PortA, Gpio::Pin::Pin5>(Gpio::Mode::Output, Gpio::Pupd::None);
}

/* setup i2c */
constexpr void setup_i2c() noexcept {
	Rcc::enable_periph_clk<Rcc::PeriphClk::GpioC>();
	Gpio::mode_setup<Gpio::Port::PortC, Gpio::Pin::Pin8, Gpio::Pin::Pin9>(Gpio::Mode::Output, Gpio::Pupd::None);
	Gpio::set<Gpio::Port::PortC, Gpio::Pin::Pin8, Gpio::Pin::Pin9>();

	Rcc::enable_periph_clk<Rcc::PeriphClk::GpioB>();

	Gpio::set_alternate_function<Gpio::Port::PortB, Gpio::Pin::Pin8, Gpio::Pin::Pin9>(Gpio::AltFunc::AF4);
	Gpio::set_output_type<Gpio::Port::PortB, Gpio::Pin::Pin8, Gpio::Pin::Pin9>(Gpio::OutputType::OpenDrain);
	Gpio::mode_setup<Gpio::Port::PortB, Gpio::Pin::Pin8, Gpio::Pin::Pin9>(Gpio::Mode::AltFunc, Gpio::Pupd::PullUp);

	I2c::reset<I2C>();

	Rcc::enable_periph_clk<Rcc::PeriphClk::I2c1>();
	I2c::write_periph_clk_freq<I2C>();
	I2c::config_scl_clock<I2C, I2c::MasterMode::FM, I2c::DutyCycle::NineToSixteen>(400_kHz);
	I2c::write_max_rising_time<I2C, I2c::MasterMode::FM>();
	I2c::set_address_mode<I2C, I2c::SlaveAddressMode::SevenBits>();
	I2c::set_digital_noise_filter<I2C, I2c::MasterMode::FM, 15>();
	I2c::enable<I2C>();
}

std::array<char, 10> str;

int main() {
	Sys::Clock<>::init();

	setup_led();
	setup_i2c();

	while (true) {
		constexpr auto SOME_INTERVAL = 1000000;
		for (int i = 0; i < SOME_INTERVAL; ++i) {
			__asm("nop");
		}

		Gpio::toggle<Gpio::Port::PortA, Gpio::Pin::Pin5>();

		constexpr std::array tx = {cpp_stm32::to_underlying(RegisterMap::WHO_AM_I)};
		auto const [gyro_id]		= I2c::xfer_blocking<I2C>(I2c::SlaveAddr7_t{GYRO_SAD}, 1_byte, tx.begin(), tx.end());

		pc << gyro_id << "\n\r";
	}
}
