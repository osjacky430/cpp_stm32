/**
 * @file  stm32/f4/define/gpio.hxx
 * @brief	GPIO class and enum define.
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

namespace cpp_stm32::gpio {

enum class Port : std::uint8_t { PortA, PortB, PortC, PortD, PortE, PortF, PortG, PortH, Total };

enum class Pin : std::uint8_t {
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
 * @enum 	Mode
 * @brief	Gpio Mode
 */
enum class Mode : std::uint8_t {
	Input,	 /*!< Input mode */
	Output,	 /*!< Output mode */
	AltFunc, /*!< Alternate Function mode*/
	Analog	 /*!< Analog mode*/
};

enum class Pupd : std::uint8_t { None, PullUp, PullDown };
enum class OutputType : std::uint8_t { PushPull, OpenDrain };
enum class OutputSpeed : std::uint8_t { Low, Medium, Fast, High };
enum class AltFunc : std::uint8_t {
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
};

/**
 * @enum  PinName
 *
 */
enum class PinName {
	// clang-format off
	PA_0, PA_1,	PA_2,	PA_3,	PA_4, PA_5, PA_6, PA_7,	PA_8,	PA_9,	PA_10,	PA_11,	PA_12,	PA_13,	PA_14,	PA_15,	 // Gpio A
	PB_0, PB_1,	PB_2,	PB_3,	PB_4,	PB_5,	PB_6,	PB_7,	PB_8,	PB_9,	PB_10,	PB_11,	PB_12,	PB_13,	PB_14,	PB_15,	// GPIOB
	PC_0, PC_1,	PC_2,	PC_3,	PC_4,	PC_5,	PC_6,	PC_7,	PC_8,	PC_9,	PC_10,	PC_11,	PC_12,	PC_13,	PC_14,	PC_15, // GPIOC
	Total,
	NC
	// clang-format on
};

}	 // namespace cpp_stm32::gpio
