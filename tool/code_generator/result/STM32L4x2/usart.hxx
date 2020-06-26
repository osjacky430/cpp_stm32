#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::usart::reg {

static constexpr auto BASE_ADDR(Port const& t_usart) {
	switch(t_usart) {
	case Port::USART1:
		return 0x40013800U;
	case Port::USART2:
		return 0x40004400U;
	case Port::UART4:
		return 0x40004c00U;
	case Port::USART3:
		return 0x40004800U;
	case Port::LPUART1:
		return 0x40008000U;
}
	}

/**
 * @defgroup	LPUART1_CR1_GROUP		Control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR1BitList, /**/
					Binary<>{BitPos_t{0}},	// UE
					Binary<>{BitPos_t{1}},	// UESM
					Binary<>{BitPos_t{2}},	// RE
					Binary<>{BitPos_t{3}},	// TE
					Binary<>{BitPos_t{4}},	// IDLEIE
					Binary<>{BitPos_t{5}},	// RXNEIE
					Binary<>{BitPos_t{6}},	// TCIE
					Binary<>{BitPos_t{7}},	// TXEIE
					Binary<>{BitPos_t{8}},	// PEIE
					Binary<>{BitPos_t{9}},	// PS
					Binary<>{BitPos_t{10}},	// PCE
					Binary<>{BitPos_t{11}},	// WAKE
					Bit<2>{BitPos_t{12}},	// M
					Binary<>{BitPos_t{13}},	// MME
					Binary<>{BitPos_t{14}},	// CMIE
					Binary<>{BitPos_t{16}},	// DEDT0
					Binary<>{BitPos_t{17}},	// DEDT1
					Binary<>{BitPos_t{18}},	// DEDT2
					Binary<>{BitPos_t{19}},	// DEDT3
					Binary<>{BitPos_t{20}},	// DEDT4
					Binary<>{BitPos_t{21}},	// DEAT0
					Binary<>{BitPos_t{22}},	// DEAT1
					Binary<>{BitPos_t{23}},	// DEAT2
					Binary<>{BitPos_t{24}},	// DEAT3
					Binary<>{BitPos_t{25}}	// DEAT4
					)

enum class CR1Field {
	UE,		/*!< USART enable*/
	UESM,		/*!< USART enable in Stop mode*/
	RE,		/*!< Receiver enable*/
	TE,		/*!< Transmitter enable*/
	IDLEIE,		/*!< IDLE interrupt enable*/
	RXNEIE,		/*!< RXNE interrupt enable*/
	TCIE,		/*!< Transmission complete interrupt enable*/
	TXEIE,		/*!< interrupt enable*/
	PEIE,		/*!< PE interrupt enable*/
	PS,		/*!< Parity selection*/
	PCE,		/*!< Parity control enable*/
	WAKE,		/*!< Receiver wakeup method*/
	M,		/*!< Word length*/
	MME,		/*!< Mute mode enable*/
	CMIE,		/*!< Character match interrupt enable*/
	DEDT0,		/*!< DEDT0*/
	DEDT1,		/*!< DEDT1*/
	DEDT2,		/*!< DEDT2*/
	DEDT3,		/*!< DEDT3*/
	DEDT4,		/*!< Driver Enable de-assertion time*/
	DEAT0,		/*!< DEAT0*/
	DEAT1,		/*!< DEAT1*/
	DEAT2,		/*!< DEAT2*/
	DEAT3,		/*!< DEAT3*/
	DEAT4,		/*!< Driver Enable assertion time*/
};

template <Port USART>
static constexpr Register<CR1BitList, CR1Field> CR1{BASE_ADDR(USART), 0x00U};
/**@}*/

/**
 * @defgroup	LPUART1_CR2_GROUP		Control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR2BitList, /**/
					Binary<>{BitPos_t{4}},	// ADDM7
					Binary<>{BitPos_t{11}},	// CLKEN
					Bit<2>{BitPos_t{12}},	// STOP
					Binary<>{BitPos_t{15}},	// SWAP
					Binary<>{BitPos_t{16}},	// RXINV
					Binary<>{BitPos_t{17}},	// TXINV
					Binary<>{BitPos_t{18}},	// TAINV
					Binary<>{BitPos_t{19}},	// MSBFIRST
					Bit<2>{BitPos_t{24}}	// ADD0_
					)

enum class CR2Field {
	ADDM7,		/*!< 7-bit Address Detection/4-bit Address Detection*/
	CLKEN,		/*!< Clock enable*/
	STOP,		/*!< STOP bits*/
	SWAP,		/*!< Swap TX/RX pins*/
	RXINV,		/*!< RX pin active level inversion*/
	TXINV,		/*!< TX pin active level inversion*/
	TAINV,		/*!< Binary data inversion*/
	MSBFIRST,		/*!< Most significant bit first*/
	ADD0_,		/*!< Address of the USART node*/
};

template <Port USART>
static constexpr Register<CR2BitList, CR2Field> CR2{BASE_ADDR(USART), 0x04U};
/**@}*/

/**
 * @defgroup	LPUART1_CR3_GROUP		Control register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR3BitList, /**/
					Binary<>{BitPos_t{0}},	// EIE
					Binary<>{BitPos_t{3}},	// HDSEL
					Binary<>{BitPos_t{6}},	// DMAR
					Binary<>{BitPos_t{7}},	// DMAT
					Binary<>{BitPos_t{8}},	// RTSE
					Binary<>{BitPos_t{9}},	// CTSE
					Binary<>{BitPos_t{10}},	// CTSIE
					Binary<>{BitPos_t{12}},	// OVRDIS
					Binary<>{BitPos_t{13}},	// DDRE
					Binary<>{BitPos_t{14}},	// DEM
					Binary<>{BitPos_t{15}},	// DEP
					Bit<2>{BitPos_t{20}},	// WUS
					Binary<>{BitPos_t{22}}	// WUFIE
					)

enum class CR3Field {
	EIE,		/*!< Error interrupt enable*/
	HDSEL,		/*!< Half-duplex selection*/
	DMAR,		/*!< DMA enable receiver*/
	DMAT,		/*!< DMA enable transmitter*/
	RTSE,		/*!< RTS enable*/
	CTSE,		/*!< CTS enable*/
	CTSIE,		/*!< CTS interrupt enable*/
	OVRDIS,		/*!< Overrun Disable*/
	DDRE,		/*!< DMA Disable on Reception Error*/
	DEM,		/*!< Driver enable mode*/
	DEP,		/*!< Driver enable polarity selection*/
	WUS,		/*!< Wakeup from Stop mode interrupt flag selection*/
	WUFIE,		/*!< Wakeup from Stop mode interrupt enable*/
};

template <Port USART>
static constexpr Register<CR3BitList, CR3Field> CR3{BASE_ADDR(USART), 0x08U};
/**@}*/

/**
 * @defgroup	LPUART1_BRR_GROUP		Baud rate register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BRRBitList, /**/
					Bit<20, std::uint32_t>{BitPos_t{0}}	// BRR
					)

enum class BRRField {
	BRR,		/*!< BRR*/
};

template <Port USART>
static constexpr Register<BRRBitList, BRRField> BRR{BASE_ADDR(USART), 0x0cU};
/**@}*/

/**
 * @defgroup	LPUART1_RQR_GROUP		Request register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RQRBitList, /**/
					Binary<>{BitPos_t{1}},	// SBKRQ
					Binary<>{BitPos_t{2}},	// MMRQ
					Binary<>{BitPos_t{3}}	// RXFRQ
					)

enum class RQRField {
	SBKRQ,		/*!< Send break request*/
	MMRQ,		/*!< Mute mode request*/
	RXFRQ,		/*!< Receive data flush request*/
};

template <Port USART>
static constexpr Register<RQRBitList, RQRField> RQR{BASE_ADDR(USART), 0x18U};
/**@}*/

/**
 * @defgroup	LPUART1_ISR_GROUP		Interrupt & status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISRBitList, /**/
					Binary<>{BitPos_t{0}},	// PE
					Binary<>{BitPos_t{1}},	// FE
					Binary<>{BitPos_t{2}},	// NF
					Binary<>{BitPos_t{3}},	// ORE
					Binary<>{BitPos_t{4}},	// IDLE
					Binary<>{BitPos_t{5}},	// RXNE
					Binary<>{BitPos_t{6}},	// TC
					Binary<>{BitPos_t{7}},	// TXE
					Binary<>{BitPos_t{9}},	// CTSIF
					Binary<>{BitPos_t{10}},	// CTS
					Binary<>{BitPos_t{16}},	// BUSY
					Binary<>{BitPos_t{17}},	// CMF
					Binary<>{BitPos_t{18}},	// SBKF
					Binary<>{BitPos_t{19}},	// RWU
					Binary<>{BitPos_t{20}},	// WUF
					Binary<>{BitPos_t{21}},	// TEACK
					Binary<>{BitPos_t{22}}	// REACK
					)

enum class ISRField {
	PE,		/*!< PE*/
	FE,		/*!< FE*/
	NF,		/*!< NF*/
	ORE,		/*!< ORE*/
	IDLE,		/*!< IDLE*/
	RXNE,		/*!< RXNE*/
	TC,		/*!< TC*/
	TXE,		/*!< TXE*/
	CTSIF,		/*!< CTSIF*/
	CTS,		/*!< CTS*/
	BUSY,		/*!< BUSY*/
	CMF,		/*!< CMF*/
	SBKF,		/*!< SBKF*/
	RWU,		/*!< RWU*/
	WUF,		/*!< WUF*/
	TEACK,		/*!< TEACK*/
	REACK,		/*!< REACK*/
};

template <Port USART>
static constexpr Register<ISRBitList, ISRField> ISR{BASE_ADDR(USART), 0x1cU};
/**@}*/

/**
 * @defgroup	LPUART1_ICR_GROUP		Interrupt flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICRBitList, /**/
					Binary<>{BitPos_t{0}},	// PECF
					Binary<>{BitPos_t{1}},	// FECF
					Binary<>{BitPos_t{2}},	// NCF
					Binary<>{BitPos_t{3}},	// ORECF
					Binary<>{BitPos_t{4}},	// IDLECF
					Binary<>{BitPos_t{6}},	// TCCF
					Binary<>{BitPos_t{9}},	// CTSCF
					Binary<>{BitPos_t{17}},	// CMCF
					Binary<>{BitPos_t{20}}	// WUCF
					)

enum class ICRField {
	PECF,		/*!< Parity error clear flag*/
	FECF,		/*!< Framing error clear flag*/
	NCF,		/*!< Noise detected clear flag*/
	ORECF,		/*!< Overrun error clear flag*/
	IDLECF,		/*!< Idle line detected clear flag*/
	TCCF,		/*!< Transmission complete clear flag*/
	CTSCF,		/*!< CTS clear flag*/
	CMCF,		/*!< Character match clear flag*/
	WUCF,		/*!< Wakeup from Stop mode clear flag*/
};

template <Port USART>
static constexpr Register<ICRBitList, ICRField> ICR{BASE_ADDR(USART), 0x20U};
/**@}*/

/**
 * @defgroup	LPUART1_RDR_GROUP		Receive data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RDRBitList, /**/
					Bit<9, std::uint16_t>{BitPos_t{0}}	// RDR
					)

enum class RDRField {
	RDR,		/*!< Receive data value*/
};

template <Port USART>
static constexpr Register<RDRBitList, RDRField> RDR{BASE_ADDR(USART), 0x24U};
/**@}*/

/**
 * @defgroup	LPUART1_TDR_GROUP		Transmit data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TDRBitList, /**/
					Bit<9, std::uint16_t>{BitPos_t{0}}	// TDR
					)

enum class TDRField {
	TDR,		/*!< Transmit data value*/
};

template <Port USART>
static constexpr Register<TDRBitList, TDRField> TDR{BASE_ADDR(USART), 0x28U};
/**@}*/


} // cpp_stm32::usart::reg
