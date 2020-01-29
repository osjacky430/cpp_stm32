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

#include "cpp_stm32/hal/mmio.hxx"
#include "cpp_stm32/hal/register.hxx"
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

constexpr auto is_in_sram_bit_band_region(std::uint32_t const& t_mem_addr) noexcept {
	return to_underlying(BitBandAddr::SRAMBase) <= t_mem_addr &&
				 t_mem_addr <= to_underlying(BitBandAddr::AliasPeriphBase);
}

constexpr auto is_in_periph_bit_band_region(std::uint32_t const& t_mem_addr) noexcept {
	return to_underlying(BitBandAddr::PeriphBase) <= t_mem_addr &&
				 t_mem_addr <= to_underlying(BitBandAddr::AliasPeriphBase);
}

constexpr auto to_alias_addr(std::uint32_t const& t_mem_addr, std::uint8_t const& t_bit) noexcept {
	if (is_in_periph_bit_band_region(t_mem_addr)) {
		return to_alias_periph_addr(t_mem_addr, t_bit);
	} else if (is_in_sram_bit_band_region(t_mem_addr)) {
		return to_alias_sram_addr(t_mem_addr, t_bit);
	} else {
		return 0UL;
	}
}

constexpr auto atomicity(std::uint32_t const& t_mem_addr) noexcept {
	return is_in_periph_bit_band_region(t_mem_addr) || is_in_sram_bit_band_region(t_mem_addr);
}

template <typename BitList, typename BitListIdx, Access IoOp, bool atomicity>
template <BitListIdx BitIdx, typename ValueType, bool b>
constexpr void Register<BitList, BitListIdx, IoOp, atomicity>::writeBit(ValueType const& t_param,
																																				Atomic_t<b> const& /*unused*/) const noexcept {
	constexpr auto bit = GET_BIT<BitIdx>();
	static_assert(atomicity && b);
	static_assert((bit.template isTypeAvailable<ValueType>()));
	static_assert((bit.isWritable()));

	auto const val = [=]() {
		if constexpr (std::is_enum_v<ValueType>) {
			return to_underlying(t_param);
		} else if constexpr (std::is_integral_v<ValueType>) {
			return t_param;
		} else {
			return t_param.get();
		}
	}();

	for (std::uint8_t i = 0U; i < bit.LENGTH; ++i) {
		MMIO32(m_base + m_offset, i) = (val & (1U << i)) >> i;
	}
}

}	 // namespace cpp_stm32
