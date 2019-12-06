/**
 * @Date:   2019-11-20T23:21:56+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: memory_map.hpp
 * @Last modified time: 2019-11-25T12:29:00+08:00
 */
#ifndef MEMORY_MAP_HPP_
#define MEMORY_MAP_HPP_

#include <type_traits>
#include "utility.hpp"

template <typename Base, typename Offset>
constexpr auto memory_at(Base b, Offset o) {
	if constexpr (std::is_enum_v<Base>) {
		return to_underlying(b) + o;
	} else {
		return b + o;
	}
}

enum class MemoryMap : std::uint32_t {
	PeriphBase = 0x40000000U,
	Apb1Base = memory_at(PeriphBase, 0x00000U),
	Apb2Base = memory_at(PeriphBase, 0x10000U),
	Ahb1Base = memory_at(PeriphBase, 0x20000U),
	Ahb2Base = memory_at(PeriphBase, 0x10000000U),
	Ahb3Base = memory_at(PeriphBase, 0x20000000U),

	PrivatePeriphBase = 0xE0000000U,
	IppbBase = memory_at(PrivatePeriphBase, 0x00000U),
	EppbBase = memory_at(PrivatePeriphBase, 0x40000U),
};

enum class Ippb : std::uint32_t {
	ItmBase = memory_at(MemoryMap::IppbBase, 0x0000),
	DwtBase = memory_at(MemoryMap::IppbBase, 0x1000),
	FbpBase = memory_at(MemoryMap::IppbBase, 0x2000),
	ScsBase = memory_at(MemoryMap::IppbBase, 0xE000)
};

enum class Scs : std::uint32_t {
	IctBase = memory_at(Ippb::ScsBase, 0x004),
	AcBase = memory_at(Ippb::ScsBase, 0x008),
	StcBase = memory_at(Ippb::ScsBase, 0x010),
	NvicBase = memory_at(Ippb::ScsBase, 0x100),
	ScbBase = memory_at(Ippb::ScsBase, 0xD00),
	FpuBase = memory_at(Ippb::ScsBase, 0xD88),
	MpuBase = memory_at(Ippb::ScsBase, 0xD90),
};

#endif
