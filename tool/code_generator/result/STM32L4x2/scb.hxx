#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::scb::reg {

static constexpr auto BASE_ADDR(Port const& t_scb) {
	switch(t_scb) {
	case Port::SCB:
		return 0xe000ed00U;
	case Port::SCB_ACTRL:
		return 0xe000e008U;
}
	}

/**
 * @defgroup	SCB_ACTRL_ACTRL_GROUP		Auxiliary control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ACTRLBitList, /**/
					Binary<>{BitPos_t{9}},	// DISOOFP
					Binary<>{BitPos_t{8}},	// DISFPCA
					Binary<>{BitPos_t{2}},	// DISFOLD
					Binary<>{BitPos_t{1}},	// DISDEFWBUF
					Binary<>{BitPos_t{0}}	// DISMCYCINT
					)

enum class ACTRLField {
	DISOOFP,		/*!< DISOOFP*/
	DISFPCA,		/*!< DISFPCA*/
	DISFOLD,		/*!< DISFOLD*/
	DISDEFWBUF,		/*!< DISDEFWBUF*/
	DISMCYCINT,		/*!< DISMCYCINT*/
};

template <Port SCB>
static constexpr Register<ACTRLBitList, ACTRLField> ACTRL{BASE_ADDR(SCB), 0x00U};
/**@}*/


} // cpp_stm32::scb::reg
