#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::crs::reg {

static constexpr auto BASE_ADDR = 0x40006000U;

/**
 * @defgroup	CRS_CR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{0}},	// SYNCOKIE
					Binary<>{BitPos_t{1}},	// SYNCWARNIE
					Binary<>{BitPos_t{2}},	// ERRIE
					Binary<>{BitPos_t{3}},	// ESYNCIE
					Binary<>{BitPos_t{5}},	// CEN
					Binary<>{BitPos_t{6}},	// AUTOTRIMEN
					Binary<>{BitPos_t{7}},	// SWSYNC
					Bit<6>{BitPos_t{8}}	// TRIM
					)

enum class CRField {
	SYNCOKIE,		/*!< SYNC event OK interrupt enable*/
	SYNCWARNIE,		/*!< SYNC warning interrupt enable*/
	ERRIE,		/*!< Synchronization or trimming error interrupt enable*/
	ESYNCIE,		/*!< Expected SYNC interrupt enable*/
	CEN,		/*!< Frequency error counter enable*/
	AUTOTRIMEN,		/*!< Automatic trimming enable*/
	SWSYNC,		/*!< Generate software SYNC event*/
	TRIM,		/*!< HSI48 oscillator smooth trimming*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	CRS_CFGR_GROUP		configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CFGRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}},	// RELOAD
					Bit<8>{BitPos_t{16}},	// FELIM
					Bit<3>{BitPos_t{24}},	// SYNCDIV
					Bit<2>{BitPos_t{28}},	// SYNCSRC
					Binary<>{BitPos_t{31}}	// SYNCPOL
					)

enum class CFGRField {
	RELOAD,		/*!< Counter reload value*/
	FELIM,		/*!< Frequency error limit*/
	SYNCDIV,		/*!< SYNC divider*/
	SYNCSRC,		/*!< SYNC signal source selection*/
	SYNCPOL,		/*!< SYNC polarity selection*/
};

static constexpr Register<CFGRBitList, CFGRField> CFGR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	CRS_ISR_GROUP		interrupt and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISRBitList, /**/
					Binary<>{BitPos_t{0}},	// SYNCOKF
					Binary<>{BitPos_t{1}},	// SYNCWARNF
					Binary<>{BitPos_t{2}},	// ERRF
					Binary<>{BitPos_t{3}},	// ESYNCF
					Binary<>{BitPos_t{8}},	// SYNCERR
					Binary<>{BitPos_t{9}},	// SYNCMISS
					Binary<>{BitPos_t{10}},	// TRIMOVF
					Binary<>{BitPos_t{15}},	// FEDIR
					Bit<16, std::uint16_t>{BitPos_t{16}}	// FECAP
					)

enum class ISRField {
	SYNCOKF,		/*!< SYNC event OK flag*/
	SYNCWARNF,		/*!< SYNC warning flag*/
	ERRF,		/*!< Error flag*/
	ESYNCF,		/*!< Expected SYNC flag*/
	SYNCERR,		/*!< SYNC error*/
	SYNCMISS,		/*!< SYNC missed*/
	TRIMOVF,		/*!< Trimming overflow or underflow*/
	FEDIR,		/*!< Frequency error direction*/
	FECAP,		/*!< Frequency error capture*/
};

static constexpr Register<ISRBitList, ISRField> ISR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	CRS_ICR_GROUP		interrupt flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICRBitList, /**/
					Binary<>{BitPos_t{0}},	// SYNCOKC
					Binary<>{BitPos_t{1}},	// SYNCWARNC
					Binary<>{BitPos_t{2}},	// ERRC
					Binary<>{BitPos_t{3}}	// ESYNCC
					)

enum class ICRField {
	SYNCOKC,		/*!< SYNC event OK clear flag*/
	SYNCWARNC,		/*!< SYNC warning clear flag*/
	ERRC,		/*!< Error clear flag*/
	ESYNCC,		/*!< Expected SYNC clear flag*/
};

static constexpr Register<ICRBitList, ICRField> ICR{BASE_ADDR, 0x0cU};
/**@}*/


} // cpp_stm32::crs::reg
