#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::exti {

enum class Line : std::uint8_t {
	Line0,
	Line1,
	Line2,
	Line3,
	Line4,
	Line5,
	Line6,
	Line7,
	Line8,
	Line9,
	Line10,
	Line11,
	Line12,
	Line13,
	Line14,
	Line15,
	Line16,
	Line17,
	Line18,
	Line19,
	Line20,
	Line21,
	Line22,
};

enum class TriggerType : std::uint8_t { Rise, Fall, Both };

}	 // namespace cpp_stm32::exti

namespace cpp_stm32::exti::reg {

static constexpr auto BASE_ADDR = 0x40013c00U;

SETUP_REGISTER_INFO(ExtiBitList, CREATE_LIST_OF_BITS<Binary<>>(detail::Interval<0, 22>{}))

/**
 * @defgroup	EXTI_IMR_GROUP		Interrupt mask register (EXTI_IMR) group
 *
 * @{
 */

static constexpr Register<ExtiBitList, Line> IMR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	EXTI_EMR_GROUP		Event mask register (EXTI_EMR) group
 *
 * @{
 */

static constexpr Register<ExtiBitList, Line> EMR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	EXTI_RTSR_GROUP		Rising Trigger selection register (EXTI_RTSR) group
 *
 * @{
 */

static constexpr Register<ExtiBitList, Line> RTSR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	EXTI_FTSR_GROUP		Falling Trigger selection register (EXTI_FTSR) group
 *
 * @{
 */

static constexpr Register<ExtiBitList, Line> FTSR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	EXTI_SWIER_GROUP		Software interrupt event register (EXTI_SWIER) group
 *
 * @{
 */

static constexpr Register<ExtiBitList, Line> SWIER{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	EXTI_PR_GROUP		Pending register (EXTI_PR) group
 *
 * @{
 */

SETUP_REGISTER_INFO(PRBitList, CREATE_LIST_OF_BITS<Binary<BitMod::RdClrWr1>>(detail::Interval<0, 22>{}))

static constexpr Register<PRBitList, Line> PR{BASE_ADDR, 0x14U};
/**@}*/

}	 // namespace cpp_stm32::exti::reg
