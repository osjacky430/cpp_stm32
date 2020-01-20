#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::quadspi::reg {

static constexpr auto BASE_ADDR = 0xa0001000U;

/**
 * @defgroup	QUADSPI_CR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// ABORT
					Binary<>{BitPos_t{2}},	// DMAEN
					Binary<>{BitPos_t{3}},	// TCEN
					Binary<>{BitPos_t{4}},	// SSHIFT
					Binary<>{BitPos_t{6}},	// DFM
					Binary<>{BitPos_t{7}},	// FSEL
					Bit<5>{BitPos_t{8}},	// FTHRES
					Binary<>{BitPos_t{16}},	// TEIE
					Binary<>{BitPos_t{17}},	// TCIE
					Binary<>{BitPos_t{18}},	// FTIE
					Binary<>{BitPos_t{19}},	// SMIE
					Binary<>{BitPos_t{20}},	// TOIE
					Binary<>{BitPos_t{22}},	// APMS
					Binary<>{BitPos_t{23}},	// PMM
					Bit<8>{BitPos_t{24}}	// PRESCALER
					)

enum class CRField {
	EN,		/*!< Enable*/
	ABORT,		/*!< Abort request*/
	DMAEN,		/*!< DMA enable*/
	TCEN,		/*!< Timeout counter enable*/
	SSHIFT,		/*!< Sample shift*/
	DFM,		/*!< Dual-flash mode*/
	FSEL,		/*!< FLASH memory selection*/
	FTHRES,		/*!< IFO threshold level*/
	TEIE,		/*!< Transfer error interrupt enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	FTIE,		/*!< FIFO threshold interrupt enable*/
	SMIE,		/*!< Status match interrupt enable*/
	TOIE,		/*!< TimeOut interrupt enable*/
	APMS,		/*!< Automatic poll mode stop*/
	PMM,		/*!< Polling match mode*/
	PRESCALER,		/*!< Clock prescaler*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	QUADSPI_DCR_GROUP		device configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DCRBitList, /**/
					Binary<>{BitPos_t{0}},	// CKMODE
					Bit<3>{BitPos_t{8}},	// CSHT
					Bit<5>{BitPos_t{16}}	// FSIZE
					)

enum class DCRField {
	CKMODE,		/*!< Mode 0 / mode 3*/
	CSHT,		/*!< Chip select high time*/
	FSIZE,		/*!< FLASH memory size*/
};

static constexpr Register<DCRBitList, DCRField> DCR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	QUADSPI_SR_GROUP		status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					Binary<>{BitPos_t{0}},	// TEF
					Binary<>{BitPos_t{1}},	// TCF
					Binary<>{BitPos_t{2}},	// FTF
					Binary<>{BitPos_t{3}},	// SMF
					Binary<>{BitPos_t{4}},	// TOF
					Binary<>{BitPos_t{5}},	// BUSY
					Bit<7>{BitPos_t{8}}	// FLEVEL
					)

enum class SRField {
	TEF,		/*!< Transfer error flag*/
	TCF,		/*!< Transfer complete flag*/
	FTF,		/*!< FIFO threshold flag*/
	SMF,		/*!< Status match flag*/
	TOF,		/*!< Timeout flag*/
	BUSY,		/*!< Busy*/
	FLEVEL,		/*!< FIFO level*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	QUADSPI_FCR_GROUP		flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FCRBitList, /**/
					Binary<>{BitPos_t{0}},	// CTEF
					Binary<>{BitPos_t{1}},	// CTCF
					Binary<>{BitPos_t{3}},	// CSMF
					Binary<>{BitPos_t{4}}	// CTOF
					)

enum class FCRField {
	CTEF,		/*!< Clear transfer error flag*/
	CTCF,		/*!< Clear transfer complete flag*/
	CSMF,		/*!< Clear status match flag*/
	CTOF,		/*!< Clear timeout flag*/
};

static constexpr Register<FCRBitList, FCRField> FCR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	QUADSPI_DLR_GROUP		data length register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DLRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// DL
					)

enum class DLRField {
	DL,		/*!< Data length*/
};

static constexpr Register<DLRBitList, DLRField> DLR{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	QUADSPI_CCR_GROUP		communication configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCRBitList, /**/
					Bit<8>{BitPos_t{0}},	// INSTRUCTION
					Bit<2>{BitPos_t{8}},	// IMODE
					Bit<2>{BitPos_t{10}},	// ADMODE
					Bit<2>{BitPos_t{12}},	// ADSIZE
					Bit<2>{BitPos_t{14}},	// ABMODE
					Bit<2>{BitPos_t{16}},	// ABSIZE
					Bit<5>{BitPos_t{18}},	// DCYC
					Bit<2>{BitPos_t{24}},	// DMODE
					Bit<2>{BitPos_t{26}},	// FMODE
					Binary<>{BitPos_t{28}},	// SIOO
					Binary<>{BitPos_t{30}},	// DHHC
					Binary<>{BitPos_t{31}}	// DDRM
					)

enum class CCRField {
	INSTRUCTION,		/*!< Instruction*/
	IMODE,		/*!< Instruction mode*/
	ADMODE,		/*!< Address mode*/
	ADSIZE,		/*!< Address size*/
	ABMODE,		/*!< Alternate bytes mode*/
	ABSIZE,		/*!< Alternate bytes size*/
	DCYC,		/*!< Number of dummy cycles*/
	DMODE,		/*!< Data mode*/
	FMODE,		/*!< Functional mode*/
	SIOO,		/*!< Send instruction only once mode*/
	DHHC,		/*!< DDR hold half cycle*/
	DDRM,		/*!< Double data rate mode*/
};

static constexpr Register<CCRBitList, CCRField> CCR{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	QUADSPI_AR_GROUP		address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// ADDRESS
					)

enum class ARField {
	ADDRESS,		/*!< Address*/
};

static constexpr Register<ARBitList, ARField> AR{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	QUADSPI_ABR_GROUP		ABR group
 *
 * @{
 */

SETUP_REGISTER_INFO(ABRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// ALTERNATE
					)

enum class ABRField {
	ALTERNATE,		/*!< ALTERNATE*/
};

static constexpr Register<ABRBitList, ABRField> ABR{BASE_ADDR, 0x1cU};
/**@}*/

/**
 * @defgroup	QUADSPI_DR_GROUP		data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// DATA
					)

enum class DRField {
	DATA,		/*!< Data*/
};

static constexpr Register<DRBitList, DRField> DR{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	QUADSPI_PSMKR_GROUP		polling status mask register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PSMKRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// MASK
					)

enum class PSMKRField {
	MASK,		/*!< Status mask*/
};

static constexpr Register<PSMKRBitList, PSMKRField> PSMKR{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	QUADSPI_PSMAR_GROUP		polling status match register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PSMARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// MATCH
					)

enum class PSMARField {
	MATCH,		/*!< Status match*/
};

static constexpr Register<PSMARBitList, PSMARField> PSMAR{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	QUADSPI_PIR_GROUP		polling interval register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PIRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// INTERVAL
					)

enum class PIRField {
	INTERVAL,		/*!< Polling interval*/
};

static constexpr Register<PIRBitList, PIRField> PIR{BASE_ADDR, 0x2cU};
/**@}*/

/**
 * @defgroup	QUADSPI_LPTR_GROUP		low-power timeout register group
 *
 * @{
 */

SETUP_REGISTER_INFO(LPTRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// TIMEOUT
					)

enum class LPTRField {
	TIMEOUT,		/*!< Timeout period*/
};

static constexpr Register<LPTRBitList, LPTRField> LPTR{BASE_ADDR, 0x30U};
/**@}*/


} // cpp_stm32::quadspi::reg
