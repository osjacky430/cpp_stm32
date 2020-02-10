#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::dac::reg {

static constexpr auto BASE_ADDR = 0x40007400U;

/**
 * @defgroup	DAC_CR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{0}},	// EN1
					Binary<>{BitPos_t{1}},	// BOFF1
					Binary<>{BitPos_t{2}},	// TEN1
					Bit<3>{BitPos_t{3}},	// TSEL1
					Bit<2>{BitPos_t{6}},	// WAVE1
					Bit<4>{BitPos_t{8}},	// MAMP1
					Binary<>{BitPos_t{12}},	// DMAEN1
					Binary<>{BitPos_t{13}},	// DMAUDRIE1
					Binary<>{BitPos_t{16}},	// EN2
					Binary<>{BitPos_t{17}},	// BOFF2
					Binary<>{BitPos_t{18}},	// TEN2
					Bit<3>{BitPos_t{19}},	// TSEL2
					Bit<2>{BitPos_t{22}},	// WAVE2
					Bit<4>{BitPos_t{24}},	// MAMP2
					Binary<>{BitPos_t{28}},	// DMAEN2
					Binary<>{BitPos_t{29}}	// DMAUDRIE2
					)

enum class CRField {
	EN1,		/*!< DAC channel1 enable*/
	BOFF1,		/*!< DAC channel1 output buffer disable*/
	TEN1,		/*!< DAC channel1 trigger enable*/
	TSEL1,		/*!< DAC channel1 trigger selection*/
	WAVE1,		/*!< DAC channel1 noise/triangle wave generation enable*/
	MAMP1,		/*!< DAC channel1 mask/amplitude selector*/
	DMAEN1,		/*!< DAC channel1 DMA enable*/
	DMAUDRIE1,		/*!< DAC channel1 DMA Underrun Interrupt enable*/
	EN2,		/*!< DAC channel2 enable*/
	BOFF2,		/*!< DAC channel2 output buffer disable*/
	TEN2,		/*!< DAC channel2 trigger enable*/
	TSEL2,		/*!< DAC channel2 trigger selection*/
	WAVE2,		/*!< DAC channel2 noise/triangle wave generation enable*/
	MAMP2,		/*!< DAC channel2 mask/amplitude selector*/
	DMAEN2,		/*!< DAC channel2 DMA enable*/
	DMAUDRIE2,		/*!< DAC channel2 DMA underrun interrupt enable*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	DAC_SWTRIGR_GROUP		software trigger register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SWTRIGRBitList, /**/
					Binary<>{BitPos_t{0}},	// SWTRIG1
					Binary<>{BitPos_t{1}}	// SWTRIG2
					)

enum class SWTRIGRField {
	SWTRIG1,		/*!< DAC channel1 software trigger*/
	SWTRIG2,		/*!< DAC channel2 software trigger*/
};

static constexpr Register<SWTRIGRBitList, SWTRIGRField> SWTRIGR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	DAC_DHR12R1_GROUP		channel1 12-bit right-aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR12R1BitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}}	// DACC1DHR
					)

enum class DHR12R1Field {
	DACC1DHR,		/*!< DAC channel1 12-bit right-aligned data*/
};

static constexpr Register<DHR12R1BitList, DHR12R1Field> DHR12R1{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	DAC_DHR12L1_GROUP		channel1 12-bit left aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR12L1BitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{4}}	// DACC1DHR
					)

enum class DHR12L1Field {
	DACC1DHR,		/*!< DAC channel1 12-bit left-aligned data*/
};

static constexpr Register<DHR12L1BitList, DHR12L1Field> DHR12L1{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	DAC_DHR8R1_GROUP		channel1 8-bit right aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR8R1BitList, /**/
					Bit<8>{BitPos_t{0}}	// DACC1DHR
					)

enum class DHR8R1Field {
	DACC1DHR,		/*!< DAC channel1 8-bit right-aligned data*/
};

static constexpr Register<DHR8R1BitList, DHR8R1Field> DHR8R1{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	DAC_DHR12R2_GROUP		channel2 12-bit right aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR12R2BitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}}	// DACC2DHR
					)

enum class DHR12R2Field {
	DACC2DHR,		/*!< DAC channel2 12-bit right-aligned data*/
};

static constexpr Register<DHR12R2BitList, DHR12R2Field> DHR12R2{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	DAC_DHR12L2_GROUP		channel2 12-bit left aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR12L2BitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{4}}	// DACC2DHR
					)

enum class DHR12L2Field {
	DACC2DHR,		/*!< DAC channel2 12-bit left-aligned data*/
};

static constexpr Register<DHR12L2BitList, DHR12L2Field> DHR12L2{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	DAC_DHR8R2_GROUP		channel2 8-bit right-aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR8R2BitList, /**/
					Bit<8>{BitPos_t{0}}	// DACC2DHR
					)

enum class DHR8R2Field {
	DACC2DHR,		/*!< DAC channel2 8-bit right-aligned data*/
};

static constexpr Register<DHR8R2BitList, DHR8R2Field> DHR8R2{BASE_ADDR, 0x1cU};
/**@}*/

/**
 * @defgroup	DAC_DHR12RD_GROUP		Dual DAC 12-bit right-aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR12RDBitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}},	// DACC1DHR
					Bit<12, std::uint16_t>{BitPos_t{16}}	// DACC2DHR
					)

enum class DHR12RDField {
	DACC1DHR,		/*!< DAC channel1 12-bit right-aligned data*/
	DACC2DHR,		/*!< DAC channel2 12-bit right-aligned data*/
};

static constexpr Register<DHR12RDBitList, DHR12RDField> DHR12RD{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	DAC_DHR12LD_GROUP		DUAL DAC 12-bit left aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR12LDBitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{4}},	// DACC1DHR
					Bit<12, std::uint16_t>{BitPos_t{20}}	// DACC2DHR
					)

enum class DHR12LDField {
	DACC1DHR,		/*!< DAC channel1 12-bit left-aligned data*/
	DACC2DHR,		/*!< DAC channel2 12-bit left-aligned data*/
};

static constexpr Register<DHR12LDBitList, DHR12LDField> DHR12LD{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	DAC_DHR8RD_GROUP		DUAL DAC 8-bit right aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR8RDBitList, /**/
					Bit<8>{BitPos_t{0}},	// DACC1DHR
					Bit<8>{BitPos_t{8}}	// DACC2DHR
					)

enum class DHR8RDField {
	DACC1DHR,		/*!< DAC channel1 8-bit right-aligned data*/
	DACC2DHR,		/*!< DAC channel2 8-bit right-aligned data*/
};

static constexpr Register<DHR8RDBitList, DHR8RDField> DHR8RD{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	DAC_DOR1_GROUP		channel1 data output register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DOR1BitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}}	// DACC1DOR
					)

enum class DOR1Field {
	DACC1DOR,		/*!< DAC channel1 data output*/
};

static constexpr Register<DOR1BitList, DOR1Field> DOR1{BASE_ADDR, 0x2cU};
/**@}*/

/**
 * @defgroup	DAC_DOR2_GROUP		channel2 data output register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DOR2BitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}}	// DACC2DOR
					)

enum class DOR2Field {
	DACC2DOR,		/*!< DAC channel2 data output*/
};

static constexpr Register<DOR2BitList, DOR2Field> DOR2{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	DAC_SR_GROUP		status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					Binary<>{BitPos_t{13}},	// DMAUDR1
					Binary<>{BitPos_t{29}}	// DMAUDR2
					)

enum class SRField {
	DMAUDR1,		/*!< DAC channel1 DMA underrun flag*/
	DMAUDR2,		/*!< DAC channel2 DMA underrun flag*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x34U};
/**@}*/


} // cpp_stm32::dac::reg
