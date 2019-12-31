/**
 * @Date:   2019-11-29T20:17:17+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: digitalout.hpp
 */

#ifndef DIGITAL_OUT_HPP_
#define DIGITAL_OUT_HPP_

#include "cpp_stm32/driver/gpio_base.hxx"
#include "cpp_stm32/target/stm32/f4/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"
#include "cpp_stm32/utility/utility.hxx"

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
