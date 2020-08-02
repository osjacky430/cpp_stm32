// #define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "catch2/catch.hpp"
#include "cpp_stm32/utility/literal_op.hxx"
#include "sys_init.hxx"

TEST_CASE("Calculate RCC PLL division factor", "[RccPllDivFac]") {
	using cpp_stm32::operator"" _MHz;

	constexpr auto HSE_CLK_FREQUENCY = 8_MHz;
	constexpr auto SYS_CLK_FREQUENCY = 180_MHz;
	constexpr auto pll_div_factors	 = cpp_stm32::sys::calc_pll_div_factor(HSE_CLK_FREQUENCY, SYS_CLK_FREQUENCY);

	constexpr auto pllm = std::get<0>(pll_div_factors);
	constexpr auto plln = std::get<1>(pll_div_factors);
	constexpr auto pllp = std::get<2>(pll_div_factors);
	constexpr auto pllq = std::get<3>(pll_div_factors);
	constexpr auto pllr = std::get<4>(pll_div_factors);

	STATIC_REQUIRE(pllm == 4);
	STATIC_REQUIRE(plln == 180);
	STATIC_REQUIRE(pllp == 2);
	STATIC_REQUIRE(pllq == 2);
	STATIC_REQUIRE(pllr == 2);
}

TEST_CASE("Calculate RCC AHB division factor", "[RccAHBDivFac]") {
	using cpp_stm32::operator"" _MHz;

	constexpr auto SYS_CLK_FREQUENCY	= 180_MHz;
	constexpr auto AHB_CLK_FREQUENCY	= 180_MHz;
	constexpr auto APB2_CLK_FREQUENCY = 90_MHz;
	constexpr auto APB1_CLK_FREQUENCY = 45_MHz;

	constexpr auto advance_bus_div_factor = cpp_stm32::sys::calc_advance_bus_div_factor(
		SYS_CLK_FREQUENCY, AHB_CLK_FREQUENCY, APB1_CLK_FREQUENCY, APB2_CLK_FREQUENCY);

	constexpr auto hpre	 = std::get<0>(advance_bus_div_factor);
	constexpr auto ppre1 = std::get<1>(advance_bus_div_factor);
	constexpr auto ppre2 = std::get<2>(advance_bus_div_factor);

	STATIC_REQUIRE(hpre == 1);
	STATIC_REQUIRE(ppre1 == 4);
	STATIC_REQUIRE(ppre2 == 2);
}