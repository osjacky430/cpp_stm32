// Copyright (c) 2020 by osjacky430.
// All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the Lesser GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// Lesser GNU General Public License for more details.
//
// You should have received a copy of the Lesser GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <array>
#include <cstdint>
#include <utility>

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"
#include "cpp_stm32/target/stm32/f4/define/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/register/memory_map.hxx"
#include "cpp_stm32/utility/integral_constant.hxx"

namespace cpp_stm32::rcc::reg {

static constexpr auto BASE_ADDR = memory_at(PeriphAddr::Ahb1Base, 0x3800U);

/**
 * @defgroup	RCC_CR_GROUP		RCC Control Register Group
 *
 * @{
 */

SETUP_REGISTER_INFO(RccCrInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(16)}, Bit<1>{BitPos_t(17)},
										Bit<1>{BitPos_t(18)}, Bit<1>{BitPos_t(19)}, Bit<1>{BitPos_t(24)}, Bit<1>{BitPos_t(25)},
										Bit<1>{BitPos_t(26)}, Bit<1>{BitPos_t(27)}, Bit<1>{BitPos_t(28)}, Bit<1>{BitPos_t(29)})

enum class CrBit {
	HsiOn,
	HsiRdy,
	HseOn,
	HseRdy,
	HseByp,
	CssOn,
	PllOn,
	PllRdy,
	PllSaiOn,
	PllSaiRdy,
};

static constexpr Register<RccCrInfo, CrBit> CR{BASE_ADDR, 0};

/** @}*/

/**
 * @defgroup	RCC_PLLCFGR_GROUP		RCC PLL Configuration Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccPllcfgrBitInfo, /**/
										Bit<6, PllM>{BitPos_t{0}}, Bit<9, PllN>{BitPos_t{6}}, Bit<2, PllP>{BitPos_t{16}},
										Bit<1, ClkSrc>{BitPos_t{22}}, Bit<4, PllQ>{BitPos_t{24}}, Bit<3, PllR>{BitPos_t{28}})

enum class PllCfgBit { PLLM, PLLN, PLLP, PLLSRC, PLLQ, PLLR };

static constexpr Register<RccPllcfgrBitInfo, PllCfgBit> PLLCFGR{BASE_ADDR, 0x04U};
/** @}*/

/**
 * @defgroup	RCC_CFG_GROUP		RCC Configuration Group
 *
 * @{
 */

SETUP_REGISTER_INFO(RccCfgInfo, /**/
										Bit<2, SysClk>{BitPos_t(0)}, Bit<2, SysClk>{BitPos_t(2)}, Bit<4, HPRE>{BitPos_t(4)},
										Bit<3, PPRE>{BitPos_t(10)}, Bit<3, PPRE>{BitPos_t(13)})

enum class CfgBit { SW, SWS, HPRE, PPRE1, PPRE2 };

static constexpr Register<RccCfgInfo, CfgBit> CFGR{BASE_ADDR, 0x08U};
/**@} */

/**
 * @defgroup	RCC_AHB1RST_GROUP		RCC AHB1 Reset Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccAhb1RstInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(3)},
										Bit<1>{BitPos_t(4)}, Bit<1>{BitPos_t(5)}, Bit<1>{BitPos_t(6)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(12)}, Bit<1>{BitPos_t(18)}, Bit<1>{BitPos_t(21)}, Bit<1>{BitPos_t(22)},
										Bit<1>{BitPos_t(29)}, Bit<1>{BitPos_t(30)})

enum class Ahb1RstBit {
	GpioARst,
	GpioBRst,
	GpioCRst,
	GpioDRst,
	GpioERst,
	GpioFRst,
	GpioGRst,
	GpioHRst,
	CrcRst,
	BkpSRAMRst,
	Dma1Rst,
	Dma2Rst,
	OtgHsRst
};

static constexpr Register<RccAhb1RstInfo, Ahb1RstBit> AHB1RST{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	RCC_APB1RST_GROUP		RCC APB1 Reset Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb1RstInfo,	 //
										Binary<>{BitPos_t{17}}, Binary<>{BitPos_t{18}}, Binary<>{BitPos_t{19}}, Binary<>{BitPos_t{20}},
										Binary<>{BitPos_t{21}}, Binary<>{BitPos_t{22}}, Binary<>{BitPos_t{23}}, Binary<>{BitPos_t{28}})

enum class Apb1RstBit { Usart2Rst, Usart3Rst, Uart4Rst, Uart5Rst, I2c1Rst, I2c2Rst, I2c3Rst, PwrRst };

static constexpr Register<RccApb1RstInfo, Apb1RstBit> APB1RST{BASE_ADDR, 0x20U};

/**@}*/

/**
 * @defgroup RCC_APB2RST_GROUP		RCC APB2 Reset Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb2RstInfo, Binary<>{BitPos_t{4}}, Binary<>{BitPos_t{5}}, Binary<>{BitPos_t{14}})

enum class Apb2RstBit { Usart1Rst, Usart6Rst, SysCfgRst };

static constexpr Register<RccApb2RstInfo, Apb2RstBit> APB2RST{BASE_ADDR, 0x24U};

/**@}*/

/**
 * @defgroup	RCC_AHB1ENR_GROUP		RCC AHB1 Enable Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccAhb1EnrInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(3)},
										Bit<1>{BitPos_t(4)}, Bit<1>{BitPos_t(5)}, Bit<1>{BitPos_t(6)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(12)}, Bit<1>{BitPos_t(18)}, Bit<1>{BitPos_t(21)}, Bit<1>{BitPos_t(22)},
										Bit<1>{BitPos_t(29)}, Bit<1>{BitPos_t(30)})

enum class Ahb1EnrBit {
	GpioAEn,
	GpioBEn,
	GpioCEn,
	GpioDEn,
	GpioEEn,
	GpioFEn,
	GpioGEn,
	GpioHEn,
	CrcEn,
	BkpSRAMEn,
	Dma1En,
	Dma2En,
	OtgHsEn,
	OtgHsULPIEn
};

static constexpr Register<RccAhb1EnrInfo, Ahb1EnrBit> AHB1ENR{BASE_ADDR, 0x30U};

/**@}*/

/**
 * @defgroup	RCC_APB1ENR_GROUP		RCC APB1 Enable Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb1EnrInfo, /**/
										Binary<>{BitPos_t{17}}, Binary<>{BitPos_t{18}}, Binary<>{BitPos_t{19}}, Binary<>{BitPos_t{20}},
										Binary<>{BitPos_t{21}}, Binary<>{BitPos_t{22}}, Binary<>{BitPos_t{23}}, Binary<>{BitPos_t{28}})

// @todo maybe change to rcc::PeriphClk as index?
enum class Apb1EnrBit { Usart2En, Usart3En, Uart4En, Uart5En, I2c1En, I2c2En, I2c3En, PwrEn };

static constexpr Register<RccApb1EnrInfo, Apb1EnrBit> APB1ENR{BASE_ADDR, 0x40U};

/**@}*/

/**
 * @defgroup RCC_APB2ENR_GROUP		RCC APB2 Enable Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb2EnrInfo, Binary<>{BitPos_t{4}},	// Usart1
										Binary<>{BitPos_t{5}},									// Usart6
										Binary<>{BitPos_t{14}}									// SysCfg
)

enum class Apb2EnrBit { Usart1En, Usart6En, SysCfgEn };

static constexpr Register<RccApb2EnrInfo, Apb2EnrBit> APB2ENR{BASE_ADDR, 0x44U};

/**@}*/

/**
 * @defgroup	RCC_BDCR_GROUP		RCC Backup Domain Control Register Group
 *
 * @{
 */

SETUP_REGISTER_INFO(RccBdcrInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(3)})

enum class BdcrBit {
	LSEON,
	LSERDY,
	LseByp,
	LSEMOD,
};

static constexpr Register<RccBdcrInfo, BdcrBit> BDCR{BASE_ADDR, 0x70U};

/**@}*/

}	 // namespace cpp_stm32::rcc::reg
