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

constexpr auto NVIC_IRQ_NUM = 96;

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
	Exti10_15,
	NvicIrqTotal
};

}	 // namespace cpp_stm32
