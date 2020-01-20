#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::rtc::reg {

static constexpr auto BASE_ADDR = 0x40002800U;

/**
 * @defgroup	RTC_TR_GROUP		time register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TRBitList, /**/
					Bit<4>{BitPos_t{0}},	// SU
					Bit<3>{BitPos_t{4}},	// ST
					Bit<4>{BitPos_t{8}},	// MNU
					Bit<3>{BitPos_t{12}},	// MNT
					Bit<4>{BitPos_t{16}},	// HU
					Bit<2>{BitPos_t{20}},	// HT
					Binary<>{BitPos_t{22}}	// PM
					)

enum class TRField {
	SU,		/*!< Second units in BCD format*/
	ST,		/*!< Second tens in BCD format*/
	MNU,		/*!< Minute units in BCD format*/
	MNT,		/*!< Minute tens in BCD format*/
	HU,		/*!< Hour units in BCD format*/
	HT,		/*!< Hour tens in BCD format*/
	PM,		/*!< AM/PM notation*/
};

static constexpr Register<TRBitList, TRField> TR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	RTC_DR_GROUP		date register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DRBitList, /**/
					Bit<4>{BitPos_t{0}},	// DU
					Bit<2>{BitPos_t{4}},	// DT
					Bit<4>{BitPos_t{8}},	// MU
					Binary<>{BitPos_t{12}},	// MT
					Bit<3>{BitPos_t{13}},	// WDU
					Bit<4>{BitPos_t{16}},	// YU
					Bit<4>{BitPos_t{20}}	// YT
					)

enum class DRField {
	DU,		/*!< Date units in BCD format*/
	DT,		/*!< Date tens in BCD format*/
	MU,		/*!< Month units in BCD format*/
	MT,		/*!< Month tens in BCD format*/
	WDU,		/*!< Week day units*/
	YU,		/*!< Year units in BCD format*/
	YT,		/*!< Year tens in BCD format*/
};

static constexpr Register<DRBitList, DRField> DR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	RTC_CR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Bit<3>{BitPos_t{0}},	// WCKSEL
					Binary<>{BitPos_t{3}},	// TSEDGE
					Binary<>{BitPos_t{4}},	// REFCKON
					Binary<>{BitPos_t{6}},	// FMT
					Binary<>{BitPos_t{7}},	// DCE
					Binary<>{BitPos_t{8}},	// ALRAE
					Binary<>{BitPos_t{9}},	// ALRBE
					Binary<>{BitPos_t{10}},	// WUTE
					Binary<>{BitPos_t{11}},	// TSE
					Binary<>{BitPos_t{12}},	// ALRAIE
					Binary<>{BitPos_t{13}},	// ALRBIE
					Binary<>{BitPos_t{14}},	// WUTIE
					Binary<>{BitPos_t{15}},	// TSIE
					Binary<>{BitPos_t{16}},	// ADD1H
					Binary<>{BitPos_t{17}},	// SUB1H
					Binary<>{BitPos_t{18}},	// BKP
					Binary<>{BitPos_t{20}},	// POL
					Bit<2>{BitPos_t{21}},	// OSEL
					Binary<>{BitPos_t{23}}	// COE
					)

enum class CRField {
	WCKSEL,		/*!< Wakeup clock selection*/
	TSEDGE,		/*!< Time-stamp event active edge*/
	REFCKON,		/*!< Reference clock detection enable (50 or 60 Hz)*/
	FMT,		/*!< Hour format*/
	DCE,		/*!< Coarse digital calibration enable*/
	ALRAE,		/*!< Alarm A enable*/
	ALRBE,		/*!< Alarm B enable*/
	WUTE,		/*!< Wakeup timer enable*/
	TSE,		/*!< Time stamp enable*/
	ALRAIE,		/*!< Alarm A interrupt enable*/
	ALRBIE,		/*!< Alarm B interrupt enable*/
	WUTIE,		/*!< Wakeup timer interrupt enable*/
	TSIE,		/*!< Time-stamp interrupt enable*/
	ADD1H,		/*!< Add 1 hour (summer time change)*/
	SUB1H,		/*!< Subtract 1 hour (winter time change)*/
	BKP,		/*!< Backup*/
	POL,		/*!< Output polarity*/
	OSEL,		/*!< Output selection*/
	COE,		/*!< Calibration output enable*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	RTC_ISR_GROUP		initialization and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISRBitList, /**/
					StatusBit<1>{BitPos_t{16}},	// RECALPF
					Binary<>{BitPos_t{14}},	// TAMP2F
					Binary<>{BitPos_t{13}},	// TAMP1F
					Binary<>{BitPos_t{12}},	// TSOVF
					Binary<>{BitPos_t{11}},	// TSF
					Binary<>{BitPos_t{10}},	// WUTF
					Binary<>{BitPos_t{9}},	// ALRBF
					Binary<>{BitPos_t{8}},	// ALRAF
					Binary<>{BitPos_t{7}},	// INIT
					StatusBit<1>{BitPos_t{6}},	// INITF
					Binary<>{BitPos_t{5}},	// RSF
					StatusBit<1>{BitPos_t{4}},	// INITS
					Binary<>{BitPos_t{3}},	// SHPF
					StatusBit<1>{BitPos_t{2}},	// WUTWF
					StatusBit<1>{BitPos_t{1}},	// ALRBWF
					StatusBit<1>{BitPos_t{0}}	// ALRAWF
					)

enum class ISRField {
	RECALPF,		/*!< Recalibration pending Flag*/
	TAMP2F,		/*!< TAMPER2 detection flag*/
	TAMP1F,		/*!< Tamper detection flag*/
	TSOVF,		/*!< Time-stamp overflow flag*/
	TSF,		/*!< Time-stamp flag*/
	WUTF,		/*!< Wakeup timer flag*/
	ALRBF,		/*!< Alarm B flag*/
	ALRAF,		/*!< Alarm A flag*/
	INIT,		/*!< Initialization mode*/
	INITF,		/*!< Initialization flag*/
	RSF,		/*!< Registers synchronization flag*/
	INITS,		/*!< Initialization status flag*/
	SHPF,		/*!< Shift operation pending*/
	WUTWF,		/*!< Wakeup timer write flag*/
	ALRBWF,		/*!< Alarm B write flag*/
	ALRAWF,		/*!< Alarm A write flag*/
};

static constexpr Register<ISRBitList, ISRField> ISR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	RTC_PRER_GROUP		prescaler register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PRERBitList, /**/
					Bit<15, std::uint16_t>{BitPos_t{0}},	// PREDIV_S
					Bit<7>{BitPos_t{16}}	// PREDIV_A
					)

enum class PRERField {
	PREDIV_S,		/*!< Synchronous prescaler factor*/
	PREDIV_A,		/*!< Asynchronous prescaler factor*/
};

static constexpr Register<PRERBitList, PRERField> PRER{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	RTC_WUTR_GROUP		wakeup timer register group
 *
 * @{
 */

SETUP_REGISTER_INFO(WUTRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// WUT
					)

enum class WUTRField {
	WUT,		/*!< Wakeup auto-reload value bits*/
};

static constexpr Register<WUTRBitList, WUTRField> WUTR{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	RTC_CALIBR_GROUP		calibration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CALIBRBitList, /**/
					Bit<5>{BitPos_t{0}},	// DC
					Binary<>{BitPos_t{7}}	// DCS
					)

enum class CALIBRField {
	DC,		/*!< Digital calibration*/
	DCS,		/*!< Digital calibration sign*/
};

static constexpr Register<CALIBRBitList, CALIBRField> CALIBR{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	RTC_ALRMAR_GROUP		alarm A register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ALRMARBitList, /**/
					Bit<4>{BitPos_t{0}},	// SU
					Bit<3>{BitPos_t{4}},	// ST
					Binary<>{BitPos_t{7}},	// MSK1
					Bit<4>{BitPos_t{8}},	// MNU
					Bit<3>{BitPos_t{12}},	// MNT
					Binary<>{BitPos_t{15}},	// MSK2
					Bit<4>{BitPos_t{16}},	// HU
					Bit<2>{BitPos_t{20}},	// HT
					Binary<>{BitPos_t{22}},	// PM
					Binary<>{BitPos_t{23}},	// MSK3
					Bit<4>{BitPos_t{24}},	// DU
					Bit<2>{BitPos_t{28}},	// DT
					Binary<>{BitPos_t{30}},	// WDSEL
					Binary<>{BitPos_t{31}}	// MSK4
					)

enum class ALRMARField {
	SU,		/*!< Second units in BCD format*/
	ST,		/*!< Second tens in BCD format*/
	MSK1,		/*!< Alarm A seconds mask*/
	MNU,		/*!< Minute units in BCD format*/
	MNT,		/*!< Minute tens in BCD format*/
	MSK2,		/*!< Alarm A minutes mask*/
	HU,		/*!< Hour units in BCD format*/
	HT,		/*!< Hour tens in BCD format*/
	PM,		/*!< AM/PM notation*/
	MSK3,		/*!< Alarm A hours mask*/
	DU,		/*!< Date units or day in BCD format*/
	DT,		/*!< Date tens in BCD format*/
	WDSEL,		/*!< Week day selection*/
	MSK4,		/*!< Alarm A date mask*/
};

static constexpr Register<ALRMARBitList, ALRMARField> ALRMAR{BASE_ADDR, 0x1cU};
/**@}*/

/**
 * @defgroup	RTC_ALRMBR_GROUP		alarm B register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ALRMBRBitList, /**/
					Bit<4>{BitPos_t{0}},	// SU
					Bit<3>{BitPos_t{4}},	// ST
					Binary<>{BitPos_t{7}},	// MSK1
					Bit<4>{BitPos_t{8}},	// MNU
					Bit<3>{BitPos_t{12}},	// MNT
					Binary<>{BitPos_t{15}},	// MSK2
					Bit<4>{BitPos_t{16}},	// HU
					Bit<2>{BitPos_t{20}},	// HT
					Binary<>{BitPos_t{22}},	// PM
					Binary<>{BitPos_t{23}},	// MSK3
					Bit<4>{BitPos_t{24}},	// DU
					Bit<2>{BitPos_t{28}},	// DT
					Binary<>{BitPos_t{30}},	// WDSEL
					Binary<>{BitPos_t{31}}	// MSK4
					)

enum class ALRMBRField {
	SU,		/*!< Second units in BCD format*/
	ST,		/*!< Second tens in BCD format*/
	MSK1,		/*!< Alarm B seconds mask*/
	MNU,		/*!< Minute units in BCD format*/
	MNT,		/*!< Minute tens in BCD format*/
	MSK2,		/*!< Alarm B minutes mask*/
	HU,		/*!< Hour units in BCD format*/
	HT,		/*!< Hour tens in BCD format*/
	PM,		/*!< AM/PM notation*/
	MSK3,		/*!< Alarm B hours mask*/
	DU,		/*!< Date units or day in BCD format*/
	DT,		/*!< Date tens in BCD format*/
	WDSEL,		/*!< Week day selection*/
	MSK4,		/*!< Alarm B date mask*/
};

static constexpr Register<ALRMBRBitList, ALRMBRField> ALRMBR{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	RTC_WPR_GROUP		write protection register group
 *
 * @{
 */

SETUP_REGISTER_INFO(WPRBitList, /**/
					Bit<8>{BitPos_t{0}}	// KEY
					)

enum class WPRField {
	KEY,		/*!< Write protection key*/
};

static constexpr Register<WPRBitList, WPRField> WPR{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	RTC_SSR_GROUP		sub second register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SSRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// SS
					)

enum class SSRField {
	SS,		/*!< Sub second value*/
};

static constexpr Register<SSRBitList, SSRField> SSR{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	RTC_SHIFTR_GROUP		shift control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SHIFTRBitList, /**/
					Bit<15, std::uint16_t>{BitPos_t{0}},	// SUBFS
					Binary<>{BitPos_t{31}}	// ADD1S
					)

enum class SHIFTRField {
	SUBFS,		/*!< Subtract a fraction of a second*/
	ADD1S,		/*!< Add one second*/
};

static constexpr Register<SHIFTRBitList, SHIFTRField> SHIFTR{BASE_ADDR, 0x2cU};
/**@}*/

/**
 * @defgroup	RTC_TSTR_GROUP		time stamp time register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TSTRBitList, /**/
					Binary<>{BitPos_t{0}},	// TAMP1E
					Binary<>{BitPos_t{1}},	// TAMP1TRG
					Binary<>{BitPos_t{2}},	// TAMPIE
					Binary<>{BitPos_t{16}},	// TAMP1INSEL
					Binary<>{BitPos_t{17}},	// TSINSEL
					Binary<>{BitPos_t{18}}	// ALARMOUTTYPE
					)

enum class TSTRField {
	TAMP1E,		/*!< Tamper 1 detection enable*/
	TAMP1TRG,		/*!< Active level for tamper 1*/
	TAMPIE,		/*!< Tamper interrupt enable*/
	TAMP1INSEL,		/*!< TAMPER1 mapping*/
	TSINSEL,		/*!< TIMESTAMP mapping*/
	ALARMOUTTYPE,		/*!< AFO_ALARM output type*/
};

static constexpr Register<TSTRBitList, TSTRField> TSTR{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	RTC_TSDR_GROUP		time stamp date register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TSDRBitList, /**/
					Bit<4>{BitPos_t{0}},	// DU
					Bit<2>{BitPos_t{4}},	// DT
					Bit<4>{BitPos_t{8}},	// MU
					Binary<>{BitPos_t{12}},	// MT
					Bit<3>{BitPos_t{13}}	// WDU
					)

enum class TSDRField {
	DU,		/*!< Date units in BCD format*/
	DT,		/*!< Date tens in BCD format*/
	MU,		/*!< Month units in BCD format*/
	MT,		/*!< Month tens in BCD format*/
	WDU,		/*!< Week day units*/
};

static constexpr Register<TSDRBitList, TSDRField> TSDR{BASE_ADDR, 0x34U};
/**@}*/

/**
 * @defgroup	RTC_TSSSR_GROUP		timestamp sub second register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TSSSRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// SS
					)

enum class TSSSRField {
	SS,		/*!< Sub second value*/
};

static constexpr Register<TSSSRBitList, TSSSRField> TSSSR{BASE_ADDR, 0x38U};
/**@}*/

/**
 * @defgroup	RTC_CALR_GROUP		calibration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CALRBitList, /**/
					Bit<9, std::uint16_t>{BitPos_t{0}},	// CALM
					Binary<>{BitPos_t{13}},	// CALW16
					Binary<>{BitPos_t{14}},	// CALW8
					Binary<>{BitPos_t{15}}	// CALP
					)

enum class CALRField {
	CALM,		/*!< Calibration minus*/
	CALW16,		/*!< Use a 16-second calibration cycle period*/
	CALW8,		/*!< Use an 8-second calibration cycle period*/
	CALP,		/*!< Increase frequency of RTC by 488.5 ppm*/
};

static constexpr Register<CALRBitList, CALRField> CALR{BASE_ADDR, 0x3cU};
/**@}*/

/**
 * @defgroup	RTC_TAFCR_GROUP		tamper and alternate function configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TAFCRBitList, /**/
					Binary<>{BitPos_t{0}},	// TAMP1E
					Binary<>{BitPos_t{1}},	// TAMP1TRG
					Binary<>{BitPos_t{2}},	// TAMPIE
					Binary<>{BitPos_t{3}},	// TAMP2E
					Binary<>{BitPos_t{4}},	// TAMP2TRG
					Binary<>{BitPos_t{7}},	// TAMPTS
					Bit<3>{BitPos_t{8}},	// TAMPFREQ
					Bit<2>{BitPos_t{11}},	// TAMPFLT
					Bit<2>{BitPos_t{13}},	// TAMPPRCH
					Binary<>{BitPos_t{15}},	// TAMPPUDIS
					Binary<>{BitPos_t{16}},	// TAMP1INSEL
					Binary<>{BitPos_t{17}},	// TSINSEL
					Binary<>{BitPos_t{18}}	// ALARMOUTTYPE
					)

enum class TAFCRField {
	TAMP1E,		/*!< Tamper 1 detection enable*/
	TAMP1TRG,		/*!< Active level for tamper 1*/
	TAMPIE,		/*!< Tamper interrupt enable*/
	TAMP2E,		/*!< Tamper 2 detection enable*/
	TAMP2TRG,		/*!< Active level for tamper 2*/
	TAMPTS,		/*!< Activate timestamp on tamper detection event*/
	TAMPFREQ,		/*!< Tamper sampling frequency*/
	TAMPFLT,		/*!< Tamper filter count*/
	TAMPPRCH,		/*!< Tamper precharge duration*/
	TAMPPUDIS,		/*!< TAMPER pull-up disable*/
	TAMP1INSEL,		/*!< TAMPER1 mapping*/
	TSINSEL,		/*!< TIMESTAMP mapping*/
	ALARMOUTTYPE,		/*!< AFO_ALARM output type*/
};

static constexpr Register<TAFCRBitList, TAFCRField> TAFCR{BASE_ADDR, 0x40U};
/**@}*/

/**
 * @defgroup	RTC_ALRMASSR_GROUP		alarm A sub second register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ALRMASSRBitList, /**/
					Bit<15, std::uint16_t>{BitPos_t{0}},	// SS
					Bit<4>{BitPos_t{24}}	// MASKSS
					)

enum class ALRMASSRField {
	SS,		/*!< Sub seconds value*/
	MASKSS,		/*!< Mask the most-significant bits starting at this bit*/
};

static constexpr Register<ALRMASSRBitList, ALRMASSRField> ALRMASSR{BASE_ADDR, 0x44U};
/**@}*/

/**
 * @defgroup	RTC_ALRMBSSR_GROUP		alarm B sub second register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ALRMBSSRBitList, /**/
					Bit<15, std::uint16_t>{BitPos_t{0}},	// SS
					Bit<4>{BitPos_t{24}}	// MASKSS
					)

enum class ALRMBSSRField {
	SS,		/*!< Sub seconds value*/
	MASKSS,		/*!< Mask the most-significant bits starting at this bit*/
};

static constexpr Register<ALRMBSSRBitList, ALRMBSSRField> ALRMBSSR{BASE_ADDR, 0x48U};
/**@}*/

/**
 * @defgroup	RTC_BKP0R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP0RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP0RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP0RBitList, BKP0RField> BKP0R{BASE_ADDR, 0x50U};
/**@}*/

/**
 * @defgroup	RTC_BKP1R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP1RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP1RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP1RBitList, BKP1RField> BKP1R{BASE_ADDR, 0x54U};
/**@}*/

/**
 * @defgroup	RTC_BKP2R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP2RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP2RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP2RBitList, BKP2RField> BKP2R{BASE_ADDR, 0x58U};
/**@}*/

/**
 * @defgroup	RTC_BKP3R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP3RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP3RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP3RBitList, BKP3RField> BKP3R{BASE_ADDR, 0x5cU};
/**@}*/

/**
 * @defgroup	RTC_BKP4R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP4RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP4RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP4RBitList, BKP4RField> BKP4R{BASE_ADDR, 0x60U};
/**@}*/

/**
 * @defgroup	RTC_BKP5R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP5RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP5RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP5RBitList, BKP5RField> BKP5R{BASE_ADDR, 0x64U};
/**@}*/

/**
 * @defgroup	RTC_BKP6R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP6RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP6RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP6RBitList, BKP6RField> BKP6R{BASE_ADDR, 0x68U};
/**@}*/

/**
 * @defgroup	RTC_BKP7R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP7RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP7RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP7RBitList, BKP7RField> BKP7R{BASE_ADDR, 0x6cU};
/**@}*/

/**
 * @defgroup	RTC_BKP8R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP8RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP8RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP8RBitList, BKP8RField> BKP8R{BASE_ADDR, 0x70U};
/**@}*/

/**
 * @defgroup	RTC_BKP9R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP9RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP9RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP9RBitList, BKP9RField> BKP9R{BASE_ADDR, 0x74U};
/**@}*/

/**
 * @defgroup	RTC_BKP10R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP10RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP10RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP10RBitList, BKP10RField> BKP10R{BASE_ADDR, 0x78U};
/**@}*/

/**
 * @defgroup	RTC_BKP11R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP11RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP11RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP11RBitList, BKP11RField> BKP11R{BASE_ADDR, 0x7cU};
/**@}*/

/**
 * @defgroup	RTC_BKP12R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP12RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP12RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP12RBitList, BKP12RField> BKP12R{BASE_ADDR, 0x80U};
/**@}*/

/**
 * @defgroup	RTC_BKP13R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP13RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP13RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP13RBitList, BKP13RField> BKP13R{BASE_ADDR, 0x84U};
/**@}*/

/**
 * @defgroup	RTC_BKP14R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP14RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP14RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP14RBitList, BKP14RField> BKP14R{BASE_ADDR, 0x88U};
/**@}*/

/**
 * @defgroup	RTC_BKP15R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP15RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP15RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP15RBitList, BKP15RField> BKP15R{BASE_ADDR, 0x8cU};
/**@}*/

/**
 * @defgroup	RTC_BKP16R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP16RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP16RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP16RBitList, BKP16RField> BKP16R{BASE_ADDR, 0x90U};
/**@}*/

/**
 * @defgroup	RTC_BKP17R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP17RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP17RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP17RBitList, BKP17RField> BKP17R{BASE_ADDR, 0x94U};
/**@}*/

/**
 * @defgroup	RTC_BKP18R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP18RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP18RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP18RBitList, BKP18RField> BKP18R{BASE_ADDR, 0x98U};
/**@}*/

/**
 * @defgroup	RTC_BKP19R_GROUP		backup register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BKP19RBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// BKP
					)

enum class BKP19RField {
	BKP,		/*!< BKP*/
};

static constexpr Register<BKP19RBitList, BKP19RField> BKP19R{BASE_ADDR, 0x9cU};
/**@}*/


} // cpp_stm32::rtc::reg
