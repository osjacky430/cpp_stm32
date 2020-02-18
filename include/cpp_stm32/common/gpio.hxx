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

#include <cstdint>

/**
 * @namespace  cpp_stm32::gpio
 * @brief      General Purpose Input Output Namespace
 */
namespace cpp_stm32::gpio {

/**
 * @enum    Port
 * @brief   Port is a group of Pin arranged in a group. The naming convenetion
 *          differs from Manufacture to Manufacture, e.g., for STMicroelectronics, the
 *          port is named in alphabetic order; for TI, the port is named in numeric order.
 */
enum class Port : std::uint8_t;

/**
 * @enum    Pin
 * @brief   Port contains multiple Gpio pins, the number of pin in a port varies from
 *          Manufacture to Manufacture, e.g., for STMicroelectronics, a port contains 16 pins
 *          , as for TI, a port contains 8 pins.
 */
enum class Pin : std::uint8_t;

enum class Mode : std::uint8_t;
enum class Pupd : std::uint8_t;
enum class OutputType : std::uint8_t;
enum class OutputSpeed : std::uint8_t;
enum class AltFunc : std::uint8_t;

enum class PinName;

}	 // namespace cpp_stm32::gpio
