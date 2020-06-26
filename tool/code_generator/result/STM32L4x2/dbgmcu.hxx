#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::dbgmcu::reg {

static constexpr auto BASE_ADDR = 0xe0042000U;

/**
 * @defgroup	DBGMCU_IDCODE_GROUP		DBGMCU_IDCODE group
 *
 * @{
 */

SETUP_REGISTER_INFO(IDCODEBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{16}},	// REV_ID
					Bit<12, std::uint16_t>{BitPos_t{0}}	// DEV_ID
					)

enum class IDCODEField {
	REV_ID,		/*!< Revision identifie*/
	DEV_ID,		/*!< Device identifier*/
};

static constexpr Register<IDCODEBitList, IDCODEField> IDCODE{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	DBGMCU_CR_GROUP		Debug MCU configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Bit<2>{BitPos_t{6}},	// TRACE_MOD
					Binary<>{BitPos_t{2}},	// DBG_STANDBY
					Binary<>{BitPos_t{1}},	// DBG_STOP
					Binary<>{BitPos_t{0}}	// DBG_SLEEP
					)

enum class CRField {
	TRACE_MOD,		/*!< Trace pin assignment control*/
	DBG_STANDBY,		/*!< Debug Standby mode*/
	DBG_STOP,		/*!< Debug Stop mode*/
	DBG_SLEEP,		/*!< Debug Sleep mode*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	DBGMCU_APB1FZR1_GROUP		Debug MCU APB1 freeze register1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB1FZR1BitList, /**/
					Binary<>{BitPos_t{31}},	// DBG_LPTIM1_STOP
					Binary<>{BitPos_t{25}},	// DBG_CAN_STOP
					Binary<>{BitPos_t{23}},	// DBG_I2C3_STOP
					Binary<>{BitPos_t{22}},	// DBG_I2C2_STOP
					Binary<>{BitPos_t{21}},	// DBG_I2C1_STOP
					Binary<>{BitPos_t{12}},	// DBG_IWDG_STOP
					Binary<>{BitPos_t{11}},	// DBG_WWDG_STOP
					Binary<>{BitPos_t{10}},	// DBG_RTC_STOP
					Binary<>{BitPos_t{5}},	// DBG_TIM7_STOP
					Binary<>{BitPos_t{4}},	// DBG_TIM6_STOP
					Binary<>{BitPos_t{0}}	// DBG_TIM2_STOP
					)

enum class APB1FZR1Field {
	DBG_LPTIM1_STOP,		/*!< LPTIM1 counter stopped when core is halted*/
	DBG_CAN_STOP,		/*!< bxCAN stopped when core is halted*/
	DBG_I2C3_STOP,		/*!< I2C3 SMBUS timeout counter stopped when core is halted*/
	DBG_I2C2_STOP,		/*!< I2C2 SMBUS timeout counter stopped when core is halted*/
	DBG_I2C1_STOP,		/*!< I2C1 SMBUS timeout counter stopped when core is halted*/
	DBG_IWDG_STOP,		/*!< Independent watchdog counter stopped when core is halted*/
	DBG_WWDG_STOP,		/*!< Window watchdog counter stopped when core is halted*/
	DBG_RTC_STOP,		/*!< RTC counter stopped when core is halted*/
	DBG_TIM7_STOP,		/*!< TIM7 counter stopped when core is halted*/
	DBG_TIM6_STOP,		/*!< TIM6 counter stopped when core is halted*/
	DBG_TIM2_STOP,		/*!< TIM2 counter stopped when core is halted*/
};

static constexpr Register<APB1FZR1BitList, APB1FZR1Field> APB1FZR1{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	DBGMCU_APB1FZR2_GROUP		Debug MCU APB1 freeze register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB1FZR2BitList, /**/
					Binary<>{BitPos_t{5}}	// DBG_LPTIM2_STOP
					)

enum class APB1FZR2Field {
	DBG_LPTIM2_STOP,		/*!< LPTIM2 counter stopped when core is halted*/
};

static constexpr Register<APB1FZR2BitList, APB1FZR2Field> APB1FZR2{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	DBGMCU_APB2FZR_GROUP		Debug MCU APB2 freeze register group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB2FZRBitList, /**/
					Binary<>{BitPos_t{17}},	// DBG_TIM16_STOP
					Binary<>{BitPos_t{16}},	// DBG_TIM15_STOP
					Binary<>{BitPos_t{11}}	// DBG_TIM1_STOP
					)

enum class APB2FZRField {
	DBG_TIM16_STOP,		/*!< TIM16 counter stopped when core is halted*/
	DBG_TIM15_STOP,		/*!< TIM15 counter stopped when core is halted*/
	DBG_TIM1_STOP,		/*!< TIM1 counter stopped when core is halted*/
};

static constexpr Register<APB2FZRBitList, APB2FZRField> APB2FZR{BASE_ADDR, 0x10U};
/**@}*/


} // cpp_stm32::dbgmcu::reg
