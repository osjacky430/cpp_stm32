/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 * @Last modified time: 2019-11-27T22:03:19+08:00
 */

#include "include/gpio.hpp"
#include "include/nvic.hpp"
#include "include/rcc.hpp"
// [[gnu::constructor(101)]] void init_test() {}

constexpr void set_rcc() noexcept {
	// HseClk<HseClkSrc::Bypass>::setup();
}

int main() {
	set_rcc();
	// Interrupt<IrqNum::WindowWatchDog>::enable();
	RccPeriphController<RccPeriph::GPIOA>::enable();

	GpioController<GpioPort::PortA, GpioPin::Pin5> led;
	led.modeSetup(GpioMode::Output, GpioPupd::None);

	while (true) {
		for (int i = 0; i < 1000000; ++i) {
		}

		led.toggle();
	}

	return 0;
}
