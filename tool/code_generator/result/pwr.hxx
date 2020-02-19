#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::pwr::reg {

static constexpr auto BASE_ADDR = 0x40007000U;

/**
 * @defgroup	PWR_CR_GROUP		power control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{21}},	// FISSR
					Binary<>{BitPos_t{20}},	// FMSSR
					Bit<2>{BitPos_t{18}},	// UDEN
					Binary<>{BitPos_t{17}},	// ODSWEN
					Binary<>{BitPos_t{16}},	// ODEN
					Bit<2>{BitPos_t{14}},	// VOS
					Binary<>{BitPos_t{13}},	// ADCDC1
					Binary<>{BitPos_t{11}},	// MRLVDS
					Binary<>{BitPos_t{10}},	// LPLVDS
					Binary<>{BitPos_t{9}},	// FPDS
					Binary<>{BitPos_t{8}},	// DBP
					Bit<3>{BitPos_t{5}},	// PLS
					Binary<>{BitPos_t{4}},	// PVDE
					Binary<>{BitPos_t{3}},	// CSBF
					Binary<>{BitPos_t{2}},	// CWUF
					Binary<>{BitPos_t{1}},	// PDDS
					Binary<>{BitPos_t{0}}	// LPDS
					)

enum class CRField {
	FISSR,		/*!< Flash Interface Stop while System Run*/
	FMSSR,		/*!< Flash Memory Stop while System Run*/
	UDEN,		/*!< Under-drive enable in stop mode*/
	ODSWEN,		/*!< Over-drive switching enabled*/
	ODEN,		/*!< Over-drive enable*/
	VOS,		/*!< Regulator voltage scaling output selection*/
	ADCDC1,		/*!< ADCDC1*/
	MRLVDS,		/*!< Main regulator low voltage in deepsleep mode*/
	LPLVDS,		/*!< Low-Power Regulator Low Voltage in deepsleep*/
	FPDS,		/*!< Flash power down in Stop mode*/
	DBP,		/*!< Disable backup domain write protection*/
	PLS,		/*!< PVD level selection*/
	PVDE,		/*!< Power voltage detector enable*/
	CSBF,		/*!< Clear standby flag*/
	CWUF,		/*!< Clear wakeup flag*/
	PDDS,		/*!< Power down deepsleep*/
	LPDS,		/*!< Low-power deep sleep*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	PWR_CSR_GROUP		power control/status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CSRBitList, /**/
					Bit<2>{BitPos_t{18}},	// UDRDY
					StatusBit<1>{BitPos_t{17}},	// ODSWRDY
					StatusBit<1>{BitPos_t{16}},	// ODRDY
					StatusBit<1>{BitPos_t{14}},	// VOSRDY
					Binary<>{BitPos_t{9}},	// BRE
					Binary<>{BitPos_t{8}},	// EWUP
					Binary<>{BitPos_t{7}},	// EWUP2
					StatusBit<1>{BitPos_t{3}},	// BRR
					StatusBit<1>{BitPos_t{2}},	// PVDO
					StatusBit<1>{BitPos_t{1}},	// SBF
					StatusBit<1>{BitPos_t{0}}	// WUF
					)

enum class CSRField {
	UDRDY,		/*!< Under-drive ready flag*/
	ODSWRDY,		/*!< Over-drive mode switching ready*/
	ODRDY,		/*!< Over-drive mode ready*/
	VOSRDY,		/*!< Regulator voltage scaling output selection ready bit*/
	BRE,		/*!< Backup regulator enable*/
	EWUP,		/*!< Enable WKUP pin*/
	EWUP2,		/*!< Enable WKUP2 pin*/
	BRR,		/*!< Backup regulator ready*/
	PVDO,		/*!< PVD output*/
	SBF,		/*!< Standby flag*/
	WUF,		/*!< Wakeup flag*/
};

static constexpr Register<CSRBitList, CSRField> CSR{BASE_ADDR, 0x04U};
/**@}*/


} // cpp_stm32::pwr::reg
