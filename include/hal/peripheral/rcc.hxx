/**
 * @Date:   2019-11-25T00:54:46+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: rcc.hpp
 * @Last modified time: 2019-12-15T15:10:12+08:00
 */

#pragma once

#include <array>
#include <tuple>
#include <utility>

#include "include/hal/memory_map.hxx"
#include "include/hal/peripheral/memory/rcc_reg.hxx"

#include "sys_info.hpp"

enum class RccPeriph : std::uint32_t {
	GPIOA,
};

class RccPeriphClk {
 private:
	static constexpr auto setOffsetAndBit = [](const std::uint32_t t_offset, const std::uint32_t t_bit) noexcept {
		return t_offset << 5U + t_bit;
	};

	static constexpr auto getOffsetAndBit = [](const std::uint32_t t_rcc_periph) noexcept {
		return std::array<std::uint32_t, 2>{t_rcc_periph >> 5U, 1U << (t_rcc_periph & 0x1FU)};
	};

	static constexpr std::array RccPeriphRst{
		setOffsetAndBit(0x10, 0),	 // GPIOA
	};

	static constexpr std::array RccPeriphEn{
		setOffsetAndBit(0x30, 0),	 // GPIOA
		setOffsetAndBit(0x30, 1),	 // GPIOB
	};

 public:
	static constexpr auto getEnableReg(const RccPeriph t_periph_clk) noexcept {
		return getOffsetAndBit(RccPeriphEn[to_underlying(t_periph_clk)]);
	}

	static constexpr auto getResetReg(const RccPeriph t_periph_clk) noexcept {
		return getOffsetAndBit(RccPeriphRst[to_underlying(t_periph_clk)]);
	}
};

static constexpr auto RCC_EN_PERIPH_CLK = [](const auto t_periph_clk) noexcept {
	const auto& [RCC_ENR_OFFSET, ENR_BIT_POS] = RccPeriphClk::getEnableReg(t_periph_clk);
	MMIO32(RCC_BASE, RCC_ENR_OFFSET) |= ENR_BIT_POS;
};
static constexpr auto RCC_RST_PERIPH_CLK = [](const auto t_periph_clk) noexcept {
	const auto& [RCC_RSTR_OFFSET, RSTR_BIT_POS] = RccPeriphClk::getResetReg(t_periph_clk);
	MMIO32(RCC_BASE, RCC_RSTR_OFFSET) |= RSTR_BIT_POS;
};

static constexpr auto RCC_BDCR = []() noexcept -> decltype(auto) { return MMIO32(RCC_BASE, 0x70U); };

enum class RccOsc {
	HsiOsc,
	HseOsc,
	PllOsc,
	PllSaiOsc,

	LseOsc,
};

enum class SysClk : std::uint32_t { Hse, Hsi, Pllp, Pllr };

template <RccOsc Clk>
struct ExtClk {
	// something like integral constant, used for static assertion
	static_assert(Clk == RccOsc::HseOsc || Clk == RccOsc::LseOsc);
};

class RccOscReg {
 private:
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
		std::pair{RCC_CR, RccCrBit::HseBypass},
		std::pair{RCC_BDCR, 2},
	};

 public:
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

template <RccOsc Clk>
static constexpr void rcc_enable_clk() noexcept {
	constexpr auto const reg_bit_pair = RccOscReg::getOscOnReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const enable_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<enable_bit>();
}

template <RccOsc Clk>
static constexpr bool rcc_is_osc_rdy() noexcept {
	constexpr auto const reg_bit_pair = RccOscReg::getOscRdyReg<Clk>();
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const rdy_bit			= std::get<1>(reg_bit_pair);

	return CTL_REG.template readBit<rdy_bit>();
}

template <RccOsc Clk>
static constexpr void rcc_bypass_clksrc() noexcept {
	constexpr auto const reg_bit_pair = RccOscReg::getExtBypassReg(ExtClk<Clk>{});
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template setBit<bypass_bit>();
}

template <RccOsc Clk>
static constexpr void rcc_no_bypass() noexcept {
	constexpr auto const reg_bit_pair = RccOscReg::getExtBypassReg(ExtClk<Clk>{});
	constexpr auto const CTL_REG			= std::get<0>(reg_bit_pair);
	constexpr auto const bypass_bit		= std::get<1>(reg_bit_pair);
	CTL_REG.template clearBit<bypass_bit>();
}

template <SysClk Clk>
static constexpr void rcc_set_sysclk() noexcept {
	RCC_CFGR.template setBit<RccCfgBit::SW>(Clk);
}

static constexpr SysClk rcc_sysclk_in_use() noexcept {
	return RCC_CFGR.template readBit<RccCfgBit::SWS>();	 //
}
