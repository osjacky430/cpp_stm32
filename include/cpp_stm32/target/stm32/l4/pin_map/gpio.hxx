#pragma once

#include <array>

#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/detail/tuple.hxx"
#include "cpp_stm32/target/stm32/l4/define/gpio.hxx"
#include "cpp_stm32/utility/enum_op.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

namespace cpp_stm32::gpio {

class PinMap {
 private:
	using PortPinPair = detail::Tuple<Port, Pin>;

	/**
	 * @var 		PIN_NAME_TABLE
	 * @brief
	 *
	 */
	static constexpr auto PIN_TABLE = []() {
		std::array<PortPinPair, to_underlying(PinName::Total)> temp{};

		detail::generate_n(temp.begin(), to_underlying(PinName::PA_15), [n = std::uint8_t{0}]() mutable {
			return PortPinPair{Port::PortA, Pin{n++}};
		});

		temp[to_underlying(PinName::PB_0)] = PortPinPair{Port::PortB, Pin::Pin0};
		temp[to_underlying(PinName::PB_1)] = PortPinPair{Port::PortB, Pin::Pin1};
		temp[to_underlying(PinName::PB_2)] = PortPinPair{Port::PortB, Pin::Pin2};
		temp[to_underlying(PinName::PB_3)] = PortPinPair{Port::PortB, Pin::Pin3};

		return temp;
	}();

 public:
	[[nodiscard]] static constexpr auto getPort(PinName const& t_pin_name) noexcept {
		return PIN_TABLE[to_underlying(t_pin_name)][0_ic];
	}

	[[nodiscard]] static constexpr auto getPin(PinName const& t_pin_name) noexcept {
		return PIN_TABLE[to_underlying(t_pin_name)][1_ic];
	}
};

}	// namespace cpp_stm32::gpio
