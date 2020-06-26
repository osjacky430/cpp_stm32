#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::firewall::reg {

static constexpr auto BASE_ADDR = 0x40011c00U;

/**
 * @defgroup	FIREWALL_CSSA_GROUP		Code segment start address group
 *
 * @{
 */

SETUP_REGISTER_INFO(CSSABitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{8}}	// ADD
					)

enum class CSSAField {
	ADD,		/*!< code segment start address*/
};

static constexpr Register<CSSABitList, CSSAField> CSSA{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	FIREWALL_CSL_GROUP		Code segment length group
 *
 * @{
 */

SETUP_REGISTER_INFO(CSLBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{8}}	// LENG
					)

enum class CSLField {
	LENG,		/*!< code segment length*/
};

static constexpr Register<CSLBitList, CSLField> CSL{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	FIREWALL_NVDSSA_GROUP		Non-volatile data segment start address group
 *
 * @{
 */

SETUP_REGISTER_INFO(NVDSSABitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{8}}	// ADD
					)

enum class NVDSSAField {
	ADD,		/*!< Non-volatile data segment start address*/
};

static constexpr Register<NVDSSABitList, NVDSSAField> NVDSSA{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	FIREWALL_NVDSL_GROUP		Non-volatile data segment length group
 *
 * @{
 */

SETUP_REGISTER_INFO(NVDSLBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{8}}	// LENG
					)

enum class NVDSLField {
	LENG,		/*!< Non-volatile data segment length*/
};

static constexpr Register<NVDSLBitList, NVDSLField> NVDSL{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	FIREWALL_VDSSA_GROUP		Volatile data segment start address group
 *
 * @{
 */

SETUP_REGISTER_INFO(VDSSABitList, /**/
					Bit<10, std::uint16_t>{BitPos_t{6}}	// ADD
					)

enum class VDSSAField {
	ADD,		/*!< Volatile data segment start address*/
};

static constexpr Register<VDSSABitList, VDSSAField> VDSSA{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	FIREWALL_VDSL_GROUP		Volatile data segment length group
 *
 * @{
 */

SETUP_REGISTER_INFO(VDSLBitList, /**/
					Bit<10, std::uint16_t>{BitPos_t{6}}	// LENG
					)

enum class VDSLField {
	LENG,		/*!< Non-volatile data segment length*/
};

static constexpr Register<VDSLBitList, VDSLField> VDSL{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	FIREWALL_CR_GROUP		Configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{0}},	// FPA
					Binary<>{BitPos_t{1}},	// VDS
					Binary<>{BitPos_t{2}}	// VDE
					)

enum class CRField {
	FPA,		/*!< Firewall pre alarm*/
	VDS,		/*!< Volatile data shared*/
	VDE,		/*!< Volatile data execution*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x20U};
/**@}*/


} // cpp_stm32::firewall::reg
