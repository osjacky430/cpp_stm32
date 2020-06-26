#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::lptim::reg {

static constexpr auto BASE_ADDR(Port const& t_lptim) {
	switch(t_lptim) {
	case Port::LPTIM1:
		return 0x40007c00U;
	case Port::LPTIM2:
		return 0x40009400U;
}
	}

/**
 * @defgroup	LPTIM2_ISR_GROUP		Interrupt and Status Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISRBitList, /**/
					Binary<>{BitPos_t{0}},	// CMPM
					Binary<>{BitPos_t{1}},	// ARRM
					Binary<>{BitPos_t{2}},	// EXTTRIG
					Binary<>{BitPos_t{3}},	// CMPOK
					Binary<>{BitPos_t{4}},	// ARROK
					Binary<>{BitPos_t{5}},	// UP
					Binary<>{BitPos_t{6}}	// DOWN
					)

enum class ISRField {
	CMPM,		/*!< Compare match*/
	ARRM,		/*!< Autoreload match*/
	EXTTRIG,		/*!< External trigger edge event*/
	CMPOK,		/*!< Compare register update OK*/
	ARROK,		/*!< Autoreload register update OK*/
	UP,		/*!< Counter direction change down to up*/
	DOWN,		/*!< Counter direction change up to down*/
};

template <Port LPTIM>
static constexpr Register<ISRBitList, ISRField> ISR{BASE_ADDR(LPTIM), 0x00U};
/**@}*/

/**
 * @defgroup	LPTIM2_ICR_GROUP		Interrupt Clear Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICRBitList, /**/
					Binary<>{BitPos_t{0}},	// CMPMCF
					Binary<>{BitPos_t{1}},	// ARRMCF
					Binary<>{BitPos_t{2}},	// EXTTRIGCF
					Binary<>{BitPos_t{3}},	// CMPOKCF
					Binary<>{BitPos_t{4}},	// ARROKCF
					Binary<>{BitPos_t{5}},	// UPCF
					Binary<>{BitPos_t{6}}	// DOWNCF
					)

enum class ICRField {
	CMPMCF,		/*!< compare match Clear Flag*/
	ARRMCF,		/*!< Autoreload match Clear Flag*/
	EXTTRIGCF,		/*!< External trigger valid edge Clear Flag*/
	CMPOKCF,		/*!< Compare register update OK Clear Flag*/
	ARROKCF,		/*!< Autoreload register update OK Clear Flag*/
	UPCF,		/*!< Direction change to UP Clear Flag*/
	DOWNCF,		/*!< Direction change to down Clear Flag*/
};

template <Port LPTIM>
static constexpr Register<ICRBitList, ICRField> ICR{BASE_ADDR(LPTIM), 0x04U};
/**@}*/

/**
 * @defgroup	LPTIM2_IER_GROUP		Interrupt Enable Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IERBitList, /**/
					Binary<>{BitPos_t{0}},	// CMPMIE
					Binary<>{BitPos_t{1}},	// ARRMIE
					Binary<>{BitPos_t{2}},	// EXTTRIGIE
					Binary<>{BitPos_t{3}},	// CMPOKIE
					Binary<>{BitPos_t{4}},	// ARROKIE
					Binary<>{BitPos_t{5}},	// UPIE
					Binary<>{BitPos_t{6}}	// DOWNIE
					)

enum class IERField {
	CMPMIE,		/*!< Compare match Interrupt Enable*/
	ARRMIE,		/*!< Autoreload match Interrupt Enable*/
	EXTTRIGIE,		/*!< External trigger valid edge Interrupt Enable*/
	CMPOKIE,		/*!< Compare register update OK Interrupt Enable*/
	ARROKIE,		/*!< Autoreload register update OK Interrupt Enable*/
	UPIE,		/*!< Direction change to UP Interrupt Enable*/
	DOWNIE,		/*!< Direction change to down Interrupt Enable*/
};

template <Port LPTIM>
static constexpr Register<IERBitList, IERField> IER{BASE_ADDR(LPTIM), 0x08U};
/**@}*/

/**
 * @defgroup	LPTIM2_CFGR_GROUP		Configuration Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CFGRBitList, /**/
					Binary<>{BitPos_t{0}},	// CKSEL
					Bit<2>{BitPos_t{1}},	// CKPOL
					Bit<2>{BitPos_t{3}},	// CKFLT
					Bit<2>{BitPos_t{6}},	// TRGFLT
					Bit<3>{BitPos_t{9}},	// PRESC
					Bit<3>{BitPos_t{13}},	// TRIGSEL
					Bit<2>{BitPos_t{17}},	// TRIGEN
					Binary<>{BitPos_t{19}},	// TIMOUT
					Binary<>{BitPos_t{20}},	// WAVE
					Binary<>{BitPos_t{21}},	// WAVPOL
					Binary<>{BitPos_t{22}},	// PRELOAD
					Binary<>{BitPos_t{23}},	// COUNTMODE
					Binary<>{BitPos_t{24}}	// ENC
					)

enum class CFGRField {
	CKSEL,		/*!< Clock selector*/
	CKPOL,		/*!< Clock Polarity*/
	CKFLT,		/*!< Configurable digital filter for external clock*/
	TRGFLT,		/*!< Configurable digital filter for trigger*/
	PRESC,		/*!< Clock prescaler*/
	TRIGSEL,		/*!< Trigger selector*/
	TRIGEN,		/*!< Trigger enable and polarity*/
	TIMOUT,		/*!< Timeout enable*/
	WAVE,		/*!< Waveform shape*/
	WAVPOL,		/*!< Waveform shape polarity*/
	PRELOAD,		/*!< Registers update mode*/
	COUNTMODE,		/*!< counter mode enabled*/
	ENC,		/*!< Encoder mode enable*/
};

template <Port LPTIM>
static constexpr Register<CFGRBitList, CFGRField> CFGR{BASE_ADDR(LPTIM), 0x0cU};
/**@}*/

/**
 * @defgroup	LPTIM2_CR_GROUP		Control Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{0}},	// ENABLE
					Binary<>{BitPos_t{1}},	// SNGSTRT
					Binary<>{BitPos_t{2}}	// CNTSTRT
					)

enum class CRField {
	ENABLE,		/*!< LPTIM Enable*/
	SNGSTRT,		/*!< LPTIM start in single mode*/
	CNTSTRT,		/*!< Timer start in continuous mode*/
};

template <Port LPTIM>
static constexpr Register<CRBitList, CRField> CR{BASE_ADDR(LPTIM), 0x10U};
/**@}*/

/**
 * @defgroup	LPTIM2_CMP_GROUP		Compare Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CMPBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// CMP
					)

enum class CMPField {
	CMP,		/*!< Compare value*/
};

template <Port LPTIM>
static constexpr Register<CMPBitList, CMPField> CMP{BASE_ADDR(LPTIM), 0x14U};
/**@}*/

/**
 * @defgroup	LPTIM2_ARR_GROUP		Autoreload Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ARRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// ARR
					)

enum class ARRField {
	ARR,		/*!< Auto reload value*/
};

template <Port LPTIM>
static constexpr Register<ARRBitList, ARRField> ARR{BASE_ADDR(LPTIM), 0x18U};
/**@}*/

/**
 * @defgroup	LPTIM2_CNT_GROUP		Counter Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CNTBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// CNT
					)

enum class CNTField {
	CNT,		/*!< Counter value*/
};

template <Port LPTIM>
static constexpr Register<CNTBitList, CNTField> CNT{BASE_ADDR(LPTIM), 0x1cU};
/**@}*/


} // cpp_stm32::lptim::reg
