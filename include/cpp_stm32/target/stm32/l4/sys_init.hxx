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

#include <algorithm>
#include <array>
#include <cmath>
#include <optional>

#include "cpp_stm32/target/stm32/l4/flash.hxx"
#include "cpp_stm32/target/stm32/l4/pwr.hxx"
#include "cpp_stm32/target/stm32/l4/rcc.hxx"

#include "cpp_stm32/utility/constexpr_algo.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

#include "sys_info.hpp"

namespace cpp_stm32::stm32::l4 {

/**
 * @defgroup DEVICE_VOLTAGE_DEF   Device voltage
 * @{
 */
#if !defined(DEVICE_VDD)
#define DEVICE_VDD 3.3f
#endif

static constexpr auto STM32_VDD = DEVICE_VDD;

static_assert(1.71f <= STM32_VDD && STM32_VDD <= 3.6f);

/**@}*/

/**
 * @defgroup	HSI_CLK_DEF		HSI Clock
 * @{
 */
#if !defined(HSI_CLK_FREQ)
static constexpr auto HSI_CLK_FREQ = 16_MHz;
#endif

static_assert(HSI_CLK_FREQ == 16_MHz);

/**@}*/

/**
 * @defgroup
 * @note maybe we can deduce MSI clk freq from other input?
 * @{
 */

#if !defined(MSI_CLK_FREQ)
static constexpr auto MSI_CLK_FREQ = 4_MHz;
#endif

static constexpr std::array MSI_FREQ_TABLE{
	100_KHz, 200_KHz, 400_KHz, 800_KHz, 1_MHz, 2_MHz, 4_MHz, 8_MHz, 16_MHz, 24_MHz, 32_MHz, 48_MHz,
};

static_assert(cstd::find(MSI_FREQ_TABLE.begin(), MSI_FREQ_TABLE.end(), MSI_CLK_FREQ) != MSI_FREQ_TABLE.end());

/**@}*/

/**
 * @defgroup HSE_CLK_DEF    HSE Clock
 * @{
 */

static constexpr auto HSE_CLK_FREQ_MIN = 4_MHz;
static constexpr auto HSE_CLK_FREQ_MAX = 48_MHz;

#if !defined(HSE_CLK_FREQ)

static constexpr auto HSE_CLK_FREQ	= 0_MHz;
static constexpr auto HSE_CLK_VALID = false;

#else

static constexpr auto HSE_CLK_VALID = true;

static_assert(HSE_CLK_FREQ_MIN <= HSE_CLK_FREQ && HSE_CLK_FREQ <= HSE_CLK_FREQ_MAX);

#endif

#if !defined(HSE_BYPASS_CLK_SRC)
static constexpr auto HSE_BYPASS_CLK_SRC = false;
#endif

/**@}*/

/**
 * @defgroup PLL_VCO_DEF    PLL VCO
 * @{
 */

static constexpr auto VCO_INPUT_FREQ_MIN	= 4_MHz;
static constexpr auto VCO_INPUT_FREQ_MAX	= 16_MHz;
static constexpr auto VCO_OUTPUT_FREQ_MIN = 64_MHz;
static constexpr auto VCO_OUTPUT_FREQ_MAX = 344_MHz;

/**@}*/

static constexpr auto APB1_FREQ_MAX_VOS_RANGE2 = 26_MHz;
static constexpr auto APB1_FREQ_MAX_VOS_RANGE1 = 80_MHz;
static constexpr auto APB2_FREQ_MAX_VOS_RANGE2 = 26_MHz;
static constexpr auto APB2_FREQ_MAX_VOS_RANGE1 = 80_MHz;

static constexpr auto AHB_VOS_RANGE1_MAX_FREQ = 80_MHz;
static constexpr auto AHB_VOS_RANGE2_MAX_FREQ = 26_MHz;

static_assert(AHB_CLK_FREQ <= AHB_VOS_RANGE1_MAX_FREQ);

class SysClock {
 private:
	static constexpr auto CALC_ADVANCE_BUS_DIV_FACTOR = []() {
		return std::tuple{
			HPRE{DivisionFactor_v<SYS_CLK_FREQ / AHB_CLK_FREQ>},
			PPRE{DivisionFactor_v<SYS_CLK_FREQ / APB1_CLK_FREQ>},
			PPRE{DivisionFactor_v<SYS_CLK_FREQ / APB2_CLK_FREQ>},
		};
	};

	template <RccOsc PllSrc>
	static constexpr auto CALC_PLL_DIV_FACTOR() noexcept {
		constexpr auto pll_input_clk_freq = []() {
			switch (PllSrc) {
				case RccOsc::MsiOsc:
					return MSI_CLK_FREQ;
				case RccOsc::HseOsc:
					return std::uint64_t(HSE_CLK_FREQ);
				case RccOsc::Hsi16Osc:
					return std::uint64_t(HSI_CLK_FREQ);
				default:
					break;
			}
		}();

		constexpr auto pllm_n_r = []() {
			for (auto const& pllr_candidate : PllR::AVAIL_DIVISION_FACTOR) {
				if (auto const vco_freq = pllr_candidate.first * SYS_CLK_FREQ;
						VCO_OUTPUT_FREQ_MIN <= vco_freq && vco_freq <= VCO_OUTPUT_FREQ_MAX) {
					for (auto plln = PllN::MIN; plln < PllN::MAX; ++plln) {
						if (auto const vco_input_freq = vco_freq / plln;
								VCO_INPUT_FREQ_MIN <= vco_input_freq && vco_input_freq <= VCO_INPUT_FREQ_MAX) {
							if (auto const pllm = pll_input_clk_freq / vco_input_freq; PllM::MIN <= pllm && pllm <= PllM::MAX)
								return std::tuple{pllm, plln, pllr_candidate.first};
						}
					}
				}
			}
		}();
		constexpr auto pllm = std::get<0>(pllm_n_r);
		constexpr auto plln = std::get<1>(pllm_n_r);
		constexpr auto pllr = std::get<2>(pllm_n_r);

		// if constexpr (need to calculate pllp, pllq)
		// {
		//  ...
		// } esle {
		return std::tuple{PllM{DivisionFactor_v<pllm>}, PllN{DivisionFactor_v<plln>}, std::nullopt, std::nullopt,
											PllR{DivisionFactor_v<pllr>}};
		// }
	}
	/**
	 * @var 	CPU_WAIT_STATE
	 * @brief	This is chosen base on AHB clock frequency
	 */
	static constexpr auto CPU_WAIT_STATE = FlashWaitTable::getWaitState<STM32_VDD>(AHB_CLK_FREQ);

	/**
	 * @var		VOLTAGE_SCALE
	 * @brief	This is chosen base on AHB clock frequency, if desire frequency is greater than
	 * 				AHB_VOS_RANGE2_MAX_FREQ, then voltage scale must be range1. If desire frequency
	 * 				is lower than AHB_VOS_RANGE2_MAX_FREQ, then choose voltage scale 2 for lower power
	 * 				consumption.
	 */
	static constexpr auto VOLTAGE_SCALE = []() {
		if constexpr (AHB_CLK_FREQ > AHB_VOS_RANGE2_MAX_FREQ) {
			return VoltageScale::Range1;
		} else {
			return VoltageScale::Range2;
		}
	}();

	/**
	 * @var 		SYS_CLK_SRC
	 * @brief		This is chosen according to the following rules:
	 * 					-	The sys clock source must be Pll if the desired clock frequency doesn't
	 * 					  match any oscillator clock (i.e. HSI, HSE, and MSI)
	 * 					- If SYS Freq does match any oscillator clock frequency, then the following order is checked
	 * 						1. HSE_CLK_FREQ: As long as HSE clk is valid, it must be the highest priority to be considered, since
	 * 														 it needs additional care to enable HSE
	 * 						2. MSI_CLK_FREQ: This is the second option because it is defaut sys clock with 4_MHz after restart.
	 * 						3. HSI_CLK_FREQ: Since HSI clk freq is fixed, this option is the least possible one, and can be
	 * 														 replaced by MSI.
	 * @note 		 In order for more complicated usage, I should provide more flags so user can skip this and choose
	 * 					 arbitrary clock.
	 *
	 */
	static constexpr auto SYS_CLK_SRC = []() {
		if constexpr (SYS_CLK_FREQ != HSE_CLK_FREQ && SYS_CLK_FREQ != HSI_CLK_FREQ && SYS_CLK_FREQ != MSI_CLK_FREQ) {
			return SysClk::Pll;
		} else if constexpr (HSE_CLK_VALID && SYS_CLK_FREQ == HSE_CLK_FREQ) {
			return SysClk::Hse;
		} else if constexpr (SYS_CLK_FREQ == MSI_CLK_FREQ) {
			return SysClk::Msi;
		} else if constexpr (SYS_CLK_FREQ == HSI_CLK_FREQ) {
			return SysClk::Hsi16;
		}
	}();

 public:
	template <RccOsc PllSrc, typename = std::enable_if_t<SYS_CLK_SRC == SysClk::Pll && is_pll_clk_src<PllSrc>>>
	static constexpr void init() noexcept {
		if constexpr (HSE_BYPASS_CLK_SRC) {
			rcc_bypass_clksrc<RccOsc::HseOsc>();
		}

		// enable pll clock src, i.e., HSE, HSI or MSI
		rcc_enable_clk<PllSrc>();
		rcc_wait_osc_rdy<PllSrc>();
		rcc_set_sysclk<rcc_to_sys_enum(PllSrc)>();

		if constexpr (PllSrc == RccOsc::MsiOsc) {
			rcc_enable_msi_range();
			rcc_set_msi_range(MsiRange{Frequency_v<MSI_CLK_FREQ>});
		}

		{
			const auto& [m, n, p, q, r] = CALC_PLL_DIV_FACTOR<PllSrc>();

			rcc_disable_clk<RccOsc::PllOsc>();
			rcc_set_pllsrc_and_div_factor<PllSrc>(m, n, p, q, r);
			rcc_enable_periph_clk<RccPeriph::Pwr>();
			pwr_set_voltage_scale(VOLTAGE_SCALE);
		}

		rcc_enable_clk<RccOsc::PllOsc>();

		constexpr auto flash_wait_state = FlashLatency{CpuWaitState_v<CPU_WAIT_STATE>};
		flash_config_access_ctl<ARTAccel::InstructCache, ARTAccel::DataCache>(flash_wait_state);

		auto const& [ahb, apb1, apb2] = CALC_ADVANCE_BUS_DIV_FACTOR();
		rcc_config_adv_bus_division_factor(ahb, apb1, apb2);

		rcc_wait_osc_rdy<RccOsc::PllOsc>();

		rcc_set_sysclk<SYS_CLK_SRC>();
		rcc_wait_sysclk_rdy<SYS_CLK_SRC>();
	}
};	// namespace cpp_stm32::stm32::l4

}	 // namespace cpp_stm32::stm32::l4
