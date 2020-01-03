/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 */

#include "cpp_stm32/target/stm32/f4/sys_init.hxx"

#include "cpp_stm32/driver/digitalout.hxx"
#include "cpp_stm32/driver/usart_serial.hxx"

using namespace cpp_stm32::driver;

struct DebugLogger {
	static inline Usart const debugOut{UsartTx_v<PinName::PA_2>, UsartRx_v<PinName::PA_3>, 115200};

	constexpr DebugLogger() noexcept {
		/**/
		debugOut.setTxeInterrupt(Callback<&DebugLogger::log>(this));
	}

	constexpr void log() noexcept { debugOut << 'c'; }
};

int main() {
	SysClock::init(PllClkSrc<RccOsc::HseOsc>{});

	DebugLogger logger{};
	DigitalOut<PinName::PA_5> led;

	while (true) {
		constexpr auto SOME_PERIOD = 1000000;
		for (int i = 0; i < SOME_PERIOD; ++i) {
			__asm__("nop");
		}

		led.toggle();
	}

	return 0;
}
