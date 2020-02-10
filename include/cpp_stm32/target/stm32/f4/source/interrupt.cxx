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

#include "cpp_stm32/target/stm32/f4/interrupt.hxx"
#include "cpp_stm32/hal/interrupt.hxx"

namespace cpp_stm32::interrupt {

[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void wwdg() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void pvd() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tamp_stamp() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void rtc_wakeup() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void flash() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void rcc() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti0() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti1() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti2() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti3() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti4() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream0() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream1() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream2() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream3() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream4() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream5() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream6() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void adc() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_tx() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_rx0() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_rx1() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_sce() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti9_5() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_brk_tim9() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_up_tim10() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_trg_com_tim11() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_cc() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim2() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim3() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim4() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c1_ev() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c1_er() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c2_ev() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c2_er() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void spi1() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void spi2() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void usart1() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void usart2() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void usart3() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti5_10() noexcept;

}	 // namespace cpp_stm32::interrupt

namespace cpp_stm32 {

template <IrqNum IRQn>
std::pair<void*, void (*)(void* const) noexcept> Interrupt<IRQn>::m_callback{
	nullptr, &WRAP_TO_C_STYLE_FUNC<interrupt::IRQ_TABLE[to_underlying(IRQn)]>};

}
