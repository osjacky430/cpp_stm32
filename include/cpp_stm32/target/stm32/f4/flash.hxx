// Copyright (c) 2020 by osjacky430.
// All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the Lesser GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// Lesser GNU General Public License for more details.
//
// You should have received a copy of the Lesser GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <array>
#include <tuple>

#include "cpp_stm32/target/stm32/f4/memory/flash_reg.hxx"
#include "cpp_stm32/utility/literal_op.hxx"
#include "cpp_stm32/utility/strongly_typed.hxx"

namespace cpp_stm32::stm32::f4 {

/**
 * @class   FlashWaitTable
 * @brief   This class is used to get flash wait state according to clock frequency and device voltage
 */
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
	/**
	 * @brief    A getter function that returns wait state according to clock frequency and device voltage
	 * @tparam   DeviceVolt  Device voltage, see @ref DEVICE_VOLTAGE_DEF
	 * @param    t_hclk      Ahb clock frequency
	 * @return   the number of wait state
	 */
	template <float const& DeviceVolt>
	static constexpr auto getWaitState(std::uint64_t const& t_hclk) noexcept {
		return std::get<GET_IDX_FROM_VDD<DeviceVolt>()>(WAIT_STATE_TABLE)(t_hclk);
	}
};

enum class ARTAccel { InstructCache = 1, DataCache = 2, InstructPrefetch = 3 };

constexpr void flash_set_latency(FlashLatency const& t_cpu) noexcept {
	FLASH_ACR.template setBit<FlashAcrBit::Latency>(t_cpu);
}

constexpr void flash_enable_dcache() noexcept { FLASH_ACR.setBit<FlashAcrBit::DCEn>(); }

constexpr void flash_enable_icache() noexcept { FLASH_ACR.setBit<FlashAcrBit::ICEn>(); }

template <ARTAccel... Setting>
constexpr void flash_config_access_ctl(FlashLatency const& t_cpu) noexcept {
	constexpr auto register_to_set = [](ARTAccel const& t_setting) {
		switch (t_setting) {
			case ARTAccel::InstructCache:
				return FlashAcrBit::ICEn;
			case ARTAccel::DataCache:
				return FlashAcrBit::DCEn;
			case ARTAccel::InstructPrefetch:
				return FlashAcrBit::PrftEn;
		}
	};

	const auto val_to_set =
		BitGroup{t_cpu, static_cast<std::uint8_t>(to_underlying(Setting) != 0)...};	 // fill the rest with 1
	FLASH_ACR.template setBit<FlashAcrBit::Latency, register_to_set(Setting)...>(val_to_set);
}

}	 // namespace cpp_stm32::stm32::f4
