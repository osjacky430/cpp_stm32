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

#include "cpp_stm32/common/pin_data.hxx"
#include "cpp_stm32/target/stm32/f4/define/dma.hxx"
#include "cpp_stm32/target/stm32/f4/define/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/interrupt.hxx"
#include "cpp_stm32/target/stm32/f4/register/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/register/usart.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

namespace cpp_stm32::gpio {

class PinMap {
 private:
	using PortPinPair = PinData<Port, Pin>;
	/**
	 * @var 		PIN_NAME_TABLE
	 * @brief
	 *
	 */
	static constexpr auto PinTable = []() {
		std::array<PortPinPair, to_underlying(PinName::Total)> temp{};

		/* GPIO A */
		temp[to_underlying(PinName::PA_0)]	= PortPinPair{Port::PortA, Pin::Pin0};
		temp[to_underlying(PinName::PA_1)]	= PortPinPair{Port::PortA, Pin::Pin1};
		temp[to_underlying(PinName::PA_2)]	= PortPinPair{Port::PortA, Pin::Pin2};
		temp[to_underlying(PinName::PA_3)]	= PortPinPair{Port::PortA, Pin::Pin3};
		temp[to_underlying(PinName::PA_4)]	= PortPinPair{Port::PortA, Pin::Pin4};
		temp[to_underlying(PinName::PA_5)]	= PortPinPair{Port::PortA, Pin::Pin5};
		temp[to_underlying(PinName::PA_6)]	= PortPinPair{Port::PortA, Pin::Pin6};
		temp[to_underlying(PinName::PA_7)]	= PortPinPair{Port::PortA, Pin::Pin7};
		temp[to_underlying(PinName::PA_8)]	= PortPinPair{Port::PortA, Pin::Pin8};
		temp[to_underlying(PinName::PA_9)]	= PortPinPair{Port::PortA, Pin::Pin9};
		temp[to_underlying(PinName::PA_10)] = PortPinPair{Port::PortA, Pin::Pin10};
		temp[to_underlying(PinName::PA_11)] = PortPinPair{Port::PortA, Pin::Pin11};
		temp[to_underlying(PinName::PA_12)] = PortPinPair{Port::PortA, Pin::Pin12};
		temp[to_underlying(PinName::PA_13)] = PortPinPair{Port::PortA, Pin::Pin13};
		temp[to_underlying(PinName::PA_14)] = PortPinPair{Port::PortA, Pin::Pin14};
		temp[to_underlying(PinName::PA_15)] = PortPinPair{Port::PortA, Pin::Pin15};

		/* GPIO B */
		temp[to_underlying(PinName::PB_0)]	= PortPinPair{Port::PortB, Pin::Pin0};
		temp[to_underlying(PinName::PB_1)]	= PortPinPair{Port::PortB, Pin::Pin1};
		temp[to_underlying(PinName::PB_2)]	= PortPinPair{Port::PortB, Pin::Pin2};
		temp[to_underlying(PinName::PB_3)]	= PortPinPair{Port::PortB, Pin::Pin3};
		temp[to_underlying(PinName::PB_4)]	= PortPinPair{Port::PortB, Pin::Pin4};
		temp[to_underlying(PinName::PB_5)]	= PortPinPair{Port::PortB, Pin::Pin5};
		temp[to_underlying(PinName::PB_6)]	= PortPinPair{Port::PortB, Pin::Pin6};
		temp[to_underlying(PinName::PB_7)]	= PortPinPair{Port::PortB, Pin::Pin7};
		temp[to_underlying(PinName::PB_8)]	= PortPinPair{Port::PortB, Pin::Pin8};
		temp[to_underlying(PinName::PB_9)]	= PortPinPair{Port::PortB, Pin::Pin9};
		temp[to_underlying(PinName::PB_10)] = PortPinPair{Port::PortB, Pin::Pin10};
		temp[to_underlying(PinName::PB_11)] = PortPinPair{Port::PortB, Pin::Pin11};
		temp[to_underlying(PinName::PB_12)] = PortPinPair{Port::PortB, Pin::Pin12};
		temp[to_underlying(PinName::PB_13)] = PortPinPair{Port::PortB, Pin::Pin13};
		temp[to_underlying(PinName::PB_14)] = PortPinPair{Port::PortB, Pin::Pin14};
		temp[to_underlying(PinName::PB_15)] = PortPinPair{Port::PortB, Pin::Pin15};

		/* GPIO C */
		temp[to_underlying(PinName::PC_0)]	= PortPinPair{Port::PortC, Pin::Pin0};
		temp[to_underlying(PinName::PC_1)]	= PortPinPair{Port::PortC, Pin::Pin1};
		temp[to_underlying(PinName::PC_2)]	= PortPinPair{Port::PortC, Pin::Pin2};
		temp[to_underlying(PinName::PC_3)]	= PortPinPair{Port::PortC, Pin::Pin3};
		temp[to_underlying(PinName::PC_4)]	= PortPinPair{Port::PortC, Pin::Pin4};
		temp[to_underlying(PinName::PC_5)]	= PortPinPair{Port::PortC, Pin::Pin5};
		temp[to_underlying(PinName::PC_6)]	= PortPinPair{Port::PortC, Pin::Pin6};
		temp[to_underlying(PinName::PC_7)]	= PortPinPair{Port::PortC, Pin::Pin7};
		temp[to_underlying(PinName::PC_8)]	= PortPinPair{Port::PortC, Pin::Pin8};
		temp[to_underlying(PinName::PC_9)]	= PortPinPair{Port::PortC, Pin::Pin9};
		temp[to_underlying(PinName::PC_10)] = PortPinPair{Port::PortC, Pin::Pin10};
		temp[to_underlying(PinName::PC_11)] = PortPinPair{Port::PortC, Pin::Pin11};
		temp[to_underlying(PinName::PC_12)] = PortPinPair{Port::PortC, Pin::Pin12};
		temp[to_underlying(PinName::PC_13)] = PortPinPair{Port::PortC, Pin::Pin13};
		temp[to_underlying(PinName::PC_14)] = PortPinPair{Port::PortC, Pin::Pin14};
		temp[to_underlying(PinName::PC_15)] = PortPinPair{Port::PortC, Pin::Pin15};

		return temp;
	}();

 public:
	[[nodiscard]] static constexpr auto getPort(PinName const& t_pin_name) noexcept {
		return PinTable[to_underlying(t_pin_name)][0_ic];
	}

	[[nodiscard]] static constexpr auto getPin(PinName const& t_pin_name) noexcept {
		return PinTable[to_underlying(t_pin_name)][1_ic];
	}
};

}	// namespace cpp_stm32::gpio
