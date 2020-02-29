/**
 * @file  stm32/pin_map/rcc.hxx
 * @brief	Header that include rcc pin map information
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
#include <utility>

#include "cpp_stm32/target/stm32/f4/define/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/register/rcc.hxx"

namespace cpp_stm32::rcc {

class ClkRegMap {
 private:
	static constexpr std::tuple PERIPH_CLK_RST_TABLE{
		/*AHB1*/
		std::pair{reg::AHB1RST, reg::Ahb1RstBit::GpioARst},
		std::pair{reg::AHB1RST, reg::Ahb1RstBit::GpioBRst},
		std::pair{reg::AHB1RST, reg::Ahb1RstBit::GpioCRst},

		std::pair{reg::AHB1RST, reg::Ahb1RstBit::Dma1Rst},
		std::pair{reg::AHB1RST, reg::Ahb1RstBit::Dma2Rst},
		/*APB1*/
		std::pair{reg::APB1RST, reg::Apb1RstBit::Spi2Rst},
		std::pair{reg::APB1RST, reg::Apb1RstBit::Spi3Rst},
		std::pair{reg::APB1RST, reg::Apb1RstBit::Usart2Rst},
		std::pair{reg::APB1RST, reg::Apb1RstBit::Usart3Rst},
		std::pair{reg::APB1RST, reg::Apb1RstBit::Uart4Rst},
		std::pair{reg::APB1RST, reg::Apb1RstBit::Uart5Rst},
		std::pair{reg::APB1RST, reg::Apb1RstBit::I2c1Rst},
		std::pair{reg::APB1RST, reg::Apb1RstBit::I2c2Rst},
		std::pair{reg::APB1RST, reg::Apb1RstBit::I2c3Rst},

		std::pair{reg::APB1RST, reg::Apb1RstBit::PwrRst},
		/*APB2*/
		std::pair{reg::APB2RST, reg::Apb2RstBit::Usart1Rst},
		std::pair{reg::APB2RST, reg::Apb2RstBit::Usart6Rst},
		std::pair{reg::APB2RST, reg::Apb2RstBit::SysCfgRst},
	};

	static constexpr std::tuple PERIPH_CLK_EN_TABLE{
		/*AHB1*/
		std::pair{reg::AHB1ENR, reg::Ahb1EnrBit::GpioAEn},
		std::pair{reg::AHB1ENR, reg::Ahb1EnrBit::GpioBEn},
		std::pair{reg::AHB1ENR, reg::Ahb1EnrBit::GpioCEn},

		std::pair{reg::AHB1ENR, reg::Ahb1EnrBit::Dma1En},
		std::pair{reg::AHB1ENR, reg::Ahb1EnrBit::Dma2En},
		/*APB1*/
		std::pair{reg::APB1ENR, reg::Apb1EnrBit::Spi2En},
		std::pair{reg::APB1ENR, reg::Apb1EnrBit::Spi3En},
		std::pair{reg::APB1ENR, reg::Apb1EnrBit::Usart2En},
		std::pair{reg::APB1ENR, reg::Apb1EnrBit::Usart3En},
		std::pair{reg::APB1ENR, reg::Apb1EnrBit::Uart4En},
		std::pair{reg::APB1ENR, reg::Apb1EnrBit::Uart5En},
		std::pair{reg::APB1ENR, reg::Apb1EnrBit::I2c1En},
		std::pair{reg::APB1ENR, reg::Apb1EnrBit::I2c2En},
		std::pair{reg::APB1ENR, reg::Apb1EnrBit::I2c3En},

		std::pair{reg::APB1ENR, reg::Apb1EnrBit::PwrEn},
		/*APB2*/
		std::pair{reg::APB2ENR, reg::Apb2EnrBit::Usart1En},
		std::pair{reg::APB2ENR, reg::Apb2EnrBit::Usart6En},
		std::pair{reg::APB2ENR, reg::Apb2EnrBit::SysCfgEn},
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
	[[nodiscard]] static constexpr auto getOscOnReg() noexcept {
		return std::get<to_underlying(Clk)>(OSC_ON_TABLE);
	}

	template <ClkSrc Clk>
	[[nodiscard]] static constexpr auto getOscRdyReg() noexcept {
		return std::get<to_underlying(Clk)>(OSC_RDY_TABLE);
	}

	template <ClkSrc Clk>
	[[nodiscard]] static constexpr auto getExtBypassReg() noexcept {
		static_assert(is_ext_clk<Clk>);
		if constexpr (Clk == ClkSrc::Hse) {
			return std::get<0>(EXT_OSC_BYP_TABLE);
		} else if constexpr (Clk == ClkSrc::Lse) {
			return std::get<1>(EXT_OSC_BYP_TABLE);
		}
	}
};

}	 // namespace cpp_stm32::rcc
