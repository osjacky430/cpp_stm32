#pragma once

#include <array>
#include <cstdint>

#include "cpp_stm32/common/flash.hxx"
#include "cpp_stm32/detail/lookup_table.hxx"

namespace cpp_stm32::flash {

using Latency = detail::KeyValTable<struct CPP_STM32_LUT_LATENCY, 0, 4>;

}	// namespace cpp_stm32::flash
