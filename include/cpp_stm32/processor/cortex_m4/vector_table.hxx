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

#include <array>
#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "interrupt.hxx"

void reset_handler();
void nmi_handler();
void hard_fault_handler();
void mem_manage_fault_handler();
void bus_fault_handler();
void usage_fault_handler();
void service_call_handler();
void debug_monitor_handler();
void pending_service_call_handler();
void system_clock_tick_handler();

extern std::uint32_t STACK;

struct [[gnu::packed]] IrqVector {
	using IrqFuncPtr = void (*)();
	using Reserved	 = std::nullptr_t;

	std::uint32_t const* const initialStackPtr;	 //
	IrqFuncPtr const reset;											 // reset handler
	IrqFuncPtr const nmi;												 // non maskable interrupt handler
	IrqFuncPtr const hardFault;									 // hard fault handler
	IrqFuncPtr const memManFault;								 // memory manage fault handler
	IrqFuncPtr const busFault;									 // bus fault handler
	IrqFuncPtr const usageFault;								 // usage fault handler

	std::array<IrqFuncPtr, 4> const exception7To10IsReserved;

	IrqFuncPtr const serviceCall;		// service call (SV) handler
	IrqFuncPtr const debugMonitor;	// debug monitor handler

	std::array<IrqFuncPtr, 1> const exception13IsReserved;

	IrqFuncPtr const pendServiceCall;	 // pending service call handler
	IrqFuncPtr const sysTick;					 // system tick handler

	std::array<IrqFuncPtr, NVIC_IRQ_NUM> const irq;
};

// Standard layout types is memcopy-able and the layout is sufficiently defined, this is added to ensure any changes
// made in the future is safe and won't break the code.
static_assert(std::is_standard_layout_v<IrqVector>);

extern IrqVector const irq_vector_table;
