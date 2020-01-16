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

#include "cpp_stm32/common/rcc.hxx"
#include "cpp_stm32/target/stm32/l4/memory/rcc_reg.hxx"

namespace cpp_stm32::rcc {

enum class PeriphClk : std::uint32_t {

	GpioA,
	GpioB,
	/*GpioC ~ GpioF*/

	Usart2,
	Pwr,

	Usart1,

};

/**
 *  @enum 	ClkSrc
 */
enum class ClkSrc : std::uint32_t { Hsi480, Msi, Hsi160, Hse, Pll, PllSai, Lse, Lsi };

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

class RccRegTable {
	// template <std::size_t Idx>
	// friend constexpr auto detail::get_periph_reg() noexcept;

 private:
	static constexpr std::tuple RccPeriphRst{
		std::pair{reg::AHB2RST, reg::Ahb2RstBit::GpioARst},
		std::pair{reg::AHB2RST, reg::Ahb2RstBit::GpioBRst},
		/*APB1*/
		std::pair{reg::APB1RST_1, reg::Apb1Rst1Bit::Usart2Rst},
		// std::pair{reg::APB1RST, RccApb1RstBit::PwrRst},
		/*APB2*/
		std::pair{reg::APB2RST, reg::Apb2RstBit::Usart1Rst},
	};

	static constexpr std::tuple RccPeriphEn{
		std::pair{reg::AHB2ENR, reg::Ahb2EnrBit::GpioAEn},
		std::pair{reg::AHB2ENR, reg::Ahb2EnrBit::GpioBEn},
		/*APB1*/
		std::pair{reg::APB1ENR_1, reg::Apb1Enr1Bit::Usart2En},
		// std::pair{reg::APB1ENR, RccApb1EnrBit::PwrEn},
		/*APB2*/
		std::pair{reg::APB2ENR, reg::Apb2EnrBit::Usart1En},
	};

	static constexpr std::tuple RccOscOn{
		std::pair{reg::CRRCR, reg::CrrCrBit::Hsi48On}, std::pair{reg::CR, reg::CrBit::MsiOn},
		std::pair{reg::CR, reg::CrBit::HsiOn},				 std::pair{reg::CR, reg::CrBit::HseOn},
		std::pair{reg::CR, reg::CrBit::PllOn},				 std::pair{reg::CR, reg::CrBit::PllSaiOn},
	};

	static constexpr std::tuple RccOscRdy{
		std::pair{reg::CRRCR, reg::CrrCrBit::Hsi48Rdy}, std::pair{reg::CR, reg::CrBit::MsiRdy},
		std::pair{reg::CR, reg::CrBit::HsiRdy},					std::pair{reg::CR, reg::CrBit::HseRdy},
		std::pair{reg::CR, reg::CrBit::PllRdy},					std::pair{reg::CR, reg::CrBit::PllSaiRdy},
	};

	static constexpr std::tuple ExtBypass{
		std::pair{reg::CR, reg::CrBit::HseByp},
		std::pair{reg::BDCR, reg::BdcrBit::LseByp},
	};

 public:
	// friend?
	template <PeriphClk PeriphClk>
	[[nodiscard]] static constexpr auto getPeriphEnReg() noexcept {
		return std::get<to_underlying(PeriphClk)>(RccPeriphEn);
	}

	template <PeriphClk PeriphClk>
	[[nodiscard]] static constexpr auto getPeriphRstReg() noexcept {
		return std::get<to_underlying(PeriphClk)>(RccPeriphRst);
	}

	template <ClkSrc Clk>
	[[nodiscard]] static constexpr auto const getOscOnReg() noexcept {
		return std::get<to_underlying(Clk)>(RccOscOn);
	}

	template <ClkSrc Clk>
	[[nodiscard]] static constexpr auto const getOscRdyReg() noexcept {
		return std::get<to_underlying(Clk)>(RccOscRdy);
	}

	template <ClkSrc Clk>
	[[nodiscard]] static constexpr auto const& getExtBypassReg() noexcept {
		static_assert(is_ext_clk<Clk>);
		if constexpr (Clk == ClkSrc::Hse) {
			return std::get<0>(ExtBypass);
		} else if constexpr (Clk == ClkSrc::Lse) {
			return std::get<1>(ExtBypass);
		}
	}
};

template <PeriphClk PeriphClk>
static constexpr void enable_periph_clk() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getPeriphEnReg<PeriphClk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <PeriphClk PeriphClk>
static constexpr void reset_periph_clk() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getOscOnReg<PeriphClk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <ClkSrc Clk>
static constexpr void enable_clk() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getOscOnReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<enable_bit>();
}

template <ClkSrc Clk>
static constexpr void disable_clk() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getOscOnReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<enable_bit>();
}

template <ClkSrc Clk>
static constexpr bool is_osc_rdy() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getOscRdyReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const rdy_bit			= std::get<1>(reg_bit_pair);
	return get<0>(CTL_REG.template readBit<rdy_bit>(ValueOnly));
}

template <ClkSrc Clk>
static constexpr void wait_osc_rdy() noexcept {
	while (!is_osc_rdy<Clk>()) {
	}
}

template <ClkSrc Clk>
static constexpr void bypass_clksrc() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getExtBypassReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<bypass_bit>();
}

template <ClkSrc Clk>
static constexpr void no_bypass() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::template getExtBypassReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<bypass_bit>();
}

template <SysClk Clk>
static constexpr void set_sysclk() noexcept {
	reg::CFGR.template setBit<reg::CfgBit::SW>(Clk);
}

static constexpr SysClk sysclk_in_use() noexcept {
	return get<0>(reg::CFGR.readBit<reg::CfgBit::SWS>(ValueOnly));	//
}

template <SysClk Clk>
static constexpr void wait_sysclk_rdy() noexcept {
	while (sysclk_in_use() != Clk) {
	}
}

template <ClkSrc Clk>
static constexpr void set_pllsrc() {
	static_assert(is_pll_clk_src<Clk>);
	reg::PLLCFGR.template setBit<reg::PllCfgBit::PllSrc>(Clk);
}

static constexpr void config_pll_division_factor(PllM const& t_pllm, PllN const& t_plln,
																								 std::optional<PllP> const& t_pllp = std::nullopt,
																								 std::optional<PllQ> const& t_pllq = std::nullopt,
																								 std::optional<PllR> const& t_pllr = std::nullopt) noexcept {
	std::uint8_t const enable_pllp = static_cast<bool>(t_pllp);
	std::uint8_t const enable_pllq = static_cast<bool>(t_pllq);
	std::uint8_t const enable_pllr = static_cast<bool>(t_pllr);

	auto const pllp_val		= t_pllp.value_or(PllP{DivisionFactor_v<7>});
	auto const pllq_val		= t_pllq.value_or(PllQ{DivisionFactor_v<2>});
	auto const pllr_val		= t_pllr.value_or(PllR{DivisionFactor_v<2>});
	auto const val_to_set = BitGroup{t_pllm, t_plln, pllp_val, enable_pllp, pllq_val, enable_pllq, pllr_val, enable_pllr};

	reg::PLLCFGR.setBit<reg::PllCfgBit::PllM, reg::PllCfgBit::PllN, reg::PllCfgBit::PllP, reg::PllCfgBit::PllPEn,
											reg::PllCfgBit::PllQ, reg::PllCfgBit::PllQEn, reg::PllCfgBit::PllR, reg::PllCfgBit::PllREn>(
		val_to_set);
}

template <ClkSrc Clk>
static constexpr void set_pllsrc_and_div_factor(PllM const& t_pllm, PllN const& t_plln,
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
	BitGroup const val_to_set{Clk, t_pllm, t_plln, pllp_val, enable_pllp, pllq_val, enable_pllq, pllr_val, enable_pllr};
	reg::PLLCFGR.setBit<reg::PllCfgBit::PllSrc, reg::PllCfgBit::PllM, reg::PllCfgBit::PllN, reg::PllCfgBit::PllP,
											reg::PllCfgBit::PllPEn, reg::PllCfgBit::PllQ, reg::PllCfgBit::PllQEn, reg::PllCfgBit::PllR,
											reg::PllCfgBit::PllREn>(val_to_set);
}

static constexpr void config_adv_bus_division_factor(HPRE const& t_hpre, PPRE const& t_ppre1, PPRE const& t_ppre2) {
	auto const val_to_set = BitGroup{t_hpre, t_ppre1, t_ppre2};
	reg::CFGR.setBit<reg::CfgBit::HPre, reg::CfgBit::PPre1, reg::CfgBit::PPre2>(val_to_set);
}

static constexpr void set_msi_range(MsiRange const& t_msi_range) noexcept {
	reg::CR.setBit<reg::CrBit::MsiRange>(t_msi_range);
}

static constexpr void enable_msi_range() noexcept { reg::CR.setBit<reg::CrBit::MsiRgSel>(std::uint8_t(1)); }

}	 // namespace cpp_stm32::rcc
