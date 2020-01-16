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

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"
#include "cpp_stm32/utility/constexpr_algo.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

#include "cpp_stm32/utility/macro.hxx"

namespace cpp_stm32::rcc {

SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(MsiRange, /**/
																		 std::pair{100_KHz, 0b000}, std::pair{200_KHz, 0b0001}, std::pair{400_KHz, 0b0010},
																		 std::pair{800_KHz, 0b0011}, std::pair{1_MHz, 0b0100}, std::pair{2_MHz, 0b0101},
																		 std::pair{4_MHz, 0b0110}, std::pair{8_MHz, 0b0111}, std::pair{16_MHz, 0b1000},
																		 std::pair{24_MHz, 0b1001}, std::pair{32_MHz, 0b1010}, std::pair{48_MHz, 0b1011});

SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(HPRE, /**/
																		 std::pair{1, 0b0000}, std::pair{2, 0b1000}, std::pair{4, 0b1001},
																		 std::pair{8, 0b1010}, std::pair{16, 0b1011}, std::pair{64, 0b1100},
																		 std::pair{128, 0b1101}, std::pair{256, 0b1110}, std::pair{512, 0b1111});

SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(PPRE, /**/
																		 std::pair{1, 0b000}, std::pair{2, 0b100}, std::pair{4, 0b101}, std::pair{8, 0b110},
																		 std::pair{16, 0b111});

SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(PllM, /**/
																		 std::pair{1, 0b000}, std::pair{2, 0b001}, std::pair{3, 0b010}, std::pair{4, 0b011},
																		 std::pair{5, 0b100}, std::pair{6, 0b101}, std::pair{7, 0b110},
																		 std::pair{8, 0b111});

SETUP_LOOKUP_TABLE_WITH_BOUND(PllN, 8, 86);

SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(PllP, std::pair{7, 0}, std::pair{17, 1});

SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(PllQ, /**/
																		 std::pair{2, 0b00}, std::pair{4, 0b01}, std::pair{6, 0b10}, std::pair{8, 0b11}, );

SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(PllR, /**/
																		 std::pair{2, 0b00}, std::pair{4, 0b01}, std::pair{6, 0b10}, std::pair{8, 0b11}, );

enum class SysClk : std::uint32_t;
enum class ClkSrc : std::uint32_t;

}	 // namespace cpp_stm32::rcc

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
