/**
 * @file  stm32/l4/clock.hxx
 * @brief	Clock data class for stm32l4
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

#include <optional>

#include "cpp_stm32/target/stm32/l4/define/rcc.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

namespace cpp_stm32::clock {

/**
 *
 */
struct ClockFreq {
	bool bypassHSE = false;
	bool bypassLSE = false;

	std::uint32_t freqHSE = HSE_DEFAULT_FREQ;
	std::uint32_t freqLSE = LSE_DEFAULT_FREQ;

	std::uint32_t freqMSI	= 4_M;
	std::uint32_t freqSYS	= 80_M;
	std::uint32_t freqAHB	= 80_M;
	std::uint32_t freqAPB1 = 80_M;
	std::uint32_t freqAPB2 = 80_M;

	float vdd = 3.3f;

	std::optional<rcc::ClkSrc> srcPLL = rcc::ClkSrc::Msi;
	std::optional<rcc::SysClk> srcSYS = std::nullopt;

	static constexpr std::uint32_t HSI_FREQ = 16_M;
	static constexpr std::uint32_t LSI_FREQ = 32_k;

	// @todo: LSE can't have second frequency!
	static constexpr std::uint32_t HSE_DEFAULT_FREQ = 0_M;
	static constexpr std::uint32_t LSE_DEFAULT_FREQ = 32.768_k;
};

}	// namespace cpp_stm32::clock
