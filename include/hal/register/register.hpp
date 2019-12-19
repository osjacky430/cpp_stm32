/**
 * @Date:   2019-12-10T21:40:46+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: register.hpp
 */

#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>
#include <utility>

#include "include/hal/utility.hxx"

template <typename BitList, std::size_t Idx>
static constexpr auto get_bit() noexcept {
	return std::get<Idx>(BitList::BIT_LIST);
}

template <typename BitList, typename BitListIdx>
class Register {
 private:
	std::uint32_t const m_base;
	std::uint32_t const m_offset;

	template <BitListIdx BitIdx, typename ValueType>
	static constexpr auto IS_TYPE_AVAILABLE = []() {
		using BitType = decltype(get_bit<BitList, to_underlying(BitIdx)>());
		return std::is_same_v<ValueType, typename BitType::AbstractType>;
	};

 public:
	explicit constexpr Register(std::uint32_t const base, std::uint32_t const offset) : m_base(base), m_offset(offset) {}

	template <BitListIdx BitIdx>
	constexpr void setBit() const noexcept {
		constexpr auto bit = get_bit<BitList, to_underlying(BitIdx)>();

		static_assert(bit.LENGTH == 1);
		MMIO32(m_base, m_offset) |= bit.mask;
	}

	template <BitListIdx... BitIdx, typename ValueType>
	constexpr void setBit(ValueType const& t_param) const noexcept {
		static_assert((IS_TYPE_AVAILABLE<BitIdx, ValueType>() & ...));

		const auto current_val = MMIO32(m_base, m_offset);

		const auto mod_val		= (... | get_bit<BitList, to_underlying(BitIdx)>()(t_param));
		const auto clear_mask = ~(... | get_bit<BitList, to_underlying(BitIdx)>().mask);

		MMIO32(m_base, m_offset) = (current_val & clear_mask) | mod_val;
	}

	template <BitListIdx BitIdx>
	constexpr auto readBit() const noexcept {
		constexpr auto bit = get_bit<BitList, to_underlying(BitIdx)>();
		using Ret_t				 = typename decltype(bit)::AbstractType;

		return static_cast<Ret_t>(MMIO32(m_base, m_offset) & bit.mask);
	}

	template <BitListIdx BitIdx>
	constexpr void clearBit() const noexcept {
		constexpr auto bit = get_bit<BitList, to_underlying(BitIdx)>();
		MMIO32(m_base, m_offset) &= (~bit.mask);
	}
};
