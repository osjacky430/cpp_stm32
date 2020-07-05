#pragma once

#include "cpp_stm32/utility/macro.hxx"

namespace cpp_stm32::flash {

using Latency = cpp_stm32::LookUpTable<struct CPP_STM32_LUT_LATENCY, 0, 15>;

}	 // namespace cpp_stm32::flash
