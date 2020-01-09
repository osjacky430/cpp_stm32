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

#include "cpp_stm32/target/stm32/common/rcc.hxx"
#include "cpp_stm32/target/stm32/l4/memory/rcc_reg.hxx"

namespace cpp_stm32::stm32::l4 {

enum class RccPeriph : std::uint32_t {
	/*AHB1*/
	GpioA,
	GpioB,
	/*GpioC ~ GpioF*/

	/*APB1*/
	Usart2,
	Pwr,

	/*APB2*/
	Usart1,

};

class RccRegTable {
 private:
	static constexpr std::tuple RccPeriphRst{
		/*AHB1*/
		std::pair{RCC_AHB2RST, RccAhb2RstBit::GpioARst}, std::pair{RCC_AHB2RST, RccAhb2RstBit::GpioBRst},
		/*APB1*/
		// std::pair{RCC_APB1RST, RccApb1RstBit::Usart2Rst},
		// std::pair{RCC_APB1RST, RccApb1RstBit::PwrRst},
		/*APB2*/
		// std::pair{RCC_APB2RST, RccApb2RstBit::Usart1Rst},
	};

	static constexpr std::tuple RccPeriphEn{
		/*AHB1*/
		std::pair{RCC_AHB2ENR, RccAhb2EnrBit::GpioAEn}, std::pair{RCC_AHB2ENR, RccAhb2EnrBit::GpioBEn},
		/*APB1*/
		// std::pair{RCC_APB1ENR, RccApb1EnrBit::Usart2En},
		// std::pair{RCC_APB1ENR, RccApb1EnrBit::PwrEn},
		/*APB2*/
		// std::pair{RCC_APB2ENR, RccApb2EnrBit::Usart1En},
	};

	// static constexpr std::tuple RccOscOn{
	// 	std::pair{RCC_CR, RccCrBit::HsiOn},
	// 	std::pair{RCC_CR, RccCrBit::HseOn},
	// 	std::pair{RCC_CR, RccCrBit::PllOn},
	// 	std::pair{RCC_CR, RccCrBit::PllSaiOn},
	// };

	// static constexpr std::tuple RccOscRdy{
	// 	std::pair{RCC_CR, RccCrBit::HsiRdy},
	// 	std::pair{RCC_CR, RccCrBit::HseRdy},
	// 	std::pair{RCC_CR, RccCrBit::PllRdy},
	// 	std::pair{RCC_CR, RccCrBit::PllSaiRdy},
	// };

	// static constexpr std::tuple ExtBypass{
	// 	std::pair{RCC_CR, RccCrBit::HseByp},
	// 	std::pair{RCC_BDCR, RccBdcrBit::LseByp},
	// };

 public:
	template <RccPeriph PeriphClk>
	[[nodiscard]] static constexpr auto getPeriphEnReg() noexcept {
		return std::get<to_underlying(PeriphClk)>(RccPeriphEn);
	}

	template <RccPeriph PeriphClk>
	[[nodiscard]] static constexpr auto getPeriphRstReg() noexcept {
		return std::get<to_underlying(PeriphClk)>(RccPeriphRst);
	}

	// template <RccOsc Clk>
	// [[nodiscard]] static constexpr auto const getOscOnReg() noexcept {
	// 	return std::get<to_underlying(Clk)>(RccOscOn);
	// }

	// template <RccOsc Clk>
	// [[nodiscard]] static constexpr auto const getOscRdyReg() noexcept {
	// 	return std::get<to_underlying(Clk)>(RccOscRdy);
	// }

	// template <RccOsc Clk>
	// [[nodiscard]] static constexpr auto const& getExtBypassReg(ExtClk<Clk> const) noexcept {
	// 	if constexpr (Clk == RccOsc::HseOsc) {
	// 		return std::get<0>(ExtBypass);
	// 	} else if constexpr (Clk == RccOsc::LseOsc) {
	// 		return std::get<1>(ExtBypass);
	// 	}
	// }
};

template <RccPeriph PeriphClk>
static constexpr void rcc_enable_periph_clk() noexcept {
	detail::rcc_enable_periph_clk_impl<RccRegTable, RccPeriph, PeriphClk>();
}

template <RccPeriph PeriphClk>
static constexpr void rcc_reset_periph_clk() noexcept {
	detail::rcc_reset_periph_clk_impl<RccRegTable, RccPeriph, PeriphClk>();
}

}	 // namespace cpp_stm32::stm32::l4
