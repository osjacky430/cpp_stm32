/**
 * @Date:   2019-11-29T20:17:17+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: digitalout.hpp
 */

#ifndef DIGITAL_OUT_HPP_
#define DIGITAL_OUT_HPP_

#include <array>
#include <tuple>
#include <type_traits>
#include <utility>

#include "include/driver/gpio_base.hpp"
#include "include/driver/utility.hpp"

#include "include/hal/peripheral/gpio.hxx"
#include "include/hal/peripheral/rcc.hxx"

template <PinName... PinNames>
class DigitalOut {
 private:
 public:
	constexpr DigitalOut() {
		GpioUtil<PinNames...>::enableAllGpioClk();
		GpioUtil<PinNames...>::modeSetup(GpioMode::Output, GpioPupd::None);
	}

	constexpr void toggle() const noexcept { GpioUtil<PinNames...>::toggle(); }
};

#endif	// DIGITAL_OUT_HPP_
