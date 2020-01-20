#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::syscfg::reg {

static constexpr auto BASE_ADDR = 0x40013800U;

/**
 * @defgroup	SYSCFG_MEMRM_GROUP		memory remap register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MEMRMBitList, /**/
					Bit<2>{BitPos_t{10}},	// SWP_FMC
					Binary<>{BitPos_t{8}},	// FB_MODE
					Bit<3>{BitPos_t{0}}	// MEM_MODE
					)

enum class MEMRMField {
	SWP_FMC,		/*!< FMC memory mapping swap*/
	FB_MODE,		/*!< Flash bank mode selection*/
	MEM_MODE,		/*!< Memory mapping selection*/
};

static constexpr Register<MEMRMBitList, MEMRMField> MEMRM{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	SYSCFG_PMC_GROUP		peripheral mode configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PMCBitList, /**/
					Binary<>{BitPos_t{18}},	// ADC3DC2
					Binary<>{BitPos_t{17}},	// ADC2DC2
					Binary<>{BitPos_t{16}},	// ADC1DC2
					Binary<>{BitPos_t{23}}	// MII_RMII_SEL
					)

enum class PMCField {
	ADC3DC2,		/*!< ADC3DC2*/
	ADC2DC2,		/*!< ADC2DC2*/
	ADC1DC2,		/*!< ADC1DC2*/
	MII_RMII_SEL,		/*!< Ethernet PHY interface selection*/
};

static constexpr Register<PMCBitList, PMCField> PMC{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	SYSCFG_EXTICR1_GROUP		external interrupt configuration register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(EXTICR1BitList, /**/
					Bit<4>{BitPos_t{0}}	// EXTI
					)

enum class EXTICR1Field {
	EXTI,		/*!< EXTI x configuration (x = 0 to 3)*/
};

static constexpr Register<EXTICR1BitList, EXTICR1Field> EXTICR1{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	SYSCFG_EXTICR2_GROUP		external interrupt configuration register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(EXTICR2BitList, /**/
					Bit<4>{BitPos_t{0}}	// EXTI
					)

enum class EXTICR2Field {
	EXTI,		/*!< EXTI x configuration (x = 4 to 7)*/
};

static constexpr Register<EXTICR2BitList, EXTICR2Field> EXTICR2{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	SYSCFG_EXTICR3_GROUP		external interrupt configuration register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(EXTICR3BitList, /**/
					Bit<3>{BitPos_t{0}},	// EXTI
					Bit<4>{BitPos_t{8}}	// EXTI10
					)

enum class EXTICR3Field {
	EXTI,		/*!< EXTI x configuration (x = 8 to 11)*/
	EXTI10,		/*!< EXTI10*/
};

static constexpr Register<EXTICR3BitList, EXTICR3Field> EXTICR3{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	SYSCFG_EXTICR4_GROUP		external interrupt configuration register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(EXTICR4BitList, /**/
					Bit<4>{BitPos_t{0}}	// EXTI1
					)

enum class EXTICR4Field {
	EXTI1,		/*!< EXTI x configuration (x = 12 to 15)*/
};

static constexpr Register<EXTICR4BitList, EXTICR4Field> EXTICR4{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	SYSCFG_CMPCR_GROUP		Compensation cell control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CMPCRBitList, /**/
					Binary<>{BitPos_t{0}},	// CMP_PD
					Binary<>{BitPos_t{8}}	// READY
					)

enum class CMPCRField {
	CMP_PD,		/*!< Compensation cell power-down*/
	READY,		/*!< READY*/
};

static constexpr Register<CMPCRBitList, CMPCRField> CMPCR{BASE_ADDR, 0x20U};
/**@}*/


} // cpp_stm32::syscfg::reg
