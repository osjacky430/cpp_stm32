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

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::dma {

enum class Port { DMA1, DMA2 };
enum class Stream { Stream0, Stream1, Stream2, Stream3, Stream4, Stream5, Stream6, Stream7 };
enum class Channel { Channel0, Channel1, Channel2, Channel3, Channel4, Channel5, Channel6, Channel7 };

enum class InterruptFlag {
	FEI,	/*!< Stream x FIFO error interrupt flag */
	DMEI, /*!< Stream x direct mode error interrupt flag */
	TEI,	/*!< Stream x transfer error interrupt flag */
	HTI,	/*!< Stream x half transfer interrupt flag */
	TCI,	/*!< Stream x transfer complete interrupt flag */
};

enum class TransferDir { PeriphToMem, MemToPeriph, MemToMem };
enum class StreamPriority { Low, Medium, High, VeryHigh };
enum class DataSize { Byte, HalfWord, Word };
enum class BurstSize { Single, Incr4, Incr8, Incr16 };
enum class FifoThreshold { OneFourths, Half, ThreeFourths, Full };
enum class FlowControl { DMA, Peripheral };

using PeriphBurstSize_t = StrongType<BurstSize, struct PeriphBurstSize>;
using MemoryBurstSize_t = StrongType<BurstSize, struct MemoryBurstSize>;

}	 // namespace cpp_stm32::dma

namespace cpp_stm32::dma::reg {

static constexpr auto BASE_ADDR(Port const& t_dma) {
	switch (t_dma) {
		case Port::DMA2:
			return 0x40026400U;
		case Port::DMA1:
			return 0x40026000U;
	}
}

/**
 * @defgroup	DMA1_LISR_GROUP		low interrupt status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(LISRBitList,																									/**/
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<0, 6, 16, 22>),		// FEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<2, 8, 18, 24>),		// DMEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<3, 9, 19, 25>),		// TEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<4, 10, 20, 26>),	// HTI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<5, 11, 21, 27>)		// TCI
)

template <Port DMA>
static constexpr Register<LISRBitList, InterruptFlag> LISR{BASE_ADDR(DMA), 0x00U};
/**@}*/

/**
 * @defgroup	DMA1_HISR_GROUP		high interrupt status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(HISRBitList,																									/**/
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<0, 6, 16, 22>),		// FEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<2, 8, 18, 24>),		// DMEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<3, 9, 19, 25>),		// TEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<4, 10, 20, 26>),	// HTI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<5, 11, 21, 27>)		// TCI
)

template <Port DMA>
static constexpr Register<HISRBitList, InterruptFlag> HISR{BASE_ADDR(DMA), 0x04U};
/**@}*/

/**
 * @defgroup	DMA1_LIFCR_GROUP		low interrupt flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(LIFCRBitList,																									/**/
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<0, 6, 16, 22>),		// CFEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<2, 8, 18, 24>),		// CDMEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<3, 9, 19, 25>),		// CTEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<4, 10, 20, 26>),	// CHTI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<5, 11, 21, 27>)		// CTCI
)

template <Port DMA>
static constexpr Register<LIFCRBitList, InterruptFlag> LIFCR{BASE_ADDR(DMA), 0x08U};
/**@}*/

/**
 * @defgroup	DMA1_HIFCR_GROUP		high interrupt flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(HIFCRBitList,																									/**/
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<0, 6, 16, 22>),		// CFEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<2, 8, 18, 24>),		// CDMEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<3, 9, 19, 25>),		// CTEI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<4, 10, 20, 26>),	// CHTI
										CREATE_LIST_OF_BITS<StatusBit<1>>(BitPosSeq<5, 11, 21, 27>)		// CTCI
)

template <Port DMA>
static constexpr Register<HIFCRBitList, InterruptFlag> HIFCR{BASE_ADDR(DMA), 0x0cU};
/**@}*/

/**
 * @defgroup	DMA1_SxCR_GROUP		stream x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SxCRBitList,													 /**/
										Binary<>{BitPos_t{0}},								 // EN
										Binary<>{BitPos_t{1}},								 // DMEIE
										Binary<>{BitPos_t{2}},								 // TEIE
										Binary<>{BitPos_t{3}},								 // HTIE
										Binary<>{BitPos_t{4}},								 // TCIE
										Binary<>{BitPos_t{5}},								 // PFCTRL
										Bit<2, TransferDir>{BitPos_t{6}},			 // DIR
										Binary<>{BitPos_t{8}},								 // CIRC
										Binary<>{BitPos_t{9}},								 // PINC
										Binary<>{BitPos_t{10}},								 // MINC
										Bit<2, DataSize>{BitPos_t{11}},				 // PSIZE
										Bit<2, DataSize>{BitPos_t{13}},				 // MSIZE
										Binary<>{BitPos_t{15}},								 // PINCOS
										Bit<2, StreamPriority>{BitPos_t{16}},	 // PL
										Binary<>{BitPos_t{18}},								 // DBM
										Binary<>{BitPos_t{19}},								 // CT
										Bit<2, BurstSize>{BitPos_t{21}},			 // PBURST
										Bit<2, BurstSize>{BitPos_t{23}},			 // MBURST
										Bit<3, Channel>{BitPos_t{25}}					 // CHSEL
)

enum class SxCRField {
	EN,			/*!< Stream enable / flag stream ready when read low*/
	DMEIE,	/*!< Direct mode error interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	PFCTRL, /*!< Peripheral flow controller*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,	/*!< Peripheral data size*/
	MSIZE,	/*!< Memory data size*/
	PINCOS, /*!< Peripheral increment offset size*/
	PL,			/*!< Priority level*/
	DBM,		/*!< Double buffer mode*/
	CT,			/*!< Current target (only in double buffer mode)*/
	PBURST, /*!< Peripheral burst transfer configuration*/
	MBURST, /*!< Memory burst transfer configuration*/
	CHSEL,	/*!< Channel selection*/
};

template <Port DMA, Stream Str>
static constexpr Register<SxCRBitList, SxCRField> SxCR{BASE_ADDR(DMA), 0x10 + 0x18U * to_underlying(Str)};
/**@}*/

/**
 * @defgroup	DMA1_SxNDTR_GROUP		stream x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SxNDTRBitList,											 /**/
										Bit<16, std::uint16_t>{BitPos_t{0}}	 // NDT
)

enum class SxNDTRField {
	NDT, /*!< Number of data items to transfer*/
};

template <Port DMA, Stream Str>
static constexpr Register<SxNDTRBitList, SxNDTRField> SxNDTR{BASE_ADDR(DMA), 0x14U + 0x18 * to_underlying(Str)};
/**@}*/

/**
 * @defgroup	DMA1_SxPAR_GROUP		stream x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SxPARBitList,													/**/
										Bit<32, std::uintptr_t>{BitPos_t{0}}	// PA
)

enum class SxPARField {
	PA, /*!< Peripheral address*/
};

template <Port DMA, Stream Str>
static constexpr Register<SxPARBitList, SxPARField> SxPAR{BASE_ADDR(DMA), 0x18 + 0x18U * to_underlying(Str)};
/**@}*/

/**
 * @defgroup	DMA1_SxM0AR_GROUP		stream x memory 0 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SxM0ARBitList,												/**/
										Bit<32, std::uintptr_t>{BitPos_t{0}}	// M0A
)

enum class SxM0ARField {
	M0A, /*!< Memory 0 address*/
};

template <Port DMA, Stream Str>
static constexpr Register<SxM0ARBitList, SxM0ARField> SxM0AR{BASE_ADDR(DMA), 0x1CU + 0x18 * to_underlying(Str)};
/**@}*/

/**
 * @defgroup	DMA1_SxM1AR_GROUP		stream x memory 1 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SxM1ARBitList,												/**/
										Bit<32, std::uintptr_t>{BitPos_t{0}}	// M1A
)

enum class SxM1ARField {
	M1A, /*!< Memory 1 address (used in case of Double buffer mode)*/
};

template <Port DMA, Stream Str>
static constexpr Register<SxM1ARBitList, SxM1ARField> SxM1AR{BASE_ADDR(DMA), 0x20U + 0x18 * to_underlying(Str)};
/**@}*/

/**
 * @defgroup	DMA1_SxFCR_GROUP		stream x FIFO control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SxFCRBitList,												 /**/
										Bit<2, FifoThreshold>{BitPos_t{0}},	 // FTH
										Binary<>{BitPos_t{2}},							 // DMDIS
										StatusBit<3>{BitPos_t{3}},					 // FS
										Binary<>{BitPos_t{7}}								 // FEIE
)

enum class SxFCRField {
	FTH,	 /*!< FIFO threshold selection*/
	DMDIS, /*!< Direct mode disable*/
	FS,		 /*!< FIFO status*/
	FEIE,	 /*!< FIFO error interrupt enable*/
};

template <Port DMA, Stream Str>
static constexpr Register<SxFCRBitList, SxFCRField> SxFCR{BASE_ADDR(DMA),											//
																													0x24U + 0x24 * to_underlying(Str),	//
																													ResetVal_t{0x0000'0021}};
/**@}*/

}	 // namespace cpp_stm32::dma::reg
