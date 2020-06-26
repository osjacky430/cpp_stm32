#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::spi::reg {

static constexpr auto BASE_ADDR(Port const& t_spi) {
	switch (t_spi) {
		case Port::SPI1:
			return 0x40013000U;
		case Port::SPI3:
			return 0x40003c00U;
		case Port::SPI2:
			return 0x40003800U;
	}
}

/**
 * @defgroup	SPI2_CR1_GROUP		control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR1BitList,										 /**/
										Binary<>{BitPos_t{0}},				 // CPHA
										Binary<>{BitPos_t{1}},				 // CPOL
										Binary<>{BitPos_t{2}},				 // MSTR
										Bit<3>{BitPos_t{3}},					 // BR
										Binary<>{BitPos_t{6}},				 // SPE
										Binary<>{BitPos_t{7}},				 // LSBFIRST
										Binary<>{BitPos_t{8}},				 // SSI
										Binary<>{BitPos_t{9}},				 // SSM
										Binary<>{BitPos_t{10}},				 // RXONLY
										Bit<1, CRCLen>{BitPos_t{11}},	 // CRCLEN
										Binary<>{BitPos_t{12}},				 // CRCNEXT
										Binary<>{BitPos_t{13}},				 // CRCEN
										Binary<>{BitPos_t{14}},				 // BIDIOE
										Binary<>{BitPos_t{15}}				 // BIDIMODE
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
	CRCLEN,		/*!< CRC length */
	CRCNEXT,	/*!< CRC transfer next*/
	CRCEN,		/*!< Hardware CRC calculation enable*/
	BIDIOE,		/*!< Output enable in bidirectional mode*/
	BIDIMODE, /*!< Bidirectional data mode enable*/
};

template <Port SPI>
static constexpr Register<CR1BitList, CR1Field> CR1{BASE_ADDR(SPI), 0x00U};
/**@}*/

/**
 * @defgroup	SPI2_CR2_GROUP		control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR2BitList,											/**/
										Binary<>{BitPos_t{14}},					// LDMA_TX
										Binary<>{BitPos_t{13}},					// LDMA_RX
										Binary<>{BitPos_t{12}},					// FRXTH
										Bit<4, DataSize>{BitPos_t{8}},	// DS
										Binary<>{BitPos_t{7}},					// TXEIE
										Binary<>{BitPos_t{6}},					// RXNEIE
										Binary<>{BitPos_t{5}},					// ERRIE
										Binary<>{BitPos_t{4}},					// FRF
										Binary<>{BitPos_t{3}},					// NSSP
										Binary<>{BitPos_t{2}},					// SSOE
										Binary<>{BitPos_t{1}},					// TXDMAEN
										Binary<>{BitPos_t{0}}						// RXDMAEN
)

enum class CR2Field {
	LDMA_TX, /*!< Last DMA transfer for transmission*/
	LDMA_RX, /*!< Last DMA transfer for reception*/
	FRXTH,	 /*!< FIFO reception threshold*/
	DS,			 /*!< Data size*/
	TXEIE,	 /*!< Tx buffer empty interrupt enable*/
	RXNEIE,	 /*!< RX buffer not empty interrupt enable*/
	ERRIE,	 /*!< Error interrupt enable*/
	FRF,		 /*!< Frame format*/
	NSSP,		 /*!< NSS pulse management*/
	SSOE,		 /*!< SS output enable*/
	TXDMAEN, /*!< Tx buffer DMA enable*/
	RXDMAEN, /*!< Rx buffer DMA enable*/
};

template <Port SPI>
static constexpr Register<CR2BitList, CR2Field> CR2{BASE_ADDR(SPI), 0x04U};
/**@}*/

/**
 * @defgroup	SPI2_SR_GROUP		status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList,									 /**/
										StatusBit<2>{BitPos_t{11}},	 // FTLVL
										StatusBit<2>{BitPos_t{9}},	 // FRLVL
										StatusBit<1>{BitPos_t{8}},	 // TIFRFE
										StatusBit<1>{BitPos_t{7}},	 // BSY
										StatusBit<1>{BitPos_t{6}},	 // OVR
										StatusBit<1>{BitPos_t{5}},	 // MODF
										Binary<>{BitPos_t{4}},			 // CRCERR
										StatusBit<1>{BitPos_t{1}},	 // TXE
										StatusBit<1>{BitPos_t{0}}		 // RXNE
)

enum class SRField {
	FTLVL,	/*!< FIFO transmission level*/
	FRLVL,	/*!< FIFO reception level*/
	TIFRFE, /*!< TI frame format error*/
	BSY,		/*!< Busy flag*/
	OVR,		/*!< Overrun flag*/
	MODF,		/*!< Mode fault*/
	CRCERR, /*!< CRC error flag*/
	TXE,		/*!< Transmit buffer empty*/
	RXNE,		/*!< Receive buffer not empty*/
};

template <Port SPI>
static constexpr Register<SRBitList, SRField> SR{BASE_ADDR(SPI), 0x08U};
/**@}*/

/**
 * @defgroup	SPI2_DR_GROUP		data register group
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
 * @defgroup	SPI2_CRCPR_GROUP		CRC polynomial register group
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
 * @defgroup	SPI2_RXCRCR_GROUP		RX CRC register group
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
 * @defgroup	SPI2_TXCRCR_GROUP		TX CRC register group
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

}	 // namespace cpp_stm32::spi::reg
