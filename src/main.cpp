/**
 * @file  example/spi/spi_imu.cpp
 * @brief	SPI example with IMU, LSM9DS0
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

#include "gpio.hxx"
#include "rcc.hxx"
#include "spi.hxx"
#include "sys_init.hxx"

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
constexpr auto XM_SAD = 0b0011110, GYRO_SAD = 0b1101010;

enum class RegisterMap : std::uint8_t {
	WHO_AM_I = 0xF,
	/* GYRO Register map */

	/* Accelerometer Register map */

};

constexpr void setup_spi() noexcept {
	// Driver::SPI imu(Driver::Miso<Gpio::PinName::PA_6>{}, Driver::Mosi<Gpio::PinName::PA_7>{},
	// 								Driver::Sclk<Gpio::PinName::PA_5>{}, Spi::Mode::Mode2, cpp_stm32::size_c<8>{}, 500_kHz);

	//	Spi::init_master<Spi::Port::SPI1, Spi::TransferMode::FullDuplex, Spi::SlaveSelectMode::OutputHardware>(
	//		Spi::Mode::Mode2, cpp_stm32::size_c<8>{}, 500_kHz);
}

// static constexpr auto M_CLOCK_DATA = []() {
// 	Sys::ClockBuilder builder;
// 	builder.setHSE(HSE_BYPASS_CLK_SRC, HSE_CLK_FREQ)
// 		.setLSE(LSE_BYPASS_CLK_SRC, LSE_CLK_FREQ)
// 		.setSYS(SYS_CLK_FREQ)
// 		.setAHB(AHB_CLK_FREQ)
// 		.setAPB1(APB1_CLK_FREQ)
// 		.setAPB2(APB2_CLK_FREQ)
// 		.setPLL(Rcc::ClkSrc::Hse);
//
// 	return builder.buildClock();
// }();

int main() {
	Sys::Clock<>::init();

	// Driver::DigitalOut<Gpio::PinName::PB_1> const xm_ss;
	// Driver::DigitalOut<Gpio::PinName::PB_0> const gyro_ss;
	//
	// setup_spi();

	// xm_ss.set();	// disable xm spi
	// gyro_ss.clear();

	while (true) {
		constexpr auto SOME_INTERVAL = 10000000;
		for (int i = 0; i < SOME_INTERVAL; ++i) {
			__asm("nop");
		}

		led.toggle();

		// std::array<std::uint8_t, 2> tx{(1 << 7) | cpp_stm32::to_underlying(RegisterMap::WHO_AM_I), std::uint8_t{0x00}};

		// Spi::xfer_blocking<Spi::Port::SPI1>(1_byte, tx.begin(), tx.begin() + 1);
		// auto const [gyro_id] = Spi::xfer_blocking<Spi::Port::SPI1>(1_byte, tx.begin() + 1, tx.end());

		//	auto const [level] = Spi::get_rx_fifo_level<Spi::Port::SPI1>();
		pc << "(gyro_id)"
			 << "\n\r";
		//		pc << cpp_stm32::to_underlying(level) << "\n\r";
	}
}
