/**
 * @Date:   2019-11-23T16:40:20+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: gpio.hpp
 */
#pragma once

#include <tuple>

#include "include/hal/memory_map.hxx"
#include "include/hal/peripheral/memory/gpio_reg.hxx"
#include "include/hal/utility.hxx"

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
