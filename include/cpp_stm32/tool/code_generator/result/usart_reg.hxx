#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::usart::reg {

static constexpr auto BASE_ADDR(Port const& t_usart) {
	case Port::USART6:
		return 0x40011400U;
	case Port::USART1:
		return 0x40011000U;
	case Port::USART2:
		return 0x40004400U;
	case Port::USART3:
		return 0x40004800U;
	case Port::UART4:
		return 0x40004c00U;
	case Port::UART5:
		return 0x40005000U;
}

/**
 * @defgroup	UART5_SR_GROUP		Status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					StatusBit<1>{BitPos_t{0}},	// PE
					StatusBit<1>{BitPos_t{1}},	// FE
					StatusBit<1>{BitPos_t{2}},	// NF
					StatusBit<1>{BitPos_t{3}},	// ORE
					StatusBit<1>{BitPos_t{4}},	// IDLE
					Binary<>{BitPos_t{5}},	// RXNE
					Binary<>{BitPos_t{6}},	// TC
					StatusBit<1>{BitPos_t{7}},	// TXE
					Binary<>{BitPos_t{8}}	// LBD
					)

enum class SRField {
	PE,		/*!< Parity error*/
	FE,		/*!< Framing error*/
	NF,		/*!< Noise detected flag*/
	ORE,		/*!< Overrun error*/
	IDLE,		/*!< IDLE line detected*/
	RXNE,		/*!< Read data register not empty*/
	TC,		/*!< Transmission complete*/
	TXE,		/*!< Transmit data register empty*/
	LBD,		/*!< LIN break detection flag*/
};

template <Port USART>
static constexpr Register<SRBitList, SRField> SR{BASE_ADDR(USART), 0x00U};
/**@}*/

/**
 * @defgroup	UART5_DR_GROUP		Data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DRBitList, /**/
					Bit<9, std::uint16_t>{BitPos_t{0}}	// DR
					)

enum class DRField {
	DR,		/*!< Data value*/
};

template <Port USART>
static constexpr Register<DRBitList, DRField> DR{BASE_ADDR(USART), 0x04U};
/**@}*/

/**
 * @defgroup	UART5_BRR_GROUP		Baud rate register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BRRBitList, /**/
					Bit<4>{BitPos_t{0}},	// DIV_Fraction
					Bit<12, std::uint16_t>{BitPos_t{4}}	// DIV_Mantissa
					)

enum class BRRField {
	DIV_Fraction,		/*!< fraction of USARTDIV*/
	DIV_Mantissa,		/*!< mantissa of USARTDIV*/
};

template <Port USART>
static constexpr Register<BRRBitList, BRRField> BRR{BASE_ADDR(USART), 0x08U};
/**@}*/

/**
 * @defgroup	UART5_CR1_GROUP		Control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR1BitList, /**/
					Binary<>{BitPos_t{0}},	// SBK
					Binary<>{BitPos_t{1}},	// RWU
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
					Binary<>{BitPos_t{12}},	// M
					Binary<>{BitPos_t{13}},	// UE
					Binary<>{BitPos_t{15}}	// OVER8
					)

enum class CR1Field {
	SBK,		/*!< Send break*/
	RWU,		/*!< Receiver wakeup*/
	RE,		/*!< Receiver enable*/
	TE,		/*!< Transmitter enable*/
	IDLEIE,		/*!< IDLE interrupt enable*/
	RXNEIE,		/*!< RXNE interrupt enable*/
	TCIE,		/*!< Transmission complete interrupt enable*/
	TXEIE,		/*!< TXE interrupt enable*/
	PEIE,		/*!< PE interrupt enable*/
	PS,		/*!< Parity selection*/
	PCE,		/*!< Parity control enable*/
	WAKE,		/*!< Wakeup method*/
	M,		/*!< Word length*/
	UE,		/*!< USART enable*/
	OVER8,		/*!< Oversampling mode*/
};

template <Port USART>
static constexpr Register<CR1BitList, CR1Field> CR1{BASE_ADDR(USART), 0x0cU};
/**@}*/

/**
 * @defgroup	UART5_CR2_GROUP		Control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR2BitList, /**/
					Bit<4>{BitPos_t{0}},	// ADD
					Binary<>{BitPos_t{5}},	// LBDL
					Binary<>{BitPos_t{6}},	// LBDIE
					Bit<2>{BitPos_t{12}},	// STOP
					Binary<>{BitPos_t{14}}	// LINEN
					)

enum class CR2Field {
	ADD,		/*!< Address of the USART node*/
	LBDL,		/*!< lin break detection length*/
	LBDIE,		/*!< LIN break detection interrupt enable*/
	STOP,		/*!< STOP bits*/
	LINEN,		/*!< LIN mode enable*/
};

template <Port USART>
static constexpr Register<CR2BitList, CR2Field> CR2{BASE_ADDR(USART), 0x10U};
/**@}*/

/**
 * @defgroup	UART5_CR3_GROUP		Control register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR3BitList, /**/
					Binary<>{BitPos_t{0}},	// EIE
					Binary<>{BitPos_t{1}},	// IREN
					Binary<>{BitPos_t{2}},	// IRLP
					Binary<>{BitPos_t{3}},	// HDSEL
					Binary<>{BitPos_t{6}},	// DMAR
					Binary<>{BitPos_t{7}},	// DMAT
					Binary<>{BitPos_t{11}}	// ONEBIT
					)

enum class CR3Field {
	EIE,		/*!< Error interrupt enable*/
	IREN,		/*!< IrDA mode enable*/
	IRLP,		/*!< IrDA low-power*/
	HDSEL,		/*!< Half-duplex selection*/
	DMAR,		/*!< DMA enable receiver*/
	DMAT,		/*!< DMA enable transmitter*/
	ONEBIT,		/*!< One sample bit method enable*/
};

template <Port USART>
static constexpr Register<CR3BitList, CR3Field> CR3{BASE_ADDR(USART), 0x14U};
/**@}*/


} // cpp_stm32::usart::reg
