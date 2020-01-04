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

#include "cpp_stm32/target/stm32/f4/memory/gpio_reg.hxx"

// @todo add function to namespace
namespace cpp_stm32::stm32::f4 {

template <GpioPort Port, GpioPin... Pins>
constexpr void gpio_set_mode(GpioMode const& t_mode) noexcept {
	GPIO_MODER<Port>.template setBit<Pins...>(t_mode);
}

template <GpioPort Port, GpioPin... Pins>
constexpr void gpio_set_pupd(GpioPupd const& t_pupd) noexcept {
	GPIO_PUPDR<Port>.template setBit<Pins...>(t_pupd);
}

template <GpioPort Port, GpioPin... Pins>
constexpr void gpio_mode_setup(GpioMode const& t_mode, GpioPupd const& t_pupd) noexcept {
	GPIO_MODER<Port>.template setBit<Pins...>(t_mode);
	GPIO_PUPDR<Port>.template setBit<Pins...>(t_pupd);
}

template <GpioPort Port, GpioPin... Pins>
constexpr void gpio_toggle() noexcept {
	constexpr auto HALF_WORD_OFFSET = 16U;

	auto const m_odr	 = GPIO_ODR<Port>.template readBit<Pins...>(ValueOnly);
	auto const mod_val = bit_group_cat(~m_odr, m_odr);

	// this is a bit hacky IMO, but can't come up with a better idea
	// @todo perhap add index rule in register class
	// @todo maybe group bits in SETUP_REGISTER_INFO macro, e.g.
	//			 SETUP_REGISTER_INFO(GpioBsrrInfo, {Bit<>{0}, Bit<>{16}, {...}})
	GPIO_BSRR<Port>.template setBit<Pins..., GpioPin{to_underlying(Pins) + HALF_WORD_OFFSET}...>(mod_val);
}

template <GpioPort Port, GpioPin... Pins>
constexpr void gpio_set_af(GpioAltFunc const& t_af) noexcept {
	if constexpr (((Pins <= GpioPin::Pin7) || ...)) {
		constexpr auto low_pin_group = [](GpioPin t_pin) {
			if (t_pin <= GpioPin::Pin7) {
				return t_pin;
			}
		};

		GPIO_AFRL<Port>.template setBit<low_pin_group(Pins)...>(t_af);
	}

	if constexpr (((Pins > GpioPin::Pin7) || ...)) {
		constexpr auto high_pin_group = [](GpioPin t_pin) {
			if (t_pin > GpioPin::Pin7) {
				// use "to_underlying" will generate internal compiler error

				// this is a bit hacky IMO, but can't come up with a better idea
				// @todo perhap add index rule in register class

				return GpioPin{static_cast<std::underlying_type_t<GpioPin>>(t_pin) - 8};
			}
		};

		GPIO_AFRH<Port>.template setBit<high_pin_group(Pins)...>(t_af);
	}
}

}	 // namespace cpp_stm32::stm32::f4
