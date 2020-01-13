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

#include "cpp_stm32/common/gpio_common.hxx"
#include "cpp_stm32/target/stm32/common/memory/gpio_reg.hxx"

namespace cpp_stm32::common {

enum class GpioPort { PortA, PortB, PortC, PortD, PortE, PortF, PortG, PortH, PortI, PortJ, PortK, Total };

enum class GpioPin {
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7,
	Pin8,
	Pin9,
	Pin10,
	Pin11,
	Pin12,
	Pin13,
	Pin14,
	Pin15,
	Total
};

/**
 * @enum GpioMode
 */
enum class GpioMode {
	Input,	 /*!< Input mode */
	Output,	 /*!< Output mode */
	AltFunc, /*!< Alternate Function mode*/
	Analog	 /*!< Analog mode*/
};

enum class GpioPupd { None, PullUp, PullDown };
enum class GpioOutType { PushPull, OpenDrain };
enum class GpioOutSpeed { Low, Medium, Fast, High };
enum class GpioAltFunc { AF0, AF1, AF2, AF3, AF4, AF5, AF6, AF7, AF8, AF9, AF10, AF11, AF12, AF13, AF14, AF15 };

/**
 * @enum  PinName
 */
enum class PinName { PA_1, PA_2, PA_3, PA_5, PB_1, PB_2, PB_3, NC };

}	 // namespace cpp_stm32::common

namespace cpp_stm32::stm32::detail {

using common::GpioPort, common::GpioPin;

/**
 * @var 		PIN_NAME_TABLE
 * @brief
 *
 */
static constexpr std::array PIN_NAME_TABLE{
	std::pair{GpioPort::PortA, GpioPin::Pin1}, std::pair{GpioPort::PortA, GpioPin::Pin2},
	std::pair{GpioPort::PortA, GpioPin::Pin3}, std::pair{GpioPort::PortA, GpioPin::Pin5},
	std::pair{GpioPort::PortB, GpioPin::Pin1}, std::pair{GpioPort::PortB, GpioPin::Pin2},
	std::pair{GpioPort::PortB, GpioPin::Pin3},
};

/**
 * @brief   This function handles the setup of mode
 * @tparam  Port      ::GpioPort
 * @tparam  Pins      ::GpioPin
 * @param   t_mode    ::GpioMode
 */
template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_set_mode_impl(common::GpioMode const& t_mode) noexcept {
	GPIO_MODER<Port>.template setBit<Pins...>(t_mode);
}

/**
 * @brief   This function handles the setup of pullup/pulldown
 * @tparam  Port    ::GpioPort
 * @tparam  Pins    ::GpioPin
 * @param   t_pupd  ::GpioPupd
 */
template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_set_pupd_impl(common::GpioPupd const& t_pupd) noexcept {
	GPIO_PUPDR<Port>.template setBit<Pins...>(t_pupd);
}

/**
 * @brief   This function handles the setup of mode and pullup/pulldown
 * @tparam  Port      ::GpioPort
 * @tparam  Pins      ::GpioPin
 * @param   t_mode    ::GpioMode
 * @param   t_pupd    ::GpioPupd
 */
template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_mode_setup_impl(common::GpioMode const& t_mode, common::GpioPupd const& t_pupd) noexcept {
	GPIO_MODER<Port>.template setBit<Pins...>(t_mode);
	GPIO_PUPDR<Port>.template setBit<Pins...>(t_pupd);
}

/**
 * @brief   This function toggles gpio pins atomically
 * @tparam  Port      ::GpioPort
 * @tparam  Pins      ::GpioPin
 */
template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_toggle_impl() noexcept {
	constexpr auto HALF_WORD_OFFSET = 16U;

	auto const m_odr	 = GPIO_ODR<Port>.template readBit<Pins...>(ValueOnly);
	auto const mod_val = bit_group_cat(~m_odr, m_odr);

	// this is a bit hacky IMO, but can't come up with a better idea
	// @todo perhap add index rule in register class
	// @todo maybe group bits in SETUP_REGISTER_INFO macro, e.g.
	//			 SETUP_REGISTER_INFO(GpioBsrrInfo, {Bit<>{0}, Bit<>{16}, {...}})
	GPIO_BSRR<Port>.template setBit<Pins..., common::GpioPin{to_underlying(Pins) + HALF_WORD_OFFSET}...>(mod_val);
}

/**
 * @brief    This function handles the setup of alternate function
 * @tparam    Port    ::GpioPort
 * @tparam    Pins    ::GpioPin
 * @param     t_af    ::GpioAltFunc
 */
template <common::GpioPort Port, common::GpioPin... Pins>
constexpr void gpio_set_af_impl(common::GpioAltFunc const& t_af) noexcept {
	constexpr auto Pin7				 = common::GpioPin::Pin7;
	constexpr auto cast_to_int = to_underlying;	 // to prevent internal compiler error
	if constexpr (((Pins <= Pin7) || ...)) {
		constexpr auto low_pin_group = [](common::GpioPin t_pin) {
			if (t_pin <= Pin7) {
				return t_pin;
			}
		};

		GPIO_AFRL<Port>.template setBit<low_pin_group(Pins)...>(t_af);
	}

	if constexpr (((Pins > Pin7) || ...)) {
		constexpr auto high_pin_group = [](common::GpioPin t_pin) {
			if (t_pin > Pin7) {
				return common::GpioPin{cast_to_int(t_pin) - 8};
			}
		};

		GPIO_AFRH<Port>.template setBit<high_pin_group(Pins)...>(t_af);
	}
}

}	 // namespace cpp_stm32::stm32::detail

namespace cpp_stm32::stm32 {

[[nodiscard]] constexpr auto get_port_from_pin_name_table(common::PinName const& t_pin_name) noexcept {
	return std::get<0>(detail::PIN_NAME_TABLE[to_underlying(t_pin_name)]);
}

[[nodiscard]] constexpr auto get_pin_from_pin_name_table(common::PinName const& t_pin_name) noexcept {
	return std::get<1>(detail::PIN_NAME_TABLE[to_underlying(t_pin_name)]);
}

}	 // namespace cpp_stm32::stm32
