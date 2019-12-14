/**
 * @Date:   2019-11-23T16:40:20+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: gpio.hpp
 * @Last modified time: 2019-12-13T20:31:03+08:00
 */
#ifndef GPIO_HPP_
#define GPIO_HPP_

#include "include/hal/memory_map.hxx"
#include "include/hal/utility.hxx"

enum class GpioPort { PortA, PortB, PortC, Total };

enum class GpioPin { Pin0, Pin1, Pin2, Pin3, Pin4, Pin5, Total };

enum class GpioMode { Input, Output, AltFunc, Analog };
enum class GpioPupd { None, PullUp, PullDown };
enum class GpioOutType { PushPull, OpenDrain };
enum class GpioOutSpeed { Low2M, Medium25M, Fast50M, High100M };
enum class GpioAltFunc { AF0, AF1, AF2, AF3 };

constexpr auto PORT_ADDRESS(const GpioPort t_port) {
	return memory_at(MemoryMap::Ahb1Base, 0x0400U * to_underlying(t_port));
}

constexpr auto GPIO_MODER = [](const GpioPort t_port) noexcept -> decltype(auto) {
	return MMIO32(PORT_ADDRESS(t_port), 0x00U);
};

constexpr auto GPIO_PUPDR = [](const GpioPort t_port) noexcept -> decltype(auto) {
	return MMIO32(PORT_ADDRESS(t_port), 0x0CU);
};

constexpr auto GPIO_ODR = [](const GpioPort t_port) noexcept -> decltype(auto) {
	return MMIO32(PORT_ADDRESS(t_port), 0x14U);
};

constexpr auto GPIO_BSRR = [](const GpioPort t_port) noexcept -> decltype(auto) {
	return MMIO32(PORT_ADDRESS(t_port), 0x18U);
};

template <typename... Pins>
constexpr void gpio_mode_setup(const GpioPort t_port, const GpioMode t_mode, const GpioPupd t_pupd,
															 Pins... t_all_of_pins) noexcept {
	const auto moder = GPIO_MODER(t_port);
	const auto pupdr = GPIO_PUPDR(t_port);

	const auto moder_flag = (... | (to_underlying(t_mode) << (2U * to_underlying(t_all_of_pins))));
	const auto pupdr_flag = (... | (to_underlying(t_pupd) << (2U * to_underlying(t_all_of_pins))));

	const auto moder_mask = ~(... | (0b11 << (to_underlying(t_all_of_pins)) * 2U));
	const auto pupdr_mask = ~(... | (0b11 << (to_underlying(t_all_of_pins)) * 2U));

	GPIO_MODER(t_port) = (moder & moder_mask) | moder_flag;
	GPIO_PUPDR(t_port) = (pupdr & pupdr_mask) | pupdr_flag;
}

template <typename... Pins>
constexpr void gpio_toggle(const GpioPort t_port, Pins... t_all_of_pins) noexcept {
	const auto pins = (... | (1U << to_underlying(t_all_of_pins)));
	const auto odr	= GPIO_ODR(t_port);

	GPIO_BSRR(t_port) = ((odr & pins) << 16U) | (~odr & pins);
}

#endif
