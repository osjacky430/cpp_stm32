#pragma once

#include <cstdint>

namespace cpp_stm32::pwr {

enum class VoltageScale : std::uint8_t { Scale1Mode = 0b11, Scale2Mode = 0b10, Scale3Mode = 0b01 };

}
