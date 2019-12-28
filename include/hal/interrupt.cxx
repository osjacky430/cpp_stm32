/**
 * @Date:   2019-12-28T00:20:49+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: interrupt.cxx
 */
#include "include/hal/interrupt.hxx"
#include "include/hal/cortex_m_vector.cpp"

[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void wwdg_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void pvd_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void tamp_stamp_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void rtc_wakeup_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void flash_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void rcc_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void exti0_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void exti1_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void exti2_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void exti3_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void exti4_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void dma1_stream0_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void dma1_stream1_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void dma1_stream2_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void dma1_stream3_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void dma1_stream4_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void dma1_stream5_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void dma1_stream6_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void adc_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void can1_tx_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void can1_rx0_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void can1_rx1_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void can1_sce_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void exti9_5_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void tim1_brk_tim9_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void tim1_up_tim10_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void tim1_trg_com_tim11_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void tim1_cc_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void tim2_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void tim3_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void tim4_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void i2c1_ev_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void i2c1_er_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void i2c2_ev_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void i2c2_er_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void spi1_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void spi2_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void usart1_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void usart2_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void usart3_isr();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void exti5_10_isr();

// void wwdg_isr(){};
// void pvd_isr(){};
// void tamp_stamp_isr(){};
// void rtc_wakeup_isr(){};
// void flash_isr(){};
// void rcc_isr(){};
// void exti0_isr(){};
// void exti1_isr(){};
// void exti2_isr(){};
// void exti3_isr(){};
// void exti4_isr(){};
// void dma1_stream0_isr(){};
// void dma1_stream1_isr(){};
// void dma1_stream2_isr(){};
// void dma1_stream3_isr(){};
// void dma1_stream4_isr(){};
// void dma1_stream5_isr(){};
// void dma1_stream6_isr(){};
// void adc_isr(){};
// void can1_tx_isr(){};
// void can1_rx0_isr(){};
// void can1_rx1_isr(){};
// void can1_sce_isr(){};
// void exti9_5_isr(){};
// void tim1_brk_tim9_isr(){};
// void tim1_up_tim10_isr(){};
// void tim1_trg_com_tim11_isr(){};
// void tim1_cc_isr(){};
// void tim2_isr(){};
// void tim3_isr(){};
// void tim4_isr(){};
// void i2c1_ev_isr(){};
// void i2c1_er_isr(){};
// void i2c2_ev_isr(){};
// void i2c2_er_isr(){};
// void spi1_isr(){};
// void spi2_isr(){};
// void usart1_isr(){};
// void usart2_isr(){};
// void usart3_isr(){};
// void exti5_10_isr(){};
