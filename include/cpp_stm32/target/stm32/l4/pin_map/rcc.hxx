#pragma once

#include <tuple>

#include "cpp_stm32/target/stm32/l4/register/rcc.hxx"

namespace cpp_stm32::rcc {

class ClkRegMap {
 private:
	static constexpr std::tuple PERIPH_CLK_RST_TABLE{
		std::pair{reg::AHB2RST, reg::Ahb2RstBit::GpioARst},
		std::pair{reg::AHB2RST, reg::Ahb2RstBit::GpioBRst},
		/*APB1*/
		std::pair{reg::APB1RST_1, reg::Apb1Rst1Bit::Usart2Rst},
		std::pair{reg::APB1RST_1, reg::Apb1Rst1Bit::PwrRst},
		/*APB2*/
		std::pair{reg::APB2RST, reg::Apb2RstBit::Usart1Rst},

	};

	static constexpr std::tuple PERIPH_CLK_EN_TABLE{
		std::pair{reg::AHB2ENR, reg::Ahb2EnrBit::GpioAEn},
		std::pair{reg::AHB2ENR, reg::Ahb2EnrBit::GpioBEn},
		/*APB1*/
		std::pair{reg::APB1ENR_1, reg::Apb1Enr1Bit::Usart2En},
		std::pair{reg::APB1ENR_1, reg::Apb1Enr1Bit::PwrEn},
		/*APB2*/
		std::pair{reg::APB2ENR, reg::Apb2EnrBit::Usart1En},
	};

	static constexpr std::tuple OSC_ON_TABLE{
		std::pair{reg::CRRCR, reg::CrrCrBit::Hsi48On}, std::pair{reg::CR, reg::CrBit::MsiOn},
		std::pair{reg::CR, reg::CrBit::HsiOn},				 std::pair{reg::CR, reg::CrBit::HseOn},
		std::pair{reg::CR, reg::CrBit::PllOn},				 std::pair{reg::CR, reg::CrBit::PllSaiOn},
	};

	static constexpr std::tuple OSC_RDY_TABLE{
		std::pair{reg::CRRCR, reg::CrrCrBit::Hsi48Rdy}, std::pair{reg::CR, reg::CrBit::MsiRdy},
		std::pair{reg::CR, reg::CrBit::HsiRdy},					std::pair{reg::CR, reg::CrBit::HseRdy},
		std::pair{reg::CR, reg::CrBit::PllRdy},					std::pair{reg::CR, reg::CrBit::PllSaiRdy},
	};

	static constexpr std::tuple EXT_OSC_BYP_TABLE{
		std::pair{reg::CR, reg::CrBit::HseByp},
		std::pair{reg::BDCR, reg::BdcrBit::LseByp},
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
