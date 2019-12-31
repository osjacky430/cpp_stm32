/**
 * @Date:   2020-01-01T02:27:31+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: pin_map.hxx
 */

#pragma once

#include <array>

#include "cpp_stm32/target/stm32/f4/gpio.hxx"

enum class PinName { PA_1, PA_2, PA_3, PA_5, PB_1, NC };

class PinNameMap {
 private:
	static constexpr std::array PinMap{
		std::pair{GpioPort::PortA, GpioPin::Pin1}, std::pair{GpioPort::PortA, GpioPin::Pin2},
		std::pair{GpioPort::PortA, GpioPin::Pin3}, std::pair{GpioPort::PortA, GpioPin::Pin5},
		std::pair{GpioPort::PortB, GpioPin::Pin1},
	};

 public:
	static constexpr auto getPortFromPinMap(const PinName t_pin_name) noexcept {
		return std::get<0>(PinMap[to_underlying(t_pin_name)]);
	}

	static constexpr auto getPinFromPinMap(const PinName t_pin_name) noexcept {
		return std::get<1>(PinMap[to_underlying(t_pin_name)]);
	}
};
