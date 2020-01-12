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

#include "cpp_stm32/target/stm32/l4/memory/flash_reg.hxx"

namespace cpp_stm32::stm32::l4 {

enum class ARTAccel { InstructCache = 1, DataCache = 2, InstructPrefetch = 3 };

constexpr void flash_set_latency(FlashLatency const& t_cpu) noexcept { FLASH_ACR.setBit<FlashAcrBit::Latency>(t_cpu); }

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

	const auto val_to_set = BitGroup{t_cpu, std::uint8_t(to_underlying(Setting) != 0)...};	// fill the rest with 1 or 0
	FLASH_ACR.template setBit<FlashAcrBit::Latency, register_to_set(Setting)...>(val_to_set);
}

}	// namespace cpp_stm32::stm32::l4
