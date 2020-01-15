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

#define NVIC_IRQ_NUM 91

namespace cpp_stm32::stm32::f4 {

void wwdg_isr() noexcept;
void pvd_isr() noexcept;
void tamp_stamp_isr() noexcept;
void rtc_wakeup_isr() noexcept;
void flash_isr() noexcept;
void rcc_isr() noexcept;
void exti0_isr() noexcept;
void exti1_isr() noexcept;
void exti2_isr() noexcept;
void exti3_isr() noexcept;
void exti4_isr() noexcept;
void dma1_stream0_isr() noexcept;
void dma1_stream1_isr() noexcept;
void dma1_stream2_isr() noexcept;
void dma1_stream3_isr() noexcept;
void dma1_stream4_isr() noexcept;
void dma1_stream5_isr() noexcept;
void dma1_stream6_isr() noexcept;
void adc_isr() noexcept;
void can1_tx_isr() noexcept;
void can1_rx0_isr() noexcept;
void can1_rx1_isr() noexcept;
void can1_sce_isr() noexcept;
void exti9_5_isr() noexcept;
void tim1_brk_tim9_isr() noexcept;
void tim1_up_tim10_isr() noexcept;
void tim1_trg_com_tim11_isr() noexcept;
void tim1_cc_isr() noexcept;
void tim2_isr() noexcept;
void tim3_isr() noexcept;
void tim4_isr() noexcept;
void i2c1_ev_isr() noexcept;
void i2c1_er_isr() noexcept;
void i2c2_ev_isr() noexcept;
void i2c2_er_isr() noexcept;
void spi1_isr() noexcept;
void spi2_isr() noexcept;
void usart1_isr() noexcept;
void usart2_isr() noexcept;
void usart3_isr() noexcept;
void exti5_10_isr() noexcept;

static constexpr auto IRQ_FUNC_HANDLER = std::array{
	wwdg_isr,					 pvd_isr,						tamp_stamp_isr,
	rtc_wakeup_isr,		 flash_isr,					rcc_isr,
	exti0_isr,				 exti1_isr,					exti2_isr,
	exti3_isr,				 exti4_isr,					dma1_stream0_isr,
	dma1_stream1_isr,	 dma1_stream2_isr,	dma1_stream3_isr,
	dma1_stream4_isr,	 dma1_stream5_isr,	dma1_stream6_isr,
	adc_isr,					 can1_tx_isr,				can1_rx0_isr,
	can1_rx1_isr,			 can1_sce_isr,			exti9_5_isr,
	tim1_brk_tim9_isr, tim1_up_tim10_isr, tim1_trg_com_tim11_isr,
	tim1_cc_isr,			 tim2_isr,					tim3_isr,
	tim4_isr,					 i2c1_ev_isr,				i2c1_er_isr,
	i2c2_ev_isr,			 i2c2_er_isr,				spi1_isr,
	spi2_isr,					 usart1_isr,				usart2_isr,
	usart3_isr,				 exti5_10_isr,
};

}	 // namespace cpp_stm32::stm32::f4

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
