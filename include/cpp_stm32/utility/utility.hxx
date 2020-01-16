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

#include <cstddef>
#include <functional>
#include <type_traits>
#include <utility>

#include "cpp_stm32/detail/index_interval.hxx"

namespace cpp_stm32 {

/**
 *
 */
template <std::size_t N, typename... Args>
using NthType = std::tuple_element_t<N, std::tuple<Args...>>;

template <std::size_t N, typename T, typename... Args>
static constexpr auto IsNthTypeSame = std::is_same_v<NthType<N, Args...>, T>;

/**
 *
 */
template <typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
constexpr auto to_underlying(Enum t_e) noexcept {
	return static_cast<std::underlying_type_t<Enum>>(t_e);
}

/**
 *
 */
template <typename Test, template <typename...> class Ref>
static constexpr bool is_specialization = false;

template <template <typename...> class Ref, typename... Args>
static constexpr bool is_specialization<Ref<Args...>, Ref> = true;

}	 // namespace cpp_stm32
