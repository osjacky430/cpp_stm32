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

#include "cpp_stm32/target/stm32/f4/memory/rcc_reg.hxx"

enum class RccPeriph : std::uint32_t {
	/*AHB1*/
	GpioA,
	GpioB,
	/*GpioC ~ GpioF*/

	/*APB1*/
	Usart2,
	Pwr,

	/*APB2*/
	Usart1,

};

enum class RccOsc : std::uint32_t { HsiOsc, HseOsc, PllOsc, PllI2cOsc, PllSaiOsc, LseOsc, LsiOsc };

enum class SysClk : std::uint32_t { Hsi, Hse, Pllp, Pllr };

template <RccOsc Clk>
struct ExtClk {
	static_assert(Clk == RccOsc::HseOsc || Clk == RccOsc::LseOsc);
};

template <RccOsc Clk>
struct PllClkSrc {
	static_assert(Clk == RccOsc::HseOsc || Clk == RccOsc::HsiOsc);
};

class RccRegTable {
 private:
	static constexpr std::tuple RccPeriphRst{
		/*AHB1*/
		std::pair{RCC_AHB1RST, RccAhb1RstBit::GpioARst},
		std::pair{RCC_AHB1RST, RccAhb1RstBit::GpioBRst},
		/*APB1*/
		std::pair{RCC_APB1RST, RccApb1RstBit::Usart2Rst},
		std::pair{RCC_APB1RST, RccApb1RstBit::PwrRst},
		/*APB2*/
		std::pair{RCC_APB2RST, RccApb2RstBit::Usart1Rst},
	};

	static constexpr std::tuple RccPeriphEn{
		/*AHB1*/
		std::pair{RCC_AHB1ENR, RccAhb1EnrBit::GpioAEn},
		std::pair{RCC_AHB1ENR, RccAhb1EnrBit::GpioBEn},
		/*APB1*/
		std::pair{RCC_APB1ENR, RccApb1EnrBit::Usart2En},
		std::pair{RCC_APB1ENR, RccApb1EnrBit::PwrEn},
		/*APB2*/
		std::pair{RCC_APB2ENR, RccApb2EnrBit::Usart1En},
	};

	static constexpr std::tuple RccOscOn{
		std::pair{RCC_CR, RccCrBit::HsiOn},
		std::pair{RCC_CR, RccCrBit::HseOn},
		std::pair{RCC_CR, RccCrBit::PllOn},
		std::pair{RCC_CR, RccCrBit::PllSaiOn},
	};

	static constexpr std::tuple RccOscRdy{
		std::pair{RCC_CR, RccCrBit::HsiRdy},
		std::pair{RCC_CR, RccCrBit::HseRdy},
		std::pair{RCC_CR, RccCrBit::PllRdy},
		std::pair{RCC_CR, RccCrBit::PllSaiRdy},
	};

	static constexpr std::tuple ExtBypass{
		std::pair{RCC_CR, RccCrBit::HseByp},
		std::pair{RCC_BDCR, RccBdcrBit::LseByp},
	};

 public:
	template <RccPeriph PeriphClk>
	[[nodiscard]] static constexpr auto getPeriphEnReg() noexcept {
		return std::get<to_underlying(PeriphClk)>(RccPeriphEn);
	}

	template <RccPeriph PeriphClk>
	[[nodiscard]] static constexpr auto getPeriphRstReg() noexcept {
		return std::get<to_underlying(PeriphClk)>(RccPeriphRst);
	}

	template <RccOsc Clk>
	[[nodiscard]] static constexpr auto const getOscOnReg() noexcept {
		return std::get<to_underlying(Clk)>(RccOscOn);
	}

	template <RccOsc Clk>
	[[nodiscard]] static constexpr auto const getOscRdyReg() noexcept {
		return std::get<to_underlying(Clk)>(RccOscRdy);
	}

	template <RccOsc Clk>
	[[nodiscard]] static constexpr auto const& getExtBypassReg(ExtClk<Clk> const) noexcept {
		if constexpr (Clk == RccOsc::HseOsc) {
			return std::get<0>(ExtBypass);
		} else if constexpr (Clk == RccOsc::LseOsc) {
			return std::get<1>(ExtBypass);
		}
	}
};

// extend en and rst so that it takes template param pack
template <RccPeriph PeriphClk>
static constexpr void rcc_enable_periph_clk() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::getPeriphEnReg<PeriphClk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <RccPeriph PeriphClk>
static constexpr void rcc_reset_periph_clk() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::getPeriphRstReg<PeriphClk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <RccOsc Clk>
static constexpr void rcc_enable_clk() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::getOscOnReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <RccOsc Clk>
static constexpr void rcc_disable_clk() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::getOscOnReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<enable_bit>();
}

template <RccOsc Clk>
static constexpr bool rcc_is_osc_rdy() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::getOscRdyReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const rdy_bit			= std::get<1>(reg_bit_pair);
	return get<0>(CTL_REG.template readBit<rdy_bit>(ValueOnly));
}

template <RccOsc Clk>
static constexpr void rcc_wait_osc_rdy() noexcept {
	while (!rcc_is_osc_rdy<Clk>()) {
	}
}

template <RccOsc Clk>
static constexpr void rcc_bypass_clksrc() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::getExtBypassReg(ExtClk<Clk>{});
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<bypass_bit>();
}

template <RccOsc Clk>
static constexpr void rcc_no_bypass() noexcept {
	constexpr auto const reg_bit_pair = RccRegTable::getExtBypassReg(ExtClk<Clk>{});
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<bypass_bit>();
}

template <SysClk Clk>
static constexpr void rcc_set_sysclk() noexcept {
	RCC_CFGR.template setBit<RccCfgBit::SW>(Clk);
}

static constexpr SysClk rcc_sysclk_in_use() noexcept {
	return get<0>(RCC_CFGR.readBit<RccCfgBit::SWS>(ValueOnly));	 //
}

template <SysClk Clk>
static constexpr void rcc_wait_sysclk_rdy() noexcept {
	while (rcc_sysclk_in_use() != Clk) {
	}
}

// shouldnt these constraints set in the beginning? (in rcc_reg.hxx)
// consider abstracting the clock src, e.g. class Hse, class Hsi etc.
// and use sfinae to ensure the availability, however, doing so maybe requires other functions
// become template function even if there are no special requirements
template <RccOsc Clk>
static constexpr void rcc_set_pllsrc(PllClkSrc<Clk> const&) {
	RCC_PLLCFGR.template setBit<RccPllCfgBit::PLLSRC>(Clk);
}

static constexpr void rcc_config_pll_division_factor(PllM const& t_pllm, PllN const& t_plln, PllP const& t_pllp,
																										 PllQ const& t_pllq, PllR const& t_pllr) noexcept {
	auto const val_to_set = BitGroup{t_pllm, t_plln, t_pllp, t_pllq, t_pllr};
	RCC_PLLCFGR
		.setBit<RccPllCfgBit::PLLM, RccPllCfgBit::PLLN, RccPllCfgBit::PLLP, RccPllCfgBit::PLLQ, RccPllCfgBit::PLLR>(
			val_to_set);
}

template <RccOsc Clk>
static constexpr void rcc_set_pllsrc_and_div_factor(PllClkSrc<Clk> const&, PllM const& t_pllm, PllN const& t_plln,
																										PllP const& t_pllp, PllQ const& t_pllq,
																										PllR const& t_pllr) noexcept {
	auto const val_to_set = BitGroup{Clk, t_pllm, t_plln, t_pllp, t_pllq, t_pllr};
	RCC_PLLCFGR.setBit<RccPllCfgBit::PLLSRC, RccPllCfgBit::PLLM, RccPllCfgBit::PLLN, RccPllCfgBit::PLLP,
										 RccPllCfgBit::PLLQ, RccPllCfgBit::PLLR>(val_to_set);
}

static constexpr void rcc_config_adv_bus_division_factor(HPRE const& t_hpre, PPRE const& t_ppre1, PPRE const& t_ppre2) {
	auto const val_to_set = BitGroup{t_hpre, t_ppre1, t_ppre2};
	RCC_CFGR.setBit<RccCfgBit::HPRE, RccCfgBit::PPRE1, RccCfgBit::PPRE2>(val_to_set);
}
