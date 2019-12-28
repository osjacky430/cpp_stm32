/**
 * @Date:   2019-12-26T23:35:54+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: interrupt.hxx
 */

#pragma once

#define NVIC_INTERRUPT                                                                                               \
	wwdg_isr, pvd_isr, tamp_stamp_isr, rtc_wakeup_isr, flash_isr, rcc_isr, exti0_isr, exti1_isr, exti2_isr, exti3_isr, \
		exti4_isr, dma1_stream0_isr, dma1_stream1_isr, dma1_stream2_isr, dma1_stream3_isr, dma1_stream4_isr,             \
		dma1_stream5_isr, dma1_stream6_isr, adc_isr, can1_tx_isr, can1_rx0_isr, can1_rx1_isr, can1_sce_isr, exti9_5_isr, \
		tim1_brk_tim9_isr, tim1_up_tim10_isr, tim1_trg_com_tim11_isr, tim1_cc_isr, tim2_isr, tim3_isr, tim4_isr,         \
		i2c1_ev_isr, i2c1_er_isr, i2c2_ev_isr, i2c2_er_isr, spi1_isr, spi2_isr, usart1_isr, usart2_isr, usart3_isr,      \
		exti5_10_isr

// class Interrupt {};
void wwdg_isr();
void pvd_isr();
void tamp_stamp_isr();
void rtc_wakeup_isr();
void flash_isr();
void rcc_isr();
void exti0_isr();
void exti1_isr();
void exti2_isr();
void exti3_isr();
void exti4_isr();
void dma1_stream0_isr();
void dma1_stream1_isr();
void dma1_stream2_isr();
void dma1_stream3_isr();
void dma1_stream4_isr();
void dma1_stream5_isr();
void dma1_stream6_isr();
void adc_isr();
void can1_tx_isr();
void can1_rx0_isr();
void can1_rx1_isr();
void can1_sce_isr();
void exti9_5_isr();
void tim1_brk_tim9_isr();
void tim1_up_tim10_isr();
void tim1_trg_com_tim11_isr();
void tim1_cc_isr();
void tim2_isr();
void tim3_isr();
void tim4_isr();
void i2c1_ev_isr();
void i2c1_er_isr();
void i2c2_ev_isr();
void i2c2_er_isr();
void spi1_isr();
void spi2_isr();
void usart1_isr();
void usart2_isr();
void usart3_isr();
void exti5_10_isr();
