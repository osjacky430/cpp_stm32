#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::stk::reg {

static constexpr auto BASE_ADDR = 0xe000e010U;

/**
 * @defgroup	STK_CTRL_GROUP		SysTick control and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CTRLBitList, /**/
					Binary<>{BitPos_t{16}},	// COUNTFLAG
					Binary<>{BitPos_t{2}},	// CLKSOURCE
					Binary<>{BitPos_t{1}},	// TICKINT
					Binary<>{BitPos_t{0}}	// ENABLE
					)

enum class CTRLField {
	COUNTFLAG,		/*!< COUNTFLAG*/
	CLKSOURCE,		/*!< Clock source selection*/
	TICKINT,		/*!< SysTick exception request enable*/
	ENABLE,		/*!< Counter enable*/
};

static constexpr Register<CTRLBitList, CTRLField> CTRL{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	STK_LOAD_GROUP		SysTick reload value register group
 *
 * @{
 */

SETUP_REGISTER_INFO(LOADBitList, /**/
					Bit<24, std::uint32_t>{BitPos_t{0}}	// RELOAD
					)

enum class LOADField {
	RELOAD,		/*!< RELOAD value*/
};

static constexpr Register<LOADBitList, LOADField> LOAD{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	STK_VAL_GROUP		SysTick current value register group
 *
 * @{
 */

SETUP_REGISTER_INFO(VALBitList, /**/
					Bit<24, std::uint32_t>{BitPos_t{0}}	// CURRENT
					)

enum class VALField {
	CURRENT,		/*!< Current counter value*/
};

static constexpr Register<VALBitList, VALField> VAL{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	STK_CALIB_GROUP		SysTick calibration value register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CALIBBitList, /**/
					Binary<>{BitPos_t{31}},	// NOREF
					Binary<>{BitPos_t{30}},	// SKEW
					Bit<24, std::uint32_t>{BitPos_t{0}}	// TENMS
					)

enum class CALIBField {
	NOREF,		/*!< NOREF flag. Reads as zero*/
	SKEW,		/*!< SKEW flag: Indicates whether the TENMS value is exact*/
	TENMS,		/*!< Calibration value*/
};

static constexpr Register<CALIBBitList, CALIBField> CALIB{BASE_ADDR, 0x0cU};
/**@}*/


} // cpp_stm32::stk::reg
