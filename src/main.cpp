/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 */

#include "include/driver/digitalout.hpp"
#include "include/hal/nvic.hpp"

#include "include/hal/peripheral/rcc.hxx"
#include "include/hal/peripheral/usart.hxx"

#include "include/hal/sys_init.hxx"

constexpr void setup_usart() noexcept {
	rcc_enable_periph_clk<RccPeriph::GpioA>();
	rcc_enable_periph_clk<RccPeriph::Usart2>();

	gpio_mode_setup<GpioPort::PortA, GpioPin::Pin2, GpioPin::Pin3>(GpioMode::AltFunc, GpioPupd::None);
	gpio_set_af<GpioPort::PortA, GpioPin::Pin2, GpioPin::Pin3>(GpioAltFunc::AF7);

	usart_set_baudrate<UsartNum::Usart2>(115200);

	usart_set_databit<UsartNum::Usart2>(DataBit::DataBit8);
	usart_set_parity<UsartNum::Usart2>(UsartParity::None);
	usart_set_stopbit<UsartNum::Usart2>(StopBit_v<UsartStopbit::Bit1>);

	usart_set_transfer_mode<UsartNum::Usart2>(UsartMode::TxRx);
	usart_set_hardware_flow_ctl<UsartNum::Usart2>(HardwareFlowControl::None);

	usart_enable<UsartNum::Usart2>();
}

int main() {
	SysClock::init(PllClkSrc<RccOsc::HseOsc>{});

	setup_usart();
	DigitalOut<PinName::PA_5> led;

	while (true) {
		constexpr auto SOME_PERIOD = 1000000;
		for (int i = 0; i < SOME_PERIOD; ++i) {
			__asm__("nop");
		}

		led.toggle();

		usart_send_blocking<UsartNum::Usart2>('2');
		usart_send_blocking<UsartNum::Usart2>('\n');
		usart_send_blocking<UsartNum::Usart2>('\r');
	}

	return 0;
}
