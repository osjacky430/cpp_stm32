/**
 * @Date:   2019-12-10T21:40:38+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: rcc_reg.hpp
 */

#pragma once

#include <array>
#include <utility>

#include "include/hal/bit/bit.hxx"
#include "include/hal/memory_map.hxx"
#include "include/hal/peripheral/memory/utility.hxx"
#include "include/hal/register/register.hpp"
#include "include/utility/constexpr_algo.hxx"

static constexpr auto RCC_BASE = memory_at(to_underlying(MemoryMap::Ahb1Base), 0x3800U);

template <std::uint32_t Val>
using DivisionFactor_t = std::integral_constant<std::uint32_t, Val>;

template <std::uint32_t Val>
static constexpr auto DivisionFactor_v = DivisionFactor_t<Val>{};

enum class RccOsc : std::uint32_t;

/**
 * @defgroup	RCC_CR_GROUP
 *
 * @{
 */

SETUP_REGISTER_INFO(RccCrBitInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(16)}, Bit<1>{BitPos_t(17)},
										Bit<1>{BitPos_t(18)}, Bit<1>{BitPos_t(19)}, Bit<1>{BitPos_t(24)}, Bit<1>{BitPos_t(25)},
										Bit<1>{BitPos_t(26)}, Bit<1>{BitPos_t(27)}, Bit<1>{BitPos_t(28)}, Bit<1>{BitPos_t(29)})

enum class RccCrBit {
	HsiOn,
	HsiRdy,
	HseOn,
	HseRdy,
	HseByp,
	CssOn,
	PllOn,
	PllRdy,
	PllSaiOn,
	PllSaiRdy,
};

static constexpr Register<RccCrBitInfo, RccCrBit> RCC_CR{RCC_BASE, 0};

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
	constexpr PllM(DivisionFactor_t<Val> const&) noexcept : m_pllmDivisionFactor(Val) {
		static_assert(2 <= Val && Val <= 63);
	}

	constexpr auto get() const noexcept { return m_pllmDivisionFactor; }
};

struct PllN {
 private:
	std::uint32_t const m_pllnDivisionFactor;

 public:
	template <std::uint32_t Val>
	constexpr PllN(DivisionFactor_t<Val> const&) noexcept : m_pllnDivisionFactor(Val) {
		static_assert(50 <= Val && Val <= 432);
	}

	constexpr auto get() const noexcept { return m_pllnDivisionFactor; }
};

struct PllP {
 private:
	std::uint32_t const m_pllpDivisionFactor;

 public:
	static constexpr std::array AVAIL_PLLP_DIV_FACTOR{2, 4, 6, 8};

	template <std::uint32_t Val>
	constexpr PllP(DivisionFactor_t<Val> const&) noexcept : m_pllpDivisionFactor(Val) {
		static_assert(2 <= Val && Val <= 8 && Val % 2 == 0);
	}

	constexpr auto get() const noexcept { return m_pllpDivisionFactor; }
};

struct PllQ {
 private:
	std::uint32_t const m_pllqDivisionFactor;

 public:
	template <std::uint32_t Val>
	constexpr PllQ(DivisionFactor_t<Val> const&) noexcept : m_pllqDivisionFactor(Val) {
		static_assert(2 <= Val && Val <= 15);
	}

	constexpr auto get() const noexcept { return m_pllqDivisionFactor; }
};

struct PllR {
 private:
	std::uint32_t const m_pllrDivisionFactor;

 public:
	template <std::uint32_t Val>
	constexpr PllR(DivisionFactor_t<Val> const&) noexcept : m_pllrDivisionFactor(Val) {
		static_assert(2 <= Val && Val <= 7);
	}

	constexpr auto get() const noexcept { return m_pllrDivisionFactor; }
};

SETUP_REGISTER_INFO(RccPllcfgrBitInfo, /**/
										Bit<6, PllM>{BitPos_t{0}}, Bit<9, PllN>{BitPos_t{6}}, Bit<2, PllP>{BitPos_t{16}},
										Bit<1, RccOsc>{BitPos_t{22}}, Bit<4, PllQ>{BitPos_t{24}}, Bit<3, PllR>{BitPos_t{28}})

enum class RccPllCfgBit { PLLM, PLLN, PLLP, PLLSRC, PLLQ, PLLR };

static constexpr Register<RccPllcfgrBitInfo, RccPllCfgBit> RCC_PLLCFGR{RCC_BASE, 0x04U};
/** @}*/

/**
 * @defgroup	RCC_CFG_GROUP
 *
 * @{
 */

enum class SysClk : std::uint32_t;

struct HPRE {
 private:
	std::uint32_t const m_hpreDivisionFactor;

 public:
	static constexpr std::array AVAIL_DIVISION_FACTOR{
		std::pair{1, 0b0000},	 std::pair{2, 0b1000},	 std::pair{4, 0b1001},	 std::pair{8, 0b1010},	std::pair{16, 0b1011},
		std::pair{64, 0b1100}, std::pair{128, 0b1101}, std::pair{256, 0b1110}, std::pair{512, 0b1111}};

 public:
	template <std::uint32_t Val>
	constexpr HPRE(DivisionFactor_t<Val> const&) noexcept
		: m_hpreDivisionFactor([]() {
				constexpr auto iter_pos = constexpr_std_find_if(AVAIL_DIVISION_FACTOR.begin(), AVAIL_DIVISION_FACTOR.end(),
																												[](auto const& t_pair) { return t_pair.first == Val; });
				static_assert(iter_pos != AVAIL_DIVISION_FACTOR.end());
				return AVAIL_DIVISION_FACTOR[iter_pos - AVAIL_DIVISION_FACTOR.begin()].second;
			}()) {}

	constexpr auto get() const noexcept { return m_hpreDivisionFactor; }
};

struct PPRE {
 private:
	std::uint32_t const m_ppreDivisionFactor;

 public:
	static constexpr std::array AVAIL_DIVISION_FACTOR{
		std::pair{1, 0b000}, std::pair{2, 0b100}, std::pair{4, 0b101}, std::pair{8, 0b110}, std::pair{16, 0b111},
	};

 public:
	template <std::uint32_t Val>
	constexpr PPRE(DivisionFactor_t<Val> const&) noexcept
		: m_ppreDivisionFactor([]() {
				constexpr auto iter_pos = constexpr_std_find_if(AVAIL_DIVISION_FACTOR.begin(), AVAIL_DIVISION_FACTOR.end(),
																												[](auto const& t_pair) { return t_pair.first == Val; });
				static_assert(iter_pos != AVAIL_DIVISION_FACTOR.end());
				return AVAIL_DIVISION_FACTOR[iter_pos - AVAIL_DIVISION_FACTOR.begin()].second;
			}()) {}

	constexpr auto get() const noexcept { return m_ppreDivisionFactor; }
};

SETUP_REGISTER_INFO(RccCfgBitInfo, /**/
										Bit<2, SysClk>{BitPos_t(0)}, Bit<2, SysClk>{BitPos_t(2)}, Bit<4, HPRE>{BitPos_t(4)},
										Bit<3, PPRE>{BitPos_t(10)}, Bit<3, PPRE>{BitPos_t(13)})

enum class RccCfgBit {
	SW,
	SWS,
	HPRE,
	PPRE1,
	PPRE2,
};

static constexpr Register<RccCfgBitInfo, RccCfgBit> RCC_CFGR{RCC_BASE, 0x08U};
/**@} */

/**
 * @defgroup	RCC_AHB1RST_GROUP
 * @{
 */

SETUP_REGISTER_INFO(RccAhb1RstInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(3)},
										Bit<1>{BitPos_t(4)}, Bit<1>{BitPos_t(5)}, Bit<1>{BitPos_t(6)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(12)}, Bit<1>{BitPos_t(18)}, Bit<1>{BitPos_t(21)}, Bit<1>{BitPos_t(22)},
										Bit<1>{BitPos_t(29)}, Bit<1>{BitPos_t(30)})

enum class RccAhb1RstBit {
	GpioARst,
	GpioBRst,
	GpioCRst,
	GpioDRst,
	GpioERst,
	GpioFRst,
	GpioGRst,
	GpioHRst,
	CrcRst,
	BkpSRAMRst,
	Dma1Rst,
	Dma2Rst,
	OtgHsRst
};

static constexpr Register<RccAhb1RstInfo, RccAhb1RstBit> RCC_AHB1RST{RCC_BASE, 0x10U};
/**@}*/

/**
 * @defgroup	RCC_AHB1ENR_GROUP
 * @{
 */

SETUP_REGISTER_INFO(RccAhb1EnrInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(3)},
										Bit<1>{BitPos_t(4)}, Bit<1>{BitPos_t(5)}, Bit<1>{BitPos_t(6)}, Bit<1>{BitPos_t(7)},
										Bit<1>{BitPos_t(12)}, Bit<1>{BitPos_t(18)}, Bit<1>{BitPos_t(21)}, Bit<1>{BitPos_t(22)},
										Bit<1>{BitPos_t(29)}, Bit<1>{BitPos_t(30)})

enum class RccAhb1EnrBit {
	GpioAEn,
	GpioBEn,
	GpioCEn,
	GpioDEn,
	GpioEEn,
	GpioFEn,
	GpioGEn,
	GpioHEn,
	CrcEn,
	BkpSRAMEn,
	Dma1En,
	Dma2En,
	OtgHsEn,
	OtgHsULPIEn
};

static constexpr Register<RccAhb1EnrInfo, RccAhb1EnrBit> RCC_AHB1ENR{RCC_BASE, 0x30U};

/**@}*/

/**
 * @defgroup	RCC_BDCR_GROUP
 *
 * @{
 */

SETUP_REGISTER_INFO(RccBdcrBitInfo, /**/
										Bit<1>{BitPos_t(0)}, Bit<1>{BitPos_t(1)}, Bit<1>{BitPos_t(2)}, Bit<1>{BitPos_t(3)})

enum class RccBdcrBit {
	LSEON,
	LSERDY,
	LseByp,
	LSEMOD,
};

static constexpr Register<RccBdcrBitInfo, RccBdcrBit> RCC_BDCR{RCC_BASE, 0x70U};

/**@}*/
