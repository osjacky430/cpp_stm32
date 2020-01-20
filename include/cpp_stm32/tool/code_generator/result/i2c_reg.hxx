#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::i2c::reg {

static constexpr auto BASE_ADDR(Port const& t_i2c) {
	case Port::I2C3:
		return 0x40005c00U;
	case Port::I2C2:
		return 0x40005800U;
	case Port::I2C1:
		return 0x40005400U;
}

/**
 * @defgroup	I2C1_CR1_GROUP		Control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR1BitList, /**/
					Binary<>{BitPos_t{0}},	// PE
					Binary<>{BitPos_t{1}},	// SMBUS
					Binary<>{BitPos_t{3}},	// SMBTYPE
					Binary<>{BitPos_t{4}},	// ENARP
					Binary<>{BitPos_t{5}},	// ENPEC
					Binary<>{BitPos_t{6}},	// ENGC
					Binary<>{BitPos_t{7}},	// NOSTRETCH
					Binary<>{BitPos_t{8}},	// START
					Binary<>{BitPos_t{9}},	// STOP
					Binary<>{BitPos_t{10}},	// ACK
					Binary<>{BitPos_t{11}},	// POS
					Binary<>{BitPos_t{12}},	// PEC
					Binary<>{BitPos_t{13}},	// ALERT
					Binary<>{BitPos_t{15}}	// SWRST
					)

enum class CR1Field {
	PE,		/*!< Peripheral enable*/
	SMBUS,		/*!< SMBus mode*/
	SMBTYPE,		/*!< SMBus type*/
	ENARP,		/*!< ARP enable*/
	ENPEC,		/*!< PEC enable*/
	ENGC,		/*!< General call enable*/
	NOSTRETCH,		/*!< Clock stretching disable (Slave mode)*/
	START,		/*!< Start generation*/
	STOP,		/*!< Stop generation*/
	ACK,		/*!< Acknowledge enable*/
	POS,		/*!< Acknowledge/PEC Position (for data reception)*/
	PEC,		/*!< Packet error checking*/
	ALERT,		/*!< SMBus alert*/
	SWRST,		/*!< Software reset*/
};

template <Port I2C>
static constexpr Register<CR1BitList, CR1Field> CR1{BASE_ADDR(I2C), 0x00U};
/**@}*/

/**
 * @defgroup	I2C1_CR2_GROUP		Control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR2BitList, /**/
					Bit<6>{BitPos_t{0}},	// FREQ
					Binary<>{BitPos_t{8}},	// ITERREN
					Binary<>{BitPos_t{9}},	// ITEVTEN
					Binary<>{BitPos_t{10}},	// ITBUFEN
					Binary<>{BitPos_t{11}},	// DMAEN
					Binary<>{BitPos_t{12}}	// LAST
					)

enum class CR2Field {
	FREQ,		/*!< Peripheral clock frequency*/
	ITERREN,		/*!< Error interrupt enable*/
	ITEVTEN,		/*!< Event interrupt enable*/
	ITBUFEN,		/*!< Buffer interrupt enable*/
	DMAEN,		/*!< DMA requests enable*/
	LAST,		/*!< DMA last transfer*/
};

template <Port I2C>
static constexpr Register<CR2BitList, CR2Field> CR2{BASE_ADDR(I2C), 0x04U};
/**@}*/

/**
 * @defgroup	I2C1_OAR1_GROUP		Own address register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(OAR1BitList, /**/
					Bit<3>{BitPos_t{0}},	// A
					Binary<>{BitPos_t{15}}	// ADDMODE
					)

enum class OAR1Field {
	A,		/*!< Interface address*/
	ADDMODE,		/*!< Addressing mode (slave mode)*/
};

template <Port I2C>
static constexpr Register<OAR1BitList, OAR1Field> OAR1{BASE_ADDR(I2C), 0x08U};
/**@}*/

/**
 * @defgroup	I2C1_OAR2_GROUP		Own address register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(OAR2BitList, /**/
					Binary<>{BitPos_t{0}},	// ENDUAL
					Bit<7>{BitPos_t{1}}	// ADD2
					)

enum class OAR2Field {
	ENDUAL,		/*!< Dual addressing mode enable*/
	ADD2,		/*!< Interface address*/
};

template <Port I2C>
static constexpr Register<OAR2BitList, OAR2Field> OAR2{BASE_ADDR(I2C), 0x0cU};
/**@}*/

/**
 * @defgroup	I2C1_DR_GROUP		Data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DRBitList, /**/
					Bit<8>{BitPos_t{0}}	// DR
					)

enum class DRField {
	DR,		/*!< 8-bit data register*/
};

template <Port I2C>
static constexpr Register<DRBitList, DRField> DR{BASE_ADDR(I2C), 0x10U};
/**@}*/

/**
 * @defgroup	I2C1_SR1_GROUP		Status register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SR1BitList, /**/
					StatusBit<1>{BitPos_t{0}},	// SB
					StatusBit<1>{BitPos_t{1}},	// ADDR
					StatusBit<1>{BitPos_t{2}},	// BTF
					StatusBit<1>{BitPos_t{3}},	// ADD10
					StatusBit<1>{BitPos_t{4}},	// STOPF
					StatusBit<1>{BitPos_t{6}},	// RxNE
					StatusBit<1>{BitPos_t{7}},	// TxE
					Binary<>{BitPos_t{8}},	// BERR
					Binary<>{BitPos_t{9}},	// ARLO
					Binary<>{BitPos_t{10}},	// AF
					Binary<>{BitPos_t{11}},	// OVR
					Binary<>{BitPos_t{12}},	// PECERR
					Binary<>{BitPos_t{14}},	// TIMEOUT
					Binary<>{BitPos_t{15}}	// SMBALERT
					)

enum class SR1Field {
	SB,		/*!< Start bit (Master mode)*/
	ADDR,		/*!< Address sent (master mode)/matched (slave mode)*/
	BTF,		/*!< Byte transfer finished*/
	ADD10,		/*!< 10-bit header sent (Master mode)*/
	STOPF,		/*!< Stop detection (slave mode)*/
	RxNE,		/*!< Data register not empty (receivers)*/
	TxE,		/*!< Data register empty (transmitters)*/
	BERR,		/*!< Bus error*/
	ARLO,		/*!< Arbitration lost (master mode)*/
	AF,		/*!< Acknowledge failure*/
	OVR,		/*!< Overrun/Underrun*/
	PECERR,		/*!< PEC Error in reception*/
	TIMEOUT,		/*!< Timeout or Tlow error*/
	SMBALERT,		/*!< SMBus alert*/
};

template <Port I2C>
static constexpr Register<SR1BitList, SR1Field> SR1{BASE_ADDR(I2C), 0x14U};
/**@}*/

/**
 * @defgroup	I2C1_SR2_GROUP		Status register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SR2BitList, /**/
					Binary<>{BitPos_t{0}},	// MSL
					Binary<>{BitPos_t{1}},	// BUSY
					Binary<>{BitPos_t{2}},	// TRA
					Binary<>{BitPos_t{4}},	// GENCALL
					Binary<>{BitPos_t{5}},	// SMBDEFAULT
					Binary<>{BitPos_t{6}},	// SMBHOST
					Binary<>{BitPos_t{7}},	// DUALF
					Bit<8>{BitPos_t{8}}	// PEC
					)

enum class SR2Field {
	MSL,		/*!< Master/slave*/
	BUSY,		/*!< Bus busy*/
	TRA,		/*!< Transmitter/receiver*/
	GENCALL,		/*!< General call address (Slave mode)*/
	SMBDEFAULT,		/*!< SMBus device default address (Slave mode)*/
	SMBHOST,		/*!< SMBus host header (Slave mode)*/
	DUALF,		/*!< Dual flag (Slave mode)*/
	PEC,		/*!< acket error checking register*/
};

template <Port I2C>
static constexpr Register<SR2BitList, SR2Field> SR2{BASE_ADDR(I2C), 0x18U};
/**@}*/

/**
 * @defgroup	I2C1_CCR_GROUP		Clock control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCRBitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}},	// CCR
					Binary<>{BitPos_t{14}},	// DUTY
					Binary<>{BitPos_t{15}}	// F_S
					)

enum class CCRField {
	CCR,		/*!< Clock control register in Fast/Standard mode (Master mode)*/
	DUTY,		/*!< Fast mode duty cycle*/
	F_S,		/*!< I2C master mode selection*/
};

template <Port I2C>
static constexpr Register<CCRBitList, CCRField> CCR{BASE_ADDR(I2C), 0x1cU};
/**@}*/

/**
 * @defgroup	I2C1_TRISE_GROUP		TRISE register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TRISEBitList, /**/
					Bit<6>{BitPos_t{0}}	// TRISE
					)

enum class TRISEField {
	TRISE,		/*!< Maximum rise time in Fast/Standard mode (Master mode)*/
};

template <Port I2C>
static constexpr Register<TRISEBitList, TRISEField> TRISE{BASE_ADDR(I2C), 0x20U};
/**@}*/

/**
 * @defgroup	I2C1_FLTR_GROUP		I2C FLTR register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FLTRBitList, /**/
					Binary<>{BitPos_t{4}},	// ANOFF
					Bit<4>{BitPos_t{0}}	// DNF
					)

enum class FLTRField {
	ANOFF,		/*!< Analog noise filter OFF*/
	DNF,		/*!< Digital noise filter*/
};

template <Port I2C>
static constexpr Register<FLTRBitList, FLTRField> FLTR{BASE_ADDR(I2C), 0x24U};
/**@}*/


} // cpp_stm32::i2c::reg
