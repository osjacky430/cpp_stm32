#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::sdio::reg {

static constexpr auto BASE_ADDR = 0x40012800U;

/**
 * @defgroup	SDMMC_POWER_GROUP		power control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(POWERBitList, /**/
					Bit<2>{BitPos_t{0}}	// PWRCTRL
					)

enum class POWERField {
	PWRCTRL,		/*!< PWRCTRL*/
};

static constexpr Register<POWERBitList, POWERField> POWER{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	SDMMC_CLKCR_GROUP		SDI clock control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CLKCRBitList, /**/
					Bit<8>{BitPos_t{0}},	// CLKDIV
					Binary<>{BitPos_t{8}},	// CLKEN
					Binary<>{BitPos_t{9}},	// PWRSAV
					Binary<>{BitPos_t{10}},	// BYPASS
					Bit<2>{BitPos_t{11}},	// WIDBUS
					Binary<>{BitPos_t{13}},	// NEGEDGE
					Binary<>{BitPos_t{14}}	// HWFC_EN
					)

enum class CLKCRField {
	CLKDIV,		/*!< Clock divide factor*/
	CLKEN,		/*!< Clock enable bit*/
	PWRSAV,		/*!< Power saving configuration bit*/
	BYPASS,		/*!< Clock divider bypass enable bit*/
	WIDBUS,		/*!< Wide bus mode enable bit*/
	NEGEDGE,		/*!< SDIO_CK dephasing selection bit*/
	HWFC_EN,		/*!< HW Flow Control enable*/
};

static constexpr Register<CLKCRBitList, CLKCRField> CLKCR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	SDMMC_ARG_GROUP		argument register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ARGBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CMDARG
					)

enum class ARGField {
	CMDARG,		/*!< Command argument*/
};

static constexpr Register<ARGBitList, ARGField> ARG{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	SDMMC_CMD_GROUP		command register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CMDBitList, /**/
					Bit<6>{BitPos_t{0}},	// CMDINDEX
					Bit<2>{BitPos_t{6}},	// WAITRESP
					Binary<>{BitPos_t{8}},	// WAITINT
					Binary<>{BitPos_t{9}},	// WAITPEND
					Binary<>{BitPos_t{10}},	// CPSMEN
					Binary<>{BitPos_t{11}},	// SDIOSuspend
					Binary<>{BitPos_t{12}},	// ENCMDcompl
					Binary<>{BitPos_t{13}},	// nIEN
					Binary<>{BitPos_t{14}}	// CE_ATACMD
					)

enum class CMDField {
	CMDINDEX,		/*!< Command index*/
	WAITRESP,		/*!< Wait for response bits*/
	WAITINT,		/*!< CPSM waits for interrupt request*/
	WAITPEND,		/*!< CPSM Waits for ends of data transfer (CmdPend internal signal)*/
	CPSMEN,		/*!< Command path state machine (CPSM) Enable bit*/
	SDIOSuspend,		/*!< SD I/O suspend command*/
	ENCMDcompl,		/*!< Enable CMD completion*/
	nIEN,		/*!< not Interrupt Enable*/
	CE_ATACMD,		/*!< CE-ATA command*/
};

static constexpr Register<CMDBitList, CMDField> CMD{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	SDMMC_RESPCMD_GROUP		command response register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RESPCMDBitList, /**/
					Bit<6>{BitPos_t{0}}	// RESPCMD
					)

enum class RESPCMDField {
	RESPCMD,		/*!< Response command index*/
};

static constexpr Register<RESPCMDBitList, RESPCMDField> RESPCMD{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	SDMMC_RESP1_GROUP		response 1..4 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RESP1BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CARDSTATUS1
					)

enum class RESP1Field {
	CARDSTATUS1,		/*!< see Table 132*/
};

static constexpr Register<RESP1BitList, RESP1Field> RESP1{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	SDMMC_RESP2_GROUP		response 1..4 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RESP2BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CARDSTATUS2
					)

enum class RESP2Field {
	CARDSTATUS2,		/*!< see Table 132*/
};

static constexpr Register<RESP2BitList, RESP2Field> RESP2{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	SDMMC_RESP3_GROUP		response 1..4 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RESP3BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CARDSTATUS3
					)

enum class RESP3Field {
	CARDSTATUS3,		/*!< see Table 132*/
};

static constexpr Register<RESP3BitList, RESP3Field> RESP3{BASE_ADDR, 0x1cU};
/**@}*/

/**
 * @defgroup	SDMMC_RESP4_GROUP		response 1..4 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RESP4BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CARDSTATUS4
					)

enum class RESP4Field {
	CARDSTATUS4,		/*!< see Table 132*/
};

static constexpr Register<RESP4BitList, RESP4Field> RESP4{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	SDMMC_DTIMER_GROUP		data timer register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DTIMERBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// DATATIME
					)

enum class DTIMERField {
	DATATIME,		/*!< Data timeout period*/
};

static constexpr Register<DTIMERBitList, DTIMERField> DTIMER{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	SDMMC_DLEN_GROUP		data length register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DLENBitList, /**/
					Bit<25, std::uint32_t>{BitPos_t{0}}	// DATALENGTH
					)

enum class DLENField {
	DATALENGTH,		/*!< Data length value*/
};

static constexpr Register<DLENBitList, DLENField> DLEN{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	SDMMC_DCTRL_GROUP		data control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DCTRLBitList, /**/
					Binary<>{BitPos_t{0}},	// DTEN
					Binary<>{BitPos_t{1}},	// DTDIR
					Binary<>{BitPos_t{2}},	// DTMODE
					Binary<>{BitPos_t{3}},	// DMAEN
					Bit<4>{BitPos_t{4}},	// DBLOCKSIZE
					Binary<>{BitPos_t{8}},	// RWSTART
					Binary<>{BitPos_t{9}},	// RWSTOP
					Binary<>{BitPos_t{10}},	// RWMOD
					Binary<>{BitPos_t{11}}	// SDIOEN
					)

enum class DCTRLField {
	DTEN,		/*!< DTEN*/
	DTDIR,		/*!< Data transfer direction selection*/
	DTMODE,		/*!< Data transfer mode selection 1: Stream or SDIO multibyte data transfer*/
	DMAEN,		/*!< DMA enable bit*/
	DBLOCKSIZE,		/*!< Data block size*/
	RWSTART,		/*!< Read wait start*/
	RWSTOP,		/*!< Read wait stop*/
	RWMOD,		/*!< Read wait mode*/
	SDIOEN,		/*!< SD I/O enable functions*/
};

static constexpr Register<DCTRLBitList, DCTRLField> DCTRL{BASE_ADDR, 0x2cU};
/**@}*/

/**
 * @defgroup	SDMMC_DCOUNT_GROUP		data counter register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DCOUNTBitList, /**/
					Bit<25, std::uint32_t>{BitPos_t{0}}	// DATACOUNT
					)

enum class DCOUNTField {
	DATACOUNT,		/*!< Data count value*/
};

static constexpr Register<DCOUNTBitList, DCOUNTField> DCOUNT{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	SDMMC_STA_GROUP		status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(STABitList, /**/
					Binary<>{BitPos_t{0}},	// CCRCFAIL
					Binary<>{BitPos_t{1}},	// DCRCFAIL
					Binary<>{BitPos_t{2}},	// CTIMEOUT
					Binary<>{BitPos_t{3}},	// DTIMEOUT
					Binary<>{BitPos_t{4}},	// TXUNDERR
					Binary<>{BitPos_t{5}},	// RXOVERR
					Binary<>{BitPos_t{6}},	// CMDREND
					Binary<>{BitPos_t{7}},	// CMDSENT
					Binary<>{BitPos_t{8}},	// DATAEND
					Binary<>{BitPos_t{9}},	// STBITERR
					Binary<>{BitPos_t{10}},	// DBCKEND
					Binary<>{BitPos_t{11}},	// CMDACT
					Binary<>{BitPos_t{12}},	// TXACT
					Binary<>{BitPos_t{13}},	// RXACT
					Binary<>{BitPos_t{14}},	// TXFIFOHE
					Binary<>{BitPos_t{15}},	// RXFIFOHF
					Binary<>{BitPos_t{16}},	// TXFIFOF
					Binary<>{BitPos_t{17}},	// RXFIFOF
					Binary<>{BitPos_t{18}},	// TXFIFOE
					Binary<>{BitPos_t{19}},	// RXFIFOE
					Binary<>{BitPos_t{20}},	// TXDAVL
					Binary<>{BitPos_t{21}},	// RXDAVL
					Binary<>{BitPos_t{22}},	// SDIOIT
					Binary<>{BitPos_t{23}}	// CEATAEND
					)

enum class STAField {
	CCRCFAIL,		/*!< Command response received (CRC check failed)*/
	DCRCFAIL,		/*!< Data block sent/received (CRC check failed)*/
	CTIMEOUT,		/*!< Command response timeout*/
	DTIMEOUT,		/*!< Data timeout*/
	TXUNDERR,		/*!< Transmit FIFO underrun error*/
	RXOVERR,		/*!< Received FIFO overrun error*/
	CMDREND,		/*!< Command response received (CRC check passed)*/
	CMDSENT,		/*!< Command sent (no response required)*/
	DATAEND,		/*!< Data end (data counter, SDIDCOUNT, is zero)*/
	STBITERR,		/*!< Start bit not detected on all data signals in wide bus mode*/
	DBCKEND,		/*!< Data block sent/received (CRC check passed)*/
	CMDACT,		/*!< Command transfer in progress*/
	TXACT,		/*!< Data transmit in progress*/
	RXACT,		/*!< Data receive in progress*/
	TXFIFOHE,		/*!< Transmit FIFO half empty: at least 8 words can be written into the FIFO*/
	RXFIFOHF,		/*!< Receive FIFO half full: there are at least 8 words in the FIFO*/
	TXFIFOF,		/*!< Transmit FIFO full*/
	RXFIFOF,		/*!< Receive FIFO full*/
	TXFIFOE,		/*!< Transmit FIFO empty*/
	RXFIFOE,		/*!< Receive FIFO empty*/
	TXDAVL,		/*!< Data available in transmit FIFO*/
	RXDAVL,		/*!< Data available in receive FIFO*/
	SDIOIT,		/*!< SDIO interrupt received*/
	CEATAEND,		/*!< CE-ATA command completion signal received for CMD61*/
};

static constexpr Register<STABitList, STAField> STA{BASE_ADDR, 0x34U};
/**@}*/

/**
 * @defgroup	SDMMC_ICR_GROUP		interrupt clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICRBitList, /**/
					Binary<>{BitPos_t{0}},	// CCRCFAILC
					Binary<>{BitPos_t{1}},	// DCRCFAILC
					Binary<>{BitPos_t{2}},	// CTIMEOUTC
					Binary<>{BitPos_t{3}},	// DTIMEOUTC
					Binary<>{BitPos_t{4}},	// TXUNDERRC
					Binary<>{BitPos_t{5}},	// RXOVERRC
					Binary<>{BitPos_t{6}},	// CMDRENDC
					Binary<>{BitPos_t{7}},	// CMDSENTC
					Binary<>{BitPos_t{8}},	// DATAENDC
					Binary<>{BitPos_t{9}},	// STBITERRC
					Binary<>{BitPos_t{10}},	// DBCKENDC
					Binary<>{BitPos_t{22}},	// SDIOITC
					Binary<>{BitPos_t{23}}	// CEATAENDC
					)

enum class ICRField {
	CCRCFAILC,		/*!< CCRCFAIL flag clear bit*/
	DCRCFAILC,		/*!< DCRCFAIL flag clear bit*/
	CTIMEOUTC,		/*!< CTIMEOUT flag clear bit*/
	DTIMEOUTC,		/*!< DTIMEOUT flag clear bit*/
	TXUNDERRC,		/*!< TXUNDERR flag clear bit*/
	RXOVERRC,		/*!< RXOVERR flag clear bit*/
	CMDRENDC,		/*!< CMDREND flag clear bit*/
	CMDSENTC,		/*!< CMDSENT flag clear bit*/
	DATAENDC,		/*!< DATAEND flag clear bit*/
	STBITERRC,		/*!< STBITERR flag clear bit*/
	DBCKENDC,		/*!< DBCKEND flag clear bit*/
	SDIOITC,		/*!< SDIOIT flag clear bit*/
	CEATAENDC,		/*!< CEATAEND flag clear bit*/
};

static constexpr Register<ICRBitList, ICRField> ICR{BASE_ADDR, 0x38U};
/**@}*/

/**
 * @defgroup	SDMMC_MASK_GROUP		mask register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MASKBitList, /**/
					Binary<>{BitPos_t{0}},	// CCRCFAILIE
					Binary<>{BitPos_t{1}},	// DCRCFAILIE
					Binary<>{BitPos_t{2}},	// CTIMEOUTIE
					Binary<>{BitPos_t{3}},	// DTIMEOUTIE
					Binary<>{BitPos_t{4}},	// TXUNDERRIE
					Binary<>{BitPos_t{5}},	// RXOVERRIE
					Binary<>{BitPos_t{6}},	// CMDRENDIE
					Binary<>{BitPos_t{7}},	// CMDSENTIE
					Binary<>{BitPos_t{8}},	// DATAENDIE
					Binary<>{BitPos_t{9}},	// STBITERRIE
					Binary<>{BitPos_t{10}},	// DBCKENDIE
					Binary<>{BitPos_t{11}},	// CMDACTIE
					Binary<>{BitPos_t{12}},	// TXACTIE
					Binary<>{BitPos_t{13}},	// RXACTIE
					Binary<>{BitPos_t{14}},	// TXFIFOHEIE
					Binary<>{BitPos_t{15}},	// RXFIFOHFIE
					Binary<>{BitPos_t{16}},	// TXFIFOFIE
					Binary<>{BitPos_t{17}},	// RXFIFOFIE
					Binary<>{BitPos_t{18}},	// TXFIFOEIE
					Binary<>{BitPos_t{19}},	// RXFIFOEIE
					Binary<>{BitPos_t{20}},	// TXDAVLIE
					Binary<>{BitPos_t{21}},	// RXDAVLIE
					Binary<>{BitPos_t{22}},	// SDIOITIE
					Binary<>{BitPos_t{23}}	// CEATAENDIE
					)

enum class MASKField {
	CCRCFAILIE,		/*!< Command CRC fail interrupt enable*/
	DCRCFAILIE,		/*!< Data CRC fail interrupt enable*/
	CTIMEOUTIE,		/*!< Command timeout interrupt enable*/
	DTIMEOUTIE,		/*!< Data timeout interrupt enable*/
	TXUNDERRIE,		/*!< Tx FIFO underrun error interrupt enable*/
	RXOVERRIE,		/*!< Rx FIFO overrun error interrupt enable*/
	CMDRENDIE,		/*!< Command response received interrupt enable*/
	CMDSENTIE,		/*!< Command sent interrupt enable*/
	DATAENDIE,		/*!< Data end interrupt enable*/
	STBITERRIE,		/*!< Start bit error interrupt enable*/
	DBCKENDIE,		/*!< Data block end interrupt enable*/
	CMDACTIE,		/*!< Command acting interrupt enable*/
	TXACTIE,		/*!< Data transmit acting interrupt enable*/
	RXACTIE,		/*!< Data receive acting interrupt enable*/
	TXFIFOHEIE,		/*!< Tx FIFO half empty interrupt enable*/
	RXFIFOHFIE,		/*!< Rx FIFO half full interrupt enable*/
	TXFIFOFIE,		/*!< Tx FIFO full interrupt enable*/
	RXFIFOFIE,		/*!< Rx FIFO full interrupt enable*/
	TXFIFOEIE,		/*!< Tx FIFO empty interrupt enable*/
	RXFIFOEIE,		/*!< Rx FIFO empty interrupt enable*/
	TXDAVLIE,		/*!< Data available in Tx FIFO interrupt enable*/
	RXDAVLIE,		/*!< Data available in Rx FIFO interrupt enable*/
	SDIOITIE,		/*!< SDIO mode interrupt received interrupt enable*/
	CEATAENDIE,		/*!< CE-ATA command completion signal received interrupt enable*/
};

static constexpr Register<MASKBitList, MASKField> MASK{BASE_ADDR, 0x3cU};
/**@}*/

/**
 * @defgroup	SDMMC_FIFOCNT_GROUP		FIFO counter register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FIFOCNTBitList, /**/
					Bit<24, std::uint32_t>{BitPos_t{0}}	// FIFOCOUNT
					)

enum class FIFOCNTField {
	FIFOCOUNT,		/*!< Remaining number of words to be written to or read from the FIFO*/
};

static constexpr Register<FIFOCNTBitList, FIFOCNTField> FIFOCNT{BASE_ADDR, 0x48U};
/**@}*/

/**
 * @defgroup	SDMMC_FIFO_GROUP		data FIFO register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FIFOBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// FIFOData
					)

enum class FIFOField {
	FIFOData,		/*!< Receive and transmit FIFO data*/
};

static constexpr Register<FIFOBitList, FIFOField> FIFO{BASE_ADDR, 0x80U};
/**@}*/


} // cpp_stm32::sdio::reg
