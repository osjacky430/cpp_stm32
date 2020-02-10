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
	DR,		/*!< Data Register*/
};

static constexpr Register<DRBitList, DRField> DR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	CRC_IDR_GROUP		Independent Data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IDRBitList, /**/
					Bit<8>{BitPos_t{0}}	// IDR
					)

enum class IDRField {
	IDR,		/*!< Independent Data register*/
};

static constexpr Register<IDRBitList, IDRField> IDR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	CRC_CR_GROUP		Control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{0}}	// CR
					)

enum class CRField {
	CR,		/*!< Control regidter*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x08U};
/**@}*/


} // cpp_stm32::crc::reg
