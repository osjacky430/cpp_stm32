/**
 * @file  stm32/f4/clock.hxx
 * @brief	Clock data class for stm32f4
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

#include "cpp_stm32/target/stm32/f4/define/rcc.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

namespace cpp_stm32::clock {

/**
 * @class 	ClockFreq
 * @brief 	This class contains all the information that it needs to initialize the clocks
 */
struct ClockFreq {
	bool bypassHSE = false;
	bool bypassLSE = false;

	std::uint32_t freqHSE = HSE_DEFAULT_FREQ;
	std::uint32_t freqLSE = LSE_DEFAULT_FREQ;

	std::uint32_t freqSYS	= 180_M;
	std::uint32_t freqAHB	= 180_M;
	std::uint32_t freqAPB1 = 45_M;
	std::uint32_t freqAPB2 = 90_M;

	float vdd = 3.3f;

	std::optional<rcc::ClkSrc> srcPLL = std::nullopt;
	std::optional<rcc::SysClk> srcSYS = std::nullopt;

	// these two are fixed
	static constexpr std::uint32_t HSI_FREQ = 16_M;
	static constexpr std::uint32_t LSI_FREQ = 32_k;

	static constexpr std::uint32_t HSE_DEFAULT_FREQ = 8_M;
	static constexpr std::uint32_t LSE_DEFAULT_FREQ = 32.768_k;
};

/**
 * @class ClockBuilder
 * @brief This class is a builder class to handle complex initialization process of RCC
 */
class ClockBuilder {
	ClockFreq m_clock{};

 public:
	constexpr ClockBuilder& setHSE(bool const t_bypass,
																 std::uint32_t const t_freq = ClockFreq::HSE_DEFAULT_FREQ) noexcept {
		m_clock.bypassHSE = t_bypass;
		m_clock.freqHSE		= t_freq;
		return *this;
	}

	constexpr ClockBuilder& setLSE(bool const t_bypass,
																 std::uint32_t const t_freq = ClockFreq::LSE_DEFAULT_FREQ) noexcept {
		m_clock.bypassLSE = t_bypass;
		m_clock.freqLSE		= t_freq;
		return *this;
	}

	constexpr ClockBuilder& setPLL(rcc::ClkSrc const t_src) noexcept {
		m_clock.srcPLL = t_src;

		return *this;
	}

	constexpr ClockBuilder& setSYS(std::uint32_t const t_freq) noexcept {
		m_clock.freqSYS = t_freq;

		return *this;
	}

	constexpr ClockBuilder& setAHB(std::uint32_t const t_freq) noexcept {
		m_clock.freqAHB = t_freq;
		return *this;
	}

	constexpr ClockBuilder& setAPB1(std::uint32_t const t_freq) noexcept {
		m_clock.freqAPB1 = t_freq;
		return *this;
	}

	constexpr ClockBuilder& setAPB2(std::uint32_t const t_freq) noexcept {
		m_clock.freqAPB2 = t_freq;
		return *this;
	}

	constexpr ClockBuilder& setSupplyVoltage(float const t_vdd) noexcept {
		m_clock.vdd = t_vdd;
		return *this;
	}

	constexpr ClockFreq buildClock() const noexcept { return this->m_clock; }
};

}	// namespace cpp_stm32::clock
