/**
 * @file  stm32/f4/define/rcc.hxx
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

#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/detail/lookup_table.hxx"

namespace cpp_stm32::rcc {

/**
 * @class 	PllM
 * @brief		Utility class used to check whether division factor is reasonable.
 * @note		PllM valid number lies between 2 and 63
 */
using PllM = detail::KeyValTable<struct CPP_STM32_LUT_PLLM, 2, 63>;

/**
 * @class		PllN
 * @brief		Utility class used to check whether division factor is reasonable.
 * @note		PllN valid number lies between 50 and 432
 */
using PllN = detail::KeyValTable<struct CPP_STM32_LUT_PLLN, 50, 432>;

/**
 * @class 	PllP
 * @brief		Utility class used to check whether division factor is reasonable.
 * @note 		PllP valid number:
 *
 * 					 DivFactor |   RegVal
 * 				  -----------|-----------
 * 					     2		 |	 0b00
 * 							 4		 |	 0b01
 * 							 6		 |   0b10
 * 							 8		 |	 0b11
 */
using PllP = detail::KeyValTable<struct CPP_STM32_LUT_PLLP, /**/
																 PAIR(2, 0b00), PAIR(4, 0b01), PAIR(6, 0b10), PAIR(8, 0b11)>;
/**
 * @class 	PllQ
 * @brief		Utility class used to check whether division factor is reasonable.
 * @note		PllQ valid number lies between 2 and 15
 */
using PllQ = detail::KeyValTable<struct CPP_STM32_LUT_PLLQ, 2, 15>;

/**
 * @class 	PllR
 * @brief		Utility class used to check whether division factor is reasonable.
 * @note 		PllR valid number lies between 2 and 7
 */
using PllR = detail::KeyValTable<struct CPP_STM32_LUT_PLLR, 2, 7>;

/**
 * @class 	HPRE
 * @brief
 */
using HPRE = detail::KeyValTable<struct CPP_STM32_LUT_HPRE, /**/
																 PAIR(1, 0b0000), PAIR(2, 0b1000), PAIR(4, 0b1001), PAIR(8, 0b1010), PAIR(16, 0b1011),
																 PAIR(64, 0b1100), PAIR(128, 0b1101), PAIR(256, 0b1110), PAIR(512, 0b1111)>;

/**
 * @class PPRE
 * @brief
 */
using PPRE = detail::KeyValTable<struct CPP_STM32_LUT_PPRE, /**/
																 PAIR(1, 0b000), PAIR(2, 0b100), PAIR(4, 0b101), PAIR(8, 0b110), PAIR(16, 0b111)>;
/**
 * [SETUP_LOOKUP_TABLE_WITH_BOUND description]
 */
using RTCPRE = detail::KeyValTable<struct CPP_STM32_LUT_RTCPRE, 2, 31>;

/**
 *	@enum 	PeriphClk
 */
enum class PeriphClk : std::uint32_t {
	/*AHB1*/
	GpioA,
	GpioB,
	GpioC,
	/*GpioC ~ GpioF*/

	Dma1,
	Dma2,
	/*APB1*/
	Spi2,
	Spi3,
	Usart2,
	Usart3,
	Uart4,
	Uart5,
	I2c1,
	I2c2,
	I2c3,

	Pwr,

	/*APB2*/
	Usart1,
	Usart6,
	SysCfg,
};

enum class ClkSrc : std::uint8_t { Hsi, Hse, Pll, PllI2c, PllSai, Lse, Lsi };

/**
 * @enum 		SysClk
 * @brief		Three different clock sources can be used to drive the system clock
 * 					- HSI (High Speed Internal) oscillator clock
 * 					- HSE (High Speed External) oscillator clock
 * 					- Two main PLL (Phase Lock Loop) clock
 */
enum class SysClk : std::uint8_t { Hsi, Hse, Pllp, Pllr };

/**
 * @enum 		RtcClk
 * @brief		Three different clock sources can be used to drive the real time clock
 * 					- Lse (Low Speed External) oscillator clock
 * 					- Lsi (Low Speed Internal) oscillator clock
 * 					- Hse (High speed External) oscillator clock
 */
enum class RtcClk : std::uint8_t { NoClk, Lse, Lsi, Hse };

/**
 *
 */
template <ClkSrc Clk>
static constexpr bool is_ext_clk = (Clk == ClkSrc::Hse || Clk == ClkSrc::Lse);

template <ClkSrc Clk>
static constexpr bool is_pll_clk_src = (Clk == ClkSrc::Hse || Clk == ClkSrc::Hsi);

}	// namespace cpp_stm32::rcc
