/**
 * @file  driver/sys_clk.hxx
 * @brief	Advance control of real time clock and systick timer
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

#pragma once

#include <chrono>

#include "cpp_stm32/driver/gpio_base.hxx"
#include "device.hxx"

namespace cpp_stm32::driver {

class RealTimeClock {
 public:
	RealTimeClock() = default;

	template <rcc::RtcClk RtcSrc, typename HourType>
	constexpr void init(rtc::Year_t const t_y, rtc::Month const t_m, rtc::Weekday const t_week, rtc::Date_t const t_date,
											HourType const t_hr, rtc::Minute_t const t_min, rtc::Second_t const t_sec) const noexcept {
		rtc::init<RtcSrc>(t_y, t_m, t_week, t_date, t_hr, t_min, t_sec);
	}

	constexpr auto read_calendar() const noexcept {
		rtc::wait_synchronization();

		auto const [h, min, s]	= rtc::get_time();
		auto const [y, w, m, d] = rtc::get_date();

		return std::tuple{y, w, m, d, h, min, s};
	}

	template <typename HourType>
	constexpr void set_calendar(rtc::Year_t const t_y, rtc::Month const t_m, rtc::Weekday const t_week,
															rtc::Date_t const t_date, HourType const t_hr, rtc::Minute_t const t_min,
															rtc::Second_t const t_sec) const noexcept {
		init_calendar(t_y, t_m, t_week, t_date, t_hr, t_min, t_sec);
	}
};

}	 // namespace cpp_stm32::driver
