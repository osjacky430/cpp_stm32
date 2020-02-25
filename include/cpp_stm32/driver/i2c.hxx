/**
 * @file  driver/i2c.hxx
 * @brief	Advance control of I2C
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

#pragma once

#include <array>
#include <cstdint>
#include <iterator>

#include "cpp_stm32/driver/gpio_base.hxx"
#include "cpp_stm32/utility/serial.hxx"

#include "device.hxx"

namespace cpp_stm32::driver {

template <gpio::PinName SDA>
struct I2cSDA {
	static constexpr auto PIN_DATA = i2c::PinMap::getSDAPinData<SDA>();

	static constexpr auto PORT = std::get<1>(PIN_DATA);
	static constexpr auto AF	 = std::get<2>(PIN_DATA);
	static constexpr auto RCC	 = std::get<3>(PIN_DATA);
	static constexpr auto IRQ	 = std::get<4>(PIN_DATA);
};

template <gpio::PinName SCL>
struct I2cSCL {
	static constexpr auto PIN_DATA = i2c::PinMap::getSCLPinData<SCL>();

	static constexpr auto PORT = std::get<1>(PIN_DATA);
	static constexpr auto AF	 = std::get<2>(PIN_DATA);
	static constexpr auto RCC	 = std::get<3>(PIN_DATA);
	static constexpr auto IRQ	 = std::get<4>(PIN_DATA);
};

template <gpio::PinName SDA, gpio::PinName SCL, std::uint32_t Hz>
class I2C {
 private:
	static constexpr auto PORT = I2cSDA<SDA>::PORT;
	static constexpr auto AF	 = I2cSDA<SDA>::AF;
	static constexpr auto RCC	 = I2cSDA<SDA>::RCC;
	static constexpr auto IRQ	 = I2cSDA<SDA>::IRQ;

	static_assert(I2cSDA<SDA>::PORT == I2cSCL<SCL>::PORT);

 public:
	explicit constexpr I2C(I2cSDA<SDA> const /*unused*/, I2cSCL<SCL> const /*unused*/,
												 Frequency<Hz> const t_freq) noexcept {
		GpioUtil<SDA, SCL>::enableAllGpioClk();
		GpioUtil<SDA, SCL>::modeSetup(gpio::Mode::AltFunc, gpio::Pupd::PullUp);
		GpioUtil<SDA, SCL>::alternateFuncSetup(AF);

		i2c::reset<PORT>();
		rcc::enable_periph_clk<RCC>();
		i2c::write_periph_clk_freq<PORT>();
		i2c::write_max_rising_time<PORT, i2c::MasterMode::FM>();
		i2c::config_scl_clock<PORT, i2c::MasterMode::FM, i2c::DutyCycle::NineToSixteen>(t_freq);	// i2c::DutyCycle ?

		i2c::enable<PORT>();
	}

	template <std::uint8_t BC, std::size_t N, typename SlaveAddrType>
	constexpr auto xfer(SlaveAddrType t_slave, ByteCount<BC> const t_bc,
											std::array<std::uint8_t, N> const& t_val) const noexcept {
		return i2c::xfer_blocking<PORT>(t_slave, t_bc, t_val.begin(), t_val.end());
	}

	template <std::size_t N, typename SlaveAddrType>
	constexpr void send(SlaveAddrType t_slave, std::array<std::uint8_t, N> const& t_val) const noexcept {
		i2c::send_blocking<PORT>(t_slave, t_val.begin(), t_val.end());
	}

	template <typename T, typename SlaveAddrType>
	constexpr auto send(SlaveAddrType t_slave, Serializable<T> const t_val) const noexcept {
		auto const& val = t_val.serialize();
		i2c::send_blocking<PORT>(t_slave, std::begin(val), std::end(val));
	}

	template <std::uint8_t BC, typename SlaveAddrType>
	constexpr auto receive(SlaveAddrType t_slave, ByteCount<BC> const t_bc) const noexcept {
		return i2c::receive_blocking<PORT>(t_slave, t_bc);
	}
};

}	 // namespace cpp_stm32::driver
