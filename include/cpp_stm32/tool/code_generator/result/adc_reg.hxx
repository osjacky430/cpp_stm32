#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::adc::reg {

static constexpr auto BASE_ADDR(Port const& t_adc) {
	case Port::ADC1:
		return 0x40012000U;
	case Port::ADC2:
		return 0x40012100U;
	case Port::ADC3:
		return 0x40012200U;
	case Port::C_ADC:
		return 0x40012300U;
}

/**
 * @defgroup	C_ADC_CSR_GROUP		ADC Common status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CSRBitList, /**/
					Binary<>{BitPos_t{0}},	// AWD1
					Binary<>{BitPos_t{1}},	// EOC1
					Binary<>{BitPos_t{2}},	// JEOC1
					Binary<>{BitPos_t{3}},	// JSTRT1
					Binary<>{BitPos_t{4}},	// STRT1
					Binary<>{BitPos_t{5}},	// OVR1
					Binary<>{BitPos_t{8}},	// AWD2
					Binary<>{BitPos_t{9}},	// EOC2
					Binary<>{BitPos_t{10}},	// JEOC2
					Binary<>{BitPos_t{11}},	// JSTRT2
					Binary<>{BitPos_t{12}},	// STRT2
					Binary<>{BitPos_t{13}},	// OVR2
					Binary<>{BitPos_t{16}},	// AWD3
					Binary<>{BitPos_t{17}},	// EOC3
					Binary<>{BitPos_t{18}},	// JEOC3
					Binary<>{BitPos_t{19}},	// JSTRT3
					Binary<>{BitPos_t{20}},	// STRT3
					Binary<>{BitPos_t{21}}	// OVR3
					)

enum class CSRField {
	AWD1,		/*!< Analog watchdog flag of ADC 1*/
	EOC1,		/*!< End of conversion of ADC 1*/
	JEOC1,		/*!< Injected channel end of conversion of ADC 1*/
	JSTRT1,		/*!< Injected channel Start flag of ADC 1*/
	STRT1,		/*!< Regular channel Start flag of ADC 1*/
	OVR1,		/*!< Overrun flag of ADC 1*/
	AWD2,		/*!< Analog watchdog flag of ADC 2*/
	EOC2,		/*!< End of conversion of ADC 2*/
	JEOC2,		/*!< Injected channel end of conversion of ADC 2*/
	JSTRT2,		/*!< Injected channel Start flag of ADC 2*/
	STRT2,		/*!< Regular channel Start flag of ADC 2*/
	OVR2,		/*!< Overrun flag of ADC 2*/
	AWD3,		/*!< Analog watchdog flag of ADC 3*/
	EOC3,		/*!< End of conversion of ADC 3*/
	JEOC3,		/*!< Injected channel end of conversion of ADC 3*/
	JSTRT3,		/*!< Injected channel Start flag of ADC 3*/
	STRT3,		/*!< Regular channel Start flag of ADC 3*/
	OVR3,		/*!< Overrun flag of ADC3*/
};

template <Port ADC>
static constexpr Register<CSRBitList, CSRField> CSR{BASE_ADDR(ADC), 0x00U};
/**@}*/

/**
 * @defgroup	C_ADC_CCR_GROUP		ADC common control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCRBitList, /**/
					Bit<5>{BitPos_t{0}},	// MULT
					Bit<4>{BitPos_t{8}},	// DELAY
					Binary<>{BitPos_t{13}},	// DDS
					Bit<2>{BitPos_t{14}},	// DMA
					Bit<2>{BitPos_t{16}},	// ADCPRE
					Binary<>{BitPos_t{22}},	// VBATE
					Binary<>{BitPos_t{23}}	// TSVREFE
					)

enum class CCRField {
	MULT,		/*!< Multi ADC mode selection*/
	DELAY,		/*!< Delay between 2 sampling phases*/
	DDS,		/*!< DMA disable selection for multi-ADC mode*/
	DMA,		/*!< Direct memory access mode for multi ADC mode*/
	ADCPRE,		/*!< ADC prescaler*/
	VBATE,		/*!< VBAT enable*/
	TSVREFE,		/*!< Temperature sensor and VREFINT enable*/
};

template <Port ADC>
static constexpr Register<CCRBitList, CCRField> CCR{BASE_ADDR(ADC), 0x04U};
/**@}*/

/**
 * @defgroup	C_ADC_CDR_GROUP		ADC common regular data register for dual and triple modes group
 *
 * @{
 */

SETUP_REGISTER_INFO(CDRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}},	// DATA1
					Bit<16, std::uint16_t>{BitPos_t{16}}	// DATA2
					)

enum class CDRField {
	DATA1,		/*!< 1st data item of a pair of regular conversions*/
	DATA2,		/*!< 2nd data item of a pair of regular conversions*/
};

template <Port ADC>
static constexpr Register<CDRBitList, CDRField> CDR{BASE_ADDR(ADC), 0x08U};
/**@}*/


} // cpp_stm32::adc::reg
