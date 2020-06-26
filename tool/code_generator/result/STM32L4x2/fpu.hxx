#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::fpu::reg {

static constexpr auto BASE_ADDR(Port const& t_fpu) {
	switch(t_fpu) {
	case Port::FPU:
		return 0xe000ef34U;
	case Port::FPU_CPACR:
		return 0xe000ed88U;
}
	}

/**
 * @defgroup	FPU_CPACR_CPACR_GROUP		Coprocessor access control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CPACRBitList, /**/
					Bit<4>{BitPos_t{20}}	// CP
					)

enum class CPACRField {
	CP,		/*!< CP*/
};

template <Port FPU>
static constexpr Register<CPACRBitList, CPACRField> CPACR{BASE_ADDR(FPU), 0x00U};
/**@}*/


} // cpp_stm32::fpu::reg
