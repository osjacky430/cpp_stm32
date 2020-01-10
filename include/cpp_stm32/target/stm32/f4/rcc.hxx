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

#include "cpp_stm32/target/stm32/common/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/memory/rcc_reg.hxx"

namespace cpp_stm32::stm32::f4 {

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
static constexpr bool is_ext_clk = (Clk == RccOsc::HseOsc || Clk == RccOsc::LseOsc);

template <RccOsc Clk>
static constexpr bool is_pll_clk_src = (Clk == RccOsc::HseOsc || Clk == RccOsc::HsiOsc);

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
	[[nodiscard]] static constexpr auto const& getExtBypassReg() noexcept {
		static_assert(is_ext_clk<Clk>);
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
	detail::rcc_enable_periph_clk_impl<RccRegTable, RccPeriph, PeriphClk>();
}

template <RccPeriph PeriphClk>
static constexpr void rcc_reset_periph_clk() noexcept {
	detail::rcc_reset_periph_clk_impl<RccRegTable, RccPeriph, PeriphClk>();
}

template <RccOsc Clk>
static constexpr void rcc_enable_clk() noexcept {
	detail::rcc_enable_clk_impl<RccRegTable, RccOsc, Clk>();
}

template <RccOsc Clk>
static constexpr void rcc_disable_clk() noexcept {
	detail::rcc_disable_clk_impl<RccRegTable, RccOsc, Clk>();
}

template <RccOsc Clk>
static constexpr bool rcc_is_osc_rdy() noexcept {
	return detail::rcc_is_osc_rdy_impl<RccRegTable, RccOsc, Clk>();
}

template <RccOsc Clk>
static constexpr void rcc_wait_osc_rdy() noexcept {
	while (!rcc_is_osc_rdy<Clk>()) {
	}
}

template <RccOsc Clk>
static constexpr void rcc_bypass_clksrc() noexcept {
	detail::rcc_bypass_clksrc_impl<RccRegTable, RccOsc, Clk>();
}

template <RccOsc Clk>
static constexpr void rcc_no_bypass() noexcept {
	detail::rcc_no_bypass_impl<RccRegTable, RccOsc, Clk>();
}

template <SysClk Clk>
static constexpr void rcc_set_sysclk() noexcept {
	RCC_CFGR.template setBit<RccCfgBit::SW>(Clk);
}

static constexpr SysClk rcc_sysclk_in_use() noexcept {
	return get<0>(RCC_CFGR.readBit<RccCfgBit::SWS>(ValueOnly));	//
}

template <SysClk Clk>
static constexpr void rcc_wait_sysclk_rdy() noexcept {
	while (rcc_sysclk_in_use() != Clk) {
	}
}

template <RccOsc Clk>
static constexpr void rcc_set_pllsrc() {
	static_assert(is_pll_clk_src<Clk>);
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
static constexpr void rcc_set_pllsrc_and_div_factor(PllM const& t_pllm, PllN const& t_plln, PllP const& t_pllp,
																										PllQ const& t_pllq, PllR const& t_pllr) noexcept {
	static_assert(is_pll_clk_src<Clk>);
	auto const val_to_set = BitGroup{Clk, t_pllm, t_plln, t_pllp, t_pllq, t_pllr};
	RCC_PLLCFGR.setBit<RccPllCfgBit::PLLSRC, RccPllCfgBit::PLLM, RccPllCfgBit::PLLN, RccPllCfgBit::PLLP,
										 RccPllCfgBit::PLLQ, RccPllCfgBit::PLLR>(val_to_set);
}

static constexpr void rcc_config_adv_bus_division_factor(HPRE const& t_hpre, PPRE const& t_ppre1, PPRE const& t_ppre2) {
	auto const val_to_set = BitGroup{t_hpre, t_ppre1, t_ppre2};
	RCC_CFGR.setBit<RccCfgBit::HPRE, RccCfgBit::PPRE1, RccCfgBit::PPRE2>(val_to_set);
}

}	// namespace cpp_stm32::stm32::f4
