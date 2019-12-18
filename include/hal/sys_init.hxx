/**
 * @Date:   2019-12-11T14:39:29+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: sys_info.hxx
 * @Last modified time: 2019-12-17T22:40:28+08:00
 */

#pragma once

#include <cmath>

#include "include/hal/peripheral/rcc.hxx"
#include "include/hal/utility.hxx"
#include "include/utility/constexpr_algo.hxx"
#include "sys_info.hpp"

#if !defined(HSE_CLK_FREQ)
#define HSE_CLK_FREQ (8 MHz)
#endif

#if !defined(HSI_CLK_FREQ)
#define HSI_CLK_FREQ (16 MHz)
#endif

#if !defined(HSE_BYPASS_CLK_SRC)
#define HSE_BYPASS_CLK_SRC false
#endif

static_assert(4_MHz <= HSE_CLK_FREQ && HSE_CLK_FREQ <= 26_MHz);
static_assert(HSI_CLK_FREQ == 16_MHz);

class SysClock {
 private:
 public:
	static constexpr auto SYS_CLK_SRC = []() {
		if constexpr (SYS_CLK_FREQ != HSE_CLK_FREQ && SYS_CLK_FREQ != HSI_CLK_FREQ) {
			return SysClk::Pllp;
		} else if constexpr (SYS_CLK_FREQ == HSE_CLK_FREQ) {
			return SysClk::Hse;
		} else if constexpr (SYS_CLK_FREQ == HSI_CLK_FREQ) {
			return SysClk::Hsi;
		}
	}();

	static constexpr auto MIN_VCO_OUTPUT_FREQ			 = 100_MHz;
	static constexpr auto MAX_VCO_OUTPUT_FREQ			 = 432_MHz;
	static constexpr auto RECOMMEND_VCO_INPUT_FREQ = 2_MHz;

 public:
	template <SysClk SystemClock = SYS_CLK_SRC>
	static constexpr void init() noexcept {
		if constexpr (HSE_BYPASS_CLK_SRC) {
			rcc_bypass_clksrc<RccOsc::HseOsc>();
		}

		constexpr auto ahb_prescaler	= HPRE{DivisionFactor_v<SYS_CLK_FREQ / AHB_CLK_FREQ>};
		constexpr auto apb1_prescaler = PPRE{DivisionFactor_v<AHB_CLK_FREQ / APB1_CLK_FREQ>};
		constexpr auto apb2_prescaler = PPRE{DivisionFactor_v<AHB_CLK_FREQ / APB2_CLK_FREQ>};
	}

	template <SysClk SystemClock = SYS_CLK_SRC, RccOsc PllSrc>
	static constexpr void init(PllClkSrc<PllSrc> const&) noexcept {
		constexpr auto pll_input_clk_freq = (PllSrc == RccOsc::HseOsc ? HSE_CLK_FREQ : HSI_CLK_FREQ);
		constexpr auto pllm = static_cast<std::uint32_t>(std::ceil(pll_input_clk_freq / RECOMMEND_VCO_INPUT_FREQ));
		constexpr auto vco_input_freq						= pll_input_clk_freq / pllm;
		constexpr auto plln_over_pllp						= SYS_CLK_FREQ / vco_input_freq;
		[[gnu::unused]] constexpr auto max_plln = std::floor(MAX_VCO_OUTPUT_FREQ / vco_input_freq);
		[[gnu::unused]] constexpr auto min_plln = std::ceil(MIN_VCO_OUTPUT_FREQ / vco_input_freq);

		constexpr auto pllp = *constexpr_std_find_if(PllP::AVAIL_PLLP_DIV_FACTOR.begin(), PllP::AVAIL_PLLP_DIV_FACTOR.end(),
																								 [&](auto const& t_pllp_candidate) {
																									 const auto plln = t_pllp_candidate * plln_over_pllp;
																									 return (min_plln <= plln && plln <= max_plln);
																								 });
		constexpr auto plln = static_cast<std::uint32_t>(plln_over_pllp * pllp);

		constexpr auto ahb_prescaler	= HPRE{DivisionFactor_v<SYS_CLK_FREQ / AHB_CLK_FREQ>};
		constexpr auto apb1_prescaler = PPRE{DivisionFactor_v<AHB_CLK_FREQ / APB1_CLK_FREQ>};
		constexpr auto apb2_prescaler = PPRE{DivisionFactor_v<AHB_CLK_FREQ / APB2_CLK_FREQ>};

		if constexpr (HSE_BYPASS_CLK_SRC) {
			rcc_bypass_clksrc<RccOsc::HseOsc>();
		}

		rcc_enable_clk<PllSrc>();
		rcc_wait_osc_rdy<PllSrc>();
		rcc_set_sysclk<SystemClock>();

		rcc_config_adv_bus_division_factor(ahb_prescaler, apb1_prescaler, apb2_prescaler);

		rcc_disable_clk<RccOsc::PllOsc>();
		rcc_set_pllsrc(PllClkSrc<PllSrc>{});

		// @todo consider pllq and pllr according to sys_info.hpp
		rcc_config_pll_division_factor(PllM{DivisionFactor_v<pllm>}, PllN{DivisionFactor_v<plln>},
																	 PllP{DivisionFactor_v<pllp>}, PllQ{DivisionFactor_v<2U>},
																	 PllR{DivisionFactor_v<2U>});
	}
};
