#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::i2c::reg {

static constexpr auto BASE_ADDR(Port const& t_i2c) {
	switch(t_i2c) {
	case Port::I2C1:
		return 0x40005400U;
	case Port::I2C3:
		return 0x40005c00U;
	case Port::I2C2:
		return 0x40005800U;
	case Port::I2C4:
		return 0x40008400U;
}
	}

/**
 * @defgroup	I2C4_CR1_GROUP		Control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR1BitList, /**/
					Binary<>{BitPos_t{23}},	// PECEN
					Binary<>{BitPos_t{22}},	// ALERTEN
					Binary<>{BitPos_t{21}},	// SMBDEN
					Binary<>{BitPos_t{20}},	// SMBHEN
					Binary<>{BitPos_t{19}},	// GCEN
					Binary<>{BitPos_t{18}},	// WUPEN
					Binary<>{BitPos_t{17}},	// NOSTRETCH
					Binary<>{BitPos_t{16}},	// SBC
					Binary<>{BitPos_t{15}},	// RXDMAEN
					Binary<>{BitPos_t{14}},	// TXDMAEN
					Binary<>{BitPos_t{12}},	// ANFOFF
					Bit<4>{BitPos_t{8}},	// DNF
					Binary<>{BitPos_t{7}},	// ERRIE
					Binary<>{BitPos_t{6}},	// TCIE
					Binary<>{BitPos_t{5}},	// STOPIE
					Binary<>{BitPos_t{4}},	// NACKIE
					Binary<>{BitPos_t{3}},	// ADDRIE
					Binary<>{BitPos_t{2}},	// RXIE
					Binary<>{BitPos_t{1}},	// TXIE
					Binary<>{BitPos_t{0}}	// PE
					)

enum class CR1Field {
	PECEN,		/*!< PEC enable*/
	ALERTEN,		/*!< SMBUS alert enable*/
	SMBDEN,		/*!< SMBus Device Default address enable*/
	SMBHEN,		/*!< SMBus Host address enable*/
	GCEN,		/*!< General call enable*/
	WUPEN,		/*!< Wakeup from STOP enable*/
	NOSTRETCH,		/*!< Clock stretching disable*/
	SBC,		/*!< Slave byte control*/
	RXDMAEN,		/*!< DMA reception requests enable*/
	TXDMAEN,		/*!< DMA transmission requests enable*/
	ANFOFF,		/*!< Analog noise filter OFF*/
	DNF,		/*!< Digital noise filter*/
	ERRIE,		/*!< Error interrupts enable*/
	TCIE,		/*!< Transfer Complete interrupt enable*/
	STOPIE,		/*!< STOP detection Interrupt enable*/
	NACKIE,		/*!< Not acknowledge received interrupt enable*/
	ADDRIE,		/*!< Address match interrupt enable (slave only)*/
	RXIE,		/*!< RX Interrupt enable*/
	TXIE,		/*!< TX Interrupt enable*/
	PE,		/*!< Peripheral enable*/
};

template <Port I2C>
static constexpr Register<CR1BitList, CR1Field> CR1{BASE_ADDR(I2C), 0x00U};
/**@}*/

/**
 * @defgroup	I2C4_CR2_GROUP		Control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR2BitList, /**/
					Bit<10, std::uint16_t>{BitPos_t{0}},	// SADD
					Binary<>{BitPos_t{10}},	// RD_WRN
					Binary<>{BitPos_t{11}},	// ADD10
					Binary<>{BitPos_t{12}},	// HEAD10R
					Binary<>{BitPos_t{13}},	// START
					Binary<>{BitPos_t{14}},	// STOP
					Binary<>{BitPos_t{15}},	// NACK
					Bit<8>{BitPos_t{16}},	// NBYTES
					Binary<>{BitPos_t{24}},	// RELOAD
					Binary<>{BitPos_t{25}},	// AUTOEND
					Binary<>{BitPos_t{26}}	// PECBYTE
					)

enum class CR2Field {
	SADD,		/*!< Slave address bit (master mode)*/
	RD_WRN,		/*!< Transfer direction (master mode)*/
	ADD10,		/*!< 10-bit addressing mode (master mode)*/
	HEAD10R,		/*!< 10-bit address header only read direction (master receiver mode)*/
	START,		/*!< Start generation*/
	STOP,		/*!< Stop generation (master mode)*/
	NACK,		/*!< NACK generation (slave mode)*/
	NBYTES,		/*!< Number of bytes*/
	RELOAD,		/*!< NBYTES reload mode*/
	AUTOEND,		/*!< Automatic end mode (master mode)*/
	PECBYTE,		/*!< Packet error checking byte*/
};

template <Port I2C>
static constexpr Register<CR2BitList, CR2Field> CR2{BASE_ADDR(I2C), 0x04U};
/**@}*/

/**
 * @defgroup	I2C4_OAR1_GROUP		Own address register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(OAR1BitList, /**/
					Binary<>{BitPos_t{15}},	// OA1EN
					Binary<>{BitPos_t{10}},	// OA1MODE
					Bit<10, std::uint16_t>{BitPos_t{0}}	// OA1
					)

enum class OAR1Field {
	OA1EN,		/*!< Own Address 1 enable*/
	OA1MODE,		/*!< Own Address 1 10-bit mode*/
	OA1,		/*!< Interface address*/
};

template <Port I2C>
static constexpr Register<OAR1BitList, OAR1Field> OAR1{BASE_ADDR(I2C), 0x08U};
/**@}*/

/**
 * @defgroup	I2C4_OAR2_GROUP		Own address register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(OAR2BitList, /**/
					Binary<>{BitPos_t{15}},	// OA2EN
					Bit<3>{BitPos_t{8}},	// OA2MSK
					Bit<7>{BitPos_t{1}}	// OA2
					)

enum class OAR2Field {
	OA2EN,		/*!< Own Address 2 enable*/
	OA2MSK,		/*!< Own Address 2 masks*/
	OA2,		/*!< Interface address*/
};

template <Port I2C>
static constexpr Register<OAR2BitList, OAR2Field> OAR2{BASE_ADDR(I2C), 0x0cU};
/**@}*/

/**
 * @defgroup	I2C4_TIMINGR_GROUP		Timing register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TIMINGRBitList, /**/
					Bit<4>{BitPos_t{28}},	// PRESC
					Bit<4>{BitPos_t{20}},	// SCLDEL
					Bit<4>{BitPos_t{16}},	// SDADEL
					Bit<8>{BitPos_t{8}},	// SCLH
					Bit<8>{BitPos_t{0}}	// SCLL
					)

enum class TIMINGRField {
	PRESC,		/*!< Timing prescaler*/
	SCLDEL,		/*!< Data setup time*/
	SDADEL,		/*!< Data hold time*/
	SCLH,		/*!< SCL high period (master mode)*/
	SCLL,		/*!< SCL low period (master mode)*/
};

template <Port I2C>
static constexpr Register<TIMINGRBitList, TIMINGRField> TIMINGR{BASE_ADDR(I2C), 0x10U};
/**@}*/

/**
 * @defgroup	I2C4_TIMEOUTR_GROUP		Status register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(TIMEOUTRBitList, /**/
					Binary<>{BitPos_t{31}},	// TEXTEN
					Bit<12, std::uint16_t>{BitPos_t{16}},	// TIMEOUTB
					Binary<>{BitPos_t{15}},	// TIMOUTEN
					Binary<>{BitPos_t{12}},	// TIDLE
					Bit<12, std::uint16_t>{BitPos_t{0}}	// TIMEOUTA
					)

enum class TIMEOUTRField {
	TEXTEN,		/*!< Extended clock timeout enable*/
	TIMEOUTB,		/*!< Bus timeout B*/
	TIMOUTEN,		/*!< Clock timeout enable*/
	TIDLE,		/*!< Idle clock timeout detection*/
	TIMEOUTA,		/*!< Bus timeout A*/
};

template <Port I2C>
static constexpr Register<TIMEOUTRBitList, TIMEOUTRField> TIMEOUTR{BASE_ADDR(I2C), 0x14U};
/**@}*/

/**
 * @defgroup	I2C4_ISR_GROUP		Interrupt and Status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISRBitList, /**/
					Binary<>{BitPos_t{0}},	// TXE
					Binary<>{BitPos_t{1}},	// TXIS
					StatusBit<1>{BitPos_t{2}},	// RXNE
					StatusBit<1>{BitPos_t{3}},	// ADDR
					StatusBit<1>{BitPos_t{4}},	// NACKF
					StatusBit<1>{BitPos_t{5}},	// STOPF
					StatusBit<1>{BitPos_t{6}},	// TC
					StatusBit<1>{BitPos_t{7}},	// TCR
					StatusBit<1>{BitPos_t{8}},	// BERR
					StatusBit<1>{BitPos_t{9}},	// ARLO
					StatusBit<1>{BitPos_t{10}},	// OVR
					StatusBit<1>{BitPos_t{11}},	// PECERR
					StatusBit<1>{BitPos_t{12}},	// TIMEOUT
					StatusBit<1>{BitPos_t{13}},	// ALERT
					StatusBit<1>{BitPos_t{15}},	// BUSY
					StatusBit<1>{BitPos_t{16}},	// DIR
					StatusBit<7>{BitPos_t{17}}	// ADDCODE
					)

enum class ISRField {
	TXE,		/*!< Transmit data register empty (transmitters)*/
	TXIS,		/*!< Transmit interrupt status (transmitters)*/
	RXNE,		/*!< Receive data register not empty (receivers)*/
	ADDR,		/*!< Address matched (slave mode)*/
	NACKF,		/*!< Not acknowledge received flag*/
	STOPF,		/*!< Stop detection flag*/
	TC,		/*!< Transfer Complete (master mode)*/
	TCR,		/*!< Transfer Complete Reload*/
	BERR,		/*!< Bus error*/
	ARLO,		/*!< Arbitration lost*/
	OVR,		/*!< Overrun/Underrun (slave mode)*/
	PECERR,		/*!< PEC Error in reception*/
	TIMEOUT,		/*!< Timeout or t_low detection flag*/
	ALERT,		/*!< SMBus alert*/
	BUSY,		/*!< Bus busy*/
	DIR,		/*!< Transfer direction (Slave mode)*/
	ADDCODE,		/*!< Address match code (Slave mode)*/
};

template <Port I2C>
static constexpr Register<ISRBitList, ISRField> ISR{BASE_ADDR(I2C), 0x18U};
/**@}*/

/**
 * @defgroup	I2C4_ICR_GROUP		Interrupt clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICRBitList, /**/
					Binary<>{BitPos_t{3}},	// ADDRCF
					Binary<>{BitPos_t{4}},	// NACKCF
					Binary<>{BitPos_t{5}},	// STOPCF
					Binary<>{BitPos_t{8}},	// BERRCF
					Binary<>{BitPos_t{9}},	// ARLOCF
					Binary<>{BitPos_t{10}},	// OVRCF
					Binary<>{BitPos_t{11}},	// PECCF
					Binary<>{BitPos_t{12}},	// TIMOUTCF
					Binary<>{BitPos_t{13}}	// ALERTCF
					)

enum class ICRField {
	ADDRCF,		/*!< Address Matched flag clear*/
	NACKCF,		/*!< Not Acknowledge flag clear*/
	STOPCF,		/*!< Stop detection flag clear*/
	BERRCF,		/*!< Bus error flag clear*/
	ARLOCF,		/*!< Arbitration lost flag clear*/
	OVRCF,		/*!< Overrun/Underrun flag clear*/
	PECCF,		/*!< PEC Error flag clear*/
	TIMOUTCF,		/*!< Timeout detection flag clear*/
	ALERTCF,		/*!< Alert flag clear*/
};

template <Port I2C>
static constexpr Register<ICRBitList, ICRField> ICR{BASE_ADDR(I2C), 0x1cU};
/**@}*/

/**
 * @defgroup	I2C4_PECR_GROUP		PEC register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PECRBitList, /**/
					Bit<8>{BitPos_t{0}}	// PEC
					)

enum class PECRField {
	PEC,		/*!< Packet error checking register*/
};

template <Port I2C>
static constexpr Register<PECRBitList, PECRField> PECR{BASE_ADDR(I2C), 0x20U};
/**@}*/

/**
 * @defgroup	I2C4_RXDR_GROUP		Receive data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RXDRBitList, /**/
					Bit<8>{BitPos_t{0}}	// RXDATA
					)

enum class RXDRField {
	RXDATA,		/*!< 8-bit receive data*/
};

template <Port I2C>
static constexpr Register<RXDRBitList, RXDRField> RXDR{BASE_ADDR(I2C), 0x24U};
/**@}*/

/**
 * @defgroup	I2C4_TXDR_GROUP		Transmit data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TXDRBitList, /**/
					Bit<8>{BitPos_t{0}}	// TXDATA
					)

enum class TXDRField {
	TXDATA,		/*!< 8-bit transmit data*/
};

template <Port I2C>
static constexpr Register<TXDRBitList, TXDRField> TXDR{BASE_ADDR(I2C), 0x28U};
/**@}*/


} // cpp_stm32::i2c::reg
