/**
 * @Date:   2019-12-10T21:40:46+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: register.hpp
 * @Last modified time: 2019-12-14T01:36:56+08:00
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

template <typename BitList, typename BitListIdx, typename... Args>
class Register {
 private:
	std::uint32_t const m_base;
	std::uint32_t const m_offset;

 public:
	explicit constexpr Register(std::uint32_t const base, std::uint32_t const offset) : m_base(base), m_offset(offset) {}

 public:
	template <std::size_t Idx>
	using ListOfAvailableType = typename std::tuple_element<Idx, std::tuple<Args...>>::type;

	template <typename T, std::size_t... Idx>
	static constexpr bool isTypeAvailable(T const &, std::index_sequence<Idx...>) noexcept {
		return (std::is_same_v<ListOfAvailableType<Idx>, T> | ...);
	}

	template <BitListIdx BitIdx>
	constexpr void setBit() const noexcept {
		constexpr auto bit = get_bit<BitList, to_underlying(BitIdx)>();

		static_assert(bit.LENGTH == 1);
		MMIO32(m_base, m_offset) |= bit.mask;
	}

	template <BitListIdx BitIdx, typename ValueType>
	constexpr void setBit(ValueType const &t_param) const noexcept {
		static_assert(isTypeAvailable(t_param, std::make_index_sequence<sizeof...(Args)>{}));

		constexpr auto bit = get_bit<BitList, to_underlying(BitIdx)>();
		const auto val		 = t_param.get();
	}

	template <BitListIdx BitIdx>
	constexpr auto read_bit() const noexcept {}
};
