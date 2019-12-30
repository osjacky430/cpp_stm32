/**
 * @Date:   2019-12-23T01:35:56+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: pwr_reg.hxx
 */

#pragma once

#include <cstdint>
#include <tuple>

#include "cpp_stm32/target/memory_map.hxx"
#include "cpp_stm32/utility/bit.hxx"
#include "cpp_stm32/utility/register.hxx"

static constexpr auto PWR_BASE = memory_at(MemoryMap::Apb1Base, 0x7000U);

/**
 * @defgroup  PWR_CR_GROUP
 * @{
 */

enum class VoltageScale;

SETUP_REGISTER_INFO(PwrCrInfo, /**/
										Bit<2, VoltageScale>{BitPos_t{14}}, Binary<>{BitPos_t{16}}, Binary<>{BitPos_t{17}}, )

enum class PwrCrBit {
	Vos,
	OdEn,
	OdSwEn,
};

static constexpr Register<PwrCrInfo, PwrCrBit> PWR_CR{PWR_BASE, 0x00U};

/**@}*/

/**
 * @defgroup  PWR_CSR_GROUP
 * @{
 */

SETUP_REGISTER_INFO(PwrCsrInfo, /**/
										StatusBit<1>{BitPos_t{14}}, StatusBit<1>{BitPos_t{16}}, StatusBit<1>{BitPos_t{17}})

enum class PwrCsrBit { VosRdy, OdrRdy, OdrSwRdy };

static constexpr Register<PwrCsrInfo, PwrCsrBit> PWR_CSR{PWR_BASE, 0x04U};
/**@}*/
