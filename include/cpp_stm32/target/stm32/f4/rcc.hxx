/**
 * @file  stm32/f4/rcc.hxx
 * @brief	Rcc setup API for stm32f4
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

#include <array>
#include <tuple>
#include <utility>

#include "cpp_stm32/common/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/define/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/pin_map/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/register/rcc.hxx"

#include "project_config.hxx"

namespace cpp_stm32::rcc {

// extend en and rst so that it takes template param pack
template <PeriphClk Clk>
constexpr void enable_periph_clk() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getPeriphEnReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

/**
 * @brief		This function disables the peripheral clock
 * @tparam	Clk	Peripheral clock @ref rcc::PeriphClk
 */
template <PeriphClk Clk>
constexpr void disable_periph_clk() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getPeriphEnReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<enable_bit>();
}

template <PeriphClk Clk>
constexpr void pulse_reset_periph() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getPeriphRstReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto rst_bit			= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<rst_bit>();
	CTL_REG.template clearBit<rst_bit>();
}

template <PeriphClk Clk>
constexpr void release_reset_periph() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getPeriphRstReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto rst_bit			= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<rst_bit>();
}

template <PeriphClk Clk>
constexpr void hold_reset_periph() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getPeriphRstReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto rst_bit			= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<rst_bit>();
}

template <ClkSrc Clk>
constexpr void enable_clk() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getOscOnReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <ClkSrc Clk>
constexpr void disable_clk() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getOscOnReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<enable_bit>();
}

template <ClkSrc Clk>
constexpr bool is_osc_rdy() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getOscRdyReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto rdy_bit			= std::get<1>(reg_bit_pair);
	return std::get<0>(CTL_REG.template readBit<rdy_bit>(ValueOnly));
}

template <ClkSrc Clk>
constexpr void wait_osc_rdy() noexcept {
	while (!is_osc_rdy<Clk>()) {
	}
}

/**
 * @brief 	This function enables the bypass bit for the clock
 * @note 		The clock can only be HSE or LSE
 */
template <ClkSrc Clk>
constexpr void bypass_clksrc() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getExtBypassReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<bypass_bit>();
}

/**
 * @brief 	This function disables the bypass bit for the clock
 * @note 		The clock can only be HSE or LSE
 */
template <ClkSrc Clk>
constexpr void no_bypass() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getExtBypassReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<bypass_bit>();
}

template <SysClk Clk>
constexpr void set_sysclk() noexcept {
	reg::CFGR.template writeBit<reg::CfgBit::SW>(Clk);
}

constexpr SysClk sysclk_in_use() noexcept {
	return std::get<0>(reg::CFGR.readBit<reg::CfgBit::SWS>(ValueOnly));	 //
}

template <SysClk Clk>
constexpr void wait_sysclk_rdy() noexcept {
	while (sysclk_in_use() != Clk) {
	}
}

template <ClkSrc Clk>
constexpr void set_pllsrc() {
	static_assert(is_pll_clk_src<Clk>);
	reg::PLLCFGR.template writeBit<reg::PllCfgBit::PLLSRC>(Clk);
}

[[nodiscard]] constexpr auto get_pllsrc() noexcept { return reg::PLLCFGR.readBit<reg::PllCfgBit::PLLSRC>(ValueOnly); }

constexpr void config_pll_division_factor(PllM const t_pllm, PllN const t_plln, PllP const t_pllp, PllQ const t_pllq,
																					PllR const t_pllr) noexcept {
	reg::PLLCFGR.writeBit<reg::PllCfgBit::PLLM, reg::PllCfgBit::PLLN, reg::PllCfgBit::PLLP, reg::PllCfgBit::PLLQ,
												reg::PllCfgBit::PLLR>(t_pllm, t_plln, t_pllp, t_pllq, t_pllr);
}

/**
 * @brief	This function sets the pll clock clock src and pll division factor
 * @param t_pllm Division factor PLLM
 * @param t_plln Division factor PLLN
 * @param t_pllp Division factor PLLP
 * @param t_pllq Division factor PLLQ
 * @param t_pllr Division factor PLLR
 */
template <ClkSrc Clk>
constexpr void set_pllsrc_and_div_factor(PllMChecker const t_pllm, PllNChecker const t_plln, PllPChecker const t_pllp,
																				 PllQChecker const t_pllq, PllRChecker const t_pllr) noexcept {
	static_assert(is_pll_clk_src<Clk>);
	reg::PLLCFGR.writeBit<reg::PllCfgBit::PLLSRC, reg::PllCfgBit::PLLM, reg::PllCfgBit::PLLN, reg::PllCfgBit::PLLP,
												reg::PllCfgBit::PLLQ, reg::PllCfgBit::PLLR>(Clk, t_pllm(), t_plln(), t_pllp(), t_pllq(),
																																		t_pllr());
}

/**
 * @brief This function sets the division factor of the advance bus
 * @param t_hpre  Division factor HPRE
 * @param t_ppre1 Division factor PPRE1
 * @param t_ppre2 Division factor PPRE2
 */
constexpr void config_adv_bus_division_factor(HPREChecker const t_hpre, PPREChecker const t_ppre1,
																							PPREChecker const t_ppre2) {
	reg::CFGR.writeBit<reg::CfgBit::HPRE, reg::CfgBit::PPRE1, reg::CfgBit::PPRE2>(t_hpre(), t_ppre1(), t_ppre2());
}

/**
 * @brief	This function enables the RTC clock
 */
constexpr void enable_rtc() noexcept { reg::BDCR.setBit<reg::BDCRField::RTCEN>(); }

/**
 * @brief 	This function sets the rtc clock source
 * @tparam 	Clk 	Rtc clock source
 */
template <RtcClk Clk>
constexpr void set_rtc_clk_src() noexcept {
	reg::BDCR.template writeBit<reg::BDCRField::RTCSEL>(Clk);
}

/**
 * @brief 	This function sets the RTC clock prescaler
 * @note 		This function needs to be called only when HSE is selected as the RTC clock source
 */
constexpr void set_rtc_prescaler(RTCPRE const t_rtcpre) noexcept { reg::CFGR.writeBit<reg::CfgBit::RTCPRE>(t_rtcpre); }

/**
 * @brief	This function sets the reset bit of the backup domain, which will be in reset state unless explicitly call
 * 				release_reset_backup_domain()
 */
constexpr void hold_reset_backup_domain() noexcept { reg::BDCR.setBit<reg::BDCRField::BDRST>(); }

/**
 * @brief This function clears the reset bit of the backup domain, which release the reset state of the backup domain
 */
constexpr void release_reset_backup_domain() noexcept { reg::BDCR.clearBit<reg::BDCRField::BDRST>(); }

/**
 * @brief	This function returns divsion factors of the advanced buses
 * @return division factors HPRE, PPRE1, and PPRE2
 */
[[nodiscard]] constexpr auto get_adv_bus_division_factor() noexcept {
	return reg::CFGR.readBit<reg::CfgBit::HPRE, reg::CfgBit::PPRE1, reg::CfgBit::PPRE2>(ValueOnly);
}

/**
 * @brief	This function returns division factos of the PLL
 * @return division factors M, N, P, Q, R
 */
[[nodiscard]] constexpr auto get_pll_division_factor() noexcept {
	return reg::PLLCFGR.readBit<reg::PllCfgBit::PLLM, reg::PllCfgBit::PLLN, reg::PllCfgBit::PLLP, reg::PllCfgBit::PLLQ,
															reg::PllCfgBit::PLLR>(ValueOnly);
}

/**
 *	@brief 	This function returns the HSE clock frequency generated from project_config.hxx. For boards that have
 *					built-in external oscillator, calling this function is identical to using HSE_FREQ directly. However, for
 *					those that don't have built-in external oscillator, using HSE_FREQ directly may cause some problems. All in
 *					all, this function is the preferred way to interface HSE clock frequency.
 *
 *	@return HSE clock frequency
 */
[[nodiscard]] constexpr auto get_hse_freq() noexcept { return HSE_FREQ; }

/**
 *
 */
[[nodiscard]] constexpr auto get_ahb_clock_freq() noexcept {
	if constexpr (FIX_CLK_FREQ) {
		return AHB_FREQ;
	} else {
		auto const [hpre, ppre1, ppre2] = get_adv_bus_division_factor();
		auto const [m, n, p, q, r]			= get_pll_division_factor();

		const auto vco_freq = [m, n]() {
			auto const pll_src_freq = []() {
				if (auto const [pll_src] = get_pllsrc(); pll_src == rcc::ClkSrc::Hse) {
					return get_hse_freq();
				} else {
					return clock::ClockFreq::HSI_FREQ;
				}
			}();

			return pll_src_freq * n.get() / m.get();
		};

		auto const sys_freq = [p, r, vco_freq]() {
			switch (auto const sys_src = sysclk_in_use(); sys_src) {
				case rcc::SysClk::Pllp:
					return vco_freq() / p.get();
				case rcc::SysClk::Pllr:
					return vco_freq() / r.get();
				case rcc::SysClk::Hsi:
					return clock::ClockFreq::HSI_FREQ;
				case rcc::SysClk::Hse:
					return get_hse_freq();
			}
		}();

		return sys_freq / hpre.get();
	}
}

/**
 * @brief	This function returns the apb1 clock frequency
 * @return APB1 clock frequency
 */
[[nodiscard]] constexpr auto get_apb1_clock_freq() noexcept {
	if constexpr (FIX_CLK_FREQ) {
		return APB1_FREQ;
	} else {
		auto const ahb_clk_freq					= get_ahb_clock_freq();
		auto const [hpre, ppre1, ppre2] = get_adv_bus_division_factor();

		return ahb_clk_freq / ppre1.get();
	}
}

/**
 * @brief	This function returns the apb2 clock frequency
 * @return APB2 clock frequency
 */
[[nodiscard]] constexpr auto get_apb2_clock_freq() noexcept {
	if constexpr (FIX_CLK_FREQ) {
		return APB2_FREQ;
	} else {
		auto const ahb_clk_freq					= get_ahb_clock_freq();
		auto const [hpre, ppre1, ppre2] = get_adv_bus_division_factor();

		return ahb_clk_freq / ppre2.get();
	}
}

}	 // namespace cpp_stm32::rcc
