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

#include <tuple>

#include "cpp_stm32/utility/register.hxx"

namespace cpp_stm32::stm32::detail {

;	//

template <typename RccRegTable, typename RccPeriph, RccPeriph PeriphClk>
static constexpr void rcc_enable_periph_clk_impl() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getPeriphEnReg<PeriphClk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <typename RccRegTable, typename RccPeriph, RccPeriph PeriphClk>
static constexpr void rcc_reset_periph_clk_impl() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getPeriphRstReg<PeriphClk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <typename RccRegTable, typename RccOsc, RccOsc Clk>
static constexpr void rcc_enable_clk_impl() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getOscOnReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <typename RccRegTable, typename RccOsc, RccOsc Clk>
static constexpr void rcc_disable_clk_impl() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getOscOnReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<enable_bit>();
}

template <typename RccRegTable, typename RccOsc, RccOsc Clk>
static constexpr bool rcc_is_osc_rdy_impl() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getOscRdyReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const rdy_bit			= std::get<1>(reg_bit_pair);
	return get<0>(CTL_REG.template readBit<rdy_bit>(ValueOnly));
}

template <typename RccRegTable, typename RccOsc, RccOsc Clk>
static constexpr void rcc_bypass_clksrc_impl() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getExtBypassReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<bypass_bit>();
}

template <typename RccRegTable, typename RccOsc, RccOsc Clk>
static constexpr void rcc_no_bypass_impl() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getExtBypassReg();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<bypass_bit>();
}

}	// namespace cpp_stm32::stm32::detail
