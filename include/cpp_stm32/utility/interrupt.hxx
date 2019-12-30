/**
 * @Date:   2019-12-31T00:51:05+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: interrupt.hxx
 */

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
	static std::pair<void*, void (*)(void* const) noexcept> m_callback;

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
