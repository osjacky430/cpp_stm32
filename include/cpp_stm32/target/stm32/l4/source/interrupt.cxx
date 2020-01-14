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

#include "cpp_stm32/target/stm32/l4/interrupt.hxx"
#include "cpp_stm32/utility/interrupt.hxx"

namespace cpp_stm32::stm32::l4 {

[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void wwdg_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void pvd_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tamp_stamp_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void rtc_wakeup_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void flash_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void rcc_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti0_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti1_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti2_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti3_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti4_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_channel1_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_channel2_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_channel3_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_channel4_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_channel5_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_channel6_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_channel7_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void adc_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_tx_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_rx0_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_rx1_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_sce_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti9_5_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_brk_tim9_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_up_tim10_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_trg_com_tim11_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_cc_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim2_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim3_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c1_ev_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c1_er_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c2_ev_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c2_er_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void spi1_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void spi2_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void usart1_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void usart2_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void usart3_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti5_10_isr() noexcept;

}	 // namespace cpp_stm32::stm32::l4

namespace cpp_stm32 {

template <IrqNum IRQn>
std::pair<void*, void (*)(void* const) noexcept> Interrupt<IRQn>::m_callback{
	nullptr, &WRAP_TO_C_STYLE_FUNC<stm32::l4::IRQ_FUNC_HANDLER[to_underlying(IRQn)]>};

}
