/**
 * @Date:   2019-11-23T16:40:20+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: gpio.hpp
 */
#ifndef GPIO_HPP_
#define GPIO_HPP_

#include "include/hal/memory_map.hxx"
#include "include/hal/peripheral/memory/gpio_reg.hxx"
#include "include/hal/utility.hxx"

constexpr auto GPIO_ODR = [](const GpioPort t_port) noexcept -> decltype(auto) {
	return MMIO32(GPIO_BASE(t_port), 0x14U);
};

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
	const auto odr = GPIO_ODR_<Port>.readBit();

	// GPIO_BSRR(Port) = ((odr & pins) << 16U) | (~odr & pins);
}

template <typename... Pins>
constexpr void gpio_toggle(const GpioPort t_port, Pins... t_all_of_pins) noexcept {
	const auto pins = (... | (1U << to_underlying(t_all_of_pins)));
	const auto odr	= GPIO_ODR(t_port);

	GPIO_BSRR(t_port) = ((odr & pins) << 16U) | (~odr & pins);
}

#endif
