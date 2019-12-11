/**
 * @Date:   2019-12-11T14:39:29+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: sys_info.hxx
 * @Last modified time: 2019-12-11T16:50:08+08:00
 */

#pragma once

#include "include/hal/utility.hxx"
#include "sys_info.hpp"

#if !defined(HSE_CLK_FREQ_)
#define HSE_CLK_FREQ_ 8_MHz
#endif

#if !defined(HSI_CLK_FREQ_)
#define HSI_CLK_FREQ_ 16_MHz
#endif

constexpr auto HSE_CLK_FREQ = HSE_CLK_FREQ_;
constexpr auto HSI_CLK_FREQ = HSI_CLK_FREQ_;
