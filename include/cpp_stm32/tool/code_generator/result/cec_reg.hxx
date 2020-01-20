#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::cec::reg {

static constexpr auto BASE_ADDR = 0x40006c00U;

/**
 * @defgroup	CEC_CR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{0}},	// CECEN
					Binary<>{BitPos_t{1}},	// TXSOM
					Binary<>{BitPos_t{2}}	// TXEOM
					)

enum class CRField {
	CECEN,		/*!< CEC Enable*/
	TXSOM,		/*!< Tx start of message*/
	TXEOM,		/*!< Tx End Of Message*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	CEC_CFGR_GROUP		configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CFGRBitList, /**/
					Binary<>{BitPos_t{31}},	// LSTN
					Bit<15, std::uint16_t>{BitPos_t{16}},	// OAR
					Binary<>{BitPos_t{8}},	// SFTOP
					Binary<>{BitPos_t{7}},	// BRDNOGEN
					Binary<>{BitPos_t{6}},	// LBPEGEN
					Binary<>{BitPos_t{5}},	// BREGEN
					Binary<>{BitPos_t{4}},	// BRESTP
					Binary<>{BitPos_t{3}},	// RXTOL
					Bit<3>{BitPos_t{0}}	// SFT
					)

enum class CFGRField {
	LSTN,		/*!< Listen mode*/
	OAR,		/*!< Own addresses configuration*/
	SFTOP,		/*!< SFT Option Bit*/
	BRDNOGEN,		/*!< Avoid Error-Bit Generation in Broadcast*/
	LBPEGEN,		/*!< Generate Error-Bit on Long Bit Period Error*/
	BREGEN,		/*!< Generate error-bit on bit rising error*/
	BRESTP,		/*!< Rx-stop on bit rising error*/
	RXTOL,		/*!< Rx-Tolerance*/
	SFT,		/*!< Signal Free Time*/
};

static constexpr Register<CFGRBitList, CFGRField> CFGR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	CEC_TXDR_GROUP		Tx data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TXDRBitList, /**/
					Bit<8>{BitPos_t{0}}	// TXD
					)

enum class TXDRField {
	TXD,		/*!< Tx Data register*/
};

static constexpr Register<TXDRBitList, TXDRField> TXDR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	CEC_RXDR_GROUP		Rx Data Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RXDRBitList, /**/
					Bit<8>{BitPos_t{0}}	// RXDR
					)

enum class RXDRField {
	RXDR,		/*!< CEC Rx Data Register*/
};

static constexpr Register<RXDRBitList, RXDRField> RXDR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	CEC_ISR_GROUP		Interrupt and Status Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISRBitList, /**/
					Binary<>{BitPos_t{0}},	// RXBR
					Binary<>{BitPos_t{1}},	// RXEND
					Binary<>{BitPos_t{2}},	// RXOVR
					Binary<>{BitPos_t{3}},	// BRE
					Binary<>{BitPos_t{4}},	// SBPE
					Binary<>{BitPos_t{5}},	// LBPE
					Binary<>{BitPos_t{6}},	// RXACKE
					Binary<>{BitPos_t{7}},	// ARBLST
					Binary<>{BitPos_t{8}},	// TXBR
					Binary<>{BitPos_t{9}},	// TXEND
					Binary<>{BitPos_t{10}},	// TXUDR
					Binary<>{BitPos_t{11}},	// TXERR
					Binary<>{BitPos_t{12}}	// TXACKE
					)

enum class ISRField {
	RXBR,		/*!< Rx-Byte Received*/
	RXEND,		/*!< End Of Reception*/
	RXOVR,		/*!< Rx-Overrun*/
	BRE,		/*!< Rx-Bit rising error*/
	SBPE,		/*!< Rx-Short Bit period error*/
	LBPE,		/*!< Rx-Long Bit Period Error*/
	RXACKE,		/*!< Rx-Missing Acknowledge*/
	ARBLST,		/*!< Arbitration Lost*/
	TXBR,		/*!< Tx-Byte Request*/
	TXEND,		/*!< End of Transmission*/
	TXUDR,		/*!< Tx-Buffer Underrun*/
	TXERR,		/*!< Tx-Error*/
	TXACKE,		/*!< Tx-Missing acknowledge error*/
};

static constexpr Register<ISRBitList, ISRField> ISR{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	CEC_IER_GROUP		interrupt enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IERBitList, /**/
					Binary<>{BitPos_t{0}},	// RXBRIE
					Binary<>{BitPos_t{1}},	// RXENDIE
					Binary<>{BitPos_t{2}},	// RXOVRIE
					Binary<>{BitPos_t{3}},	// BREIE
					Binary<>{BitPos_t{4}},	// SBPEIE
					Binary<>{BitPos_t{5}},	// LBPEIE
					Binary<>{BitPos_t{6}},	// RXACKIE
					Binary<>{BitPos_t{7}},	// ARBLSTIE
					Binary<>{BitPos_t{8}},	// TXBRIE
					Binary<>{BitPos_t{9}},	// TXENDIE
					Binary<>{BitPos_t{10}},	// TXUDRIE
					Binary<>{BitPos_t{11}},	// TXERRIE
					Binary<>{BitPos_t{12}}	// TXACKIE
					)

enum class IERField {
	RXBRIE,		/*!< Rx-Byte Received Interrupt Enable*/
	RXENDIE,		/*!< End Of Reception Interrupt Enable*/
	RXOVRIE,		/*!< Rx-Buffer Overrun Interrupt Enable*/
	BREIE,		/*!< Bit Rising Error Interrupt Enable*/
	SBPEIE,		/*!< Short Bit Period Error Interrupt Enable*/
	LBPEIE,		/*!< Long Bit Period Error Interrupt Enable*/
	RXACKIE,		/*!< Rx-Missing Acknowledge Error Interrupt Enable*/
	ARBLSTIE,		/*!< Arbitration Lost Interrupt Enable*/
	TXBRIE,		/*!< Tx-Byte Request Interrupt Enable*/
	TXENDIE,		/*!< Tx-End of message interrupt enable*/
	TXUDRIE,		/*!< Tx-Underrun interrupt enable*/
	TXERRIE,		/*!< Tx-Error Interrupt Enable*/
	TXACKIE,		/*!< Tx-Missing Acknowledge Error Interrupt Enable*/
};

static constexpr Register<IERBitList, IERField> IER{BASE_ADDR, 0x14U};
/**@}*/


} // cpp_stm32::cec::reg
