/**
 * @Date:   2019-11-19T13:55:25+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: cortex_m_vector.hpp
 * @Last modified time: 2019-11-25T22:06:29+08:00
 */

#ifndef CORTEX_M_VECTOR_HPP_
#define CORTEX_M_VECTOR_HPP_

#include <cstddef>
#include <cstdint>

struct IrqVector {
	using IrqFuncPtr = void (*)();
	using Reserved = std::nullptr_t;

	std::uint32_t *initialStackPtr;	 //
	IrqFuncPtr reset;								 // reset handler
	IrqFuncPtr nmi;									 // non maskable interrupt handler
	IrqFuncPtr hardFault;						 // hard fault handler
	IrqFuncPtr memManFault;					 // memory manage fault handler
	IrqFuncPtr busFault;						 // bus fault handler
	IrqFuncPtr usageFault;					 // usage fault handler

	IrqFuncPtr exception7To10IsReserved[4];

	IrqFuncPtr serviceCall;		// service call (SV) handler
	IrqFuncPtr debugMonitor;	// debug monitor handler

	IrqFuncPtr exception13IsReserved[1];

	IrqFuncPtr pendServiceCall;	 // pending service call handler
	IrqFuncPtr sysTick;					 // system tick handler
	IrqFuncPtr irq[91];
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
extern const IrqVector irq_vector_table;

#endif	// CORTEX_M_VECTOR_HPP_
