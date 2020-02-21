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

#include <array>
#include <tuple>
#include <utility>

#include "cpp_stm32/common/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/pin_map.hxx"

#include "cpp_stm32/target/stm32/f4/register/rcc.hxx"

namespace cpp_stm32::rcc {

// extend en and rst so that it takes template param pack
template <PeriphClk PeriphClk>
static constexpr void enable_periph_clk() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getPeriphEnReg<PeriphClk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <PeriphClk PeriphClk>
static constexpr void reset_periph_clk() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getPeriphRstReg<PeriphClk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto rst_bit			= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<rst_bit>();
}

template <ClkSrc Clk>
static constexpr void enable_clk() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getOscOnReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <ClkSrc Clk>
static constexpr void disable_clk() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getOscOnReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<enable_bit>();
}

template <ClkSrc Clk>
static constexpr bool is_osc_rdy() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getOscRdyReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto rdy_bit			= std::get<1>(reg_bit_pair);
	return std::get<0>(CTL_REG.template readBit<rdy_bit>(ValueOnly));
}

template <ClkSrc Clk>
static constexpr void wait_osc_rdy() noexcept {
	while (!is_osc_rdy<Clk>()) {
	}
}

template <ClkSrc Clk>
static constexpr void bypass_clksrc() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getExtBypassReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<bypass_bit>();
}

template <ClkSrc Clk>
static constexpr void no_bypass() noexcept {
	constexpr auto reg_bit_pair = ClkRegMap::template getExtBypassReg<Clk>();
	constexpr auto CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<bypass_bit>();
}

template <SysClk Clk>
static constexpr void set_sysclk() noexcept {
	reg::CFGR.template writeBit<reg::CfgBit::SW>(Clk);
}

static constexpr SysClk sysclk_in_use() noexcept {
	return std::get<0>(reg::CFGR.readBit<reg::CfgBit::SWS>(ValueOnly));	//
}

template <SysClk Clk>
static constexpr void wait_sysclk_rdy() noexcept {
	while (sysclk_in_use() != Clk) {
	}
}

template <ClkSrc Clk>
static constexpr void set_pllsrc() {
	static_assert(is_pll_clk_src<Clk>);
	reg::PLLCFGR.template writeBit<reg::PllCfgBit::PLLSRC>(Clk);
}

static constexpr void config_pll_division_factor(PllM const& t_pllm, PllN const& t_plln, PllP const& t_pllp,
																								 PllQ const& t_pllq, PllR const& t_pllr) noexcept {
	reg::PLLCFGR.writeBit<reg::PllCfgBit::PLLM, reg::PllCfgBit::PLLN, reg::PllCfgBit::PLLP, reg::PllCfgBit::PLLQ,
												reg::PllCfgBit::PLLR>(t_pllm, t_plln, t_pllp, t_pllq, t_pllr);
}

template <ClkSrc Clk>
static constexpr void set_pllsrc_and_div_factor(PllM const& t_pllm, PllN const& t_plln, PllP const& t_pllp,
																								PllQ const& t_pllq, PllR const& t_pllr) noexcept {
	static_assert(is_pll_clk_src<Clk>);
	reg::PLLCFGR.writeBit<reg::PllCfgBit::PLLSRC, reg::PllCfgBit::PLLM, reg::PllCfgBit::PLLN, reg::PllCfgBit::PLLP,
												reg::PllCfgBit::PLLQ, reg::PllCfgBit::PLLR>(Clk, t_pllm, t_plln, t_pllp, t_pllq, t_pllr);
}

static constexpr void config_adv_bus_division_factor(HPRE const& t_hpre, PPRE const& t_ppre1, PPRE const& t_ppre2) {
	reg::CFGR.writeBit<reg::CfgBit::HPRE, reg::CfgBit::PPRE1, reg::CfgBit::PPRE2>(t_hpre, t_ppre1, t_ppre2);
}

}	 // namespace cpp_stm32::rcc
