#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::syscfg::reg {

static constexpr auto BASE_ADDR = 0x40010000U;

/**
 * @defgroup	SYSCFG_MEMRMP_GROUP		memory remap register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MEMRMPBitList, /**/
					Bit<3>{BitPos_t{0}},	// MEM_MODE
					Binary<>{BitPos_t{3}},	// QFS
					Binary<>{BitPos_t{8}}	// FB_MODE
					)

enum class MEMRMPField {
	MEM_MODE,		/*!< Memory mapping selection*/
	QFS,		/*!< QUADSPI memory mapping swap*/
	FB_MODE,		/*!< Flash Bank mode selection*/
};

static constexpr Register<MEMRMPBitList, MEMRMPField> MEMRMP{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	SYSCFG_CFGR1_GROUP		configuration register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CFGR1BitList, /**/
					Binary<>{BitPos_t{0}},	// FWDIS
					Binary<>{BitPos_t{8}},	// BOOSTEN
					Binary<>{BitPos_t{16}},	// I2C_PB6_FMP
					Binary<>{BitPos_t{17}},	// I2C_PB7_FMP
					Binary<>{BitPos_t{18}},	// I2C_PB8_FMP
					Binary<>{BitPos_t{19}},	// I2C_PB9_FMP
					Binary<>{BitPos_t{20}},	// I2C1_FMP
					Binary<>{BitPos_t{21}},	// I2C2_FMP
					Binary<>{BitPos_t{22}},	// I2C3_FMP
					Bit<6>{BitPos_t{26}}	// FPU_IE
					)

enum class CFGR1Field {
	FWDIS,		/*!< Firewall disable*/
	BOOSTEN,		/*!< I/O analog switch voltage booster enable*/
	I2C_PB6_FMP,		/*!< Fast-mode Plus (Fm+) driving capability activation on PB6*/
	I2C_PB7_FMP,		/*!< Fast-mode Plus (Fm+) driving capability activation on PB7*/
	I2C_PB8_FMP,		/*!< Fast-mode Plus (Fm+) driving capability activation on PB8*/
	I2C_PB9_FMP,		/*!< Fast-mode Plus (Fm+) driving capability activation on PB9*/
	I2C1_FMP,		/*!< I2C1 Fast-mode Plus driving capability activation*/
	I2C2_FMP,		/*!< I2C2 Fast-mode Plus driving capability activation*/
	I2C3_FMP,		/*!< I2C3 Fast-mode Plus driving capability activation*/
	FPU_IE,		/*!< Floating Point Unit interrupts enable bits*/
};

static constexpr Register<CFGR1BitList, CFGR1Field> CFGR1{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	SYSCFG_EXTICR1_GROUP		external interrupt configuration register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(EXTICR1BitList, /**/
					Bit<3>{BitPos_t{0}},	// EXTI0
					Bit<3>{BitPos_t{4}},	// EXTI1
					Bit<3>{BitPos_t{8}},	// EXTI2
					Bit<3>{BitPos_t{12}}	// EXTI3
					)

enum class EXTICR1Field {
	EXTI0,		/*!< EXTI 0 configuration bits*/
	EXTI1,		/*!< EXTI 1 configuration bits*/
	EXTI2,		/*!< EXTI 2 configuration bits*/
	EXTI3,		/*!< EXTI 3 configuration bits*/
};

static constexpr Register<EXTICR1BitList, EXTICR1Field> EXTICR1{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	SYSCFG_EXTICR2_GROUP		external interrupt configuration register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(EXTICR2BitList, /**/
					Bit<3>{BitPos_t{0}},	// EXTI4
					Bit<3>{BitPos_t{4}},	// EXTI5
					Bit<3>{BitPos_t{8}},	// EXTI6
					Bit<3>{BitPos_t{12}}	// EXTI7
					)

enum class EXTICR2Field {
	EXTI4,		/*!< EXTI 4 configuration bits*/
	EXTI5,		/*!< EXTI 5 configuration bits*/
	EXTI6,		/*!< EXTI 6 configuration bits*/
	EXTI7,		/*!< EXTI 7 configuration bits*/
};

static constexpr Register<EXTICR2BitList, EXTICR2Field> EXTICR2{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	SYSCFG_EXTICR3_GROUP		external interrupt configuration register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(EXTICR3BitList, /**/
					Bit<3>{BitPos_t{0}},	// EXTI8
					Bit<3>{BitPos_t{4}},	// EXTI9
					Bit<3>{BitPos_t{8}},	// EXTI10
					Bit<3>{BitPos_t{12}}	// EXTI11
					)

enum class EXTICR3Field {
	EXTI8,		/*!< EXTI 8 configuration bits*/
	EXTI9,		/*!< EXTI 9 configuration bits*/
	EXTI10,		/*!< EXTI 10 configuration bits*/
	EXTI11,		/*!< EXTI 11 configuration bits*/
};

static constexpr Register<EXTICR3BitList, EXTICR3Field> EXTICR3{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	SYSCFG_EXTICR4_GROUP		external interrupt configuration register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(EXTICR4BitList, /**/
					Bit<3>{BitPos_t{0}},	// EXTI12
					Bit<3>{BitPos_t{4}},	// EXTI13
					Bit<3>{BitPos_t{8}},	// EXTI14
					Bit<3>{BitPos_t{12}}	// EXTI15
					)

enum class EXTICR4Field {
	EXTI12,		/*!< EXTI12 configuration bits*/
	EXTI13,		/*!< EXTI13 configuration bits*/
	EXTI14,		/*!< EXTI14 configuration bits*/
	EXTI15,		/*!< EXTI15 configuration bits*/
};

static constexpr Register<EXTICR4BitList, EXTICR4Field> EXTICR4{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	SYSCFG_SCSR_GROUP		SCSR group
 *
 * @{
 */

SETUP_REGISTER_INFO(SCSRBitList, /**/
					Binary<>{BitPos_t{0}},	// SRAM2ER
					StatusBit<1>{BitPos_t{1}}	// SRAM2BSY
					)

enum class SCSRField {
	SRAM2ER,		/*!< SRAM2 Erase*/
	SRAM2BSY,		/*!< SRAM2 busy by erase operation*/
};

static constexpr Register<SCSRBitList, SCSRField> SCSR{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	SYSCFG_CFGR2_GROUP		CFGR2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CFGR2BitList, /**/
					Binary<BitMod::WrOnly>{BitPos_t{0}},	// CLL
					Binary<BitMod::WrOnly>{BitPos_t{1}},	// SPL
					Binary<BitMod::WrOnly>{BitPos_t{2}},	// PVDL
					Binary<BitMod::WrOnly>{BitPos_t{3}},	// ECCL
					Binary<>{BitPos_t{8}}	// SPF
					)

enum class CFGR2Field {
	CLL,		/*!< OCKUP (Hardfault) output enable bit*/
	SPL,		/*!< SRAM2 parity lock bit*/
	PVDL,		/*!< PVD lock enable bit*/
	ECCL,		/*!< ECC Lock*/
	SPF,		/*!< SRAM2 parity error flag*/
};

static constexpr Register<CFGR2BitList, CFGR2Field> CFGR2{BASE_ADDR, 0x1cU};
/**@}*/

/**
 * @defgroup	SYSCFG_SWPR_GROUP		SWPR group
 *
 * @{
 */

SETUP_REGISTER_INFO(SWPRBitList, /**/
					Binary<>{BitPos_t{0}},	// P0WP
					Binary<>{BitPos_t{1}},	// P1WP
					Binary<>{BitPos_t{2}},	// P2WP
					Binary<>{BitPos_t{3}},	// P3WP
					Binary<>{BitPos_t{4}},	// P4WP
					Binary<>{BitPos_t{5}},	// P5WP
					Binary<>{BitPos_t{6}},	// P6WP
					Binary<>{BitPos_t{7}},	// P7WP
					Binary<>{BitPos_t{8}},	// P8WP
					Binary<>{BitPos_t{9}},	// P9WP
					Binary<>{BitPos_t{10}},	// P10WP
					Binary<>{BitPos_t{11}},	// P11WP
					Binary<>{BitPos_t{12}},	// P12WP
					Binary<>{BitPos_t{13}},	// P13WP
					Binary<>{BitPos_t{14}},	// P14WP
					Binary<>{BitPos_t{15}},	// P15WP
					Binary<>{BitPos_t{16}},	// P16WP
					Binary<>{BitPos_t{17}},	// P17WP
					Binary<>{BitPos_t{18}},	// P18WP
					Binary<>{BitPos_t{19}},	// P19WP
					Binary<>{BitPos_t{20}},	// P20WP
					Binary<>{BitPos_t{21}},	// P21WP
					Binary<>{BitPos_t{22}},	// P22WP
					Binary<>{BitPos_t{23}},	// P23WP
					Binary<>{BitPos_t{24}},	// P24WP
					Binary<>{BitPos_t{25}},	// P25WP
					Binary<>{BitPos_t{26}},	// P26WP
					Binary<>{BitPos_t{27}},	// P27WP
					Binary<>{BitPos_t{28}},	// P28WP
					Binary<>{BitPos_t{29}},	// P29WP
					Binary<>{BitPos_t{30}},	// P30WP
					Binary<>{BitPos_t{31}}	// P31WP
					)

enum class SWPRField {
	P0WP,		/*!< P0WP*/
	P1WP,		/*!< P1WP*/
	P2WP,		/*!< P2WP*/
	P3WP,		/*!< P3WP*/
	P4WP,		/*!< P4WP*/
	P5WP,		/*!< P5WP*/
	P6WP,		/*!< P6WP*/
	P7WP,		/*!< P7WP*/
	P8WP,		/*!< P8WP*/
	P9WP,		/*!< P9WP*/
	P10WP,		/*!< P10WP*/
	P11WP,		/*!< P11WP*/
	P12WP,		/*!< P12WP*/
	P13WP,		/*!< P13WP*/
	P14WP,		/*!< P14WP*/
	P15WP,		/*!< P15WP*/
	P16WP,		/*!< P16WP*/
	P17WP,		/*!< P17WP*/
	P18WP,		/*!< P18WP*/
	P19WP,		/*!< P19WP*/
	P20WP,		/*!< P20WP*/
	P21WP,		/*!< P21WP*/
	P22WP,		/*!< P22WP*/
	P23WP,		/*!< P23WP*/
	P24WP,		/*!< P24WP*/
	P25WP,		/*!< P25WP*/
	P26WP,		/*!< P26WP*/
	P27WP,		/*!< P27WP*/
	P28WP,		/*!< P28WP*/
	P29WP,		/*!< P29WP*/
	P30WP,		/*!< P30WP*/
	P31WP,		/*!< SRAM2 page 31 write protection*/
};

static constexpr Register<SWPRBitList, SWPRField> SWPR{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	SYSCFG_SKR_GROUP		SKR group
 *
 * @{
 */

SETUP_REGISTER_INFO(SKRBitList, /**/
					Bit<8>{BitPos_t{0}}	// KEY
					)

enum class SKRField {
	KEY,		/*!< SRAM2 write protection key for software erase*/
};

static constexpr Register<SKRBitList, SKRField> SKR{BASE_ADDR, 0x24U};
/**@}*/


} // cpp_stm32::syscfg::reg
