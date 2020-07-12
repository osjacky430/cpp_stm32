#include "test_setup.hxx"

#include "cpp_stm32/driver/digitalout.hxx"
#include "cpp_stm32/driver/usart_serial.hxx"

#include "gpio.hxx"
#include "rcc.hxx"
#include "sys_init.hxx"

namespace Rcc		 = cpp_stm32::rcc;
namespace Gpio	 = cpp_stm32::gpio;
namespace Sys		 = cpp_stm32::sys;
namespace Usart	= cpp_stm32::usart;
namespace Driver = cpp_stm32::driver;

using Usart::operator"" _Baud;

void* __dso_handle = (void*)&__dso_handle;

Driver::Usart const pc{Driver::UsartTx_v<Gpio::PinName::PA_2>, Driver::UsartRx_v<Gpio::PinName::PA_3>, 115200_Baud};

// this function can be implemented using SPI, CAN instead of USART
void OutBuff::put_str(const char* t_str, std::streamsize t_n) noexcept {
	for (int i = 0; i < t_n; ++i) {
		if (char c = t_str[i]; c == '\n') {
			pc << c << '\r';
		} else {
			pc << c;
		}
	}
}

int main() {
	Sys::Clock::init<Rcc::ClkSrc::Hse>();

	pc << "test start: \n\r";

	Driver::DigitalOut<Gpio::PinName::PA_5> const led;
	Catch::Session().run();

	pc << "test end\n\n\r";

	while (true) {
		for (int i = 0; i < 10000000; ++i) {
			__asm("nop");
		}

		led.toggle();
	}

	return 0;
}
