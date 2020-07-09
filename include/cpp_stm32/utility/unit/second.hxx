#pragma once

#include "cpp_stm32/utility/unit/unit.hxx"

namespace cpp_stm32 {

template <std::uint32_t Sec>
struct Second : Unit<Sec, struct CPP_STM32_TIME_UNIT> {};

}	// namespace cpp_stm32
