#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::wwdg::reg {

static constexpr auto BASE_ADDR = 0x40002c00U;

/**
 * @defgroup	WWDG_CR_GROUP		Control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Bit<7>{BitPos_t{0}},	// T
					Binary<>{BitPos_t{7}}	// WDGA
					)

enum class CRField {
	T,		/*!< 7-bit counter (MSB to LSB)*/
	WDGA,		/*!< Activation bit*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	WWDG_CFR_GROUP		Configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CFRBitList, /**/
					Bit<7>{BitPos_t{0}},	// W
					Bit<2>{BitPos_t{7}},	// WDGTB
					Binary<>{BitPos_t{9}}	// EWI
					)

enum class CFRField {
	W,		/*!< 7-bit window value*/
	WDGTB,		/*!< Timer base*/
	EWI,		/*!< Early wakeup interrupt*/
};

static constexpr Register<CFRBitList, CFRField> CFR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	WWDG_SR_GROUP		Status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					Binary<>{BitPos_t{0}}	// EWIF
					)

enum class SRField {
	EWIF,		/*!< Early wakeup interrupt flag*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x08U};
/**@}*/


} // cpp_stm32::wwdg::reg
