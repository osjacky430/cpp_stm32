#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::dbg::reg {

static constexpr auto BASE_ADDR = 0xe0042000U;

/**
 * @defgroup	DBG_DBGMCU_IDCODE_GROUP		IDCODE group
 *
 * @{
 */

SETUP_REGISTER_INFO(DBGMCU_IDCODEBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{16}},	// REV_ID
					Bit<12, std::uint16_t>{BitPos_t{0}}	// DEV_ID
					)

enum class DBGMCU_IDCODEField {
	REV_ID,		/*!< REV_ID*/
	DEV_ID,		/*!< DEV_ID*/
};

static constexpr Register<DBGMCU_IDCODEBitList, DBGMCU_IDCODEField> DBGMCU_IDCODE{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	DBG_DBGMCU_CR_GROUP		Control Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DBGMCU_CRBitList, /**/
					Bit<2>{BitPos_t{6}},	// TRACE_MODE
					Binary<>{BitPos_t{5}},	// TRACE_IOEN
					Binary<>{BitPos_t{2}},	// DBG_STANDBY
					Binary<>{BitPos_t{1}},	// DBG_STOP
					Binary<>{BitPos_t{0}}	// DBG_SLEEP
					)

enum class DBGMCU_CRField {
	TRACE_MODE,		/*!< TRACE_MODE*/
	TRACE_IOEN,		/*!< TRACE_IOEN*/
	DBG_STANDBY,		/*!< DBG_STANDBY*/
	DBG_STOP,		/*!< DBG_STOP*/
	DBG_SLEEP,		/*!< DBG_SLEEP*/
};

static constexpr Register<DBGMCU_CRBitList, DBGMCU_CRField> DBGMCU_CR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	DBG_DBGMCU_APB1_FZ_GROUP		Debug MCU APB1 Freeze registe group
 *
 * @{
 */

SETUP_REGISTER_INFO(DBGMCU_APB1_FZBitList, /**/
					Binary<>{BitPos_t{26}},	// DBG_CAN2_STOP
					Binary<>{BitPos_t{25}},	// DBG_CAN1_STOP
					Binary<>{BitPos_t{24}},	// DBG_I2CFMP_SMBUS_TIMEOUT
					Binary<>{BitPos_t{23}},	// DBG_J2C3SMBUS_TIMEOUT
					Binary<>{BitPos_t{22}},	// DBG_J2C2_SMBUS_TIMEOUT
					Binary<>{BitPos_t{21}},	// DBG_J2C1_SMBUS_TIMEOUT
					Binary<>{BitPos_t{12}},	// DBG_IWDEG_STOP
					Binary<>{BitPos_t{11}},	// DBG_WWDG_STOP
					Binary<>{BitPos_t{10}},	// DBG_RTC_STOP
					Binary<>{BitPos_t{8}},	// DBG_TIM14_STOP
					Binary<>{BitPos_t{7}},	// DBG_TIM13_STOP
					Binary<>{BitPos_t{6}},	// DBG_TIM12_STOP
					Binary<>{BitPos_t{5}},	// DBG_TIM7_STOP
					Binary<>{BitPos_t{4}},	// DBG_TIM6_STOP
					Binary<>{BitPos_t{3}},	// DBG_TIM5_STOP
					Binary<>{BitPos_t{2}},	// DBG_TIM4_STOP
					Binary<>{BitPos_t{1}},	// DBG_TIM3_STOP
					Binary<>{BitPos_t{0}}	// DBG_TIM2_STOP
					)

enum class DBGMCU_APB1_FZField {
	DBG_CAN2_STOP,		/*!< DBG_CAN2_STOP*/
	DBG_CAN1_STOP,		/*!< DBG_CAN1_STOP*/
	DBG_I2CFMP_SMBUS_TIMEOUT,		/*!< SMBUS timeout mode stopped when Core is halted*/
	DBG_J2C3SMBUS_TIMEOUT,		/*!< DBG_J2C3SMBUS_TIMEOUT*/
	DBG_J2C2_SMBUS_TIMEOUT,		/*!< DBG_J2C2_SMBUS_TIMEOUT*/
	DBG_J2C1_SMBUS_TIMEOUT,		/*!< DBG_J2C1_SMBUS_TIMEOUT*/
	DBG_IWDEG_STOP,		/*!< DBG_IWDEG_STOP*/
	DBG_WWDG_STOP,		/*!< DBG_WWDG_STOP*/
	DBG_RTC_STOP,		/*!< RTC stopped when Core is halted*/
	DBG_TIM14_STOP,		/*!< DBG_TIM14_STOP*/
	DBG_TIM13_STOP,		/*!< DBG_TIM13_STOP*/
	DBG_TIM12_STOP,		/*!< DBG_TIM12_STOP*/
	DBG_TIM7_STOP,		/*!< DBG_TIM7_STOP*/
	DBG_TIM6_STOP,		/*!< DBG_TIM6_STOP*/
	DBG_TIM5_STOP,		/*!< DBG_TIM5_STOP*/
	DBG_TIM4_STOP,		/*!< DBG_TIM4_STOP*/
	DBG_TIM3_STOP,		/*!< DBG_TIM3 _STOP*/
	DBG_TIM2_STOP,		/*!< DBG_TIM2_STOP*/
};

static constexpr Register<DBGMCU_APB1_FZBitList, DBGMCU_APB1_FZField> DBGMCU_APB1_FZ{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	DBG_DBGMCU_APB2_FZ_GROUP		Debug MCU APB2 Freeze registe group
 *
 * @{
 */

SETUP_REGISTER_INFO(DBGMCU_APB2_FZBitList, /**/
					Binary<>{BitPos_t{18}},	// DBG_TIM11_STOP
					Binary<>{BitPos_t{17}},	// DBG_TIM10_STOP
					Binary<>{BitPos_t{16}},	// DBG_TIM9_STOP
					Binary<>{BitPos_t{1}},	// DBG_TIM8_STOP
					Binary<>{BitPos_t{0}}	// DBG_TIM1_STOP
					)

enum class DBGMCU_APB2_FZField {
	DBG_TIM11_STOP,		/*!< TIM11 counter stopped when core is halted*/
	DBG_TIM10_STOP,		/*!< TIM10 counter stopped when core is halted*/
	DBG_TIM9_STOP,		/*!< TIM9 counter stopped when core is halted*/
	DBG_TIM8_STOP,		/*!< TIM8 counter stopped when core is halted*/
	DBG_TIM1_STOP,		/*!< TIM1 counter stopped when core is halted*/
};

static constexpr Register<DBGMCU_APB2_FZBitList, DBGMCU_APB2_FZField> DBGMCU_APB2_FZ{BASE_ADDR, 0x0cU};
/**@}*/


} // cpp_stm32::dbg::reg
