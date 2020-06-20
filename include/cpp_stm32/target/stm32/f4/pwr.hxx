/**
 * @file  stm32/f4/pwr.hxx
 * @brief	Pwr setup API for stm32f4
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

#include "cpp_stm32/target/stm32/f4/register/pwr.hxx"

namespace cpp_stm32::pwr {

enum class VoltageScale { Scale1Mode = 0b11, Scale2Mode = 0b10, Scale3Mode = 0b01 };

// only set when pll is enabled
// @ref https://community.st.com/s/question/0D50X0000A4qUmwSQE/more-documentation-about-vosrdy
constexpr auto is_vos_rdy() noexcept { return std::get<0>(reg::CSR.readBit<reg::CsrBit::VosRdy>(ValueOnly)); }

constexpr void enable_overdrive() noexcept { reg::CR.setBit<reg::CrBit::OdEn>(); }

constexpr void enable_overdrive_switch() noexcept { reg::CR.setBit<reg::CrBit::OdSwEn>(); }

constexpr auto is_overdrive_rdy() noexcept { return std::get<0>(reg::CSR.readBit<reg::CsrBit::OdrRdy>(ValueOnly)); }

constexpr auto is_overdrive_switch_rdy() noexcept {
	return std::get<0>(reg::CSR.readBit<reg::CsrBit::OdrSwRdy>(ValueOnly));
}

constexpr void wait_vos_rdy() noexcept {
	while (is_vos_rdy() != 1) {
	}
}

constexpr void wait_overdrive_rdy() noexcept {
	while (is_overdrive_rdy() != 1) {
	}
}

constexpr void wait_overdrive_switch_rdy() noexcept {
	while (is_overdrive_switch_rdy() != 1) {
	}
}

constexpr void set_voltage_scale(VoltageScale const& t_val) noexcept { reg::CR.writeBit<reg::CrBit::Vos>(t_val); }

/**
 * @brief	This function unlocks write protection so that write to RCC_BDCR register is valid
 */
constexpr void unlock_write_protection() noexcept { reg::CR.setBit<reg::CrBit::DBP>(); }

/**
 * @brief This function locks write protection so that write to RCC_BDCR register is not valid
 */
constexpr void lock_write_protection() noexcept { reg::CR.clearBit<reg::CrBit::DBP>(); }

}	 // namespace cpp_stm32::pwr
