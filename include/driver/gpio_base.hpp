/**
 * @Date:   2019-12-06T12:48:41+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: gpio_base.hpp
 */

#ifndef GPIO_BASE_HPP_
#define GPIO_BASE_HPP_

#include <tuple>

#include "include/driver/utility.hpp"
#include "include/hal/peripheral/gpio.hxx"
#include "include/hal/peripheral/rcc.hxx"

enum class PinName { PA_1, PA_5 };

class PinNameMap {
 private:
	static constexpr std::array PinMap{
		std::pair{GpioPort::PortA, GpioPin::Pin1},
		std::pair{GpioPort::PortA, GpioPin::Pin5},
	};

 public:
	static constexpr auto getPortFromPinMap(const PinName t_pin_name) noexcept {
		return std::get<0>(PinMap[to_underlying(t_pin_name)]);
	}

	static constexpr auto getPinFromPinMap(const PinName t_pin_name) noexcept {
		return std::get<1>(PinMap[to_underlying(t_pin_name)]);
	}
};

template <PinName... PinNames>
class PinGroupingHelper {
 private:
	// @todo need to solve duplicate elements
	static constexpr auto portList = std::make_tuple(PinNameMap::getPortFromPinMap(PinNames)...);
	static constexpr auto pinList	 = std::make_tuple(PinNameMap::getPinFromPinMap(PinNames)...);

 public:
	template <std::size_t N>
	static constexpr auto getPort(ConstIndexType<N>) noexcept {
		return std::get<N>(portList);
	}

	template <std::size_t N>
	static constexpr auto getPin(ConstIndexType<N>) noexcept {
		return std::get<N>(pinList);
	}

	static constexpr auto getUsedPortNum() noexcept { return std::tuple_size<decltype(portList)>::value; }
};

template <PinName... PinNames>
class GpioBase {
 private:
	using PinGrouper	 = PinGroupingHelper<PinNames...>;
	using PortIterator = std::make_index_sequence<PinGrouper::getUsedPortNum()>;

	template <std::size_t PortIdx, std::size_t... PinIdx>
	static constexpr auto groupPinByPort(ConstIndexType<PortIdx>, std::index_sequence<PinIdx...>) noexcept {
		constexpr auto IterateThruPins = [](const auto t_pin_idx) noexcept {
			if constexpr (constexpr auto pin_name = std::get<t_pin_idx()>(ALL_PIN_NAMES);
										PinGrouper::getPort(ConstIndexType<PortIdx>{}) == PinNameMap::getPortFromPinMap(pin_name)) {
				return std::tuple{PinNameMap::getPinFromPinMap(pin_name)};
			} else {
				return std::tuple{};
			}
		};

		return std::tuple_cat(IterateThruPins(ConstIndexType<PinIdx>{})...);
	}

	template <std::size_t... Idx>
	static constexpr auto makeGpioGroupListImp(std::index_sequence<Idx...>) noexcept {
		constexpr auto IterateThruPorts = [](const auto t_port_iter) {
			using pinIterator = std::make_index_sequence<sizeof...(PinNames)>;
			return groupPinByPort(t_port_iter, pinIterator{});
		};

		return std::make_tuple(IterateThruPorts(ConstIndexType<Idx>{})...);
	}

	template <std::size_t... Idx>
	static constexpr void enableAllGpioClkImp(std::index_sequence<Idx...>) noexcept {
		(rcc_enable_periph_clk<static_cast<RccPeriph>(PinGrouper::getPort(ConstIndexType<Idx>{}))>(), ...);
	}

 protected:
	static constexpr auto ALL_PIN_NAMES = std::tuple{PinNames...};

	static constexpr auto makeGpioGroupList() noexcept { return makeGpioGroupListImp(PortIterator{}); }

	static constexpr void enableAllGpioClk() noexcept { enableAllGpioClkImp(PortIterator{}); }
};

#endif	// DRIVER_UTILITY_HPP_
