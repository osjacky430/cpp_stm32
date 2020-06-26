#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::adc::reg {

static constexpr auto BASE_ADDR = 0x50040000U;

/**
 * @defgroup	ADC_ISR_GROUP		interrupt and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISRBitList, /**/
					Binary<>{BitPos_t{0}},	// ADRDY
					Binary<>{BitPos_t{1}},	// EOSMP
					Binary<>{BitPos_t{2}},	// EOC
					Binary<>{BitPos_t{3}},	// EOS
					Binary<>{BitPos_t{4}},	// OVR
					Binary<>{BitPos_t{5}},	// JEOC
					Binary<>{BitPos_t{6}},	// JEOS
					Binary<>{BitPos_t{7}},	// AWD1
					Binary<>{BitPos_t{8}},	// AWD2
					Binary<>{BitPos_t{9}},	// AWD3
					Binary<>{BitPos_t{10}}	// JQOVF
					)

enum class ISRField {
	ADRDY,		/*!< ADRDY*/
	EOSMP,		/*!< EOSMP*/
	EOC,		/*!< EOC*/
	EOS,		/*!< EOS*/
	OVR,		/*!< OVR*/
	JEOC,		/*!< JEOC*/
	JEOS,		/*!< JEOS*/
	AWD1,		/*!< AWD1*/
	AWD2,		/*!< AWD2*/
	AWD3,		/*!< AWD3*/
	JQOVF,		/*!< JQOVF*/
};

static constexpr Register<ISRBitList, ISRField> ISR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	ADC_IER_GROUP		interrupt enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IERBitList, /**/
					Binary<>{BitPos_t{0}},	// ADRDYIE
					Binary<>{BitPos_t{1}},	// EOSMPIE
					Binary<>{BitPos_t{2}},	// EOCIE
					Binary<>{BitPos_t{3}},	// EOSIE
					Binary<>{BitPos_t{4}},	// OVRIE
					Binary<>{BitPos_t{5}},	// JEOCIE
					Binary<>{BitPos_t{6}},	// JEOSIE
					Binary<>{BitPos_t{7}},	// AWD1IE
					Binary<>{BitPos_t{8}},	// AWD2IE
					Binary<>{BitPos_t{9}},	// AWD3IE
					Binary<>{BitPos_t{10}}	// JQOVFIE
					)

enum class IERField {
	ADRDYIE,		/*!< ADRDYIE*/
	EOSMPIE,		/*!< EOSMPIE*/
	EOCIE,		/*!< EOCIE*/
	EOSIE,		/*!< EOSIE*/
	OVRIE,		/*!< OVRIE*/
	JEOCIE,		/*!< JEOCIE*/
	JEOSIE,		/*!< JEOSIE*/
	AWD1IE,		/*!< AWD1IE*/
	AWD2IE,		/*!< AWD2IE*/
	AWD3IE,		/*!< AWD3IE*/
	JQOVFIE,		/*!< JQOVFIE*/
};

static constexpr Register<IERBitList, IERField> IER{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	ADC_CR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{0}},	// ADEN
					Binary<>{BitPos_t{1}},	// ADDIS
					Binary<>{BitPos_t{2}},	// ADSTART
					Binary<>{BitPos_t{3}},	// JADSTART
					Binary<>{BitPos_t{4}},	// ADSTP
					Binary<>{BitPos_t{5}},	// JADSTP
					Binary<>{BitPos_t{28}},	// ADVREGEN
					Binary<>{BitPos_t{29}},	// DEEPPWD
					Binary<>{BitPos_t{30}},	// ADCALDIF
					Binary<>{BitPos_t{31}}	// ADCAL
					)

enum class CRField {
	ADEN,		/*!< ADEN*/
	ADDIS,		/*!< ADDIS*/
	ADSTART,		/*!< ADSTART*/
	JADSTART,		/*!< JADSTART*/
	ADSTP,		/*!< ADSTP*/
	JADSTP,		/*!< JADSTP*/
	ADVREGEN,		/*!< ADVREGEN*/
	DEEPPWD,		/*!< DEEPPWD*/
	ADCALDIF,		/*!< ADCALDIF*/
	ADCAL,		/*!< ADCAL*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	ADC_CFGR_GROUP		configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CFGRBitList, /**/
					Binary<>{BitPos_t{0}},	// DMAEN
					Binary<>{BitPos_t{1}},	// DMACFG
					Bit<2>{BitPos_t{3}},	// RES
					Binary<>{BitPos_t{5}},	// ALIGN
					Bit<4>{BitPos_t{6}},	// EXTSEL
					Bit<2>{BitPos_t{10}},	// EXTEN
					Binary<>{BitPos_t{12}},	// OVRMOD
					Binary<>{BitPos_t{13}},	// CONT
					Binary<>{BitPos_t{14}},	// AUTDLY
					Binary<>{BitPos_t{15}},	// AUTOFF
					Binary<>{BitPos_t{16}},	// DISCEN
					Bit<3>{BitPos_t{17}},	// DISCNUM
					Binary<>{BitPos_t{20}},	// JDISCEN
					Binary<>{BitPos_t{21}},	// JQM
					Binary<>{BitPos_t{22}},	// AWD1SGL
					Binary<>{BitPos_t{23}},	// AWD1EN
					Binary<>{BitPos_t{24}},	// JAWD1EN
					Binary<>{BitPos_t{25}},	// JAUTO
					Bit<5>{BitPos_t{26}}	// AWDCH1CH
					)

enum class CFGRField {
	DMAEN,		/*!< DMAEN*/
	DMACFG,		/*!< DMACFG*/
	RES,		/*!< RES*/
	ALIGN,		/*!< ALIGN*/
	EXTSEL,		/*!< EXTSEL*/
	EXTEN,		/*!< EXTEN*/
	OVRMOD,		/*!< OVRMOD*/
	CONT,		/*!< CONT*/
	AUTDLY,		/*!< AUTDLY*/
	AUTOFF,		/*!< AUTOFF*/
	DISCEN,		/*!< DISCEN*/
	DISCNUM,		/*!< DISCNUM*/
	JDISCEN,		/*!< JDISCEN*/
	JQM,		/*!< JQM*/
	AWD1SGL,		/*!< AWD1SGL*/
	AWD1EN,		/*!< AWD1EN*/
	JAWD1EN,		/*!< JAWD1EN*/
	JAUTO,		/*!< JAUTO*/
	AWDCH1CH,		/*!< AWDCH1CH*/
};

static constexpr Register<CFGRBitList, CFGRField> CFGR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	ADC_CFGR2_GROUP		configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CFGR2BitList, /**/
					Binary<>{BitPos_t{0}},	// ROVSE
					Binary<>{BitPos_t{1}},	// JOVSE
					Bit<3>{BitPos_t{2}},	// OVSR
					Bit<4>{BitPos_t{5}},	// OVSS
					Binary<>{BitPos_t{9}},	// TOVS
					Binary<>{BitPos_t{10}}	// ROVSM
					)

enum class CFGR2Field {
	ROVSE,		/*!< DMAEN*/
	JOVSE,		/*!< DMACFG*/
	OVSR,		/*!< RES*/
	OVSS,		/*!< ALIGN*/
	TOVS,		/*!< EXTSEL*/
	ROVSM,		/*!< EXTEN*/
};

static constexpr Register<CFGR2BitList, CFGR2Field> CFGR2{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	ADC_SMPR1_GROUP		sample time register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SMPR1BitList, /**/
					Bit<3>{BitPos_t{3}},	// SMP1
					Bit<3>{BitPos_t{6}},	// SMP2
					Bit<3>{BitPos_t{9}},	// SMP3
					Bit<3>{BitPos_t{12}},	// SMP4
					Bit<3>{BitPos_t{15}},	// SMP5
					Bit<3>{BitPos_t{18}},	// SMP6
					Bit<3>{BitPos_t{21}},	// SMP7
					Bit<3>{BitPos_t{24}},	// SMP8
					Bit<3>{BitPos_t{27}}	// SMP9
					)

enum class SMPR1Field {
	SMP1,		/*!< SMP1*/
	SMP2,		/*!< SMP2*/
	SMP3,		/*!< SMP3*/
	SMP4,		/*!< SMP4*/
	SMP5,		/*!< SMP5*/
	SMP6,		/*!< SMP6*/
	SMP7,		/*!< SMP7*/
	SMP8,		/*!< SMP8*/
	SMP9,		/*!< SMP9*/
};

static constexpr Register<SMPR1BitList, SMPR1Field> SMPR1{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	ADC_SMPR2_GROUP		sample time register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SMPR2BitList, /**/
					Bit<3>{BitPos_t{0}},	// SMP10
					Bit<3>{BitPos_t{3}},	// SMP11
					Bit<3>{BitPos_t{6}},	// SMP12
					Bit<3>{BitPos_t{9}},	// SMP13
					Bit<3>{BitPos_t{12}},	// SMP14
					Bit<3>{BitPos_t{15}},	// SMP15
					Bit<3>{BitPos_t{18}},	// SMP16
					Bit<3>{BitPos_t{21}},	// SMP17
					Bit<3>{BitPos_t{24}}	// SMP18
					)

enum class SMPR2Field {
	SMP10,		/*!< SMP10*/
	SMP11,		/*!< SMP11*/
	SMP12,		/*!< SMP12*/
	SMP13,		/*!< SMP13*/
	SMP14,		/*!< SMP14*/
	SMP15,		/*!< SMP15*/
	SMP16,		/*!< SMP16*/
	SMP17,		/*!< SMP17*/
	SMP18,		/*!< SMP18*/
};

static constexpr Register<SMPR2BitList, SMPR2Field> SMPR2{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	ADC_TR1_GROUP		watchdog threshold register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(TR1BitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}},	// LT1
					Bit<12, std::uint16_t>{BitPos_t{16}}	// HT1
					)

enum class TR1Field {
	LT1,		/*!< LT1*/
	HT1,		/*!< HT1*/
};

static constexpr Register<TR1BitList, TR1Field> TR1{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	ADC_TR2_GROUP		watchdog threshold register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TR2BitList, /**/
					Bit<8>{BitPos_t{0}},	// LT2
					Bit<8>{BitPos_t{16}}	// HT2
					)

enum class TR2Field {
	LT2,		/*!< LT2*/
	HT2,		/*!< HT2*/
};

static constexpr Register<TR2BitList, TR2Field> TR2{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	ADC_TR3_GROUP		watchdog threshold register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(TR3BitList, /**/
					Bit<8>{BitPos_t{0}},	// LT3
					Bit<8>{BitPos_t{16}}	// HT3
					)

enum class TR3Field {
	LT3,		/*!< LT3*/
	HT3,		/*!< HT3*/
};

static constexpr Register<TR3BitList, TR3Field> TR3{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	ADC_SQR1_GROUP		regular sequence register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SQR1BitList, /**/
					Bit<4>{BitPos_t{0}},	// L3
					Bit<5>{BitPos_t{6}},	// SQ1
					Bit<5>{BitPos_t{12}},	// SQ2
					Bit<5>{BitPos_t{18}},	// SQ3
					Bit<5>{BitPos_t{24}}	// SQ4
					)

enum class SQR1Field {
	L3,		/*!< L3*/
	SQ1,		/*!< SQ1*/
	SQ2,		/*!< SQ2*/
	SQ3,		/*!< SQ3*/
	SQ4,		/*!< SQ4*/
};

static constexpr Register<SQR1BitList, SQR1Field> SQR1{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	ADC_SQR2_GROUP		regular sequence register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SQR2BitList, /**/
					Bit<5>{BitPos_t{0}},	// SQ5
					Bit<5>{BitPos_t{6}},	// SQ6
					Bit<5>{BitPos_t{12}},	// SQ7
					Bit<5>{BitPos_t{18}},	// SQ8
					Bit<5>{BitPos_t{24}}	// SQ9
					)

enum class SQR2Field {
	SQ5,		/*!< SQ5*/
	SQ6,		/*!< SQ6*/
	SQ7,		/*!< SQ7*/
	SQ8,		/*!< SQ8*/
	SQ9,		/*!< SQ9*/
};

static constexpr Register<SQR2BitList, SQR2Field> SQR2{BASE_ADDR, 0x34U};
/**@}*/

/**
 * @defgroup	ADC_SQR3_GROUP		regular sequence register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SQR3BitList, /**/
					Bit<5>{BitPos_t{0}},	// SQ10
					Bit<5>{BitPos_t{6}},	// SQ11
					Bit<5>{BitPos_t{12}},	// SQ12
					Bit<5>{BitPos_t{18}},	// SQ13
					Bit<5>{BitPos_t{24}}	// SQ14
					)

enum class SQR3Field {
	SQ10,		/*!< SQ10*/
	SQ11,		/*!< SQ11*/
	SQ12,		/*!< SQ12*/
	SQ13,		/*!< SQ13*/
	SQ14,		/*!< SQ14*/
};

static constexpr Register<SQR3BitList, SQR3Field> SQR3{BASE_ADDR, 0x38U};
/**@}*/

/**
 * @defgroup	ADC_SQR4_GROUP		regular sequence register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(SQR4BitList, /**/
					Bit<5>{BitPos_t{0}},	// SQ15
					Bit<5>{BitPos_t{6}}	// SQ16
					)

enum class SQR4Field {
	SQ15,		/*!< SQ15*/
	SQ16,		/*!< SQ16*/
};

static constexpr Register<SQR4BitList, SQR4Field> SQR4{BASE_ADDR, 0x3cU};
/**@}*/

/**
 * @defgroup	ADC_DR_GROUP		regular Data Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// regularDATA
					)

enum class DRField {
	regularDATA,		/*!< regularDATA*/
};

static constexpr Register<DRBitList, DRField> DR{BASE_ADDR, 0x40U};
/**@}*/

/**
 * @defgroup	ADC_JSQR_GROUP		injected sequence register group
 *
 * @{
 */

SETUP_REGISTER_INFO(JSQRBitList, /**/
					Bit<2>{BitPos_t{0}},	// JL
					Bit<4>{BitPos_t{2}},	// JEXTSEL
					Bit<2>{BitPos_t{6}},	// JEXTEN
					Bit<5>{BitPos_t{8}},	// JSQ1
					Bit<5>{BitPos_t{14}},	// JSQ2
					Bit<5>{BitPos_t{20}},	// JSQ3
					Bit<5>{BitPos_t{26}}	// JSQ4
					)

enum class JSQRField {
	JL,		/*!< JL*/
	JEXTSEL,		/*!< JEXTSEL*/
	JEXTEN,		/*!< JEXTEN*/
	JSQ1,		/*!< JSQ1*/
	JSQ2,		/*!< JSQ2*/
	JSQ3,		/*!< JSQ3*/
	JSQ4,		/*!< JSQ4*/
};

static constexpr Register<JSQRBitList, JSQRField> JSQR{BASE_ADDR, 0x4cU};
/**@}*/

/**
 * @defgroup	ADC_OFR1_GROUP		offset register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(OFR1BitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}},	// OFFSET1
					Bit<5>{BitPos_t{26}},	// OFFSET1_CH
					Binary<>{BitPos_t{31}}	// OFFSET1_EN
					)

enum class OFR1Field {
	OFFSET1,		/*!< OFFSET1*/
	OFFSET1_CH,		/*!< OFFSET1_CH*/
	OFFSET1_EN,		/*!< OFFSET1_EN*/
};

static constexpr Register<OFR1BitList, OFR1Field> OFR1{BASE_ADDR, 0x60U};
/**@}*/

/**
 * @defgroup	ADC_OFR2_GROUP		offset register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(OFR2BitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}},	// OFFSET2
					Bit<5>{BitPos_t{26}},	// OFFSET2_CH
					Binary<>{BitPos_t{31}}	// OFFSET2_EN
					)

enum class OFR2Field {
	OFFSET2,		/*!< OFFSET2*/
	OFFSET2_CH,		/*!< OFFSET2_CH*/
	OFFSET2_EN,		/*!< OFFSET2_EN*/
};

static constexpr Register<OFR2BitList, OFR2Field> OFR2{BASE_ADDR, 0x64U};
/**@}*/

/**
 * @defgroup	ADC_OFR3_GROUP		offset register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(OFR3BitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}},	// OFFSET3
					Bit<5>{BitPos_t{26}},	// OFFSET3_CH
					Binary<>{BitPos_t{31}}	// OFFSET3_EN
					)

enum class OFR3Field {
	OFFSET3,		/*!< OFFSET3*/
	OFFSET3_CH,		/*!< OFFSET3_CH*/
	OFFSET3_EN,		/*!< OFFSET3_EN*/
};

static constexpr Register<OFR3BitList, OFR3Field> OFR3{BASE_ADDR, 0x68U};
/**@}*/

/**
 * @defgroup	ADC_OFR4_GROUP		offset register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(OFR4BitList, /**/
					Bit<12, std::uint16_t>{BitPos_t{0}},	// OFFSET4
					Bit<5>{BitPos_t{26}},	// OFFSET4_CH
					Binary<>{BitPos_t{31}}	// OFFSET4_EN
					)

enum class OFR4Field {
	OFFSET4,		/*!< OFFSET4*/
	OFFSET4_CH,		/*!< OFFSET4_CH*/
	OFFSET4_EN,		/*!< OFFSET4_EN*/
};

static constexpr Register<OFR4BitList, OFR4Field> OFR4{BASE_ADDR, 0x6cU};
/**@}*/

/**
 * @defgroup	ADC_JDR1_GROUP		injected data register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(JDR1BitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// JDATA1
					)

enum class JDR1Field {
	JDATA1,		/*!< JDATA1*/
};

static constexpr Register<JDR1BitList, JDR1Field> JDR1{BASE_ADDR, 0x80U};
/**@}*/

/**
 * @defgroup	ADC_JDR2_GROUP		injected data register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(JDR2BitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// JDATA2
					)

enum class JDR2Field {
	JDATA2,		/*!< JDATA2*/
};

static constexpr Register<JDR2BitList, JDR2Field> JDR2{BASE_ADDR, 0x84U};
/**@}*/

/**
 * @defgroup	ADC_JDR3_GROUP		injected data register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(JDR3BitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// JDATA3
					)

enum class JDR3Field {
	JDATA3,		/*!< JDATA3*/
};

static constexpr Register<JDR3BitList, JDR3Field> JDR3{BASE_ADDR, 0x88U};
/**@}*/

/**
 * @defgroup	ADC_JDR4_GROUP		injected data register 4 group
 *
 * @{
 */

SETUP_REGISTER_INFO(JDR4BitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// JDATA4
					)

enum class JDR4Field {
	JDATA4,		/*!< JDATA4*/
};

static constexpr Register<JDR4BitList, JDR4Field> JDR4{BASE_ADDR, 0x8cU};
/**@}*/

/**
 * @defgroup	ADC_AWD2CR_GROUP		Analog Watchdog 2 Configuration Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AWD2CRBitList, /**/
					Bit<18, std::uint32_t>{BitPos_t{1}}	// AWD2CH
					)

enum class AWD2CRField {
	AWD2CH,		/*!< AWD2CH*/
};

static constexpr Register<AWD2CRBitList, AWD2CRField> AWD2CR{BASE_ADDR, 0xa0U};
/**@}*/

/**
 * @defgroup	ADC_AWD3CR_GROUP		Analog Watchdog 3 Configuration Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AWD3CRBitList, /**/
					Bit<18, std::uint32_t>{BitPos_t{1}}	// AWD3CH
					)

enum class AWD3CRField {
	AWD3CH,		/*!< AWD3CH*/
};

static constexpr Register<AWD3CRBitList, AWD3CRField> AWD3CR{BASE_ADDR, 0xa4U};
/**@}*/

/**
 * @defgroup	ADC_DIFSEL_GROUP		Differential Mode Selection Register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(DIFSELBitList, /**/
					StatusBit<3>{BitPos_t{16}},	// DIFSEL_16_18
					Bit<15, std::uint16_t>{BitPos_t{1}}	// DIFSEL_1_15
					)

enum class DIFSELField {
	DIFSEL_16_18,		/*!< Differential mode for channels 18 to 16*/
	DIFSEL_1_15,		/*!< Differential mode for channels 15 to 1*/
};

static constexpr Register<DIFSELBitList, DIFSELField> DIFSEL{BASE_ADDR, 0xb0U};
/**@}*/

/**
 * @defgroup	ADC_CALFACT_GROUP		Calibration Factors group
 *
 * @{
 */

SETUP_REGISTER_INFO(CALFACTBitList, /**/
					Bit<7>{BitPos_t{0}},	// CALFACT_S
					Bit<7>{BitPos_t{16}}	// CALFACT_D
					)

enum class CALFACTField {
	CALFACT_S,		/*!< CALFACT_S*/
	CALFACT_D,		/*!< CALFACT_D*/
};

static constexpr Register<CALFACTBitList, CALFACTField> CALFACT{BASE_ADDR, 0xb4U};
/**@}*/


} // cpp_stm32::adc::reg
