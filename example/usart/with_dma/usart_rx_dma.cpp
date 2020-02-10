// Copyright (c) 2020 by osjacky430.
// All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the Lesser GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// Lesser GNU General Public License for more details.
//
// You should have received a copy of the Lesser GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "sys_init.hxx"

#include "cpp_stm32/driver/digitalout.hxx"
#include "cpp_stm32/driver/usart_serial.hxx"

#include "cpp_stm32/target/stm32/f4/dma.hxx"

namespace Driver = cpp_stm32::driver;
namespace Gpio	 = cpp_stm32::gpio;
namespace Usart	 = cpp_stm32::usart;
namespace Rcc		 = cpp_stm32::rcc;
namespace Dma		 = cpp_stm32::dma;
namespace Nvic	 = cpp_stm32::nvic;
namespace Sys		 = cpp_stm32::sys;

using Usart::operator"" _Baud;

/* Global Storage for DMA destination */
char array[20];

/* Input from PC */
Driver::Usart const pc{Driver::UsartTx_v<Gpio::PinName::PA_2>, Driver::UsartRx_v<Gpio::PinName::PA_3>, 115200_Baud};

/* For indication, whether interrupt is entered or not */
Driver::DigitalOut<Gpio::PinName::PA_5> led;

constexpr void setup_dma() noexcept {
	constexpr auto p_addr = Usart::reg::DR<Usart::Port::Usart2>.memoryAddr();
	constexpr auto m_addr = &array[0];

	constexpr auto DMA = Dma::Port::DMA1;
	constexpr auto Str = Dma::Stream::Stream5;

	Rcc::enable_periph_clk<Rcc::PeriphClk::Dma1>();
	Nvic::enable_irq<cpp_stm32::IrqNum::Dma1Stream5Global>();

	// reset<DMA, Str>();
	// set_tx_mode<DMA, Str>(TransferDir::PeriphToMem);
	// set_tx_data_num<DMA, Str>(5);
	// channel_select<DMA, Str>(Channel::Channel4);
	// set_memory_data_size<DMA, Str>(DataSize::Byte);
	// set_periph_data_size<DMA, Str>(DataSize::Byte);
	// enable_mem_increment<DMA, Str>();
	// enable_circular_mode<DMA, Str>();
	// set_address<DMA, Str>(MemoryAddress_t{(std::uintptr_t)m_addr});
	// set_address<DMA, Str>(PeriphAddress_t{p_addr});
	// set_priority<DMA, Str>(StreamPriority::Low);
	// enable_irq<DMA, Str, InterruptFlag::TCI>();
	// enable<DMA, Str>();

	Dma::DmaBuilder<DMA, Str>()
		.transferDir(Dma::PeriphAddress_t{p_addr}, Dma::MemoryAddress_t{(std::uintptr_t)m_addr})
		.txDataNum(5)
		.selectChannel(Dma::Channel::Channel4)
		.streamPriority(Dma::StreamPriority::VeryHigh)
		.memoryDataWidth(Dma::DataSize::Byte)
		.enableMemIncrement()
		.useCircularMode()
		.perihperalDataWidth(Dma::DataSize::Byte)
		.enableInterrupt<Dma::InterruptFlag::TCI>()
		.build();

	Usart::enable_rx_dma<Usart::Port::Usart2>();
}

int main() {
	Sys::Clock::init<Rcc::ClkSrc::Hse>();

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

void cpp_stm32::interrupt::dma1_stream5() noexcept {
	if (Dma::get_tx_complete_flag<Dma::Port::DMA1, Dma::Stream::Stream5>()) {
		Dma::clear_tx_complete_flag<Dma::Port::DMA1, Dma::Stream::Stream5>();

		led.toggle();
	}
}
