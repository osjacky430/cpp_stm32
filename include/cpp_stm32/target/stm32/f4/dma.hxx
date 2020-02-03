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

#include "cpp_stm32/target/stm32/f4/memory/dma_reg.hxx"

namespace cpp_stm32::dma {

template <Port DMA, Stream Str>
constexpr void reset() noexcept {
	reg::SxCR<DMA, Str>.template clearBit<reg::SxCRField::EN>();
}

/**
 * [clear_interrupt_flag description]
 */
template <Port DMA, Stream Str, InterruptFlag... Flags>
constexpr void clear_interrupt_flag() noexcept {
	if constexpr (to_underlying(Str) <= 3) {
		reg::LIFCR<DMA>.template setBit<Flags...>();
	} else {
		reg::HIFCR<DMA>.template setBit<Flags...>();
	}
}

/**
 * [get_interrupt_flag description]
 * @return [description]
 */
template <Port DMA, Stream Str, InterruptFlag... Flags>
constexpr auto get_interrupt_flag() noexcept {
	if constexpr (to_underlying(Str) <= 3) {
		return reg::LIFCR<DMA>.template readBit<Flags...>(ValueOnly);
	} else {
		return reg::HIFCR<DMA>.template readBit<Flags...>(ValueOnly);
	}
}

/**
 * [is_enabled description]
 * @return [description]
 */
template <Port DMA, Stream Str>
constexpr bool is_enabled() noexcept {
	return reg::SxCR<DMA, Str>.template readBit<reg::SxCRField::EN>();
}

/**
 * [set_tx_direction description]
 * @param t_dir [description]
 */
template <Port DMA, Stream Str>
constexpr void set_tx_mode(TransferDir const& t_dir) noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template writeBit<reg::SxCRField::DIR>(t_dir);
	}
}

/**
 * [enable_tx_complete_irq description]
 */
template <Port DMA, Stream Str>
constexpr void set_priority(StreamPriority const& t_prior) noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template writeBit<reg::SxCRField::PL>(t_prior);
	}
}

/**
 * [set_memory_size description]
 * @param size [description]
 */
template <Port DMA, Stream Str>
constexpr void set_memory_data_size(DataSize const& t_size) noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template writeBit<reg::SxCRField::MSIZE>(t_size);
	}
}

/**
 * [set_periph_data_size description]
 * @param t_size [description]
 */
template <Port DMA, Stream Str>
constexpr void set_periph_data_size(DataSize const& t_size) noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template writeBit<reg::SxCRField::PSIZE>(t_size);
	}
}

/**
 * [enable_tx_complete_irq description]
 */
template <Port DMA, Stream Str>
constexpr void enable_mem_increment() noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template setBit<reg::SxCRField::MINC>();
	}
}

/**
 * [disable_mem_increment description]
 */
template <Port DMA, Stream Str>
constexpr void disable_mem_increment() noexcept {
	reg::SxCR<DMA, Str>.template clearBit<reg::SxCRField::MINC>();
}

/**
 * [enable_periph_increment description]
 */
template <Port DMA, Stream Str>
constexpr void enable_periph_increment() noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template setBit<reg::SxCRField::PINC>();
	}
}

/**
 * [disable_periph_increment description]
 */
template <Port DMA, Stream Str>
constexpr void disable_periph_increment() noexcept {
	reg::SxCR<DMA, Str>.template clearBit<reg::SxCRField::PINC>();

}	 // namespace cpp_stm32::dma

/**
 * [enable_periph_fix_increment description]
 */
template <Port DMA, Stream Str>
constexpr void enable_periph_fix_increment() noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template setBit<reg::SxCRField::PINC, reg::SxCRField::PINCOS>();
	}
}

/**
 * [enable_circular_mode description]
 */
template <Port DMA, Stream Str>
constexpr void enable_circular_mode() noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template setBit<reg::SxCRField::CIRC>();
	}
}

/**
 * [channel_select description]
 * @param t_ch [description]
 */
template <Port DMA, Stream Str>
constexpr void channel_select(Channel const& t_ch) noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template writeBit<reg::SxCRField::CHSEL>(t_ch);
	}
}

/**
 * [set_memory_burst description]
 * @param t_bs [description]
 */
template <Port DMA, Stream Str>
constexpr void set_memory_burst(BurstSize const& t_bs) noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template writeBit<reg::SxCRField::MBURST>(t_bs);
	}
}

/**
 * [set_memory_burst description]
 * @param t_bs [description]
 */
template <Port DMA, Stream Str>
constexpr void set_periph_burst(BurstSize const& t_bs) noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template writeBit<reg::SxCRField::PBURST>(t_bs);
	}
}

/**
 * [set_current_target description]
 */
template <Port DMA, Stream Str>
constexpr void double_buffer_set_target(std::uint8_t const& t_mem) noexcept {
	if (!is_enabled<DMA, Str>()) {
		reg::SxCR<DMA, Str>.template writeBit<reg::SxCRField::CT>(t_mem);
	}
}

/**
 * [set_mem_addr description]
 * @param t_mem_addr [description]
 */
template <Port DMA, Stream Str>
constexpr void set_mem_addr(std::uint32_t const& t_mem_addr) noexcept {
	//
}

/**
 * [set_tx_data_num description]
 * @param t_num [description]
 */
template <Port DMA, Stream Str>
constexpr void set_tx_data_num(std::uint16_t const& t_num) noexcept {
	reg::SxNDTR<DMA, Str>.template writeBit<reg::SxNDTRField::NDT>(t_num);
}

/**
 * [get_tx_data_num description]
 * @return [description]
 */
template <Port DMA, Stream Str>
constexpr auto get_tx_data_num() noexcept {
	return reg::SxNDTR<DMA, Str>.template readBit<reg::SxNDTRField::NDT>(ValueOnly);
}

/**
 * @brief   This function enables the transfer complete interrupt
 * @tparam  Port    ::Port
 * @tparam  Stream  ::Stream
 */
template <Port DMA, Stream Str>
constexpr void enable_tx_complete_irq() noexcept {
	if constexpr (to_underlying(Str) <= 3) {
		constexpr auto idx = to_underlying(InterruptFlag::TCI) * 4U + to_underlying(Str);
		reg::LISR<DMA>.template setBit<InterruptFlag{idx}>();
	} else {
		constexpr auto idx = to_underlying(InterruptFlag::TCI) * 4U + to_underlying(Str);
		reg::HISR<DMA>.template setBit<InterruptFlag{idx}>();
	}
}

/**
 * [enable description]
 */
template <Port DMA, Stream Str>
constexpr void enable() noexcept {
	reg::SxCR<DMA, Str>.template setBit<reg::SxCRField::EN>();
}

/**
 *
 */
template <Port DMA, Stream Str>
class DmaBuilder {};

}	 // namespace cpp_stm32::dma
