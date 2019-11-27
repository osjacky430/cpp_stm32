/**
 * @Date:   2019-11-23T16:40:20+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: gpio.hpp
 * @Last modified time: 2019-11-27T22:04:18+08:00
 */
#ifndef GPIO_HPP_
#define GPIO_HPP_

#include "memory_map.hpp"
#include "utility.hpp"

enum class GpioPort {
	PortA = memory_at(MemoryMap::Ahb1Base, 0x0000),
	PortB = memory_at(MemoryMap::Ahb1Base, 0x0400),
	PortC = memory_at(MemoryMap::Ahb1Base, 0x0800),
};

enum class GpioPin { Pin0, Pin1, Pin2, Pin3, Pin4, Pin5 };

enum class GpioMode { Input, Output, AltFunc, Analog };
enum class GpioPupd { None, PullUp, PullDown };
enum class GpioOutType { PushPull, OpenDrain };
enum class GpioOutSpeed { Low2M, Medium25M, Fast50M, High100M };
enum class GpioAltFunc { AF0, AF1, AF2, AF3 };

template <GpioPort Port>
struct GpioRegister {
 private:
	static constexpr auto m_port = to_underlying(Port);

 public:
	static constexpr auto MODER = []() noexcept -> decltype(auto) { return MMIO32(m_port, 0x00U); };
	static constexpr auto PUPDR = []() noexcept -> decltype(auto) { return MMIO32(m_port, 0x0CU); };

	static constexpr auto ODR = []() noexcept -> decltype(auto) { return MMIO32(m_port, 0x14U); };
	static constexpr auto BSRR = []() noexcept -> decltype(auto) { return MMIO32(m_port, 0x18U); };
};

template <GpioPort Port, GpioPin... Pins>
class GpioController {
 private:
	static constexpr GpioRegister<Port> GPIOx{};
	static constexpr auto pins = (... | (1U << to_underlying(Pins)));

	static constexpr auto m_setFlag = [](const auto opt) noexcept {
		return (... | (to_underlying(opt) << (2U * to_underlying(Pins))));
	};

 public:
	constexpr GpioController() noexcept {}

	constexpr void modeSetup(const GpioMode& t_mode, const GpioPupd& t_pupd) const noexcept {
		auto moder = GPIOx.MODER();
		auto pupdr = GPIOx.PUPDR();

		constexpr auto moder_mask = ~(... | (0b11 << (to_underlying(Pins)) * 2U));
		constexpr auto pupd_mask = ~(... | (0b11 << (to_underlying(Pins)) * 2U));

		GPIOx.MODER() = (moder & moder_mask) | m_setFlag(t_mode);
		GPIOx.PUPDR() = (pupdr & pupd_mask) | m_setFlag(t_pupd);
	}

	constexpr void toggle() const noexcept {
		const auto odr = GPIOx.ODR();
		GPIOx.BSRR() = ((odr & pins) << 16U) | (~odr & pins);
	}
};

#endif
