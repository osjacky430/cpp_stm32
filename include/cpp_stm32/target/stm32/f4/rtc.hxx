/**
 * @file  stm32/f4/rtc.hxx
 * @brief	Rtc setup API for stm32f4
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

#include <array>
#include <chrono>
#include <numeric>
#include <tuple>

#include "cpp_stm32/common/rtc.hxx"
#include "cpp_stm32/target/stm32/f4/define/rtc.hxx"
#include "cpp_stm32/target/stm32/f4/pwr.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/register/rtc.hxx"
#include "cpp_stm32/target/stm32/f4/sys_init.hxx"

namespace cpp_stm32::rtc {

/**
 * @brief This function decompose input integer to its ten and unit
 * @return Tuple that contains ten and unit of the input val
 */
constexpr auto to_ten_and_unit(std::uint8_t const t_val) noexcept {
	return std::tuple<std::uint8_t, std::uint8_t>{t_val / 10, t_val % 10};
}

/**
 * [get_status description]
 * @return [description]
 *
 * @todo 		this should be a general function since all the status register share same format (wait status)
 */
template <auto Flag>
[[nodiscard]] constexpr auto get_status() noexcept {
	return reg::ISR.readBit<Flag>(ValueOnly);
}

/**
 * @brief  	This function wait until the status flag turns to desire value
 * @tparam 	Flag
 *
 * @param		t_desire 	desire value of the status bit
 *
 * @todo 		this should be a general function since all the status register share same format (wait status)
 */
template <auto Flag>
constexpr void wait_status(bool const t_desire) noexcept {
	while (std::get<0>(get_status<Flag>()) != t_desire) {
	}
}

/**
 * @brief This function sets the asynchronous prescaler of RTC clock
 * @param t_async Asynchronous prescaler
 */
constexpr void set_async_prescaler(AsyncPrescaler_t const t_async) noexcept {
	reg::PRER.writeBit<reg::PRERField::PREDIV_A>(t_async.get());
}

/**
 * @brief This function sets the synchronous prescaler of RTC clock
 * @param t_sync Synchronous prescaler
 */
constexpr void set_sync_prescaler(SyncPrescaler_t const t_sync) noexcept {
	reg::PRER.writeBit<reg::PRERField::PREDIV_S>(t_sync.get());
}

/**
 * @brief This function sets both synchronous and asynchronous prescaler of RTC clock
 * @param t_async Asynchronous prescaler
 * @param t_sync  Synchronous prescaler
 */
constexpr void set_prescaler(AsyncPrescaler_t const t_async, SyncPrescaler_t const t_sync) noexcept {
	reg::PRER.writeBit<reg::PRERField::PREDIV_A, reg::PRERField::PREDIV_S>(t_async.get(), t_sync.get());
}

/**
 * @brief This function sets the hour format of RTC clock to 24 hour or AM/PM
 * @param t_format Hour format
 */
constexpr void set_hour_format(HourFormat const t_format) noexcept { reg::CR.writeBit<reg::CRField::FMT>(t_format); }

/**
 * @brief This function selects the flag to be routed to rtc alarm output
 * @param t_output  Output selection
 */
constexpr void set_alarm_output_event(AlarmOutput const t_output) noexcept {
	reg::CR.writeBit<reg::CRField::OSEL>(t_output);
}

/**
 * @brief This function sets the alarm output type
 * @param t_output_type   Output type selection
 */
constexpr void set_alarm_output_type(AlarmOutputType const t_output_type) noexcept {
	reg::TAFCR.writeBit<reg::TAFCRField::ALARMOUTTYPE>(t_output_type);
}

/**
 * @brief This function enables initialization mode, counters are stopped and start counting from the new value when
 *        INIT is reset.
 */
constexpr void enable_init_mode() noexcept {
	reg::ISR.setBit<Status::INIT>();
	wait_status<Status::INITF>(true);
}

/**
 * @brief This function disables initialization mode (free running mode)
 */
constexpr void disable_init_mode() noexcept { reg::ISR.clearBit<Status::INIT>(); }

/**
 * @brief This function sets output polarity of the pin
 * @param t_output_pol  Alarm output polarity
 */
constexpr void set_output_polarity(AlarmOutputPolarity const t_output_pol) noexcept {
	reg::CR.writeBit<reg::CRField::POL>(t_output_pol);
}

/**
 * @brief This function enables bypassing of the shadow register when reading from RTC_SSR, RTC_TR, and RTC_DR
 *
 * @note  If the frequency of the APB1 clock is less than seven times the frequency of RTCCLK,
 *        BYPSHAD must be set to ‘1’.
 */
constexpr void enable_bypass_shadow_reg() noexcept { reg::CR.setBit<reg::CRField::BYPSHAD>(); }

/**
 * @brief This function disables bypassing of the shadow register when reading from RTC_SSR, RTC_TR, and RTC_DR
 */
constexpr void disable_bypass_shadow_reg() noexcept { reg::CR.clearBit<reg::CRField::BYPSHAD>(); }

/**
 * @brief This function enables reference clock detection
 */
constexpr void enable_ref_clock() noexcept { reg::CR.setBit<reg::CRField::REFCKON>(); }

/**
 * @brief This function disables reference clock detection
 */
constexpr void disable_ref_clock() noexcept { reg::CR.clearBit<reg::CRField::REFCKON>(); }

/**
 * @brief This function sets the time format to AM or PM
 */
constexpr void set_time_format_am_pm(TimeFormat const t_time_format) noexcept {
	reg::TR.writeBit<reg::TRField::PM>(to_underlying(t_time_format));
}

/**
 * @brief This function sets the time format to 24 hour
 */
constexpr void set_time_format_24_hour() noexcept { reg::TR.clearBit<reg::TRField::PM>(); }

/**
 * @brief This function sets time
 * @param t_hour Hour
 * @param t_min  Minute
 * @param t_sec  Second
 */
constexpr void set_time(std::chrono::hours const t_hour, std::chrono::minutes const t_min,
												std::chrono::seconds const t_sec) noexcept {
	auto const [hour_ten, hour_unit] = to_ten_and_unit(t_hour.count());
	auto const [min_ten, min_unit]	 = to_ten_and_unit(t_min.count());
	auto const [sec_ten, sec_unit]	 = to_ten_and_unit(t_sec.count());

	reg::TR.writeBit<reg::TRField::HT, reg::TRField::HU, reg::TRField::MNT, reg::TRField::MNU, reg::TRField::ST,
									 reg::TRField::SU>(hour_ten, hour_unit, min_ten, min_unit, sec_ten, sec_unit);
}

/**
 * [get_time description]
 * @return [description]
 *
 * @note 	One must call get_date() after get_time() to unlock the values in the higher-order calendar shadow
 * 				registers to ensure consistency between the time and date values. Reading RTC current time locks the values in
 * 				calendar shadow registers until current date is read.
 */
[[nodiscard]] constexpr auto get_time() noexcept {
	auto const [hour_ten, hour_unit, min_ten, min_unit, sec_ten, sec_unit] =
		reg::TR.readBit<reg::TRField::HT, reg::TRField::HU, reg::TRField::MNT, reg::TRField::MNU, reg::TRField::ST,
										reg::TRField::SU>(ValueOnly);

	return std::tuple{hour_ten * 10 + hour_unit, min_ten * 10 + min_unit, sec_ten * 10 + sec_unit};
}

/**
 * @brief This function sets date
 * @param t_y  Year
 * @param t_m  Month
 * @param t_w  Weekday
 * @param t_d  Date
 */
constexpr void set_date(Year_t const t_y, Month const t_m, Weekday const t_w, Date_t const t_d) noexcept {
	auto const [year_ten, year_unit]	 = to_ten_and_unit(t_y.get() - 2000);
	auto const [month_ten, month_unit] = to_ten_and_unit(to_underlying(t_m));
	auto const weekday_unit						 = to_underlying(t_w);
	auto const [date_ten, date_unit]	 = to_ten_and_unit(t_d.get());

	reg::DR.writeBit<reg::DRField::YT, reg::DRField::YU, reg::DRField::WDU, reg::DRField::MT, reg::DRField::MU,
									 reg::DRField::DT, reg::DRField::DU>(year_ten, year_unit, weekday_unit, month_ten, month_unit,
																											 date_ten, date_unit);
}

/**
 * @brief This function returns the date in Y-M-D sequence
 * @return  tuple that contains date in Y-M-D sequence
 *
 * @note 	One must call get_date() after get_time() to unlock the values in the higher-order calendar shadow registers
 * 				to ensure consistency between the time and date values. Reading RTC current time locks the values in calendar
 * 				shadow registers until current date is read.
 */
constexpr auto get_date() noexcept {
	auto const [year_ten, year_unit, weekday, month_ten, month_unit, date_ten, date_unit] =
		reg::DR.readBit<reg::DRField::YT, reg::DRField::YU, reg::DRField::WDU, reg::DRField::MT, reg::DRField::MU,
										reg::DRField::DT, reg::DRField::DU>(ValueOnly);

	return std::tuple{2000 + year_ten * 10 + year_unit, Weekday{weekday},
										Month{static_cast<std::uint8_t>(month_ten * 10 + month_unit)}, date_ten * 10 + date_unit};
}

/**
 * @brief This function locks write protection
 */
constexpr void lock_write_protection() noexcept { reg::WPR.writeBit<reg::WPRField::KEY>(LOCK_WRITE_PROTECTION_KEY); }

/**
 * @brief This function unlocks write protection
 */
constexpr void unlock_write_protection() noexcept {
	reg::WPR.writeBit<reg::WPRField::KEY>(UNLOCK_WRITE_PROTECTION_KEY_1);
	reg::WPR.writeBit<reg::WPRField::KEY>(UNLOCK_WRITE_PROTECTION_KEY_2);
}

/**
 * @brief This function applies winter time change, i.e, subtract 1 hour to the calendar time
 */
constexpr void apply_winter_time_change() noexcept { reg::CR.setBit<reg::CRField::SUB1H>(); }

/**
 * @brief This function applies summer time change, i.e, add 1 hour to the calendar time
 */
constexpr void apply_summer_time_change() noexcept { reg::CR.setBit<reg::CRField::ADD1H>(); }

/**
 * [clear_status description]
 */
template <auto Flag>
constexpr void clear_status() noexcept {
	return reg::ISR.clearBit<Flag>();
}

/**
 *
 */
constexpr void wait_synchronization() noexcept {
	clear_status<Status::RSF>();
	wait_status<Status::RSF>(true);
}

/**
 *
 */
auto create_init_section() noexcept {
	struct InitHandler {
		InitHandler() noexcept {
			unlock_write_protection();
			enable_init_mode();
		}

		~InitHandler() noexcept {
			disable_init_mode();
			lock_write_protection();
		}
	};

	return InitHandler{};
}

/**
 *
 */
template <rcc::RtcClk RtcSrc>
constexpr void init_clock_src() noexcept {
	pwr::unlock_write_protection();
	rcc::hold_reset_backup_domain();
	rcc::release_reset_backup_domain();

	if constexpr (RtcSrc == rcc::RtcClk::Hse) {
		constexpr std::uint32_t rtc_prescaler = Frequency<HSE_CLK_FREQ>{} / HSE_CLK_FREQ_TO_RTC;
		rcc::set_rtc_prescaler(rcc::RTCPRE{rcc::DivisionFactor_v<rtc_prescaler>});
	}

	rcc::set_rtc_clk_src<RtcSrc>();
	rcc::enable_rtc();
}

/**
 *
 */
template <typename HourType>
constexpr void init_calendar(Year_t const t_y, Month const t_m, Weekday const t_w, Date_t const t_d,
														 HourType const t_hour, Minute_t const t_min, Second_t const t_sec) noexcept {
	auto const init_section = create_init_section();

	if constexpr (std::is_same_v<HourType, Hour_t>) {
		set_hour_format(HourFormat::Twelve);
		set_time_format_am_pm(t_hour.timeFormat);
	} else {
		set_hour_format(HourFormat::TwentyFour);
		set_time_format_24_hour();
	}

	set_time(t_hour.hour, t_min, t_sec);
	set_date(t_y, t_m, t_w, t_d);
}

/**
 * @brief
 */
template <rcc::RtcClk RtcSrc, typename HourType>
constexpr void init(Year_t const t_y, Month const t_m, Weekday const t_w, Date_t const t_d, HourType const t_hour,
										Minute_t const t_min, Second_t const t_sec) noexcept {
	static_assert(std::is_same_v<HourType, Hour_t> || std::is_same_v<HourType, std::chrono::hours>);

	init_clock_src<RtcSrc>();

	auto const init_section = create_init_section();

	// set prescaler
	constexpr std::tuple RTC_CLK_FREQ{LSE_CLK_FREQ, LSI_CLK_FREQ, HSE_CLK_FREQ_TO_RTC};
	constexpr std::uint16_t SYNC_PRESCALER_VAL =
		std::get<to_underlying(RtcSrc) - 1>(RTC_CLK_FREQ) / (ASYNC_PRESCALER_MAX.get() + 1) - 1;
	constexpr SyncPrescaler_t SYNC_PRESCALER{SYNC_PRESCALER_VAL};

	set_async_prescaler(ASYNC_PRESCALER_MAX);
	set_sync_prescaler(SYNC_PRESCALER);

	// set calander format
	if constexpr (std::is_same_v<HourType, Hour_t>) {
		set_hour_format(HourFormat::Twelve);
		set_time_format_am_pm(t_hour.timeFormat);
	} else {
		set_hour_format(HourFormat::TwentyFour);
		set_time_format_24_hour();
	}

	set_time(t_hour.hour, t_min, t_sec);
	set_date(t_y, t_m, t_w, t_d);
}

}	// namespace cpp_stm32::rtc
