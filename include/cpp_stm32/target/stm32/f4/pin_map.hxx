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

#include <array>

#include "cpp_stm32/common/pin_data.hxx"

#include "cpp_stm32/utility/literal_op.hxx"

#include "cpp_stm32/target/stm32/f4/dma.hxx"
#include "cpp_stm32/target/stm32/f4/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/interrupt.hxx"
#include "cpp_stm32/target/stm32/f4/memory/rcc_reg.hxx"
#include "cpp_stm32/target/stm32/f4/memory/usart_reg.hxx"

#define SET_USART_TX_DATA(pinname, usart) \
	UsartPinData { pinname, usart, AF<usart>, RCC<usart>, IRQ<usart>, TX_DMA<usart> }

#define SET_USART_RX_DATA(pinname, usart) \
	UsartPinData { pinname, usart, AF<usart>, RCC<usart>, IRQ<usart>, RX_DMA<usart> }

namespace cpp_stm32::dma {

using DmaData = PinData<Port, Stream, Channel, PeriphAddress_t>;

}	 // namespace cpp_stm32::dma

namespace cpp_stm32::usart {

class PinMap {
 private:
	using PinName = gpio::PinName;

	using UsartPinData = PinData<PinName, Port, gpio::AltFunc, rcc::PeriphClk, IrqNum, dma::DmaData>;

	template <Port USART>
	static constexpr auto AF = []() {
		if constexpr (USART == Port::Usart1 || USART == Port::Usart2 || USART == Port::Usart3 || USART == Port::Uart5) {
			return gpio::AltFunc::AF7;
		} else {
			return gpio::AltFunc::AF8;
		}
	}();

	template <Port USART>
	static constexpr auto RCC = []() {
		switch (USART) {
			case Port::Usart1:
				return rcc::PeriphClk::Usart1;
			case Port::Usart2:
				return rcc::PeriphClk::Usart2;
			case Port::Usart3:
				// return rcc::PeriphClk::Usart3;
			case Port::Uart4:
				// return rcc::PeriphClk::Uart4;
			case Port::Uart5:
				// return rcc::PeriphClk::Usart5;
			case Port::Usart6:
				return rcc::PeriphClk::Usart6;
		}
	}();

	template <Port USART>
	static constexpr auto IRQ = []() {
		switch (USART) {
			case Port::Usart1:
				return IrqNum::Usart1Global;
			case Port::Usart2:
				return IrqNum::Usart2Global;
			case Port::Usart3:
				return IrqNum::Usart3Global;
			case Port::Uart4:
				// return IrqNum::Uart4Global;
			case Port::Uart5:
				// return IrqNum::Uart5Global
			case Port::Usart6:
				// return IrqNum::Usart6Global
				break;
		}
	}();

	template <Port USART>
	static constexpr auto TX_DMA = []() {
		switch (USART) {
			case Port::Usart1:
				break;
			case Port::Usart2:
				return dma::DmaData{dma::Port::DMA1, dma::Stream::Stream6, dma::Channel::Channel4,
														dma::PeriphAddress_t{usart::reg::DR<USART>.memoryAddr()}};
		}
	}();

	template <Port USART>
	static constexpr auto RX_DMA = []() {
		switch (USART) {
			case Port::Usart1:
				break;
			case Port::Usart2:
				return dma::DmaData{dma::Port::DMA1, dma::Stream::Stream5, dma::Channel::Channel4,
														dma::PeriphAddress_t{usart::reg::DR<USART>.memoryAddr()}};
		}
	}();

	// @todo refine it, does this table contain too much information(?)
	static constexpr std::array TX_PIN_TABLE{
		SET_USART_TX_DATA(PinName::PA_2, Port::Usart2),
	};

	static constexpr std::array RX_PIN_TABLE{
		SET_USART_RX_DATA(PinName::PA_3, Port::Usart2),
	};

	template <PinName Pin>
	static constexpr auto PREDICATE = [](auto const& t_pin_data) { return t_pin_data[0_ic] == Pin; };

	template <std::size_t... Idx>
	static constexpr auto RETURN_PIN_DATA(UsartPinData const& iter, std::index_sequence<Idx...> const&) {
		return std::tuple{iter[size_c<Idx>{}]...};
	}

 public:
	template <PinName Pin>
	[[nodiscard]] static constexpr auto getTxPinData() noexcept {
		constexpr auto iter = *detail::find_if(TX_PIN_TABLE.begin(), TX_PIN_TABLE.end(), PREDICATE<Pin>);

		return RETURN_PIN_DATA(iter, detail::Interval<1, 4>{});
	}

	template <PinName Pin>
	[[nodiscard]] static constexpr auto getRxPinData() noexcept {
		constexpr auto iter = *detail::find_if(RX_PIN_TABLE.begin(), RX_PIN_TABLE.end(), PREDICATE<Pin>);

		return RETURN_PIN_DATA(iter, detail::Interval<1, 4>{});
	}

	template <PinName Pin>
	[[nodiscard]] static constexpr auto getTxDmaData() noexcept {
		constexpr auto iter = *detail::find_if(TX_PIN_TABLE.begin(), TX_PIN_TABLE.end(), PREDICATE<Pin>);

		return RETURN_PIN_DATA(iter, std::index_sequence<5>{});
	}

	template <PinName Pin>
	[[nodiscard]] static constexpr auto getRxDmaData() noexcept {
		constexpr auto iter = *detail::find_if(RX_PIN_TABLE.begin(), RX_PIN_TABLE.end(), PREDICATE<Pin>);

		return RETURN_PIN_DATA(iter, std::index_sequence<5>{});
	}
};

}	 // namespace cpp_stm32::usart

namespace cpp_stm32::gpio {

class PinMap {
 private:
	using PortPinPair = PinData<Port, Pin>;
	/**
	 * @var 		PIN_NAME_TABLE
	 * @brief
	 *
	 */
	static constexpr auto PinTable = []() {
		std::array<PortPinPair, to_underlying(PinName::Total)> temp{};

		temp[to_underlying(PinName::PA_1)] = PortPinPair{Port::PortA, Pin::Pin1};
		temp[to_underlying(PinName::PA_2)] = PortPinPair{Port::PortA, Pin::Pin2};
		temp[to_underlying(PinName::PA_3)] = PortPinPair{Port::PortA, Pin::Pin3};
		temp[to_underlying(PinName::PA_5)] = PortPinPair{Port::PortA, Pin::Pin5};

		temp[to_underlying(PinName::PB_1)] = PortPinPair{Port::PortB, Pin::Pin1};
		temp[to_underlying(PinName::PB_2)] = PortPinPair{Port::PortB, Pin::Pin2};
		temp[to_underlying(PinName::PB_3)] = PortPinPair{Port::PortB, Pin::Pin3};

		return temp;
	}();

 public:
	[[nodiscard]] static constexpr auto getPort(PinName const& t_pin_name) noexcept {
		return PinTable[to_underlying(t_pin_name)][0_ic];
	}

	[[nodiscard]] static constexpr auto getPin(PinName const& t_pin_name) noexcept {
		return PinTable[to_underlying(t_pin_name)][1_ic];
	}
};

}	 // namespace cpp_stm32::gpio

namespace cpp_stm32::rcc {

class ClkRegMap {
 private:
	static constexpr std::tuple PERIPH_CLK_RST_TABLE{
		/*AHB1*/
		std::pair{reg::AHB1RST, reg::Ahb1RstBit::GpioARst},
		std::pair{reg::AHB1RST, reg::Ahb1RstBit::GpioBRst},

		std::pair{reg::AHB1RST, reg::Ahb1RstBit::Dma1Rst},
		std::pair{reg::AHB1RST, reg::Ahb1RstBit::Dma2Rst},
		/*APB1*/
		std::pair{reg::APB1RST, reg::Apb1RstBit::Usart2Rst},
		std::pair{reg::APB1RST, reg::Apb1RstBit::PwrRst},
		/*APB2*/
		std::pair{reg::APB2RST, reg::Apb2RstBit::Usart1Rst},
	};

	static constexpr std::tuple PERIPH_CLK_EN_TABLE{
		/*AHB1*/
		std::pair{reg::AHB1ENR, reg::Ahb1EnrBit::GpioAEn},
		std::pair{reg::AHB1ENR, reg::Ahb1EnrBit::GpioBEn},

		std::pair{reg::AHB1ENR, reg::Ahb1EnrBit::Dma1En},
		std::pair{reg::AHB1ENR, reg::Ahb1EnrBit::Dma2En},
		/*APB1*/
		std::pair{reg::APB1ENR, reg::Apb1EnrBit::Usart2En},
		std::pair{reg::APB1ENR, reg::Apb1EnrBit::PwrEn},
		/*APB2*/
		std::pair{reg::APB2ENR, reg::Apb2EnrBit::Usart1En},
	};

	static constexpr std::tuple OSC_ON_TABLE{
		std::pair{reg::CR, reg::CrBit::HsiOn},
		std::pair{reg::CR, reg::CrBit::HseOn},
		std::pair{reg::CR, reg::CrBit::PllOn},
		std::pair{reg::CR, reg::CrBit::PllSaiOn},
	};

	static constexpr std::tuple OSC_RDY_TABLE{
		std::pair{reg::CR, reg::CrBit::HsiRdy},
		std::pair{reg::CR, reg::CrBit::HseRdy},
		std::pair{reg::CR, reg::CrBit::PllRdy},
		std::pair{reg::CR, reg::CrBit::PllSaiRdy},
	};

	static constexpr std::tuple EXT_OSC_BYP_TABLE{
		std::pair{reg::CR, reg::CrBit::HseByp},
		std::pair{reg::BDCR, reg::BdcrBit::LseByp},
	};

 public:
	template <PeriphClk PeriphClk>
	[[nodiscard]] static constexpr auto getPeriphEnReg() noexcept {
		return std::get<to_underlying(PeriphClk)>(PERIPH_CLK_EN_TABLE);
	}

	template <PeriphClk PeriphClk>
	[[nodiscard]] static constexpr auto getPeriphRstReg() noexcept {
		return std::get<to_underlying(PeriphClk)>(PERIPH_CLK_RST_TABLE);
	}

	template <ClkSrc Clk>
	[[nodiscard]] static constexpr auto const getOscOnReg() noexcept {
		return std::get<to_underlying(Clk)>(OSC_ON_TABLE);
	}

	template <ClkSrc Clk>
	[[nodiscard]] static constexpr auto const getOscRdyReg() noexcept {
		return std::get<to_underlying(Clk)>(OSC_RDY_TABLE);
	}

	template <ClkSrc Clk>
	[[nodiscard]] static constexpr auto const& getExtBypassReg() noexcept {
		static_assert(is_ext_clk<Clk>);
		if constexpr (Clk == ClkSrc::Hse) {
			return std::get<0>(EXT_OSC_BYP_TABLE);
		} else if constexpr (Clk == ClkSrc::Lse) {
			return std::get<1>(EXT_OSC_BYP_TABLE);
		}
	}
};

}	 // namespace cpp_stm32::rcc
