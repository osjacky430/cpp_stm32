#pragma once

#include "cpp_stm32/target/stm32/f4/define/wwdg.hxx"
#include "cpp_stm32/target/stm32/f4/register/wwdg.hxx"

namespace cpp_stm32::wwdg {

/**
 *  @brief This function enables window watchdog
 */
constexpr void enable_watchdog() noexcept { reg::CR.setBit<reg::CRField::WDGA>(); }

/**
 *  @brief This function disables window watchdog
 */
constexpr void disable_watchdog() noexcept { reg::CR.clearBit<reg::CRField::WDGA>(); }

/**
 *  @brief This function sets the value of watchdog counter to t_val
 *  @param t_val Watchdog counter value
 */
constexpr void set_counter(std::uint8_t const t_val) noexcept { reg::CR.writeBit<reg::CRField::T>(t_val); }

/**
 *  @brief This function sets the prescaler of the watchdog clock source
 *  @param t_prescaler Prescaler
 */
constexpr void set_prescaler(WDGPRE const t_prescaler) noexcept {
	reg::CFR.writeBit<reg::CFRField::WDGTB>(t_prescaler);
}

/**
 *  @brief This function sets the window value of watchdog
 *  @param t_val Window value
 */
constexpr void set_window_value(std::uint8_t const t_val) noexcept { reg::CFR.writeBit<reg::CFRField::W>(t_val); }

/**
 *  @brief This function returns whether the early wakeup flag is set or not
 *  @return Flag status
 */
[[nodiscard]] constexpr auto is_early_wakeup() noexcept { return reg::SR.readBit<reg::SRField::EWIF>(ValueOnly); }

/**
 *  @brief This function clears the early wakeup status flag
 */
constexpr void clear_early_wakeup_flag() noexcept { reg::SR.clearBit<reg::SRField::EWIF>(); }

/**
 *  @brief This function enables the early wakeup interrupt
 */
constexpr void enable_early_wakeup_interrupt() noexcept { reg::CFR.setBit<reg::CFRField::EWI>(); }

}	 // namespace cpp_stm32::wwdg

