/**
 * @file  cortex_m4/core_util.hxx
 * @brief	Provide cortex-m4 specific utility functions
 */

/** Copyright (c) 2020 by osjacky430.
 * All Rights Reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstdint>
#include <utility>

namespace cpp_stm32 {

template <std::size_t Priority>
using MaskPriority = std::integral_constant<std::uint8_t, Priority>;

}	 // namespace cpp_stm32

namespace cpp_stm32::core {

/**
 * @brief 	This function disables all the interrupts (except nmi_handler and hard_fault_handler) by setting PRIMASK
 * 					to 1.
 * @note 	This function can only be executed in priviledged mode
 */
[[gnu::always_inline]] inline void disable_all_interrupts() noexcept {
	__asm volatile(
		"movs r0, #1   \n\t"	// move 1 to r0
		"msr primask, r0"			// move the content of r0 into PRIMASK
		:											// no output
		:											// no input
		: "memory"						// performs memory reads or writes to items other than those
													// listed in the input and output operands
	);
}

/**
 * 	@brief 	This function enables all the interrupts by setting PRIMASK to 0
 * 	@note 	This function can only be executed in priviledged mode
 */
[[gnu::always_inline]] inline void enable_all_interrupts() noexcept {
	__asm volatile(
		"movs r0, #0   \n\t"	// move 0 to r0
		"msr primask, r0"			// move the content of r0 into PRIMASK
		:											// no output
		:											// no input
		: "memory");
}

/**
 * @brief 	This function returns the value of PRIMASK
 * @note 		This function can only be executed in priviledged mode
 *
 * @return 	true if interrupt is disabled, false otherwise
 */
[[gnu::always_inline, nodiscard]] inline auto all_interrupts_disabled() noexcept {
	std::uint32_t is_disabled = 0;
	__asm volatile("mrs %0, PRIMASK" : "=r"(is_disabled));
	// 0 => all interrupts not disabled
	// 1 => all interrupts disabled
	return is_disabled;
}

/**
 * @brief 	This function disables all the interrupts having priority lower than input priority
 * @param 	t_priority 	Priority to set
 */
[[gnu::always_inline]] inline void set_interrupt_mask_priority(int const t_priority) noexcept {
	__asm volatile("msr BASEPRI, %0 \n"	 // move the content of r0 into BASEPRI
								 :										 // no output
								 : "r"(t_priority)		 //
								 : "memory"						 //
	);
}

/**
 * @brief 	This function gets the interrupt priority by reading BASEPRI
 * @param 	t_priority 	Priority to set
 */
[[gnu::always_inline, nodiscard]] inline auto get_interrupt_mask_priority() noexcept {
	std::uint8_t ret_val = 0;
	__asm volatile("mrs %0, BASEPRI" : "=r"(ret_val));

	return ret_val;
}

/**
 * @brief 	This function enables all IRQ
 * @note		This function can only be executed in privileged modes.
 */
[[gnu::always_inline]] inline void enable_fault_irq() noexcept {
	__asm volatile(
		"movs r0, #0 	\n\t"	 // move 0 to r0
		"msr FAULTMASK, r0"	 // move the content of r0 to FAUTLMASK
		:
		:
		: "memory");
}

/**
 * @brief 	This function disables all IRQ, including hard_fault_handler
 * @note		This function can only be executed in privileged modes.
 */
[[gnu::always_inline]] inline void disable_fault_irq() noexcept {
	__asm volatile(
		"movs r0, #1 	\n\t"	 // move 1 to r0
		"msr FAULTMASK, r0"	 // move the content of r0 to FAUTLMASK
		:
		:
		: "memory");
}

/**
 * @brief 	This function checks whether hard_fault_handler is disabled
 * @note		This function can only be executed in privileged mode
 */
[[gnu::always_inline, nodiscard]] inline auto is_fault_irq_disabled() noexcept {
	std::uint32_t ret_val;
	__asm volatile("mrs %0, FAULTMASK" : "=r"(ret_val));

	return ret_val;
}

}	 // namespace cpp_stm32::core

namespace cpp_stm32::core {

static constexpr auto MAX_IRQ_NUM = 240;

/**
 * 	@brief 		This function creates a critical section that masks the interrupt priority up to input priority. The
 * 						critical section will end only when it goes out of scope. Therefore it is recommended to limit the scope
 * 						of the critical section so that it goes out of scope ASAP.
 * 	@tparam 	Priority 	Desire priority to mask
 * 	@param  	t_mask
 *
 * 	@note			This function can only be executed in priviledged mode
 * 	@return		critical section
 */
template <std::uint8_t Priority = 0>
[[nodiscard]] constexpr auto create_critical_section(
	[[gnu::unused]] MaskPriority<Priority> const& t_mask = MaskPriority<0>{}) noexcept {
	class CriticalSection {
	 private:
		std::uint32_t const m_interruptValue{Priority == 0 ? all_interrupts_disabled() : get_interrupt_mask_priority()};

	 public:
		CriticalSection() noexcept {
			if constexpr (Priority != 0) {
				static_assert(Priority & MAX_IRQ_NUM);	// Cortex M4 implement four priority bits, i.e., 0b11110000 (240)
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

}	 // namespace cpp_stm32::core
