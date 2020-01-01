/**
 * @Date:   2019-11-20T23:21:56+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: memory_map.hpp
 */

#pragma once

#include <type_traits>

#include "cpp_stm32/utility/utility.hxx"

/**
 * @brief  This function is a helper function that add base addr and offset
 * @param  b  Base address, can be scoped enum or integer
 * @param  o  Offset address, normally an integer
 * @return    the memory address
 */
template <typename Base, typename Offset>
constexpr auto memory_at(Base b, Offset o) {
	if constexpr (std::is_enum_v<Base>) {
		return to_underlying(b) + o;
	} else {
		return b + o;
	}
}

/**
 * @defgroup  INTERNAL_PRIVATE_PERIPH_BUSS
 * @ref 			ARM® Cortex®‑M4 Processor Technical Reference Manual
 *
 * @todo 			Need to see also cortex-m3, or ARMv7-M Architecture Reference Manual
 * @{
 */

/**
 * @enum 	CorePeriphAddr
 * @brief	Cortex-M4 core peripheral (Private Peripheral Bus)
 */
enum class CorePeriphAddr : std::uint32_t {
	PrivatePeriphBase = 0xE0000000U,
	IppbBase					= memory_at(PrivatePeriphBase, 0x00000U),
	EppbBase					= memory_at(PrivatePeriphBase, 0x40000U),
};

/**
 * @enum 	Ippb
 * @brief	Internal Private Peripheral Bus, provides access to
 * 				- Instrumentation Trace Macrocell (ITM)
 * 				- Data Watchpoint and Trace (DWT)
 * 				- Flashpatch and Breakpoint	(FBP)
 * 				- System Control Space (SCS)
 */
enum class Ippb : std::uint32_t {
	ItmBase = memory_at(CorePeriphAddr::IppbBase, 0x0000U),
	DwtBase = memory_at(CorePeriphAddr::IppbBase, 0x1000U),
	FbpBase = memory_at(CorePeriphAddr::IppbBase, 0x2000U),
	ScsBase = memory_at(CorePeriphAddr::IppbBase, 0xE000U)
};

/**
 * @enum 	Eppb
 * @brief	External Private Peripheral Bus, provides access to
 * 				- Trace Point Interface Unit (TPIU)
 * 				- Embedded Trace Macrocell (ETM)
 * 				- ROM Table
 */
enum class Eppb : std::uint32_t {
	TpiuBase = memory_at(CorePeriphAddr::EppbBase, 0x0000U),
	EtmBase	 = memory_at(CorePeriphAddr::EppbBase, 0x1000U),
	RomBase	 = memory_at(CorePeriphAddr::EppbBase, 0xF000U),
};

/**
 * @enum 	Scs
 * @brief	System Control Space (SCS), provides access to
 * 				- System control and ID register
 * 					- Interrupt Controller Type and Auxiliary Control registers
 * 					- System Control Block
 * 					- Debug register
 * 					- SW Trigger Interrupt Register
 * 					- Cache and branch predictor maintenance
 * 					- Microcontroller-specific ID space
 * 				- System Timer Control (STC)
 * 				- Nested Vector Interrupt (NVIC)
 * 				- Memory Protection Unit (MPU)
 */
enum class Scs : std::uint32_t {
	ScIdBase = memory_at(Ippb::ScsBase, 0x000U),
	StcBase	 = memory_at(Ippb::ScsBase, 0x010U),
	NvicBase = memory_at(Ippb::ScsBase, 0x100U),
	MpuBase	 = memory_at(Ippb::ScsBase, 0xD90U),
};

/**@}*/
