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

#include "cpp_stm32/target/stm32/l4/clock.hxx"
#include "cpp_stm32/target/stm32/l4/flash.hxx"
#include "cpp_stm32/target/stm32/l4/pwr.hxx"
#include "cpp_stm32/target/stm32/l4/rcc.hxx"

#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/detail/tuple.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

#include "project_config.hxx"

namespace cpp_stm32::sys {

constexpr auto STM32_VDD_MIN = 1.71f;
constexpr auto STM32_VDD_MAX = 3.6f;

static constexpr std::tuple MSI_FREQ_TABLE{
	100_kHz, 200_kHz, 400_kHz, 800_kHz, 1_MHz, 2_MHz, 4_MHz, 8_MHz, 16_MHz, 24_MHz, 32_MHz, 48_MHz,
};

// @todo fix this, use find_if?
// static_assert(detail::find(MSI_FREQ_TABLE, Frequency<MSI_CLK_FREQ>{}) !=
// std::tuple_size_v<decltype(MSI_FREQ_TABLE)>);

constexpr auto HSE_CLK_FREQ_MIN = 4_MHz;
constexpr auto HSE_CLK_FREQ_MAX = 48_MHz;

constexpr auto VCO_INPUT_FREQ_MIN	 = 4_MHz;
constexpr auto VCO_INPUT_FREQ_MAX	 = 16_MHz;
constexpr auto VCO_OUTPUT_FREQ_MIN = 64_MHz;
constexpr auto VCO_OUTPUT_FREQ_MAX = 344_MHz;

constexpr auto APB1_FREQ_MAX_VOS_RANGE2 = 26_MHz;
constexpr auto APB1_FREQ_MAX_VOS_RANGE1 = 80_MHz;
constexpr auto APB2_FREQ_MAX_VOS_RANGE2 = 26_MHz;
constexpr auto APB2_FREQ_MAX_VOS_RANGE1 = 80_MHz;

constexpr auto AHB_VOS_RANGE1_MAX_FREQ = 80_MHz;
constexpr auto AHB_VOS_RANGE2_MAX_FREQ = 26_MHz;

// static_assert(HSE_CLK_FREQ_MIN <= Frequency<HSE_CLK_FREQ>{} && Frequency<HSE_CLK_FREQ>{} <= HSE_CLK_FREQ_MAX);
// static_assert(STM32_VDD_MIN <= STM32_VDD && STM32_VDD <= STM32_VDD_MAX);
// static_assert(Frequency<HSI_CLK_FREQ>{} == 16_MHz);
// static_assert(Frequency<AHB_CLK_FREQ>{} <= AHB_VOS_RANGE1_MAX_FREQ);
// static_assert(Frequency<SYS_CLK_FREQ>{} <= AHB_VOS_RANGE1_MAX_FREQ);
// static_assert(Frequency<APB1_FREQ>{} <= AHB_VOS_RANGE1_MAX_FREQ);
// static_assert(Frequency<APB2_FREQ>{} <= AHB_VOS_RANGE1_MAX_FREQ);

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
	constexpr auto hpre	 = t_sys / t_ahb;
	constexpr auto ppre1 = t_ahb / t_apb1;
	constexpr auto ppre2 = t_ahb / t_apb2;
	return std::tuple{hpre, ppre1, ppre2};
}

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
template <auto SYS, auto HSE, auto HSI, auto MSI>
constexpr auto determine_sys_clk_src(Frequency<SYS> const t_sys, Frequency<HSE> const t_hse, Frequency<HSI> const t_hsi,
																		 Frequency<MSI> const t_msi) noexcept {
	using rcc::SysClk;
	if constexpr (t_sys != t_hse && t_sys != t_hsi && t_sys != t_msi) {
		return SysClk::Pll;
	} else if constexpr (t_sys == t_hse) {
		return SysClk::Hse;
	} else if constexpr (t_sys == t_msi) {
		return SysClk::Msi;
	} else if constexpr (t_sys == t_hsi) {
		return SysClk::Hsi16;
	}
}

/**
 * @var		VOLTAGE_SCALE
 * @brief	This is chosen base on AHB clock frequency, if desire frequency is greater than
 * 				AHB_VOS_RANGE2_MAX_FREQ, then voltage scale must be range1. If desire frequency
 * 				is lower than AHB_VOS_RANGE2_MAX_FREQ, then choose voltage scale 2 for lower power
 * 				consumption.
 */
template <auto AHB>
constexpr auto determine_voltage_scale(Frequency<AHB> const t_ahb) noexcept {
	if constexpr (t_ahb > AHB_VOS_RANGE2_MAX_FREQ) {
		return pwr::VoltageScale::Range1;
	} else {
		return pwr::VoltageScale::Range2;
	}
}

/**
 * @class Clock
 * @brief
 */
template <clock::ClockFreq const& ClkData = CPP_STM32_CLOCK_DATA>
class Clock {
 private:
	static constexpr clock::ClockFreq CLOCK_DATA = ClkData;

	static constexpr auto AHB_CLK	 = Frequency<CLOCK_DATA.freqAHB>{};
	static constexpr auto APB1_CLK = Frequency<CLOCK_DATA.freqAPB1>{};
	static constexpr auto APB2_CLK = Frequency<CLOCK_DATA.freqAPB2>{};
	static constexpr auto SYS_CLK	 = Frequency<CLOCK_DATA.freqSYS>{};
	static constexpr auto MSI_CLK	 = Frequency<CLOCK_DATA.freqMSI>{};
	static constexpr auto HSE_CLK	 = Frequency<CLOCK_DATA.freqHSE>{};
	static constexpr auto VDD			 = CLOCK_DATA.vdd;

	static constexpr auto HSI_CLK = Frequency<CLOCK_DATA.HSI_FREQ>{};
	static constexpr auto LSI_CLK = Frequency<CLOCK_DATA.LSI_FREQ>{};

	static constexpr auto GET_ADVANCE_BUS_DIV_FACTOR() noexcept {
		using rcc::HPREChecker, rcc::PPREChecker, rcc::DivisionFactor_v;
		constexpr auto bus_div = calc_advance_bus_div_factor(SYS_CLK, AHB_CLK, APB1_CLK, APB2_CLK);
		constexpr auto hpre		 = std::get<0>(bus_div);
		constexpr auto ppre1	 = std::get<1>(bus_div);
		constexpr auto ppre2	 = std::get<2>(bus_div);

		return std::tuple{HPREChecker{DivisionFactor_v<hpre>}, PPREChecker{DivisionFactor_v<ppre1>},
											PPREChecker{DivisionFactor_v<ppre2>}};
	}

	template <std::size_t Idx>
	static constexpr auto CHECK_PLL_MNR_IMPL(std::uint64_t const t_pll_input) noexcept {
		constexpr auto pllr						= std::get<Idx>(rcc::PllR::KEY_VAL_MAP).key;
		constexpr auto vco_freq				= pllr * CLOCK_DATA.freqSYS;
		constexpr auto vco_in_inrange = [](auto const t_vco_in) {
			return VCO_INPUT_FREQ_MIN() <= t_vco_in && t_vco_in <= VCO_INPUT_FREQ_MAX();
		};
		constexpr auto vco_out_inrange = [](auto const t_vco_out) {
			return VCO_OUTPUT_FREQ_MIN() <= t_vco_out && t_vco_out <= VCO_OUTPUT_FREQ_MAX();
		};

		if constexpr (vco_out_inrange(vco_freq)) {
			for (auto plln = rcc::PllNChecker::MIN; plln <= rcc::PllNChecker::MAX; ++plln) {
				if (auto const vco_in_freq = vco_freq / plln; vco_in_inrange(vco_in_freq)) {
					if (auto const pllm = t_pll_input / vco_in_freq; 1 <= pllm && pllm <= 7) {
						return std::tuple{pllm, plln, pllr};
					}
				}
			}
		}

		if constexpr (Idx + 1 < rcc::PllR::KEY_VAL_NUM) {
			return CHECK_PLL_MNR_IMPL<Idx + 1>(t_pll_input);
		} else {
			return std::tuple{0ULL, 0, 0};
		}
	}

	static constexpr auto CHECK_PLL_MNR(std::uint64_t const t_pll_input) noexcept {
		return CHECK_PLL_MNR_IMPL<0>(t_pll_input);
	}

	template <rcc::ClkSrc PllSrc>
	static constexpr auto CALC_PLL_DIV_FACTOR() noexcept {
		using rcc::ClkSrc, rcc::PllMChecker, rcc::PllNChecker, rcc::PllP, rcc::PllQ, rcc::PllR;

		constexpr auto pll_input_clk_freq = []() {
			switch (PllSrc) {
				case ClkSrc::Msi:
					return std::uint64_t{CLOCK_DATA.freqMSI};
				case ClkSrc::Hse:
					return std::uint64_t(CLOCK_DATA.freqHSE);
				case ClkSrc::Hsi160:
					return std::uint64_t(CLOCK_DATA.HSI_FREQ);
				default:
					break;
			}
		}();

		constexpr auto pllm_n_r = CHECK_PLL_MNR(pll_input_clk_freq);
		constexpr auto pllm			= std::get<0>(pllm_n_r);
		constexpr auto plln			= std::get<1>(pllm_n_r);
		constexpr auto pllr			= std::get<2>(pllm_n_r);

		// if constexpr (need to calculate pllp, pllq)
		// {
		//  ...
		// } esle {
		return std::tuple{PllMChecker{rcc::DivisionFactor_v<pllm>}, PllNChecker{rcc::DivisionFactor_v<plln>}, std::nullopt,
											std::nullopt, PllR{rcc::DivisionFactor_v<pllr>}};
		// }
	}	 // namespace cpp_stm32::sys

	static constexpr auto CPU_WAIT_STATE = flash::WaitTable::getWaitState<VDD>(AHB_CLK);
	static constexpr auto NEED_OVERDRIVE = system_need_overdrive(AHB_CLK, APB1_CLK, APB2_CLK);
	static constexpr auto VOLTAGE_SCALE	 = determine_voltage_scale(AHB_CLK);
	static constexpr auto SYS_CLK_SRC		 = determine_sys_clk_src(SYS_CLK, HSE_CLK, HSI_CLK, MSI_CLK);

 public:
	static constexpr auto IS_CLOCK_DATA_VALID() noexcept {
		using rcc::SysClk;
		constexpr auto SYS_CLK_SRC_IS_PLL = SYS_CLK_SRC == SysClk::Pll;
		constexpr auto CLK_SRC_IS_VALID		= (SYS_CLK_SRC_IS_PLL && CLOCK_DATA.srcPLL.has_value());

		// constexpr auto HSE_FREQ_IS_VALID = HSE_CLK_FREQ_MIN <= HSE_CLK && HSE_CLK <= HSE_CLK_FREQ_MAX;
		constexpr auto APB1_CLK_IS_VALID = APB1_CLK <= APB1_FREQ_MAX_VOS_RANGE1;
		constexpr auto VDD_IS_VALID			 = STM32_VDD_MIN <= VDD && VDD <= STM32_VDD_MAX;

		constexpr auto MSI_IS_VALID = detail::find_if(MSI_FREQ_TABLE, [](auto const t_in) { return t_in == MSI_CLK; }) !=
																	std::tuple_size_v<decltype(MSI_FREQ_TABLE)>;
		// @todo other validity check...
		return CLK_SRC_IS_VALID && APB1_CLK_IS_VALID && VDD_IS_VALID && MSI_IS_VALID;
	}

	static constexpr void init() noexcept {
		static_assert(IS_CLOCK_DATA_VALID());
		using rcc::MsiRange, rcc::Frequency_v, rcc::PeriphClk, rcc::ClkSrc;

		if constexpr (CLOCK_DATA.bypassHSE) {
			rcc::bypass_clksrc<rcc::ClkSrc::Hse>();
		}

		// enable pll clock src, i.e., HSE, HSI or MSI
		if constexpr (CLOCK_DATA.srcPLL.has_value()) {
			rcc::enable_clk<CLOCK_DATA.srcPLL.value()>();
			rcc::wait_osc_rdy<CLOCK_DATA.srcPLL.value()>();
			rcc::set_sysclk<rcc::to_sys_clk(CLOCK_DATA.srcPLL.value())>();

			if constexpr (CLOCK_DATA.srcPLL.value() == ClkSrc::Msi) {
				rcc::enable_msi_range();
				rcc::set_msi_range(MsiRange{MSI_CLK});
			}

			{
				const auto& [m, n, p, q, r] = CALC_PLL_DIV_FACTOR<CLOCK_DATA.srcPLL.value()>();

				rcc::disable_clk<ClkSrc::Pll>();
				rcc::set_pllsrc_and_div_factor<CLOCK_DATA.srcPLL.value()>(m, n, p, q, r);
				rcc::enable_periph_clk<PeriphClk::Pwr>();
				pwr::set_voltage_scale(VOLTAGE_SCALE);
			}
		}

		rcc::enable_clk<ClkSrc::Pll>();

		constexpr auto wait_state = flash::Latency{flash::CpuWaitState_v<CPU_WAIT_STATE>};
		flash::config_access_ctl<flash::ARTAccel::InstructCache, flash::ARTAccel::DataCache>(wait_state);

		auto const& [ahb, apb1, apb2] = GET_ADVANCE_BUS_DIV_FACTOR();
		rcc::config_adv_bus_division_factor(ahb, apb1, apb2);

		if constexpr (CLOCK_DATA.srcPLL.has_value()) {
			rcc::wait_osc_rdy<ClkSrc::Pll>();	 // wait for PLL lock
		}

		// switch sysclk and wait ready
		rcc::set_sysclk<SYS_CLK_SRC>();
		rcc::wait_sysclk_rdy<SYS_CLK_SRC>();
	}
};

}	 // namespace cpp_stm32::sys
