#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::usb::reg {

static constexpr auto BASE_ADDR(Port const& t_usb) {
	switch(t_usb) {
	case Port::USB_SRAM:
		return 0x40006c00U;
	case Port::USB_FS:
		return 0x40006800U;
}
	}

/**
 * @defgroup	USB_FS_EP0R_GROUP		endpoint 0 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(EP0RBitList, /**/
					Binary<>{BitPos_t{15}},	// CTR_RX
					Binary<>{BitPos_t{14}},	// DTOG_RX
					Bit<2>{BitPos_t{12}},	// STAT_RX
					Binary<>{BitPos_t{11}},	// SETUP
					Bit<2>{BitPos_t{9}},	// EP_TYPE
					Binary<>{BitPos_t{8}},	// EP_KIND
					Binary<>{BitPos_t{7}},	// CTR_TX
					Binary<>{BitPos_t{6}},	// DTOG_TX
					Bit<2>{BitPos_t{4}},	// STAT_TX
					Bit<4>{BitPos_t{0}}	// EA
					)

enum class EP0RField {
	CTR_RX,		/*!< Correct transfer for reception*/
	DTOG_RX,		/*!< Data Toggle, for reception transfers*/
	STAT_RX,		/*!< Status bits, for reception transfers*/
	SETUP,		/*!< Setup transaction completed*/
	EP_TYPE,		/*!< Endpoint type*/
	EP_KIND,		/*!< Endpoint kind*/
	CTR_TX,		/*!< Correct Transfer for transmission*/
	DTOG_TX,		/*!< Data Toggle, for transmission transfers*/
	STAT_TX,		/*!< Status bits, for transmission transfers*/
	EA,		/*!< Endpoint address*/
};

template <Port USB>
static constexpr Register<EP0RBitList, EP0RField> EP0R{BASE_ADDR(USB), 0x00U};
/**@}*/

/**
 * @defgroup	USB_FS_EP1R_GROUP		endpoint 1 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(EP1RBitList, /**/
					Binary<>{BitPos_t{15}},	// CTR_RX
					Binary<>{BitPos_t{14}},	// DTOG_RX
					Bit<2>{BitPos_t{12}},	// STAT_RX
					Binary<>{BitPos_t{11}},	// SETUP
					Bit<2>{BitPos_t{9}},	// EP_TYPE
					Binary<>{BitPos_t{8}},	// EP_KIND
					Binary<>{BitPos_t{7}},	// CTR_TX
					Binary<>{BitPos_t{6}},	// DTOG_TX
					Bit<2>{BitPos_t{4}},	// STAT_TX
					Bit<4>{BitPos_t{0}}	// EA
					)

enum class EP1RField {
	CTR_RX,		/*!< Correct transfer for reception*/
	DTOG_RX,		/*!< Data Toggle, for reception transfers*/
	STAT_RX,		/*!< Status bits, for reception transfers*/
	SETUP,		/*!< Setup transaction completed*/
	EP_TYPE,		/*!< Endpoint type*/
	EP_KIND,		/*!< Endpoint kind*/
	CTR_TX,		/*!< Correct Transfer for transmission*/
	DTOG_TX,		/*!< Data Toggle, for transmission transfers*/
	STAT_TX,		/*!< Status bits, for transmission transfers*/
	EA,		/*!< Endpoint address*/
};

template <Port USB>
static constexpr Register<EP1RBitList, EP1RField> EP1R{BASE_ADDR(USB), 0x04U};
/**@}*/

/**
 * @defgroup	USB_FS_EP2R_GROUP		endpoint 2 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(EP2RBitList, /**/
					Binary<>{BitPos_t{15}},	// CTR_RX
					Binary<>{BitPos_t{14}},	// DTOG_RX
					Bit<2>{BitPos_t{12}},	// STAT_RX
					Binary<>{BitPos_t{11}},	// SETUP
					Bit<2>{BitPos_t{9}},	// EP_TYPE
					Binary<>{BitPos_t{8}},	// EP_KIND
					Binary<>{BitPos_t{7}},	// CTR_TX
					Binary<>{BitPos_t{6}},	// DTOG_TX
					Bit<2>{BitPos_t{4}},	// STAT_TX
					Bit<4>{BitPos_t{0}}	// EA
					)

enum class EP2RField {
	CTR_RX,		/*!< Correct transfer for reception*/
	DTOG_RX,		/*!< Data Toggle, for reception transfers*/
	STAT_RX,		/*!< Status bits, for reception transfers*/
	SETUP,		/*!< Setup transaction completed*/
	EP_TYPE,		/*!< Endpoint type*/
	EP_KIND,		/*!< Endpoint kind*/
	CTR_TX,		/*!< Correct Transfer for transmission*/
	DTOG_TX,		/*!< Data Toggle, for transmission transfers*/
	STAT_TX,		/*!< Status bits, for transmission transfers*/
	EA,		/*!< Endpoint address*/
};

template <Port USB>
static constexpr Register<EP2RBitList, EP2RField> EP2R{BASE_ADDR(USB), 0x08U};
/**@}*/

/**
 * @defgroup	USB_FS_EP3R_GROUP		endpoint 3 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(EP3RBitList, /**/
					Binary<>{BitPos_t{15}},	// CTR_RX
					Binary<>{BitPos_t{14}},	// DTOG_RX
					Bit<2>{BitPos_t{12}},	// STAT_RX
					Binary<>{BitPos_t{11}},	// SETUP
					Bit<2>{BitPos_t{9}},	// EP_TYPE
					Binary<>{BitPos_t{8}},	// EP_KIND
					Binary<>{BitPos_t{7}},	// CTR_TX
					Binary<>{BitPos_t{6}},	// DTOG_TX
					Bit<2>{BitPos_t{4}},	// STAT_TX
					Bit<4>{BitPos_t{0}}	// EA
					)

enum class EP3RField {
	CTR_RX,		/*!< Correct transfer for reception*/
	DTOG_RX,		/*!< Data Toggle, for reception transfers*/
	STAT_RX,		/*!< Status bits, for reception transfers*/
	SETUP,		/*!< Setup transaction completed*/
	EP_TYPE,		/*!< Endpoint type*/
	EP_KIND,		/*!< Endpoint kind*/
	CTR_TX,		/*!< Correct Transfer for transmission*/
	DTOG_TX,		/*!< Data Toggle, for transmission transfers*/
	STAT_TX,		/*!< Status bits, for transmission transfers*/
	EA,		/*!< Endpoint address*/
};

template <Port USB>
static constexpr Register<EP3RBitList, EP3RField> EP3R{BASE_ADDR(USB), 0x0cU};
/**@}*/

/**
 * @defgroup	USB_FS_EP4R_GROUP		endpoint 4 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(EP4RBitList, /**/
					Binary<>{BitPos_t{15}},	// CTR_RX
					Binary<>{BitPos_t{14}},	// DTOG_RX
					Bit<2>{BitPos_t{12}},	// STAT_RX
					Binary<>{BitPos_t{11}},	// SETUP
					Bit<2>{BitPos_t{9}},	// EP_TYPE
					Binary<>{BitPos_t{8}},	// EP_KIND
					Binary<>{BitPos_t{7}},	// CTR_TX
					Binary<>{BitPos_t{6}},	// DTOG_TX
					Bit<2>{BitPos_t{4}},	// STAT_TX
					Bit<4>{BitPos_t{0}}	// EA
					)

enum class EP4RField {
	CTR_RX,		/*!< Correct transfer for reception*/
	DTOG_RX,		/*!< Data Toggle, for reception transfers*/
	STAT_RX,		/*!< Status bits, for reception transfers*/
	SETUP,		/*!< Setup transaction completed*/
	EP_TYPE,		/*!< Endpoint type*/
	EP_KIND,		/*!< Endpoint kind*/
	CTR_TX,		/*!< Correct Transfer for transmission*/
	DTOG_TX,		/*!< Data Toggle, for transmission transfers*/
	STAT_TX,		/*!< Status bits, for transmission transfers*/
	EA,		/*!< Endpoint address*/
};

template <Port USB>
static constexpr Register<EP4RBitList, EP4RField> EP4R{BASE_ADDR(USB), 0x10U};
/**@}*/

/**
 * @defgroup	USB_FS_EP5R_GROUP		endpoint 5 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(EP5RBitList, /**/
					Binary<>{BitPos_t{15}},	// CTR_RX
					Binary<>{BitPos_t{14}},	// DTOG_RX
					Bit<2>{BitPos_t{12}},	// STAT_RX
					Binary<>{BitPos_t{11}},	// SETUP
					Bit<2>{BitPos_t{9}},	// EP_TYPE
					Binary<>{BitPos_t{8}},	// EP_KIND
					Binary<>{BitPos_t{7}},	// CTR_TX
					Binary<>{BitPos_t{6}},	// DTOG_TX
					Bit<2>{BitPos_t{4}},	// STAT_TX
					Bit<4>{BitPos_t{0}}	// EA
					)

enum class EP5RField {
	CTR_RX,		/*!< Correct transfer for reception*/
	DTOG_RX,		/*!< Data Toggle, for reception transfers*/
	STAT_RX,		/*!< Status bits, for reception transfers*/
	SETUP,		/*!< Setup transaction completed*/
	EP_TYPE,		/*!< Endpoint type*/
	EP_KIND,		/*!< Endpoint kind*/
	CTR_TX,		/*!< Correct Transfer for transmission*/
	DTOG_TX,		/*!< Data Toggle, for transmission transfers*/
	STAT_TX,		/*!< Status bits, for transmission transfers*/
	EA,		/*!< Endpoint address*/
};

template <Port USB>
static constexpr Register<EP5RBitList, EP5RField> EP5R{BASE_ADDR(USB), 0x14U};
/**@}*/

/**
 * @defgroup	USB_FS_EP6R_GROUP		endpoint 6 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(EP6RBitList, /**/
					Binary<>{BitPos_t{15}},	// CTR_RX
					Binary<>{BitPos_t{14}},	// DTOG_RX
					Bit<2>{BitPos_t{12}},	// STAT_RX
					Binary<>{BitPos_t{11}},	// SETUP
					Bit<2>{BitPos_t{9}},	// EP_TYPE
					Binary<>{BitPos_t{8}},	// EP_KIND
					Binary<>{BitPos_t{7}},	// CTR_TX
					Binary<>{BitPos_t{6}},	// DTOG_TX
					Bit<2>{BitPos_t{4}},	// STAT_TX
					Bit<4>{BitPos_t{0}}	// EA
					)

enum class EP6RField {
	CTR_RX,		/*!< Correct transfer for reception*/
	DTOG_RX,		/*!< Data Toggle, for reception transfers*/
	STAT_RX,		/*!< Status bits, for reception transfers*/
	SETUP,		/*!< Setup transaction completed*/
	EP_TYPE,		/*!< Endpoint type*/
	EP_KIND,		/*!< Endpoint kind*/
	CTR_TX,		/*!< Correct Transfer for transmission*/
	DTOG_TX,		/*!< Data Toggle, for transmission transfers*/
	STAT_TX,		/*!< Status bits, for transmission transfers*/
	EA,		/*!< Endpoint address*/
};

template <Port USB>
static constexpr Register<EP6RBitList, EP6RField> EP6R{BASE_ADDR(USB), 0x18U};
/**@}*/

/**
 * @defgroup	USB_FS_EP7R_GROUP		endpoint 7 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(EP7RBitList, /**/
					Binary<>{BitPos_t{15}},	// CTR_RX
					Binary<>{BitPos_t{14}},	// DTOG_RX
					Bit<2>{BitPos_t{12}},	// STAT_RX
					Binary<>{BitPos_t{11}},	// SETUP
					Bit<2>{BitPos_t{9}},	// EP_TYPE
					Binary<>{BitPos_t{8}},	// EP_KIND
					Binary<>{BitPos_t{7}},	// CTR_TX
					Binary<>{BitPos_t{6}},	// DTOG_TX
					Bit<2>{BitPos_t{4}},	// STAT_TX
					Bit<4>{BitPos_t{0}}	// EA
					)

enum class EP7RField {
	CTR_RX,		/*!< Correct transfer for reception*/
	DTOG_RX,		/*!< Data Toggle, for reception transfers*/
	STAT_RX,		/*!< Status bits, for reception transfers*/
	SETUP,		/*!< Setup transaction completed*/
	EP_TYPE,		/*!< Endpoint type*/
	EP_KIND,		/*!< Endpoint kind*/
	CTR_TX,		/*!< Correct Transfer for transmission*/
	DTOG_TX,		/*!< Data Toggle, for transmission transfers*/
	STAT_TX,		/*!< Status bits, for transmission transfers*/
	EA,		/*!< Endpoint address*/
};

template <Port USB>
static constexpr Register<EP7RBitList, EP7RField> EP7R{BASE_ADDR(USB), 0x1cU};
/**@}*/

/**
 * @defgroup	USB_FS_CNTR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CNTRBitList, /**/
					Binary<>{BitPos_t{15}},	// CTRM
					Binary<>{BitPos_t{14}},	// PMAOVRM
					Binary<>{BitPos_t{13}},	// ERRM
					Binary<>{BitPos_t{12}},	// WKUPM
					Binary<>{BitPos_t{11}},	// SUSPM
					Binary<>{BitPos_t{10}},	// RESETM
					Binary<>{BitPos_t{9}},	// SOFM
					Binary<>{BitPos_t{8}},	// ESOFM
					Binary<>{BitPos_t{7}},	// L1REQM
					Binary<>{BitPos_t{5}},	// L1RESUME
					Binary<>{BitPos_t{4}},	// RESUME
					Binary<>{BitPos_t{3}},	// FSUSP
					Binary<>{BitPos_t{2}},	// LPMODE
					Binary<>{BitPos_t{1}},	// PDWN
					Binary<>{BitPos_t{0}}	// FRES
					)

enum class CNTRField {
	CTRM,		/*!< Correct transfer interrupt mask*/
	PMAOVRM,		/*!< Packet memory area over / underrun interrupt mask*/
	ERRM,		/*!< Error interrupt mask*/
	WKUPM,		/*!< Wakeup interrupt mask*/
	SUSPM,		/*!< Suspend mode interrupt mask*/
	RESETM,		/*!< USB reset interrupt mask*/
	SOFM,		/*!< Start of frame interrupt mask*/
	ESOFM,		/*!< Expected start of frame interrupt mask*/
	L1REQM,		/*!< LPM L1 state request interrupt mask*/
	L1RESUME,		/*!< LPM L1 Resume request*/
	RESUME,		/*!< Resume request*/
	FSUSP,		/*!< Force suspend*/
	LPMODE,		/*!< Low-power mode*/
	PDWN,		/*!< Power down*/
	FRES,		/*!< Force USB Reset*/
};

template <Port USB>
static constexpr Register<CNTRBitList, CNTRField> CNTR{BASE_ADDR(USB), 0x40U};
/**@}*/

/**
 * @defgroup	USB_FS_ISTR_GROUP		interrupt status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISTRBitList, /**/
					StatusBit<1>{BitPos_t{15}},	// CTR
					Binary<>{BitPos_t{14}},	// PMAOVR
					Binary<>{BitPos_t{13}},	// ERR
					Binary<>{BitPos_t{12}},	// WKUP
					Binary<>{BitPos_t{11}},	// SUSP
					Binary<>{BitPos_t{10}},	// RESET
					Binary<>{BitPos_t{9}},	// SOF
					Binary<>{BitPos_t{8}},	// ESOF
					Binary<>{BitPos_t{7}},	// L1REQ
					StatusBit<1>{BitPos_t{4}},	// DIR
					StatusBit<4>{BitPos_t{0}}	// EP_ID
					)

enum class ISTRField {
	CTR,		/*!< Correct transfer*/
	PMAOVR,		/*!< Packet memory area over / underrun*/
	ERR,		/*!< Error*/
	WKUP,		/*!< Wakeup*/
	SUSP,		/*!< Suspend mode request*/
	RESET,		/*!< reset request*/
	SOF,		/*!< start of frame*/
	ESOF,		/*!< Expected start frame*/
	L1REQ,		/*!< LPM L1 state request*/
	DIR,		/*!< Direction of transaction*/
	EP_ID,		/*!< Endpoint Identifier*/
};

template <Port USB>
static constexpr Register<ISTRBitList, ISTRField> ISTR{BASE_ADDR(USB), 0x44U};
/**@}*/

/**
 * @defgroup	USB_FS_FNR_GROUP		frame number register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FNRBitList, /**/
					Binary<>{BitPos_t{15}},	// RXDP
					Binary<>{BitPos_t{14}},	// RXDM
					Binary<>{BitPos_t{13}},	// LCK
					Bit<2>{BitPos_t{11}},	// LSOF
					Bit<11, std::uint16_t>{BitPos_t{0}}	// FN
					)

enum class FNRField {
	RXDP,		/*!< Receive data + line status*/
	RXDM,		/*!< Receive data - line status*/
	LCK,		/*!< Locked*/
	LSOF,		/*!< Lost SOF*/
	FN,		/*!< Frame number*/
};

template <Port USB>
static constexpr Register<FNRBitList, FNRField> FNR{BASE_ADDR(USB), 0x48U};
/**@}*/

/**
 * @defgroup	USB_FS_DADDR_GROUP		device address group
 *
 * @{
 */

SETUP_REGISTER_INFO(DADDRBitList, /**/
					Binary<>{BitPos_t{7}},	// EF
					Bit<7>{BitPos_t{0}}	// ADD
					)

enum class DADDRField {
	EF,		/*!< Enable function*/
	ADD,		/*!< Device address*/
};

template <Port USB>
static constexpr Register<DADDRBitList, DADDRField> DADDR{BASE_ADDR(USB), 0x4cU};
/**@}*/

/**
 * @defgroup	USB_FS_BTABLE_GROUP		Buffer table address group
 *
 * @{
 */

SETUP_REGISTER_INFO(BTABLEBitList, /**/
					Bit<13, std::uint16_t>{BitPos_t{3}}	// BTABLE
					)

enum class BTABLEField {
	BTABLE,		/*!< Buffer table*/
};

template <Port USB>
static constexpr Register<BTABLEBitList, BTABLEField> BTABLE{BASE_ADDR(USB), 0x50U};
/**@}*/

/**
 * @defgroup	USB_FS_LPMCSR_GROUP		LPM control and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(LPMCSRBitList, /**/
					StatusBit<4>{BitPos_t{4}},	// BESL
					StatusBit<1>{BitPos_t{3}},	// REMWAKE
					Binary<>{BitPos_t{1}},	// LPMACK
					Binary<>{BitPos_t{0}}	// LPMEN
					)

enum class LPMCSRField {
	BESL,		/*!< BESL value*/
	REMWAKE,		/*!< bRemoteWake value*/
	LPMACK,		/*!< LPM Token acknowledge enable*/
	LPMEN,		/*!< LPM support enable*/
};

template <Port USB>
static constexpr Register<LPMCSRBitList, LPMCSRField> LPMCSR{BASE_ADDR(USB), 0x54U};
/**@}*/

/**
 * @defgroup	USB_FS_BCDR_GROUP		Battery charging detector group
 *
 * @{
 */

SETUP_REGISTER_INFO(BCDRBitList, /**/
					Binary<>{BitPos_t{15}},	// DPPU
					StatusBit<1>{BitPos_t{7}},	// PS2DET
					StatusBit<2>{BitPos_t{6}},	// SD
					StatusBit<2>{BitPos_t{5}},	// PD
					StatusBit<2>{BitPos_t{4}},	// DCD
					Binary<>{BitPos_t{0}}	// BCDEN
					)

enum class BCDRField {
	DPPU,		/*!< DP pull-up control*/
	PS2DET,		/*!< DM pull-up detection status*/
	SD,		/*!< Secondary detection*/
	PD,		/*!< Primary detection*/
	DCD,		/*!< Data contact detection*/
	BCDEN,		/*!< Battery charging detector*/
};

template <Port USB>
static constexpr Register<BCDRBitList, BCDRField> BCDR{BASE_ADDR(USB), 0x58U};
/**@}*/


} // cpp_stm32::usb::reg
