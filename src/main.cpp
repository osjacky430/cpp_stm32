/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 */

// #include "sys_init.hxx"

// #include "cpp_stm32/driver/digitalout.hxx"
// #include "cpp_stm32/driver/usart_serial.hxx"
#include "cpp_stm32/target/stm32/f4/usart.hxx"

using namespace cpp_stm32;
// using namespace driver;
// using namespace gpio;
using namespace usart;

int main() {
	// sys::Clock::init<rcc::ClkSrc::Hse>();

	// usart::reg::CR1<usart::Port::Usart2>.setBit<usart::reg::Cr1Bit::TCIE, usart::reg::Cr1Bit::RE>(
	// 	BitGroup{std::uint8_t(1), std::uint8_t(1)},
	// 	usart::reg::CR1<usart::Port::Usart2>.isolateFrom<usart::reg::Cr1Bit::RWu>());
	usart::set_dps<usart::Port::Usart2>(DataBit::DataBit8, Parity::None, StopBit_v<Stopbit::Bit1>);
	// usart::set_baudrate<usart::Port::Usart2>(9600_Baud);
	// Usart const debugOut{UsartTx_v<PinName::PA_2>, UsartRx_v<PinName::PA_3>, 115200_Baud};
	// DigitalOut<PinName::PA_5> led;
	//
	while (true) {
		constexpr auto SOME_PERIOD = 1000000;
		for (int i = 0; i < SOME_PERIOD; ++i) {
			__asm__("nop");
		}

		// debugOut << "c\n\r";
		// led.toggle();
	}

	return 0;
}
