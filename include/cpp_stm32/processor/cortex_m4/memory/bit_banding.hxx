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

#include "cpp_stm32/utility/utility.hxx"

namespace cpp_stm32 {

enum class BitBandAddr : std::uint32_t {
	SRAMBase				= 0x2000'0000U,
	AliasSRAMBase		= 0x2200'0000U,
	PeriphBase			= 0x4000'0000U,
	AliasPeriphBase = 0x4200'0000U
};

constexpr auto to_alias_periph_addr(std::uint32_t const& t_mem_addr, std::uint8_t const& t_bit) noexcept {
	return to_underlying(BitBandAddr::AliasPeriphBase) + (t_mem_addr - to_underlying(BitBandAddr::PeriphBase)) * 32U +
				 t_bit * 4U;
}

constexpr auto to_alias_sram_addr(std::uint32_t const& t_mem_addr, std::uint8_t const& t_bit) noexcept {
	return to_underlying(BitBandAddr::AliasSRAMBase) + (t_mem_addr - to_underlying(BitBandAddr::SRAMBase)) * 32U +
				 t_bit * 4U;
}

}	 // namespace cpp_stm32
