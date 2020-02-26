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
#include <functional>

namespace cpp_stm32 {

enum class IrqNum : std::uint8_t;

template <auto F>
struct Callback;

template <typename OwnerT, void (OwnerT::*F)()>
class Callback<F> {
	using MethodHolder = OwnerT;

	template <IrqNum IRQn>
	friend class Interrupt;

	OwnerT* const thisPtr;

	Callback() = delete;

 public:
	explicit constexpr Callback(OwnerT* const t_val) : thisPtr{t_val} {}

	constexpr auto invoke() const noexcept { return thisPtr != nullptr ? std::invoke(F, thisPtr) : void(); }
};

template <typename Ret, Ret (*F)()>
struct Callback<F> {
	using MethodHolder = void;

	constexpr auto invoke() const noexcept { return F(); }
};

}	 // namespace cpp_stm32
