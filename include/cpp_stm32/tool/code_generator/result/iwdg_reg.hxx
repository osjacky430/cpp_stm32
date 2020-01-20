#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::iwdg::reg {

static constexpr auto BASE_ADDR = 0x40003000U;

/**
 * @defgroup	IWDG_KR_GROUP		Key register group
 *
 * @{
 */

SETUP_REGISTER_INFO(KRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// KEY
					)

enum class KRField {
	KEY,		/*!< Key value (write only, read 0000h)*/
};

static constexpr Register<KRBitList, KRField> KR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	IWDG_PR_GROUP		Prescaler register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PRBitList, /**/
					Bit<3>{BitPos_t{0}}	// PR
					)

enum class PRField {
	PR,		/*!< Prescaler divider*/
};

static constexpr Register<PRBitList, PRField> PR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	IWDG_RLR_GROUP		Reload register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RLRBitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}}	// RL
					)

enum class RLRField {
	RL,		/*!< Watchdog counter reload value*/
};

static constexpr Register<RLRBitList, RLRField> RLR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	IWDG_SR_GROUP		Status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					Binary<>{BitPos_t{0}},	// PVU
					Binary<>{BitPos_t{1}}	// RVU
					)

enum class SRField {
	PVU,		/*!< Watchdog prescaler value update*/
	RVU,		/*!< Watchdog counter reload value update*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x0cU};
/**@}*/


} // cpp_stm32::iwdg::reg
