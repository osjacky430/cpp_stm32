/**
 * @file  stm32/f4/register/spi.hxx
 * @brief	Spi registers of stm32f4
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

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

#include "cpp_stm32/target/stm32/f4/define/spi.hxx"

namespace cpp_stm32::spi::reg {

static constexpr auto BASE_ADDR(Port const& t_spi) {
	switch (t_spi) {
		case Port::SPI1:
			return 0x40013000U;
		case Port::SPI2:
			return 0x40003800U;
		case Port::SPI3:
			return 0x40003c00U;
		case Port::SPI4:
			return 0x40013400U;
	}
}

/**
 * @defgroup	SPI4_CR1_GROUP		control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR1BitList,															/**/
										Binary<>{BitPos_t{0}},									// CPHA
										Binary<>{BitPos_t{1}},									// CPOL
										Binary<>{BitPos_t{2}},									// MSTR
										Bit<3, Baudrate_t>{BitPos_t{3}},				// BR
										Binary<>{BitPos_t{6}},									// SPE
										Binary<>{BitPos_t{7}},									// LSBFIRST
										Binary<>{BitPos_t{8}},									// SSI
										Binary<>{BitPos_t{9}},									// SSM
										Binary<>{BitPos_t{10}},									// RXONLY
										Bit<1, DataFrameFormat>{BitPos_t{11}},	// DFF
										Binary<>{BitPos_t{12}},									// CRCNEXT
										Binary<>{BitPos_t{13}},									// CRCEN
										Binary<>{BitPos_t{14}},									// BIDIOE
										Binary<>{BitPos_t{15}}									// BIDIMODE
)

enum class CR1Field {
	CPHA,			/*!< Clock phase*/
	CPOL,			/*!< Clock polarity*/
	MSTR,			/*!< Master selection*/
	BR,				/*!< Baud rate control*/
	SPE,			/*!< SPI enable*/
	LSBFIRST, /*!< Frame format*/
	SSI,			/*!< Internal slave select*/
	SSM,			/*!< Software slave management*/
	RXONLY,		/*!< Receive only*/
	DFF,			/*!< Data frame format*/
	CRCNEXT,	/*!< CRC transfer next*/
	CRCEN,		/*!< Hardware CRC calculation enable*/
	BIDIOE,		/*!< Output enable in bidirectional mode*/
	BIDIMODE, /*!< Bidirectional data mode enable*/
};

template <Port SPI>
static constexpr Register<CR1BitList, CR1Field> CR1{BASE_ADDR(SPI), 0x00U};
/**@}*/

/**
 * @defgroup	SPI4_CR2_GROUP		control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR2BitList,							/**/
										Binary<>{BitPos_t{0}},	// RXDMAEN
										Binary<>{BitPos_t{1}},	// TXDMAEN
										Binary<>{BitPos_t{2}},	// SSOE
										Binary<>{BitPos_t{4}},	// FRF
										Binary<>{BitPos_t{5}},	// ERRIE
										Binary<>{BitPos_t{6}},	// RXNEIE
										Binary<>{BitPos_t{7}}		// TXEIE
)

enum class CR2Field {
	RXDMAEN, /*!< Rx buffer DMA enable*/
	TXDMAEN, /*!< Tx buffer DMA enable*/
	SSOE,		 /*!< SS output enable*/
	FRF,		 /*!< Frame format*/
	ERRIE,	 /*!< Error interrupt enable*/
	RXNEIE,	 /*!< RX buffer not empty interrupt enable*/
	TXEIE,	 /*!< Tx buffer empty interrupt enable*/
};

template <Port SPI>
static constexpr Register<CR2BitList, CR2Field> CR2{BASE_ADDR(SPI), 0x04U};
/**@}*/

/**
 * @defgroup	SPI4_SR_GROUP		status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList,									/**/
										StatusBit<1>{BitPos_t{0}},	// RXNE
										StatusBit<1>{BitPos_t{1}},	// TXE
										StatusBit<1>{BitPos_t{2}},	// CHSIDE
										StatusBit<1>{BitPos_t{3}},	// UDR
										Binary<>{BitPos_t{4}},			// CRCERR
										StatusBit<1>{BitPos_t{5}},	// MODF
										StatusBit<1>{BitPos_t{6}},	// OVR
										StatusBit<1>{BitPos_t{7}},	// BSY
										StatusBit<1>{BitPos_t{8}}		// TIFRFE
)

template <Port SPI>
static constexpr Register<SRBitList, Status> SR{BASE_ADDR(SPI), 0x08U};
/**@}*/

/**
 * @defgroup	SPI4_DR_GROUP		data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DRBitList,													 /**/
										Bit<16, std::uint16_t>{BitPos_t{0}}	 // DR
)

enum class DRField {
	DR, /*!< Data register*/
};

template <Port SPI>
static constexpr Register<DRBitList, DRField> DR{BASE_ADDR(SPI), 0x0cU};
/**@}*/

/**
 * @defgroup	SPI4_CRCPR_GROUP		CRC polynomial register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRCPRBitList,												 /**/
										Bit<16, std::uint16_t>{BitPos_t{0}}	 // CRCPOLY
)

enum class CRCPRField {
	CRCPOLY, /*!< CRC polynomial register*/
};

template <Port SPI>
static constexpr Register<CRCPRBitList, CRCPRField> CRCPR{BASE_ADDR(SPI), 0x10U};
/**@}*/

/**
 * @defgroup	SPI4_RXCRCR_GROUP		RX CRC register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RXCRCRBitList,											 /**/
										Bit<16, std::uint16_t>{BitPos_t{0}}	 // RxCRC
)

enum class RXCRCRField {
	RxCRC, /*!< Rx CRC register*/
};

template <Port SPI>
static constexpr Register<RXCRCRBitList, RXCRCRField> RXCRCR{BASE_ADDR(SPI), 0x14U};
/**@}*/

/**
 * @defgroup	SPI4_TXCRCR_GROUP		TX CRC register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TXCRCRBitList,											 /**/
										Bit<16, std::uint16_t>{BitPos_t{0}}	 // TxCRC
)

enum class TXCRCRField {
	TxCRC, /*!< Tx CRC register*/
};

template <Port SPI>
static constexpr Register<TXCRCRBitList, TXCRCRField> TXCRCR{BASE_ADDR(SPI), 0x18U};
/**@}*/

/**
 * @defgroup	SPI4_I2SCFGR_GROUP		I2S configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(I2SCFGRBitList,					 /**/
										Binary<>{BitPos_t{0}},	 // CHLEN
										Bit<2>{BitPos_t{1}},		 // DATLEN
										Binary<>{BitPos_t{3}},	 // CKPOL
										Bit<2>{BitPos_t{4}},		 // I2SSTD
										Binary<>{BitPos_t{7}},	 // PCMSYNC
										Bit<2>{BitPos_t{8}},		 // I2SCFG
										Binary<>{BitPos_t{10}},	 // I2SE
										Binary<>{BitPos_t{11}}	 // I2SMOD
)

enum class I2SCFGRField {
	CHLEN,	 /*!< Channel length (number of bits per audio channel)*/
	DATLEN,	 /*!< Data length to be transferred*/
	CKPOL,	 /*!< Steady state clock polarity*/
	I2SSTD,	 /*!< I2S standard selection*/
	PCMSYNC, /*!< PCM frame synchronization*/
	I2SCFG,	 /*!< I2S configuration mode*/
	I2SE,		 /*!< I2S Enable*/
	I2SMOD,	 /*!< I2S mode selection*/
};

template <Port SPI>
static constexpr Register<I2SCFGRBitList, I2SCFGRField> I2SCFGR{BASE_ADDR(SPI), 0x1cU};
/**@}*/

/**
 * @defgroup	SPI4_I2SPR_GROUP		I2S prescaler register group
 *
 * @{
 */

SETUP_REGISTER_INFO(I2SPRBitList,						/**/
										Bit<8>{BitPos_t{0}},		// I2SDIV
										Binary<>{BitPos_t{8}},	// ODD
										Binary<>{BitPos_t{9}}		// MCKOE
)

enum class I2SPRField {
	I2SDIV, /*!< I2S Linear prescaler*/
	ODD,		/*!< Odd factor for the prescaler*/
	MCKOE,	/*!< Master clock output enable*/
};

template <Port SPI>
static constexpr Register<I2SPRBitList, I2SPRField> I2SPR{BASE_ADDR(SPI), 0x20U};
/**@}*/

}	 // namespace cpp_stm32::spi::reg
