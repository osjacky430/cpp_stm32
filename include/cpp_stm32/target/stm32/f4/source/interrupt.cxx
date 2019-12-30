/**
 * @Date:   2019-12-30T01:21:03+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: interrupt.cxx
 */

#include "cpp_stm32/target/stm32/f4/interrupt.hxx"
#include "cpp_stm32/utility/interrupt.hxx"

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
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream0_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream1_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream2_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream3_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream4_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream5_isr() noexcept;
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream6_isr() noexcept;
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
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim4_isr() noexcept;
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

template <IrqNum IRQn>
std::pair<void*, void (*)(void* const) noexcept> Interrupt<IRQn>::m_callback{
	nullptr, &WRAP_TO_C_STYLE_FUNC<IRQ_FUNC_HANDLER[to_underlying(IRQn)]>};
