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

#include "cpp_stm32/target/stm32/f4/memory/pwr_reg.hxx"

enum class VoltageScale { Scale1Mode = 0b11, Scale2Mode = 0b10, Scale3Mode = 0b01 };

// only set with pll is enabled
// @ref https://community.st.com/s/question/0D50X0000A4qUmwSQE/more-documentation-about-vosrdy
constexpr auto pwr_is_vos_rdy() noexcept { return get<0>(PWR_CSR.readBit<PwrCsrBit::VosRdy>(ValueOnly)); }

constexpr void pwr_enable_overdrive() noexcept { PWR_CR.setBit<PwrCrBit::OdEn>(); }

constexpr void pwr_enable_overdrive_switch() noexcept { PWR_CR.setBit<PwrCrBit::OdSwEn>(); }

constexpr auto pwr_is_overdrive_rdy() noexcept { return get<0>(PWR_CSR.readBit<PwrCsrBit::OdrRdy>(ValueOnly)); }

constexpr auto pwr_is_overdrive_switch_rdy() noexcept {
	return get<0>(PWR_CSR.readBit<PwrCsrBit::OdrSwRdy>(ValueOnly));
}

constexpr void pwr_wait_vos_rdy() noexcept {
	while (pwr_is_vos_rdy() != 1) {
	}
}

constexpr void pwr_wait_overdrive_rdy() noexcept {
	while (pwr_is_overdrive_rdy() != 1) {
	}
}

constexpr void pwr_wait_overdrive_switch_rdy() noexcept {
	while (pwr_is_overdrive_switch_rdy() != 1) {
	}
}

constexpr void pwr_set_voltage_scale(VoltageScale const& t_val) noexcept { PWR_CR.setBit<PwrCrBit::Vos>(t_val); }
