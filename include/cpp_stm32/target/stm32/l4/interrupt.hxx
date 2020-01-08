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

#define NVIC_INTERRUPT 0
#define NVIC_IRQ_NUM 1
// 73

#pragma once

#include <cstdint>

#include "cpp_stm32/utility/callback.hxx"
#include "cpp_stm32/utility/interrupt.hxx"
#include "cpp_stm32/utility/utility.hxx"

namespace cpp_stm32::stm32::l4 {}

namespace cpp_stm32 {
enum class IrqNum : std::uint8_t {

};
}
