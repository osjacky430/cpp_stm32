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

#include "cpp_stm32/common/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/interrupt.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/usart.hxx"

namespace cpp_stm32::stm32 {

class UsartPinMap {
 private:
	// this is not the best way of doing it
	using PinName						= gpio::PinName;
	using UsartAltFuncGroup = std::tuple<f4::UsartNum, gpio::AltFunc, f4::RccPeriph, IrqNum>;

	static constexpr auto TX_PIN_NAME_TABLE = std::array{
		std::pair{PinName::PA_2, UsartAltFuncGroup{f4::UsartNum::Usart2, gpio::AltFunc::AF7, f4::RccPeriph::Usart2,
																							 IrqNum::Usart2Global}},
	};

	static constexpr auto RX_PIN_NAME_TABLE = std::array{
		std::pair{PinName::PA_3, UsartAltFuncGroup{f4::UsartNum::Usart2, gpio::AltFunc::AF7, f4::RccPeriph::Usart2,
																							 IrqNum::Usart2Global}},
	};

	static constexpr auto USART_PIN_NAME_TABLE = std::tuple{TX_PIN_NAME_TABLE, RX_PIN_NAME_TABLE};

 public:
	enum class PinInfo { Tx, Rx };

	template <PinName Pin, PinInfo Idx>
	static constexpr auto getPinInfo() noexcept {
		constexpr auto PIN_NAME_TABLE = std::get<to_underlying(Idx)>(USART_PIN_NAME_TABLE);
		const auto iter_pos						= cstd::find_if(PIN_NAME_TABLE.begin(), PIN_NAME_TABLE.end(),
																				[](auto const& t_pair) { return (t_pair.first == Pin); });

		return iter_pos->second;
	};
};

}	 // namespace cpp_stm32::stm32
