/**
 * @file  stm32/pin_map/spi.hxx
 * @brief	Header that include all pin map information
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

#include "cpp_stm32/detail/tuple.hxx"
#include "cpp_stm32/target/stm32/f4/define/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/define/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/define/spi.hxx"
#include "cpp_stm32/target/stm32/f4/interrupt.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

namespace cpp_stm32::spi {

class PinMap {
 private:
	using PinData = detail::Tuple<gpio::PinName, Port, gpio::AltFunc, rcc::PeriphClk, IrqNum>;

	static constexpr std::array MISO_TABLE{
		PinData{gpio::PinName::PA_6, Port::SPI1, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2 /**/, IrqNum::Spi1Global},
		PinData{gpio::PinName::PB_4, Port::SPI2, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2, IrqNum::Spi2Global},
		PinData{gpio::PinName::PB_4, Port::SPI3, gpio::AltFunc::AF6, rcc::PeriphClk::Spi3, IrqNum::Spi3Global},
		PinData{gpio::PinName::PB_14, Port::SPI2, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2, IrqNum::Spi2Global},
		PinData{gpio::PinName::PC_2, Port::SPI2, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2, IrqNum::Spi2Global},
		PinData{gpio::PinName::PC_11, Port::SPI3, gpio::AltFunc::AF6, rcc::PeriphClk::Spi3, IrqNum::Spi3Global /**/},
	};

	static constexpr std::array MOSI_TABLE{
		PinData{gpio::PinName::PA_7, Port::SPI1, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2 /**/, IrqNum::Spi1Global},
		PinData{gpio::PinName::PB_0, Port::SPI3, gpio::AltFunc::AF7, rcc::PeriphClk::Spi3, IrqNum::Spi3Global},
		PinData{gpio::PinName::PB_2, Port::SPI3, gpio::AltFunc::AF7, rcc::PeriphClk::Spi3, IrqNum::Spi3Global},
		PinData{gpio::PinName::PB_5, Port::SPI1, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2 /**/, IrqNum::Spi1Global},
		PinData{gpio::PinName::PB_5, Port::SPI3, gpio::AltFunc::AF6, rcc::PeriphClk::Spi3, IrqNum::Spi3Global},
		PinData{gpio::PinName::PB_15, Port::SPI2, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2, IrqNum::Spi2Global},
		PinData{gpio::PinName::PC_1, Port::SPI3, gpio::AltFunc::AF5, rcc::PeriphClk::Spi3, IrqNum::Spi3Global},
		PinData{gpio::PinName::PC_1, Port::SPI2, gpio::AltFunc::AF7, rcc::PeriphClk::Spi2, IrqNum::Spi2Global},
		PinData{gpio::PinName::PC_3, Port::SPI2, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2, IrqNum::Spi2Global},
		PinData{gpio::PinName::PC_12, Port::SPI3, gpio::AltFunc::AF6, rcc::PeriphClk::Spi3, IrqNum::Spi3Global},
	};

	static constexpr std::array SCLK_TABLE{
		PinData{gpio::PinName::PA_5, Port::SPI1, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2 /**/, IrqNum::Spi1Global},
		PinData{gpio::PinName::PA_9, Port::SPI2, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2, IrqNum::Spi2Global},
		PinData{gpio::PinName::PB_3, Port::SPI1, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2 /**/, IrqNum::Spi1Global},
		PinData{gpio::PinName::PB_3, Port::SPI3, gpio::AltFunc::AF6, rcc::PeriphClk::Spi3, IrqNum::Spi3Global},
		PinData{gpio::PinName::PB_10, Port::SPI2, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2, IrqNum::Spi2Global},
		PinData{gpio::PinName::PB_13, Port::SPI2, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2, IrqNum::Spi2Global},
		PinData{gpio::PinName::PC_7, Port::SPI2, gpio::AltFunc::AF5, rcc::PeriphClk::Spi2, IrqNum::Spi2Global},
		PinData{gpio::PinName::PC_10, Port::SPI3, gpio::AltFunc::AF6, rcc::PeriphClk::Spi3, IrqNum::Spi3Global},
	};

 public:
	template <gpio::PinName MISO, gpio::PinName MOSI, gpio::PinName SCLK>
	[[nodiscard]] static constexpr auto getSpiPinData() noexcept {
		// @todo is there a better way? (recursive?)
		for (auto const& miso : MISO_TABLE) {
			if (auto const spi_port = detail::get<1>(miso); detail::get<0>(miso) == MISO) {
				for (auto const& mosi : MOSI_TABLE) {
					if (detail::get<0>(mosi) == MOSI && spi_port == detail::get<1>(miso)) {
						for (auto const& sclk : SCLK_TABLE) {
							if (detail::get<0>(sclk) == SCLK && spi_port == detail::get<1>(sclk)) {
								return std::tuple{detail::to_std_tuple(miso), detail::to_std_tuple(mosi), detail::to_std_tuple(sclk)};
							}
						}
					}
				}
			}
		}
	}
};

}	 // namespace cpp_stm32::spi
