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

#include "cpp_stm32/common/gpio.hxx"
#include "cpp_stm32/target/stm32/common/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/memory/gpio_reg.hxx"

namespace cpp_stm32::stm32::f4 {

/**
 * @brief   This function handles the setup of mode
 * @tparam  Port      ::Port
 * @tparam  Pins      ::Pin
 * @param   t_mode    ::Mode
 */
template <gpio::Port Port, gpio::Pin... Pins>
constexpr void set_mode(gpio::Mode const& t_mode) noexcept {
	GPIO_MODER<Port>.template setBit<Pins...>(t_mode);
}

/**
 * @brief   This function handles the setup of pullup/pulldown
 * @tparam  Port    ::Port
 * @tparam  Pins    ::Pin
 * @param   t_pupd  ::Pupd
 */
template <gpio::Port Port, gpio::Pin... Pins>
constexpr void set_pupd(gpio::Pupd const& t_pupd) noexcept {
	GPIO_PUPDR<Port>.template setBit<Pins...>(t_pupd);
}

/**
 * @brief   This function handles the setup of mode and pullup/pulldown
 * @tparam  Port      ::Port
 * @tparam  Pins      ::Pin
 * @param   t_mode    ::Mode
 * @param   t_pupd    ::Pupd
 */
template <gpio::Port Port, gpio::Pin... Pins>
constexpr void mode_setup(gpio::Mode const& t_mode, gpio::Pupd const& t_pupd) noexcept {
	GPIO_MODER<Port>.template setBit<Pins...>(t_mode);
	GPIO_PUPDR<Port>.template setBit<Pins...>(t_pupd);
}

/**
 * @brief   This function toggles gpio pins atomically
 * @tparam  Port      ::Port
 * @tparam  Pins      ::Pin
 */
template <gpio::Port Port, gpio::Pin... Pins>
constexpr void toggle() noexcept {
	constexpr auto HALF_WORD_OFFSET = 16U;

	auto const m_odr	 = GPIO_ODR<Port>.template readBit<Pins...>(ValueOnly);
	auto const mod_val = bit_group_cat(~m_odr, m_odr);

	// this is a bit hacky IMO, but can't come up with a better idea
	// @todo perhap add index rule in register class
	// @todo maybe group bits in SETUP_REGISTER_INFO macro, e.g.
	//			 SETUP_REGISTER_INFO(GpioBsrrInfo, {Bit<>{0}, Bit<>{16}, {...}})
	GPIO_BSRR<Port>.template setBit<Pins..., gpio::Pin{to_underlying(Pins) + HALF_WORD_OFFSET}...>(mod_val);
}

/**
 * @brief    This function handles the setup of alternate function
 * @tparam    Port    ::Port
 * @tparam    Pins    ::Pin
 * @param     t_af    ::AltFunc
 */
template <gpio::Port Port, gpio::Pin... Pins>
constexpr void set_alternate_function(gpio::AltFunc const& t_af) noexcept {
	constexpr auto Pin7				 = gpio::Pin::Pin7;
	constexpr auto cast_to_int = [](auto const& t_val) {
		return to_underlying(t_val);
	};	// to prevent internal compiler error
	if constexpr (((Pins <= Pin7) || ...)) {
		constexpr auto low_pin_group = [](gpio::Pin t_pin) {
			if (t_pin <= Pin7) {
				return t_pin;
			}
		};

		GPIO_AFRL<Port>.template setBit<low_pin_group(Pins)...>(t_af);
	}

	if constexpr (((Pins > Pin7) || ...)) {
		constexpr auto high_pin_group = [](gpio::Pin t_pin) {
			if (t_pin > Pin7) {
				return gpio::Pin{cast_to_int(t_pin) - 8};
			}
		};

		GPIO_AFRH<Port>.template setBit<high_pin_group(Pins)...>(t_af);
	}
}

}	 // namespace cpp_stm32::stm32::f4
