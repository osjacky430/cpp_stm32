/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 * @Last modified time: 2019-12-11T00:50:51+08:00
 */

#include "include/hal/gpio.hpp"
#include "include/hal/nvic.hpp"
#include "include/hal/rcc.hpp"

#include "include/driver/digitalout.hpp"

int main() {
	// rcc_enable_clk<RccOsc::HsiOsc>();
	// rcc_is_osc_rdy<RccOsc::HsiOsc>();

	DigitalOut<PinName::PA_5> led;

	while (true) {
		for (int i = 0; i < 1000000; ++i) {
		}

		led.toggle();
	}

	return 0;
}
