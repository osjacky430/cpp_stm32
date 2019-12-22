/**
 * @Date:   2019-11-23T16:40:20+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: gpio.hpp
 */
#ifndef GPIO_HPP_
#define GPIO_HPP_

#include <tuple>

#include "include/hal/memory_map.hxx"
#include "include/hal/peripheral/memory/gpio_reg.hxx"
#include "include/hal/utility.hxx"

constexpr auto GPIO_BSRR = [](const GpioPort t_port) noexcept -> decltype(auto) {
	return MMIO32(GPIO_BASE(t_port), 0x18U);
};

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
	GPIO_BSRR_<Port>.template setBit<Pins..., GpioPin{to_underlying(Pins) + HALF_WORD_OFFSET}...>(mod_val);
}

#endif
