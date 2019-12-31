/**
 * @Date:   2019-11-20T23:21:56+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: memory_map.hpp
 * @Last modified time: 2020-01-01T05:19:22+08:00
 */
#pragma once

#include <type_traits>

#include "cpp_stm32/utility/utility.hxx"

template <typename Base, typename Offset>
constexpr auto memory_at(Base b, Offset o) {
	if constexpr (std::is_enum_v<Base>) {
		return to_underlying(b) + o;
	} else {
		return b + o;
	}
}

/**
 * @enum 	CorePeriphAddr
 * @brief	Cortex-M4 core peripherals enum (Private Peripheral Bus)
 */
enum class CorePeriphAddr : std::uint32_t {
	PrivatePeriphBase = 0xE0000000U,
};

/**
 * @enum PeriphAddr
 * @brief
 * @note	move to target/stm32/f4, this enum is device specific
 */
enum class PeriphAddr : std::uint32_t {
	PeriphBase = 0x40000000U,
	Apb1Base	 = memory_at(PeriphBase, 0x00000U),
	Apb2Base	 = memory_at(PeriphBase, 0x10000U),
	Ahb1Base	 = memory_at(PeriphBase, 0x20000U),
	Ahb2Base	 = memory_at(PeriphBase, 0x10000000U),
	Ahb3Base	 = memory_at(PeriphBase, 0x20000000U),
};

enum class MemoryMap : std::uint32_t {
	PeriphBase = 0x40000000U,
	Apb1Base	 = memory_at(PeriphBase, 0x00000U),
	Apb2Base	 = memory_at(PeriphBase, 0x10000U),
	Ahb1Base	 = memory_at(PeriphBase, 0x20000U),
	Ahb2Base	 = memory_at(PeriphBase, 0x10000000U),
	Ahb3Base	 = memory_at(PeriphBase, 0x20000000U),

	PrivatePeriphBase = 0xE0000000U,
	IppbBase					= memory_at(PrivatePeriphBase, 0x00000U),
	EppbBase					= memory_at(PrivatePeriphBase, 0x40000U),
};

/**
 * @defgroup  INTERNAL_PRIVATE_PERIPH_BUSS
 * @ref 			ARM® Cortex®‑M4 Processor Technical Reference Manual
 *
 * @{
 */

/**
 * @enum 	Ippb
 * @brief	Internal Private Peripheral Bus, provides access to
 * 				- Instrumentation Trace Macrocell (ITM)
 * 				- Data Watchpoint and Trace (DWT)
 * 				- Flashpatch and Breakpoint	(FBP)
 * 				- System Control Space (SCS)
 */
enum class Ippb : std::uint32_t {
	ItmBase = memory_at(MemoryMap::IppbBase, 0x0000),
	DwtBase = memory_at(MemoryMap::IppbBase, 0x1000),
	FbpBase = memory_at(MemoryMap::IppbBase, 0x2000),
	ScsBase = memory_at(MemoryMap::IppbBase, 0xE000)
};

/**
 * @enum 	Scs
 * @brief	System Control Space, provides access to
 * 				- System Timer Control (STC)
 * 				- Nested Vector Interrupt (NVIC)
 * 				- System Control Block (SCB)
 * 				- Floating Point Unit (FPU)
 * 				- Memory Protection Unit (MPU)
 */
enum class Scs : std::uint32_t {
	// IctBase	 = memory_at(Ippb::ScsBase, 0x004),	 // this is for cortex m3
	// AcBase	 = memory_at(Ippb::ScsBase, 0x008),
	StcBase	 = memory_at(Ippb::ScsBase, 0x010),
	NvicBase = memory_at(Ippb::ScsBase, 0x100),
	ScbBase	 = memory_at(Ippb::ScsBase, 0xD00),
	FpuBase	 = memory_at(Ippb::ScsBase, 0xD88),
	MpuBase	 = memory_at(Ippb::ScsBase, 0xD90),
};

/**@}*/
