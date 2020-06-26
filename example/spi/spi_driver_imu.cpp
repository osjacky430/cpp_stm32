/**
 * @file  example/spi/spi_driver_imu.cpp
 * @brief	SPI driver example with IMU, LSM9DS0
 *
 * @note  Still Under Construction, there is a bug still can't resolve
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
#include "cpp_stm32/driver/spi.hxx"
#include "cpp_stm32/driver/usart_serial.hxx"
#include "sys_init.hxx"

#include "lsm9ds0.hpp"

namespace Rcc		= cpp_stm32::rcc;
namespace Gpio	= cpp_stm32::gpio;
namespace Sys		= cpp_stm32::sys;
namespace Usart = cpp_stm32::usart;
namespace Spi		= cpp_stm32::spi;

namespace Driver = cpp_stm32::driver;

using cpp_stm32::operator"" _kHz;
using cpp_stm32::operator"" _byte;
using Usart::operator"" _Baud;

Driver::Usart const pc{Driver::UsartTx_v<Gpio::PinName::PA_2>, Driver::UsartRx_v<Gpio::PinName::PA_3>, 115200_Baud};

Driver::DigitalOut<Gpio::PinName::PA_5> const led;

/* IMU defines */
using Lsm9ds0::LSM9DS0, Lsm9ds0::GyroCs, Lsm9ds0::XMCs, Lsm9ds0::SDO, Lsm9ds0::SCL, Lsm9ds0::SDA;

LSM9DS0 const imu{GyroCs<Gpio::PinName::PB_3>{}, XMCs<Gpio::PinName::PB_10>{}, SDO<Gpio::PinName::PB_14>{},
									SCL<Gpio::PinName::PB_13>{}, SDA<Gpio::PinName::PB_15>{}};

int main() {
	Sys::Clock::init<Rcc::ClkSrc::Hse>();

	while (true) {
		constexpr auto SOME_INTERVAL = 1000000;
		for (int i = 0; i < SOME_INTERVAL; ++i) {
			__asm("nop");
		}

		led.toggle();

		auto const [gyro_id] = imu.getID(Lsm9ds0::Sensor::Accelerometer);

		pc << gyro_id << "\n\r";
	}
}
