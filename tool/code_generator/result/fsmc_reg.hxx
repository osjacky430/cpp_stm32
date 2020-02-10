#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::fsmc::reg {

static constexpr auto BASE_ADDR = 0xa0000000U;

/**
 * @defgroup	FMC_BCR1_GROUP		SRAM/NOR-Flash chip-select control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BCR1BitList, /**/
					Binary<>{BitPos_t{0}},	// MBKEN
					Binary<>{BitPos_t{1}},	// MUXEN
					Bit<2>{BitPos_t{2}},	// MTYP
					Bit<2>{BitPos_t{4}},	// MWID
					Binary<>{BitPos_t{6}},	// FACCEN
					Binary<>{BitPos_t{8}},	// BURSTEN
					Binary<>{BitPos_t{9}},	// WAITPOL
					Binary<>{BitPos_t{11}},	// WAITCFG
					Binary<>{BitPos_t{12}},	// WREN
					Binary<>{BitPos_t{13}},	// WAITEN
					Binary<>{BitPos_t{14}},	// EXTMOD
					Binary<>{BitPos_t{15}},	// ASYNCWAIT
					Binary<>{BitPos_t{19}},	// CBURSTRW
					Binary<>{BitPos_t{20}}	// CCLKEN
					)

enum class BCR1Field {
	MBKEN,		/*!< MBKEN*/
	MUXEN,		/*!< MUXEN*/
	MTYP,		/*!< MTYP*/
	MWID,		/*!< MWID*/
	FACCEN,		/*!< FACCEN*/
	BURSTEN,		/*!< BURSTEN*/
	WAITPOL,		/*!< WAITPOL*/
	WAITCFG,		/*!< WAITCFG*/
	WREN,		/*!< WREN*/
	WAITEN,		/*!< WAITEN*/
	EXTMOD,		/*!< EXTMOD*/
	ASYNCWAIT,		/*!< ASYNCWAIT*/
	CBURSTRW,		/*!< CBURSTRW*/
	CCLKEN,		/*!< CCLKEN*/
};

static constexpr Register<BCR1BitList, BCR1Field> BCR1{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	FMC_BTR1_GROUP		SRAM/NOR-Flash chip-select timing register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BTR1BitList, /**/
					Bit<4>{BitPos_t{0}},	// ADDSET
					Bit<4>{BitPos_t{4}},	// ADDHLD
					Bit<8>{BitPos_t{8}},	// DATAST
					Bit<4>{BitPos_t{16}},	// BUSTURN
					Bit<4>{BitPos_t{20}},	// CLKDIV
					Bit<4>{BitPos_t{24}},	// DATLAT
					Bit<2>{BitPos_t{28}}	// ACCMOD
					)

enum class BTR1Field {
	ADDSET,		/*!< ADDSET*/
	ADDHLD,		/*!< ADDHLD*/
	DATAST,		/*!< DATAST*/
	BUSTURN,		/*!< BUSTURN*/
	CLKDIV,		/*!< CLKDIV*/
	DATLAT,		/*!< DATLAT*/
	ACCMOD,		/*!< ACCMOD*/
};

static constexpr Register<BTR1BitList, BTR1Field> BTR1{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	FMC_BCR2_GROUP		SRAM/NOR-Flash chip-select control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BCR2BitList, /**/
					Binary<>{BitPos_t{0}},	// MBKEN
					Binary<>{BitPos_t{1}},	// MUXEN
					Bit<2>{BitPos_t{2}},	// MTYP
					Bit<2>{BitPos_t{4}},	// MWID
					Binary<>{BitPos_t{6}},	// FACCEN
					Binary<>{BitPos_t{8}},	// BURSTEN
					Binary<>{BitPos_t{9}},	// WAITPOL
					Binary<>{BitPos_t{10}},	// WRAPMOD
					Binary<>{BitPos_t{11}},	// WAITCFG
					Binary<>{BitPos_t{12}},	// WREN
					Binary<>{BitPos_t{13}},	// WAITEN
					Binary<>{BitPos_t{14}},	// EXTMOD
					Binary<>{BitPos_t{15}},	// ASYNCWAIT
					Binary<>{BitPos_t{19}}	// CBURSTRW
					)

enum class BCR2Field {
	MBKEN,		/*!< MBKEN*/
	MUXEN,		/*!< MUXEN*/
	MTYP,		/*!< MTYP*/
	MWID,		/*!< MWID*/
	FACCEN,		/*!< FACCEN*/
	BURSTEN,		/*!< BURSTEN*/
	WAITPOL,		/*!< WAITPOL*/
	WRAPMOD,		/*!< WRAPMOD*/
	WAITCFG,		/*!< WAITCFG*/
	WREN,		/*!< WREN*/
	WAITEN,		/*!< WAITEN*/
	EXTMOD,		/*!< EXTMOD*/
	ASYNCWAIT,		/*!< ASYNCWAIT*/
	CBURSTRW,		/*!< CBURSTRW*/
};

static constexpr Register<BCR2BitList, BCR2Field> BCR2{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	FMC_BTR2_GROUP		SRAM/NOR-Flash chip-select timing register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BTR2BitList, /**/
					Bit<4>{BitPos_t{0}},	// ADDSET
					Bit<4>{BitPos_t{4}},	// ADDHLD
					Bit<8>{BitPos_t{8}},	// DATAST
					Bit<4>{BitPos_t{16}},	// BUSTURN
					Bit<4>{BitPos_t{20}},	// CLKDIV
					Bit<4>{BitPos_t{24}},	// DATLAT
					Bit<2>{BitPos_t{28}}	// ACCMOD
					)

enum class BTR2Field {
	ADDSET,		/*!< ADDSET*/
	ADDHLD,		/*!< ADDHLD*/
	DATAST,		/*!< DATAST*/
	BUSTURN,		/*!< BUSTURN*/
	CLKDIV,		/*!< CLKDIV*/
	DATLAT,		/*!< DATLAT*/
	ACCMOD,		/*!< ACCMOD*/
};

static constexpr Register<BTR2BitList, BTR2Field> BTR2{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	FMC_BCR3_GROUP		SRAM/NOR-Flash chip-select control register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BCR3BitList, /**/
					Binary<>{BitPos_t{0}},	// MBKEN
					Binary<>{BitPos_t{1}},	// MUXEN
					Bit<2>{BitPos_t{2}},	// MTYP
					Bit<2>{BitPos_t{4}},	// MWID
					Binary<>{BitPos_t{6}},	// FACCEN
					Binary<>{BitPos_t{8}},	// BURSTEN
					Binary<>{BitPos_t{9}},	// WAITPOL
					Binary<>{BitPos_t{10}},	// WRAPMOD
					Binary<>{BitPos_t{11}},	// WAITCFG
					Binary<>{BitPos_t{12}},	// WREN
					Binary<>{BitPos_t{13}},	// WAITEN
					Binary<>{BitPos_t{14}},	// EXTMOD
					Binary<>{BitPos_t{15}},	// ASYNCWAIT
					Binary<>{BitPos_t{19}}	// CBURSTRW
					)

enum class BCR3Field {
	MBKEN,		/*!< MBKEN*/
	MUXEN,		/*!< MUXEN*/
	MTYP,		/*!< MTYP*/
	MWID,		/*!< MWID*/
	FACCEN,		/*!< FACCEN*/
	BURSTEN,		/*!< BURSTEN*/
	WAITPOL,		/*!< WAITPOL*/
	WRAPMOD,		/*!< WRAPMOD*/
	WAITCFG,		/*!< WAITCFG*/
	WREN,		/*!< WREN*/
	WAITEN,		/*!< WAITEN*/
	EXTMOD,		/*!< EXTMOD*/
	ASYNCWAIT,		/*!< ASYNCWAIT*/
	CBURSTRW,		/*!< CBURSTRW*/
};

static constexpr Register<BCR3BitList, BCR3Field> BCR3{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	FMC_BTR3_GROUP		SRAM/NOR-Flash chip-select timing register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BTR3BitList, /**/
					Bit<4>{BitPos_t{0}},	// ADDSET
					Bit<4>{BitPos_t{4}},	// ADDHLD
					Bit<8>{BitPos_t{8}},	// DATAST
					Bit<4>{BitPos_t{16}},	// BUSTURN
					Bit<4>{BitPos_t{20}},	// CLKDIV
					Bit<4>{BitPos_t{24}},	// DATLAT
					Bit<2>{BitPos_t{28}}	// ACCMOD
					)

enum class BTR3Field {
	ADDSET,		/*!< ADDSET*/
	ADDHLD,		/*!< ADDHLD*/
	DATAST,		/*!< DATAST*/
	BUSTURN,		/*!< BUSTURN*/
	CLKDIV,		/*!< CLKDIV*/
	DATLAT,		/*!< DATLAT*/
	ACCMOD,		/*!< ACCMOD*/
};

static constexpr Register<BTR3BitList, BTR3Field> BTR3{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	FMC_BCR4_GROUP		SRAM/NOR-Flash chip-select control register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BCR4BitList, /**/
					Binary<>{BitPos_t{0}},	// MBKEN
					Binary<>{BitPos_t{1}},	// MUXEN
					Bit<2>{BitPos_t{2}},	// MTYP
					Bit<2>{BitPos_t{4}},	// MWID
					Binary<>{BitPos_t{6}},	// FACCEN
					Binary<>{BitPos_t{8}},	// BURSTEN
					Binary<>{BitPos_t{9}},	// WAITPOL
					Binary<>{BitPos_t{10}},	// WRAPMOD
					Binary<>{BitPos_t{11}},	// WAITCFG
					Binary<>{BitPos_t{12}},	// WREN
					Binary<>{BitPos_t{13}},	// WAITEN
					Binary<>{BitPos_t{14}},	// EXTMOD
					Binary<>{BitPos_t{15}},	// ASYNCWAIT
					Binary<>{BitPos_t{19}}	// CBURSTRW
					)

enum class BCR4Field {
	MBKEN,		/*!< MBKEN*/
	MUXEN,		/*!< MUXEN*/
	MTYP,		/*!< MTYP*/
	MWID,		/*!< MWID*/
	FACCEN,		/*!< FACCEN*/
	BURSTEN,		/*!< BURSTEN*/
	WAITPOL,		/*!< WAITPOL*/
	WRAPMOD,		/*!< WRAPMOD*/
	WAITCFG,		/*!< WAITCFG*/
	WREN,		/*!< WREN*/
	WAITEN,		/*!< WAITEN*/
	EXTMOD,		/*!< EXTMOD*/
	ASYNCWAIT,		/*!< ASYNCWAIT*/
	CBURSTRW,		/*!< CBURSTRW*/
};

static constexpr Register<BCR4BitList, BCR4Field> BCR4{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	FMC_BTR4_GROUP		SRAM/NOR-Flash chip-select timing register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BTR4BitList, /**/
					Bit<4>{BitPos_t{0}},	// ADDSET
					Bit<4>{BitPos_t{4}},	// ADDHLD
					Bit<8>{BitPos_t{8}},	// DATAST
					Bit<4>{BitPos_t{16}},	// BUSTURN
					Bit<4>{BitPos_t{20}},	// CLKDIV
					Bit<4>{BitPos_t{24}},	// DATLAT
					Bit<2>{BitPos_t{28}}	// ACCMOD
					)

enum class BTR4Field {
	ADDSET,		/*!< ADDSET*/
	ADDHLD,		/*!< ADDHLD*/
	DATAST,		/*!< DATAST*/
	BUSTURN,		/*!< BUSTURN*/
	CLKDIV,		/*!< CLKDIV*/
	DATLAT,		/*!< DATLAT*/
	ACCMOD,		/*!< ACCMOD*/
};

static constexpr Register<BTR4BitList, BTR4Field> BTR4{BASE_ADDR, 0x1cU};
/**@}*/

/**
 * @defgroup	FMC_PCR2_GROUP		PC Card/NAND Flash control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(PCR2BitList, /**/
					Binary<>{BitPos_t{1}},	// PWAITEN
					Binary<>{BitPos_t{2}},	// PBKEN
					Binary<>{BitPos_t{3}},	// PTYP
					Bit<2>{BitPos_t{4}},	// PWID
					Binary<>{BitPos_t{6}},	// ECCEN
					Bit<4>{BitPos_t{9}},	// TCLR
					Bit<4>{BitPos_t{13}},	// TAR
					Bit<3>{BitPos_t{17}}	// ECCPS
					)

enum class PCR2Field {
	PWAITEN,		/*!< PWAITEN*/
	PBKEN,		/*!< PBKEN*/
	PTYP,		/*!< PTYP*/
	PWID,		/*!< PWID*/
	ECCEN,		/*!< ECCEN*/
	TCLR,		/*!< TCLR*/
	TAR,		/*!< TAR*/
	ECCPS,		/*!< ECCPS*/
};

static constexpr Register<PCR2BitList, PCR2Field> PCR2{BASE_ADDR, 0x60U};
/**@}*/

/**
 * @defgroup	FMC_SR2_GROUP		FIFO status and interrupt register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SR2BitList, /**/
					Binary<>{BitPos_t{0}},	// IRS
					Binary<>{BitPos_t{1}},	// ILS
					Binary<>{BitPos_t{2}},	// IFS
					Binary<>{BitPos_t{3}},	// IREN
					Binary<>{BitPos_t{4}},	// ILEN
					Binary<>{BitPos_t{5}},	// IFEN
					StatusBit<1>{BitPos_t{6}}	// FEMPT
					)

enum class SR2Field {
	IRS,		/*!< IRS*/
	ILS,		/*!< ILS*/
	IFS,		/*!< IFS*/
	IREN,		/*!< IREN*/
	ILEN,		/*!< ILEN*/
	IFEN,		/*!< IFEN*/
	FEMPT,		/*!< FEMPT*/
};

static constexpr Register<SR2BitList, SR2Field> SR2{BASE_ADDR, 0x64U};
/**@}*/

/**
 * @defgroup	FMC_PMEM2_GROUP		Common memory space timing register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(PMEM2BitList, /**/
					Bit<8>{BitPos_t{0}},	// MEMSETx
					Bit<8>{BitPos_t{8}},	// MEMWAITx
					Bit<8>{BitPos_t{16}},	// MEMHOLDx
					Bit<8>{BitPos_t{24}}	// MEMHIZx
					)

enum class PMEM2Field {
	MEMSETx,		/*!< MEMSETx*/
	MEMWAITx,		/*!< MEMWAITx*/
	MEMHOLDx,		/*!< MEMHOLDx*/
	MEMHIZx,		/*!< MEMHIZx*/
};

static constexpr Register<PMEM2BitList, PMEM2Field> PMEM2{BASE_ADDR, 0x68U};
/**@}*/

/**
 * @defgroup	FMC_PATT2_GROUP		Attribute memory space timing register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(PATT2BitList, /**/
					Bit<8>{BitPos_t{0}},	// ATTSETx
					Bit<8>{BitPos_t{8}},	// ATTWAITx
					Bit<8>{BitPos_t{16}},	// ATTHOLDx
					Bit<8>{BitPos_t{24}}	// ATTHIZx
					)

enum class PATT2Field {
	ATTSETx,		/*!< ATTSETx*/
	ATTWAITx,		/*!< ATTWAITx*/
	ATTHOLDx,		/*!< ATTHOLDx*/
	ATTHIZx,		/*!< ATTHIZx*/
};

static constexpr Register<PATT2BitList, PATT2Field> PATT2{BASE_ADDR, 0x6cU};
/**@}*/

/**
 * @defgroup	FMC_ECCR2_GROUP		ECC result register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(ECCR2BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// ECCx
					)

enum class ECCR2Field {
	ECCx,		/*!< ECCx*/
};

static constexpr Register<ECCR2BitList, ECCR2Field> ECCR2{BASE_ADDR, 0x74U};
/**@}*/

/**
 * @defgroup	FMC_PCR3_GROUP		PC Card/NAND Flash control register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(PCR3BitList, /**/
					Binary<>{BitPos_t{1}},	// PWAITEN
					Binary<>{BitPos_t{2}},	// PBKEN
					Binary<>{BitPos_t{3}},	// PTYP
					Bit<2>{BitPos_t{4}},	// PWID
					Binary<>{BitPos_t{6}},	// ECCEN
					Bit<4>{BitPos_t{9}},	// TCLR
					Bit<4>{BitPos_t{13}},	// TAR
					Bit<3>{BitPos_t{17}}	// ECCPS
					)

enum class PCR3Field {
	PWAITEN,		/*!< PWAITEN*/
	PBKEN,		/*!< PBKEN*/
	PTYP,		/*!< PTYP*/
	PWID,		/*!< PWID*/
	ECCEN,		/*!< ECCEN*/
	TCLR,		/*!< TCLR*/
	TAR,		/*!< TAR*/
	ECCPS,		/*!< ECCPS*/
};

static constexpr Register<PCR3BitList, PCR3Field> PCR3{BASE_ADDR, 0x80U};
/**@}*/

/**
 * @defgroup	FMC_SR3_GROUP		FIFO status and interrupt register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SR3BitList, /**/
					Binary<>{BitPos_t{0}},	// IRS
					Binary<>{BitPos_t{1}},	// ILS
					Binary<>{BitPos_t{2}},	// IFS
					Binary<>{BitPos_t{3}},	// IREN
					Binary<>{BitPos_t{4}},	// ILEN
					Binary<>{BitPos_t{5}},	// IFEN
					StatusBit<1>{BitPos_t{6}}	// FEMPT
					)

enum class SR3Field {
	IRS,		/*!< IRS*/
	ILS,		/*!< ILS*/
	IFS,		/*!< IFS*/
	IREN,		/*!< IREN*/
	ILEN,		/*!< ILEN*/
	IFEN,		/*!< IFEN*/
	FEMPT,		/*!< FEMPT*/
};

static constexpr Register<SR3BitList, SR3Field> SR3{BASE_ADDR, 0x84U};
/**@}*/

/**
 * @defgroup	FMC_PMEM3_GROUP		Common memory space timing register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(PMEM3BitList, /**/
					Bit<8>{BitPos_t{0}},	// MEMSETx
					Bit<8>{BitPos_t{8}},	// MEMWAITx
					Bit<8>{BitPos_t{16}},	// MEMHOLDx
					Bit<8>{BitPos_t{24}}	// MEMHIZx
					)

enum class PMEM3Field {
	MEMSETx,		/*!< MEMSETx*/
	MEMWAITx,		/*!< MEMWAITx*/
	MEMHOLDx,		/*!< MEMHOLDx*/
	MEMHIZx,		/*!< MEMHIZx*/
};

static constexpr Register<PMEM3BitList, PMEM3Field> PMEM3{BASE_ADDR, 0x88U};
/**@}*/

/**
 * @defgroup	FMC_PATT3_GROUP		Attribute memory space timing register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(PATT3BitList, /**/
					Bit<8>{BitPos_t{0}},	// ATTSETx
					Bit<8>{BitPos_t{8}},	// ATTWAITx
					Bit<8>{BitPos_t{16}},	// ATTHOLDx
					Bit<8>{BitPos_t{24}}	// ATTHIZx
					)

enum class PATT3Field {
	ATTSETx,		/*!< ATTSETx*/
	ATTWAITx,		/*!< ATTWAITx*/
	ATTHOLDx,		/*!< ATTHOLDx*/
	ATTHIZx,		/*!< ATTHIZx*/
};

static constexpr Register<PATT3BitList, PATT3Field> PATT3{BASE_ADDR, 0x8cU};
/**@}*/

/**
 * @defgroup	FMC_ECCR3_GROUP		ECC result register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(ECCR3BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// ECCx
					)

enum class ECCR3Field {
	ECCx,		/*!< ECCx*/
};

static constexpr Register<ECCR3BitList, ECCR3Field> ECCR3{BASE_ADDR, 0x94U};
/**@}*/

/**
 * @defgroup	FMC_PCR4_GROUP		PC Card/NAND Flash control register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(PCR4BitList, /**/
					Binary<>{BitPos_t{1}},	// PWAITEN
					Binary<>{BitPos_t{2}},	// PBKEN
					Binary<>{BitPos_t{3}},	// PTYP
					Bit<2>{BitPos_t{4}},	// PWID
					Binary<>{BitPos_t{6}},	// ECCEN
					Bit<4>{BitPos_t{9}},	// TCLR
					Bit<4>{BitPos_t{13}},	// TAR
					Bit<3>{BitPos_t{17}}	// ECCPS
					)

enum class PCR4Field {
	PWAITEN,		/*!< PWAITEN*/
	PBKEN,		/*!< PBKEN*/
	PTYP,		/*!< PTYP*/
	PWID,		/*!< PWID*/
	ECCEN,		/*!< ECCEN*/
	TCLR,		/*!< TCLR*/
	TAR,		/*!< TAR*/
	ECCPS,		/*!< ECCPS*/
};

static constexpr Register<PCR4BitList, PCR4Field> PCR4{BASE_ADDR, 0xa0U};
/**@}*/

/**
 * @defgroup	FMC_SR4_GROUP		FIFO status and interrupt register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SR4BitList, /**/
					Binary<>{BitPos_t{0}},	// IRS
					Binary<>{BitPos_t{1}},	// ILS
					Binary<>{BitPos_t{2}},	// IFS
					Binary<>{BitPos_t{3}},	// IREN
					Binary<>{BitPos_t{4}},	// ILEN
					Binary<>{BitPos_t{5}},	// IFEN
					StatusBit<1>{BitPos_t{6}}	// FEMPT
					)

enum class SR4Field {
	IRS,		/*!< IRS*/
	ILS,		/*!< ILS*/
	IFS,		/*!< IFS*/
	IREN,		/*!< IREN*/
	ILEN,		/*!< ILEN*/
	IFEN,		/*!< IFEN*/
	FEMPT,		/*!< FEMPT*/
};

static constexpr Register<SR4BitList, SR4Field> SR4{BASE_ADDR, 0xa4U};
/**@}*/

/**
 * @defgroup	FMC_PMEM4_GROUP		Common memory space timing register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(PMEM4BitList, /**/
					Bit<8>{BitPos_t{0}},	// MEMSETx
					Bit<8>{BitPos_t{8}},	// MEMWAITx
					Bit<8>{BitPos_t{16}},	// MEMHOLDx
					Bit<8>{BitPos_t{24}}	// MEMHIZx
					)

enum class PMEM4Field {
	MEMSETx,		/*!< MEMSETx*/
	MEMWAITx,		/*!< MEMWAITx*/
	MEMHOLDx,		/*!< MEMHOLDx*/
	MEMHIZx,		/*!< MEMHIZx*/
};

static constexpr Register<PMEM4BitList, PMEM4Field> PMEM4{BASE_ADDR, 0xa8U};
/**@}*/

/**
 * @defgroup	FMC_PATT4_GROUP		Attribute memory space timing register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(PATT4BitList, /**/
					Bit<8>{BitPos_t{0}},	// ATTSETx
					Bit<8>{BitPos_t{8}},	// ATTWAITx
					Bit<8>{BitPos_t{16}},	// ATTHOLDx
					Bit<8>{BitPos_t{24}}	// ATTHIZx
					)

enum class PATT4Field {
	ATTSETx,		/*!< ATTSETx*/
	ATTWAITx,		/*!< ATTWAITx*/
	ATTHOLDx,		/*!< ATTHOLDx*/
	ATTHIZx,		/*!< ATTHIZx*/
};

static constexpr Register<PATT4BitList, PATT4Field> PATT4{BASE_ADDR, 0xacU};
/**@}*/

/**
 * @defgroup	FMC_PIO4_GROUP		I/O space timing register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(PIO4BitList, /**/
					Bit<8>{BitPos_t{0}},	// IOSETx
					Bit<8>{BitPos_t{8}},	// IOWAITx
					Bit<8>{BitPos_t{16}},	// IOHOLDx
					Bit<8>{BitPos_t{24}}	// IOHIZx
					)

enum class PIO4Field {
	IOSETx,		/*!< IOSETx*/
	IOWAITx,		/*!< IOWAITx*/
	IOHOLDx,		/*!< IOHOLDx*/
	IOHIZx,		/*!< IOHIZx*/
};

static constexpr Register<PIO4BitList, PIO4Field> PIO4{BASE_ADDR, 0xb0U};
/**@}*/

/**
 * @defgroup	FMC_BWTR1_GROUP		SRAM/NOR-Flash write timing registers 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BWTR1BitList, /**/
					Bit<4>{BitPos_t{0}},	// ADDSET
					Bit<4>{BitPos_t{4}},	// ADDHLD
					Bit<8>{BitPos_t{8}},	// DATAST
					Bit<4>{BitPos_t{20}},	// CLKDIV
					Bit<4>{BitPos_t{24}},	// DATLAT
					Bit<2>{BitPos_t{28}}	// ACCMOD
					)

enum class BWTR1Field {
	ADDSET,		/*!< ADDSET*/
	ADDHLD,		/*!< ADDHLD*/
	DATAST,		/*!< DATAST*/
	CLKDIV,		/*!< CLKDIV*/
	DATLAT,		/*!< DATLAT*/
	ACCMOD,		/*!< ACCMOD*/
};

static constexpr Register<BWTR1BitList, BWTR1Field> BWTR1{BASE_ADDR, 0x104U};
/**@}*/

/**
 * @defgroup	FMC_BWTR2_GROUP		SRAM/NOR-Flash write timing registers 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BWTR2BitList, /**/
					Bit<4>{BitPos_t{0}},	// ADDSET
					Bit<4>{BitPos_t{4}},	// ADDHLD
					Bit<8>{BitPos_t{8}},	// DATAST
					Bit<4>{BitPos_t{20}},	// CLKDIV
					Bit<4>{BitPos_t{24}},	// DATLAT
					Bit<2>{BitPos_t{28}}	// ACCMOD
					)

enum class BWTR2Field {
	ADDSET,		/*!< ADDSET*/
	ADDHLD,		/*!< ADDHLD*/
	DATAST,		/*!< DATAST*/
	CLKDIV,		/*!< CLKDIV*/
	DATLAT,		/*!< DATLAT*/
	ACCMOD,		/*!< ACCMOD*/
};

static constexpr Register<BWTR2BitList, BWTR2Field> BWTR2{BASE_ADDR, 0x10cU};
/**@}*/

/**
 * @defgroup	FMC_BWTR3_GROUP		SRAM/NOR-Flash write timing registers 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BWTR3BitList, /**/
					Bit<4>{BitPos_t{0}},	// ADDSET
					Bit<4>{BitPos_t{4}},	// ADDHLD
					Bit<8>{BitPos_t{8}},	// DATAST
					Bit<4>{BitPos_t{20}},	// CLKDIV
					Bit<4>{BitPos_t{24}},	// DATLAT
					Bit<2>{BitPos_t{28}}	// ACCMOD
					)

enum class BWTR3Field {
	ADDSET,		/*!< ADDSET*/
	ADDHLD,		/*!< ADDHLD*/
	DATAST,		/*!< DATAST*/
	CLKDIV,		/*!< CLKDIV*/
	DATLAT,		/*!< DATLAT*/
	ACCMOD,		/*!< ACCMOD*/
};

static constexpr Register<BWTR3BitList, BWTR3Field> BWTR3{BASE_ADDR, 0x114U};
/**@}*/

/**
 * @defgroup	FMC_BWTR4_GROUP		SRAM/NOR-Flash write timing registers 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BWTR4BitList, /**/
					Bit<4>{BitPos_t{0}},	// ADDSET
					Bit<4>{BitPos_t{4}},	// ADDHLD
					Bit<8>{BitPos_t{8}},	// DATAST
					Bit<4>{BitPos_t{20}},	// CLKDIV
					Bit<4>{BitPos_t{24}},	// DATLAT
					Bit<2>{BitPos_t{28}}	// ACCMOD
					)

enum class BWTR4Field {
	ADDSET,		/*!< ADDSET*/
	ADDHLD,		/*!< ADDHLD*/
	DATAST,		/*!< DATAST*/
	CLKDIV,		/*!< CLKDIV*/
	DATLAT,		/*!< DATLAT*/
	ACCMOD,		/*!< ACCMOD*/
};

static constexpr Register<BWTR4BitList, BWTR4Field> BWTR4{BASE_ADDR, 0x11cU};
/**@}*/

/**
 * @defgroup	FMC_SDCR1_GROUP		SDRAM Control Register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SDCR1BitList, /**/
					Bit<2>{BitPos_t{13}},	// RPIPE
					Binary<>{BitPos_t{12}},	// RBURST
					Bit<2>{BitPos_t{10}},	// SDCLK
					Binary<>{BitPos_t{9}},	// WP
					Bit<2>{BitPos_t{7}},	// CAS
					Binary<>{BitPos_t{6}},	// NB
					Bit<2>{BitPos_t{4}},	// MWID
					Bit<2>{BitPos_t{2}},	// NR
					Bit<2>{BitPos_t{0}}	// NC
					)

enum class SDCR1Field {
	RPIPE,		/*!< Read pipe*/
	RBURST,		/*!< Burst read*/
	SDCLK,		/*!< SDRAM clock configuration*/
	WP,		/*!< Write protection*/
	CAS,		/*!< CAS latency*/
	NB,		/*!< Number of internal banks*/
	MWID,		/*!< Memory data bus width*/
	NR,		/*!< Number of row address bits*/
	NC,		/*!< Number of column address bits*/
};

static constexpr Register<SDCR1BitList, SDCR1Field> SDCR1{BASE_ADDR, 0x140U};
/**@}*/

/**
 * @defgroup	FMC_SDCR2_GROUP		SDRAM Control Register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SDCR2BitList, /**/
					Bit<2>{BitPos_t{13}},	// RPIPE
					Binary<>{BitPos_t{12}},	// RBURST
					Bit<2>{BitPos_t{10}},	// SDCLK
					Binary<>{BitPos_t{9}},	// WP
					Bit<2>{BitPos_t{7}},	// CAS
					Binary<>{BitPos_t{6}},	// NB
					Bit<2>{BitPos_t{4}},	// MWID
					Bit<2>{BitPos_t{2}},	// NR
					Bit<2>{BitPos_t{0}}	// NC
					)

enum class SDCR2Field {
	RPIPE,		/*!< Read pipe*/
	RBURST,		/*!< Burst read*/
	SDCLK,		/*!< SDRAM clock configuration*/
	WP,		/*!< Write protection*/
	CAS,		/*!< CAS latency*/
	NB,		/*!< Number of internal banks*/
	MWID,		/*!< Memory data bus width*/
	NR,		/*!< Number of row address bits*/
	NC,		/*!< Number of column address bits*/
};

static constexpr Register<SDCR2BitList, SDCR2Field> SDCR2{BASE_ADDR, 0x144U};
/**@}*/

/**
 * @defgroup	FMC_SDTR1_GROUP		SDRAM Timing register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SDTR1BitList, /**/
					Bit<4>{BitPos_t{24}},	// TRCD
					Bit<4>{BitPos_t{20}},	// TRP
					Bit<4>{BitPos_t{16}},	// TWR
					Bit<4>{BitPos_t{12}},	// TRC
					Bit<4>{BitPos_t{8}},	// TRAS
					Bit<4>{BitPos_t{4}},	// TXSR
					Bit<4>{BitPos_t{0}}	// TMRD
					)

enum class SDTR1Field {
	TRCD,		/*!< Row to column delay*/
	TRP,		/*!< Row precharge delay*/
	TWR,		/*!< Recovery delay*/
	TRC,		/*!< Row cycle delay*/
	TRAS,		/*!< Self refresh time*/
	TXSR,		/*!< Exit self-refresh delay*/
	TMRD,		/*!< Load Mode Register to Active*/
};

static constexpr Register<SDTR1BitList, SDTR1Field> SDTR1{BASE_ADDR, 0x148U};
/**@}*/

/**
 * @defgroup	FMC_SDTR2_GROUP		SDRAM Timing register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SDTR2BitList, /**/
					Bit<4>{BitPos_t{24}},	// TRCD
					Bit<4>{BitPos_t{20}},	// TRP
					Bit<4>{BitPos_t{16}},	// TWR
					Bit<4>{BitPos_t{12}},	// TRC
					Bit<4>{BitPos_t{8}},	// TRAS
					Bit<4>{BitPos_t{4}},	// TXSR
					Bit<4>{BitPos_t{0}}	// TMRD
					)

enum class SDTR2Field {
	TRCD,		/*!< Row to column delay*/
	TRP,		/*!< Row precharge delay*/
	TWR,		/*!< Recovery delay*/
	TRC,		/*!< Row cycle delay*/
	TRAS,		/*!< Self refresh time*/
	TXSR,		/*!< Exit self-refresh delay*/
	TMRD,		/*!< Load Mode Register to Active*/
};

static constexpr Register<SDTR2BitList, SDTR2Field> SDTR2{BASE_ADDR, 0x14cU};
/**@}*/

/**
 * @defgroup	FMC_SDCMR_GROUP		SDRAM Command Mode register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SDCMRBitList, /**/
					Bit<13, std::uint16_t>{BitPos_t{9}},	// MRD
					Bit<4>{BitPos_t{5}},	// NRFS
					Binary<BitMod::WrOnly>{BitPos_t{4}},	// CTB1
					Binary<BitMod::WrOnly>{BitPos_t{3}},	// CTB2
					Bit<3, BitMod::WrOnly>{BitPos_t{0}}	// MODE
					)

enum class SDCMRField {
	MRD,		/*!< Mode Register definition*/
	NRFS,		/*!< Number of Auto-refresh*/
	CTB1,		/*!< Command target bank 1*/
	CTB2,		/*!< Command target bank 2*/
	MODE,		/*!< Command mode*/
};

static constexpr Register<SDCMRBitList, SDCMRField> SDCMR{BASE_ADDR, 0x150U};
/**@}*/

/**
 * @defgroup	FMC_SDRTR_GROUP		SDRAM Refresh Timer register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SDRTRBitList, /**/
					Binary<>{BitPos_t{14}},	// REIE
					Bit<13, std::uint16_t>{BitPos_t{1}},	// COUNT
					Binary<BitMod::WrOnly>{BitPos_t{0}}	// CRE
					)

enum class SDRTRField {
	REIE,		/*!< RES Interrupt Enable*/
	COUNT,		/*!< Refresh Timer Count*/
	CRE,		/*!< Clear Refresh error flag*/
};

static constexpr Register<SDRTRBitList, SDRTRField> SDRTR{BASE_ADDR, 0x154U};
/**@}*/

/**
 * @defgroup	FMC_SDSR_GROUP		SDRAM Status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SDSRBitList, /**/
					Binary<>{BitPos_t{5}},	// BUSY
					Bit<2>{BitPos_t{3}},	// MODES2
					Bit<2>{BitPos_t{1}},	// MODES1
					Binary<>{BitPos_t{0}}	// RE
					)

enum class SDSRField {
	BUSY,		/*!< Busy status*/
	MODES2,		/*!< Status Mode for Bank 2*/
	MODES1,		/*!< Status Mode for Bank 1*/
	RE,		/*!< Refresh error flag*/
};

static constexpr Register<SDSRBitList, SDSRField> SDSR{BASE_ADDR, 0x158U};
/**@}*/


} // cpp_stm32::fsmc::reg
