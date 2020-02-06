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

#include <tuple>

#include "cpp_stm32/utility/integral_constant.hxx"

namespace cpp_stm32 {

// this is substitution of std::tuple due to nonconstexpr assignment of std::tuple, rename and complete it in the future
template <typename... Args>
class PinData {
 private:
	std::tuple<Args...> argTup;

	template <std::size_t... Idx>
	constexpr void element_eq(PinData<Args...> const& t_data, std::index_sequence<Idx...> const& /*unused*/) noexcept {
		((std::get<Idx>(argTup) = std::get<Idx>(t_data.argTup)), ...);
	}

 public:
	constexpr PinData() noexcept : argTup{Args{}...} {}
	constexpr PinData(PinData const& t_tup) noexcept : argTup(t_tup.argTup) {}
	constexpr PinData(Args... args) noexcept : argTup{args...} {}

	template <auto Idx>
	[[nodiscard]] constexpr auto const& operator[](size_c<Idx> const& /*unused*/) const noexcept {
		return std::get<Idx>(argTup);
	}

	constexpr void operator=(PinData<Args...> const& t_data) noexcept {
		element_eq(t_data, std::make_index_sequence<sizeof...(Args)>{});
	}
};

}	 // namespace cpp_stm32
