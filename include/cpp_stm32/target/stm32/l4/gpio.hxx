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

#include "cpp_stm32/detail/tuple.hxx"
#include "cpp_stm32/target/stm32/l4/register/gpio.hxx"

namespace cpp_stm32::gpio {

/**
 * @brief   This function handles the setup of mode
 * @tparam  Port      ::Port
 * @tparam  Pins      ::Pin
 * @param   t_mode    ::Mode
 */
template <Port Port, Pin... Pins>
constexpr void set_mode(Mode const& t_mode) noexcept {
	// do some static assertion
	// static_assert(Port < Port::PortJ);
	reg::MODER<Port>.template writeBit<Pins...>(t_mode);
}

/**
 * @brief   This function handles the setup of pullup/pulldown
 * @tparam  Port    ::Port
 * @tparam  Pins    ::Pin
 * @param   t_pupd  ::Pupd
 */
template <Port Port, Pin... Pins>
constexpr void set_pupd(Pupd const& t_pupd) noexcept {
	reg::PUPDR<Port>.template writeBit<Pins...>(t_pupd);
}

/**
 * @brief   This function handles the setup of mode and pullup/pulldown
 * @tparam  Port      ::Port
 * @tparam  Pins      ::Pin
 * @param   t_mode    ::Mode
 * @param   t_pupd    ::Pupd
 */
template <Port Port, Pin... Pins>
constexpr void mode_setup(Mode const& t_mode, Pupd const& t_pupd) noexcept {
	reg::MODER<Port>.template writeBit<Pins...>(t_mode);
	reg::PUPDR<Port>.template writeBit<Pins...>(t_pupd);
}

/**
 * @brief   This function toggles gpio pins atomically
 * @tparam  Port      ::Port
 * @tparam  Pins      ::Pin
 */
template <Port Port, Pin... Pins>
constexpr void toggle() noexcept {
	using namespace detail;
	constexpr auto HALF_WORD_OFFSET = 16U;

	auto const m_odr	 = reg::ODR<Port>.template readBit<Pins...>(ValueOnly);
	auto const mod_val = std::tuple_cat(~m_odr, m_odr);

	// this is a bit hacky IMO, but can't come up with a better idea
	// @todo perhap add index rule in register class
	// @todo maybe group bits in SETUP_REGISTER_INFO macro, e.g.
	//			 SETUP_REGISTER_INFO(GpioBsrrInfo, {Bit<>{0}, Bit<>{16}, {...}})
	reg::BSRR<Port>.template writeBit<Pins..., Pin{to_underlying(Pins) + HALF_WORD_OFFSET}...>(mod_val);
}

// helper struct
template <Port InputPort, Pin... Pins>
struct SortAfrPins {
	static constexpr auto PIN_LIST		 = std::tuple{Pins...};
	static constexpr auto HIGH_PIN_NUM = ((Pins > Pin::Pin7) + ...);
	static constexpr auto LOW_PIN_NUM	 = sizeof...(Pins) - HIGH_PIN_NUM;

	template <std::size_t... Idx>
	static constexpr auto GEN_LOW_PIN(std::index_sequence<Idx...> const /**/) noexcept {
		constexpr auto IterateThruPins = [](auto const t_pin) {
			if constexpr (constexpr auto pin_name = std::get<t_pin()>(PIN_LIST); pin_name <= Pin::Pin7) {
				return std::tuple{pin_name};
			} else {
				return std::tuple{};
			}
		};

		return std::tuple_cat(IterateThruPins(size_c<Idx>{})...);
	}

	template <std::size_t... Idx>
	static constexpr auto GEN_HIGH_PIN(std::index_sequence<Idx...> const /**/) noexcept {
		constexpr auto IterateThruPins = [](auto const t_pin) {
			if constexpr (constexpr auto pin_name = std::get<t_pin()>(PIN_LIST); pin_name > Pin::Pin7) {
				return std::tuple{pin_name};
			} else {
				return std::tuple{};
			}
		};

		return std::tuple_cat(IterateThruPins(size_c<Idx>{})...);
	}

	static constexpr auto HIGH_PIN_LIST = GEN_HIGH_PIN(std::make_index_sequence<sizeof...(Pins)>{});
	static constexpr auto LOW_PIN_LIST	= GEN_LOW_PIN(std::make_index_sequence<sizeof...(Pins)>{});

	template <std::size_t... Idx>
	static constexpr void set_afhr([[maybe_unused]] AltFunc const t_af, std::index_sequence<Idx...> const /**/) noexcept {
		if constexpr (HIGH_PIN_NUM > 0) {
			reg::AFRH<InputPort>.template writeBit<std::get<Idx>(HIGH_PIN_LIST)...>(t_af);
		}
	}

	template <std::size_t... Idx>
	static constexpr void set_aflr([[maybe_unused]] AltFunc const t_af, std::index_sequence<Idx...> const /**/) noexcept {
		if constexpr (LOW_PIN_NUM > 0) {
			reg::AFRL<InputPort>.template writeBit<std::get<Idx>(LOW_PIN_LIST)...>(t_af);
		}
	}
};

/**
 * @brief     This function handles the setup of alternate function
 * @tparam    InputPort @ref gpio::Port
 * @tparam    Pins    	@ref gpio::Pin
 * @param     t_af    	@ref gpio::AltFunc
 *
 */
template <Port InputPort, Pin... Pins>
constexpr void set_alternate_function(AltFunc const t_af) noexcept {
	constexpr SortAfrPins<InputPort, Pins...> afr_pins;

	afr_pins.set_aflr(t_af, std::make_index_sequence<afr_pins.LOW_PIN_NUM>{});
	afr_pins.set_afhr(t_af, std::make_index_sequence<afr_pins.HIGH_PIN_NUM>{});
}

/**
 * @brief			This function set the gpio to high
 * @tparam 		InputPort  @ref gpio::Port
 * @tparam 		Pins 			 @ref gpio::Pin
 */
template <Port InputPort, Pin... Pins>
constexpr void set() noexcept {
	reg::BSRR<InputPort>.template setBit<Pins...>();
}

/**
 * @brief		This function clears the gpio pin to low
 * @tparam 		InputPort  @ref gpio::Port
 * @tparam 		Pins 			 @ref gpio::Pin
 */
template <Port InputPort, Pin... Pins>
constexpr void clear() noexcept {
	constexpr auto HALF_WORD_OFFSET = 16U;
	reg::BSRR<InputPort>.template setBit<Pin{to_underlying(Pins) + HALF_WORD_OFFSET}...>();
}

}	 // namespace cpp_stm32::gpio
