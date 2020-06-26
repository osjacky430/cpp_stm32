#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::flash::reg {

static constexpr auto BASE_ADDR = 0x40022000U;

/**
 * @defgroup	FLASH_ACR_GROUP		Access control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ACRBitList, /**/
					Binary<>{BitPos_t{14}},	// SLEEP_PD
					Binary<>{BitPos_t{13}},	// RUN_PD
					Binary<>{BitPos_t{12}},	// DCRST
					Binary<>{BitPos_t{11}},	// ICRST
					Binary<>{BitPos_t{10}},	// DCEN
					Binary<>{BitPos_t{9}},	// ICEN
					Binary<>{BitPos_t{8}},	// PRFTEN
					Bit<3>{BitPos_t{0}}	// LATENCY
					)

enum class ACRField {
	SLEEP_PD,		/*!< Flash Power-down mode during Low-power sleep mode*/
	RUN_PD,		/*!< Flash Power-down mode during Low-power run mode*/
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
 * @defgroup	FLASH_PDKEYR_GROUP		Power down key register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PDKEYRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PDKEYR
					)

enum class PDKEYRField {
	PDKEYR,		/*!< RUN_PD in FLASH_ACR key*/
};

static constexpr Register<PDKEYRBitList, PDKEYRField> PDKEYR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	FLASH_KEYR_GROUP		Flash key register group
 *
 * @{
 */

SETUP_REGISTER_INFO(KEYRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// KEYR
					)

enum class KEYRField {
	KEYR,		/*!< KEYR*/
};

static constexpr Register<KEYRBitList, KEYRField> KEYR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	FLASH_OPTKEYR_GROUP		Option byte key register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OPTKEYRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// OPTKEYR
					)

enum class OPTKEYRField {
	OPTKEYR,		/*!< Option byte key*/
};

static constexpr Register<OPTKEYRBitList, OPTKEYRField> OPTKEYR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	FLASH_SR_GROUP		Status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					StatusBit<1>{BitPos_t{16}},	// BSY
					Binary<>{BitPos_t{15}},	// OPTVERR
					Binary<>{BitPos_t{14}},	// RDERR
					Binary<>{BitPos_t{9}},	// FASTERR
					Binary<>{BitPos_t{8}},	// MISERR
					Binary<>{BitPos_t{7}},	// PGSERR
					Binary<>{BitPos_t{6}},	// SIZERR
					Binary<>{BitPos_t{5}},	// PGAERR
					Binary<>{BitPos_t{4}},	// WRPERR
					Binary<>{BitPos_t{3}},	// PROGERR
					Binary<>{BitPos_t{1}},	// OPERR
					Binary<>{BitPos_t{0}}	// EOP
					)

enum class SRField {
	BSY,		/*!< Busy*/
	OPTVERR,		/*!< Option validity error*/
	RDERR,		/*!< PCROP read error*/
	FASTERR,		/*!< Fast programming error*/
	MISERR,		/*!< Fast programming data miss error*/
	PGSERR,		/*!< Programming sequence error*/
	SIZERR,		/*!< Size error*/
	PGAERR,		/*!< Programming alignment error*/
	WRPERR,		/*!< Write protected error*/
	PROGERR,		/*!< Programming error*/
	OPERR,		/*!< Operation error*/
	EOP,		/*!< End of operation*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	FLASH_CR_GROUP		Flash control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{31}},	// LOCK
					Binary<>{BitPos_t{30}},	// OPTLOCK
					Binary<>{BitPos_t{27}},	// OBL_LAUNCH
					Binary<>{BitPos_t{26}},	// RDERRIE
					Binary<>{BitPos_t{25}},	// ERRIE
					Binary<>{BitPos_t{24}},	// EOPIE
					Binary<>{BitPos_t{18}},	// FSTPG
					Binary<>{BitPos_t{17}},	// OPTSTRT
					Binary<>{BitPos_t{16}},	// START
					Binary<>{BitPos_t{15}},	// MER2
					Binary<>{BitPos_t{11}},	// BKER
					Bit<8>{BitPos_t{3}},	// PNB
					Binary<>{BitPos_t{2}},	// MER1
					Binary<>{BitPos_t{1}},	// PER
					Binary<>{BitPos_t{0}}	// PG
					)

enum class CRField {
	LOCK,		/*!< FLASH_CR Lock*/
	OPTLOCK,		/*!< Options Lock*/
	OBL_LAUNCH,		/*!< Force the option byte loading*/
	RDERRIE,		/*!< PCROP read error interrupt enable*/
	ERRIE,		/*!< Error interrupt enable*/
	EOPIE,		/*!< End of operation interrupt enable*/
	FSTPG,		/*!< Fast programming*/
	OPTSTRT,		/*!< Options modification start*/
	START,		/*!< Start*/
	MER2,		/*!< Bank 2 Mass erase*/
	BKER,		/*!< Bank erase*/
	PNB,		/*!< Page number*/
	MER1,		/*!< Bank 1 Mass erase*/
	PER,		/*!< Page erase*/
	PG,		/*!< Programming*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	FLASH_ECCR_GROUP		Flash ECC register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ECCRBitList, /**/
					Binary<>{BitPos_t{31}},	// ECCD
					Binary<>{BitPos_t{30}},	// ECCC
					Binary<>{BitPos_t{24}},	// ECCIE
					StatusBit<1>{BitPos_t{20}},	// SYSF_ECC
					StatusBit<1>{BitPos_t{19}},	// BK_ECC
					StatusBit<19std::uint32_t>{BitPos_t{0}}	// ADDR_ECC
					)

enum class ECCRField {
	ECCD,		/*!< ECC detection*/
	ECCC,		/*!< ECC correction*/
	ECCIE,		/*!< ECC correction interrupt enable*/
	SYSF_ECC,		/*!< System Flash ECC fail*/
	BK_ECC,		/*!< ECC fail bank*/
	ADDR_ECC,		/*!< ECC fail address*/
};

static constexpr Register<ECCRBitList, ECCRField> ECCR{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	FLASH_OPTR_GROUP		Flash option register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OPTRBitList, /**/
					Binary<>{BitPos_t{25}},	// SRAM2_RST
					Binary<>{BitPos_t{24}},	// SRAM2_PE
					Binary<>{BitPos_t{23}},	// nBOOT1
					Binary<>{BitPos_t{21}},	// DUALBANK
					Binary<>{BitPos_t{20}},	// BFB2
					Binary<>{BitPos_t{19}},	// WWDG_SW
					Binary<>{BitPos_t{18}},	// IWDG_STDBY
					Binary<>{BitPos_t{17}},	// IWDG_STOP
					Binary<>{BitPos_t{16}},	// IDWG_SW
					Binary<>{BitPos_t{13}},	// nRST_STDBY
					Binary<>{BitPos_t{12}},	// nRST_STOP
					Bit<3>{BitPos_t{8}},	// BOR_LEV
					Bit<8>{BitPos_t{0}}	// RDP
					)

enum class OPTRField {
	SRAM2_RST,		/*!< SRAM2 Erase when system reset*/
	SRAM2_PE,		/*!< SRAM2 parity check enable*/
	nBOOT1,		/*!< Boot configuration*/
	DUALBANK,		/*!< Dual-Bank on 512 KB or 256 KB Flash memory devices*/
	BFB2,		/*!< Dual-bank boot*/
	WWDG_SW,		/*!< Window watchdog selection*/
	IWDG_STDBY,		/*!< Independent watchdog counter freeze in Standby mode*/
	IWDG_STOP,		/*!< Independent watchdog counter freeze in Stop mode*/
	IDWG_SW,		/*!< Independent watchdog selection*/
	nRST_STDBY,		/*!< nRST_STDBY*/
	nRST_STOP,		/*!< nRST_STOP*/
	BOR_LEV,		/*!< BOR reset Level*/
	RDP,		/*!< Read protection level*/
};

static constexpr Register<OPTRBitList, OPTRField> OPTR{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	FLASH_PCROP1SR_GROUP		Flash Bank 1 PCROP Start address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PCROP1SRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PCROP1_STRT
					)

enum class PCROP1SRField {
	PCROP1_STRT,		/*!< Bank 1 PCROP area start offset*/
};

static constexpr Register<PCROP1SRBitList, PCROP1SRField> PCROP1SR{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	FLASH_PCROP1ER_GROUP		Flash Bank 1 PCROP End address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PCROP1ERBitList, /**/
					Binary<>{BitPos_t{31}},	// PCROP_RDP
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PCROP1_END
					)

enum class PCROP1ERField {
	PCROP_RDP,		/*!< PCROP area preserved when RDP level decreased*/
	PCROP1_END,		/*!< Bank 1 PCROP area end offset*/
};

static constexpr Register<PCROP1ERBitList, PCROP1ERField> PCROP1ER{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	FLASH_WRP1AR_GROUP		Flash Bank 1 WRP area A address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(WRP1ARBitList, /**/
					Bit<8>{BitPos_t{16}},	// WRP1A_END
					Bit<8>{BitPos_t{0}}	// WRP1A_STRT
					)

enum class WRP1ARField {
	WRP1A_END,		/*!< Bank 1 WRP first area A end offset*/
	WRP1A_STRT,		/*!< Bank 1 WRP first area tart offset*/
};

static constexpr Register<WRP1ARBitList, WRP1ARField> WRP1AR{BASE_ADDR, 0x2cU};
/**@}*/

/**
 * @defgroup	FLASH_WRP1BR_GROUP		Flash Bank 1 WRP area B address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(WRP1BRBitList, /**/
					Bit<8>{BitPos_t{0}},	// WRP1B_END
					Bit<8>{BitPos_t{16}}	// WRP1B_STRT
					)

enum class WRP1BRField {
	WRP1B_END,		/*!< Bank 1 WRP second area B start offset*/
	WRP1B_STRT,		/*!< Bank 1 WRP second area B end offset*/
};

static constexpr Register<WRP1BRBitList, WRP1BRField> WRP1BR{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	FLASH_PCROP2SR_GROUP		Flash Bank 2 PCROP Start address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PCROP2SRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PCROP2_STRT
					)

enum class PCROP2SRField {
	PCROP2_STRT,		/*!< Bank 2 PCROP area start offset*/
};

static constexpr Register<PCROP2SRBitList, PCROP2SRField> PCROP2SR{BASE_ADDR, 0x44U};
/**@}*/

/**
 * @defgroup	FLASH_PCROP2ER_GROUP		Flash Bank 2 PCROP End address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PCROP2ERBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// PCROP2_END
					)

enum class PCROP2ERField {
	PCROP2_END,		/*!< Bank 2 PCROP area end offset*/
};

static constexpr Register<PCROP2ERBitList, PCROP2ERField> PCROP2ER{BASE_ADDR, 0x48U};
/**@}*/

/**
 * @defgroup	FLASH_WRP2AR_GROUP		Flash Bank 2 WRP area A address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(WRP2ARBitList, /**/
					Bit<8>{BitPos_t{16}},	// WRP2A_END
					Bit<8>{BitPos_t{0}}	// WRP2A_STRT
					)

enum class WRP2ARField {
	WRP2A_END,		/*!< Bank 2 WRP first area A end offset*/
	WRP2A_STRT,		/*!< Bank 2 WRP first area A start offset*/
};

static constexpr Register<WRP2ARBitList, WRP2ARField> WRP2AR{BASE_ADDR, 0x4cU};
/**@}*/

/**
 * @defgroup	FLASH_WRP2BR_GROUP		Flash Bank 2 WRP area B address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(WRP2BRBitList, /**/
					Bit<8>{BitPos_t{16}},	// WRP2B_END
					Bit<8>{BitPos_t{0}}	// WRP2B_STRT
					)

enum class WRP2BRField {
	WRP2B_END,		/*!< Bank 2 WRP second area B end offset*/
	WRP2B_STRT,		/*!< Bank 2 WRP second area B start offset*/
};

static constexpr Register<WRP2BRBitList, WRP2BRField> WRP2BR{BASE_ADDR, 0x50U};
/**@}*/


} // cpp_stm32::flash::reg
