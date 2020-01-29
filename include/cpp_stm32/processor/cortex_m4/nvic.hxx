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

#include "cpp_stm32/processor/cortex_m4/memory/internal_periph.hxx"
#include "cpp_stm32/processor/cortex_m4/memory/nvic_reg.hxx"

namespace cpp_stm32 {

template <IrqNum IRQn>
constexpr void nvic_enable_irq() noexcept {
	NVIC_ISER<IRQn>.template writeBit<NVIC_IRQ_BIT_POS(IRQn)>();
}

template <IrqNum IRQn>
[[nodiscard]] constexpr bool nvic_is_irq_enabled() noexcept {
	return get<0>(NVIC_ISER<IRQn>.template readBit<NVIC_IRQ_BIT_POS(IRQn)>(ValueOnly));
}

template <IrqNum IRQn>
constexpr void nvic_disable_irq() noexcept {
	NVIC_ICER<IRQn>.template writeBit<NVIC_IRQ_BIT_POS(IRQn)>();
}

template <IrqNum IRQn>
constexpr auto nvic_is_irq_pending() noexcept {
	return NVIC_ISPR<IRQn>.template readBit<NVIC_IRQ_BIT_POS(IRQn)>(ValueOnly);
}

template <IrqNum IRQn>
constexpr void nvic_set_irq_pending() noexcept {
	NVIC_ISPR<IRQn>.template writeBit<NVIC_IRQ_BIT_POS(IRQn)>();
}

template <IrqNum IRQn>
constexpr void nvic_clear_pending_irq() noexcept {
	NVIC_ICPR<IRQn>.template writeBit<NVIC_IRQ_BIT_POS(IRQn)>();
}

template <IrqNum IRQn>
[[nodiscard]] constexpr auto nvic_is_irq_active() noexcept {
	return NVIC_IABR<IRQn>.template readBit<NVIC_IRQ_BIT_POS(IRQn)>(ValueOnly);
}

template <IrqNum IRQn>
constexpr void nvic_gen_software_interrupt() noexcept {
	NVIC_STIR.writeBit<NvicStirBit::IntId>(to_underlying(IRQn));
}

template <IrqNum IRQn>
constexpr void nvic_set_irq_priority(std::uint8_t const& t_priority) noexcept {
	if constexpr (to_underlying(IRQn) <= 0) {
	} else {
		NVIC_IPR<IRQn>.writeBit<NvicIprBit::Ip>(t_priority);
	}
}

}	 // namespace cpp_stm32
