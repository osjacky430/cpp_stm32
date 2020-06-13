/**
 * @file  stm32/f4/pin_map/usart.hxx
 * @brief	USART Pin Mapping for stm32f4
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

#include <tuple>

#include "cpp_stm32/common/pin_data.hxx"

#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/detail/tuple.hxx"
#include "cpp_stm32/target/stm32/f4/define/dma.hxx"
#include "cpp_stm32/target/stm32/f4/define/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/define/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/interrupt.hxx"
#include "cpp_stm32/target/stm32/f4/register/usart.hxx"
#include "cpp_stm32/utility/literal_op.hxx"

namespace cpp_stm32::dma {

using UsartDma = PinData<Port, Stream, cpp_stm32::IrqNum, Channel, PeriphAddress_t, DataSize>;

}	 // namespace cpp_stm32::dma

namespace cpp_stm32::usart {

class PinMap {
 private:
	using PinName	 = gpio::PinName;
	using AltFunc	 = gpio::AltFunc;
	using UsartClk = rcc::PeriphClk;

	using UsartPinData = detail::Tuple<PinName, Port, AltFunc, UsartClk, cpp_stm32::IrqNum, dma::UsartDma>;

	static constexpr std::array AF{AltFunc::AF7, AltFunc::AF7, AltFunc::AF7, AltFunc::AF8, AltFunc::AF7, AltFunc::AF8};

	static constexpr std::array RCC{UsartClk::Usart1, UsartClk::Usart2, UsartClk::Usart3,
																	UsartClk::Uart4,	UsartClk::Uart5,	UsartClk::Usart6};

	static constexpr std::array IRQ{IrqNum::Usart1Global, IrqNum::Usart2Global, IrqNum::Usart3Global};

	static constexpr std::array TX_DMA{
		dma::UsartDma{dma::Port::DMA1, dma::Stream::Stream7,
									cpp_stm32::IrqNum::Dma1Stream6Global /*cpp_stm32::IrqNum::Dma2Stream6Global*/, dma::Channel::Channel4,
									dma::PeriphAddress_t{usart::reg::DR<Port::Usart1>.memoryAddr()}, dma::DataSize::Byte},
		dma::UsartDma{dma::Port::DMA1, dma::Stream::Stream6, cpp_stm32::IrqNum::Dma1Stream6Global, dma::Channel::Channel4,
									dma::PeriphAddress_t{usart::reg::DR<Port::Usart2>.memoryAddr()}, dma::DataSize::Byte},
	};

	static constexpr std::array RX_DMA{
		dma::UsartDma{dma::Port::DMA2, dma::Stream::Stream7,
									cpp_stm32::IrqNum::Dma1Stream6Global /*cpp_stm32::IrqNum::Dma2Stream7Global*/, dma::Channel::Channel5,
									dma::PeriphAddress_t{usart::reg::DR<Port::Usart1>.memoryAddr()}, dma::DataSize::Byte},
		dma::UsartDma{dma::Port::DMA1, dma::Stream::Stream5, cpp_stm32::IrqNum::Dma1Stream5Global, dma::Channel::Channel4,
									dma::PeriphAddress_t{usart::reg::DR<Port::Usart2>.memoryAddr()}, dma::DataSize::Byte},
	};

	static constexpr auto SET_USART_TX_DATA = [](PinName t_pin, Port t_port) {
		auto const idx = to_underlying(t_port);
		return UsartPinData{t_pin, t_port, AF[idx], RCC[idx], IRQ[idx], TX_DMA[idx]};
	};

	static constexpr auto SET_USART_RX_DATA = [](PinName t_pin, Port t_port) {
		auto const idx = to_underlying(t_port);
		return UsartPinData{t_pin, t_port, AF[idx], RCC[idx], IRQ[idx], RX_DMA[idx]};
	};

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

		return RETURN_PIN_DATA(iter, detail::IdxRange<1, 4>{});
	}

	template <PinName Pin>
	[[nodiscard]] static constexpr auto getRxPinData() noexcept {
		constexpr auto iter = *detail::find_if(RX_PIN_TABLE.begin(), RX_PIN_TABLE.end(), PREDICATE<Pin>);

		return RETURN_PIN_DATA(iter, detail::IdxRange<1, 4>{});
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
