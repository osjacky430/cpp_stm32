/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 */

#include "include/driver/digitalout.hpp"
#include "include/driver/usart.hxx"
#include "include/hal/nvic.hpp"

#include "include/hal/peripheral/rcc.hxx"
#include "include/hal/peripheral/usart.hxx"

#include "include/hal/sys_init.hxx"

int main() {
	SysClock::init(PllClkSrc<RccOsc::HseOsc>{});

	// setup_usart();

	Usart debug(UsartTx_v<PinName::PA_2>, UsartRx_v<PinName::PA_3>, 115200);
	DigitalOut<PinName::PA_5> led;

	while (true) {
		constexpr auto SOME_PERIOD = 1000000;
		for (int i = 0; i < SOME_PERIOD; ++i) {
			__asm__("nop");
		}

		led.toggle();

		debug << "string\n\r";
	}

	return 0;
}
