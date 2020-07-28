/**
 * @file  stm32/f4/sys_init.hxx
 * @brief	System clock setup API for stm32f4
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

#include <cmath>
#include <optional>

#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/detail/tuple.hxx"
#include "cpp_stm32/target/stm32/f4/clock.hxx"
#include "cpp_stm32/target/stm32/f4/flash.hxx"
#include "cpp_stm32/target/stm32/f4/pwr.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

namespace cpp_stm32::sys {

// reference
static constexpr auto STM32_VDD_MIN = 1.8f;
static constexpr auto STM32_VDD_MAX = 3.6f;

// reference
static constexpr auto HSE_CLK_FREQ_MIN				 = 4_MHz;
static constexpr auto HSE_CLK_FREQ_MAX				 = 25_MHz;
static constexpr auto RECOMMEND_VCO_INPUT_FREQ = 2_MHz;
static constexpr auto VCO_OUTPUT_FREQ_MIN			 = 100_MHz;
static constexpr auto VCO_OUTPUT_FREQ_MAX			 = 432_MHz;

// reference
static constexpr auto AHB_VOS_SCALE1_MAX_FREQ							 = 120_MHz;
static constexpr auto AHB_VOS_SCALE2_MAX_FREQ_NO_OVERDRIVE = 144_MHz;
static constexpr auto AHB_VOS_SCALE2_MAX_FREQ_OVERDRIVE		 = 168_MHz;

// reference
static constexpr auto APB1_FREQ_MAX_NO_OVERDRIVE = 42_MHz;
static constexpr auto APB1_FREQ_MAX_OVERDRIVE		 = 45_MHz;
static constexpr auto APB2_FREQ_MAX_NO_OVERDRIVE = 84_MHz;
static constexpr auto APB2_FREQ_MAX_OVERDRIVE		 = 90_MHz;

/* @todo Is this necessary? */
struct ExternalClock {
	bool const BYPASS = false;
	std::uint32_t const FREQ;

	explicit constexpr ExternalClock(bool const t_bypass, std::uint32_t const t_freq) : BYPASS(t_bypass), FREQ(t_freq) {}
};

using HSE_CLOCK = StrongType<ExternalClock, struct CPP_STM32_HSE_CLOCK>;
using LSE_CLOCK = StrongType<ExternalClock, struct CPP_STM32_LSE_CLOCK>;

/**
 * @brief 	This function calculate pll division factor with given input frequency and system frequency
 * @param		t_pll_freq Input clock frequency of PLL, possibly HSE or HSI, refer to the clock tree for further
 * 										 information.
 * @param 	t_sys_freq System clock frequency.
 *
 * @return  a tuple that contains the value of 5 divisino factors, i.e., pllm, plln, pllp, pllq, pllr
 */
template <auto ClkSrcFreq, auto SysClkFreq>
constexpr auto calc_pll_div_factor(Frequency<ClkSrcFreq> const t_pll_freq, Frequency<SysClkFreq> const t_sys_freq) {
	using rcc::PllPChecker;

	constexpr auto pllm						= static_cast<std::uint32_t>(std::ceil(t_pll_freq / RECOMMEND_VCO_INPUT_FREQ));
	constexpr auto vco_input_freq = Frequency<ClkSrcFreq / pllm>{};
	constexpr auto plln_over_pllp = t_sys_freq / vco_input_freq;
	constexpr auto max_plln				= std::floor(VCO_OUTPUT_FREQ_MAX / vco_input_freq);
	constexpr auto min_plln				= std::ceil(VCO_OUTPUT_FREQ_MIN / vco_input_freq);

	constexpr auto pllp_satisfy_constraint = [](auto&& t_pllp_candidate) {
		auto const plln = t_pllp_candidate.key * plln_over_pllp;
		return (min_plln <= plln && plln <= max_plln);
	};

	constexpr auto pllp_idx = detail::find_if(PllPChecker::KEY_VAL_MAP, pllp_satisfy_constraint);
	constexpr auto pllp			= std::get<pllp_idx>(PllPChecker::KEY_VAL_MAP).key;
	constexpr auto plln			= static_cast<std::uint32_t>(plln_over_pllp * pllp);

	// @todo finish this
	// if constexpr (need to calculate pllq and pllr) {
	//    ...
	// } else
	return std::tuple{pllm, plln, pllp, 2, 2};
}

/**
 * @brief	 This function determines whether overdrive is needed base on the bus frequencies
 * @param  t_ahb  AHB clock frequency
 * @param  t_apb1 APB1 clock frequency
 * @param  t_apb2 APB2 clock frequency
 *
 * @return Boolean that indicate if overdrive is needed or not
 */
template <auto AHB, auto APB1, auto APB2>
constexpr auto system_need_overdrive(Frequency<AHB> const t_ahb, Frequency<APB1> const t_apb1,
																		 Frequency<APB2> const t_apb2) noexcept {
	constexpr bool ahb_need_overdrive	= t_ahb >= AHB_VOS_SCALE2_MAX_FREQ_OVERDRIVE;
	constexpr bool apb1_need_overdrive = t_apb1 >= APB1_FREQ_MAX_NO_OVERDRIVE;
	constexpr bool apb2_need_overdrive = t_apb2 >= APB2_FREQ_MAX_NO_OVERDRIVE;
	return ahb_need_overdrive || apb1_need_overdrive || apb2_need_overdrive;
}

/**
 * @brief	 This function calculates the division factor of the bus
 * @param  t_sys  SYS clock frequency
 * @param  t_ahb  AHB clock frequency
 * @param  t_apb1 APB1 clock frequency
 * @param  t_apb2 APB2 clock frequency
 *
 * @return tuple that contains the division factor, i.e., hpre, ppre1, ppre2
 */
template <auto SYS, auto AHB, auto APB1, auto APB2>
constexpr auto calc_advance_bus_div_factor(Frequency<SYS> const t_sys, Frequency<AHB> const t_ahb,
																					 Frequency<APB1> const t_apb1, Frequency<APB2> const t_apb2) noexcept {
	constexpr auto hpre	= t_sys / t_ahb;
	constexpr auto ppre1 = t_ahb / t_apb1;
	constexpr auto ppre2 = t_ahb / t_apb2;
	return std::tuple{hpre, ppre1, ppre2};
}

/**
 * @brief  This function determines what system clock source is used according to each source frequency
 * @param  t_sys SYS clock frequency
 * @param  t_hse HSE clock frequency
 * @param  t_hsi HSI clock frequency
 * @return SysClk
 */
template <auto SYS, auto HSE, auto HSI>
constexpr auto determine_sys_clk_src(Frequency<SYS> const t_sys, Frequency<HSE> const t_hse,
																		 Frequency<HSI> const t_hsi) noexcept {
	using rcc::SysClk;
	if constexpr (t_sys != t_hse && t_sys != t_hsi) {
		// maybe its Pllr, @todo add this into consideration
		return SysClk::Pllp;
	} else if constexpr (t_sys == t_hse) {
		return SysClk::Hse;
	} else if constexpr (t_sys == t_hsi) {
		return SysClk::Hsi;
	}
}

/**
 * @brief	 This function determines the voltage scale of the system
 * @param  t_ahb 	AHB clock frequency
 * @return Voltage scale
 */
template <auto NeedOverdrive, auto AHB>
constexpr auto determine_voltage_scale(Frequency<AHB> const t_ahb) noexcept {
	if constexpr (NeedOverdrive || t_ahb >= AHB_VOS_SCALE2_MAX_FREQ_NO_OVERDRIVE) {
		return pwr::VoltageScale::Scale1Mode;
	} else if constexpr (t_ahb >= AHB_VOS_SCALE1_MAX_FREQ) {
		return pwr::VoltageScale::Scale2Mode;
	} else {
		return pwr::VoltageScale::Scale3Mode;
	}
}

/**
 * @class   Clock
 * @brief
 */
template <clock::ClockFreq const& ClkData = CPP_STM32_CLOCK_DATA>
class Clock {
 private:
	static constexpr clock::ClockFreq CLOCK_DATA = ClkData;

	static constexpr auto AHB_CLK	= Frequency<CLOCK_DATA.freqAHB>{};
	static constexpr auto APB1_CLK = Frequency<CLOCK_DATA.freqAPB1>{};
	static constexpr auto APB2_CLK = Frequency<CLOCK_DATA.freqAPB2>{};
	static constexpr auto SYS_CLK	= Frequency<CLOCK_DATA.freqSYS>{};
	static constexpr auto HSE_CLK	= Frequency<CLOCK_DATA.freqHSE>{};
	static constexpr auto VDD			 = CLOCK_DATA.vdd;

	// internal clock frequency is fixed
	static constexpr auto HSI_CLK = Frequency<CLOCK_DATA.HSI_FREQ>{};
	static constexpr auto LSI_CLK = Frequency<CLOCK_DATA.LSI_FREQ>{};

	static constexpr auto GET_ADVANCE_BUS_DIV_FACTOR() noexcept {
		using rcc::HPREChecker, rcc::PPREChecker, rcc::DivisionFactor_v;
		constexpr auto bus_div = calc_advance_bus_div_factor(SYS_CLK, AHB_CLK, APB1_CLK, APB2_CLK);
		constexpr auto hpre		 = std::get<0>(bus_div);
		constexpr auto ppre1	 = std::get<1>(bus_div);
		constexpr auto ppre2	 = std::get<2>(bus_div);

		// std::optional is also a choice
		return std::tuple{HPREChecker{DivisionFactor_v<hpre>}, PPREChecker{DivisionFactor_v<ppre1>},
											PPREChecker{DivisionFactor_v<ppre2>}};
	}

	template <rcc::ClkSrc PllSrc>
	static constexpr auto GET_PLL_DIV_FACTOR() noexcept {
		using rcc::ClkSrc, rcc::DivisionFactor_v;
		using rcc::PllMChecker, rcc::PllNChecker, rcc::PllPChecker, rcc::PllQChecker, rcc::PllRChecker;

		constexpr auto pll_input_clk = Frequency<(PllSrc == ClkSrc::Hse ? CLOCK_DATA.freqHSE : CLOCK_DATA.HSI_FREQ)>{};
		constexpr auto result				 = calc_pll_div_factor(pll_input_clk, SYS_CLK);

		constexpr auto pllm = std::get<0>(result);
		constexpr auto plln = std::get<1>(result);
		constexpr auto pllp = std::get<2>(result);
		constexpr auto pllq = std::get<3>(result);
		constexpr auto pllr = std::get<4>(result);

		return std::tuple{PllMChecker{DivisionFactor_v<pllm>}, PllNChecker{DivisionFactor_v<plln>},
											PllPChecker{DivisionFactor_v<pllp>}, PllQChecker{DivisionFactor_v<pllq>},
											PllRChecker{DivisionFactor_v<pllr>}};
	}

	constexpr auto check_sys_src_valid() noexcept {
		if constexpr (CLOCK_DATA.srcSYS.has_value()) {
			switch (CLOCK_DATA.srcSYS.value()) {}
		}

		return true;	// sys src is determined by our library
	}

 public:
	static constexpr auto CPU_WAIT_STATE = flash::WaitTable::getWaitState<VDD>(AHB_CLK);
	static constexpr auto NEED_OVERDRIVE = system_need_overdrive(AHB_CLK, APB1_CLK, APB2_CLK);
	static constexpr auto VOLTAGE_SCALE	= determine_voltage_scale<NEED_OVERDRIVE>(AHB_CLK);
	static constexpr auto SYS_CLK_SRC		 = determine_sys_clk_src(SYS_CLK, HSE_CLK, HSI_CLK);

	static constexpr auto IS_CLOCK_DATA_VALID() noexcept {
		using rcc::SysClk;
		constexpr auto SYS_CLK_SRC_IS_PLL = SYS_CLK_SRC == SysClk::Pllp || SYS_CLK_SRC == SysClk::Pllr;
		constexpr auto CLK_SRC_IS_VALID		= (SYS_CLK_SRC_IS_PLL && CLOCK_DATA.srcPLL.has_value());

		constexpr auto HSE_FREQ_IS_VALID = HSE_CLK_FREQ_MIN <= HSE_CLK && HSE_CLK <= HSE_CLK_FREQ_MAX;
		constexpr auto APB1_CLK_IS_VALID = APB1_CLK <= APB1_FREQ_MAX_OVERDRIVE;
		constexpr auto VDD_IS_VALID			 = STM32_VDD_MIN <= VDD && VDD <= STM32_VDD_MAX;

		// @todo other validity check...
		return CLK_SRC_IS_VALID && HSE_FREQ_IS_VALID && APB1_CLK_IS_VALID && VDD_IS_VALID;
	}

	// template <rcc::ClkSrc PllSrc, rcc::RtcClk RtcSrc>
	// static constexpr void init() noexcept {
	// 	init<PllSrc>();
	//
	// 	pwr::unlock_write_protection();
	// 	rcc::hold_reset_backup_domain();
	// 	rcc::release_reset_backup_domain();
	//
	// 	if constexpr (RtcSrc == rcc::RtcClk::Hse) {
	// 		constexpr std::uint32_t rtc_prescaler = HSE_FREQ / rtc::HSE_CLK_FREQ_TO_RTC;
	// 		rcc::set_rtc_prescaler(rcc::RTCPRE{rcc::DivisionFactor_v<rtc_prescaler>});
	// 	}
	//
	// 	rcc::set_rtc_clk_src<RtcSrc>();
	// 	rcc::enable_rtc();
	// }

	static constexpr void init() noexcept {
		static_assert(IS_CLOCK_DATA_VALID());

		using rcc::ClkSrc, rcc::PeriphClk;
		if constexpr (CLOCK_DATA.bypassHSE) {
			rcc::bypass_clksrc<ClkSrc::Hse>();
		}

		// enable PLL Clock Src, i.e., HSE or HSI
		if constexpr (CLOCK_DATA.srcPLL.has_value()) {
			rcc::enable_clk<CLOCK_DATA.srcPLL.value()>();
			rcc::wait_osc_rdy<CLOCK_DATA.srcPLL.value()>();
			rcc::set_sysclk<rcc::SysClk{to_underlying(CLOCK_DATA.srcPLL.value())}>();

			{	// operations that requires PLL off
				auto const& [m, n, p, q, r] = GET_PLL_DIV_FACTOR<CLOCK_DATA.srcPLL.value()>();

				rcc::disable_clk<ClkSrc::Pll>();
				rcc::set_pllsrc_and_div_factor<CLOCK_DATA.srcPLL.value()>(m, n, p, q, r);
				rcc::enable_periph_clk<PeriphClk::Pwr>();
				pwr::set_voltage_scale(VOLTAGE_SCALE);
			}

			rcc::enable_clk<ClkSrc::Pll>();
		}

		if constexpr (NEED_OVERDRIVE) {
			pwr::enable_overdrive();
			pwr::wait_overdrive_rdy();

			pwr::enable_overdrive_switch();
			pwr::wait_overdrive_switch_rdy();
		}

		constexpr auto wait_state = flash::Latency{flash::CpuWaitState_v<CPU_WAIT_STATE>};
		flash::config_access_ctl<flash::ARTAccel::InstructCache, flash::ARTAccel::DataCache>(wait_state);

		auto const& [ahb, apb1, apb2] = GET_ADVANCE_BUS_DIV_FACTOR();
		rcc::config_adv_bus_division_factor(ahb, apb1, apb2);

		if constexpr (CLOCK_DATA.srcPLL.has_value()) {
			rcc::wait_osc_rdy<ClkSrc::Pll>();	// wait for PLL lock
		}

		// switch sysclk and wait ready
		rcc::set_sysclk<SYS_CLK_SRC>();
		rcc::wait_sysclk_rdy<SYS_CLK_SRC>();
	}
};	// namespace cpp_stm32::sys

}	// namespace cpp_stm32::sys
