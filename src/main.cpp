/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 * @Last modified time: 2019-12-15T14:54:13+08:00
 */

#include "include/hal/gpio.hpp"
#include "include/hal/nvic.hpp"
#include "include/hal/peripheral/rcc.hxx"

#include "include/driver/digitalout.hpp"

constexpr void init_rcc() {
	rcc_bypass_clksrc<RccOsc::HseOsc>();
	rcc_set_sysclk<SysClk::Hse>();
}

int main() {
	init_rcc();
	// RCC_CR.setBit<RccCrReg::HsiOn>();
	// rcc_enable_clk<RccOsc::HsiOsc>();
	// RCC_PLLCFGR.setBit<RccPllCfgBit::PLLM>(PllM{DivisionFactor_v<20U>});

	DigitalOut<PinName::PA_5> led;

	while (true) {
		for (int i = 0; i < 1000000; ++i) {
		}

		led.toggle();
	}

	return 0;
}
