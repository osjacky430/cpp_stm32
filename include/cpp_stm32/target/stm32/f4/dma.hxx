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

#include "cpp_stm32/common/dma.hxx"
#include "cpp_stm32/target/stm32/f4/memory/dma_reg.hxx"

namespace cpp_stm32::dma {

/**
 * [clear_interrupt_flag description]
 */
template <Port DMA, Stream Str, InterruptFlag... Flags>
constexpr void clear_interrupt_flag() noexcept {
	if constexpr (to_underlying(Str) <= 3) {
		reg::LIFCR<DMA>.template setBit<InterruptFlag{to_underlying(Flags) * 4U + to_underlying(Str)}...>();
	} else {
		reg::HIFCR<DMA>.template setBit<InterruptFlag{to_underlying(Flags) * 4U + to_underlying(Str) - 4}...>();
	}
}

/**
 * [get_interrupt_flag description]
 * @return [description]
 */
template <Port DMA, Stream Str, InterruptFlag... Flags>
[[nodiscard]] constexpr bool get_interrupt_flag() noexcept {
	if constexpr (to_underlying(Str) <= 3) {
		return get<0>(
			reg::LISR<DMA>.template readBit<InterruptFlag{to_underlying(Flags) * 4U + to_underlying(Str)}...>(ValueOnly));
	} else {
		return get<0>(
			reg::HISR<DMA>.template readBit<InterruptFlag{to_underlying(Flags) * 4U + to_underlying(Str) - 4}...>(ValueOnly));
	}
}

/**
 * [is_enabled description]
 * @return [description]
 */
template <Port DMA, Stream Str>
[[nodiscard]] constexpr bool is_enabled() noexcept {
	return get<0>(reg::SxCR<DMA, Str>.template readBit<reg::SxCRField::EN>(ValueOnly));
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

}	// namespace cpp_stm32::dma

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
// template <Port DMA, Stream Str>
// constexpr void enable_tx_complete_irq() noexcept {
// 	if constexpr (to_underlying(Str) <= 3) {
// 		constexpr auto idx = to_underlying(InterruptFlag::TCI) * 4U + to_underlying(Str);
// 		reg::LISR<DMA>.template setBit<InterruptFlag{idx}>();
// 	} else {
// 		constexpr auto idx = to_underlying(InterruptFlag::TCI) * 4U + to_underlying(Str);
// 		reg::HISR<DMA>.template setBit<InterruptFlag{idx}>();
// 	}
// }

/**
 * [enable description]
 */
template <Port DMA, Stream Str>
constexpr void disable() noexcept {
	reg::SxCR<DMA, Str>.template clearBit<reg::SxCRField::EN>();
}

/**
 * [enable description]
 */
template <Port DMA, Stream Str>
constexpr void enable() noexcept {
	reg::SxCR<DMA, Str>.template setBit<reg::SxCRField::EN>();
}

/**
 * [reset description]
 */
template <Port DMA, Stream Str>
constexpr void reset() noexcept {
	reg::SxCR<DMA, Str>.template clearBit<reg::SxCRField::EN>();

	while (is_enabled<DMA, Str>()) {
	}

	reg::SxCR<DMA, Str>.reset();
	reg::SxNDTR<DMA, Str>.reset();
	reg::SxPAR<DMA, Str>.reset();
	reg::SxM0AR<DMA, Str>.reset();
	reg::SxM1AR<DMA, Str>.reset();
	reg::SxFCR<DMA, Str>.reset();

	if constexpr (to_underlying(Str) <= 3) {
		// reg::LIFCR<DMA>.
	}
}

/**
 * [DmaBuilder description]
 *
 * @note     Stream configuration procedure
 *           1. disable stream if is enabled, wait until the stream is disabled
 *           2.
 */
template <Port DMA, Stream Str>
class DmaBuilder {
 private:
	Channel m_channelSelect;
	TransferDir m_transferDirection;
	StreamPriority m_streamPriority;

	std::uint8_t m_periphIncrementMode;
	std::uint8_t m_periphFixIncr;
	DataSize m_peripheralDataSize;
	BurstSize m_peripheralBurstSize;

	std::uint8_t m_memoryIncrementMode;
	DataSize m_memoryDataSize;
	BurstSize m_memoryBurstSize;

	std::uint8_t m_circularMode;
	std::uint8_t m_doubleBuffer;
	std::uint8_t m_currentTarget;

	std::uint8_t m_directModeDisabled;
	std::uint8_t m_fifoErrorIrq;
	FifoThreshold m_fifoThreshold;

	std::uint8_t m_directModeDisabledErrorIrq;
	std::uint8_t m_transferErrorIrq;
	std::uint8_t m_halfTransferIrq;
	std::uint8_t m_transferCompleteIrq;

 public:
	constexpr DmaBuilder() noexcept
		: m_channelSelect(Channel::Channel0),
			m_transferDirection(TransferDir::PeriphToMem),
			m_streamPriority(StreamPriority::Low),
			m_periphIncrementMode(false),
			m_periphFixIncr(false),
			m_peripheralDataSize(DataSize::Byte),
			m_peripheralBurstSize(BurstSize::Single),
			m_memoryIncrementMode(false),
			m_memoryDataSize(DataSize::Byte),
			m_memoryBurstSize(BurstSize::Single),
			m_circularMode(false),
			m_doubleBuffer(false),
			m_currentTarget(0),
			m_directModeDisabled(false),
			m_fifoErrorIrq(false),
			m_fifoThreshold(FifoThreshold::OneFourths),
			m_directModeDisabledErrorIrq(false),
			m_transferErrorIrq(false),
			m_halfTransferIrq(false),
			m_transferCompleteIrq(false) {
		reset<DMA, Str>();
	}

	[[nodiscard]] constexpr auto transferDir(PeriphAddress_t const& t_from, MemoryAddress_t const& t_to) noexcept {
		m_transferDirection = TransferDir::PeriphToMem;

		reg::SxPAR<DMA, Str>.template writeBit<reg::SxPARField::PA>(t_from.get());
		reg::SxM0AR<DMA, Str>.template writeBit<reg::SxM0ARField::M0A>(t_to.get());

		return *this;
	}

	[[nodiscard]] constexpr auto transferDir(MemoryAddress_t const& t_from, PeriphAddress_t const& t_to) noexcept {
		m_transferDirection = TransferDir::MemToPeriph;

		reg::SxPAR<DMA, Str>.template writeBit<reg::SxPARField::PA>(t_to.get());
		reg::SxM0AR<DMA, Str>.template writeBit<reg::SxM0ARField::M0A>(t_from.get());

		return *this;
	}

	[[nodiscard]] constexpr auto transferDir(MemoryAddress_t const& t_from, MemoryAddress_t const& t_to) noexcept {
		m_transferDirection = TransferDir::MemToMem;

		reg::SxPAR<DMA, Str>.template writeBit<reg::SxPARField::PA>(t_from.get());
		reg::SxM0AR<DMA, Str>.template writeBit<reg::SxM0ARField::M0A>(t_to.get());

		return *this;
	}

	[[nodiscard]] constexpr auto txDataNum(std::uint16_t const& t_ndt) noexcept {
		reg::SxNDTR<DMA, Str>.template writeBit<reg::SxNDTRField::NDT>(t_ndt);
		return *this;
	}

	[[nodiscard]] constexpr auto selectChannel(Channel const& t_ch) noexcept {
		m_channelSelect = t_ch;
		return *this;
	}

	[[nodiscard]] constexpr auto streamPriority(StreamPriority const& t_str) noexcept {
		m_streamPriority = t_str;
		return *this;
	}

	[[nodiscard]] constexpr auto memoryIncrementMode(bool const& t_incr) noexcept {
		m_memoryIncrementMode = t_incr;
		return *this;
	}

	[[nodiscard]] constexpr auto memoryBurstTransfer(BurstSize const& t_bs) noexcept {
		m_memoryBurstSize = t_bs;
		return *this;
	}

	[[nodiscard]] constexpr auto memoryDataWidth(DataSize const& t_ds) noexcept {
		m_memoryDataSize = t_ds;
		return *this;
	}

	[[nodiscard]] constexpr auto peripheralIncrementMode(bool const& t_incr) noexcept {
		m_periphIncrementMode = t_incr;
		return *this;
	}

	[[nodiscard]] constexpr auto perihperalFixIncrement(bool const& t_fix_incr) noexcept {
		m_periphFixIncr = t_fix_incr;
		return *this;
	}

	[[nodiscard]] constexpr auto peripheralBurstTransfer(BurstSize const& t_bs) noexcept {
		m_peripheralBurstSize = t_bs;
		return *this;
	}

	[[nodiscard]] constexpr auto perihperalDataWidth(DataSize const& t_ds) noexcept {
		m_peripheralDataSize = t_ds;
		return *this;
	}

	[[nodiscard]] constexpr auto circularMode(bool const& t_c) noexcept {
		m_circularMode = t_c;
		return *this;
	}

	[[nodiscard]] constexpr auto doubleBufferTarget(std::uint8_t const& t_target = 0) noexcept {
		m_doubleBuffer	= true;
		m_currentTarget = t_target;
		return *this;
	}

	[[nodiscard]] constexpr auto configFIFO(FifoThreshold const& t_fts) noexcept {
		m_directModeDisabled = true;
		m_fifoThreshold			 = t_fts;
		return *this;
	}

	template <InterruptFlag... Flags>
	[[nodiscard]] constexpr auto enableInterrupt() noexcept {
		// @todo find a better way to do this
		m_fifoErrorIrq							 = ((Flags == InterruptFlag::FEI) || ...);
		m_directModeDisabledErrorIrq = ((Flags == InterruptFlag::DMEI) || ...);
		m_transferErrorIrq					 = ((Flags == InterruptFlag::TEI) || ...);
		m_halfTransferIrq						 = ((Flags == InterruptFlag::HTI) || ...);
		m_transferCompleteIrq				 = ((Flags == InterruptFlag::TCI) || ...);

		return *this;
	}

	constexpr void build() noexcept {
		using namespace reg;

		SxFCR<DMA, Str>.template writeBit<SxFCRField::FTH, SxFCRField::DMDIS, SxFCRField::FEIE>(
			m_fifoThreshold, m_directModeDisabled, m_fifoErrorIrq);

		SxCR<DMA, Str>.template writeBit<SxCRField::DMEIE, SxCRField::TEIE, SxCRField::HTIE, SxCRField::TCIE, SxCRField::DIR,   //
                                     SxCRField::CIRC, SxCRField::PINC, SxCRField::MINC, SxCRField::PSIZE, SxCRField::MSIZE, //
                                     SxCRField::PINCOS, SxCRField::PL, SxCRField::DBM, SxCRField::CT, SxCRField::PBURST,
                                     SxCRField::MBURST, SxCRField::CHSEL>(
			m_directModeDisabledErrorIrq, m_transferErrorIrq, m_halfTransferIrq, m_transferCompleteIrq, m_transferDirection,
			m_circularMode, m_periphIncrementMode, m_memoryIncrementMode, m_peripheralDataSize, m_memoryDataSize, m_periphFixIncr,
      m_streamPriority, m_doubleBuffer, m_currentTarget, m_peripheralBurstSize, m_memoryBurstSize, m_channelSelect);

		enable<DMA, Str>();
	}
};

}	// namespace cpp_stm32::dma
