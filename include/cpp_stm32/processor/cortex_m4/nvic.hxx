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

#include "cpp_stm32/hal/callback.hxx"
#include "cpp_stm32/hal/interrupt.hxx"

#include "cpp_stm32/processor/cortex_m4/core_util.hxx"
#include "cpp_stm32/processor/cortex_m4/memory/internal_periph.hxx"
#include "cpp_stm32/processor/cortex_m4/memory/nvic_reg.hxx"

namespace cpp_stm32::nvic {

template <IrqNum IRQn, auto F>
constexpr void enable_irq(Callback<F> const& t_cb) noexcept {
	reg::NVIC_ISER<IRQn>.template setBit<reg::NVIC_IRQ_BIT_POS(IRQn)>();

	{
		auto const critical_sec = create_critical_section();
		Interrupt<IRQn>::attach(t_cb);
	}	 // end critical section
}

template <IrqNum IRQn>
[[nodiscard]] constexpr bool is_irq_enabled() noexcept {
	return std::get<0>(reg::NVIC_ISER<IRQn>.template readBit<reg::NVIC_IRQ_BIT_POS(IRQn)>(ValueOnly));
}

template <IrqNum IRQn>
constexpr void disable_irq() noexcept {
	reg::NVIC_ICER<IRQn>.template setBit<reg::NVIC_IRQ_BIT_POS(IRQn)>();
}

template <IrqNum IRQn>
constexpr auto is_irq_pending() noexcept {
	return reg::NVIC_ISPR<IRQn>.template readBit<reg::NVIC_IRQ_BIT_POS(IRQn)>(ValueOnly);
}

template <IrqNum IRQn>
constexpr void set_irq_pending() noexcept {
	reg::NVIC_ISPR<IRQn>.template setBit<reg::NVIC_IRQ_BIT_POS(IRQn)>();
}

template <IrqNum IRQn>
constexpr void clear_pending_irq() noexcept {
	reg::NVIC_ICPR<IRQn>.template setBit<reg::NVIC_IRQ_BIT_POS(IRQn)>();
}

template <IrqNum IRQn>
[[nodiscard]] constexpr auto is_irq_active() noexcept {
	return reg::NVIC_IABR<IRQn>.template readBit<reg::NVIC_IRQ_BIT_POS(IRQn)>(ValueOnly);
}

template <IrqNum IRQn>
constexpr void gen_software_interrupt() noexcept {
	reg::NVIC_STIR.writeBit<reg::NvicStirBit::IntId>(to_underlying(IRQn));
}

template <IrqNum IRQn>
constexpr void set_irq_priority(std::uint8_t const& t_priority) noexcept {
	if constexpr (to_underlying(IRQn) <= 0) {
	} else {
		reg::NVIC_IPR<IRQn>.writeBit<reg::NvicIprBit::Ip>(t_priority);
	}
}

}	 // namespace cpp_stm32::nvic
