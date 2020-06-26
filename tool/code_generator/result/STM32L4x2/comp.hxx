#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::comp::reg {

static constexpr auto BASE_ADDR = 0x40010200U;

/**
 * @defgroup	COMP_COMP1_CSR_GROUP		Comparator 1 control and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(COMP1_CSRBitList, /**/
					Binary<BitMod::WrOnly>{BitPos_t{31}},	// COMP1_LOCK
					StatusBit<1>{BitPos_t{30}},	// COMP1_VALUE
					Bit<2>{BitPos_t{25}},	// COMP1_INMESEL
					Binary<>{BitPos_t{23}},	// COMP1_SCALEN
					Binary<>{BitPos_t{22}},	// COMP1_BRGEN
					Bit<3>{BitPos_t{18}},	// COMP1_BLANKING
					Bit<2>{BitPos_t{16}},	// COMP1_HYST
					Binary<>{BitPos_t{15}},	// COMP1_POLARITY
					Bit<2>{BitPos_t{7}},	// COMP1_INPSEL
					Bit<3>{BitPos_t{4}},	// COMP1_INMSEL
					Bit<2>{BitPos_t{2}},	// COMP1_PWRMODE
					Binary<>{BitPos_t{0}}	// COMP1_EN
					)

enum class COMP1_CSRField {
	COMP1_LOCK,		/*!< COMP1_CSR register lock bit*/
	COMP1_VALUE,		/*!< Comparator 1 output status bit*/
	COMP1_INMESEL,		/*!< comparator 1 input minus extended selection bits*/
	COMP1_SCALEN,		/*!< Voltage scaler enable bit*/
	COMP1_BRGEN,		/*!< Scaler bridge enable*/
	COMP1_BLANKING,		/*!< Comparator 1 blanking source selection bits*/
	COMP1_HYST,		/*!< Comparator 1 hysteresis selection bits*/
	COMP1_POLARITY,		/*!< Comparator 1 polarity selection bit*/
	COMP1_INPSEL,		/*!< Comparator1 input plus selection bit*/
	COMP1_INMSEL,		/*!< Comparator 1 Input Minus connection configuration bit*/
	COMP1_PWRMODE,		/*!< Power Mode of the comparator 1*/
	COMP1_EN,		/*!< Comparator 1 enable bit*/
};

static constexpr Register<COMP1_CSRBitList, COMP1_CSRField> COMP1_CSR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	COMP_COMP2_CSR_GROUP		Comparator 2 control and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(COMP2_CSRBitList, /**/
					Binary<BitMod::WrOnly>{BitPos_t{31}},	// COMP2_LOCK
					StatusBit<1>{BitPos_t{30}},	// COMP2_VALUE
					Bit<2>{BitPos_t{25}},	// COMP2_INMESEL
					Binary<>{BitPos_t{23}},	// COMP2_SCALEN
					Binary<>{BitPos_t{22}},	// COMP2_BRGEN
					Bit<3>{BitPos_t{18}},	// COMP2_BLANKING
					Bit<2>{BitPos_t{16}},	// COMP2_HYST
					Binary<>{BitPos_t{15}},	// COMP2_POLARITY
					Binary<>{BitPos_t{9}},	// COMP2_WINMODE
					Bit<2>{BitPos_t{7}},	// COMP2_INPSEL
					Bit<3>{BitPos_t{4}},	// COMP2_INMSEL
					Bit<2>{BitPos_t{2}},	// COMP2_PWRMODE
					Binary<>{BitPos_t{0}}	// COMP2_EN
					)

enum class COMP2_CSRField {
	COMP2_LOCK,		/*!< COMP2_CSR register lock bit*/
	COMP2_VALUE,		/*!< Comparator 2 output status bit*/
	COMP2_INMESEL,		/*!< comparator 2 input minus extended selection bits*/
	COMP2_SCALEN,		/*!< Voltage scaler enable bit*/
	COMP2_BRGEN,		/*!< Scaler bridge enable*/
	COMP2_BLANKING,		/*!< Comparator 2 blanking source selection bits*/
	COMP2_HYST,		/*!< Comparator 2 hysteresis selection bits*/
	COMP2_POLARITY,		/*!< Comparator 2 polarity selection bit*/
	COMP2_WINMODE,		/*!< Windows mode selection bit*/
	COMP2_INPSEL,		/*!< Comparator 2 Input Plus connection configuration bit*/
	COMP2_INMSEL,		/*!< Comparator 2 Input Minus connection configuration bit*/
	COMP2_PWRMODE,		/*!< Power Mode of the comparator 2*/
	COMP2_EN,		/*!< Comparator 2 enable bit*/
};

static constexpr Register<COMP2_CSRBitList, COMP2_CSRField> COMP2_CSR{BASE_ADDR, 0x04U};
/**@}*/


} // cpp_stm32::comp::reg
