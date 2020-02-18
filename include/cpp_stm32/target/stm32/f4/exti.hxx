/**
 * @file  stm32/f4/exti.hxx
 * @brief	Exti setup API for stm32f4
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

#include "cpp_stm32/target/stm32/f4/register/exti.hxx"

namespace cpp_stm32::exti {

/**
 * @brief   This function enables the external interrupt
 * @tparam  Lines   @ref exti::Line
 */
template <Line... Lines>
constexpr void enable() noexcept {
	reg::IMR.setBit<Lines...>();
	reg::EMR.setBit<Lines...>();
}

/**
 * @brief   This function disables the external interrupt
 * @tparam  Lines   @ref exti::Line
 */
template <Line... Lines>
constexpr void disable() noexcept {
	reg::IMR.clearBit<Lines...>();
	reg::EMR.clearBit<Lines...>();
}

/**
 * @brief   This function sets the trigger type of external interrupt
 * @tparam  Lines     @ref exti::Line
 * @param   t_trigger @ref exti::TriggerType
 */
template <Line... Lines>
constexpr void set_trigger_type(TriggerType const t_trigger) noexcept {
	static_assert(((Lines != Line::Line19) && ...));

	switch (t_trigger) {
		case TriggerType::Rise:
			reg::RTSR.setBit<Lines...>();
			reg::FTSR.clearBit<Lines...>();
			break;
		case TriggerType::Fall:
			reg::RTSR.clearBit<Lines...>();
			reg::FTSR.setBit<Lines...>();
			break;
		case TriggerType::Both:
			reg::RTSR.setBit<Lines...>();
			reg::FTSR.setBit<Lines...>();
			break;
	}
}

/**
 * @brief   This function generates interrupt requests of external interrupts
 * @tparam  Lines   @ref exti::Line
 */
template <Line... Lines>
constexpr void generate_software_irq() noexcept {
	reg::SWIER.setBit<Lines...>();
}

/**
 * @brief   This function returns the states of the external interrupt lines
 * @tparam  Lines   @ref exti::Line
 * @return  @ref BitGroup that contains the state of exti line, true for active, and false for not.
 */
template <Line... Lines>
[[nodiscard]] constexpr auto is_active() noexcept {
	return reg::PR.readBit<Lines...>(ValueOnly);
}

/**
 * @brief   This function clears the states of the external interrupt lines
 * @tparam  Lines   @ref exti::Line
 */
template <Line... Lines>
constexpr void clear_active_flag() noexcept {
	reg::PR.setBit<Lines...>();
}

}	 // namespace cpp_stm32::exti
