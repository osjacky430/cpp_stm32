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

#include <tuple>

#include "cpp_stm32/common/gpio_common.hxx"
#include "cpp_stm32/target/stm32/l4/memory/gpio_reg.hxx"

namespace cpp_stm32::stm32::l4 {

template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_set_mode(common::GpioMode const& t_mode) noexcept {
	GPIO_MODER<Port>.template setBit<Pins...>(t_mode);
}

template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_set_pupd(common::GpioPupd const& t_pupd) noexcept {
	GPIO_PUPDR<Port>.template setBit<Pins...>(t_pupd);
}

template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_mode_setup(common::GpioMode const& t_mode, common::GpioPupd const& t_pupd) noexcept {
	GPIO_MODER<Port>.template setBit<Pins...>(t_mode);
	GPIO_PUPDR<Port>.template setBit<Pins...>(t_pupd);
}

template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_toggle() noexcept {
	constexpr auto HALF_WORD_OFFSET = 16U;

	auto const m_odr	 = GPIO_ODR<Port>.template readBit<Pins...>(ValueOnly);
	auto const mod_val = bit_group_cat(~m_odr, m_odr);

	// this is a bit hacky IMO, but can't come up with a better idea
	// @todo perhap add index rule in register class
	// @todo maybe group bits in SETUP_REGISTER_INFO macro, e.g.
	//			 SETUP_REGISTER_INFO(GpioBsrrInfo, {Bit<>{0}, Bit<>{16}, {...}})
	GPIO_BSRR<Port>.template setBit<Pins..., common::GpioPin{to_underlying(Pins) + HALF_WORD_OFFSET}...>(mod_val);
}

}	 // namespace cpp_stm32::stm32::l4
