/**
 * @Date:   2019-11-29T20:17:17+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: digitalout.hpp
 */

#ifndef DIGITAL_OUT_HPP_
#define DIGITAL_OUT_HPP_

#include <array>
#include <tuple>
#include <type_traits>
#include <utility>

#include "include/driver/gpio_base.hpp"
#include "include/driver/utility.hpp"

#include "include/hal/gpio.hxx"
#include "include/hal/peripheral/rcc.hxx"

template <PinName... PinNames>
class DigitalOut : public GpioBase<PinNames...> {
 private:
	// tuple of tuple
	static constexpr auto gpioGroupList = GpioBase<PinNames...>::makeGpioGroupList();

	// this is basically the same as the num of port
	static constexpr auto gpioGroupListNum = std::tuple_size<decltype(gpioGroupList)>::value;

	using PinGrouper					= PinGroupingHelper<PinNames...>;
	using GpioGroupListIdxSeq = std::make_index_sequence<gpioGroupListNum>;

	template <std::size_t Idx>
	using GpioGroupTupType = std::decay_t<decltype(std::get<Idx>(gpioGroupList))>;

	template <std::size_t Idx>
	static constexpr auto GpioGroupTupElemNum = std::tuple_size<GpioGroupTupType<Idx>>::value;

	template <std::size_t Idx>
	static constexpr auto GpioGroupTupIdxSeq = std::make_index_sequence<GpioGroupTupElemNum<Idx>>{};

	template <std::size_t Num, std::size_t... Idx>
	static constexpr void modeSetupIdxThruPin(ConstIndexType<Num> /*unused*/,
																						std::index_sequence<Idx...> /*unused*/) noexcept {
		constexpr auto gpio_port			= PinGrouper::getPort(ConstIndexType<Num>{});
		constexpr auto gpio_pin_group = std::get<Num>(gpioGroupList);
		gpio_mode_setup<gpio_port, std::get<Idx>(gpio_pin_group)...>(GpioMode::Output, GpioPupd::None);
	}

	template <std::size_t... Idx>
	static constexpr void modeSetupIdxThruPort(std::index_sequence<Idx...> /*unused*/) noexcept {
		(modeSetupIdxThruPin(ConstIndexType<Idx>{}, GpioGroupTupIdxSeq<Idx>), ...);
	}

	template <typename Tuple, std::size_t... Idx>
	static constexpr void toggleImp(Tuple const tup, std::index_sequence<Idx...>) noexcept {
		constexpr auto gpio_toggle_for_gpio_group = [](const auto t_tup, const auto num) constexpr noexcept {
			const auto param_list = std::tuple_cat(std::make_tuple(PinGrouper::getPort(num)), std::get<num()>(t_tup));

			std::apply([](auto&&... args) { gpio_toggle(std::forward<decltype(args)>(args)...); }, param_list);
		};

		(gpio_toggle_for_gpio_group(tup, ConstIndexType<Idx>{}), ...);
	}

 public:
	constexpr DigitalOut() {
		// enable rcc
		GpioBase<PinNames...>::enableAllGpioClk();

		// setup mode
		modeSetup();
	}

	static constexpr void modeSetup() noexcept { modeSetupIdxThruPort(GpioGroupListIdxSeq{}); }

	static constexpr void toggle() noexcept { toggleImp(gpioGroupList, GpioGroupListIdxSeq{}); }
};

#endif	// DIGITAL_OUT_HPP_
