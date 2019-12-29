/**
 * @Date:   2019-12-30T01:21:03+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: interrupt.cxx
 */

#include "include/hal/interrupt.hxx"

[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void wwdg_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void pvd_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tamp_stamp_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void rtc_wakeup_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void flash_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void rcc_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti0_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti1_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti2_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti3_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti4_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream0_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream1_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream2_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream3_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream4_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream5_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void dma1_stream6_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void adc_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_tx_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_rx0_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_rx1_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void can1_sce_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti9_5_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_brk_tim9_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_up_tim10_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_trg_com_tim11_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim1_cc_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim2_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim3_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void tim4_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c1_ev_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c1_er_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c2_ev_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void i2c2_er_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void spi1_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void spi2_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void usart1_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void usart2_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void usart3_isr();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void exti5_10_isr();
