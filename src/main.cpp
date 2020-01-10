/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 */

// #include "cpp_stm32/target/stm32/f4/sys_init.hxx"

// #include "gpio.hxx"
// #include "rcc.hxx"
#include "cpp_stm32/driver/digitalout.hxx"
// #include "cpp_stm32/driver/usart_serial.hxx"

using namespace cpp_stm32::driver;
using namespace Manufacture;
// using namespace cpp_stm32::common;
// using namespace cpp_stm32::stm32::l4;

// struct DebugLogger {
// 	static inline Usart const debugOut{UsartTx_v<PinName::PA_2>, UsartRx_v<PinName::PA_3>, 115200_Baud};
//
// 	constexpr DebugLogger() noexcept {
// 		/**/
// 		debugOut.setTxeInterrupt(Callback<&DebugLogger::log>(this));
// 	}
//
// 	constexpr void log() noexcept { debugOut << 'c'; }
// };

int main() {
	// rcc_enable_periph_clk<RccPeriph::GpioB>();
	// SysClock::init(PllClkSrc<RccOsc::HseOsc>{});
	// gpio_mode_setup<GpioPort::PortB, GpioPin::Pin3>(GpioMode::Output, GpioPupd::None);
	// DebugLogger logger{};
	DigitalOut<PinName::PB_3> led;

	while (true) {
		constexpr auto SOME_PERIOD = 1000000;
		for (int i = 0; i < SOME_PERIOD; ++i) {
			__asm__("nop");
		}

		// gpio_toggle<GpioPort::PortB, GpioPin::Pin3>();
		led.toggle();
	}

	return 0;
}
