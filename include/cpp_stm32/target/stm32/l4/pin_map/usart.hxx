#pragma once

#include "cpp_stm32/detail/tuple.hxx"
#include "cpp_stm32/target/stm32/l4/gpio.hxx"
#include "cpp_stm32/target/stm32/l4/interrupt.hxx"
#include "cpp_stm32/target/stm32/l4/register/rcc.hxx"
#include "cpp_stm32/target/stm32/l4/register/usart.hxx"
#include "cpp_stm32/utility/enum_op.hxx"

namespace cpp_stm32::usart {

class PinMap {
 private:
	using PinName = gpio::PinName;

	using UsartPinData = detail::Tuple<PinName, Port, gpio::AltFunc, rcc::PeriphClk, IrqNum>;

	static constexpr std::array TX_PIN_TABLE{
		UsartPinData{PinName::PA_2, Port::Usart2, gpio::AltFunc::AF7, rcc::PeriphClk::Usart2, IrqNum::Usart2Global},

	};

	static constexpr std::array RX_PIN_TABLE{
		UsartPinData{PinName::PA_3, Port::Usart2, gpio::AltFunc::AF7, rcc::PeriphClk::Usart2, IrqNum::Usart2Global},

	};

 public:
	template <PinName Pin>

	[[nodiscard]] static constexpr auto getTxPinData() noexcept {
		auto const iter = *detail::find_if(TX_PIN_TABLE.begin(), TX_PIN_TABLE.end(),

																			 [](auto const& pin_data) { return pin_data[0_ic] == Pin; });

		return std::tuple{iter[1_ic], iter[2_ic], iter[3_ic], iter[4_ic]};
	}

	template <PinName Pin>

	[[nodiscard]] static constexpr auto getRxPinData() noexcept {
		auto const iter = *detail::find_if(RX_PIN_TABLE.begin(), RX_PIN_TABLE.end(),

																			 [](auto const& pin_data) { return pin_data[0_ic] == Pin; });

		return std::tuple{iter[1_ic], iter[2_ic], iter[3_ic], iter[4_ic]};
	}
};

}	 // namespace cpp_stm32::usart
