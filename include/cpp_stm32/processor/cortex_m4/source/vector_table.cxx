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

#include "cpp_stm32/processor/cortex_m4/vector_table.hxx"
// @todo change the including header according to device
#include "cpp_stm32/target/stm32/f4/interrupt.hxx"

/**
 * [main description]
 * @return [description]
 */
int main();

/**
 * [null_handler description]
 */
void null_handler() { return; }

/**
 * [blocking_handler description]
 */
void blocking_handler() {
	while (true) {
	}
}

[[gnu::section((".IrqVector"))]] IrqVector const irq_vector_table{
	&STACK,
	reset_handler,
	nmi_handler,
	hard_fault_handler,
	mem_manage_fault_handler,
	bus_fault_handler,
	usage_fault_handler,
	{
		IrqVector::Reserved{},
	},
	service_call_handler,
	debug_monitor_handler,
	{
		IrqVector::Reserved{},
	},
	pending_service_call_handler,
	system_clock_tick_handler,
	{
		NVIC_INTERRUPT,
	},
};

void reset_handler() {
	using FuncPtr = void (*)();

	extern FuncPtr __preinit_array_start, __preinit_array_end;
	extern FuncPtr __init_array_start, __init_array_end;
	extern FuncPtr __fini_array_start, __fini_array_end;

	extern unsigned load_data_start_addr_, sdata_, edata_, ebss_;
	volatile unsigned* src	= &load_data_start_addr_;
	volatile unsigned* dest = &sdata_;

	for (; dest < &edata_; ++src, ++dest) {
		*dest = *src;
	}

	while (dest < &ebss_) {
		*dest++ = 0;
	}

	for (FuncPtr* p_fp = &__preinit_array_start; p_fp < &__preinit_array_end; ++p_fp) {
		(*p_fp)();
	}

	// constructor
	for (FuncPtr* p_fp = &__init_array_start; p_fp < &__init_array_end; ++p_fp) {
		(*p_fp)();
	}

	//
	main();

	// destructor
	for (FuncPtr* p_fp = &__fini_array_start; p_fp < &__fini_array_end; ++p_fp) {
		(*p_fp)();
	}
}

/**/
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void nmi_handler();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void hard_fault_handler();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void mem_manage_fault_handler();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void bus_fault_handler();
[[gnu::weak, gnu::alias("_Z16blocking_handlerv")]] void usage_fault_handler();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void service_call_handler();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void debug_monitor_handler();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void pending_service_call_handler();
[[gnu::weak, gnu::alias("_Z12null_handlerv")]] void system_clock_tick_handler();

// @todo change to include difference c file according to device
#include "cpp_stm32/target/stm32/f4/source/interrupt.cxx"
