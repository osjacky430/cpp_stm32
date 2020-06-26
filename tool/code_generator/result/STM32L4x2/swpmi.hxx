#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::swpmi::reg {

static constexpr auto BASE_ADDR = 0x40008800U;

/**
 * @defgroup	SWPMI1_CR_GROUP		SWPMI Configuration/Control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{10}},	// DEACT
					Binary<>{BitPos_t{5}},	// SWPME
					Binary<>{BitPos_t{4}},	// LPBK
					Binary<>{BitPos_t{3}},	// TXMODE
					Binary<>{BitPos_t{2}},	// RXMODE
					Binary<>{BitPos_t{1}},	// TXDMA
					Binary<>{BitPos_t{0}}	// RXDMA
					)

enum class CRField {
	DEACT,		/*!< Single wire protocol master interface deactivate*/
	SWPME,		/*!< Single wire protocol master interface enable*/
	LPBK,		/*!< Loopback mode enable*/
	TXMODE,		/*!< Transmission buffering mode*/
	RXMODE,		/*!< Reception buffering mode*/
	TXDMA,		/*!< Transmission DMA enable*/
	RXDMA,		/*!< Reception DMA enable*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	SWPMI1_BRR_GROUP		SWPMI Bitrate register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BRRBitList, /**/
					Bit<6>{BitPos_t{0}}	// BR
					)

enum class BRRField {
	BR,		/*!< Bitrate prescaler*/
};

static constexpr Register<BRRBitList, BRRField> BRR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	SWPMI1_ISR_GROUP		SWPMI Interrupt and Status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISRBitList, /**/
					Binary<>{BitPos_t{10}},	// DEACTF
					Binary<>{BitPos_t{9}},	// SUSP
					Binary<>{BitPos_t{8}},	// SRF
					Binary<>{BitPos_t{7}},	// TCF
					Binary<>{BitPos_t{6}},	// TXE
					Binary<>{BitPos_t{5}},	// RXNE
					Binary<>{BitPos_t{4}},	// TXUNRF
					Binary<>{BitPos_t{3}},	// RXOVRF
					Binary<>{BitPos_t{2}},	// RXBERF
					Binary<>{BitPos_t{1}},	// TXBEF
					Binary<>{BitPos_t{0}}	// RXBFF
					)

enum class ISRField {
	DEACTF,		/*!< DEACTIVATED flag*/
	SUSP,		/*!< SUSPEND flag*/
	SRF,		/*!< Slave resume flag*/
	TCF,		/*!< Transfer complete flag*/
	TXE,		/*!< Transmit data register empty*/
	RXNE,		/*!< Receive data register not empty*/
	TXUNRF,		/*!< Transmit underrun error flag*/
	RXOVRF,		/*!< Receive overrun error flag*/
	RXBERF,		/*!< Receive CRC error flag*/
	TXBEF,		/*!< Transmit buffer empty flag*/
	RXBFF,		/*!< Receive buffer full flag*/
};

static constexpr Register<ISRBitList, ISRField> ISR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	SWPMI1_ICR_GROUP		SWPMI Interrupt Flag Clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICRBitList, /**/
					Binary<>{BitPos_t{8}},	// CSRF
					Binary<>{BitPos_t{7}},	// CTCF
					Binary<>{BitPos_t{4}},	// CTXUNRF
					Binary<>{BitPos_t{3}},	// CRXOVRF
					Binary<>{BitPos_t{2}},	// CRXBERF
					Binary<>{BitPos_t{1}},	// CTXBEF
					Binary<>{BitPos_t{0}}	// CRXBFF
					)

enum class ICRField {
	CSRF,		/*!< Clear slave resume flag*/
	CTCF,		/*!< Clear transfer complete flag*/
	CTXUNRF,		/*!< Clear transmit underrun error flag*/
	CRXOVRF,		/*!< Clear receive overrun error flag*/
	CRXBERF,		/*!< Clear receive CRC error flag*/
	CTXBEF,		/*!< Clear transmit buffer empty flag*/
	CRXBFF,		/*!< Clear receive buffer full flag*/
};

static constexpr Register<ICRBitList, ICRField> ICR{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	SWPMI1_IER_GROUP		SWPMI Interrupt Enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IERBitList, /**/
					Binary<>{BitPos_t{8}},	// SRIE
					Binary<>{BitPos_t{7}},	// TCIE
					Binary<>{BitPos_t{6}},	// TIE
					Binary<>{BitPos_t{5}},	// RIE
					Binary<>{BitPos_t{4}},	// TXUNRIE
					Binary<>{BitPos_t{3}},	// RXOVRIE
					Binary<>{BitPos_t{2}},	// RXBERIE
					Binary<>{BitPos_t{1}},	// TXBEIE
					Binary<>{BitPos_t{0}}	// RXBFIE
					)

enum class IERField {
	SRIE,		/*!< Slave resume interrupt enable*/
	TCIE,		/*!< Transmit complete interrupt enable*/
	TIE,		/*!< Transmit interrupt enable*/
	RIE,		/*!< Receive interrupt enable*/
	TXUNRIE,		/*!< Transmit underrun error interrupt enable*/
	RXOVRIE,		/*!< Receive overrun error interrupt enable*/
	RXBERIE,		/*!< Receive CRC error interrupt enable*/
	TXBEIE,		/*!< Transmit buffer empty interrupt enable*/
	RXBFIE,		/*!< Receive buffer full interrupt enable*/
};

static constexpr Register<IERBitList, IERField> IER{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	SWPMI1_RFL_GROUP		SWPMI Receive Frame Length register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RFLBitList, /**/
					Bit<5>{BitPos_t{0}}	// RFL
					)

enum class RFLField {
	RFL,		/*!< Receive frame length*/
};

static constexpr Register<RFLBitList, RFLField> RFL{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	SWPMI1_TDR_GROUP		SWPMI Transmit data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TDRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// TD
					)

enum class TDRField {
	TD,		/*!< Transmit data*/
};

static constexpr Register<TDRBitList, TDRField> TDR{BASE_ADDR, 0x1cU};
/**@}*/

/**
 * @defgroup	SWPMI1_RDR_GROUP		SWPMI Receive data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RDRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// RD
					)

enum class RDRField {
	RD,		/*!< received data*/
};

static constexpr Register<RDRBitList, RDRField> RDR{BASE_ADDR, 0x20U};
/**@}*/


} // cpp_stm32::swpmi::reg
