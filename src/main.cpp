/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 */

#include "include/hal/nvic.hpp"
#include "include/hal/peripheral/rcc.hxx"

#include "include/driver/digitalout.hpp"
#include "include/hal/sys_init.hxx"

int main() {
	SysClock::init(PllClkSrc<RccOsc::HseOsc>{});

	DigitalOut<PinName::PA_5> led;

	while (true) {
		constexpr auto SOME_PERIOD = 1000000;
		for (int i = 0; i < SOME_PERIOD; ++i) {
		}

		led.toggle();
	}

	return 0;
}
