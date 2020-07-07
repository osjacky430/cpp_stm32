#pragma once

#include <array>
#include <cstdint>
#include <utility>

#include "cpp_stm32/detail/lookup_table.hxx"
#include "cpp_stm32/utility/literal_op.hxx"
#include "cpp_stm32/utility/macro.hxx"
#include "cpp_stm32/utility/strongly_typed.hxx"

namespace cpp_stm32::rcc {

// @todo change this to KeyValTable
SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(MsiRange, /**/
																		 std::pair{100_KHz, 0b000}, std::pair{200_KHz, 0b0001}, std::pair{400_KHz, 0b0010},
																		 std::pair{800_KHz, 0b0011}, std::pair{1_MHz, 0b0100}, std::pair{2_MHz, 0b0101},
																		 std::pair{4_MHz, 0b0110}, std::pair{8_MHz, 0b0111}, std::pair{16_MHz, 0b1000},
																		 std::pair{24_MHz, 0b1001}, std::pair{32_MHz, 0b1010}, std::pair{48_MHz, 0b1011});

/**
 *
 *
 */
using HPRE = detail::KeyValTable<struct CPP_STM32_LUT_HPRE, /**/
																 PAIR(1, 0b0000), PAIR(2, 0b1000), PAIR(4, 0b1001), PAIR(8, 0b1010), PAIR(16, 0b1011),
																 PAIR(64, 0b1100), PAIR(128, 0b1101), PAIR(256, 0b1110), PAIR(512, 0b1111)>;

/**
 *
 *
 */
using PPRE = detail::KeyValTable<struct CPP_STM32_LUT_PPRE, /**/
																 PAIR(1, 0b000), PAIR(2, 0b100), PAIR(4, 0b101), PAIR(8, 0b110), PAIR(16, 0b111)>;

/**
 *
 *
 */
using PllM = detail::KeyValTable<struct CPP_STM32_LUT_PLLM, /**/
																 PAIR(1, 0b000), PAIR(2, 0b001), PAIR(3, 0b010), PAIR(4, 0b011), PAIR(5, 0b100),
																 PAIR(6, 0b101), PAIR(7, 0b110), PAIR(8, 0b111)>;

/**
 *
 *
 */
using PllN = detail::KeyValTable<struct CPP_STM32_LUT_PLLN, 8, 86>;

/**
 *
 *
 */
using PllP = detail::KeyValTable<struct CPP_STM32_LUT_PLLP, PAIR(7, 0), PAIR(17, 1)>;

/**
 *
 */
using PllQ = detail::KeyValTable<struct CPP_STM32_LUT_PLLQ, /**/
																 PAIR(2, 0b00), PAIR(4, 0b01), PAIR(6, 0b10), PAIR(8, 0b11)>;

/**
 *
 *
 */
using PllR = detail::KeyValTable<struct CPP_STM32_LUT_PLLR, /**/
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
enum class SysClk : std::uint32_t { Msi, Hsi16, Hse, Pll };

/**
 *  @enum 	ClkSrc
 */
enum class ClkSrc : std::uint32_t { Hsi480, Msi, Hsi160, Hse, Pll, PllSai, Lse, Lsi };

/**
 * @brief		This function transform rcc enum to its equivalent sys enum
 * @param 	t_rcc  see ::ClkSrc
 */
static constexpr auto to_sys_clk = [](ClkSrc t_rcc) {
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
};

/**
 *
 */
template <ClkSrc Clk>
static constexpr bool is_ext_clk = (Clk == ClkSrc::Hse || Clk == ClkSrc::Lse);

template <ClkSrc Clk>
static constexpr bool is_pll_clk_src = (Clk == ClkSrc::Hse || Clk == ClkSrc::Hsi160 || Clk == ClkSrc::Msi);

}	// namespace cpp_stm32::rcc
