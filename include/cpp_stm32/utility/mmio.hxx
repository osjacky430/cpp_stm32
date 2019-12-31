/**
 * @Date:   2019-12-31T01:12:00+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: mmio.hxx
 */

#pragma once

#include <cstdint>

#include "cpp_stm32/utility/utility.hxx"

// slightly binary file size overhead, due to "regVal"
template <typename T>
class MMIO_t {
 private:
	T& regVal;

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

enum class Access { Word = 0b100, HalfWord = 0b010, Byte = 0b001 };
constexpr auto operator|(Access const& lhs, Access const& rhs) {
	return Access{to_underlying(lhs) | to_underlying(rhs)};
}
