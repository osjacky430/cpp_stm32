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

#include <cstddef>
#include <cstdint>

#include "interrupt.hxx"

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

	IrqFuncPtr const exception7To10IsReserved[4];

	IrqFuncPtr const serviceCall;		// service call (SV) handler
	IrqFuncPtr const debugMonitor;	// debug monitor handler

	IrqFuncPtr const exception13IsReserved[1];

	IrqFuncPtr const pendServiceCall;	 // pending service call handler
	IrqFuncPtr const sysTick;					 // system tick handler
	IrqFuncPtr const irq[NVIC_IRQ_NUM];
};

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
extern IrqVector const irq_vector_table;
