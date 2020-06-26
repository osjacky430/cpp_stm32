#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::rng::reg {

static constexpr auto BASE_ADDR = 0x50060800U;

/**
 * @defgroup	RNG_CR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{2}},	// RNGEN
					Binary<>{BitPos_t{3}}	// IE
					)

enum class CRField {
	RNGEN,		/*!< Random number generator enable*/
	IE,		/*!< Interrupt enable*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	RNG_SR_GROUP		status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					StatusBit<1>{BitPos_t{0}},	// DRDY
					StatusBit<1>{BitPos_t{1}},	// CECS
					StatusBit<1>{BitPos_t{2}},	// SECS
					Binary<>{BitPos_t{5}},	// CEIS
					Binary<>{BitPos_t{6}}	// SEIS
					)

enum class SRField {
	DRDY,		/*!< Data ready*/
	CECS,		/*!< Clock error current status*/
	SECS,		/*!< Seed error current status*/
	CEIS,		/*!< Clock error interrupt status*/
	SEIS,		/*!< Seed error interrupt status*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	RNG_DR_GROUP		data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// RNDATA
					)

enum class DRField {
	RNDATA,		/*!< Random data*/
};

static constexpr Register<DRBitList, DRField> DR{BASE_ADDR, 0x08U};
/**@}*/


} // cpp_stm32::rng::reg
