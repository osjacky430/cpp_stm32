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
#include "cpp_stm32/utility/utility.hxx"

namespace cpp_stm32::gpio {

enum class Port { PortA, PortB, PortC, PortD, PortE, PortF, PortG, PortH, PortI, PortJ, PortK, Total };

enum class Pin {
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7,
	Pin8,
	Pin9,
	Pin10,
	Pin11,
	Pin12,
	Pin13,
	Pin14,
	Pin15,
	Total
};

/**
 * @enum Mode
 */
enum class Mode {
	Input,	 /*!< Input mode */
	Output,	 /*!< Output mode */
	AltFunc, /*!< Alternate Function mode*/
	Analog	 /*!< Analog mode*/
};

enum class Pupd { None, PullUp, PullDown };
enum class OutputType { PushPull, OpenDrain };
enum class OutputSpeed { Low, Medium, Fast, High };
enum class AltFunc { AF0, AF1, AF2, AF3, AF4, AF5, AF6, AF7, AF8, AF9, AF10, AF11, AF12, AF13, AF14, AF15 };

/**
 * @enum  PinName
 */
enum class PinName { PA_1, PA_2, PA_3, PA_5, PB_1, PB_2, PB_3, NC };

}	 // namespace cpp_stm32::gpio

namespace cpp_stm32::stm32::detail {

using gpio::Port, gpio::Pin;

/**
 * @var 		PIN_NAME_TABLE
 * @brief
 *
 */
static constexpr std::array PIN_NAME_TABLE{
	std::pair{Port::PortA, Pin::Pin1}, std::pair{Port::PortA, Pin::Pin2}, std::pair{Port::PortA, Pin::Pin3},
	std::pair{Port::PortA, Pin::Pin5}, std::pair{Port::PortB, Pin::Pin1}, std::pair{Port::PortB, Pin::Pin2},
	std::pair{Port::PortB, Pin::Pin3},
};

}	 // namespace cpp_stm32::stm32::detail

namespace cpp_stm32::stm32 {

[[nodiscard]] constexpr auto get_port_from_pin_name_table(gpio::PinName const& t_pin_name) noexcept {
	return std::get<0>(detail::PIN_NAME_TABLE[to_underlying(t_pin_name)]);
}

[[nodiscard]] constexpr auto get_pin_from_pin_name_table(gpio::PinName const& t_pin_name) noexcept {
	return std::get<1>(detail::PIN_NAME_TABLE[to_underlying(t_pin_name)]);
}

}	 // namespace cpp_stm32::stm32
