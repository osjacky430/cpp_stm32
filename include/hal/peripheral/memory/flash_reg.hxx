/**
 * @Date:   2019-12-23T04:27:43+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: flash_reg.hxx
 */

#pragma once

#include <cstdint>

#include "include/hal/bit/bit.hxx"
#include "include/hal/memory_map.hxx"
#include "include/hal/peripheral/memory/utility.hxx"
#include "include/hal/register/register.hxx"

static constexpr auto FLASH_BASE = memory_at(MemoryMap::Ahb1Base, 0x3C00U);

template <std::uint8_t Val>
using CpuWaitState_t = std::integral_constant<std::uint8_t, Val>;

template <std::uint8_t Val>
static constexpr auto CpuWaitState_v = CpuWaitState_t<Val>{};

/**
 * @defgroup FLASH_ACR_GROUP
 * @{
 */

struct FlashLatency {
 private:
	std::uint8_t const m_flashLatency;

 public:
	template <std::uint8_t Val>
	constexpr FlashLatency(CpuWaitState_t<Val> const&) noexcept : m_flashLatency(Val) {
		static_assert(0 <= Val && Val <= 15);
	}

	constexpr auto get() const noexcept { return m_flashLatency; }
};

SETUP_REGISTER_INFO(FlashAcrInfo, /**/
										Bit<4, FlashLatency>{BitPos_t{0}}, BinaryBit<>{BitPos_t{8}}, BinaryBit<>{BitPos_t{9}},
										BinaryBit<>{BitPos_t{10}}, BinaryBit<>{BitPos_t{11}}, BinaryBit<>{BitPos_t{12}})

enum class FlashAcrBit {
	Latency,
	PrftEn,
	ICEn,
	DCEn,
	ICRst,
	DCRst,
};

static constexpr Register<FlashAcrInfo, FlashAcrBit> FLASH_ACR{FLASH_BASE, 0x00U};

/**@}*/
