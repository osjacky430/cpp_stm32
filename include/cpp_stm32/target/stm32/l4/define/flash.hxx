#pragma once

#include <array>
#include <cstdint>

#include "cpp_stm32/common/flash.hxx"
#include "cpp_stm32/utility/macro.hxx"

namespace cpp_stm32::flash {

using Latency = cpp_stm32::LookUpTable<struct CPP_STM32_LUT_LATENCY, 0, 4>;

}	 // namespace cpp_stm32::flash
