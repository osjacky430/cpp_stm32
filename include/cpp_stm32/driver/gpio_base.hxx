/**
 * @Date:   2019-12-06T12:48:41+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: gpio_base.hpp
 */

#ifndef GPIO_BASE_HPP_
#define GPIO_BASE_HPP_

#include <algorithm>
#include <tuple>

#include "cpp_stm32/utility/utility.hxx"

// @todo add hal gpio.hxx for unified interface
#include "cpp_stm32/target/stm32/f4/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/pin_map.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"

/**
 * [genPortList description]
 * @param  [name] [description]
 * @return        [description]
 */
template <PinName... PinNames>
class PinGroupingHelper {
 private:
	template <std::size_t... Idx>
	static constexpr auto genPortList(std::index_sequence<Idx...> const& /*unused*/) noexcept {
		auto port_list = std::array{PinNameMap::getPortFromPinMap(PIN_NAME_LIST[Idx])...};
		std::array<GpioPort, PORT_NUM> result_port_list{};
		cstd::unique_copy(port_list.begin(), port_list.end(), result_port_list.begin(),
											[](auto const& lhs, auto const& rhs) { return lhs == rhs; });
		return result_port_list;
	}

	template <std::size_t... Idx>
	static constexpr auto genPinList(std::index_sequence<Idx...> const& /*unused*/) noexcept {
		return std::array{PinNameMap::getPinFromPinMap(PIN_NAME_LIST[Idx])...};
	}

	static constexpr auto calcPortNum() noexcept {
		auto port_list = std::array{PinNameMap::getPortFromPinMap(PinNames)...};
		cstd::sort(port_list, [](auto rhs, auto lhs) { return (to_underlying(rhs) < to_underlying(lhs)); });
		return cstd::unique(port_list.begin(), port_list.end()) - port_list.begin();
	}

	static constexpr auto PORT_NUM = calcPortNum();

	static constexpr auto PIN_NAME_LIST = []() {
		auto pin_name_list = std::array{PinNames...};
		cstd::sort(pin_name_list,
							 [](auto const& lhs, auto const& rhs) { return (to_underlying(lhs) < to_underlying(rhs)); });
		return pin_name_list;
	}();

	using IdxThruPinNameList = std::make_index_sequence<sizeof...(PinNames)>;

	static constexpr auto PORT_LIST = genPortList(IdxThruPinNameList{});
	static constexpr auto PIN_LIST	= genPinList(IdxThruPinNameList{});

	template <std::size_t PortIdx, std::size_t... PinIdx>
	static constexpr auto groupPinByPort(ConstIndexType<PortIdx> const& /*unused*/,
																			 std::index_sequence<PinIdx...> const& /*unused*/) noexcept {
		constexpr auto IterateThruPins = [](const auto t_pin_idx) noexcept {
			if constexpr (constexpr auto pin_name = std::get<t_pin_idx()>(PIN_NAME_LIST);
										getPort(ConstIndexType<PortIdx>{}) == PinNameMap::getPortFromPinMap(pin_name)) {
				return std::tuple{PinNameMap::getPinFromPinMap(pin_name)};
			} else {
				return std::tuple{};
			}
		};

		return std::tuple_cat(IterateThruPins(ConstIndexType<PinIdx>{})...);
	}

	template <std::size_t... Idx>
	static constexpr auto makeGpioGroupListImp(std::index_sequence<Idx...> const& /*unused*/) noexcept {
		constexpr auto IterateThruPorts = [](const auto t_port_iter) {
			using IdxThruPin = std::make_index_sequence<sizeof...(PinNames)>;
			return groupPinByPort(t_port_iter, IdxThruPin{});
		};

		return std::make_tuple(IterateThruPorts(ConstIndexType<Idx>{})...);
	}

	static constexpr auto makeGpioGroupList() noexcept { return makeGpioGroupListImp(IdxThruPort{}); }

 public:
	using IdxThruPort = std::make_index_sequence<PORT_NUM>;

	template <std::size_t N>
	[[nodiscard]] static constexpr auto getPort(ConstIndexType<N>) noexcept {
		return std::get<N>(PORT_LIST);
	}

	template <std::size_t N>
	[[nodiscard]] static constexpr auto getPin(ConstIndexType<N>) noexcept {
		return std::get<N>(PIN_LIST);
	}

	[[nodiscard]] static constexpr auto getPortNum() noexcept { return PORT_NUM; }

	static constexpr auto GPIO_GROUP_LIST = makeGpioGroupList();
};

template <PinName... PinNames>
class GpioUtil {
 private:
	using PinGrouper	= PinGroupingHelper<PinNames...>;
	using IdxThruPort = typename PinGrouper::IdxThruPort;

	template <std::size_t Idx>
	using GpioGroupTupType = std::decay_t<decltype(std::get<Idx>(PinGrouper::GPIO_GROUP_LIST))>;

	template <std::size_t Idx>
	static constexpr auto GpioGroupTupElemNum = std::tuple_size_v<GpioGroupTupType<Idx>>;

	template <std::size_t Idx>
	static constexpr auto GpioGroupTupIdxSeq = std::make_index_sequence<GpioGroupTupElemNum<Idx>>{};

	/**
	 * [modeSetupIdxThruPin description]
	 * @param ConstIndexType<Num> [description]
	 * @param [name]              [description]
	 */
	template <std::size_t Num, std::size_t... Idx>
	static constexpr void modeSetupIdxThruPin(ConstIndexType<Num> const& /*unused*/,
																						std::index_sequence<Idx...> const& /*unused*/, GpioMode const& t_mode,
																						GpioPupd const& t_pupd) noexcept {
		constexpr auto gpio_port			= PinGrouper::getPort(ConstIndexType<Num>{});
		constexpr auto gpio_pin_group = std::get<Num>(PinGrouper::GPIO_GROUP_LIST);
		gpio_mode_setup<gpio_port, std::get<Idx>(gpio_pin_group)...>(t_mode, t_pupd);
	}

	/**
	 * [modeSetupIdxThruPort description]
	 * @param [name] [description]
	 */
	template <std::size_t... Idx>
	static constexpr void modeSetupIdxThruPort(std::index_sequence<Idx...> const& /*unused*/, GpioMode const& t_mode,
																						 GpioPupd const& t_pupd) noexcept {
		(modeSetupIdxThruPin(ConstIndexType<Idx>{}, GpioGroupTupIdxSeq<Idx>, t_mode, t_pupd), ...);
	}

	/**
	 * [toggleIdxThruPin description]
	 * @param ConstIndexType<Num> [description]
	 * @param [name]              [description]
	 */
	template <std::size_t Num, std::size_t... Idx>
	static constexpr void toggleIdxThruPin(ConstIndexType<Num> /*unused*/,
																				 std::index_sequence<Idx...> /*unused*/) noexcept {
		constexpr auto gpio_port			= PinGrouper::getPort(ConstIndexType<Num>{});
		constexpr auto gpio_pin_group = std::get<Num>(PinGrouper::GPIO_GROUP_LIST);
		gpio_toggle<gpio_port, std::get<Idx>(gpio_pin_group)...>();
	}

	/**
	 * [toggleIdxThruPort description]
	 * @param [name] [description]
	 */
	template <std::size_t... Idx>
	static constexpr void toggleIdxThruPort(std::index_sequence<Idx...>) noexcept {
		(toggleIdxThruPin(ConstIndexType<Idx>{}, GpioGroupTupIdxSeq<Idx>), ...);
	}

	/**
	 * [enableAllGpioClkImp description]
	 * @param [name] [description]
	 */
	template <std::size_t... Idx>
	static constexpr void enableAllGpioClkImp(std::index_sequence<Idx...>) noexcept {
		(rcc_enable_periph_clk<static_cast<RccPeriph>(PinGrouper::getPort(ConstIndexType<Idx>{}))>(), ...);
	}

	template <std::size_t Num, std::size_t... Idx>
	static constexpr void alternateFuncSteupThruPin(ConstIndexType<Num> const& /*unused*/,
																									std::index_sequence<Idx...> const& /*unused*/,
																									GpioAltFunc const& t_af) noexcept {
		constexpr auto gpio_port			= PinGrouper::getPort(ConstIndexType<Num>{});
		constexpr auto gpio_pin_group = std::get<Num>(PinGrouper::GPIO_GROUP_LIST);
		gpio_set_af<gpio_port, std::get<Idx>(gpio_pin_group)...>(t_af);
	}

	/**
	 * [enableAllGpioClk description]
	 */
	template <std::size_t... Idx>
	static constexpr void alternateFuncSetupThruPort(std::index_sequence<Idx...> const& /*unused*/,
																									 GpioAltFunc const& t_af) noexcept {
		(alternateFuncSteupThruPin(ConstIndexType<Idx>{}, GpioGroupTupIdxSeq<Idx>, t_af), ...);
	}

 public:
	static constexpr void enableAllGpioClk() noexcept { enableAllGpioClkImp(IdxThruPort{}); }

	static constexpr void modeSetup(GpioMode const& t_mode, GpioPupd const& t_pupd) noexcept {
		modeSetupIdxThruPort(IdxThruPort{}, t_mode, t_pupd);
	}

	static constexpr void toggle() noexcept { toggleIdxThruPort(IdxThruPort{}); }

	static constexpr void alternateFuncSetup(GpioAltFunc const& t_af) noexcept {
		alternateFuncSetupThruPort(IdxThruPort{}, t_af);
	}
};

#endif	// DRIVER_UTILITY_HPP_
