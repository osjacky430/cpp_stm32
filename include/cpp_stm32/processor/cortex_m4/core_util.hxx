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
#include <utility>

namespace cpp_stm32 {

template <std::size_t Priority>
using MaskPriority = std::integral_constant<std::uint8_t, Priority>;

}

namespace cpp_stm32::detail {

[[gnu::always_inline]] inline void disable_all_interrupts() noexcept {
	__asm volatile(
		"mov r0 #1   \n"	// move 1 to r0
		"msr PRIMASK r0"	// move the content of r0 into PRIMASK
		:									// no output
		:									// no input
		: "memory"				// performs memory reads or writes to items other than those
											// listed in the input and output operands
	);
}

[[gnu::always_inline]] inline void enable_all_interrupts() noexcept {
	__asm volatile(
		"mov r0 #0   \n"	// move 0 to r0
		"msr PRIMASK r0"	// move the content of r0 into PRIMASK
		:									// no output
		:									// no input
		: "memory");
}

[[gnu::always_inline]] inline auto all_interrupts_disabled() noexcept {
	std::uint32_t is_disabled = 0;
	__asm volatile("mrs %0 PRIMASK" : "=r"(is_disabled));
	// 0 => all interrupts not disabled
	// 1 => all interrupts disabled
	return is_disabled;
}

[[gnu::always_inline]] inline void set_interrupt_mask_priority(int t_priority) noexcept {
	__asm volatile("msr BASEPRI %0 \n"	// move the content of r0 into BASEPRI
								 :										// no output
								 : "r"(t_priority)		//
								 : "memory"						//
	);
}

[[gnu::always_inline]] inline auto get_interrupt_mask_priority() noexcept {
	std::uint8_t ret_val = 0;
	__asm volatile("mrs %0 BASEPRI" : "=r"(ret_val));

	return ret_val;
}

}	 // namespace cpp_stm32::detail

namespace cpp_stm32 {

template <std::uint8_t Priority = 0>
[[nodiscard]] constexpr auto create_critical_section(
	[[gnu::unused]] MaskPriority<Priority> const& t_mask = MaskPriority<0>{}) noexcept {
	using namespace detail;

	class CriticalSection {
	 private:
		std::uint32_t const m_interruptValue;

	 public:
		constexpr CriticalSection() noexcept
			: m_interruptValue(Priority == 0 ? all_interrupts_disabled() : get_interrupt_mask_priority()) {
			if constexpr (Priority != 0) {
				static_assert(Priority & 0xF0);
				set_interrupt_mask_priority(Priority);
			} else {
				disable_all_interrupts();
			}
		}

		~CriticalSection() noexcept {
			if constexpr (Priority != 0) {
				if (m_interruptValue == 0) {
					set_interrupt_mask_priority(0);
				}
			} else {
				if (m_interruptValue == 0) {
					enable_all_interrupts();
				}
			}
		}
	};

	return CriticalSection{};
}

}	 // namespace cpp_stm32
