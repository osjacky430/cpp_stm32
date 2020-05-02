/**
 * @file  stm32/f4/rtc.hxx
 * @brief	RTC setup API for stm32f4
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

#include <chrono>
#include <tuple>

#include "cpp_stm32/common/rtc.hxx"
#include "cpp_stm32/target/stm32/f4/define/rtc.hxx"
#include "cpp_stm32/target/stm32/f4/register/rtc.hxx"

namespace cpp_stm32::rtc {

/**
 * [to_ten_and_unit description]
 * @return [description]
 */
constexpr auto to_ten_and_unit(std::uint8_t const t_val) noexcept {
	return std::tuple<std::uint8_t, std::uint8_t>{t_val / 10, t_val % 10};
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
constexpr void enable_init_mode() noexcept { reg::ISR.setBit<reg::ISRField::INIT>(); }

/**
 * @brief This function disables initialization mode (free running mode)
 */
constexpr void disable_init_mode() noexcept { reg::ISR.clearBit<reg::ISRField::INIT>(); }

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
constexpr void enaable_bypass_shadow_reg() noexcept { reg::CR.setBit<reg::CRField::BYPSHAD>(); }

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
 * @brief This function sets date
 * @param t_y  Year
 * @param t_m  Month
 * @param t_d  Date
 */
constexpr void set_date(Year_t const t_y, Month_t const t_m, Date_t const t_d) noexcept {
	auto const [year_ten, year_unit]	 = to_ten_and_unit(t_y.get() - 2000);
	auto const [month_ten, month_unit] = to_ten_and_unit(t_m.get());
	auto const [date_ten, date_unit]	 = to_ten_and_unit(t_d.get());

	reg::DR.writeBit<reg::DRField::YT, reg::DRField::YU, reg::DRField::MT, reg::DRField::MU, reg::DRField::DT,
									 reg::DRField::DU>(year_ten, year_unit, month_ten, month_unit, date_ten, date_unit);
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

}	 // namespace cpp_stm32::rtc
