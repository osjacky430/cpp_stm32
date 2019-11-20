/**
 * @Date:   2019-11-19T15:47:16+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: cortex_m_vector.cpp
 * @Last modified time: 2019-11-20T14:52:48+08:00
 */

#include "include/cortex_m_vector.hpp"

int main();
void null_handler();
void blocking_handler();

[[gnu::section((".IrqVector"))]] constexpr IrqVector irq_vector_table{
	&STACK,
	reset_handler,
	nmi_handler,
	hard_fault_handler,
	mem_manage_fault_handler,
	bus_fault_handler,
	usage_fault_handler,
	{
		IrqVector::Reserved{},
		IrqVector::Reserved{},
		IrqVector::Reserved{},
		IrqVector::Reserved{},
	},
	service_call_handler,
	debug_monitor_handler,
	{
		IrqVector::Reserved{},
	},
	pending_service_call_handler,
	system_clock_tick_handler,
};

void reset_handler() {
	main();
	return;
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
