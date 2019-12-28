/**
 * @Date:   2019-11-19T13:55:25+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: cortex_m_vector.hpp
 * @Last modified time: 2019-12-28T01:07:39+08:00
 */

#ifndef CORTEX_M_VECTOR_HPP_
#define CORTEX_M_VECTOR_HPP_

#include <cstddef>
#include <cstdint>

struct IrqVector {
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
	IrqFuncPtr const irq[91];
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

#endif	// CORTEX_M_VECTOR_HPP_
