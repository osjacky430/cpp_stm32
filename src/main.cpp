/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 */

#include "sys_init.hxx"

#include "cpp_stm32/driver/digitalout.hxx"
#include "cpp_stm32/driver/usart_serial.hxx"

#include "cpp_stm32/target/stm32/f4/dma.hxx"

using namespace cpp_stm32;
using namespace driver;
using namespace gpio;
using namespace usart;

char array[20];
Usart const pc{UsartTx_v<PinName::PA_2>, UsartRx_v<PinName::PA_3>, 115200_Baud};

constexpr void setup_dma() noexcept {
	using namespace dma;
	constexpr auto p_addr = usart::reg::DR<usart::Port::Usart2>.memoryAddr();
	constexpr auto m_addr = &array[0];

	rcc::enable_periph_clk<rcc::PeriphClk::Dma1>();
	nvic::enable_irq<IrqNum::Dma1Stream5Global>();

	DmaBuilder<dma::Port::DMA1, dma::Stream::Stream5>()
		.transferDir(PeriphAddress_t{p_addr}, MemoryAddress_t{(std::uintptr_t)m_addr})
		.txDataNum(5)
		.selectChannel(dma::Channel::Channel4)
		.streamPriority(dma::StreamPriority::VeryHigh)
		.memoryDataWidth(DataSize::Byte)
		.memoryIncrementMode(true)
		.circularMode(true)
		.perihperalDataWidth(DataSize::Byte)
		.enableInterrupt<dma::InterruptFlag::TCI>()
		.build();

	usart::enable_rx_dma<usart::Port::Usart2>();
}

DigitalOut<PinName::PA_5> led;

int main() {
	sys::Clock::init<rcc::ClkSrc::Hse>();

	setup_dma();

	while (true) {
		constexpr auto SOME_INTERVAL = 10000000;
		for (int i = 0; i < SOME_INTERVAL; ++i) {
			__asm("nop");
		}

		pc << array << "\n\r";
	}

	return 0;
}

void interrupt::dma1_stream5_isr() noexcept {
	auto const dma_state = dma::DmaStateManager<dma::Port::DMA1, dma::Stream::Stream5, dma::InterruptFlag::TCI>();
	led.toggle();
}
