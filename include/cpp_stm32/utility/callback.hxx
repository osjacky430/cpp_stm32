/**
 * @Date:   2019-12-30T15:09:24+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: Callback.hxx
 */

#pragma once

#include <functional>

template <auto F>
struct Callback;

template <typename OwnerT, void (OwnerT::*F)()>
struct Callback<F> {
	using MethodHolder = OwnerT;

	explicit constexpr Callback(OwnerT* const t_val) : thisPtr{t_val} {}

	OwnerT* const thisPtr;
	constexpr auto invoke() const noexcept { return thisPtr != nullptr ? std::invoke(F, thisPtr) : void(); }
};

template <typename Ret, Ret (*F)()>
struct Callback<F> {
	using MethodHolder = void;

	constexpr auto invoke() const noexcept { return F(); }
};
