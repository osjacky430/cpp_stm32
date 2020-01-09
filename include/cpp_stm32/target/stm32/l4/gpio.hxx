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

#include <tuple>

#include "cpp_stm32/common/gpio_common.hxx"
#include "cpp_stm32/target/stm32/common/gpio.hxx"
#include "cpp_stm32/target/stm32/l4/memory/gpio_reg.hxx"

namespace cpp_stm32::stm32::l4 {

template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_set_mode(common::GpioMode const& t_mode) noexcept {
	// do some static assertion
	// static_assert(Port < common::GpioPort::PortJ);
	detail::gpio_set_mode_impl<Port, Pins...>(t_mode);
}

template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_set_pupd(common::GpioPupd const& t_pupd) noexcept {
	detail::gpio_set_pupd_impl<Port, Pins...>(t_pupd);
}

template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_mode_setup(common::GpioMode const& t_mode, common::GpioPupd const& t_pupd) noexcept {
	detail::gpio_mode_setup_impl<Port, Pins...>(t_mode, t_pupd);
}

template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_toggle() noexcept {
	detail::gpio_toggle_impl<Port, Pins...>();
}

template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_set_af(common::GpioAltFunc const& t_af) noexcept {
	detail::gpio_set_af_impl<Port, Pins...>();
}

}	 // namespace cpp_stm32::stm32::l4
