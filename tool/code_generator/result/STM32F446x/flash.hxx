#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::flash::reg {

static constexpr auto BASE_ADDR = 0x40023c00U;

/**
 * @defgroup	FLASH_ACR_GROUP		Flash access control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ACRBitList, /**/
					Binary<>{BitPos_t{12}},	// DCRST
					Binary<BitMod::WrOnly>{BitPos_t{11}},	// ICRST
					Binary<>{BitPos_t{10}},	// DCEN
					Binary<>{BitPos_t{9}},	// ICEN
					Binary<>{BitPos_t{8}},	// PRFTEN
					Bit<3>{BitPos_t{0}}	// LATENCY
					)

enum class ACRField {
	DCRST,		/*!< Data cache reset*/
	ICRST,		/*!< Instruction cache reset*/
	DCEN,		/*!< Data cache enable*/
	ICEN,		/*!< Instruction cache enable*/
	PRFTEN,		/*!< Prefetch enable*/
	LATENCY,		/*!< Latency*/
};

static constexpr Register<ACRBitList, ACRField> ACR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	FLASH_KEYR_GROUP		Flash key register group
 *
 * @{
 */

SETUP_REGISTER_INFO(KEYRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// KEY
					)

enum class KEYRField {
	KEY,		/*!< FPEC key*/
};

static constexpr Register<KEYRBitList, KEYRField> KEYR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	FLASH_OPTKEYR_GROUP		Flash option key register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OPTKEYRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// OPTKEY
					)

enum class OPTKEYRField {
	OPTKEY,		/*!< Option byte key*/
};

static constexpr Register<OPTKEYRBitList, OPTKEYRField> OPTKEYR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	FLASH_SR_GROUP		Status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					StatusBit<1>{BitPos_t{16}},	// BSY
					Binary<>{BitPos_t{8}},	// RDERR
					Binary<>{BitPos_t{7}},	// PGSERR
					Binary<>{BitPos_t{6}},	// PGPERR
					Binary<>{BitPos_t{5}},	// PGAERR
					Binary<>{BitPos_t{4}},	// WRPERR
					Binary<>{BitPos_t{1}},	// OPERR
					Binary<>{BitPos_t{0}}	// EOP
					)

enum class SRField {
	BSY,		/*!< Busy*/
	RDERR,		/*!< Read Protection Error*/
	PGSERR,		/*!< Programming sequence error*/
	PGPERR,		/*!< Programming parallelism error*/
	PGAERR,		/*!< Programming alignment error*/
	WRPERR,		/*!< Write protection error*/
	OPERR,		/*!< Operation error*/
	EOP,		/*!< End of operation*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	FLASH_CR_GROUP		Control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{31}},	// LOCK
					Binary<>{BitPos_t{25}},	// ERRIE
					Binary<>{BitPos_t{24}},	// EOPIE
					Binary<>{BitPos_t{16}},	// STRT
					Bit<2>{BitPos_t{8}},	// PSIZE
					Bit<4>{BitPos_t{3}},	// SNB
					Binary<>{BitPos_t{2}},	// MER
					Binary<>{BitPos_t{1}},	// SER
					Binary<>{BitPos_t{0}}	// PG
					)

enum class CRField {
	LOCK,		/*!< Lock*/
	ERRIE,		/*!< Error interrupt enable*/
	EOPIE,		/*!< End of operation interrupt enable*/
	STRT,		/*!< Start*/
	PSIZE,		/*!< Program size*/
	SNB,		/*!< Sector number*/
	MER,		/*!< Mass Erase of sectors 0 to 11*/
	SER,		/*!< Sector Erase*/
	PG,		/*!< Programming*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	FLASH_OPTCR_GROUP		Flash option control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OPTCRBitList, /**/
					Binary<>{BitPos_t{31}},	// SPRMOD
					Bit<8>{BitPos_t{16}},	// nWRP
					Bit<8>{BitPos_t{8}},	// RDP
					Binary<>{BitPos_t{7}},	// nRST_STDBY
					Binary<>{BitPos_t{6}},	// nRST_STOP
					Binary<>{BitPos_t{5}},	// WDG_SW
					Bit<2>{BitPos_t{2}},	// BOR_LEV
					Binary<>{BitPos_t{1}},	// OPTSTRT
					Binary<>{BitPos_t{0}}	// OPTLOCK
					)

enum class OPTCRField {
	SPRMOD,		/*!< Selection of Protection Mode of nWPRi bits*/
	nWRP,		/*!< Not write protect*/
	RDP,		/*!< Read protect*/
	nRST_STDBY,		/*!< nRST_STDBY User option bytes*/
	nRST_STOP,		/*!< nRST_STOP User option bytes*/
	WDG_SW,		/*!< WDG_SW User option bytes*/
	BOR_LEV,		/*!< BOR reset Level*/
	OPTSTRT,		/*!< Option start*/
	OPTLOCK,		/*!< Option lock*/
};

static constexpr Register<OPTCRBitList, OPTCRField> OPTCR{BASE_ADDR, 0x14U};
/**@}*/


} // cpp_stm32::flash::reg
