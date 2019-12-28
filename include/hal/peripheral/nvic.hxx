/**
 * @Date:   2019-12-27T02:22:23+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: nvic.hxx
 */

#pragma once

#include "include/hal/memory_map.hxx"
#include "include/hal/peripheral/memory/nvic_reg.hxx"
#include "include/hal/utility.hxx"

// @todo : collect all enum class to one enum class
template <IrqNum IRQn>
constexpr void nvic_enable_irq() noexcept {
	NVIC_ISER<IRQn>.template setBit<NVIC_IRQ_BIT_POS(IRQn)>();
}

template <IrqNum IRQn>
constexpr void nvic_disable_irq() noexcept {
	NVIC_ICER<IRQn>.template setBit<NVIC_IRQ_BIT_POS(IRQn)>();
}

template <IrqNum IRQn>
constexpr auto nvic_is_irq_pending() noexcept {
	return NVIC_ISPR<IRQn>.template readBit<NVIC_IRQ_BIT_POS(IRQn)>(ValueOnly);
}

template <IrqNum IRQn>
constexpr void nvic_set_irq_pending() noexcept {
	NVIC_ISPR<IRQn>.template setBit<NVIC_IRQ_BIT_POS(IRQn)>();
}

template <IrqNum IRQn>
constexpr void nvic_clear_pending_irq() noexcept {
	NVIC_ICPR<IRQn>.template setBit<NVIC_IRQ_BIT_POS(IRQn)>();
}

template <IrqNum IRQn>
constexpr auto nvic_is_irq_active() noexcept {
	return NVIC_IABR<IRQn>.template readBit<NVIC_IRQ_BIT_POS(IRQn)>(ValueOnly);
}

template <IrqNum IRQn>
constexpr void nvic_gen_software_interrupt() noexcept {
	NVIC_STIR.setBit<NvicStirBit::IntId>(to_underlying(IRQn));
}

template <IrqNum IRQn>
constexpr void nvic_set_irq_priority(std::uint8_t const& t_priority) noexcept {
	if constexpr (to_underlying(IRQn) <= 0) {
	} else {
		NVIC_IPR<IRQn>.setBit<NvicIprBit::Ip>(t_priority);
	}
}
