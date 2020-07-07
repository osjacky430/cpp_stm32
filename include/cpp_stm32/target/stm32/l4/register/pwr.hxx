#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

#include "cpp_stm32/target/stm32/l4/define/pwr.hxx"

namespace cpp_stm32::pwr::reg {

/*!< */
static constexpr auto PWR_BASE = memory_at(PeriphAddr::Apb1Base, 0x7000U);

/**
 * @defgroup  PWR_CR_GROUP		Power Control Register Group
 * @{
 */

SETUP_REGISTER_INFO(PwrCrInfo, /**/
										Bit<2, VoltageScale>{BitPos_t{9}})

enum class CrBit {
	Vos,
};

static constexpr Register<PwrCrInfo, CrBit> CR{PWR_BASE, 0x00U};

/**@}*/

}	// namespace cpp_stm32::pwr::reg
