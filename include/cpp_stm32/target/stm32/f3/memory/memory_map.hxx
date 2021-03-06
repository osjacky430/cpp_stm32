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

#include "cpp_stm32/processor/cortex_m4/memory/internal_periph.hxx"

namespace cpp_stm32::stm32 {

/**
 * @enum  PeriphAddr
 * @brief
 */
enum class PeriphAddr : std::uint32_t {
	PeriphBase = 0x40000000U,
	Apb1Base	 = memory_at(PeriphBase, 0x00000U),
	Apb2Base	 = memory_at(PeriphBase, 0x10000U),
	Ahb1Base	 = memory_at(PeriphBase, 0x20000U),
	Ahb2Base	 = memory_at(PeriphBase, 0x0800'0000U),
	Ahb3Base	 = memory_at(PeriphBase, 0x1000'0000U),
};

}	 // namespace cpp_stm32::stm32
