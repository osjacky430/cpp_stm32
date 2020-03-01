/**
 * @file  stm32/f4/register/syscfg.hxx
 * @brief	SysCfg register for stm32f4
 */

/** Copyright (c) 2020 by osjacky430.
 * All Rights Reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

#include "cpp_stm32/target/stm32/f4/define/exti.hxx"
#include "cpp_stm32/target/stm32/f4/define/gpio.hxx"

namespace cpp_stm32::syscfg::reg {

static constexpr auto BASE_ADDR = 0x40013800U;

static constexpr auto OFFSET(gpio::Pin const t_exticr) {
	switch (to_underlying(t_exticr) / 4) {
		case 0:
			return 0x08U;
		case 1:
			return 0x0CU;
		case 2:
			return 0x10U;
		case 3:
			return 0x14U;
	}
}

struct ExtiCRxIdxPolicy {
	static constexpr auto TO_IDX(gpio::Pin const t_line) noexcept { return to_underlying(t_line) % 4; }
};

/**
 * @defgroup	SYSCFG_MEMRM_GROUP		memory remap register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MEMRMBitList,						/**/
										Bit<2>{BitPos_t{10}},		// SWP_FMC
										Binary<>{BitPos_t{8}},	// FB_MODE
										Bit<3>{BitPos_t{0}}			// MEM_MODE
)

enum class MEMRMField {
	SWP_FMC,	/*!< FMC memory mapping swap*/
	FB_MODE,	/*!< Flash bank mode selection*/
	MEM_MODE, /*!< Memory mapping selection*/
};

static constexpr Register<MEMRMBitList, MEMRMField> MEMRM{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	SYSCFG_PMC_GROUP		peripheral mode configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PMCBitList,							 /**/
										Binary<>{BitPos_t{18}},	 // ADC3DC2
										Binary<>{BitPos_t{17}},	 // ADC2DC2
										Binary<>{BitPos_t{16}},	 // ADC1DC2
										Binary<>{BitPos_t{23}}	 // MII_RMII_SEL
)

enum class PMCField {
	ADC3DC2,			/*!< ADC3DC2*/
	ADC2DC2,			/*!< ADC2DC2*/
	ADC1DC2,			/*!< ADC1DC2*/
	MII_RMII_SEL, /*!< Ethernet PHY interface selection*/
};

static constexpr Register<PMCBitList, PMCField> PMC{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	SYSCFG_EXTICR1_GROUP		external interrupt configuration register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(EXTICRxBitList, CREATE_LIST_OF_BITS<Bit<4, gpio::Port>>(detail::Interval<0, 12, 4>{}))

template <gpio::Pin CR>
static constexpr Register<EXTICRxBitList, gpio::Pin, DEFAULT_ACCESS, true, ExtiCRxIdxPolicy> EXTICRx{BASE_ADDR,
																																																		OFFSET(CR)};
/**@}*/

/**
 * @defgroup	SYSCFG_CMPCR_GROUP		Compensation cell control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CMPCRBitList,						/**/
										Binary<>{BitPos_t{0}},	// CMP_PD
										Binary<>{BitPos_t{8}}		// READY
)

enum class CMPCRField {
	CMP_PD, /*!< Compensation cell power-down*/
	READY,	/*!< READY*/
};

static constexpr Register<CMPCRBitList, CMPCRField> CMPCR{BASE_ADDR, 0x20U};
/**@}*/

}	 // namespace cpp_stm32::syscfg::reg
