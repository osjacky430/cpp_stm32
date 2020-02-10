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

#pragma once

#include <array>
#include <tuple>

#include "cpp_stm32/hal/callback.hxx"
#include "cpp_stm32/hal/interrupt.hxx"
#include "cpp_stm32/utility/utility.hxx"

#define NVIC_INTERRUPT                                                                                                \
	Interrupt<IrqNum::WindowWatchDog>::interrupt, Interrupt<IrqNum::ProgVoltDetector>::interrupt,                       \
		Interrupt<IrqNum::TampStamp>::interrupt, Interrupt<IrqNum::RtcWakeUp>::interrupt,                                 \
		Interrupt<IrqNum::FlashGlobal>::interrupt, Interrupt<IrqNum::RccGlobal>::interrupt,                               \
		Interrupt<IrqNum::Exti0Global>::interrupt, Interrupt<IrqNum::Exti1Global>::interrupt,                             \
		Interrupt<IrqNum::Exti2Global>::interrupt, Interrupt<IrqNum::Exti3Global>::interrupt,                             \
		Interrupt<IrqNum::Exti4Global>::interrupt, Interrupt<IrqNum::Dma1Stream0Global>::interrupt,                       \
		Interrupt<IrqNum::Dma1Stream1Global>::interrupt, Interrupt<IrqNum::Dma1Stream2Global>::interrupt,                 \
		Interrupt<IrqNum::Dma1Stream3Global>::interrupt, Interrupt<IrqNum::Dma1Stream4Global>::interrupt,                 \
		Interrupt<IrqNum::Dma1Stream5Global>::interrupt, Interrupt<IrqNum::Dma1Stream6Global>::interrupt,                 \
		Interrupt<IrqNum::AdcGlobal>::interrupt, Interrupt<IrqNum::Can1Tx>::interrupt,                                    \
		Interrupt<IrqNum::Can1Rx0>::interrupt, Interrupt<IrqNum::Can1Rx1>::interrupt,                                     \
		Interrupt<IrqNum::Can1Sce>::interrupt, Interrupt<IrqNum::Exti9_5>::interrupt,                                     \
		Interrupt<IrqNum::Tim1BrkTim9Global>::interrupt, Interrupt<IrqNum::Tim1UpTim10Global>::interrupt,                 \
		Interrupt<IrqNum::Tim1TrgComTim11Global>::interrupt, Interrupt<IrqNum::Tim1CC>::interrupt,                        \
		Interrupt<IrqNum::Tim2Global>::interrupt, Interrupt<IrqNum::Tim3Global>::interrupt,                               \
		Interrupt<IrqNum::Tim4Global>::interrupt, Interrupt<IrqNum::I2c1Ev>::interrupt,                                   \
		Interrupt<IrqNum::I2c1Er>::interrupt, Interrupt<IrqNum::I2c2Ev>::interrupt, Interrupt<IrqNum::I2c2Er>::interrupt, \
		Interrupt<IrqNum::Spi1Global>::interrupt, Interrupt<IrqNum::Spi2Global>::interrupt,                               \
		Interrupt<IrqNum::Usart1Global>::interrupt, Interrupt<IrqNum::Usart2Global>::interrupt,                           \
		Interrupt<IrqNum::Usart3Global>::interrupt, Interrupt<IrqNum::Exti5_10>::interrupt

#define NVIC_IRQ_NUM 96

namespace cpp_stm32::interrupt {

void wwdg() noexcept;
void pvd() noexcept;
void tamp_stamp() noexcept;
void rtc_wakeup() noexcept;
void flash() noexcept;
void rcc() noexcept;
void exti0() noexcept;
void exti1() noexcept;
void exti2() noexcept;
void exti3() noexcept;
void exti4() noexcept;
void dma1_stream0() noexcept;
void dma1_stream1() noexcept;
void dma1_stream2() noexcept;
void dma1_stream3() noexcept;
void dma1_stream4() noexcept;
void dma1_stream5() noexcept;
void dma1_stream6() noexcept;
void adc() noexcept;
void can1_tx() noexcept;
void can1_rx0() noexcept;
void can1_rx1() noexcept;
void can1_sce() noexcept;
void exti9_5() noexcept;
void tim1_brk_tim9() noexcept;
void tim1_up_tim10() noexcept;
void tim1_trg_com_tim11() noexcept;
void tim1_cc() noexcept;
void tim2() noexcept;
void tim3() noexcept;
void tim4() noexcept;
void i2c1_ev() noexcept;
void i2c1_er() noexcept;
void i2c2_ev() noexcept;
void i2c2_er() noexcept;
void spi1() noexcept;
void spi2() noexcept;
void usart1() noexcept;
void usart2() noexcept;
void usart3() noexcept;
void exti5_10() noexcept;

static constexpr auto IRQ_TABLE = std::array{
	wwdg,					 pvd,						tamp_stamp,
	rtc_wakeup,		 flash,					rcc,
	exti0,				 exti1,					exti2,
	exti3,				 exti4,					dma1_stream0,
	dma1_stream1,	 dma1_stream2,	dma1_stream3,
	dma1_stream4,	 dma1_stream5,	dma1_stream6,
	adc,					 can1_tx,				can1_rx0,
	can1_rx1,			 can1_sce,			exti9_5,
	tim1_brk_tim9, tim1_up_tim10, tim1_trg_com_tim11,
	tim1_cc,			 tim2,					tim3,
	tim4,					 i2c1_ev,				i2c1_er,
	i2c2_ev,			 i2c2_er,				spi1,
	spi2,					 usart1,				usart2,
	usart3,				 exti5_10,
};

}	 // namespace cpp_stm32::interrupt

namespace cpp_stm32 {

enum class IrqNum : std::uint8_t {
	WindowWatchDog = 0,
	ProgVoltDetector,
	TampStamp,
	RtcWakeUp,
	FlashGlobal,
	RccGlobal,
	Exti0Global,
	Exti1Global,
	Exti2Global,
	Exti3Global,
	Exti4Global,
	Dma1Stream0Global,
	Dma1Stream1Global,
	Dma1Stream2Global,
	Dma1Stream3Global,
	Dma1Stream4Global,
	Dma1Stream5Global,
	Dma1Stream6Global,
	AdcGlobal,
	Can1Tx,
	Can1Rx0,
	Can1Rx1,
	Can1Sce,
	Exti9_5,
	Tim1BrkTim9Global,
	Tim1UpTim10Global,
	Tim1TrgComTim11Global,
	Tim1CC,
	Tim2Global,
	Tim3Global,
	Tim4Global,
	I2c1Ev,
	I2c1Er,
	I2c2Ev,
	I2c2Er,
	Spi1Global,
	Spi2Global,
	Usart1Global,
	Usart2Global,
	Usart3Global,
	Exti5_10,
	NvicIrqTotal
};

}	 // namespace cpp_stm32
