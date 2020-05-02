/**
 * @file  driver/digital_irq.hxx
 * @brief	Advance control of GPIO input mode external interrupt class
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

#include "cpp_stm32/driver/gpio_base.hxx"

#include "device.hxx"

namespace cpp_stm32::driver {

// @todo finish this
template <gpio::PinName Pin>
class DigitalIrq {
 public:
	template <auto F>
	explicit constexpr DigitalIrq(Callback<F> const& t_cb, exti::TriggerType const t_trigger) noexcept {
		using gpio::Mode, gpio::Pupd;

		GpioUtil<Pin>::enableAllGpioClk();
		GpioUtil<Pin>::modeSetup(Mode::Input, Pupd::None);

		// exti::set_trigger_type<>(t_trigger);

		{
			auto const critical_section = core::create_critical_section();
			// Interrupt<>::attach(t_cb);
		}
	}
};

}	 // namespace cpp_stm32::driver
