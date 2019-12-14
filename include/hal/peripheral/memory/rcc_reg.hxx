/**
 * @Date:   2019-12-10T21:40:38+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: rcc_reg.hpp
 * @Last modified time: 2019-12-14T01:04:11+08:00
 */

#pragma once

#include "include/hal/bit/bit.hxx"
#include "include/hal/memory_map.hxx"
#include "include/hal/register/register.hpp"

static constexpr auto RCC_BASE = memory_at(to_underlying(MemoryMap::Ahb1Base), 0x3800U);

template <std::uint32_t Val>
using DivisionFactor_t = std::integral_constant<std::uint32_t, Val>;

template <std::uint32_t Val>
static constexpr auto DivisionFactor_v = DivisionFactor_t<Val>{};

/**
 * @defgroup	RCC_CR_GROUP
 *
 * @{
 */

class RccCrBitList {
	template <typename BitList, std::size_t Idx>
	friend constexpr auto get_bit() noexcept;

 private:
	static constexpr std::tuple BIT_LIST{
		Bit<1>{BitPos_t(0)},	// HsiOn
		Bit<1>{BitPos_t(1)},	// HsiRdy
	};
};

enum class RccCrReg {
	HsiOn,
	HsiRdy,
	HseOn,
	HseRdy,
	HseBypass,
	CssOn,
	PllOn,
	PllRdy,
	PllSaiOn,
	PllSaiRdy,
};

static constexpr Register<RccCrBitList, RccCrReg> RCC_CR{RCC_BASE, 0};

/** @}*/

/**
 * @defgroup	RCC_PLLCFGR_GROUP
 *
 * @{
 */

class RccPllcfgrBitList {
	template <typename BitList, std::size_t Idx>
	friend constexpr auto get_bit() noexcept;

 private:
	static constexpr std::tuple BIT_LIST{
		Bit<6>{BitPos_t(0)},
	};
};

enum class RccPllCfgBit {
	PLLM,
	PLLN,
};

struct PllM {
 private:
	std::uint32_t const m_plllmDivisionFactor;

 public:
	template <std::uint32_t Val>
	constexpr PllM(DivisionFactor_t<Val> const&) : m_plllmDivisionFactor(Val) {
		static_assert(2 <= Val && Val <= 63);
	}

	constexpr auto get() const noexcept { return m_plllmDivisionFactor; };
};

static constexpr Register<RccPllcfgrBitList, RccPllCfgBit, PllM> RCC_PLLCFGR{RCC_BASE, 0x04U};

/** @}0*/

enum class RccCfgBit {
	SW,
	SWS,
	HPRE,
	PPRE1,
	PPRE2,
};
