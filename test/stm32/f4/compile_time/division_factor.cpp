// #define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "catch2/catch.hpp"
#include "cpp_stm32/utility/literal_op.hxx"
#include "sys_init.hxx"

// make test independent of sys_info.hpp
TEST_CASE("Calculate RCC PLL division factor", "[RccPllDivFac]") {
	using cpp_stm32::operator"" _MHz;

	constexpr auto HSE_CLK_FREQUENCY = 8_MHz;
	constexpr auto SYS_CLK_FREQUENCY = 180_MHz;
	constexpr auto pll_div_factors	 = cpp_stm32::sys::CALC_PLL_DIV_FACTOR(HSE_CLK_FREQUENCY, SYS_CLK_FREQUENCY);

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
