#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::vref::reg {

static constexpr auto BASE_ADDR = 0x40010030U;

/**
 * @defgroup	VREFBUF_CSR_GROUP		VREF control and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CSRBitList, /**/
					StatusBit<1>{BitPos_t{3}},	// VRR
					Binary<>{BitPos_t{2}},	// VRS
					Binary<>{BitPos_t{1}},	// HIZ
					Binary<>{BitPos_t{0}}	// ENVR
					)

enum class CSRField {
	VRR,		/*!< Voltage reference buffer ready*/
	VRS,		/*!< Voltage reference scale*/
	HIZ,		/*!< High impedance mode*/
	ENVR,		/*!< Voltage reference buffer enable*/
};

static constexpr Register<CSRBitList, CSRField> CSR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	VREFBUF_CCR_GROUP		calibration control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCRBitList, /**/
					Bit<6>{BitPos_t{0}}	// TRIM
					)

enum class CCRField {
	TRIM,		/*!< Trimming code*/
};

static constexpr Register<CCRBitList, CCRField> CCR{BASE_ADDR, 0x04U};
/**@}*/


} // cpp_stm32::vref::reg
