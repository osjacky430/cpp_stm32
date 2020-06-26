#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::mpu::reg {

static constexpr auto BASE_ADDR = 0xe000ed90U;

/**
 * @defgroup	MPU_MPU_TYPER_GROUP		MPU type register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MPU_TYPERBitList, /**/
					Bit<8>{BitPos_t{16}},	// IREGION
					Bit<8>{BitPos_t{8}},	// DREGION
					Binary<>{BitPos_t{0}}	// SEPARATE
					)

enum class MPU_TYPERField {
	IREGION,		/*!< Number of MPU instruction regions*/
	DREGION,		/*!< Number of MPU data regions*/
	SEPARATE,		/*!< Separate flag*/
};

static constexpr Register<MPU_TYPERBitList, MPU_TYPERField> MPU_TYPER{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	MPU_MPU_CTRL_GROUP		MPU control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MPU_CTRLBitList, /**/
					Binary<>{BitPos_t{2}},	// PRIVDEFENA
					Binary<>{BitPos_t{1}},	// HFNMIENA
					Binary<>{BitPos_t{0}}	// ENABLE
					)

enum class MPU_CTRLField {
	PRIVDEFENA,		/*!< Enable priviliged software access to default memory map*/
	HFNMIENA,		/*!< Enables the operation of MPU during hard fault*/
	ENABLE,		/*!< Enables the MPU*/
};

static constexpr Register<MPU_CTRLBitList, MPU_CTRLField> MPU_CTRL{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	MPU_MPU_RNR_GROUP		MPU region number register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MPU_RNRBitList, /**/
					Bit<8>{BitPos_t{0}}	// REGION
					)

enum class MPU_RNRField {
	REGION,		/*!< MPU region*/
};

static constexpr Register<MPU_RNRBitList, MPU_RNRField> MPU_RNR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	MPU_MPU_RBAR_GROUP		MPU region base address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MPU_RBARBitList, /**/
					Bit<27, std::uint32_t>{BitPos_t{5}},	// ADDR
					Binary<>{BitPos_t{4}},	// VALID
					Bit<4>{BitPos_t{0}}	// REGION
					)

enum class MPU_RBARField {
	ADDR,		/*!< Region base address field*/
	VALID,		/*!< MPU region number valid*/
	REGION,		/*!< MPU region field*/
};

static constexpr Register<MPU_RBARBitList, MPU_RBARField> MPU_RBAR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	MPU_MPU_RASR_GROUP		MPU region attribute and size register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MPU_RASRBitList, /**/
					Binary<>{BitPos_t{28}},	// XN
					Bit<3>{BitPos_t{24}},	// AP
					Bit<3>{BitPos_t{19}},	// TE
					Binary<>{BitPos_t{18}},	// S
					Bit<8>{BitPos_t{8}},	// SRD
					Bit<5>{BitPos_t{1}},	// SIZE
					Binary<>{BitPos_t{0}}	// ENABLE
					)

enum class MPU_RASRField {
	XN,		/*!< Instruction access disable bit*/
	AP,		/*!< Access permission*/
	TE,		/*!< memory attribute*/
	S,		/*!< Shareable memory attribute*/
	SRD,		/*!< Subregion disable bits*/
	SIZE,		/*!< Size of the MPU protection region*/
	ENABLE,		/*!< Region enable bit.*/
};

static constexpr Register<MPU_RASRBitList, MPU_RASRField> MPU_RASR{BASE_ADDR, 0x10U};
/**@}*/


} // cpp_stm32::mpu::reg
