/**
 * @file  stm32/f4/pin_map/i2c.hxx
 * @brief I2C pin mapping for stm32f4
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

#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/detail/tuple.hxx"
#include "cpp_stm32/target/stm32/f4/define/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/define/i2c.hxx"
#include "cpp_stm32/target/stm32/f4/define/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/interrupt.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

namespace cpp_stm32::i2c {

class PinMap {
 private:
	using I2CPinData = detail::Tuple<gpio::PinName, Port, gpio::AltFunc, rcc::PeriphClk, std::array<IrqNum, 2>>;

	static constexpr auto AF = gpio::AltFunc::AF4;
	static constexpr std::array RCC{rcc::PeriphClk::I2c1, rcc::PeriphClk::I2c2, rcc::PeriphClk::I2c3};
	static constexpr std::array IRQ{std::array{IrqNum::I2c1Ev, IrqNum::I2c1Er},
																	std::array{IrqNum::I2c2Ev, IrqNum::I2c2Er},
																	std::array{IrqNum::I2c2Ev, IrqNum::I2c2Er}};	// @todo change to i2c3ev, i2c3er

	static constexpr auto SET_DATA = [](gpio::PinName const t_pin, Port const t_port) {
		auto const idx = to_underlying(t_port);
		return I2CPinData{t_pin, t_port, AF, RCC[idx], IRQ[idx]};
	};

	static constexpr std::array SDA_TABLE{
		SET_DATA(gpio::PinName::PB_3, Port::I2C2),	SET_DATA(gpio::PinName::PB_4, Port::I2C3),
		SET_DATA(gpio::PinName::PB_7, Port::I2C1),	SET_DATA(gpio::PinName::PB_9, Port::I2C1),
		SET_DATA(gpio::PinName::PB_11, Port::I2C2), SET_DATA(gpio::PinName::PC_9, Port::I2C3),
		SET_DATA(gpio::PinName::PC_12, Port::I2C3),
	};

	static constexpr std::array SCL_TABLE{
		SET_DATA(gpio::PinName::PA_8, Port::I2C3),
		SET_DATA(gpio::PinName::PB_6, Port::I2C1),
		SET_DATA(gpio::PinName::PB_8, Port::I2C1),
		SET_DATA(gpio::PinName::PB_10, Port::I2C2),
	};

	template <gpio::PinName Pin>
	static constexpr auto PREDICATE = [](auto const& t_pin_data) { return t_pin_data[0_ic] == Pin; };

 public:
	template <gpio::PinName Pin>
	[[nodiscard]] static constexpr auto getSDAPinData() noexcept {
		constexpr auto iter = *detail::find_if(SDA_TABLE.begin(), SDA_TABLE.end(), PREDICATE<Pin>);

		return detail::to_std_tuple(iter);
	}

	template <gpio::PinName Pin>
	[[nodiscard]] static constexpr auto getSCLPinData() noexcept {
		constexpr auto iter = *detail::find_if(SCL_TABLE.begin(), SCL_TABLE.end(), PREDICATE<Pin>);

		return detail::to_std_tuple(iter);
	}
};

}	 // namespace cpp_stm32::i2c
