#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::dac::reg {

static constexpr auto BASE_ADDR = 0x40007400U;

/**
 * @defgroup	DAC1_CR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{30}},	// CEN2
					Binary<>{BitPos_t{29}},	// DMAUDRIE2
					Binary<>{BitPos_t{28}},	// DMAEN2
					Bit<4>{BitPos_t{24}},	// MAMP2
					Bit<2>{BitPos_t{22}},	// WAVE2
					Bit<3>{BitPos_t{19}},	// TSEL2
					Binary<>{BitPos_t{18}},	// TEN2
					Binary<>{BitPos_t{16}},	// EN2
					Binary<>{BitPos_t{14}},	// CEN1
					Binary<>{BitPos_t{13}},	// DMAUDRIE1
					Binary<>{BitPos_t{12}},	// DMAEN1
					Bit<4>{BitPos_t{8}},	// MAMP1
					Bit<2>{BitPos_t{6}},	// WAVE1
					Bit<3>{BitPos_t{3}},	// TSEL1
					Binary<>{BitPos_t{2}},	// TEN1
					Binary<>{BitPos_t{0}}	// EN1
					)

enum class CRField {
	CEN2,		/*!< DAC Channel 2 calibration enable*/
	DMAUDRIE2,		/*!< DAC channel2 DMA underrun interrupt enable*/
	DMAEN2,		/*!< DAC channel2 DMA enable*/
	MAMP2,		/*!< DAC channel2 mask/amplitude selector*/
	WAVE2,		/*!< DAC channel2 noise/triangle wave generation enable*/
	TSEL2,		/*!< DAC channel2 trigger selection*/
	TEN2,		/*!< DAC channel2 trigger enable*/
	EN2,		/*!< DAC channel2 enable*/
	CEN1,		/*!< DAC Channel 1 calibration enable*/
	DMAUDRIE1,		/*!< DAC channel1 DMA Underrun Interrupt enable*/
	DMAEN1,		/*!< DAC channel1 DMA enable*/
	MAMP1,		/*!< DAC channel1 mask/amplitude selector*/
	WAVE1,		/*!< DAC channel1 noise/triangle wave generation enable*/
	TSEL1,		/*!< DAC channel1 trigger selection*/
	TEN1,		/*!< DAC channel1 trigger enable*/
	EN1,		/*!< DAC channel1 enable*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	DAC1_SWTRIGR_GROUP		software trigger register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SWTRIGRBitList, /**/
					Binary<>{BitPos_t{1}},	// SWTRIG2
					Binary<>{BitPos_t{0}}	// SWTRIG1
					)

enum class SWTRIGRField {
	SWTRIG2,		/*!< DAC channel2 software trigger*/
	SWTRIG1,		/*!< DAC channel1 software trigger*/
};

static constexpr Register<SWTRIGRBitList, SWTRIGRField> SWTRIGR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	DAC1_DHR12R1_GROUP		channel1 12-bit right-aligned data holding register group
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
 * @defgroup	DAC1_DHR12L1_GROUP		channel1 12-bit left-aligned data holding register group
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
 * @defgroup	DAC1_DHR8R1_GROUP		channel1 8-bit right-aligned data holding register group
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
 * @defgroup	DAC1_DHR12R2_GROUP		channel2 12-bit right aligned data holding register group
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
 * @defgroup	DAC1_DHR12L2_GROUP		channel2 12-bit left aligned data holding register group
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
 * @defgroup	DAC1_DHR8R2_GROUP		channel2 8-bit right-aligned data holding register group
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
 * @defgroup	DAC1_DHR12RD_GROUP		Dual DAC 12-bit right-aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR12RDBitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{16}},	// DACC2DHR
					Bit<12, std::uint16_t>{BitPos_t{0}}	// DACC1DHR
					)

enum class DHR12RDField {
	DACC2DHR,		/*!< DAC channel2 12-bit right-aligned data*/
	DACC1DHR,		/*!< DAC channel1 12-bit right-aligned data*/
};

static constexpr Register<DHR12RDBitList, DHR12RDField> DHR12RD{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	DAC1_DHR12LD_GROUP		DUAL DAC 12-bit left aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR12LDBitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{20}},	// DACC2DHR
					Bit<12, std::uint16_t>{BitPos_t{4}}	// DACC1DHR
					)

enum class DHR12LDField {
	DACC2DHR,		/*!< DAC channel2 12-bit left-aligned data*/
	DACC1DHR,		/*!< DAC channel1 12-bit left-aligned data*/
};

static constexpr Register<DHR12LDBitList, DHR12LDField> DHR12LD{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	DAC1_DHR8RD_GROUP		DUAL DAC 8-bit right aligned data holding register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DHR8RDBitList, /**/
					Bit<8>{BitPos_t{8}},	// DACC2DHR
					Bit<8>{BitPos_t{0}}	// DACC1DHR
					)

enum class DHR8RDField {
	DACC2DHR,		/*!< DAC channel2 8-bit right-aligned data*/
	DACC1DHR,		/*!< DAC channel1 8-bit right-aligned data*/
};

static constexpr Register<DHR8RDBitList, DHR8RDField> DHR8RD{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	DAC1_DOR1_GROUP		channel1 data output register group
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
 * @defgroup	DAC1_DOR2_GROUP		channel2 data output register group
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
 * @defgroup	DAC1_SR_GROUP		status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					StatusBit<1>{BitPos_t{31}},	// BWST2
					StatusBit<1>{BitPos_t{30}},	// CAL_FLAG2
					Binary<>{BitPos_t{29}},	// DMAUDR2
					StatusBit<1>{BitPos_t{15}},	// BWST1
					StatusBit<1>{BitPos_t{14}},	// CAL_FLAG1
					Binary<>{BitPos_t{13}}	// DMAUDR1
					)

enum class SRField {
	BWST2,		/*!< DAC Channel 2 busy writing sample time flag*/
	CAL_FLAG2,		/*!< DAC Channel 2 calibration offset status*/
	DMAUDR2,		/*!< DAC channel2 DMA underrun flag*/
	BWST1,		/*!< DAC Channel 1 busy writing sample time flag*/
	CAL_FLAG1,		/*!< DAC Channel 1 calibration offset status*/
	DMAUDR1,		/*!< DAC channel1 DMA underrun flag*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x34U};
/**@}*/

/**
 * @defgroup	DAC1_CCR_GROUP		calibration control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCRBitList, /**/
					Bit<5>{BitPos_t{16}},	// OTRIM2
					Bit<5>{BitPos_t{0}}	// OTRIM1
					)

enum class CCRField {
	OTRIM2,		/*!< DAC Channel 2 offset trimming value*/
	OTRIM1,		/*!< DAC Channel 1 offset trimming value*/
};

static constexpr Register<CCRBitList, CCRField> CCR{BASE_ADDR, 0x38U};
/**@}*/

/**
 * @defgroup	DAC1_MCR_GROUP		mode control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MCRBitList, /**/
					Bit<3>{BitPos_t{16}},	// MODE2
					Bit<3>{BitPos_t{0}}	// MODE1
					)

enum class MCRField {
	MODE2,		/*!< DAC Channel 2 mode*/
	MODE1,		/*!< DAC Channel 1 mode*/
};

static constexpr Register<MCRBitList, MCRField> MCR{BASE_ADDR, 0x3cU};
/**@}*/

/**
 * @defgroup	DAC1_SHSR1_GROUP		Sample and Hold sample time register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SHSR1BitList, /**/
					Bit<10, std::uint16_t>{BitPos_t{0}}	// TSAMPLE1
					)

enum class SHSR1Field {
	TSAMPLE1,		/*!< DAC Channel 1 sample Time*/
};

static constexpr Register<SHSR1BitList, SHSR1Field> SHSR1{BASE_ADDR, 0x40U};
/**@}*/

/**
 * @defgroup	DAC1_SHSR2_GROUP		Sample and Hold sample time register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SHSR2BitList, /**/
					Bit<10, std::uint16_t>{BitPos_t{0}}	// TSAMPLE2
					)

enum class SHSR2Field {
	TSAMPLE2,		/*!< DAC Channel 2 sample Time*/
};

static constexpr Register<SHSR2BitList, SHSR2Field> SHSR2{BASE_ADDR, 0x44U};
/**@}*/

/**
 * @defgroup	DAC1_SHHR_GROUP		Sample and Hold hold time register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SHHRBitList, /**/
					Bit<10, std::uint16_t>{BitPos_t{16}},	// THOLD2
					Bit<10, std::uint16_t>{BitPos_t{0}}	// THOLD1
					)

enum class SHHRField {
	THOLD2,		/*!< DAC Channel 2 hold time*/
	THOLD1,		/*!< DAC Channel 1 hold Time*/
};

static constexpr Register<SHHRBitList, SHHRField> SHHR{BASE_ADDR, 0x48U};
/**@}*/

/**
 * @defgroup	DAC1_SHRR_GROUP		Sample and Hold refresh time register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SHRRBitList, /**/
					Bit<8>{BitPos_t{16}},	// TREFRESH2
					Bit<8>{BitPos_t{0}}	// TREFRESH1
					)

enum class SHRRField {
	TREFRESH2,		/*!< DAC Channel 2 refresh Time*/
	TREFRESH1,		/*!< DAC Channel 1 refresh Time*/
};

static constexpr Register<SHRRBitList, SHRRField> SHRR{BASE_ADDR, 0x4cU};
/**@}*/


} // cpp_stm32::dac::reg
