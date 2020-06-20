/**
 * @file  stm32/f4/define/dma.hxx
 * @brief	Dma class and enum define.
 */

/** Copyright (c) 2020 by osjacky430.
 * All Rights Reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstdint>

#include "cpp_stm32/common/dma.hxx"

namespace cpp_stm32::dma {

/**
 * @enum Port
 */
enum class Port : std::uint8_t { DMA1, DMA2 };

/**
 * @enum 		Stream
 * @brief		Each of the streams provides a unidirectional transfer link between a source and a destination:
 * 						- Regular type: memory-to-peripherals, peripherals-to-memory or memory- to-memory transfers
 * 						- Double-buffer type: using two memory pointers for the memory.
 */
enum class Stream : std::uint8_t { Stream0, Stream1, Stream2, Stream3, Stream4, Stream5, Stream6, Stream7 };

/**
 * @enum Channel
 */
enum class Channel : std::uint8_t { Channel0, Channel1, Channel2, Channel3, Channel4, Channel5, Channel6, Channel7 };

/**
 * @enum 	InterruptFlag
 */
enum class InterruptFlag : std::uint8_t {
	FEI,	/*!< Stream x FIFO error interrupt flag */
	DMEI, /*!< Stream x direct mode error interrupt flag */
	TEI,	/*!< Stream x transfer error interrupt flag */
	HTI,	/*!< Stream x half transfer interrupt flag */
	TCI,	/*!< Stream x transfer complete interrupt flag */
};

/**
 * @enum 		TransferMode
 * @brief 	DMA transfer direction
 */
enum class TransferMode : std::uint8_t {
	PeriphToMem, /*!< Perihperal to Memory */
	MemToPeriph, /*!< Memory to Peripheral */
	MemToMem,		 /*!< Memory to Memory */
};

/**
 * @enum 	StreamPriority
 * @note 	If two requests have the same software priority level, the stream with the lower number takes priority over
 * 				the stream with the higher number. For example, stream 2 takes priority over stream 4.
 */
enum class StreamPriority : std::uint8_t { Low, Medium, High, VeryHigh };

/**
 * @enum  DataSize
 * @note 	When the data width is a half-word or a word, respectively, the peripheral or memory address written into the
 * 				DMA_SxPAR or DMA_SxM0AR/M1AR registers has to be aligned on a word or half-word address boundary,
 * 				respectively.
 */
enum class DataSize : std::uint8_t { Byte, HalfWord, Word };
enum class BurstSize : std::uint8_t { Single, Incr4, Incr8, Incr16 };
enum class FifoThreshold : std::uint8_t { OneFourths, Half, ThreeFourths, Full };
enum class FlowControl : std::uint8_t { DMA, Peripheral };

using PeriphBurstSize_t = StrongType<BurstSize, struct PeriphBurstSize>;
using MemoryBurstSize_t = StrongType<BurstSize, struct MemoryBurstSize>;

}	 // namespace cpp_stm32::dma
