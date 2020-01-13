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

// slightly binary file size overhead, due to "regVal"
// if memory location is non-type template param, this overhead can be eliminated,
// but this is a huge change
template <typename T>
class MMIO_t {
 private:
	T& regVal;	// this can be wrong

 public:
	explicit constexpr MMIO_t(T& t_reg_val) noexcept : regVal(t_reg_val) {}

	template <typename Rhs>
	[[nodiscard]] constexpr auto operator|(Rhs const& t_val) const noexcept {
		return regVal | t_val;
	}

	template <typename Rhs>
	constexpr void operator|=(Rhs const& t_val) const noexcept {
		regVal |= t_val;
	}

	template <typename Rhs>
	[[nodiscard]] constexpr auto operator&(Rhs const& t_val) const noexcept {
		return regVal & t_val;
	}

	template <typename Rhs>
	constexpr void operator&=(Rhs const& t_val) const noexcept {
		regVal &= t_val;
	}

	template <typename Rhs>
	[[nodiscard]] constexpr auto operator^(Rhs const& t_val) const noexcept {
		return regVal ^ t_val;
	}

	template <typename Rhs>
	constexpr void operator^=(Rhs const& t_val) const noexcept {
		regVal ^= t_val;
	}

	template <typename Rhs>
	[[nodiscard]] constexpr auto operator~() const noexcept {
		return ~regVal;
	}

	template <typename Rhs>
	[[nodiscard]] constexpr auto operator<<(Rhs const& t_val) const noexcept {
		return regVal << t_val;
	}

	template <typename Rhs>
	constexpr void operator<<=(Rhs const& t_val) const noexcept {
		regVal <<= t_val;
	}

	template <typename Rhs>
	[[nodiscard]] constexpr auto operator>>(Rhs const& t_val) const noexcept {
		return regVal >> t_val;
	}

	template <typename Rhs>
	constexpr void operator>>=(Rhs const& t_val) const noexcept {
		regVal >>= t_val;
	}

	template <typename Rhs>
	constexpr void operator=(Rhs const& t_val) const noexcept {
		regVal = t_val;
	}
};

// template <typename T>
// class MMIO_t {
//  private:
// 	std::uint32_t addr;
// 	T regVal;
//
// 	static constexpr decltype(auto) MMIO(std::uint32_t t_addr) noexcept { return *reinterpret_cast<volatile T*>(t_addr);
// }
// 	// T& regVal;	// this can be wrong
//
//  public:
// 	// explicit constexpr MMIO_t(T& t_reg_val) noexcept : regVal(t_reg_val) {}
// 	explicit constexpr MMIO_t(std::uint32_t t_addr) noexcept : addr(t_addr), regVal(MMIO(addr)) {}
//
// 	template <typename Rhs>
// 	[[nodiscard]] constexpr auto operator|(Rhs const& t_val) const noexcept {
// 		return regVal | t_val;
// 	}
//
// 	template <typename Rhs>
// 	constexpr void operator|=(Rhs const& t_val) const noexcept {
// 		MMIO(addr) |= t_val;
// 	}
//
// 	template <typename Rhs>
// 	[[nodiscard]] constexpr auto operator&(Rhs const& t_val) const noexcept {
// 		return regVal & t_val;
// 	}
//
// 	template <typename Rhs>
// 	constexpr void operator&=(Rhs const& t_val) const noexcept {
// 		MMIO(addr) &= t_val;
// 	}
//
// 	template <typename Rhs>
// 	[[nodiscard]] constexpr auto operator^(Rhs const& t_val) const noexcept {
// 		return regVal ^ t_val;
// 	}
//
// 	template <typename Rhs>
// 	constexpr void operator^=(Rhs const& t_val) const noexcept {
// 		MMIO(addr) ^= t_val;
// 	}
//
// 	template <typename Rhs>
// 	[[nodiscard]] constexpr auto operator~() const noexcept {
// 		return ~regVal;
// 	}
//
// 	template <typename Rhs>
// 	[[nodiscard]] constexpr auto operator<<(Rhs const& t_val) const noexcept {
// 		return regVal << t_val;
// 	}
//
// 	template <typename Rhs>
// 	constexpr void operator<<=(Rhs const& t_val) const noexcept {
// 		MMIO(addr) <<= t_val;
// 	}
//
// 	template <typename Rhs>
// 	[[nodiscard]] constexpr auto operator>>(Rhs const& t_val) const noexcept {
// 		return regVal >> t_val;
// 	}
//
// 	template <typename Rhs>
// 	constexpr void operator>>=(Rhs const& t_val) const noexcept {
// 		MMIO(addr) >>= t_val;
// 	}
//
// 	template <typename Rhs>
// 	constexpr void operator=(Rhs const& t_val) const noexcept {
// 		MMIO(addr) = t_val;
// 	}
// };
// //
// template <typename T>
// constexpr auto MMIO(std::uint32_t addr, const std::uint16_t offset) noexcept {
// 	return MMIO_t<T>{addr + offset};
// }

template <typename T>
constexpr auto MMIO(std::uint32_t addr, const std::uint16_t offset) noexcept {
	return MMIO_t{*reinterpret_cast<volatile T*>(addr + offset)};
}

// template <typename T>
// constexpr decltype(auto) MMIO(std::uint32_t addr, const std::uint16_t offset) noexcept {
// 	return *reinterpret_cast<volatile T*>(addr + offset);
// }

static constexpr auto const MMIO32 = MMIO<std::uint32_t>;
static constexpr auto const MMIO16 = MMIO<std::uint16_t>;
static constexpr auto const MMIO8	 = MMIO<std::uint8_t>;

}	 // namespace cpp_stm32
