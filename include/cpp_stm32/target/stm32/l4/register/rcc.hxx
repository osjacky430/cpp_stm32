#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"
#include "cpp_stm32/target/stm32/l4/define/rcc.hxx"
#include "cpp_stm32/target/stm32/l4/register/memory_map.hxx"

namespace cpp_stm32::rcc::reg {

static constexpr auto BASE_ADDR = memory_at(PeriphAddr::Ahb1Base, 0x1000U);

/**
 * @defgroup  CR_GROUP        RCC Control Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccCrInfo, /**/
										Bit<1>{BitPos_t{0}}, Bit<1>{BitPos_t{1}}, Bit<1>{BitPos_t{2}}, Bit<1>{BitPos_t{3}},
										Bit<4, MsiRange>{BitPos_t{4}}, Bit<1>{BitPos_t{8}}, Bit<1>{BitPos_t{9}}, Bit<1>{BitPos_t{10}},
										Bit<1>{BitPos_t{11}}, Bit<1>{BitPos_t{16}}, Bit<1>{BitPos_t{17}}, Bit<1>{BitPos_t{18}},
										Bit<1>{BitPos_t{19}}, Bit<1>{BitPos_t{24}}, Bit<1>{BitPos_t{25}}, Bit<1>{BitPos_t{26}},
										Bit<1>{BitPos_t{27}});

enum class CrBit {
	MsiOn,
	MsiRdy,
	MsiPllEn,
	MsiRgSel,
	MsiRange,
	HsiOn,
	HsiKerOn,
	HsiRdy,
	HsiASfS,
	HseOn,
	HseRdy,
	HseByp,
	CssOn,
	PllOn,
	PllRdy,
	PllSaiOn,
	PllSaiRdy
};

constexpr Register<RccCrInfo, CrBit> CR{BASE_ADDR, 0};

/**@}*/

/**
 * @defgroup  CFGR_GROUP    RCC Configuration Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccCfgInfo, /**/
										Bit<2, SysClk>{BitPos_t{0}}, Bit<2, SysClk>{BitPos_t{2}}, Bit<4, HPRE>{BitPos_t{4}},
										Bit<3, PPRE>{BitPos_t{8}}, Bit<3, PPRE>{BitPos_t{11}})

enum class CfgBit { SW, SWS, HPre, PPre1, PPre2 };

static constexpr Register<RccCfgInfo, CfgBit> CFGR{BASE_ADDR, 0x08};

/**@}*/

/**
 * @defgroup  PLLCFGR_GROUP   RCC Pll Configuration Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccPllcfgrBitInfo, /**/
										Bit<2, ClkSrc>{BitPos_t{0}}, Bit<3, PllM>{BitPos_t{4}}, Bit<7, PllN>{BitPos_t{8}},
										Bit<1>{BitPos_t{16}}, Bit<1, PllP>{BitPos_t{17}}, Bit<1>{BitPos_t{20}}, Bit<2, PllQ>{BitPos_t{21}},
										Bit<1>{BitPos_t{24}}, Bit<2, PllR>{BitPos_t{25}}, Bit<5>{BitPos_t{27}})

enum class PllCfgBit { PllSrc, PllM, PllN, PllPEn, PllP, PllQEn, PllQ, PllREn, PllR, PllPDiv };

static constexpr Register<RccPllcfgrBitInfo, PllCfgBit> PLLCFGR{BASE_ADDR, 0x0C};

/**}*/

/**
 * @defgroup	AHB2RST_GROUP		RCC AHB2 Reset Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccAhb2RstInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(13)}, Bit<1>{BitPos_t(18)})

enum class Ahb2RstBit { GpioARst, GpioBRst, GpioCRst, GpioHRst, AdcRst, RngRst };

static constexpr Register<RccAhb2RstInfo, Ahb2RstBit> AHB2RST{BASE_ADDR, 0x2CU};

/**@}*/

/**
 * @defgroup	APB1RST_1_GROUP		RCC APB1 Reset Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb1Rst1Info, /**/
										Bit<1>{BitPos_t{17}}, Bit<1>{BitPos_t{28}})

enum class Apb1Rst1Bit { Usart2Rst, PwrRst };

static constexpr Register<RccApb1Rst1Info, Apb1Rst1Bit> APB1RST_1{BASE_ADDR, 0x38U};

/**@}*/

/**
 * @defgroup	APB2RST_GROUP		RCC APB2 Reset Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb2RstInfo, /**/
										Bit<1>{BitPos_t{14}})

enum class Apb2RstBit { Usart1Rst };

static constexpr Register<RccApb2RstInfo, Apb2RstBit> APB2RST{BASE_ADDR, 0x40U};

/**@}*/

/**
 * @defgroup	AHB2ENR_GROUP		RCC AHB2 Enable Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccAhb2EnrInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(13)}, Bit<1>{BitPos_t(18)})

enum class Ahb2EnrBit { GpioAEn, GpioBEn, GpioCEn, GpioHEn, AdcEn, RngEn };

static constexpr Register<RccAhb2EnrInfo, Ahb2EnrBit> AHB2ENR{BASE_ADDR, 0x4CU};

/**@}*/

/**
 * @defgroup		APB1ENR_GROUP 	RCC APb1 Enable Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb1Enr1Info, /**/
										Bit<1>{BitPos_t{17}}, Bit<1>{BitPos_t{28}})

enum class Apb1Enr1Bit { Usart2En, PwrEn };

static constexpr Register<RccApb1Enr1Info, Apb1Enr1Bit> APB1ENR_1{BASE_ADDR, 0x58U};

/**@}*/

/**
 * @defgroup		APB2ENR_GROUP		RCC APB2 Enable Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb2EnrInfo, /**/
										Bit<1>{BitPos_t{14}})

enum class Apb2EnrBit { Usart1En };

static constexpr Register<RccApb2EnrInfo, Apb2EnrBit> APB2ENR{BASE_ADDR, 0x5CU};

/**@}*/

/**
 * @defgroup  BDCR_GROUP    RCC Backup Domain Control Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccBdcrInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<2>{BitPos_t(3)})

enum class BdcrBit {
	LseOn,
	LseRdy,
	LseByp,
	LseDrv,
};

static constexpr Register<RccBdcrInfo, BdcrBit> BDCR{BASE_ADDR, 0x90U};

/**@}*/

/**
 * @defgroup  CRRCR_GROUP   RCC Clock Recovery RC Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccCrrCrInfo, Bit<1>{BitPos_t{0}}, Bit<1>{BitPos_t{1}}, Bit<9>{BitPos_t{7}})

enum class CrrCrBit { Hsi48On, Hsi48Rdy, Hsi48Cal };

static constexpr Register<RccCrrCrInfo, CrrCrBit> CRRCR{BASE_ADDR, 0x98U};

/**@}*/

}	 // namespace cpp_stm32::rcc::reg
