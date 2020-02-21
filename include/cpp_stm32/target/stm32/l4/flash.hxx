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

#include <cstdint>

#include "cpp_stm32/target/stm32/l4/memory/flash_reg.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

namespace cpp_stm32::pwr {

enum class VoltageScale;

}

namespace cpp_stm32::flash {

struct Latency;

/**
 * [if  description]
 * @param _MHz [description]
 */
struct WaitTable {
 private:
	static constexpr std::tuple WAIT_STATE_TABLE{
		[](std::uint64_t const& t_hclk) {
			if (64_MHz <= t_hclk && t_hclk <= 80_MHz) {
				return 4;
			} else if (48_MHz <= t_hclk && t_hclk <= 64_MHz) {
				return 3;
			} else if (32_MHz <= t_hclk && t_hclk <= 48_MHz) {
				return 2;
			} else if (16_MHz <= t_hclk && t_hclk <= 32_MHz) {
				return 1;
			} else if (t_hclk <= 16_MHz) {
				return 0;
			}
		},
		[](std::uint64_t const& t_hclk) {
			if (18_MHz <= t_hclk && t_hclk <= 26_MHz) {
				return 3;
			} else if (12_MHz <= t_hclk && t_hclk <= 18_MHz) {
				return 2;
			} else if (6_MHz <= t_hclk && t_hclk <= 12_MHz) {
				return 1;
			} else if (t_hclk <= 6_MHz) {
				return 0;
			}
		},
		/*add the rest here*/
	};

 public:
	/**
	 * [getWaitState description]
	 * @tparam 	DeviceVolt 		Device voltage, valid range from 1.71V to 3.6V
	 * @param   t_hclk 				Ahpb clock freqency
	 * @note		DeviceVolt is useless here, despite that the wait state depends on the voltage output
	 * 				  of internal regulator, which somehow depends on Vdd. Since only two possible voltage
	 * 				  range, we can decide the wait state by clock frequency.
	 * @return  The wait state
	 */
	template <float const& DeviceVolt>
	static constexpr auto getWaitState(std::uint64_t const& t_hclk) noexcept {
		if (t_hclk >= 26_MHz) {
			return std::get<0>(WAIT_STATE_TABLE)(t_hclk);
		} else {
			return std::get<1>(WAIT_STATE_TABLE)(t_hclk);
		}
	}
};

enum class ARTAccel { InstructCache = 1, DataCache = 2, InstructPrefetch = 3 };

constexpr void set_latency(Latency const& t_cpu) noexcept { reg::ACR.writeBit<reg::AcrBit::Latency>(t_cpu); }

constexpr void enable_dcache() noexcept { reg::ACR.setBit<reg::AcrBit::DCEn>(); }

constexpr void enable_icache() noexcept { reg::ACR.setBit<reg::AcrBit::ICEn>(); }

template <ARTAccel... Setting>
constexpr void config_access_ctl(Latency const& t_cpu) noexcept {
	constexpr auto register_to_set = [](ARTAccel const& t_setting) {
		switch (t_setting) {
			case ARTAccel::InstructCache:
				return reg::AcrBit::ICEn;
			case ARTAccel::DataCache:
				return reg::AcrBit::DCEn;
			case ARTAccel::InstructPrefetch:
				return reg::AcrBit::PrftEn;
		}
	};

	std::tuple const val_to_set{t_cpu, std::uint8_t(to_underlying(Setting) != 0)...};	 // fill the rest with 1 or 0
	reg::ACR.template writeBit<reg::AcrBit::Latency, register_to_set(Setting)...>(val_to_set);
}

}	 // namespace cpp_stm32::flash
