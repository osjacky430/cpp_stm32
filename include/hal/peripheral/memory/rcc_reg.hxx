/**
 * @Date:   2019-12-10T21:40:38+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: rcc_reg.hpp
 * @Last modified time: 2019-12-15T14:56:14+08:00
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
		Bit<1>{BitPos_t(0)},	 // HsiOn
		Bit<1>{BitPos_t(1)},	 // HsiRdy
		Bit<1>{BitPos_t(16)},	 // HseOn
		Bit<1>{BitPos_t(17)},	 // HseRdy
		Bit<1>{BitPos_t(18)},	 // HseBypass
	};
};

enum class RccCrBit {
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

static constexpr Register<RccCrBitList, RccCrBit> RCC_CR{RCC_BASE, 0};

/** @}*/

/**
 * @defgroup	RCC_PLLCFGR_GROUP
 *
 * @{
 */

struct PllM {
 private:
	std::uint32_t const m_pllmDivisionFactor;

 public:
	template <std::uint32_t Val>
	constexpr PllM(DivisionFactor_t<Val> const&) : m_pllmDivisionFactor(Val) {
		static_assert(2 <= Val && Val <= 63);
	}

	constexpr auto get() const noexcept { return m_pllmDivisionFactor; };
};

struct PllN {
 private:
	std::uint32_t const m_pllnDivisionFactor;

 public:
	template <std::uint32_t Val>
	constexpr PllN(DivisionFactor_t<Val> const&) : m_pllnDivisionFactor(Val) {
		static_assert(50 <= Val && Val <= 432);
	}

	constexpr auto get() const noexcept { return m_pllnDivisionFactor; };
};

class RccPllcfgrBitList {
	template <typename BitList, std::size_t Idx>
	friend constexpr auto get_bit() noexcept;

 private:
	static constexpr std::tuple BIT_LIST{
		Bit<6, PllM>{BitPos_t{0}},
		Bit<9, PllN>{BitPos_t{6}},
	};
};

enum class RccPllCfgBit {
	PLLM,
	PLLN,
};

static constexpr Register<RccPllcfgrBitList, RccPllCfgBit> RCC_PLLCFGR{RCC_BASE, 0x04U};

/** @}0*/

enum class SysClk : std::uint32_t;

enum class RccCfgBit {
	SW,
	SWS,
	HPRE,
	PPRE1,
	PPRE2,
};

class RccCfgBitList {
	template <typename BitList, std::size_t Idx>
	friend constexpr auto get_bit() noexcept;

 private:
	static constexpr std::tuple BIT_LIST{
		Bit<2, SysClk>{BitPos_t(0)},	// SW
		Bit<2, SysClk>{BitPos_t(2)},	// SWS
	};
};

static constexpr Register<RccCfgBitList, RccCfgBit> RCC_CFGR{RCC_BASE, 0x08U};
