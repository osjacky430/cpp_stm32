// Copyright (c) 2020 by osjacky430.
// All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the Lesser GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// Lesser GNU General Public License for more details.
//
// You should have received a copy of the Lesser GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <array>

#include "cpp_stm32/common/gpio_common.hxx"
#include "cpp_stm32/target/stm32/f4/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/interrupt.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/usart.hxx"

namespace cpp_stm32::stm32 {

using common::GpioPort, common::GpioPin, common::GpioAltFunc;

enum class PinName { PA_1, PA_2, PA_3, PA_5, PB_1, NC };

class PinNameMap {
 private:
	static constexpr std::array PinMap{
		std::pair{GpioPort::PortA, GpioPin::Pin1}, std::pair{GpioPort::PortA, GpioPin::Pin2},
		std::pair{GpioPort::PortA, GpioPin::Pin3}, std::pair{GpioPort::PortA, GpioPin::Pin5},
		std::pair{GpioPort::PortB, GpioPin::Pin1},
	};

 public:
	static constexpr auto getPortFromPinMap(const PinName t_pin_name) noexcept {
		return std::get<0>(PinMap[to_underlying(t_pin_name)]);
	}

	static constexpr auto getPinFromPinMap(const PinName t_pin_name) noexcept {
		return std::get<1>(PinMap[to_underlying(t_pin_name)]);
	}
};

class UsartPinMap {
 private:
	// this is not the best way of doing it
	using UsartAltFuncGroup = std::tuple<f4::UsartNum, GpioAltFunc, f4::RccPeriph, IrqNum>;

	static constexpr auto TX_PIN_MAP = std::array{
		std::pair{PinName::PA_2,
							UsartAltFuncGroup{f4::UsartNum::Usart2, GpioAltFunc::AF7, f4::RccPeriph::Usart2, IrqNum::Usart2Global}},
	};

	static constexpr auto RX_PIN_MAP = std::array{
		std::pair{PinName::PA_3,
							UsartAltFuncGroup{f4::UsartNum::Usart2, GpioAltFunc::AF7, f4::RccPeriph::Usart2, IrqNum::Usart2Global}},
	};

	static constexpr auto USART_PIN_MAP = std::tuple{TX_PIN_MAP, RX_PIN_MAP};

 public:
	enum class PinInfo { Tx, Rx };

	template <PinName Pin, PinInfo Idx>
	static constexpr auto getPinInfo() noexcept {
		constexpr auto PIN_MAP = std::get<to_underlying(Idx)>(USART_PIN_MAP);
		const auto iter_pos =
			cstd::find_if(PIN_MAP.begin(), PIN_MAP.end(), [](auto const& t_pair) { return (t_pair.first == Pin); });

		return iter_pos->second;
	};
};

}	 // namespace cpp_stm32::stm32
