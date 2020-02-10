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

#include <algorithm>
#include <tuple>

#include "cpp_stm32/common/gpio.hxx"
#include "cpp_stm32/utility/utility.hxx"

// target specific include
#include "device.hxx"

/**
 * @namespace   cpp_stm32::driver
 */
namespace cpp_stm32::driver {

/**
 * @class   PinGroupingHelper
 * @brief   This class is a helper class that extracts pins and ports from input pin names, and provides some
 *          useful information.
 * @tparam  PinNames @ref PinName
 */
template <gpio::PinName... PinNames>
class PinGroupingHelper {
 private:
	using IdxThruPinNameList = std::make_index_sequence<sizeof...(PinNames)>;

	/**
	 * @brief    This function handles the generation of list of port used according to the input pin names
	 * @return   List of gpio port used
	 */
	template <std::size_t... Idx>
	static constexpr auto genPortList(std::index_sequence<Idx...> const& /*unused*/) noexcept {
		using gpio::Port;
		auto port_list = std::array{gpio::PinMap::getPort(PIN_NAME_LIST[Idx])...};
		std::array<Port, PORT_NUM> result_port_list{};
		detail::unique_copy(port_list.begin(), port_list.end(), result_port_list.begin(),
												[](auto const& lhs, auto const& rhs) { return lhs == rhs; });
		return result_port_list;
	}

	/**
	 * @brief    This function handles the generation of list of pin list, the generated list of pin list
	 *           have same seqeunce as port list
	 * @return   list of gpio pin list
	 */
	template <std::size_t... Idx>
	static constexpr auto genPinList(std::index_sequence<Idx...> const& /*unused*/) noexcept {
		return std::array{gpio::PinMap::getPin(PIN_NAME_LIST[Idx])...};
	}

	/**
	 * @brief    This function calculate the number of port used
	 * @return   The number of port used
	 */
	static constexpr auto calcPortNum() noexcept {
		auto port_list = std::array{gpio::PinMap::getPort(PinNames)...};
		detail::sort(port_list, [](auto rhs, auto lhs) { return (to_underlying(rhs) < to_underlying(lhs)); });
		return detail::unique(port_list.begin(), port_list.end()) - port_list.begin();
	}

	/**
	 * @brief    This function generate pin name list, it will remove duplicate pin name
	 * @return   List of pin name
	 */
	static constexpr auto genPinNameList() noexcept {
		auto pin_name_list = std::array{PinNames...};
		detail::sort(pin_name_list,
								 [](auto const& lhs, auto const& rhs) { return (to_underlying(lhs) < to_underlying(rhs)); });
		return pin_name_list;
	}

	static constexpr auto PORT_NUM			= calcPortNum();								 /*!< Number of port used */
	static constexpr auto PIN_NAME_LIST = genPinNameList();							 /*!< List of pin name */
	static constexpr auto PORT_LIST = genPortList(IdxThruPinNameList{}); /*!< list of port according to pin name list */
	static constexpr auto PIN_LIST	= genPinList(IdxThruPinNameList{});	 /*!< list of pin according to pin name list*/

	/**
	 * @brief    This function collect pins with same port
	 * @details  This is basically done by index through port list and pin list, if the port of pin name matches current
	 *           port in the port list, then return the pin number. This function handles pin list indexing.
	 * @return   The tuple of pin number
	 */
	template <std::size_t PortIdx, std::size_t... PinIdx>
	static constexpr auto groupPinByPort(size_c<PortIdx> const& /*unused*/,
																			 std::index_sequence<PinIdx...> const& /*unused*/) noexcept {
		constexpr auto IterateThruPins = [](const auto t_pin_idx) noexcept {
			if constexpr (constexpr auto pin_name = std::get<t_pin_idx()>(PIN_NAME_LIST);
										getPort(size_c<PortIdx>{}) == gpio::PinMap::getPort(pin_name)) {
				return std::tuple{gpio::PinMap::getPin(pin_name)};
			} else {
				return std::tuple{};
			}
		};

		return std::tuple_cat(IterateThruPins(size_c<PinIdx>{})...);
	}

	/**
	 * @brief    This function collect pins with same port, for implementation details, see @ref groupPinByPort,
	 *           this function handles port list indexing.
	 * @return   Return list of gpio pin list
	 */
	template <std::size_t... Idx>
	static constexpr auto makeGpioGroupListImp(std::index_sequence<Idx...> const& /*unused*/) noexcept {
		constexpr auto IterateThruPorts = [](const auto t_port_iter) {
			using IdxThruPin = std::make_index_sequence<sizeof...(PinNames)>;
			return groupPinByPort(t_port_iter, IdxThruPin{});
		};

		return std::make_tuple(IterateThruPorts(size_c<Idx>{})...);
	}

	/**
	 * @brief    This function wraps the implementation of makeing list of gpio list
	 * @return   List of gpio pin list
	 */
	static constexpr auto makeGpioGroupList() noexcept { return makeGpioGroupListImp(IdxThruPort{}); }

 public:
	using IdxThruPort = std::make_index_sequence<PORT_NUM>;
	/**
	 * @brief    This function is a getter function to get nth port in gpio port list
	 * @todo     Is the order of Port important in this case? Since we remove duplicate
	 *           pin name, this means the number may not be the same as user expected
	 * @return   @ref Port
	 */
	template <std::size_t N>
	[[nodiscard]] static constexpr auto getPort(size_c<N>) noexcept {
		return std::get<N>(PORT_LIST);
	}

	/**
	 * @brief   This function is a getter function to get nth pin in gpio pin list
	 * @return  @ref Pin
	 */
	template <std::size_t N>
	[[nodiscard]] static constexpr auto getPin(size_c<N>) noexcept {
		return std::get<N>(PIN_LIST);
	}

	/**
	 * @brief    This function is a getter function to get the number of port used
	 * @return   The number of port used
	 */
	[[nodiscard]] static constexpr auto getPortNum() noexcept { return PORT_NUM; }

	static constexpr auto GPIO_GROUP_LIST = makeGpioGroupList(); /*!< List of gpio pin list */
};

/**
 * @class GpioUtil
 * @brief This class provides a more advance gpio utility, this class is used by other
 *        driver class.
 *
 * @tparam  PinNames gpio::PinName
 */
template <gpio::PinName... PinNames>
class GpioUtil {
 private:
	using PinName			= gpio::PinName;
	using PinGrouper	= PinGroupingHelper<PinNames...>;
	using IdxThruPort = typename PinGrouper::IdxThruPort;

	template <std::size_t Idx>
	using GpioGroupTupType = std::decay_t<decltype(std::get<Idx>(PinGrouper::GPIO_GROUP_LIST))>;

	template <std::size_t Idx>
	static constexpr auto GpioGroupTupElemNum = std::tuple_size_v<GpioGroupTupType<Idx>>;

	template <std::size_t Idx>
	static constexpr auto GpioGroupTupIdxSeq = std::make_index_sequence<GpioGroupTupElemNum<Idx>>{};

	/**
	 * @brief    This function handles the setup of gpio mode
	 * @details  Since we aim to accept pin names, we need to group pins wth same port, and call
	 *           gpio functions for each port, this is done by two std::index_sequence, first one
	 *           index through all port, see @ref modeSetupIdxThruPort, second one index through
	 *           pins, which is the purpose of this function
	 * @param t_mode @ref Mode
	 * @param t_pupd @ref Pupd
	 */
	template <std::size_t Num, std::size_t... Idx>
	static constexpr void modeSetupIdxThruPin(size_c<Num> const& /*unused*/,
																						std::index_sequence<Idx...> const& /*unused*/, gpio::Mode const& t_mode,
																						gpio::Pupd const& t_pupd) noexcept {
		constexpr auto gpio_port			= PinGrouper::getPort(size_c<Num>{});
		constexpr auto gpio_pin_group = std::get<Num>(PinGrouper::GPIO_GROUP_LIST);
		gpio::mode_setup<gpio_port, std::get<Idx>(gpio_pin_group)...>(t_mode, t_pupd);
	}

	/**
	 * @brief    This function handles the setup of gpio mode
	 * @details  Since we aim to accept pin names, we need to group pins wth same port, and call
	 *           gpio functions for each port, this is done by two std::index_sequence, first one
	 *           index through all port, which is the purpose of this function
	 * @param t_mode @ref Mode
	 * @param t_pupd @ref Pupd
	 */
	template <std::size_t... Idx>
	static constexpr void modeSetupIdxThruPort(std::index_sequence<Idx...> const& /*unused*/, gpio::Mode const& t_mode,
																						 gpio::Pupd const& t_pupd) noexcept {
		(modeSetupIdxThruPin(size_c<Idx>{}, GpioGroupTupIdxSeq<Idx>, t_mode, t_pupd), ...);
	}

	/**
	 * @brief    This function handels gpio toggle, for implementation detail, see @ref modeSetupIdxThruPin
	 */
	template <std::size_t Num, std::size_t... Idx>
	static constexpr void toggleIdxThruPin(size_c<Num> /*unused*/, std::index_sequence<Idx...> /*unused*/) noexcept {
		constexpr auto gpio_port			= PinGrouper::getPort(size_c<Num>{});
		constexpr auto gpio_pin_group = std::get<Num>(PinGrouper::GPIO_GROUP_LIST);
		gpio::toggle<gpio_port, std::get<Idx>(gpio_pin_group)...>();
	}

	/**
	 * @brief    This function handels gpio toggle, for implementation detail, see @ref modeSetupIdxThruPort
	 */
	template <std::size_t... Idx>
	static constexpr void toggleIdxThruPort(std::index_sequence<Idx...>) noexcept {
		(toggleIdxThruPin(size_c<Idx>{}, GpioGroupTupIdxSeq<Idx>), ...);
	}

	/**
	 * @brief    This function handles enabling of RCC peripheral clock of @ref Port
	 * @note     This is done by static casting @ref Port to @ref PeriphClk, this implies that
	 *           if we want this to work, we need to ensure @ref Port enum entries match to the
	 *           correct @ref PeriphClk enum entries
	 */
	template <std::size_t... Idx>
	static constexpr void enableAllGpioClkImp(std::index_sequence<Idx...> /*unused*/) noexcept {
		(rcc::enable_periph_clk<static_cast<rcc::PeriphClk>(PinGrouper::getPort(size_c<Idx>{}))>(), ...);
	}

	/**
	 * @brief    This function handles the setup of alternate function, for implementation
	 *           detail, see @ref modeSetupIdxThruPin
	 * @param    t_af   @ref gpio::AltFunc
	 */
	template <std::size_t Num, std::size_t... Idx>
	static constexpr void alternateFuncSteupThruPin(size_c<Num> const& /*unused*/,
																									std::index_sequence<Idx...> const& /*unused*/,
																									gpio::AltFunc const& t_af) noexcept {
		constexpr auto gpio_port			= PinGrouper::getPort(size_c<Num>{});
		constexpr auto gpio_pin_group = std::get<Num>(PinGrouper::GPIO_GROUP_LIST);
		gpio::set_alternate_function<gpio_port, std::get<Idx>(gpio_pin_group)...>(t_af);
	}

	/**
	 * @brief    This function handles the setup of alternate function, for implementation detail,
	 *           see @ref modeSetupIdxThruPort
	 * @param    t_af  @ref gpio::AltFunc
	 */
	template <std::size_t... Idx>
	static constexpr void alternateFuncSetupThruPort(std::index_sequence<Idx...> const& /*unused*/,
																									 gpio::AltFunc const& t_af) noexcept {
		(alternateFuncSteupThruPin(size_c<Idx>{}, GpioGroupTupIdxSeq<Idx>, t_af), ...);
	}

 public:
	/**
	 * @brief  This function is the public interface of enabling RCC gpio clock according to input pin names
	 */
	static constexpr void enableAllGpioClk() noexcept { enableAllGpioClkImp(IdxThruPort{}); }

	/**
	 * @brief  This function is the public interface of gpio mode setup
	 * @param t_mode @ref gpio::Mode
	 * @param t_pupd @ref gpio::Pupd
	 */
	static constexpr void modeSetup(gpio::Mode const& t_mode, gpio::Pupd const& t_pupd) noexcept {
		modeSetupIdxThruPort(IdxThruPort{}, t_mode, t_pupd);
	}

	/**
	 * @brief  This function is the public interface of gpio toggle
	 */
	static constexpr void toggle() noexcept { toggleIdxThruPort(IdxThruPort{}); }

	/**
	 * @brief  This function is the public interface of gpio set alternate function
	 * @param  t_af  @ref gpio::AltFunc
	 */
	static constexpr void alternateFuncSetup(gpio::AltFunc const& t_af) noexcept {
		alternateFuncSetupThruPort(IdxThruPort{}, t_af);
	}
};

}	 // namespace cpp_stm32::driver
