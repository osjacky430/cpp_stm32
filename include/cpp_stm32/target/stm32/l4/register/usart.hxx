#pragma once

#include "cpp_stm32/common/usart.hxx"

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"
#include "cpp_stm32/target/stm32/l4/define/usart.hxx"
#include "cpp_stm32/target/stm32/l4/register/memory_map.hxx"

namespace cpp_stm32::usart::reg {

[[nodiscard]] constexpr auto BASE_ADDR(Port const t_usart_num) {
	switch (t_usart_num) {
		case Port::Usart1:
			return memory_at(PeriphAddr::Apb2Base, 0x3800U);
		case Port::Usart2:
			return memory_at(PeriphAddr::Apb1Base, 0x4400U);
		case Port::Total:
			break;
	}
}

/**
 * @degroup CR1_GROUP		USART Control Register 1 Group
 * @{
 */

SETUP_REGISTER_INFO(CR1BitList,																	/************ Description ************/
										Binary<>{BitPos_t{0}},											// USART Enable
										Binary<>{BitPos_t{1}},											// USART Enable in stop mode
										Binary<>{BitPos_t{2}},											// Receiver Enable
										Binary<>{BitPos_t{3}},											// Transmitter Enable
										Binary<>{BitPos_t{4}},											// Idle Interrupt Enable
										Binary<>{BitPos_t{5}},											// Receiver Not Empty Interrupt Enable
										Binary<>{BitPos_t{6}},											// Transmission Complete Interrupt Enable
										Binary<>{BitPos_t{7}},											// Transmitter Empty Interrupt Enable
										Binary<>{BitPos_t{8}},											// Packet Error Interrupt Enable
										Bit<1, usart::Parity>{BitPos_t{9}},					// Parity Selection
										Binary<>{BitPos_t{10}},											// Parity Control Enable
										Binary<>{BitPos_t{11}},											// Receiver Wakeup Mode
										Binary<>{BitPos_t{12}},											// Word Length (bit 0)
										Binary<>{BitPos_t{13}},											// Mute Mode Enable
										Binary<>{BitPos_t{14}},											// Character match interrupt enable
										Bit<1, usart::OverSampling>{BitPos_t{15}},	// OverSampling
										Bit<5>{BitPos_t{16}},												// Driver Enable De-assertion time
										Bit<5>{BitPos_t{21}},												// Driver Enable assertion time
										Binary<>{BitPos_t{26}},											// Receiver Timeout Interrupt Enable
										Binary<>{BitPos_t{27}},											// End of Block Interrupt Enable
										Binary<>{BitPos_t{28}}											// Word Length (bit 1)
)

enum class CR1Field {
	UE,
	UESM,
	RE,
	TE,
	IdleIE,
	RxNEIE,
	TCIE,
	TxEIE,
	PEIE,
	PS,
	PCE,
	Wake,
	M0,
	MME,
	CMIE,
	Over8,
	DEDT,
	DEAT,
	RToIE,
	EoBIE,
	M1
};

template <Port InputPort>
static constexpr Register<CR1BitList, CR1Field> CR1{BASE_ADDR(InputPort), 0x00U};

/**@}*/

/**
 * @defgroup CR2_GROUP		USART Control Register 2 Group
 * @{
 */

SETUP_REGISTER_INFO(CR2BitList,											/************ Description ************/
										Binary<>{BitPos_t{4}},					// Address Detectio/4-bit Address Detection
										Binary<>{BitPos_t{5}},					// Line Break Detection Length
										Binary<>{BitPos_t{6}},					// Line Break Detection Interrupt Enable
										Binary<>{BitPos_t{8}},					// Last Bit Clock Pause
										Binary<>{BitPos_t{9}},					// Clock Phase
										Binary<>{BitPos_t{10}},					// Clock Polarity
										Binary<>{BitPos_t{11}},					// Clock Enable
										Bit<2, Stopbit>{BitPos_t{12}},	// Stop Bit
										Binary<>{BitPos_t{14}},					// LIN Mode Enable
										Binary<>{BitPos_t{15}},					// Swap TX/RX Pin
										Binary<>{BitPos_t{16}},					// RX pin active level Inversion
										Binary<>{BitPos_t{17}},					// TX pin active level Inversion
										Binary<>{BitPos_t{18}},					// Binary Data Inversion
										Binary<>{BitPos_t{19}},					// Most Significant Bit first
										Binary<>{BitPos_t{20}},					// Auto Baudrate Enable
										Bit<2>{BitPos_t{21}},						// Auto Baudrate Mode
										Binary<>{BitPos_t{23}},					// Receiver Timeout Enable
										Bit<8>{BitPos_t{24}}						// Address of USART node
)

enum class CR2Field {
	ADDM7,
	LBDL,
	LBDIE,
	LbCl,
	CPha,
	CPol,
	ClkEn,
	Stop,
	LINEn,
	Swap,
	RxInv,
	TxInv,
	DataInv,
	MsbFirst,
	ABREn,
	RTOEn,
	ADD
};

template <Port InputPort>
static constexpr Register<CR2BitList, CR2Field> CR2{BASE_ADDR(InputPort), 0x04U};

/**@}*/

/**
 * @defgroup CR3_GROUP		USART Control Register 3 Group
 * @{
 */

SETUP_REGISTER_INFO(CR3BitList,							 /************ Description ************/
										Binary<>{BitPos_t{0}},	 // Error Interrupt Enable
										Binary<>{BitPos_t{1}},	 // IrDA mode Enable
										Binary<>{BitPos_t{2}},	 // IrDA Low Power
										Binary<>{BitPos_t{3}},	 // Half Duplex Selection
										Binary<>{BitPos_t{4}},	 // Smartcard NACK enable
										Binary<>{BitPos_t{5}},	 // Smarcard mode Enable
										Binary<>{BitPos_t{6}},	 // DMA Enable Receiver
										Binary<>{BitPos_t{7}},	 // DMA Enable Transmitter
										Binary<>{BitPos_t{8}},	 // RTS Enable
										Binary<>{BitPos_t{9}},	 // CTS Enable
										Binary<>{BitPos_t{10}},	 // CTS Interrupt Enable
										Binary<>{BitPos_t{11}},	 // One sample bit method enable
										Binary<>{BitPos_t{12}},	 // Overrun Disable
										Binary<>{BitPos_t{13}},	 // DMA Disable on Reception Error
										Binary<>{BitPos_t{14}},	 // Driver Enable Mode
										Binary<>{BitPos_t{15}},	 // Driver Enable Polarity selection
										Bit<3>{BitPos_t{17}},		 // Smartcard auto-retry count
										Bit<2>{BitPos_t{20}},		 // Wakeup from Stop mode interrupt flag selection
										Binary<>{BitPos_t{22}},	 // Wakeup from Stop mode interrupt Enable
										Binary<>{BitPos_t{23}},	 // USART Clock Enable in Stop mode
										Binary<>{BitPos_t{24}}	 // Transmission Complete Before Guard Time Interrupt Enable
)

enum class CR3Field {
	EIE,
	IrEn,
	IrLP,
	HDSel,
	NAck,
	SCEN,
	DMAR,
	DMAT,
	RTSE,
	CTSE,
	CTSIE,
	OneBit,
	OvrDis,
	DDRE,
	DEM,
	DEP,
	SCARCnt,
	WuS,
	WuSIE,
	UCESm,
	TCBGTIE
};

template <Port InputPort>
static constexpr Register<CR3BitList, CR3Field> CR3{BASE_ADDR(InputPort), 0x08U};

/**@}*/

/**
 * @defgroup BRR_GROUP		Usart Baud Rate Register Group
 * @{
 */

SETUP_REGISTER_INFO(BRRBitList,													 /************ Description ************/
										Bit<16, std::uint16_t>{BitPos_t{0}}	 // Baud Rate Register
)

enum class BRRField { BRR };

template <Port InputPort>
static constexpr Register<BRRBitList, BRRField> BRR{BASE_ADDR(InputPort), 0x0CU};
/**@}*/

/**
 * @defgroup ISR_GROUP		USART Interrupt and Status Register Group
 * @{
 */

SETUP_REGISTER_INFO(ISRBitList,									/************ Description ************/
										StatusBit<1>{BitPos_t{0}},	// Parity Error
										StatusBit<1>{BitPos_t{1}},	// Framing Error
										StatusBit<1>{BitPos_t{2}},	// start bit Noise detection Flag
										StatusBit<1>{BitPos_t{3}},	// Overrun Error
										StatusBit<1>{BitPos_t{4}},	// Idle line detected
										Binary<>{BitPos_t{5}},			// Read data register not empty
										Binary<>{BitPos_t{6}},			// Transmission complete
										StatusBit<1>{BitPos_t{7}},	// Transmit Data Register empty
										Binary<>{BitPos_t{8}},			// LIN Break detection flag
										Binary<>{BitPos_t{9}},			// CTS Interrupt flag
										Binary<>{BitPos_t{10}},			// CTS flag
										Binary<>{BitPos_t{11}},			// Receiver Timeout Flag
										Binary<>{BitPos_t{12}},			// End Of Block Flag
										Binary<>{BitPos_t{14}},			// Auto Baud Rate Error
										Binary<>{BitPos_t{15}},			// Auto Baud Rate Flag
										Binary<>{BitPos_t{16}},			// Busy flag
										Binary<>{BitPos_t{17}},			// Character Match Flag
										Binary<>{BitPos_t{18}},			// Send Break Flag
										Binary<>{BitPos_t{19}},			// Receiver WakeUp from mute mode
										Binary<>{BitPos_t{20}},			// WakeUp from stop mode Flag
										Binary<>{BitPos_t{21}},			// Transmit Enable ACKnowledge flag
										Binary<>{BitPos_t{22}},			// Receive Enable ACKnowledge flag
										Binary<>{BitPos_t{25}}			// Transmission Complete Before Guard Time completion
)

enum class ISRField {
	PE,
	FE,
	NF,
	OrE,
	Idle,
	RxNE,
	TC,
	TxE,
	LBD,
	CTSIF,
	CTS,
	RTOF,
	EoBF,
	ABRE,
	ABRF,
	Busy,
	CMF,
	SBKF,
	RWu,
	WuF,
	TEAck,
	REAck,
	TCBGT
};

template <Port InputPort>
static constexpr Register<ISRBitList, ISRField> ISR{BASE_ADDR(InputPort), 0x1CU};
/**@}*/

/**
 * @defgroup ICR_GROUP		USART Interrupt Clear Register Group
 * @{
 */

SETUP_REGISTER_INFO(ICRBitList,															 /************ Description ************/
										Binary<BitMod::RdClrWr1>{BitPos_t{0}},	 // Parity Error Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{1}},	 // Framing Error Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{2}},	 // Noise detected Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{3}},	 // OverRun Error Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{4}},	 // IDLE line detected Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{6}},	 // Transmission Complete Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{7}},	 // Transmission Complete Before Guard Time Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{8}},	 // LIN Break Detection Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{9}},	 // CTS Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{11}},	 // Receiver TimeOut Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{12}},	 // End Of Block Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{17}},	 // Character Match Clear Flag
										Binary<BitMod::RdClrWr1>{BitPos_t{20}}	 // WakeUp from stop mode Clear Flag
)

enum class ICRField { PECF, FECF, NCF, ORECF, IdleCF, TCCF, TCBGTCF, LBDCF, CTSCF, RTOCF, EOBCF, CMCF, WUCF };

template <Port InputPort>
static constexpr Register<ICRBitList, ICRField> ICR{BASE_ADDR(InputPort), 0x20U};
/**@}*/

/**
 * @defgroup RDR_GROUP		USART Data Register Group
 * @{
 */
SETUP_REGISTER_INFO(RDRBitList,																				 /************ Description ************/
										Bit<8, std::uint8_t, BitMod::RdOnly>{BitPos_t{0}}	 // Receive data value
)

enum class RDRField { RDr };

template <Port InputPort>
static constexpr Register<RDRBitList, RDRField> RDR{BASE_ADDR(InputPort), 0x24U};

/**@}*/

/**
 * @defgroup TDR_GROUP		USART Data Register Group
 * @{
 */
SETUP_REGISTER_INFO(TDRBitList,					 /************ Description ************/
										Bit<8>{BitPos_t{0}}	 // Transmit data value
)

enum class TDRField { TDr };

template <Port InputPort>
static constexpr Register<TDRBitList, TDRField> TDR{BASE_ADDR(InputPort), 0x28U};

/**@}*/

}	 // namespace cpp_stm32::usart::reg
