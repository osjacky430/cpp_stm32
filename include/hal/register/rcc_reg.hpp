/**
 * @Date:   2019-12-10T21:40:38+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: rcc_reg.hpp
 * @Last modified time: 2019-12-12T00:15:40+08:00
 */

#include "include/hal/register/bit.hxx"
#include "include/hal/register/memory_map.hpp"
#include "include/hal/register/register.hpp"
#include "include/hal/register/utility.hpp"

enum class RccClkRegBit {
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

enum class RccPllCfgBit {
	PLLM,
	PLLN,
};

enum class RccCfgBit {
	SW,
	SWS,
	HPRE,
	PPRE1,
	PPRE2,
};

class RCC_CR_BIT_LIST {
 private:
	static constexpr std::array BIT_LIST{
		Bit{0, 1},	// HsiOn
		Bit{1, 1},	// HsiRdy
	};
};

static constexpr auto RCC_BASE = memory_at(to_underlying(MemoryMap::Ahb1Base), 0x3800U);
static constexpr Register<RccClkRegBit> RCC_CR{RCC_BASE, 0};
static constexpr Register<RccPllCfgBit> RCC_PLLCFGR{RCC_BASE, 0x04U};
