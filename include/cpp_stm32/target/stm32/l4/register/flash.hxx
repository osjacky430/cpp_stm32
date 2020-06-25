#pragma once

#include "cpp_stm32/target/stm32/l4/define/flash.hxx"
#include "cpp_stm32/target/stm32/l4/register/memory_map.hxx"

namespace cpp_stm32::flash::reg {

static constexpr auto BASE_ADDR = memory_at(PeriphAddr::Ahb1Base, 0x2'000U);

/**
 * @defgroup ACR_GROUP    Flash Access Control Register Group
 * @{
 */

SETUP_REGISTER_INFO(FlashAcrInfo, /**/
										Bit<3, Latency>{BitPos_t{0}}, Binary<>{BitPos_t{8}}, Binary<>{BitPos_t{9}}, Binary<>{BitPos_t{10}},
										Binary<>{BitPos_t{11}}, Binary<>{BitPos_t{12}})

enum class AcrBit {
	Latency,
	PrftEn,
	ICEn,
	DCEn,
	ICRst,
	DCRst,
};

static constexpr Register<FlashAcrInfo, AcrBit> ACR{BASE_ADDR, 0x00U};

/**@}*/

}	 // namespace cpp_stm32::flash::reg
