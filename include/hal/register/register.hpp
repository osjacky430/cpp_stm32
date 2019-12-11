/**
 * @Date:   2019-12-10T21:40:46+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: register.hpp
 * @Last modified time: 2019-12-11T20:35:52+08:00
 */

#ifndef REGISTER_HPP_
#define REGISTER_HPP_

#include <cstdint>
#include <tuple>
#include <type_traits>
#include <utility>

#include "include/hal/utility.hxx"

template <typename... Args>
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

	template <typename T>
	constexpr void operator|=(T const &t) const noexcept {
		static_assert(isTypeAvailable(t, std::make_index_sequence<sizeof...(Args)>{}));

		MMIO32(m_base, m_offset) |= to_underlying(t);
	}

	template <typename T>
	constexpr auto operator&(T const &t) const noexcept {
		static_assert(isTypeAvailable(t, std::make_index_sequence<sizeof...(Args)>{}));

		return MMIO32(m_base, m_offset) & to_underlying(t);
	}
};

#endif	// REGISTER_HPP_
