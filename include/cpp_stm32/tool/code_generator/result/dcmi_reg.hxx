#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::dcmi::reg {

static constexpr auto BASE_ADDR = 0x50050000U;

/**
 * @defgroup	DCMI_CR_GROUP		control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Bit<2>{BitPos_t{8}},	// FCRC
					StatusBit<1>{BitPos_t{20}},	// OELS
					StatusBit<1>{BitPos_t{19}},	// LSM
					StatusBit<1>{BitPos_t{18}},	// OEBS
					StatusBit<2>{BitPos_t{16}},	// BSM
					Binary<>{BitPos_t{14}},	// ENABLE
					Bit<2>{BitPos_t{10}},	// EDM
					Binary<>{BitPos_t{7}},	// VSPOL
					Binary<>{BitPos_t{6}},	// HSPOL
					Binary<>{BitPos_t{5}},	// PCKPOL
					Binary<>{BitPos_t{4}},	// ESS
					Binary<>{BitPos_t{3}},	// JPEG
					Binary<>{BitPos_t{2}},	// CROP
					Binary<>{BitPos_t{1}},	// CM
					StatusBit<1>{BitPos_t{0}}	// CAPTURE
					)

enum class CRField {
	FCRC,		/*!< Frame capture rate control*/
	OELS,		/*!< Odd/Even Line Select*/
	LSM,		/*!< Line Select mode*/
	OEBS,		/*!< Odd/Even Byte Select*/
	BSM,		/*!< Byte Select mode*/
	ENABLE,		/*!< DCMI enable*/
	EDM,		/*!< Extended data mode*/
	VSPOL,		/*!< Vertical synchronization polarity*/
	HSPOL,		/*!< Horizontal synchronization polarity*/
	PCKPOL,		/*!< Pixel clock polarity*/
	ESS,		/*!< Embedded synchronization select*/
	JPEG,		/*!< JPEG format*/
	CROP,		/*!< Crop feature*/
	CM,		/*!< Capture mode*/
	CAPTURE,		/*!< Capture enable*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	DCMI_SR_GROUP		status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					Binary<>{BitPos_t{0}},	// HSYNC
					Binary<>{BitPos_t{1}},	// VSYNC
					Binary<>{BitPos_t{2}}	// FNE
					)

enum class SRField {
	HSYNC,		/*!< HSYNC*/
	VSYNC,		/*!< VSYNC*/
	FNE,		/*!< FIFO not empty*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	DCMI_RIS_GROUP		raw interrupt status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RISBitList, /**/
					Binary<>{BitPos_t{0}},	// FRAME_RIS
					Binary<>{BitPos_t{1}},	// OVR_RIS
					Binary<>{BitPos_t{2}},	// ERR_RIS
					Binary<>{BitPos_t{3}},	// VSYNC_RIS
					Binary<>{BitPos_t{4}}	// LINE_RIS
					)

enum class RISField {
	FRAME_RIS,		/*!< Capture complete raw interrupt status*/
	OVR_RIS,		/*!< Overrun raw interrupt status*/
	ERR_RIS,		/*!< Synchronization error raw interrupt status*/
	VSYNC_RIS,		/*!< VSYNC raw interrupt status*/
	LINE_RIS,		/*!< Line raw interrupt status*/
};

static constexpr Register<RISBitList, RISField> RIS{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	DCMI_IER_GROUP		interrupt enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IERBitList, /**/
					Binary<>{BitPos_t{0}},	// FRAME_IE
					Binary<>{BitPos_t{1}},	// OVR_IE
					Binary<>{BitPos_t{2}},	// ERR_IE
					Binary<>{BitPos_t{3}},	// VSYNC_IE
					Binary<>{BitPos_t{4}}	// LINE_IE
					)

enum class IERField {
	FRAME_IE,		/*!< Capture complete interrupt enable*/
	OVR_IE,		/*!< Overrun interrupt enable*/
	ERR_IE,		/*!< Synchronization error interrupt enable*/
	VSYNC_IE,		/*!< VSYNC interrupt enable*/
	LINE_IE,		/*!< Line interrupt enable*/
};

static constexpr Register<IERBitList, IERField> IER{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	DCMI_MIS_GROUP		masked interrupt status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MISBitList, /**/
					Binary<>{BitPos_t{0}},	// FRAME_MIS
					Binary<>{BitPos_t{1}},	// OVR_MIS
					Binary<>{BitPos_t{2}},	// ERR_MIS
					Binary<>{BitPos_t{3}},	// VSYNC_MIS
					Binary<>{BitPos_t{4}}	// LINE_MIS
					)

enum class MISField {
	FRAME_MIS,		/*!< Capture complete masked interrupt status*/
	OVR_MIS,		/*!< Overrun masked interrupt status*/
	ERR_MIS,		/*!< Synchronization error masked interrupt status*/
	VSYNC_MIS,		/*!< VSYNC masked interrupt status*/
	LINE_MIS,		/*!< Line masked interrupt status*/
};

static constexpr Register<MISBitList, MISField> MIS{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	DCMI_ICR_GROUP		interrupt clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICRBitList, /**/
					Binary<>{BitPos_t{0}},	// FRAME_ISC
					Binary<>{BitPos_t{1}},	// OVR_ISC
					Binary<>{BitPos_t{2}},	// ERR_ISC
					Binary<>{BitPos_t{3}},	// VSYNC_ISC
					Binary<>{BitPos_t{4}}	// LINE_ISC
					)

enum class ICRField {
	FRAME_ISC,		/*!< Capture complete interrupt status clear*/
	OVR_ISC,		/*!< Overrun interrupt status clear*/
	ERR_ISC,		/*!< Synchronization error interrupt status clear*/
	VSYNC_ISC,		/*!< Vertical synch interrupt status clear*/
	LINE_ISC,		/*!< line interrupt status clear*/
};

static constexpr Register<ICRBitList, ICRField> ICR{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	DCMI_ESCR_GROUP		embedded synchronization code register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ESCRBitList, /**/
					Bit<8>{BitPos_t{0}},	// FSC
					Bit<8>{BitPos_t{8}},	// LSC
					Bit<8>{BitPos_t{16}},	// LEC
					Bit<8>{BitPos_t{24}}	// FEC
					)

enum class ESCRField {
	FSC,		/*!< Frame start delimiter code*/
	LSC,		/*!< Line start delimiter code*/
	LEC,		/*!< Line end delimiter code*/
	FEC,		/*!< Frame end delimiter code*/
};

static constexpr Register<ESCRBitList, ESCRField> ESCR{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	DCMI_ESUR_GROUP		embedded synchronization unmask register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ESURBitList, /**/
					Bit<8>{BitPos_t{0}},	// FSU
					Bit<8>{BitPos_t{8}},	// LSU
					Bit<8>{BitPos_t{16}},	// LEU
					Bit<8>{BitPos_t{24}}	// FEU
					)

enum class ESURField {
	FSU,		/*!< Frame start delimiter unmask*/
	LSU,		/*!< Line start delimiter unmask*/
	LEU,		/*!< Line end delimiter unmask*/
	FEU,		/*!< Frame end delimiter unmask*/
};

static constexpr Register<ESURBitList, ESURField> ESUR{BASE_ADDR, 0x1cU};
/**@}*/

/**
 * @defgroup	DCMI_CWSTRT_GROUP		crop window start group
 *
 * @{
 */

SETUP_REGISTER_INFO(CWSTRTBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{0}},	// HOFFCNT
					Bit<13, std::uint16_t>{BitPos_t{16}}	// VST
					)

enum class CWSTRTField {
	HOFFCNT,		/*!< Horizontal offset count*/
	VST,		/*!< Vertical start line count*/
};

static constexpr Register<CWSTRTBitList, CWSTRTField> CWSTRT{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	DCMI_CWSIZE_GROUP		crop window size group
 *
 * @{
 */

SETUP_REGISTER_INFO(CWSIZEBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{0}},	// CAPCNT
					Bit<14, std::uint16_t>{BitPos_t{16}}	// VLINE
					)

enum class CWSIZEField {
	CAPCNT,		/*!< Capture count*/
	VLINE,		/*!< Vertical line count*/
};

static constexpr Register<CWSIZEBitList, CWSIZEField> CWSIZE{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	DCMI_DR_GROUP		data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DRBitList, /**/
					Bit<8>{BitPos_t{0}},	// Byte0
					Bit<8>{BitPos_t{8}},	// Byte1
					Bit<8>{BitPos_t{16}},	// Byte2
					Bit<8>{BitPos_t{24}}	// Byte3
					)

enum class DRField {
	Byte0,		/*!< Data byte 0*/
	Byte1,		/*!< Data byte 1*/
	Byte2,		/*!< Data byte 2*/
	Byte3,		/*!< Data byte 3*/
};

static constexpr Register<DRBitList, DRField> DR{BASE_ADDR, 0x28U};
/**@}*/


} // cpp_stm32::dcmi::reg
