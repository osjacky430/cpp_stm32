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

#include <array>

#include "cpp_stm32/utility/callback.hxx"
#include "cpp_stm32/utility/utility.hxx"

enum class IrqNum : std::uint8_t;

/**
 * [void  description]
 * @param [name] [description]
 */
template <typename Class>
using MemberFuncPtr = void (Class::*)() noexcept;
using NormalFuncPtr = void (*)() noexcept;

template <typename Class, MemberFuncPtr<Class> MemberFunc>
static constexpr void WRAP_TO_C_STYLE_FUNC(void* const t_this_ptr) noexcept {
	std::invoke(MemberFunc, static_cast<Class* const>(t_this_ptr));
}

template <NormalFuncPtr Func>
static constexpr void WRAP_TO_C_STYLE_FUNC(void* const /**/) noexcept {
	Func();
}

/**
 * [void  description]
 * @param [name] [description]
 */
template <IrqNum IRQn>
class Interrupt {
 private:
	using WrapperFuncPtr = void (*)(void* const) noexcept;
	using CStyleThisPtr	 = void*;

	static std::pair<CStyleThisPtr, WrapperFuncPtr> m_callback;

 public:
	explicit constexpr Interrupt() noexcept {}

	static constexpr void interrupt() noexcept {
		auto const [class_ptr, c_style_wrapper_func] = m_callback;
		c_style_wrapper_func(class_ptr);
	}

	template <auto F>
	static constexpr void attach(Callback<F> const& t_cb) noexcept {
		if constexpr (std::is_class_v<typename Callback<F>::MethodHolder>) {
			std::get<0>(m_callback) = static_cast<void* const>(t_cb.thisPtr);
			std::get<1>(m_callback) = &WRAP_TO_C_STYLE_FUNC<typename Callback<F>::MethodHolder, F>;
		} else {
			std::get<1>(m_callback) = &WRAP_TO_C_STYLE_FUNC<F>;
		}
	}

	template <typename Class, MemberFuncPtr<Class> MemberFunc>
	static constexpr void attach(Class* const t_this_ptr) noexcept {
		std::get<0>(m_callback) = static_cast<void*>(t_this_ptr);
		std::get<1>(m_callback) = &WRAP_TO_C_STYLE_FUNC<Class, MemberFunc>;
	}

	template <NormalFuncPtr Function>
	static constexpr void attach() noexcept {
		std::get<0>(m_callback) = nullptr;
		std::get<1>(m_callback) = &WRAP_TO_C_STYLE_FUNC<Function>;
	}
};
