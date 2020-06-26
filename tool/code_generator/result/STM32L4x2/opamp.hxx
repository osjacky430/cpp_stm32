#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::opamp::reg {

static constexpr auto BASE_ADDR = 0x40007800U;

/**
 * @defgroup	OPAMP_OPAMP1_CSR_GROUP		OPAMP1 control/status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OPAMP1_CSRBitList, /**/
					Binary<>{BitPos_t{31}},	// OPA_RANGE
					Binary<>{BitPos_t{15}},	// CALOUT
					Binary<>{BitPos_t{14}},	// USERTRIM
					Binary<>{BitPos_t{13}},	// CALSEL
					Binary<>{BitPos_t{12}},	// CALON
					Binary<>{BitPos_t{10}},	// VP_SEL
					Bit<2>{BitPos_t{8}},	// VM_SEL
					Bit<2>{BitPos_t{4}},	// PGA_GAIN
					Bit<2>{BitPos_t{2}},	// OPAMODE
					Binary<>{BitPos_t{1}},	// OPALPM
					Binary<>{BitPos_t{0}}	// OPAEN
					)

enum class OPAMP1_CSRField {
	OPA_RANGE,		/*!< Operational amplifier power supply range for stability*/
	CALOUT,		/*!< Operational amplifier calibration output*/
	USERTRIM,		/*!< allows to switch from AOP offset trimmed values to AOP offset*/
	CALSEL,		/*!< Calibration selection*/
	CALON,		/*!< Calibration mode enabled*/
	VP_SEL,		/*!< Non inverted input selection*/
	VM_SEL,		/*!< Inverting input selection*/
	PGA_GAIN,		/*!< Operational amplifier Programmable amplifier gain value*/
	OPAMODE,		/*!< Operational amplifier PGA mode*/
	OPALPM,		/*!< Operational amplifier Low Power Mode*/
	OPAEN,		/*!< Operational amplifier Enable*/
};

static constexpr Register<OPAMP1_CSRBitList, OPAMP1_CSRField> OPAMP1_CSR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	OPAMP_OPAMP1_OTR_GROUP		OPAMP1 offset trimming register in normal mode group
 *
 * @{
 */

SETUP_REGISTER_INFO(OPAMP1_OTRBitList, /**/
					Bit<5>{BitPos_t{8}},	// TRIMOFFSETP
					Bit<5>{BitPos_t{0}}	// TRIMOFFSETN
					)

enum class OPAMP1_OTRField {
	TRIMOFFSETP,		/*!< Trim for PMOS differential pairs*/
	TRIMOFFSETN,		/*!< Trim for NMOS differential pairs*/
};

static constexpr Register<OPAMP1_OTRBitList, OPAMP1_OTRField> OPAMP1_OTR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	OPAMP_OPAMP1_LPOTR_GROUP		OPAMP1 offset trimming register in low-power mode group
 *
 * @{
 */

SETUP_REGISTER_INFO(OPAMP1_LPOTRBitList, /**/
					Bit<5>{BitPos_t{8}},	// TRIMLPOFFSETP
					Bit<5>{BitPos_t{0}}	// TRIMLPOFFSETN
					)

enum class OPAMP1_LPOTRField {
	TRIMLPOFFSETP,		/*!< Trim for PMOS differential pairs*/
	TRIMLPOFFSETN,		/*!< Trim for NMOS differential pairs*/
};

static constexpr Register<OPAMP1_LPOTRBitList, OPAMP1_LPOTRField> OPAMP1_LPOTR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	OPAMP_OPAMP2_CSR_GROUP		OPAMP2 control/status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OPAMP2_CSRBitList, /**/
					Binary<>{BitPos_t{15}},	// CALOUT
					Binary<>{BitPos_t{14}},	// USERTRIM
					Binary<>{BitPos_t{13}},	// CALSEL
					Binary<>{BitPos_t{12}},	// CALON
					Binary<>{BitPos_t{10}},	// VP_SEL
					Bit<2>{BitPos_t{8}},	// VM_SEL
					Bit<2>{BitPos_t{4}},	// PGA_GAIN
					Bit<2>{BitPos_t{2}},	// OPAMODE
					Binary<>{BitPos_t{1}},	// OPALPM
					Binary<>{BitPos_t{0}}	// OPAEN
					)

enum class OPAMP2_CSRField {
	CALOUT,		/*!< Operational amplifier calibration output*/
	USERTRIM,		/*!< allows to switch from AOP offset trimmed values to AOP offset*/
	CALSEL,		/*!< Calibration selection*/
	CALON,		/*!< Calibration mode enabled*/
	VP_SEL,		/*!< Non inverted input selection*/
	VM_SEL,		/*!< Inverting input selection*/
	PGA_GAIN,		/*!< Operational amplifier Programmable amplifier gain value*/
	OPAMODE,		/*!< Operational amplifier PGA mode*/
	OPALPM,		/*!< Operational amplifier Low Power Mode*/
	OPAEN,		/*!< Operational amplifier Enable*/
};

static constexpr Register<OPAMP2_CSRBitList, OPAMP2_CSRField> OPAMP2_CSR{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	OPAMP_OPAMP2_OTR_GROUP		OPAMP2 offset trimming register in normal mode group
 *
 * @{
 */

SETUP_REGISTER_INFO(OPAMP2_OTRBitList, /**/
					Bit<5>{BitPos_t{8}},	// TRIMOFFSETP
					Bit<5>{BitPos_t{0}}	// TRIMOFFSETN
					)

enum class OPAMP2_OTRField {
	TRIMOFFSETP,		/*!< Trim for PMOS differential pairs*/
	TRIMOFFSETN,		/*!< Trim for NMOS differential pairs*/
};

static constexpr Register<OPAMP2_OTRBitList, OPAMP2_OTRField> OPAMP2_OTR{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	OPAMP_OPAMP2_LPOTR_GROUP		OPAMP2 offset trimming register in low-power mode group
 *
 * @{
 */

SETUP_REGISTER_INFO(OPAMP2_LPOTRBitList, /**/
					Bit<5>{BitPos_t{8}},	// TRIMLPOFFSETP
					Bit<5>{BitPos_t{0}}	// TRIMLPOFFSETN
					)

enum class OPAMP2_LPOTRField {
	TRIMLPOFFSETP,		/*!< Trim for PMOS differential pairs*/
	TRIMLPOFFSETN,		/*!< Trim for NMOS differential pairs*/
};

static constexpr Register<OPAMP2_LPOTRBitList, OPAMP2_LPOTRField> OPAMP2_LPOTR{BASE_ADDR, 0x18U};
/**@}*/


} // cpp_stm32::opamp::reg
