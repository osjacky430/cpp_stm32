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

#include <cmath>

#include "cpp_stm32/target/stm32/f4/flash.hxx"
#include "cpp_stm32/target/stm32/f4/pwr.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"

#include "cpp_stm32/utility/constexpr_algo.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

// user spcific include
#include "sys_info.hpp"

namespace cpp_stm32::stm32::f4 {

/**
 * @defgroup DEVICE_VOLTAGE_DEF   Device voltage
 * @{
 */

#if !defined(DEVICE_VDD)
#define DEVICE_VDD 3.3f
#endif

static constexpr auto STM32_VDD = DEVICE_VDD;

static_assert(1.8f <= STM32_VDD && STM32_VDD <= 3.6f);

/**@}*/

/**
 * @defgroup HSI_CLK_DEF    HSI Clock
 * @{
 */

#if !defined(HSI_CLK_FREQ)
#define HSI_CLK_FREQ (16 MHz)
#endif

static_assert(HSI_CLK_FREQ == 16_MHz);

/**@}*/

/**
 * @defgroup HSE_CLK_DEF    HSE Clock
 * @{
 */

#if !defined(HSE_CLK_FREQ)
#define HSE_CLK_FREQ (8 MHz)
#endif

#if !defined(HSE_BYPASS_CLK_SRC)
#define HSE_BYPASS_CLK_SRC false
#endif

static constexpr auto HSE_CLK_FREQ_MIN = 4_MHz;
static constexpr auto HSE_CLK_FREQ_MAX = 25_MHz;

static_assert(HSE_CLK_FREQ_MIN <= HSE_CLK_FREQ && HSE_CLK_FREQ <= HSE_CLK_FREQ_MAX);

/**@}*/

/**
 * @defgroup PLL_VCO_DEF    PLL VCO
 * @{
 */

static constexpr auto RECOMMEND_VCO_INPUT_FREQ = 2_MHz;
static constexpr auto VCO_OUTPUT_FREQ_MIN			 = 100_MHz;
static constexpr auto VCO_OUTPUT_FREQ_MAX			 = 432_MHz;

/**@}*/

/**
 * @defgroup VOS_MAX_FREQ_DEF    Max HCLK Freq under different VOS with/without overdrive
 * @{
 */

static constexpr auto AHB_VOS_SCALE1_MAX_FREQ							 = 120_MHz;
static constexpr auto AHB_VOS_SCALE2_MAX_FREQ_NO_OVERDRIVE = 144_MHz;
static constexpr auto AHB_VOS_SCALE2_MAX_FREQ_OVERDRIVE		 = 168_MHz;

/**@}*/

static constexpr auto APB1_FREQ_MAX_NO_OVERDRIVE = 42_MHz;
static constexpr auto APB1_FREQ_MAX_OVERDRIVE		 = 45_MHz;
static constexpr auto APB2_FREQ_MAX_NO_OVERDRIVE = 84_MHz;
static constexpr auto APB2_FREQ_MAX_OVERDRIVE		 = 90_MHz;

class SysClock {
 private:
	static constexpr std::uint64_t AHB_CLK_FREQ_ = AHB_CLK_FREQ;

	static constexpr auto CALC_ADVANCE_BUS_DIV_FACTOR = []() {
		return std::tuple{
			HPRE{DivisionFactor_v<SYS_CLK_FREQ / AHB_CLK_FREQ>},
			PPRE{DivisionFactor_v<AHB_CLK_FREQ / APB1_CLK_FREQ>},
			PPRE{DivisionFactor_v<AHB_CLK_FREQ / APB2_CLK_FREQ>},
		};
	};

	template <RccOsc PllSrc>
	static constexpr auto CALC_PLL_DIV_FACTOR() {
		constexpr auto pll_input_clk_freq = (PllSrc == RccOsc::HseOsc ? HSE_CLK_FREQ : HSI_CLK_FREQ);
		constexpr auto pllm = static_cast<std::uint32_t>(std::ceil(pll_input_clk_freq / RECOMMEND_VCO_INPUT_FREQ));
		constexpr auto vco_input_freq = pll_input_clk_freq / pllm;
		constexpr auto plln_over_pllp = SYS_CLK_FREQ / vco_input_freq;
		constexpr auto max_plln				= std::floor(VCO_OUTPUT_FREQ_MAX / vco_input_freq);
		constexpr auto min_plln				= std::ceil(VCO_OUTPUT_FREQ_MIN / vco_input_freq);

		constexpr auto pllp_satisfy_constraint = [](auto const& t_pllp_candidate) {
			auto const plln = t_pllp_candidate.first * plln_over_pllp;
			return (min_plln <= plln && plln <= max_plln);
		};

		constexpr auto pllp_iter =
			cstd::find_if(PllP::AVAIL_DIVISION_FACTOR.begin(), PllP::AVAIL_DIVISION_FACTOR.end(), pllp_satisfy_constraint);
		constexpr auto pllp = pllp_iter->first;
		constexpr auto plln = static_cast<std::uint32_t>(plln_over_pllp * pllp);

		// if constexpr (need to calculate pllq and pllr) {
		//    ...
		// } else
		return std::tuple{PllM{DivisionFactor_v<pllm>}, PllN{DivisionFactor_v<plln>}, PllP{DivisionFactor_v<pllp>},
											PllQ{DivisionFactor_v<2U>}, PllR{DivisionFactor_v<2U>}};
	}

 public:
	static constexpr auto CPU_WAIT_STATE = FlashWaitTable::getWaitState<STM32_VDD>(AHB_CLK_FREQ_);

	static constexpr auto NEED_OVERDRIVE =
		(APB1_CLK_FREQ >= APB1_FREQ_MAX_NO_OVERDRIVE || APB2_CLK_FREQ >= APB2_FREQ_MAX_NO_OVERDRIVE ||
		 AHB_CLK_FREQ >= AHB_VOS_SCALE2_MAX_FREQ_OVERDRIVE);

	static constexpr auto VOLTAGE_SCALE = []() {
		if constexpr (NEED_OVERDRIVE || AHB_CLK_FREQ >= AHB_VOS_SCALE2_MAX_FREQ_NO_OVERDRIVE) {
			return VoltageScale::Scale1Mode;
		} else if constexpr (AHB_CLK_FREQ >= AHB_VOS_SCALE1_MAX_FREQ) {
			return VoltageScale::Scale2Mode;
		} else {
			return VoltageScale::Scale3Mode;
		}
	}();

	static constexpr auto SYS_CLK_SRC = []() {
		if constexpr (SYS_CLK_FREQ != HSE_CLK_FREQ && SYS_CLK_FREQ != HSI_CLK_FREQ) {
			// maybe its Pllr, @todo add this into consideration
			return SysClk::Pllp;
		} else if constexpr (SYS_CLK_FREQ == HSE_CLK_FREQ) {
			return SysClk::Hse;
		} else if constexpr (SYS_CLK_FREQ == HSI_CLK_FREQ) {
			return SysClk::Hsi;
		}
	}();

	template <SysClk SystemClock = SYS_CLK_SRC>
	static constexpr void init() noexcept {
		if constexpr (HSE_BYPASS_CLK_SRC) {
			rcc_bypass_clksrc<RccOsc::HseOsc>();
		}
	}

	// @todo, this is a bit strange
	template <RccOsc PllSrc, typename = std::enable_if_t<is_pll_clk_src<PllSrc>>>
	static constexpr void init() noexcept {
		if constexpr (HSE_BYPASS_CLK_SRC) {
			rcc_bypass_clksrc<RccOsc::HseOsc>();
		}

		// enable PLL Clock Src, i.e., HSE or HSI
		rcc_enable_clk<PllSrc>();
		rcc_wait_osc_rdy<PllSrc>();
		rcc_set_sysclk<SysClk{to_underlying(PllSrc)}>();

		{	 // operations that requires PLL off
			auto const& [m, n, p, q, r] = CALC_PLL_DIV_FACTOR<PllSrc>();

			rcc_disable_clk<RccOsc::PllOsc>();
			rcc_set_pllsrc_and_div_factor<PllSrc>(m, n, p, q, r);
			rcc_enable_periph_clk<RccPeriph::Pwr>();
			pwr_set_voltage_scale(VOLTAGE_SCALE);
		}

		rcc_enable_clk<RccOsc::PllOsc>();

		if constexpr (NEED_OVERDRIVE) {
			pwr_enable_overdrive();
			pwr_wait_overdrive_rdy();

			pwr_enable_overdrive_switch();
			pwr_wait_overdrive_switch_rdy();
		}

		constexpr auto flash_wait_state = FlashLatency{CpuWaitState_v<CPU_WAIT_STATE>};
		flash_config_access_ctl<ARTAccel::InstructCache, ARTAccel::DataCache>(flash_wait_state);

		auto const& [ahb, apb1, apb2] = CALC_ADVANCE_BUS_DIV_FACTOR();
		rcc_config_adv_bus_division_factor(ahb, apb1, apb2);

		rcc_wait_osc_rdy<RccOsc::PllOsc>();	 // wait for PLL lock

		// switch sysclk and wait ready
		rcc_set_sysclk<SYS_CLK_SRC>();
		rcc_wait_sysclk_rdy<SYS_CLK_SRC>();
	}
};

}	 // namespace cpp_stm32::stm32::f4
