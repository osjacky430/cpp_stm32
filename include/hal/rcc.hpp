/**
 * @Date:   2019-11-25T00:54:46+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: rcc.hpp
 * @Last modified time: 2019-11-26T21:15:56+08:00
 */

#ifndef RCC_HPP_
#define RCC_HPP_

#include <array>

#include "memory_map.hpp"
#include "sys_info.hpp"

constexpr auto set_offset_and_bit(const std::uint32_t t_offset, const std::uint32_t t_bit) noexcept {
	return t_offset << 5U + t_bit;
}

constexpr auto get_offset_and_bit(const std::uint32_t t_rcc_periph) noexcept -> std::array<std::uint32_t, 2> {
	return {t_rcc_periph >> 5U, 1U << (t_rcc_periph & 0x1FU)};
}

enum class RccPeriph : std::uint32_t {
	GPIOA,
};

class RccPeriphClk {
 private:
	static constexpr std::array RccPeriphRst{
		set_offset_and_bit(0x10, 0),	// GPIOA
	};

	static constexpr std::array RccPeriphEn{
		set_offset_and_bit(0x30, 0),	// GPIOA
		set_offset_and_bit(0x30, 1),	// GPIOB
	};

 public:
	static constexpr auto getEnableReg(const RccPeriph t_periph_clk) noexcept {
		return RccPeriphEn[to_underlying(t_periph_clk)];
	}

	static constexpr auto getResetReg(const RccPeriph t_periph_clk) noexcept {
		return RccPeriphRst[to_underlying(t_periph_clk)];
	}
};

static constexpr auto RCC_BASE = memory_at(to_underlying(MemoryMap::Ahb1Base), 0x3800U);
static constexpr auto RCC_CR = []() noexcept -> decltype(auto) { return MMIO32(RCC_BASE, 0x00U); };
static constexpr auto RCC_EN_PERIPH_CLK = [](const auto t_periph_clk) noexcept {
	const auto& [RCC_ENR_OFFSET, ENR_BIT_POS] = get_offset_and_bit(RccPeriphClk::getEnableReg(t_periph_clk));
	MMIO32(RCC_BASE, RCC_ENR_OFFSET) |= ENR_BIT_POS;
};
static constexpr auto RCC_RST_PERIPH_CLK = [](const auto t_periph_clk) noexcept {
	static_assert(std::is_same_v<decltype(t_periph_clk), const RccPeriph>);
	const auto& [RCC_RSTR_OFFSET, RSTR_BIT_POS] = get_offset_and_bit(RccPeriphClk::getResetReg(t_periph_clk));
	MMIO32(RCC_BASE, RCC_RSTR_OFFSET) |= RSTR_BIT_POS;
};
static constexpr auto RCC_PLLCFGR = []() noexcept -> decltype(auto) { return MMIO32(RCC_BASE, 0x04U); };

class RccSysClkReg {
	static constexpr std::array RccOscOn{1};
};

#endif	// RCC_HPP_