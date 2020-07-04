/**
 * @file  driver/spi.hxx
 * @brief	Advance control of SPI
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

#include <cstdint>

#include "cpp_stm32/driver/gpio_base.hxx"
#include "cpp_stm32/utility/serial.hxx"

#include "pin_map/spi.hxx"

namespace cpp_stm32::driver {

template <gpio::PinName MISO>
struct Miso {};

template <gpio::PinName MOSI>
struct Mosi {};

template <gpio::PinName SCLK>
struct Sclk {};

template <gpio::PinName NSS>
struct Nss {};

template <gpio::PinName MISO, gpio::PinName MOSI, gpio::PinName SCLK, gpio::PinName NSS = gpio::PinName::NC>
class SPI {
 private:
	static constexpr auto SPI_PIN_DATA = spi::PinMap::getSpiPinData<MISO, MOSI, SCLK>();

	static constexpr auto MISO_PIN = std::get<0>(SPI_PIN_DATA);
	static constexpr auto MOSI_PIN = std::get<1>(SPI_PIN_DATA);
	static constexpr auto SCLK_PIN = std::get<2>(SPI_PIN_DATA);

	static constexpr auto PORT = std::get<1>(MISO_PIN);

	static constexpr auto MISO_AF = std::get<2>(MISO_PIN);
	static constexpr auto MOSI_AF = std::get<2>(MOSI_PIN);
	static constexpr auto SCLK_AF = std::get<2>(SCLK_PIN);

	static constexpr auto RCC = std::get<3>(MISO_PIN);

 public:
	/**
	 * @brief    Construct SPI with
	 */
	template <std::uint32_t HZ, std::size_t Ds, typename = std::enable_if_t<MISO != gpio::PinName::NC>,
						typename = std::enable_if_t<NSS == gpio::PinName::NC>>
	explicit constexpr SPI(Miso<MISO> const /**/, Mosi<MOSI> const /**/, Sclk<SCLK> const /**/, spi::Mode const t_mode,
												 size_c<Ds> t_ds, Frequency<HZ> const t_freq) noexcept {
		GpioUtil<MISO, MOSI, SCLK>::enableAllGpioClk();
		GpioUtil<MISO, MOSI, SCLK>::modeSetup(gpio::Mode::AltFunc, gpio::Pupd::None);

		if constexpr (MISO_AF == MOSI_AF && MOSI_AF == MISO_AF) {
			GpioUtil<MISO, MOSI, SCLK>::alternateFuncSetup(MISO_AF);
		} else if constexpr (MISO_AF == MOSI_AF) {
			GpioUtil<MISO, MOSI>::alternateFuncSetup(MISO_AF);
			GpioUtil<SCLK>::alternateFuncSetup(SCLK_AF);
		} else if constexpr (MISO_AF == SCLK_AF) {
			GpioUtil<MISO, SCLK>::alternateFuncSetup(MISO_AF);
			GpioUtil<MOSI>::alternateFuncSetup(MOSI_AF);
		} else if constexpr (MOSI_AF == SCLK_AF) {
			GpioUtil<MOSI, SCLK>::alternateFuncSetup(MOSI_AF);
			GpioUtil<MISO>::alternateFuncSetup(MISO_AF);
		} else {
			GpioUtil<MISO>::alternateFuncSetup(MISO_AF);
			GpioUtil<MOSI>::alternateFuncSetup(MOSI_AF);
			GpioUtil<SCLK>::alternateFuncSetup(SCLK_AF);
		}

		rcc::enable_periph_clk<RCC>();
		spi::init_master<PORT, spi::TransferMode::FullDuplex, spi::SlaveSelectMode::OutputHardware>(t_mode, t_ds, t_freq);
	}

	/**
	 * @brief    This function sets CPOL and CPHA
	 * @param    t_mode @ref spi::Mode
	 *
	 * @bug  This doesn't work
	 */
	void setMode(spi::Mode const t_mode) const noexcept {
		spi::disable<PORT>();
		spi::set_mode<PORT>(t_mode);
		spi::enable<PORT>();
	}

	constexpr void setMsbFirst() const noexcept { spi::set_msb_first<PORT>(); }

	constexpr void setLsbFirst() const noexcept { spi::set_lsb_first<PORT>(); }

	template <std::uint32_t HZ>
	constexpr void setBaudrate(Frequency<HZ> const) const noexcept {
		// @todo implement
	}

	template <std::uint8_t BC>
	constexpr auto xfer(ByteCount<BC> const t_bc, std::uint16_t const t_val) const noexcept {
		std::array<std::uint16_t, 1> val{t_val};
		return spi::xfer_blocking<PORT>(t_bc, val.begin(), val.end());
	}

	template <typename DataType, std::uint8_t BC, std::size_t N>
	constexpr auto xfer(DataCount<DataType, BC> const t_bc, std::array<std::uint16_t, N> const& t_val) const noexcept {
		return spi::xfer_blocking<PORT>(t_bc, t_val.begin(), t_val.end());
	}

	template <std::size_t N>
	constexpr void send(std::array<std::uint8_t, N> const& t_val) const noexcept {
		spi::send_blocking<PORT>(t_val.begin(), t_val.end());
	}

	template <typename T>
	constexpr auto send(Serializable<T> const t_val) const noexcept {
		auto const& val = t_val.serialize();
		spi::send_blocking<PORT>(std::begin(val), std::end(val));
	}

	template <typename DataType, std::uint8_t BC>
	constexpr auto receive(DataCount<DataType, BC> const t_bc) const noexcept {
		return spi::receive_blocking<PORT>(t_bc);
	}
};

}	 // namespace cpp_stm32::driver
