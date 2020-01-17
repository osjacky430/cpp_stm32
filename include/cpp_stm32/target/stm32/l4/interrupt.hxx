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

#define NVIC_INTERRUPT                                                                                                \
	Interrupt<IrqNum::WindowWatchDog>::interrupt, Interrupt<IrqNum::ProgVoltDetector>::interrupt,                       \
		Interrupt<IrqNum::RtcTampStamp>::interrupt, Interrupt<IrqNum::RtcWakeUp>::interrupt,                              \
		Interrupt<IrqNum::FlashGlobal>::interrupt, Interrupt<IrqNum::RccGlobal>::interrupt,                               \
		Interrupt<IrqNum::Exti0Global>::interrupt, Interrupt<IrqNum::Exti1Global>::interrupt,                             \
		Interrupt<IrqNum::Exti2Global>::interrupt, Interrupt<IrqNum::Exti3Global>::interrupt,                             \
		Interrupt<IrqNum::Exti4Global>::interrupt, Interrupt<IrqNum::Dma1Channel1Global>::interrupt,                      \
		Interrupt<IrqNum::Dma1Channel2Global>::interrupt, Interrupt<IrqNum::Dma1Channel3Global>::interrupt,               \
		Interrupt<IrqNum::Dma1Channel4Global>::interrupt, Interrupt<IrqNum::Dma1Channel5Global>::interrupt,               \
		Interrupt<IrqNum::Dma1Channel6Global>::interrupt, Interrupt<IrqNum::Dma1Channel7Global>::interrupt,               \
		Interrupt<IrqNum::AdcGlobal>::interrupt, Interrupt<IrqNum::Can1Tx>::interrupt,                                    \
		Interrupt<IrqNum::Can1Rx0>::interrupt, Interrupt<IrqNum::Can1Rx1>::interrupt,                                     \
		Interrupt<IrqNum::Can1Sce>::interrupt, Interrupt<IrqNum::Exti9_5>::interrupt,                                     \
		Interrupt<IrqNum::Tim1BrkTim9Global>::interrupt, Interrupt<IrqNum::Tim1UpTim10Global>::interrupt,                 \
		Interrupt<IrqNum::Tim1TrgComTim11Global>::interrupt, Interrupt<IrqNum::Tim1CC>::interrupt,                        \
		Interrupt<IrqNum::Tim2Global>::interrupt, Interrupt<IrqNum::Tim3Global>::interrupt,                               \
		Interrupt<IrqNum::I2c1Ev>::interrupt, Interrupt<IrqNum::I2c1Er>::interrupt, Interrupt<IrqNum::I2c2Ev>::interrupt, \
		Interrupt<IrqNum::I2c2Er>::interrupt, Interrupt<IrqNum::Spi1Global>::interrupt,                                   \
		Interrupt<IrqNum::Spi2Global>::interrupt, Interrupt<IrqNum::Usart1Global>::interrupt,                             \
		Interrupt<IrqNum::Usart2Global>::interrupt, Interrupt<IrqNum::Usart3Global>::interrupt,                           \
		Interrupt<IrqNum::Exti5_10>::interrupt

#define NVIC_IRQ_NUM 84

#include <cstdint>

#include "cpp_stm32/hal/callback.hxx"
#include "cpp_stm32/hal/interrupt.hxx"
#include "cpp_stm32/utility/utility.hxx"

namespace cpp_stm32 {

enum class IrqNum : std::uint8_t {
	WindowWatchDog,
	ProgVoltDetector,	 // PVD_PVM
	RtcTampStamp,			 // RTC_TAMP_STAMP / CSS_LSE
	RtcWakeUp,
	FlashGlobal,
	RccGlobal,
	Exti0Global,
	Exti1Global,
	Exti2Global,
	Exti3Global,
	Exti4Global,
	Dma1Channel1Global,
	Dma1Channel2Global,
	Dma1Channel3Global,
	Dma1Channel4Global,
	Dma1Channel5Global,
	Dma1Channel6Global,
	Dma1Channel7Global,
	AdcGlobal,	// ADC1_2
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
	/* 30 reserved */
	I2c1Ev = 31,
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

}

namespace cpp_stm32::interrupt {

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
void dma1_channel1_isr() noexcept;
void dma1_channel2_isr() noexcept;
void dma1_channel3_isr() noexcept;
void dma1_channel4_isr() noexcept;
void dma1_channel5_isr() noexcept;
void dma1_channel6_isr() noexcept;
void dma1_channel7_isr() noexcept;
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

static constexpr auto IRQ_TABLE = []() {
	using irq_func_ptr = void (*)() noexcept;
	std::array<irq_func_ptr, to_underlying(IrqNum::NvicIrqTotal)> func_ptr_holder{};

	func_ptr_holder[to_underlying(IrqNum::WindowWatchDog)]				= wwdg_isr;
	func_ptr_holder[to_underlying(IrqNum::ProgVoltDetector)]			= pvd_isr;
	func_ptr_holder[to_underlying(IrqNum::RtcTampStamp)]					= tamp_stamp_isr;
	func_ptr_holder[to_underlying(IrqNum::RtcWakeUp)]							= rtc_wakeup_isr;
	func_ptr_holder[to_underlying(IrqNum::FlashGlobal)]						= flash_isr;
	func_ptr_holder[to_underlying(IrqNum::RccGlobal)]							= rcc_isr;
	func_ptr_holder[to_underlying(IrqNum::Exti0Global)]						= exti0_isr;
	func_ptr_holder[to_underlying(IrqNum::Exti1Global)]						= exti1_isr;
	func_ptr_holder[to_underlying(IrqNum::Exti2Global)]						= exti2_isr;
	func_ptr_holder[to_underlying(IrqNum::Exti3Global)]						= exti3_isr;
	func_ptr_holder[to_underlying(IrqNum::Exti4Global)]						= exti4_isr;
	func_ptr_holder[to_underlying(IrqNum::Dma1Channel1Global)]		= dma1_channel1_isr;
	func_ptr_holder[to_underlying(IrqNum::Dma1Channel2Global)]		= dma1_channel2_isr;
	func_ptr_holder[to_underlying(IrqNum::Dma1Channel3Global)]		= dma1_channel3_isr;
	func_ptr_holder[to_underlying(IrqNum::Dma1Channel4Global)]		= dma1_channel4_isr;
	func_ptr_holder[to_underlying(IrqNum::Dma1Channel5Global)]		= dma1_channel5_isr;
	func_ptr_holder[to_underlying(IrqNum::Dma1Channel6Global)]		= dma1_channel6_isr;
	func_ptr_holder[to_underlying(IrqNum::Dma1Channel7Global)]		= dma1_channel7_isr;
	func_ptr_holder[to_underlying(IrqNum::AdcGlobal)]							= adc_isr;
	func_ptr_holder[to_underlying(IrqNum::Can1Tx)]								= can1_tx_isr;
	func_ptr_holder[to_underlying(IrqNum::Can1Rx0)]								= can1_rx0_isr;
	func_ptr_holder[to_underlying(IrqNum::Can1Rx1)]								= can1_rx1_isr;
	func_ptr_holder[to_underlying(IrqNum::Can1Sce)]								= can1_sce_isr;
	func_ptr_holder[to_underlying(IrqNum::Exti9_5)]								= exti9_5_isr;
	func_ptr_holder[to_underlying(IrqNum::Tim1BrkTim9Global)]			= tim1_brk_tim9_isr;
	func_ptr_holder[to_underlying(IrqNum::Tim1UpTim10Global)]			= tim1_up_tim10_isr;
	func_ptr_holder[to_underlying(IrqNum::Tim1TrgComTim11Global)] = tim1_trg_com_tim11_isr;
	func_ptr_holder[to_underlying(IrqNum::Tim1CC)]								= tim1_cc_isr;
	func_ptr_holder[to_underlying(IrqNum::Tim2Global)]						= tim2_isr;
	func_ptr_holder[to_underlying(IrqNum::Tim3Global)]						= tim3_isr;
	func_ptr_holder[to_underlying(IrqNum::I2c1Ev)]								= i2c1_ev_isr;
	func_ptr_holder[to_underlying(IrqNum::I2c1Er)]								= i2c1_er_isr;
	func_ptr_holder[to_underlying(IrqNum::I2c2Ev)]								= i2c2_ev_isr;
	func_ptr_holder[to_underlying(IrqNum::I2c2Er)]								= i2c2_er_isr;
	func_ptr_holder[to_underlying(IrqNum::Spi1Global)]						= spi1_isr;
	func_ptr_holder[to_underlying(IrqNum::Spi2Global)]						= spi2_isr;
	func_ptr_holder[to_underlying(IrqNum::Usart1Global)]					= usart1_isr;
	func_ptr_holder[to_underlying(IrqNum::Usart2Global)]					= usart2_isr;
	func_ptr_holder[to_underlying(IrqNum::Usart3Global)]					= usart3_isr;
	func_ptr_holder[to_underlying(IrqNum::Exti5_10)]							= exti5_10_isr;

	return func_ptr_holder;
}();

}	 // namespace cpp_stm32::interrupt
