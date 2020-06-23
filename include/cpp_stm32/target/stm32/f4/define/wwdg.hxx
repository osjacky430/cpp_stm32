#pragma once

#include "cpp_stm32/utility/macro.hxx"

namespace cpp_stm32::wwdg {

SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(WDGPRE, std::pair{1, 0b00}, std::pair{2, 0b01}, std::pair{4, 0b10},
																		 std::pair{8, 0b11});

}
