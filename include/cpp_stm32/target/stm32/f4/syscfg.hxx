/**
 * @file  stm32/f4/syscfg.hxx
 * @brief	SysCfg setup API for stm32f4
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

#include "cpp_stm32/target/stm32/f4/define/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/register/syscfg.hxx"

namespace cpp_stm32::syscfg {

template <gpio::Port Port, gpio::Pin Pin>
constexpr void config_exti_source() noexcept {
	reg::EXTICRx<Pin>.template writeBit<Pin>(Port);
}

}	 // namespace cpp_stm32::syscfg
