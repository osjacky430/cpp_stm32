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
#include "cpp_stm32/target/stm32/f4/memory/gpio_reg.hxx"

namespace cpp_stm32::gpio {

/**
 * @brief   This function handles the setup of mode
 * @tparam  Port      ::Port
 * @tparam  Pins      ::Pin
 * @param   t_mode    ::Mode
 */
template <Port InputPort, Pin... Pins>
constexpr void set_mode(Mode const& t_mode) noexcept {
	reg::MODER<InputPort>.template writeBit<Pins...>(t_mode);
}

/**
 * @brief   This function handles the setup of pullup/pulldown
 * @tparam  Port    ::Port
 * @tparam  Pins    ::Pin
 * @param   t_pupd  ::Pupd
 */
template <Port InputPort, Pin... Pins>
constexpr void set_pupd(Pupd const& t_pupd) noexcept {
	reg::PUPDR<InputPort>.template writeBit<Pins...>(t_pupd);
}

/**
 * @brief   This function handles the setup of mode and pullup/pulldown
 * @tparam  Port      ::Port
 * @tparam  Pins      ::Pin
 * @param   t_mode    ::Mode
 * @param   t_pupd    ::Pupd
 */
template <Port InputPort, Pin... Pins>
constexpr void mode_setup(Mode const& t_mode, Pupd const& t_pupd) noexcept {
	reg::MODER<InputPort>.template writeBit<Pins...>(t_mode);
	reg::PUPDR<InputPort>.template writeBit<Pins...>(t_pupd);
}

/**
 * @brief   This function toggles gpio pins atomically
 * @tparam  Port      ::Port
 * @tparam  Pins      ::Pin
 */
template <Port InputPort, Pin... Pins>
constexpr void toggle() noexcept {
	constexpr auto HALF_WORD_OFFSET = 16U;

	auto const m_odr	 = reg::ODR<InputPort>.template readBit<Pins...>(ValueOnly);
	auto const mod_val = bit_group_cat(~m_odr, m_odr);

	// this is a bit hacky IMO, but can't come up with a better idea
	// @todo perhap add index rule in register class
	// @todo maybe group bits in SETUP_REGISTER_INFO macro, e.g.
	//			 SETUP_REGISTER_INFO(GpioBsrrInfo, {Bit<>{0}, Bit<>{16}, {...}})
	reg::BSRR<InputPort>.template writeBit<Pins..., Pin{to_underlying(Pins) + HALF_WORD_OFFSET}...>(mod_val);
}

/**
 * @brief    This function handles the setup of alternate function
 * @tparam    Port    ::Port
 * @tparam    Pins    ::Pin
 * @param     t_af    ::AltFunc
 */
template <Port InputPort, Pin... Pins>
constexpr void set_alternate_function(AltFunc const& t_af) noexcept {
	constexpr auto Pin7				 = Pin::Pin7;
	constexpr auto cast_to_int = [](auto const& t_val) {
		return to_underlying(t_val);
	};	// to prevent internal compiler error
	if constexpr (((Pins <= Pin7) || ...)) {
		constexpr auto low_pin_group = [](Pin t_pin) {
			if (t_pin <= Pin7) {
				return t_pin;
			}
		};

		reg::AFRL<InputPort>.template writeBit<low_pin_group(Pins)...>(t_af);
	}

	if constexpr (((Pins > Pin7) || ...)) {
		constexpr auto high_pin_group = [](Pin t_pin) {
			if (t_pin > Pin7) {
				return Pin{cast_to_int(t_pin) - 8};
			}
		};

		reg::AFRH<InputPort>.template writeBit<high_pin_group(Pins)...>(t_af);
	}
}

}	 // namespace cpp_stm32::gpio
