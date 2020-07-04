#pragma once

#include "cpp_stm32/utility/macro.hxx"

namespace cpp_stm32::wwdg {

using WDGPRE = cpp_stm32::KeyValTable<struct CPP_STM32_LUT_WDGPRE, /**/
																			PAIR(1, 0b00), PAIR(2, 0b01), PAIR(4, 0b10), PAIR(8, 0b11)>;
}	 // namespace cpp_stm32::wwdg
