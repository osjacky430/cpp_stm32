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

#include <optional>
#include <tuple>

#include "cpp_stm32/common/rcc.hxx"
#include "cpp_stm32/target/stm32/l4/pin_map/pin_map.hxx"
#include "cpp_stm32/target/stm32/l4/register/rcc.hxx"

namespace cpp_stm32::rcc {

/**
 * [enable_periph_clk description]
 */
template <PeriphClk PeriphClk>
constexpr void enable_periph_clk() noexcept {
	constexpr auto const reg_bit_pair = ClkRegMap::template getPeriphEnReg<PeriphClk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <PeriphClk PeriphClk>
constexpr void reset_periph_clk() noexcept {
	constexpr auto const reg_bit_pair = ClkRegMap::template getPeriphRstReg<PeriphClk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const rst_bit			= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<rst_bit>();
}

template <ClkSrc Clk>
constexpr void enable_clk() noexcept {
	constexpr auto const reg_bit_pair = ClkRegMap::template getOscOnReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <ClkSrc Clk>
constexpr void disable_clk() noexcept {
	constexpr auto const reg_bit_pair = ClkRegMap::template getOscOnReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<enable_bit>();
}

template <ClkSrc Clk>
constexpr bool is_osc_rdy() noexcept {
	constexpr auto const reg_bit_pair = ClkRegMap::template getOscRdyReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const rdy_bit			= std::get<1>(reg_bit_pair);
	return std::get<0>(CTL_REG.template readBit<rdy_bit>(ValueOnly));
}

template <ClkSrc Clk>
constexpr void wait_osc_rdy() noexcept {
	while (!is_osc_rdy<Clk>()) {
	}
}

template <ClkSrc Clk>
constexpr void bypass_clksrc() noexcept {
	constexpr auto const reg_bit_pair = ClkRegMap::template getExtBypassReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<bypass_bit>();
}

template <ClkSrc Clk>
constexpr void no_bypass() noexcept {
	constexpr auto const reg_bit_pair = ClkRegMap::template getExtBypassReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<bypass_bit>();
}

template <SysClk Clk>
constexpr void set_sysclk() noexcept {
	reg::CFGR.template writeBit<reg::CFGRField::SW>(Clk);
}

constexpr SysClk sysclk_in_use() noexcept {
	return std::get<0>(reg::CFGR.readBit<reg::CFGRField::SWS>(ValueOnly));	//
}

template <SysClk Clk>
constexpr void wait_sysclk_rdy() noexcept {
	while (sysclk_in_use() != Clk) {
	}
}

template <ClkSrc Clk>
constexpr void set_pllsrc() {
	static_assert(is_pll_clk_src<Clk>);
	reg::PLLCFGR.template writeBit<reg::PLLCFGRField::PLLSRC>(Clk);
}

constexpr void config_pll_division_factor(PllM const& t_pllm, PllN const& t_plln,
																					std::optional<PllP> const& t_pllp = std::nullopt,
																					std::optional<PllQ> const& t_pllq = std::nullopt,
																					std::optional<PllR> const& t_pllr = std::nullopt) noexcept {
	std::uint8_t const enable_pllp = static_cast<bool>(t_pllp);
	std::uint8_t const enable_pllq = static_cast<bool>(t_pllq);
	std::uint8_t const enable_pllr = static_cast<bool>(t_pllr);

	auto const pllp_val = t_pllp.value_or(PllP{DivisionFactor_v<7>});
	auto const pllq_val = t_pllq.value_or(PllQ{DivisionFactor_v<2>});
	auto const pllr_val = t_pllr.value_or(PllR{DivisionFactor_v<2>});
	std::tuple const mod_val{t_pllm, t_plln, pllp_val, enable_pllp, pllq_val, enable_pllq, pllr_val, enable_pllr};

	reg::PLLCFGR
		.writeBit<reg::PLLCFGRField::PLLM, reg::PLLCFGRField::PLLN, reg::PLLCFGRField::PLLP, reg::PLLCFGRField::PLLPEN,
							reg::PLLCFGRField::PLLQ, reg::PLLCFGRField::PLLQEN, reg::PLLCFGRField::PLLR, reg::PLLCFGRField::PLLREN>(
			mod_val);
}

template <ClkSrc Clk>
constexpr void set_pllsrc_and_div_factor(PllM const& t_pllm, PllN const& t_plln,
																				 std::optional<PllP> const& t_pllp = std::nullopt,
																				 std::optional<PllQ> const& t_pllq = std::nullopt,
																				 std::optional<PllR> const& t_pllr = std::nullopt) noexcept {
	static_assert(is_pll_clk_src<Clk>);

	std::uint8_t const enable_pllp = static_cast<bool>(t_pllp);
	std::uint8_t const enable_pllq = static_cast<bool>(t_pllq);
	std::uint8_t const enable_pllr = static_cast<bool>(t_pllr);

	auto const pllp_val = t_pllp.value_or(PllP{DivisionFactor_v<7>});
	auto const pllq_val = t_pllq.value_or(PllQ{DivisionFactor_v<2>});
	auto const pllr_val = t_pllr.value_or(PllR{DivisionFactor_v<2>});
	std::tuple const mod_val{Clk, t_pllm, t_plln, pllp_val, enable_pllp, pllq_val, enable_pllq, pllr_val, enable_pllr};

	reg::PLLCFGR.writeBit<reg::PLLCFGRField::PLLSRC, reg::PLLCFGRField::PLLM, reg::PLLCFGRField::PLLN,
												reg::PLLCFGRField::PLLP, reg::PLLCFGRField::PLLPEN, reg::PLLCFGRField::PLLQ,
												reg::PLLCFGRField::PLLQEN, reg::PLLCFGRField::PLLR, reg::PLLCFGRField::PLLREN>(mod_val);
}

constexpr void config_adv_bus_division_factor(HPRE const& t_hpre, PPRE const& t_ppre1, PPRE const& t_ppre2) {
	reg::CFGR.writeBit<reg::CFGRField::HPRE, reg::CFGRField::PPRE1, reg::CFGRField::PPRE2>(t_hpre, t_ppre1, t_ppre2);
}

constexpr void set_msi_range(MsiRange const& t_msi_range) noexcept {
	reg::CR.writeBit<reg::CRField::MSIRANGE>(t_msi_range);
}

constexpr void enable_msi_range() noexcept { reg::CR.setBit<reg::CRField::MSIRGSEL>(); }

}	 // namespace cpp_stm32::rcc
