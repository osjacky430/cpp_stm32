#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::spdif_rx::reg {

static constexpr auto BASE_ADDR = 0x40004000U;

/**
 * @defgroup	SPDIF_RX_CR_GROUP		Control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Bit<3>{BitPos_t{16}},	// INSEL
					Binary<>{BitPos_t{14}},	// WFA
					Bit<2>{BitPos_t{12}},	// NBTR
					Binary<>{BitPos_t{11}},	// CHSEL
					Binary<>{BitPos_t{10}},	// CBDMAEN
					Binary<>{BitPos_t{9}},	// PTMSK
					Binary<>{BitPos_t{8}},	// CUMSK
					Binary<>{BitPos_t{7}},	// VMSK
					Binary<>{BitPos_t{6}},	// PMSK
					Bit<2>{BitPos_t{4}},	// DRFMT
					Binary<>{BitPos_t{3}},	// RXSTEO
					Binary<>{BitPos_t{2}},	// RXDMAEN
					Bit<2>{BitPos_t{0}}	// SPDIFEN
					)

enum class CRField {
	INSEL,		/*!< input selection*/
	WFA,		/*!< Wait For Activity*/
	NBTR,		/*!< Maximum allowed re-tries during synchronization phase*/
	CHSEL,		/*!< Channel Selection*/
	CBDMAEN,		/*!< Control Buffer DMA ENable for control flow*/
	PTMSK,		/*!< Mask of Preamble Type bits*/
	CUMSK,		/*!< Mask of channel status and user bits*/
	VMSK,		/*!< Mask of Validity bit*/
	PMSK,		/*!< Mask Parity error bit*/
	DRFMT,		/*!< RX Data format*/
	RXSTEO,		/*!< STerEO Mode*/
	RXDMAEN,		/*!< Receiver DMA ENable for data flow*/
	SPDIFEN,		/*!< Peripheral Block Enable*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	SPDIF_RX_IMR_GROUP		Interrupt mask register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IMRBitList, /**/
					Binary<>{BitPos_t{6}},	// IFEIE
					Binary<>{BitPos_t{5}},	// SYNCDIE
					Binary<>{BitPos_t{4}},	// SBLKIE
					Binary<>{BitPos_t{3}},	// OVRIE
					Binary<>{BitPos_t{2}},	// PERRIE
					Binary<>{BitPos_t{1}},	// CSRNEIE
					Binary<>{BitPos_t{0}}	// RXNEIE
					)

enum class IMRField {
	IFEIE,		/*!< Serial Interface Error Interrupt Enable*/
	SYNCDIE,		/*!< Synchronization Done*/
	SBLKIE,		/*!< Synchronization Block Detected Interrupt Enable*/
	OVRIE,		/*!< Overrun error Interrupt Enable*/
	PERRIE,		/*!< Parity error interrupt enable*/
	CSRNEIE,		/*!< Control Buffer Ready Interrupt Enable*/
	RXNEIE,		/*!< RXNE interrupt enable*/
};

static constexpr Register<IMRBitList, IMRField> IMR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	SPDIF_RX_SR_GROUP		Status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					Bit<15, std::uint16_t>{BitPos_t{16}},	// WIDTH5
					Binary<>{BitPos_t{8}},	// TERR
					Binary<>{BitPos_t{7}},	// SERR
					Binary<>{BitPos_t{6}},	// FERR
					Binary<>{BitPos_t{5}},	// SYNCD
					Binary<>{BitPos_t{4}},	// SBD
					Binary<>{BitPos_t{3}},	// OVR
					Binary<>{BitPos_t{2}},	// PERR
					Binary<>{BitPos_t{1}},	// CSRNE
					Binary<>{BitPos_t{0}}	// RXNE
					)

enum class SRField {
	WIDTH5,		/*!< Duration of 5 symbols counted with SPDIF_CLK*/
	TERR,		/*!< Time-out error*/
	SERR,		/*!< Synchronization error*/
	FERR,		/*!< Framing error*/
	SYNCD,		/*!< Synchronization Done*/
	SBD,		/*!< Synchronization Block Detected*/
	OVR,		/*!< Overrun error*/
	PERR,		/*!< Parity error*/
	CSRNE,		/*!< Control Buffer register is not empty*/
	RXNE,		/*!< Read data register not empty*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	SPDIF_RX_IFCR_GROUP		Interrupt Flag Clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IFCRBitList, /**/
					Binary<>{BitPos_t{5}},	// SYNCDCF
					Binary<>{BitPos_t{4}},	// SBDCF
					Binary<>{BitPos_t{3}},	// OVRCF
					Binary<>{BitPos_t{2}}	// PERRCF
					)

enum class IFCRField {
	SYNCDCF,		/*!< Clears the Synchronization Done flag*/
	SBDCF,		/*!< Clears the Synchronization Block Detected flag*/
	OVRCF,		/*!< Clears the Overrun error flag*/
	PERRCF,		/*!< Clears the Parity error flag*/
};

static constexpr Register<IFCRBitList, IFCRField> IFCR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	SPDIF_RX_DR_GROUP		Data input register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DRBitList, /**/
					Bit<2>{BitPos_t{28}},	// PT
					Binary<>{BitPos_t{27}},	// C
					Binary<>{BitPos_t{26}},	// U
					Binary<>{BitPos_t{25}},	// V
					Bit<2>{BitPos_t{24}}	// P
					)

enum class DRField {
	PT,		/*!< Preamble Type*/
	C,		/*!< Channel Status bit*/
	U,		/*!< User bit*/
	V,		/*!< Validity bit*/
	P,		/*!< Parity Error bit*/
};

static constexpr Register<DRBitList, DRField> DR{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	SPDIF_RX_CSR_GROUP		Channel Status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CSRBitList, /**/
					Binary<>{BitPos_t{24}},	// SOB
					Bit<8>{BitPos_t{16}},	// CS
					Bit<16, std::uint16_t>{BitPos_t{0}}	// USR
					)

enum class CSRField {
	SOB,		/*!< Start Of Block*/
	CS,		/*!< Channel A status information*/
	USR,		/*!< User data information*/
};

static constexpr Register<CSRBitList, CSRField> CSR{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	SPDIF_RX_DIR_GROUP		Debug Information register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DIRBitList, /**/
					Bit<13, std::uint16_t>{BitPos_t{16}},	// TLO
					Bit<13, std::uint16_t>{BitPos_t{0}}	// THI
					)

enum class DIRField {
	TLO,		/*!< Threshold LOW*/
	THI,		/*!< Threshold HIGH*/
};

static constexpr Register<DIRBitList, DIRField> DIR{BASE_ADDR, 0x18U};
/**@}*/


} // cpp_stm32::spdif_rx::reg
