/**
 * @file  stm32/l4/define/rcc.hxx
 * @brief	Rcc class and enum define.
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
#include <cstdint>
#include <utility>

#include "cpp_stm32/detail/lookup_table.hxx"
#include "cpp_stm32/utility/literal_op.hxx"
#include "cpp_stm32/utility/strongly_typed.hxx"

namespace cpp_stm32::rcc {

/**
 *
 */
using MsiRange =
	detail::TypeTable<struct CPP_STM32_LUT_MSIRANGE, /**/
										detail::TypePair<Frequency<100_k>, 0b0000>, detail::TypePair<Frequency<200_k>, 0b0001>,
										detail::TypePair<Frequency<400_k>, 0b0010>, detail::TypePair<Frequency<800_k>, 0b0011>,
										detail::TypePair<Frequency<1_M>, 0b0011>, detail::TypePair<Frequency<2_M>, 0b0101>,
										detail::TypePair<Frequency<4_M>, 0b0110>, detail::TypePair<Frequency<8_M>, 0b0111>,
										detail::TypePair<Frequency<16_M>, 0b1000>, detail::TypePair<Frequency<24_M>, 0b1001>,
										detail::TypePair<Frequency<32_M>, 0b1010>, detail::TypePair<Frequency<48_M>, 0b1011> >;

/**
 *
 *
 */
using HPRE = StrongType<std::uint32_t, struct CPP_STM32_HPRE>;
using HPREChecker =
	detail::KeyValTable<HPRE, /**/
											PAIR(1, 0b0000), PAIR(2, 0b1000), PAIR(4, 0b1001), PAIR(8, 0b1010), PAIR(16, 0b1011),
											PAIR(64, 0b1100), PAIR(128, 0b1101), PAIR(256, 0b1110), PAIR(512, 0b1111)>;

/**
 *
 *
 */
using PPRE = StrongType<std::uint32_t, struct CPP_STM32_PPRE>;
using PPREChecker =
	detail::KeyValTable<PPRE, /**/
											PAIR(1, 0b000), PAIR(2, 0b100), PAIR(4, 0b101), PAIR(8, 0b110), PAIR(16, 0b111)>;

/**
 *
 *
 */
using PllM				= StrongType<std::uint32_t, struct CPP_STM32_PLLM>;
using PllMChecker = detail::KeyValTable<PllM, /**/
																				PAIR(1, 0b000), PAIR(2, 0b001), PAIR(3, 0b010), PAIR(4, 0b011), PAIR(5, 0b100),
																				PAIR(6, 0b101), PAIR(7, 0b110), PAIR(8, 0b111)>;

/**
 *
 *
 */
using PllN				= StrongType<std::uint32_t, struct CPP_STM32_PLLN>;
using PllNChecker = detail::KeyValTable<PllN, 8, 86>;

/**
 *
 *
 */
using PllP				= StrongType<std::uint32_t, struct CPP_STM32_PLLP>;
using PllPChecker = detail::KeyValTable<PllP, PAIR(7, 0), PAIR(17, 1)>;

/**
 *
 */
using PllQ				= StrongType<std::uint32_t, struct CPP_STM32_HPRE>;
using PllQChecker = detail::KeyValTable<PllQ, /**/
																				PAIR(2, 0b00), PAIR(4, 0b01), PAIR(6, 0b10), PAIR(8, 0b11)>;

/**
 *
 *
 */
using PllR				= StrongType<std::uint32_t, struct CPP_STM32_HPRE>;
using PllRChecker = detail::KeyValTable<PllR, /**/
																				PAIR(2, 0b00), PAIR(4, 0b01), PAIR(6, 0b10), PAIR(8, 0b11)>;

/**
 * @enum 		PeriphClk
 * @brief		It is used @ref rcc::enable_periph_clk and @ref rcc::reset_periph_clk
 */
enum class PeriphClk : std::uint32_t {

	GpioA,
	GpioB,
	/*GpioC ~ GpioF*/

	Usart2,
	Pwr,

	Spi1,
	Usart1,
};

/**
 * 	@enum 	SysClk
 * 	@brief	Four different clock sources can be used to drive the system clock:
 * 					- HSI16 (High Speed Internal) 16 MHz RC oscillator clock
 * 					- MSI (Multi Speed Internal) RC oscillator clock
 * 					- HSE (High Speed External) oscillator clock, from 4 to 48 MHz
 * 					- PLL Clock
 */
enum class SysClk : std::uint8_t { Msi, Hsi16, Hse, Pll };

/**
 *  @enum 	ClkSrc
 *
 * @todo 		why 480 instead of 48?
 */
enum class ClkSrc : std::uint8_t { Hsi480, Msi, Hsi160, Hse, Pll, PllSai, Lse, Lsi };

/**
 * @brief		This function transform rcc enum to its equivalent sys enum
 * @param 	t_rcc  see ::ClkSrc
 */
static constexpr auto to_sys_clk(ClkSrc t_rcc) noexcept {
	switch (t_rcc) {
		case ClkSrc::Hsi160:
			return SysClk::Hsi16;
		case ClkSrc::Msi:
			return SysClk::Msi;
		case ClkSrc::Hse:
			return SysClk::Hse;
		case ClkSrc::Pll:
			return SysClk::Pll;
		default:
			break;
	}
}

/**
 *
 */
template <ClkSrc Clk>
static constexpr bool is_ext_clk = (Clk == ClkSrc::Hse || Clk == ClkSrc::Lse);

template <ClkSrc Clk>
static constexpr bool is_pll_clk_src = (Clk == ClkSrc::Hse || Clk == ClkSrc::Hsi160 || Clk == ClkSrc::Msi);

}	 // namespace cpp_stm32::rcc
