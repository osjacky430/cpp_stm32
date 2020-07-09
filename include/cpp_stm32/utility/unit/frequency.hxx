#pragma once

#include "cpp_stm32/utility/unit/unit.hxx"

namespace cpp_stm32 {

template <std::uint32_t Freq>
struct Frequency : Unit<Freq, struct CPP_STM32_FREQUENCY_UNIT> {
	template <std::uint32_t P>
	constexpr auto operator/(Frequency<P> const) const noexcept {
		return Freq / P;
	}

	template <std::uint32_t P>
	constexpr auto operator/(std::integral_constant<std::uint32_t, P> const) const noexcept {
		return Frequency<Freq / P>{};
	}
};

}	// namespace cpp_stm32
