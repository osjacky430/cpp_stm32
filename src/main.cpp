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

auto array = std::array<std::uint8_t, 20>{};

constexpr void setup_dma() noexcept {
	using namespace dma;
	constexpr auto p_addr = usart::reg::DR<usart::Port::Usart2>.memoryAddr();
	constexpr auto m_addr = &array[0];

	rcc::enable_periph_clk<rcc::PeriphClk::Dma1>();

	DmaBuilder<dma::Port::DMA1, dma::Stream::Stream5>()
		.transferDir(PeriphAddress_t{p_addr}, MemoryAddress_t{(std::uintptr_t)m_addr})
		.txDataNum(1)
		.selectChannel(dma::Channel::Channel4)
		.streamPriority(dma::StreamPriority::Low)
		.memoryDataWidth(DataSize::Byte)
		.circularMode(true)
		.perihperalDataWidth(DataSize::Byte)
		.build();

	usart::enable_rx_dma<usart::Port::Usart2>();
}

int main() {
	sys::Clock::init<rcc::ClkSrc::Hse>();

	Usart const pc{UsartTx_v<PinName::PA_2>, UsartRx_v<PinName::PA_3>, 115200_Baud};
	DigitalOut<PinName::PA_5> led;

	setup_dma();

	while (true) {
		led.toggle();

		while (!dma::get_tx_complete_flag<dma::Port::DMA1, dma::Stream::Stream5>()) {
		}
		//
		dma::clear_tx_complete_flag<dma::Port::DMA1, dma::Stream::Stream5>();
		// auto const [user_input, nl] = pc.receive(2_byte, Waiting<true>);
		pc << array[0] << "\n\r";
	}

	return 0;
}
