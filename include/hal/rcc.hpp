/**
 * @Date:   2019-11-25T00:54:46+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: rcc.hpp
 * @Last modified time: 2019-11-26T21:15:56+08:00
 */

#ifndef RCC_HPP_
#define RCC_HPP_

#include <array>
#include <utility>

#include "memory_map.hpp"
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
		setOffsetAndBit(0x10, 0),	// GPIOA
	};

	static constexpr std::array RccPeriphEn{
		setOffsetAndBit(0x30, 0),	// GPIOA
		setOffsetAndBit(0x30, 1),	// GPIOB
	};

 public:
	static constexpr auto getEnableReg(const RccPeriph t_periph_clk) noexcept {
		return getOffsetAndBit(RccPeriphEn[to_underlying(t_periph_clk)]);
	}

	static constexpr auto getResetReg(const RccPeriph t_periph_clk) noexcept {
		return getOffsetAndBit(RccPeriphRst[to_underlying(t_periph_clk)]);
	}
};

static constexpr auto RCC_BASE = memory_at(to_underlying(MemoryMap::Ahb1Base), 0x3800U);
static constexpr auto RCC_CR = []() noexcept -> decltype(auto) { return MMIO32(RCC_BASE, 0x00U); };
static constexpr auto RCC_EN_PERIPH_CLK = [](const auto t_periph_clk) noexcept {
	const auto& [RCC_ENR_OFFSET, ENR_BIT_POS] = RccPeriphClk::getEnableReg(t_periph_clk);
	MMIO32(RCC_BASE, RCC_ENR_OFFSET) |= ENR_BIT_POS;
};
static constexpr auto RCC_RST_PERIPH_CLK = [](const auto t_periph_clk) noexcept {
	static_assert(std::is_same_v<decltype(t_periph_clk), const RccPeriph>);
	const auto& [RCC_RSTR_OFFSET, RSTR_BIT_POS] = RccPeriphClk::getResetReg(t_periph_clk);
	MMIO32(RCC_BASE, RCC_RSTR_OFFSET) |= RSTR_BIT_POS;
};
static constexpr auto RCC_PLLCFGR = []() noexcept -> decltype(auto) { return MMIO32(RCC_BASE, 0x04U); };

enum class RccOsc {
	HsiOsc,
	HseOsc,
	PllOsc,
	PllSaiOsc,
};

class RccOscReg {
 private:
	static constexpr std::array RccOscOn{
		std::pair{RCC_CR, 0},		// HSI
		std::pair{RCC_CR, 16},	// HSE
		std::pair{RCC_CR, 24},	// PLL
		std::pair{RCC_CR, 26},	// PLLSAI
	};

	static constexpr std::array RccOscRdy{
		std::pair{RCC_CR, 1},		// HSI
		std::pair{RCC_CR, 17},	// HSE
		std::pair{RCC_CR, 25},	// PLL
		std::pair{RCC_CR, 27},	// PLLSAI
	};

 public:
	static constexpr auto getOscOnReg(const RccOsc t_rcc_osc) noexcept { return RccOscOn[to_underlying(t_rcc_osc)]; }

	static constexpr auto getOscRdyReg(const RccOsc t_rcc_osc) noexcept { return RccOscRdy[to_underlying(t_rcc_osc)]; }
};

static inline void rcc_enable_clk(const RccOsc t_rcc_osc) noexcept {
	const auto& [CTL_REG, enable_bit_shift] = RccOscReg::getOscOnReg(t_rcc_osc);
	CTL_REG() |= (1U << enable_bit_shift);
}

static inline bool rcc_is_osc_rdy(const RccOsc t_rcc_osc) noexcept {
	const auto& [CTL_REG, rdy_bit_shift] = RccOscReg::getOscRdyReg(t_rcc_osc);
	return (CTL_REG() & (1U << rdy_bit_shift));
}

#endif	// RCC_HPP_
