/**
 * @file  stm32/f4/define/i2c.hxx
 * @brief	This file contains I2C class and enum define.
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

namespace cpp_stm32::i2c {

enum class Port : std::uint8_t { I2C3, I2C2, I2C1 };

enum class SlaveAddressMode : std::uint8_t { SevenBits, TenBits };

}	 // namespace cpp_stm32::i2c
