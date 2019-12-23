/**
 * @Date:   2019-12-23T05:12:13+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: flash.hxx
 */

#pragma once

#include <array>
#include <tuple>

#include "include/hal/peripheral/memory/flash_reg.hxx"
#include "include/utility/strongly_typed.hxx"

struct FlashWaitTable {
 private:
	template <float const& Vdd>
	static constexpr auto GET_IDX_FROM_VDD = []() -> std::size_t {
		if (2.7f <= Vdd && Vdd <= 3.6f) {
			return 0;
		} else if (2.4f <= Vdd && Vdd < 2.7f) {
			return 1;
		} else if (2.1f <= Vdd && Vdd < 2.4f) {
			return 2;
		} else if (1.8f <= Vdd && Vdd < 2.1f) {
			return 3;
		}
	};

	static constexpr std::tuple WAIT_STATE_TABLE{
		[](std::uint64_t const& t_hclk) {
			if (150_MHz <= t_hclk && t_hclk <= 180_MHz) {
				return 5;
			} else if (120_MHz <= t_hclk && t_hclk < 150_MHz) {
				return 4;
			} else if (90_MHz <= t_hclk && t_hclk < 120_MHz) {
				return 3;
			} else if (60_MHz <= t_hclk && t_hclk < 90_MHz) {
				return 2;
			} else if (30_MHz <= t_hclk && t_hclk < 60_MHz) {
				return 1;
			} else {
				return 0;
			}
		},
	};

 public:
	template <float const& DeviceVolt>
	static constexpr auto getWaitState(std::uint64_t const& t_hclk) noexcept {
		return std::get<GET_IDX_FROM_VDD<DeviceVolt>()>(WAIT_STATE_TABLE)(t_hclk);
	}
};

template <std::uint8_t Val>
constexpr void flash_set_latency() noexcept {
	FLASH_ACR.template setBit<FlashAcrBit::Latency>(FlashLatency{CpuWaitState_v<Val>});
}

constexpr void flash_enable_dcache() noexcept { FLASH_ACR.setBit<FlashAcrBit::DCEn>(); }

constexpr void flash_enable_icache() noexcept { FLASH_ACR.setBit<FlashAcrBit::ICEn>(); }
