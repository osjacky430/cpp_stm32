/**
 * @file  stm32/f4/define/rtc.hxx
 * @brief	RTC class and enum define.
 */

/** Copyright (c) 2020 by osjacky430.
 * All Rights Reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdint>

#include "cpp_stm32/utility/strongly_typed.hxx"

namespace cpp_stm32::rtc {

enum class AlarmOutput : std::uint8_t { OutputDisabled, AlarmA, AlarmB, Wakeup };
enum class AlarmOutputType : std::uint8_t { OpenDrain, PushPull };
enum class AlarmOutputPolarity : std::uint8_t { High, Low };

using AsyncPrescaler_t = StrongType<std::uint8_t, struct AsyncPrescaler>;
using SyncPrescaler_t	 = StrongType<std::uint16_t, struct SyncPrescaler>;

constexpr std::uint8_t LOCK_WRITE_PROTECTION_KEY		 = 0xFFU;
constexpr std::uint8_t UNLOCK_WRITE_PROTECTION_KEY_1 = 0xCAU;
constexpr std::uint8_t UNLOCK_WRITE_PROTECTION_KEY_2 = 0x53U;

}	 // namespace cpp_stm32::rtc
