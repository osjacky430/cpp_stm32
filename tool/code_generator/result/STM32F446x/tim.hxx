#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::tim::reg {

static constexpr auto BASE_ADDR(Port const& t_tim) {
	switch(t_tim) {
	case Port::TIM1:
		return 0x40010000U;
	case Port::TIM8:
		return 0x40010400U;
	case Port::TIM2:
		return 0x40000000U;
	case Port::TIM3:
		return 0x40000400U;
	case Port::TIM4:
		return 0x40000800U;
	case Port::TIM5:
		return 0x40000c00U;
	case Port::TIM9:
		return 0x40014000U;
	case Port::TIM12:
		return 0x40001800U;
	case Port::TIM10:
		return 0x40014400U;
	case Port::TIM13:
		return 0x40001c00U;
	case Port::TIM14:
		return 0x40002000U;
	case Port::TIM11:
		return 0x40014800U;
	case Port::TIM6:
		return 0x40001000U;
	case Port::TIM7:
		return 0x40001400U;
}
	}

/**
 * @defgroup	TIM7_CR1_GROUP		control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR1BitList, /**/
					Binary<>{BitPos_t{0}},	// CEN
					Binary<>{BitPos_t{1}},	// UDIS
					Binary<>{BitPos_t{2}},	// URS
					Binary<>{BitPos_t{3}},	// OPM
					Binary<>{BitPos_t{7}}	// ARPE
					)

enum class CR1Field {
	CEN,		/*!< Counter enable*/
	UDIS,		/*!< Update disable*/
	URS,		/*!< Update request source*/
	OPM,		/*!< One-pulse mode*/
	ARPE,		/*!< Auto-reload preload enable*/
};

template <Port TIM>
static constexpr Register<CR1BitList, CR1Field> CR1{BASE_ADDR(TIM), 0x00U};
/**@}*/

/**
 * @defgroup	TIM7_CR2_GROUP		control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CR2BitList, /**/
					Bit<3>{BitPos_t{4}}	// MMS
					)

enum class CR2Field {
	MMS,		/*!< Master mode selection*/
};

template <Port TIM>
static constexpr Register<CR2BitList, CR2Field> CR2{BASE_ADDR(TIM), 0x04U};
/**@}*/

/**
 * @defgroup	TIM7_DIER_GROUP		DMA/Interrupt enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DIERBitList, /**/
					Binary<>{BitPos_t{0}},	// UIE
					Binary<>{BitPos_t{8}}	// UDE
					)

enum class DIERField {
	UIE,		/*!< Update interrupt enable*/
	UDE,		/*!< Update DMA request enable*/
};

template <Port TIM>
static constexpr Register<DIERBitList, DIERField> DIER{BASE_ADDR(TIM), 0x0cU};
/**@}*/

/**
 * @defgroup	TIM7_SR_GROUP		status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					Binary<>{BitPos_t{0}}	// UIF
					)

enum class SRField {
	UIF,		/*!< Update interrupt flag*/
};

template <Port TIM>
static constexpr Register<SRBitList, SRField> SR{BASE_ADDR(TIM), 0x10U};
/**@}*/

/**
 * @defgroup	TIM7_EGR_GROUP		event generation register group
 *
 * @{
 */

SETUP_REGISTER_INFO(EGRBitList, /**/
					Binary<>{BitPos_t{0}}	// UG
					)

enum class EGRField {
	UG,		/*!< Update generation*/
};

template <Port TIM>
static constexpr Register<EGRBitList, EGRField> EGR{BASE_ADDR(TIM), 0x14U};
/**@}*/

/**
 * @defgroup	TIM7_CNT_GROUP		counter group
 *
 * @{
 */

SETUP_REGISTER_INFO(CNTBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// CNT
					)

enum class CNTField {
	CNT,		/*!< Low counter value*/
};

template <Port TIM>
static constexpr Register<CNTBitList, CNTField> CNT{BASE_ADDR(TIM), 0x24U};
/**@}*/

/**
 * @defgroup	TIM7_PSC_GROUP		prescaler group
 *
 * @{
 */

SETUP_REGISTER_INFO(PSCBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PSC
					)

enum class PSCField {
	PSC,		/*!< Prescaler value*/
};

template <Port TIM>
static constexpr Register<PSCBitList, PSCField> PSC{BASE_ADDR(TIM), 0x28U};
/**@}*/

/**
 * @defgroup	TIM7_ARR_GROUP		auto-reload register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ARRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// ARR
					)

enum class ARRField {
	ARR,		/*!< Low Auto-reload value*/
};

template <Port TIM>
static constexpr Register<ARRBitList, ARRField> ARR{BASE_ADDR(TIM), 0x2cU};
/**@}*/


} // cpp_stm32::tim::reg
