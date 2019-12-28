/**
 * @Date:   2019-11-19T15:47:16+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: cortex_m_vector.cpp
 */

#include "include/hal/cortex_m_vector.hpp"
#include "include/hal/interrupt.hxx"

int main();
void null_handler();
void blocking_handler();

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

void null_handler() { return; }

void blocking_handler() {
	while (true) {
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
