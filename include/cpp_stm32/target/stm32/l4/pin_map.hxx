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
#include <tuple>

#include "cpp_stm32/common/pin_data.hxx"

#include "cpp_stm32/target/stm32/l4/gpio.hxx"
#include "cpp_stm32/target/stm32/l4/interrupt.hxx"
#include "cpp_stm32/target/stm32/l4/memory/usart_reg.hxx"
#include "cpp_stm32/target/stm32/l4/rcc.hxx"

namespace cpp_stm32::usart {

class PinMap {
 private:
	using PinName = gpio::PinName;

	using UsartPinData = PinData<PinName, Port, gpio::AltFunc, rcc::PeriphClk, IrqNum>;

	static constexpr std::array TX_PIN_TABLE{
		UsartPinData{PinName::PA_2, Port::Usart2, gpio::AltFunc::AF7, rcc::PeriphClk::Usart2, IrqNum::Usart2Global},
	};

	static constexpr std::array RX_PIN_TABLE{
		UsartPinData{PinName::PA_3, Port::Usart2, gpio::AltFunc::AF7, rcc::PeriphClk::Usart2, IrqNum::Usart2Global},
	};

	static constexpr auto USART_PIN_NAME_TABLE = std::tuple{TX_PIN_TABLE, RX_PIN_TABLE};

 public:
	template <PinName Pin>
	[[nodiscard]] static constexpr auto getTxPinData() noexcept {
		auto const iter = *cstd::find_if(TX_PIN_TABLE.begin(), TX_PIN_TABLE.end(),
																		 [](auto const& pin_data) { return pin_data[0_ic] == Pin; });

		return std::tuple{iter[1_ic], iter[2_ic], iter[3_ic], iter[4_ic]};
	}

	template <PinName Pin>
	[[nodiscard]] static constexpr auto getRxPinData() noexcept {
		auto const iter = *cstd::find_if(RX_PIN_TABLE.begin(), RX_PIN_TABLE.end(),
																		 [](auto const& pin_data) { return pin_data[0_ic] == Pin; });

		return std::tuple{iter[1_ic], iter[2_ic], iter[3_ic], iter[4_ic]};
	}
};

}	 // namespace cpp_stm32::usart

namespace cpp_stm32::gpio {

class PinMap {
 private:
	using PortPinPair = PinData<Port, Pin>;

	/**
	 * @var 		PIN_NAME_TABLE
	 * @brief
	 *
	 */
	static constexpr auto PIN_TABLE = []() {
		std::array<PortPinPair, to_underlying(PinName::Total)> temp{};

		temp[to_underlying(PinName::PA_0)] = PortPinPair{Port::PortA, Pin::Pin0};
		temp[to_underlying(PinName::PA_1)] = PortPinPair{Port::PortA, Pin::Pin1};
		temp[to_underlying(PinName::PA_2)] = PortPinPair{Port::PortA, Pin::Pin2};
		temp[to_underlying(PinName::PA_3)] = PortPinPair{Port::PortA, Pin::Pin3};
		temp[to_underlying(PinName::PA_5)] = PortPinPair{Port::PortA, Pin::Pin5};

		temp[to_underlying(PinName::PB_1)] = PortPinPair{Port::PortB, Pin::Pin1};
		temp[to_underlying(PinName::PB_2)] = PortPinPair{Port::PortB, Pin::Pin2};
		temp[to_underlying(PinName::PB_3)] = PortPinPair{Port::PortB, Pin::Pin3};

		return temp;
	}();

 public:
	[[nodiscard]] static constexpr auto getPort(PinName const& t_pin_name) noexcept {
		return PIN_TABLE[to_underlying(t_pin_name)][0_ic];
	}

	[[nodiscard]] static constexpr auto getPin(PinName const& t_pin_name) noexcept {
		return PIN_TABLE[to_underlying(t_pin_name)][1_ic];
	}
};

}	 // namespace cpp_stm32::gpio
