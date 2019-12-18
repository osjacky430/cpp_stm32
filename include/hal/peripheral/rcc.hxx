/**
 * @Date:   2019-11-25T00:54:46+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: rcc.hpp
 * @Last modified time: 2019-12-18T20:08:28+08:00
 */

#pragma once

#include <array>
#include <tuple>
#include <utility>

#include "include/hal/memory_map.hxx"
#include "include/hal/peripheral/memory/rcc_reg.hxx"

enum class RccPeriph : std::uint32_t {
	GPIOA,
};

enum class RccOsc : std::uint32_t {
	HsiOsc,
	HseOsc,
	PllOsc,
	PllSaiOsc,

	LseOsc,
};

enum class SysClk : std::uint32_t { Hse, Hsi, Pllp, Pllr };

template <RccOsc Clk>
struct ExtClk {
	static_assert(Clk == RccOsc::HseOsc || Clk == RccOsc::LseOsc);
};

template <RccOsc Clk>
struct PllClkSrc {
	static_assert(Clk == RccOsc::HseOsc || Clk == RccOsc::HsiOsc);
};

class RccAuxiliaryReg {
 private:
	static constexpr auto setOffsetAndBit = [](const std::uint32_t t_offset, const std::uint32_t t_bit) noexcept {
		return (t_offset << 5U) + t_bit;
	};

	static constexpr auto getOffsetAndBit = [](const std::uint32_t t_rcc_periph) noexcept {
		return std::array<std::uint32_t, 2>{t_rcc_periph >> 5U, 1U << (t_rcc_periph & 0x1FU)};
	};

	static constexpr std::array RccPeriphRst{
		setOffsetAndBit(0x10, 0),	 // GPIOA
	};

	static constexpr std::tuple RccPeriphEn{
		std::pair{RCC_AHB1ENR, RccAhb1EnrBit::GpioAEn},
		std::pair{RCC_AHB1ENR, RccAhb1EnrBit::GpioBEn},
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
	static constexpr auto getEnableReg() noexcept {
		return std::get<to_underlying(PeriphClk)>(RccPeriphEn);
	}

	static constexpr auto getResetReg(const RccPeriph t_periph_clk) noexcept {
		return getOffsetAndBit(RccPeriphRst[to_underlying(t_periph_clk)]);
	}

	template <RccOsc Clk>
	static constexpr auto const getOscOnReg() noexcept {
		return std::get<to_underlying(Clk)>(RccOscOn);
	}

	template <RccOsc Clk>
	static constexpr auto const getOscRdyReg() noexcept {
		return std::get<to_underlying(Clk)>(RccOscRdy);
	}

	template <RccOsc Clk>
	static constexpr auto const& getExtBypassReg(ExtClk<Clk> const) noexcept {
		if constexpr (Clk == RccOsc::HseOsc) {
			return std::get<0>(ExtBypass);
		} else if constexpr (Clk == RccOsc::LseOsc) {
			return std::get<1>(ExtBypass);
		}
	}
};

static constexpr auto RCC_RST_PERIPH_CLK = [](const auto t_periph_clk) noexcept {
	const auto [RCC_RSTR_OFFSET, RSTR_BIT_POS] = RccAuxiliaryReg::getResetReg(t_periph_clk);
	MMIO32(RCC_BASE, RCC_RSTR_OFFSET) |= RSTR_BIT_POS;
};

template <RccPeriph PeriphClk>
static constexpr void rcc_enable_periph_clk() noexcept {
	constexpr auto const reg_bit_pair = RccAuxiliaryReg::getEnableReg<PeriphClk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <RccOsc Clk>
static constexpr void rcc_enable_clk() noexcept {
	constexpr auto const reg_bit_pair = RccAuxiliaryReg::getOscOnReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <RccOsc Clk>
static constexpr void rcc_disable_clk() noexcept {
	constexpr auto const reg_bit_pair = RccAuxiliaryReg::getOscOnReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<enable_bit>();
}

template <RccOsc Clk>
static constexpr bool rcc_is_osc_rdy() noexcept {
	constexpr auto const reg_bit_pair = RccAuxiliaryReg::getOscRdyReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const rdy_bit			= std::get<1>(reg_bit_pair);

	return CTL_REG.template readBit<rdy_bit>();
}

template <RccOsc Clk>
static constexpr void rcc_wait_osc_rdy() noexcept {
	while (!rcc_is_osc_rdy<Clk>()) {
	}
}

template <RccOsc Clk>
static constexpr void rcc_bypass_clksrc() noexcept {
	constexpr auto const reg_bit_pair = RccAuxiliaryReg::getExtBypassReg(ExtClk<Clk>{});
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<bypass_bit>();
}

template <RccOsc Clk>
static constexpr void rcc_no_bypass() noexcept {
	constexpr auto const reg_bit_pair = RccAuxiliaryReg::getExtBypassReg(ExtClk<Clk>{});
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<bypass_bit>();
}

template <SysClk Clk>
static constexpr void rcc_set_sysclk() noexcept {
	RCC_CFGR.template setBit<RccCfgBit::SW>(Clk);
}

static constexpr SysClk rcc_sysclk_in_use() noexcept {
	return RCC_CFGR.readBit<RccCfgBit::SWS>();	//
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
	RCC_PLLCFGR.setBit<RccPllCfgBit::PLLM>(t_pllm);
	RCC_PLLCFGR.setBit<RccPllCfgBit::PLLN>(t_plln);
	RCC_PLLCFGR.setBit<RccPllCfgBit::PLLP>(t_pllp);
	RCC_PLLCFGR.setBit<RccPllCfgBit::PLLQ>(t_pllq);
	RCC_PLLCFGR.setBit<RccPllCfgBit::PLLR>(t_pllr);
}

static constexpr void rcc_config_adv_bus_division_factor(HPRE const& t_hpre, PPRE const& t_ppre1, PPRE const& t_ppre2) {
	RCC_CFGR.setBit<RccCfgBit::HPRE>(t_hpre);
	RCC_CFGR.setBit<RccCfgBit::PPRE1>(t_ppre1);
	RCC_CFGR.setBit<RccCfgBit::PPRE2>(t_ppre2);
}
