// Copyright (c) 2020 by osjacky430.
// All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the Lesser GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// Lesser GNU General Public License for more details.
//
// You should have received a copy of the Lesser GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "cpp_stm32/target/stm32/f4/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/interrupt.hxx"
#include "cpp_stm32/target/stm32/f4/nvic.hxx"
#include "cpp_stm32/target/stm32/f4/pin_map.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/usart.hxx"

namespace cpp_stm32::driver {

// this is a bit messy
namespace Manufacture = cpp_stm32::stm32;

using Manufacture::PinName;
using Manufacture::PinNameMap;

using Manufacture::UsartPinMap;

namespace TargetDevice = cpp_stm32::stm32::f4;

using TargetDevice::rcc_enable_periph_clk;
using TargetDevice::RccPeriph;

using TargetDevice::gpio_mode_setup;
using TargetDevice::gpio_set_af;
using TargetDevice::gpio_toggle;

using TargetDevice::StopBit_v;
using TargetDevice::UsartNum;

using TargetDevice::usart_enable;
using TargetDevice::usart_enable_txe_irq;
using TargetDevice::usart_send;
using TargetDevice::usart_send_blocking;
using TargetDevice::usart_set_baudrate;
using TargetDevice::usart_set_dps;
using TargetDevice::usart_set_hardware_flow_ctl;
using TargetDevice::usart_set_transfer_mode;

using TargetDevice::PllClkSrc;
using TargetDevice::RccOsc;
using TargetDevice::SysClock;

using TargetDevice::IRQ_FUNC_HANDLER;

}	 // namespace cpp_stm32::driver
