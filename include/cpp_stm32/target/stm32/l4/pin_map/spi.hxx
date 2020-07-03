#pragma once

#include "cpp_stm32/detail/tuple.hxx"
#include "cpp_stm32/target/stm32/l4/define/gpio.hxx"
#include "cpp_stm32/target/stm32/l4/define/rcc.hxx"
#include "cpp_stm32/target/stm32/l4/define/spi.hxx"
#include "cpp_stm32/target/stm32/l4/interrupt.hxx"

namespace cpp_stm32::spi {
class PinMap {
 private:
	using PinData = detail::Tuple<gpio::PinName, Port, gpio::AltFunc, rcc::PeriphClk, IrqNum>;

	static constexpr std::array MISO_TABLE{
		PinData{gpio::PinName::PA_6, Port::SPI1, gpio::AltFunc::AF5, rcc::PeriphClk::Spi1, IrqNum::Spi1Global},
		PinData{gpio::PinName::PA_11, Port::SPI1, gpio::AltFunc::AF5, rcc::PeriphClk::Spi1, IrqNum::Spi1Global},
	};

	static constexpr std::array MOSI_TABLE{
		PinData{gpio::PinName::PA_7, Port::SPI1, gpio::AltFunc::AF5, rcc::PeriphClk::Spi1, IrqNum::Spi1Global},
		PinData{gpio::PinName::PA_12, Port::SPI1, gpio::AltFunc::AF5, rcc::PeriphClk::Spi1, IrqNum::Spi1Global},
	};

	static constexpr std::array SCLK_TABLE{
		PinData{gpio::PinName::PA_1, Port::SPI1, gpio::AltFunc::AF5, rcc::PeriphClk::Spi1, IrqNum::Spi1Global},
		PinData{gpio::PinName::PA_5, Port::SPI1, gpio::AltFunc::AF5, rcc::PeriphClk::Spi1, IrqNum::Spi1Global},
	};

	template <gpio::PinName Pin, Port SPI>
	static constexpr auto CHECK_PORT_AND_PIN =
		[](auto const t_val) { return detail::get<0>(t_val) == Pin && detail::get<1>(t_val) == SPI; };

 public:
	template <gpio::PinName MISO, gpio::PinName MOSI, gpio::PinName SCLK>
	[[nodiscard]] static constexpr auto getSpiPinData() noexcept {
		constexpr auto miso = *detail::find_if(MISO_TABLE.begin(), MISO_TABLE.end(),
																					 [](auto const t_val) { return detail::get<0>(t_val) == MISO; });

		constexpr auto spi_port = detail::get<1>(miso);
		constexpr auto mosi = *detail::find_if(MOSI_TABLE.begin(), MOSI_TABLE.end(), CHECK_PORT_AND_PIN<MOSI, spi_port>);
		constexpr auto sclk = *detail::find_if(SCLK_TABLE.begin(), SCLK_TABLE.end(), CHECK_PORT_AND_PIN<SCLK, spi_port>);

		return std::tuple{detail::to_std_tuple(miso), detail::to_std_tuple(mosi), detail::to_std_tuple(sclk)};
	}
};
}	// namespace cpp_stm32::spi
