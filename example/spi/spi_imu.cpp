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
	Rcc::enable_periph_clk<Rcc::PeriphClk::GpioB>();
	Rcc::enable_periph_clk<Rcc::PeriphClk::Spi2>();
	Gpio::mode_setup<Gpio::Port::PortB, Gpio::Pin::Pin13, Gpio::Pin::Pin14, Gpio::Pin::Pin15>(Gpio::Mode::AltFunc,
																																														Gpio::Pupd::None);

	Gpio::set_alternate_function<Gpio::Port::PortB, Gpio::Pin::Pin13, Gpio::Pin::Pin14, Gpio::Pin::Pin15>(
		Gpio::AltFunc::AF5);

	Spi::set_master_mode<Spi::Port::SPI2>();
	Spi::set_baudrate_prescaler<Spi::Port::SPI2>(Spi::Baudrate_t{cpp_stm32::uint32_c<32>{}});
	Spi::set_transfer_mode<Spi::Port::SPI2, Spi::TransferMode::FullDuplex>();
	Spi::set_mode<Spi::Port::SPI2>(Spi::Mode::Mode2);
	Spi::set_data_frame_format<Spi::Port::SPI2>(Spi::DataFrameFormat::Byte);
	Spi::set_msb_first<Spi::Port::SPI2>();
	Spi::set_slave_select_mode<Spi::Port::SPI2, Spi::SlaveSelectMode::OutputHardware>();

	Spi::enable<Spi::Port::SPI2>();
}

int main() {
	Sys::Clock::init<Rcc::ClkSrc::Hse>();

	Driver::DigitalOut<Gpio::PinName::PB_10> const xm_ss;
	Driver::DigitalOut<Gpio::PinName::PB_12> const gyro_ss;

	setup_spi();

	xm_ss.set();	// disable xm spi
	gyro_ss.clear();

	while (true) {
		constexpr auto SOME_INTERVAL = 10000000;
		for (int i = 0; i < SOME_INTERVAL; ++i) {
			__asm("nop");
		}

		led.toggle();

		std::array<std::uint8_t, 2> tx{(1 << 7) | cpp_stm32::to_underlying(RegisterMap::WHO_AM_I), std::uint8_t{0x00}};

		Spi::xfer_blocking<Spi::Port::SPI2>(1_byte, tx.begin(), tx.begin() + 1);
		auto const [gyro_id] = Spi::xfer_blocking<Spi::Port::SPI2>(1_byte, tx.begin() + 1, tx.end());

		pc << gyro_id << "\n\r";
	}
}
