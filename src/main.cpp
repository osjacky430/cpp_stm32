/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 */

#include "sys_init.hxx"

#include "cpp_stm32/driver/digitalout.hxx"
#include "cpp_stm32/driver/usart_serial.hxx"

using namespace cpp_stm32::driver;
using namespace target_device;
using namespace cpp_stm32::gpio;
using namespace cpp_stm32::usart;

int main() {
	SysClock::init<RccOsc::MsiOsc>();

	Usart const debugOut{UsartTx_v<PinName::PA_2>, UsartRx_v<PinName::PA_3>, 9600_Baud};
	DigitalOut<PinName::PB_3> led;

	while (true) {
		constexpr auto SOME_PERIOD = 1000000;
		for (int i = 0; i < SOME_PERIOD; ++i) {
			__asm__("nop");
		}

		debugOut << "c\n\r";
		led.toggle();
	}

	return 0;
}
