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

#include "cpp_stm32/target/stm32/common/gpio_reg.hxx"
#include "cpp_stm32/target/stm32/f3/memory/memory_map.hxx"

namespace cpp_stm32::common {

enum class GpioPort {
	PortA,
	PortB,
	PortC,
	PortD,
	PortEReserved,
	PortF,
};

enum class GpioPin {
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

enum class GpioMode { Input, Output, AltFunc, Analog };
enum class GpioPupd { None, PullUp, PullDown };
enum class GpioOutType { PushPull, OpenDrain };
enum class GpioOutSpeed { Low2M, Medium10M, High50M };
enum class GpioAltFunc { AF0, AF1, AF2, AF3, AF4, AF5, AF6, AF7, AF8, AF9, AF10, AF11, AF12, AF13, AF14, AF15 };

}	 // namespace cpp_stm32::common

namespace cpp_stm32::stm32 {

constexpr auto GPIO_BASE(common::GpioPort const& t_port) noexcept {
	return memory_at(PeriphAddr::Ahb2Base, 0x0400 * to_underlying(t_port));
}

}	 // namespace cpp_stm32::stm32
