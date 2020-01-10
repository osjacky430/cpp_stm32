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

#include <cstdint>

#include "cpp_stm32/target/stm32/l4/memory/memory_map.hxx"

#include "cpp_stm32/utility/bit.hxx"
#include "cpp_stm32/utility/constexpr_algo.hxx"
#include "cpp_stm32/utility/register.hxx"

#include "cpp_stm32/target/stm32/common/macro.hxx"

namespace cpp_stm32::stm32::l4 {

static constexpr auto RCC_BASE = memory_at(PeriphAddr::Ahb1Base, 0x1000U);

// @todo I think this can be put in common
template <std::uint32_t Val>
using DivisionFactor_t = std::integral_constant<std::uint32_t, Val>;

template <std::uint32_t Val>
static constexpr auto DivisionFactor_v = DivisionFactor_t<Val>{};

enum class RccOsc : std::uint32_t;

// @todo, consider combining all bitInfo and bit list for rst and en

/**
 * @defgroup  RCC_CR_GROUP        RCC Control Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccCrBitInfo, /**/
										Bit<1>{BitPos_t{0}}, Bit<1>{BitPos_t{1}}, Bit<1>{BitPos_t{2}}, Bit<1>{BitPos_t{3}},
										Bit<4>{BitPos_t{4}}, Bit<1>{BitPos_t{8}}, Bit<1>{BitPos_t{9}}, Bit<1>{BitPos_t{10}},
										Bit<1>{BitPos_t{11}}, Bit<1>{BitPos_t{16}}, Bit<1>{BitPos_t{17}}, Bit<1>{BitPos_t{18}},
										Bit<1>{BitPos_t{19}}, Bit<1>{BitPos_t{24}}, Bit<1>{BitPos_t{25}}, Bit<1>{BitPos_t{26}},
										Bit<1>{BitPos_t{27}});

enum class RccCrBit {
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

constexpr Register<RccCrBitInfo, RccCrBit> RCC_CR{RCC_BASE, 0};

/**@}*/

/**
 * @defgroup  RCC_CFGR_GROUP    RCC Configuration Register Group
 * @{
 */

enum class SysClk : std::uint32_t;

SETUP_DIVISION_FACTOR_WITH_KEY_VAL_PAIR(HPRE, /**/
																				std::pair{1, 0b0000}, std::pair{2, 0b1000}, std::pair{4, 0b1001},
																				std::pair{8, 0b1010}, std::pair{16, 0b1011}, std::pair{64, 0b1100},
																				std::pair{128, 0b1101}, std::pair{256, 0b1110}, std::pair{512, 0b1111});

SETUP_DIVISION_FACTOR_WITH_KEY_VAL_PAIR(PPRE, /**/
																				std::pair{1, 0b000}, std::pair{2, 0b100}, std::pair{4, 0b101},
																				std::pair{8, 0b110}, std::pair{16, 0b111});

SETUP_REGISTER_INFO(RccCfgBitInfo, /**/
										Bit<2, SysClk>{BitPos_t{0}}, Bit<2, SysClk>{BitPos_t{2}}, Bit<4, HPRE>{BitPos_t{4}},
										Bit<3, PPRE>{BitPos_t{8}}, Bit<3, PPRE>{BitPos_t{11}})

enum class RccCfgBit { SW, SWS, HPre, PPre1, PPre2 };

static constexpr Register<RccCfgBitInfo, RccCfgBit> RCC_CFGR{RCC_BASE, 0x08};

/**@}*/

/**
 * @defgroup  RCC_PLLCFGR_GROUP   RCC Pll Configuration Register Group
 * @{
 */

SETUP_DIVISION_FACTOR_WITH_BOUND(PllM, 1, 8);

SETUP_DIVISION_FACTOR_WITH_BOUND(PllN, 8, 86);

SETUP_DIVISION_FACTOR_WITH_KEY_VAL_PAIR(PllP, std::pair{7, 0}, std::pair{17, 1});

SETUP_DIVISION_FACTOR_WITH_KEY_VAL_PAIR(PllQ, /**/
																				std::pair{2, 0b00}, std::pair{4, 0b01}, std::pair{6, 0b10},
																				std::pair{8, 0b11}, );

SETUP_DIVISION_FACTOR_WITH_KEY_VAL_PAIR(PllR, /**/
																				std::pair{2, 0b00}, std::pair{4, 0b01}, std::pair{6, 0b10},
																				std::pair{8, 0b11}, );

SETUP_REGISTER_INFO(RccPllcfgrBitInfo, /**/
										Bit<2, RccOsc>{BitPos_t{0}}, Bit<3, PllM>{BitPos_t{4}}, Bit<7, PllN>{BitPos_t{8}},
										Bit<1>{BitPos_t{16}}, Bit<1, PllP>{BitPos_t{17}}, Bit<1>{BitPos_t{20}}, Bit<2, PllQ>{BitPos_t{21}},
										Bit<1>{BitPos_t{24}}, Bit<2, PllR>{BitPos_t{25}}, Bit<5>{BitPos_t{27}})

enum class RccPllCfgBit { PllSrc, PllM, PllN, PllPEn, PllP, PllQEn, PllQ, PllREn, PllR, PllPDiv };

static constexpr Register<RccPllcfgrBitInfo, RccPllCfgBit> RCC_PLLCFGR{RCC_BASE, 0x0C};

/**}*/

/**
 * @defgroup	RCC_AHB2RST_GROUP		RCC AHB2 Reset Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccAhb2RstInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(13)}, Bit<1>{BitPos_t(18)})

enum class RccAhb2RstBit { GpioARst, GpioBRst, GpioCRst, GpioHRst, AdcRst, RngRst };

static constexpr Register<RccAhb2RstInfo, RccAhb2RstBit> RCC_AHB2RST{RCC_BASE, 0x2CU};

/**@}*/

/**
 * @defgroup	RCC_APB1RST_1_GROUP		RCC APB1 Reset Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb1Rst1Info, /**/
										Bit<1>{BitPos_t{17}}, Bit<1>{BitPos_t{28}})

enum class RccApb1Rst1Bit { Usart2Rst, PwrRst };

static constexpr Register<RccApb1Rst1Info, RccApb1Rst1Bit> RCC_APB1RST_1{RCC_BASE, 0x38U};

/**@}*/

/**
 * @defgroup	RCC_APB2RST_GROUP		RCC APB2 Reset Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb2RstInfo, /**/
										Bit<1>{BitPos_t{14}})

enum class RccApb2RstBit { Usart1Rst };

static constexpr Register<RccApb2RstInfo, RccApb2RstBit> RCC_APB2RST{RCC_BASE, 0x40U};

/**@}*/

/**
 * @defgroup	RCC_AHB2ENR_GROUP		RCC AHB2 Enable Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccAhb2EnrInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(13)}, Bit<1>{BitPos_t(18)})

enum class RccAhb2EnrBit { GpioAEn, GpioBEn, GpioCEn, GpioHEn, AdcEn, RngEn };

static constexpr Register<RccAhb2EnrInfo, RccAhb2EnrBit> RCC_AHB2ENR{RCC_BASE, 0x4CU};

/**@}*/

/**
 * @defgroup		RCC_APB1ENR_GROUP 	RCC APb1 Enable Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb1Enr1Info, /**/
										Bit<1>{BitPos_t{17}}, Bit<1>{BitPos_t{28}})

enum class RccApb1Enr1Bit { Usart2En, PwrEn };

static constexpr Register<RccApb1Enr1Info, RccApb1Enr1Bit> RCC_APB1ENR_1{RCC_BASE, 0x58U};

/**@}*/

/**
 * @defgroup		RCC_APB2ENR_GROUP		RCC APB2 Enable Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccApb2EnrInfo, /**/
										Bit<1>{BitPos_t{14}})

enum class RccApb2EnrBit { Usart1En };

static constexpr Register<RccApb2EnrInfo, RccApb2EnrBit> RCC_APB2ENR{RCC_BASE, 0x5CU};

/**@}*/

/**
 * @defgroup  RCC_BDCR_GROUP    RCC Backup Domain Control Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccBdcrBitInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<2>{BitPos_t(3)})

enum class RccBdcrBit {
	LseOn,
	LseRdy,
	LseByp,
	LseDrv,
};

static constexpr Register<RccBdcrBitInfo, RccBdcrBit> RCC_BDCR{RCC_BASE, 0x90U};

/**@}*/

/**
 * @defgroup  RCC_CRRCR_GROUP   RCC Clock Recovery RC Register Group
 * @{
 */

SETUP_REGISTER_INFO(RccCrrCrBitInfo, Bit<1>{BitPos_t{0}}, Bit<1>{BitPos_t{1}}, Bit<9>{BitPos_t{7}})

enum class RccCrrCrBit { Hsi48On, Hsi48Rdy, Hsi48Cal };

static constexpr Register<RccCrrCrBitInfo, RccCrrCrBit> RCC_CRRCR{RCC_BASE, 0x98U};

/**@}*/

}	// namespace cpp_stm32::stm32::l4
