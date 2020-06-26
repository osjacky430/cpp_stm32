#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::crc::reg {

static constexpr auto BASE_ADDR = 0x40023000U;

/**
 * @defgroup	CRC_DR_GROUP		Data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// DR
					)

enum class DRField {
	DR,		/*!< Data register bits*/
};

static constexpr Register<DRBitList, DRField> DR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	CRC_IDR_GROUP		Independent data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IDRBitList, /**/
					Bit<8>{BitPos_t{0}}	// IDR
					)

enum class IDRField {
	IDR,		/*!< General-purpose 8-bit data register bits*/
};

static constexpr Register<IDRBitList, IDRField> IDR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	CRC_CR_GROUP		Control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<BitMod::WrOnly>{BitPos_t{0}},	// RESET
					Bit<2>{BitPos_t{3}},	// POLYSIZE
					Bit<2>{BitPos_t{5}},	// REV_IN
					Binary<>{BitPos_t{7}}	// REV_OUT
					)

enum class CRField {
	RESET,		/*!< RESET bit*/
	POLYSIZE,		/*!< Polynomial size*/
	REV_IN,		/*!< Reverse input data*/
	REV_OUT,		/*!< Reverse output data*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	CRC_INIT_GROUP		Initial CRC value group
 *
 * @{
 */

SETUP_REGISTER_INFO(INITBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CRC_INIT
					)

enum class INITField {
	CRC_INIT,		/*!< Programmable initial CRC value*/
};

static constexpr Register<INITBitList, INITField> INIT{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	CRC_POL_GROUP		polynomial group
 *
 * @{
 */

SETUP_REGISTER_INFO(POLBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// Polynomialcoefficients
					)

enum class POLField {
	Polynomialcoefficients,		/*!< Programmable polynomial*/
};

static constexpr Register<POLBitList, POLField> POL{BASE_ADDR, 0x14U};
/**@}*/


} // cpp_stm32::crc::reg
