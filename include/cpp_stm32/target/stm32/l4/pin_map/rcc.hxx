#pragma once

#include <tuple>

#include "cpp_stm32/target/stm32/l4/register/rcc.hxx"

namespace cpp_stm32::rcc {

class ClkRegMap {
 private:
	static constexpr std::tuple PERIPH_CLK_RST_TABLE{
		std::pair{reg::AHB2RSTR, reg::AHB2RSTRField::GPIOARST},
		std::pair{reg::AHB2RSTR, reg::AHB2RSTRField::GPIOBRST},
		/*APB1*/
		std::pair{reg::APB1RSTR1, reg::APB1RSTR1Field::USART2RST},
		std::pair{reg::APB1RSTR1, reg::APB1RSTR1Field::PWRRST},
		/*APB2*/
		std::pair{reg::APB2RSTR, reg::APB2RSTRField::SPI1RST},
		std::pair{reg::APB2RSTR, reg::APB2RSTRField::USART1RST},
	};

	static constexpr std::tuple PERIPH_CLK_EN_TABLE{
		std::pair{reg::AHB2ENR, reg::AHB2ENRField::GPIOAEN},
		std::pair{reg::AHB2ENR, reg::AHB2ENRField::GPIOBEN},
		/*APB1*/
		std::pair{reg::APB1ENR1, reg::APB1ENR1Field::USART2EN},
		std::pair{reg::APB1ENR1, reg::APB1ENR1Field::PWREN},
		/*APB2*/
		std::pair{reg::APB2ENR, reg::APB2ENRField::SPI1EN},
		std::pair{reg::APB2ENR, reg::APB2ENRField::USART1EN},
	};

	static constexpr std::tuple OSC_ON_TABLE{
		std::pair{reg::CRRCR, reg::CRRCRField::HSI48ON}, std::pair{reg::CR, reg::CRField::MSION},
		std::pair{reg::CR, reg::CRField::HSION},				 std::pair{reg::CR, reg::CRField::HSEON},
		std::pair{reg::CR, reg::CRField::PLLON},				 std::pair{reg::CR, reg::CRField::PLLSAI1ON},
	};

	static constexpr std::tuple OSC_RDY_TABLE{
		std::pair{reg::CRRCR, reg::CRRCRField::HSI48RDY}, std::pair{reg::CR, reg::CRField::MSIRDY},
		std::pair{reg::CR, reg::CRField::HSIRDY},					std::pair{reg::CR, reg::CRField::HSERDY},
		std::pair{reg::CR, reg::CRField::PLLRDY},					std::pair{reg::CR, reg::CRField::PLLSAI1RDY},
	};

	static constexpr std::tuple EXT_OSC_BYP_TABLE{
		std::pair{reg::CR, reg::CRField::HSEBYP},
		std::pair{reg::BDCR, reg::BDCRField::LSEBYP},
	};

 public:
	// friend?

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
