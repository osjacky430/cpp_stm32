#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::nvic::reg {

static constexpr auto BASE_ADDR(Port const& t_nvic) {
	switch(t_nvic) {
	case Port::NVIC:
		return 0xe000e100U;
	case Port::NVIC_STIR:
		return 0xe000ef00U;
}
	}

/**
 * @defgroup	NVIC_STIR_STIR_GROUP		Software trigger interrupt register group
 *
 * @{
 */

SETUP_REGISTER_INFO(STIRBitList, /**/
					Bit<9, std::uint16_t>{BitPos_t{0}}	// INTID
					)

enum class STIRField {
	INTID,		/*!< Software generated interrupt ID*/
};

template <Port NVIC>
static constexpr Register<STIRBitList, STIRField> STIR{BASE_ADDR(NVIC), 0x00U};
/**@}*/


} // cpp_stm32::nvic::reg
