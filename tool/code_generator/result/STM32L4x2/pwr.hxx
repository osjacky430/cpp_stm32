#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::pwr::reg {

static constexpr auto BASE_ADDR = 0x40007000U;

/**
 * @defgroup	PWR_CR1_GROUP		Power control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR1BitList, /**/
					Bit<3>{BitPos_t{0}},	// LPMS
					Binary<>{BitPos_t{8}},	// DBP
					Bit<2>{BitPos_t{9}},	// VOS
					Binary<>{BitPos_t{14}}	// LPR
					)

enum class CR1Field {
	LPMS,		/*!< Low-power mode selection*/
	DBP,		/*!< Disable backup domain write protection*/
	VOS,		/*!< Voltage scaling range selection*/
	LPR,		/*!< Low-power run*/
};

static constexpr Register<CR1BitList, CR1Field> CR1{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	PWR_CR2_GROUP		Power control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR2BitList, /**/
					Binary<>{BitPos_t{0}},	// PVDE
					Bit<3>{BitPos_t{1}},	// PLS
					Binary<>{BitPos_t{4}},	// PVME1
					Binary<>{BitPos_t{5}},	// PVME2
					Binary<>{BitPos_t{6}},	// PVME3
					Binary<>{BitPos_t{7}},	// PVME4
					Binary<>{BitPos_t{9}},	// IOSV
					Binary<>{BitPos_t{10}}	// USV
					)

enum class CR2Field {
	PVDE,		/*!< Power voltage detector enable*/
	PLS,		/*!< Power voltage detector level selection*/
	PVME1,		/*!< Peripheral voltage monitoring 1 enable: VDDUSB vs. 1.2V*/
	PVME2,		/*!< Peripheral voltage monitoring 2 enable: VDDIO2 vs. 0.9V*/
	PVME3,		/*!< Peripheral voltage monitoring 3 enable: VDDA vs. 1.62V*/
	PVME4,		/*!< Peripheral voltage monitoring 4 enable: VDDA vs. 2.2V*/
	IOSV,		/*!< VDDIO2 Independent I/Os supply valid*/
	USV,		/*!< VDDUSB USB supply valid*/
};

static constexpr Register<CR2BitList, CR2Field> CR2{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	PWR_CR3_GROUP		Power control register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR3BitList, /**/
					Binary<>{BitPos_t{0}},	// EWUP1
					Binary<>{BitPos_t{1}},	// EWUP2
					Binary<>{BitPos_t{2}},	// EWUP3
					Binary<>{BitPos_t{3}},	// EWUP4
					Binary<>{BitPos_t{4}},	// EWUP5
					Binary<>{BitPos_t{8}},	// RRS
					Binary<>{BitPos_t{10}},	// APC
					Binary<>{BitPos_t{15}}	// EWF
					)

enum class CR3Field {
	EWUP1,		/*!< Enable Wakeup pin WKUP1*/
	EWUP2,		/*!< Enable Wakeup pin WKUP2*/
	EWUP3,		/*!< Enable Wakeup pin WKUP3*/
	EWUP4,		/*!< Enable Wakeup pin WKUP4*/
	EWUP5,		/*!< Enable Wakeup pin WKUP5*/
	RRS,		/*!< SRAM2 retention in Standby mode*/
	APC,		/*!< Apply pull-up and pull-down configuration*/
	EWF,		/*!< Enable internal wakeup line*/
};

static constexpr Register<CR3BitList, CR3Field> CR3{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	PWR_CR4_GROUP		Power control register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR4BitList, /**/
					Binary<>{BitPos_t{0}},	// WP1
					Binary<>{BitPos_t{1}},	// WP2
					Binary<>{BitPos_t{2}},	// WP3
					Binary<>{BitPos_t{3}},	// WP4
					Binary<>{BitPos_t{4}},	// WP5
					Binary<>{BitPos_t{8}},	// VBE
					Binary<>{BitPos_t{9}}	// VBRS
					)

enum class CR4Field {
	WP1,		/*!< Wakeup pin WKUP1 polarity*/
	WP2,		/*!< Wakeup pin WKUP2 polarity*/
	WP3,		/*!< Wakeup pin WKUP3 polarity*/
	WP4,		/*!< Wakeup pin WKUP4 polarity*/
	WP5,		/*!< Wakeup pin WKUP5 polarity*/
	VBE,		/*!< VBAT battery charging enable*/
	VBRS,		/*!< VBAT battery charging resistor selection*/
};

static constexpr Register<CR4BitList, CR4Field> CR4{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	PWR_SR1_GROUP		Power status register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SR1BitList, /**/
					Binary<>{BitPos_t{0}},	// CWUF1
					Binary<>{BitPos_t{1}},	// CWUF2
					Binary<>{BitPos_t{2}},	// CWUF3
					Binary<>{BitPos_t{3}},	// CWUF4
					Binary<>{BitPos_t{4}},	// CWUF5
					Binary<>{BitPos_t{8}},	// CSBF
					Binary<>{BitPos_t{15}}	// WUFI
					)

enum class SR1Field {
	CWUF1,		/*!< Wakeup flag 1*/
	CWUF2,		/*!< Wakeup flag 2*/
	CWUF3,		/*!< Wakeup flag 3*/
	CWUF4,		/*!< Wakeup flag 4*/
	CWUF5,		/*!< Wakeup flag 5*/
	CSBF,		/*!< Standby flag*/
	WUFI,		/*!< Wakeup flag internal*/
};

static constexpr Register<SR1BitList, SR1Field> SR1{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	PWR_SR2_GROUP		Power status register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SR2BitList, /**/
					Binary<>{BitPos_t{8}},	// REGLPS
					Binary<>{BitPos_t{9}},	// REGLPF
					Binary<>{BitPos_t{10}},	// VOSF
					Binary<>{BitPos_t{11}},	// PVDO
					Binary<>{BitPos_t{12}},	// PVMO1
					Binary<>{BitPos_t{13}},	// PVMO2
					Binary<>{BitPos_t{14}},	// PVMO3
					Binary<>{BitPos_t{15}}	// PVMO4
					)

enum class SR2Field {
	REGLPS,		/*!< Low-power regulator started*/
	REGLPF,		/*!< Low-power regulator flag*/
	VOSF,		/*!< Voltage scaling flag*/
	PVDO,		/*!< Power voltage detector output*/
	PVMO1,		/*!< Peripheral voltage monitoring output: VDDUSB vs. 1.2 V*/
	PVMO2,		/*!< Peripheral voltage monitoring output: VDDIO2 vs. 0.9 V*/
	PVMO3,		/*!< Peripheral voltage monitoring output: VDDA vs. 1.62 V*/
	PVMO4,		/*!< Peripheral voltage monitoring output: VDDA vs. 2.2 V*/
};

static constexpr Register<SR2BitList, SR2Field> SR2{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	PWR_SCR_GROUP		Power status clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SCRBitList, /**/
					Binary<>{BitPos_t{0}},	// WUF1
					Binary<>{BitPos_t{1}},	// WUF2
					Binary<>{BitPos_t{2}},	// WUF3
					Binary<>{BitPos_t{3}},	// WUF4
					Binary<>{BitPos_t{4}},	// WUF5
					Binary<>{BitPos_t{8}}	// SBF
					)

enum class SCRField {
	WUF1,		/*!< Clear wakeup flag 1*/
	WUF2,		/*!< Clear wakeup flag 2*/
	WUF3,		/*!< Clear wakeup flag 3*/
	WUF4,		/*!< Clear wakeup flag 4*/
	WUF5,		/*!< Clear wakeup flag 5*/
	SBF,		/*!< Clear standby flag*/
};

static constexpr Register<SCRBitList, SCRField> SCR{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	PWR_PUCRA_GROUP		Power Port A pull-up control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PUCRABitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PU
					)

enum class PUCRAField {
	PU,		/*!< Port A pull-up bit y (y=0..15)*/
};

static constexpr Register<PUCRABitList, PUCRAField> PUCRA{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	PWR_PDCRA_GROUP		Power Port A pull-down control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PDCRABitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PD
					)

enum class PDCRAField {
	PD,		/*!< Port A pull-down bit y (y=0..15)*/
};

static constexpr Register<PDCRABitList, PDCRAField> PDCRA{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	PWR_PUCRB_GROUP		Power Port B pull-up control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PUCRBBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PU
					)

enum class PUCRBField {
	PU,		/*!< Port B pull-up bit y (y=0..15)*/
};

static constexpr Register<PUCRBBitList, PUCRBField> PUCRB{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	PWR_PDCRB_GROUP		Power Port B pull-down control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PDCRBBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PD
					)

enum class PDCRBField {
	PD,		/*!< Port B pull-down bit y (y=0..15)*/
};

static constexpr Register<PDCRBBitList, PDCRBField> PDCRB{BASE_ADDR, 0x2cU};
/**@}*/

/**
 * @defgroup	PWR_PUCRC_GROUP		Power Port C pull-up control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PUCRCBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PU
					)

enum class PUCRCField {
	PU,		/*!< Port C pull-up bit y (y=0..15)*/
};

static constexpr Register<PUCRCBitList, PUCRCField> PUCRC{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	PWR_PDCRC_GROUP		Power Port C pull-down control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PDCRCBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PD
					)

enum class PDCRCField {
	PD,		/*!< Port C pull-down bit y (y=0..15)*/
};

static constexpr Register<PDCRCBitList, PDCRCField> PDCRC{BASE_ADDR, 0x34U};
/**@}*/

/**
 * @defgroup	PWR_PUCRD_GROUP		Power Port D pull-up control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PUCRDBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PU
					)

enum class PUCRDField {
	PU,		/*!< Port D pull-up bit y (y=0..15)*/
};

static constexpr Register<PUCRDBitList, PUCRDField> PUCRD{BASE_ADDR, 0x38U};
/**@}*/

/**
 * @defgroup	PWR_PDCRD_GROUP		Power Port D pull-down control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PDCRDBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PD
					)

enum class PDCRDField {
	PD,		/*!< Port D pull-down bit y (y=0..15)*/
};

static constexpr Register<PDCRDBitList, PDCRDField> PDCRD{BASE_ADDR, 0x3cU};
/**@}*/

/**
 * @defgroup	PWR_PUCRE_GROUP		Power Port E pull-up control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PUCREBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PU
					)

enum class PUCREField {
	PU,		/*!< Port E pull-up bit y (y=0..15)*/
};

static constexpr Register<PUCREBitList, PUCREField> PUCRE{BASE_ADDR, 0x40U};
/**@}*/

/**
 * @defgroup	PWR_PDCRE_GROUP		Power Port E pull-down control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PDCREBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PD
					)

enum class PDCREField {
	PD,		/*!< Port E pull-down bit y (y=0..15)*/
};

static constexpr Register<PDCREBitList, PDCREField> PDCRE{BASE_ADDR, 0x44U};
/**@}*/

/**
 * @defgroup	PWR_PUCRF_GROUP		Power Port F pull-up control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PUCRFBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PU
					)

enum class PUCRFField {
	PU,		/*!< Port F pull-up bit y (y=0..15)*/
};

static constexpr Register<PUCRFBitList, PUCRFField> PUCRF{BASE_ADDR, 0x48U};
/**@}*/

/**
 * @defgroup	PWR_PDCRF_GROUP		Power Port F pull-down control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PDCRFBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PD
					)

enum class PDCRFField {
	PD,		/*!< Port F pull-down bit y (y=0..15)*/
};

static constexpr Register<PDCRFBitList, PDCRFField> PDCRF{BASE_ADDR, 0x4cU};
/**@}*/

/**
 * @defgroup	PWR_PUCRG_GROUP		Power Port G pull-up control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PUCRGBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PU
					)

enum class PUCRGField {
	PU,		/*!< Port G pull-up bit y (y=0..15)*/
};

static constexpr Register<PUCRGBitList, PUCRGField> PUCRG{BASE_ADDR, 0x50U};
/**@}*/

/**
 * @defgroup	PWR_PDCRG_GROUP		Power Port G pull-down control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PDCRGBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PD
					)

enum class PDCRGField {
	PD,		/*!< Port G pull-down bit y (y=0..15)*/
};

static constexpr Register<PDCRGBitList, PDCRGField> PDCRG{BASE_ADDR, 0x54U};
/**@}*/

/**
 * @defgroup	PWR_PUCRH_GROUP		Power Port H pull-up control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PUCRHBitList, /**/
					Bit<2>{BitPos_t{0}}	// PU
					)

enum class PUCRHField {
	PU,		/*!< Port H pull-up bit y (y=0..1)*/
};

static constexpr Register<PUCRHBitList, PUCRHField> PUCRH{BASE_ADDR, 0x58U};
/**@}*/

/**
 * @defgroup	PWR_PDCRH_GROUP		Power Port H pull-down control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PDCRHBitList, /**/
					Bit<2>{BitPos_t{0}}	// PD
					)

enum class PDCRHField {
	PD,		/*!< Port H pull-down bit y (y=0..1)*/
};

static constexpr Register<PDCRHBitList, PDCRHField> PDCRH{BASE_ADDR, 0x5cU};
/**@}*/


} // cpp_stm32::pwr::reg
