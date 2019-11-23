/**
 * @Date:   2019-11-23T16:40:20+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: gpio.hpp
 * @Last modified time: 2019-11-24T00:41:27+08:00
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

enum class GpioPin { Pin1, Pin2, Pin3, Pin4 };

template <GpioPort Port, GpioPin pin>
class Gpio {
 private:
 public:
	Gpio() {}
};

#endif
