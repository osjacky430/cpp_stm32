#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::tsc::reg {

static constexpr auto BASE_ADDR = 0x40024000U;

/**
 * @defgroup	TSC_CR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{0}},	// TSCE
					Binary<>{BitPos_t{1}},	// START
					Binary<>{BitPos_t{2}},	// AM
					Binary<>{BitPos_t{3}},	// SYNCPOL
					Binary<>{BitPos_t{4}},	// IODEF
					Bit<3>{BitPos_t{5}},	// MCV
					Bit<3>{BitPos_t{12}},	// PGPSC
					Binary<>{BitPos_t{15}},	// SSPSC
					Binary<>{BitPos_t{16}},	// SSE
					Bit<7>{BitPos_t{17}},	// SSD
					Bit<4>{BitPos_t{24}},	// CTPL
					Bit<4>{BitPos_t{28}}	// CTPH
					)

enum class CRField {
	TSCE,		/*!< Touch sensing controller enable*/
	START,		/*!< Start a new acquisition*/
	AM,		/*!< Acquisition mode*/
	SYNCPOL,		/*!< Synchronization pin polarity*/
	IODEF,		/*!< I/O Default mode*/
	MCV,		/*!< Max count value*/
	PGPSC,		/*!< pulse generator prescaler*/
	SSPSC,		/*!< Spread spectrum prescaler*/
	SSE,		/*!< Spread spectrum enable*/
	SSD,		/*!< Spread spectrum deviation*/
	CTPL,		/*!< Charge transfer pulse low*/
	CTPH,		/*!< Charge transfer pulse high*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	TSC_IER_GROUP		interrupt enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IERBitList, /**/
					Binary<>{BitPos_t{0}},	// EOAIE
					Binary<>{BitPos_t{1}}	// MCEIE
					)

enum class IERField {
	EOAIE,		/*!< End of acquisition interrupt enable*/
	MCEIE,		/*!< Max count error interrupt enable*/
};

static constexpr Register<IERBitList, IERField> IER{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	TSC_ICR_GROUP		interrupt clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICRBitList, /**/
					Binary<>{BitPos_t{0}},	// EOAIC
					Binary<>{BitPos_t{1}}	// MCEIC
					)

enum class ICRField {
	EOAIC,		/*!< End of acquisition interrupt clear*/
	MCEIC,		/*!< Max count error interrupt clear*/
};

static constexpr Register<ICRBitList, ICRField> ICR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	TSC_ISR_GROUP		interrupt status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISRBitList, /**/
					Binary<>{BitPos_t{0}},	// EOAF
					Binary<>{BitPos_t{1}}	// MCEF
					)

enum class ISRField {
	EOAF,		/*!< End of acquisition flag*/
	MCEF,		/*!< Max count error flag*/
};

static constexpr Register<ISRBitList, ISRField> ISR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	TSC_IOHCR_GROUP		I/O hysteresis control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOHCRBitList, /**/
					Binary<>{BitPos_t{0}},	// G1_IO1
					Binary<>{BitPos_t{1}},	// G1_IO2
					Binary<>{BitPos_t{2}},	// G1_IO3
					Binary<>{BitPos_t{3}},	// G1_IO4
					Binary<>{BitPos_t{4}},	// G2_IO1
					Binary<>{BitPos_t{5}},	// G2_IO2
					Binary<>{BitPos_t{6}},	// G2_IO3
					Binary<>{BitPos_t{7}},	// G2_IO4
					Binary<>{BitPos_t{8}},	// G3_IO1
					Binary<>{BitPos_t{9}},	// G3_IO2
					Binary<>{BitPos_t{10}},	// G3_IO3
					Binary<>{BitPos_t{11}},	// G3_IO4
					Binary<>{BitPos_t{12}},	// G4_IO1
					Binary<>{BitPos_t{13}},	// G4_IO2
					Binary<>{BitPos_t{14}},	// G4_IO3
					Binary<>{BitPos_t{15}},	// G4_IO4
					Binary<>{BitPos_t{16}},	// G5_IO1
					Binary<>{BitPos_t{17}},	// G5_IO2
					Binary<>{BitPos_t{18}},	// G5_IO3
					Binary<>{BitPos_t{19}},	// G5_IO4
					Binary<>{BitPos_t{20}},	// G6_IO1
					Binary<>{BitPos_t{21}},	// G6_IO2
					Binary<>{BitPos_t{22}},	// G6_IO3
					Binary<>{BitPos_t{23}},	// G6_IO4
					Binary<>{BitPos_t{24}},	// G7_IO1
					Binary<>{BitPos_t{25}},	// G7_IO2
					Binary<>{BitPos_t{26}},	// G7_IO3
					Binary<>{BitPos_t{27}},	// G7_IO4
					Binary<>{BitPos_t{28}},	// G8_IO1
					Binary<>{BitPos_t{29}},	// G8_IO2
					Binary<>{BitPos_t{30}},	// G8_IO3
					Binary<>{BitPos_t{31}}	// G8_IO4
					)

enum class IOHCRField {
	G1_IO1,		/*!< G1_IO1*/
	G1_IO2,		/*!< G1_IO2*/
	G1_IO3,		/*!< G1_IO3*/
	G1_IO4,		/*!< G1_IO4*/
	G2_IO1,		/*!< G2_IO1*/
	G2_IO2,		/*!< G2_IO2*/
	G2_IO3,		/*!< G2_IO3*/
	G2_IO4,		/*!< G2_IO4*/
	G3_IO1,		/*!< G3_IO1*/
	G3_IO2,		/*!< G3_IO2*/
	G3_IO3,		/*!< G3_IO3*/
	G3_IO4,		/*!< G3_IO4*/
	G4_IO1,		/*!< G4_IO1*/
	G4_IO2,		/*!< G4_IO2*/
	G4_IO3,		/*!< G4_IO3*/
	G4_IO4,		/*!< G4_IO4*/
	G5_IO1,		/*!< G5_IO1*/
	G5_IO2,		/*!< G5_IO2*/
	G5_IO3,		/*!< G5_IO3*/
	G5_IO4,		/*!< G5_IO4*/
	G6_IO1,		/*!< G6_IO1*/
	G6_IO2,		/*!< G6_IO2*/
	G6_IO3,		/*!< G6_IO3*/
	G6_IO4,		/*!< G6_IO4*/
	G7_IO1,		/*!< G7_IO1*/
	G7_IO2,		/*!< G7_IO2*/
	G7_IO3,		/*!< G7_IO3*/
	G7_IO4,		/*!< G7_IO4*/
	G8_IO1,		/*!< G8_IO1*/
	G8_IO2,		/*!< G8_IO2*/
	G8_IO3,		/*!< G8_IO3*/
	G8_IO4,		/*!< G8_IO4*/
};

static constexpr Register<IOHCRBitList, IOHCRField> IOHCR{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	TSC_IOASCR_GROUP		I/O analog switch control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOASCRBitList, /**/
					Binary<>{BitPos_t{0}},	// G1_IO1
					Binary<>{BitPos_t{1}},	// G1_IO2
					Binary<>{BitPos_t{2}},	// G1_IO3
					Binary<>{BitPos_t{3}},	// G1_IO4
					Binary<>{BitPos_t{4}},	// G2_IO1
					Binary<>{BitPos_t{5}},	// G2_IO2
					Binary<>{BitPos_t{6}},	// G2_IO3
					Binary<>{BitPos_t{7}},	// G2_IO4
					Binary<>{BitPos_t{8}},	// G3_IO1
					Binary<>{BitPos_t{9}},	// G3_IO2
					Binary<>{BitPos_t{10}},	// G3_IO3
					Binary<>{BitPos_t{11}},	// G3_IO4
					Binary<>{BitPos_t{12}},	// G4_IO1
					Binary<>{BitPos_t{13}},	// G4_IO2
					Binary<>{BitPos_t{14}},	// G4_IO3
					Binary<>{BitPos_t{15}},	// G4_IO4
					Binary<>{BitPos_t{16}},	// G5_IO1
					Binary<>{BitPos_t{17}},	// G5_IO2
					Binary<>{BitPos_t{18}},	// G5_IO3
					Binary<>{BitPos_t{19}},	// G5_IO4
					Binary<>{BitPos_t{20}},	// G6_IO1
					Binary<>{BitPos_t{21}},	// G6_IO2
					Binary<>{BitPos_t{22}},	// G6_IO3
					Binary<>{BitPos_t{23}},	// G6_IO4
					Binary<>{BitPos_t{24}},	// G7_IO1
					Binary<>{BitPos_t{25}},	// G7_IO2
					Binary<>{BitPos_t{26}},	// G7_IO3
					Binary<>{BitPos_t{27}},	// G7_IO4
					Binary<>{BitPos_t{28}},	// G8_IO1
					Binary<>{BitPos_t{29}},	// G8_IO2
					Binary<>{BitPos_t{30}},	// G8_IO3
					Binary<>{BitPos_t{31}}	// G8_IO4
					)

enum class IOASCRField {
	G1_IO1,		/*!< G1_IO1*/
	G1_IO2,		/*!< G1_IO2*/
	G1_IO3,		/*!< G1_IO3*/
	G1_IO4,		/*!< G1_IO4*/
	G2_IO1,		/*!< G2_IO1*/
	G2_IO2,		/*!< G2_IO2*/
	G2_IO3,		/*!< G2_IO3*/
	G2_IO4,		/*!< G2_IO4*/
	G3_IO1,		/*!< G3_IO1*/
	G3_IO2,		/*!< G3_IO2*/
	G3_IO3,		/*!< G3_IO3*/
	G3_IO4,		/*!< G3_IO4*/
	G4_IO1,		/*!< G4_IO1*/
	G4_IO2,		/*!< G4_IO2*/
	G4_IO3,		/*!< G4_IO3*/
	G4_IO4,		/*!< G4_IO4*/
	G5_IO1,		/*!< G5_IO1*/
	G5_IO2,		/*!< G5_IO2*/
	G5_IO3,		/*!< G5_IO3*/
	G5_IO4,		/*!< G5_IO4*/
	G6_IO1,		/*!< G6_IO1*/
	G6_IO2,		/*!< G6_IO2*/
	G6_IO3,		/*!< G6_IO3*/
	G6_IO4,		/*!< G6_IO4*/
	G7_IO1,		/*!< G7_IO1*/
	G7_IO2,		/*!< G7_IO2*/
	G7_IO3,		/*!< G7_IO3*/
	G7_IO4,		/*!< G7_IO4*/
	G8_IO1,		/*!< G8_IO1*/
	G8_IO2,		/*!< G8_IO2*/
	G8_IO3,		/*!< G8_IO3*/
	G8_IO4,		/*!< G8_IO4*/
};

static constexpr Register<IOASCRBitList, IOASCRField> IOASCR{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	TSC_IOSCR_GROUP		I/O sampling control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOSCRBitList, /**/
					Binary<>{BitPos_t{0}},	// G1_IO1
					Binary<>{BitPos_t{1}},	// G1_IO2
					Binary<>{BitPos_t{2}},	// G1_IO3
					Binary<>{BitPos_t{3}},	// G1_IO4
					Binary<>{BitPos_t{4}},	// G2_IO1
					Binary<>{BitPos_t{5}},	// G2_IO2
					Binary<>{BitPos_t{6}},	// G2_IO3
					Binary<>{BitPos_t{7}},	// G2_IO4
					Binary<>{BitPos_t{8}},	// G3_IO1
					Binary<>{BitPos_t{9}},	// G3_IO2
					Binary<>{BitPos_t{10}},	// G3_IO3
					Binary<>{BitPos_t{11}},	// G3_IO4
					Binary<>{BitPos_t{12}},	// G4_IO1
					Binary<>{BitPos_t{13}},	// G4_IO2
					Binary<>{BitPos_t{14}},	// G4_IO3
					Binary<>{BitPos_t{15}},	// G4_IO4
					Binary<>{BitPos_t{16}},	// G5_IO1
					Binary<>{BitPos_t{17}},	// G5_IO2
					Binary<>{BitPos_t{18}},	// G5_IO3
					Binary<>{BitPos_t{19}},	// G5_IO4
					Binary<>{BitPos_t{20}},	// G6_IO1
					Binary<>{BitPos_t{21}},	// G6_IO2
					Binary<>{BitPos_t{22}},	// G6_IO3
					Binary<>{BitPos_t{23}},	// G6_IO4
					Binary<>{BitPos_t{24}},	// G7_IO1
					Binary<>{BitPos_t{25}},	// G7_IO2
					Binary<>{BitPos_t{26}},	// G7_IO3
					Binary<>{BitPos_t{27}},	// G7_IO4
					Binary<>{BitPos_t{28}},	// G8_IO1
					Binary<>{BitPos_t{29}},	// G8_IO2
					Binary<>{BitPos_t{30}},	// G8_IO3
					Binary<>{BitPos_t{31}}	// G8_IO4
					)

enum class IOSCRField {
	G1_IO1,		/*!< G1_IO1*/
	G1_IO2,		/*!< G1_IO2*/
	G1_IO3,		/*!< G1_IO3*/
	G1_IO4,		/*!< G1_IO4*/
	G2_IO1,		/*!< G2_IO1*/
	G2_IO2,		/*!< G2_IO2*/
	G2_IO3,		/*!< G2_IO3*/
	G2_IO4,		/*!< G2_IO4*/
	G3_IO1,		/*!< G3_IO1*/
	G3_IO2,		/*!< G3_IO2*/
	G3_IO3,		/*!< G3_IO3*/
	G3_IO4,		/*!< G3_IO4*/
	G4_IO1,		/*!< G4_IO1*/
	G4_IO2,		/*!< G4_IO2*/
	G4_IO3,		/*!< G4_IO3*/
	G4_IO4,		/*!< G4_IO4*/
	G5_IO1,		/*!< G5_IO1*/
	G5_IO2,		/*!< G5_IO2*/
	G5_IO3,		/*!< G5_IO3*/
	G5_IO4,		/*!< G5_IO4*/
	G6_IO1,		/*!< G6_IO1*/
	G6_IO2,		/*!< G6_IO2*/
	G6_IO3,		/*!< G6_IO3*/
	G6_IO4,		/*!< G6_IO4*/
	G7_IO1,		/*!< G7_IO1*/
	G7_IO2,		/*!< G7_IO2*/
	G7_IO3,		/*!< G7_IO3*/
	G7_IO4,		/*!< G7_IO4*/
	G8_IO1,		/*!< G8_IO1*/
	G8_IO2,		/*!< G8_IO2*/
	G8_IO3,		/*!< G8_IO3*/
	G8_IO4,		/*!< G8_IO4*/
};

static constexpr Register<IOSCRBitList, IOSCRField> IOSCR{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	TSC_IOCCR_GROUP		I/O channel control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOCCRBitList, /**/
					Binary<>{BitPos_t{0}},	// G1_IO1
					Binary<>{BitPos_t{1}},	// G1_IO2
					Binary<>{BitPos_t{2}},	// G1_IO3
					Binary<>{BitPos_t{3}},	// G1_IO4
					Binary<>{BitPos_t{4}},	// G2_IO1
					Binary<>{BitPos_t{5}},	// G2_IO2
					Binary<>{BitPos_t{6}},	// G2_IO3
					Binary<>{BitPos_t{7}},	// G2_IO4
					Binary<>{BitPos_t{8}},	// G3_IO1
					Binary<>{BitPos_t{9}},	// G3_IO2
					Binary<>{BitPos_t{10}},	// G3_IO3
					Binary<>{BitPos_t{11}},	// G3_IO4
					Binary<>{BitPos_t{12}},	// G4_IO1
					Binary<>{BitPos_t{13}},	// G4_IO2
					Binary<>{BitPos_t{14}},	// G4_IO3
					Binary<>{BitPos_t{15}},	// G4_IO4
					Binary<>{BitPos_t{16}},	// G5_IO1
					Binary<>{BitPos_t{17}},	// G5_IO2
					Binary<>{BitPos_t{18}},	// G5_IO3
					Binary<>{BitPos_t{19}},	// G5_IO4
					Binary<>{BitPos_t{20}},	// G6_IO1
					Binary<>{BitPos_t{21}},	// G6_IO2
					Binary<>{BitPos_t{22}},	// G6_IO3
					Binary<>{BitPos_t{23}},	// G6_IO4
					Binary<>{BitPos_t{24}},	// G7_IO1
					Binary<>{BitPos_t{25}},	// G7_IO2
					Binary<>{BitPos_t{26}},	// G7_IO3
					Binary<>{BitPos_t{27}},	// G7_IO4
					Binary<>{BitPos_t{28}},	// G8_IO1
					Binary<>{BitPos_t{29}},	// G8_IO2
					Binary<>{BitPos_t{30}},	// G8_IO3
					Binary<>{BitPos_t{31}}	// G8_IO4
					)

enum class IOCCRField {
	G1_IO1,		/*!< G1_IO1*/
	G1_IO2,		/*!< G1_IO2*/
	G1_IO3,		/*!< G1_IO3*/
	G1_IO4,		/*!< G1_IO4*/
	G2_IO1,		/*!< G2_IO1*/
	G2_IO2,		/*!< G2_IO2*/
	G2_IO3,		/*!< G2_IO3*/
	G2_IO4,		/*!< G2_IO4*/
	G3_IO1,		/*!< G3_IO1*/
	G3_IO2,		/*!< G3_IO2*/
	G3_IO3,		/*!< G3_IO3*/
	G3_IO4,		/*!< G3_IO4*/
	G4_IO1,		/*!< G4_IO1*/
	G4_IO2,		/*!< G4_IO2*/
	G4_IO3,		/*!< G4_IO3*/
	G4_IO4,		/*!< G4_IO4*/
	G5_IO1,		/*!< G5_IO1*/
	G5_IO2,		/*!< G5_IO2*/
	G5_IO3,		/*!< G5_IO3*/
	G5_IO4,		/*!< G5_IO4*/
	G6_IO1,		/*!< G6_IO1*/
	G6_IO2,		/*!< G6_IO2*/
	G6_IO3,		/*!< G6_IO3*/
	G6_IO4,		/*!< G6_IO4*/
	G7_IO1,		/*!< G7_IO1*/
	G7_IO2,		/*!< G7_IO2*/
	G7_IO3,		/*!< G7_IO3*/
	G7_IO4,		/*!< G7_IO4*/
	G8_IO1,		/*!< G8_IO1*/
	G8_IO2,		/*!< G8_IO2*/
	G8_IO3,		/*!< G8_IO3*/
	G8_IO4,		/*!< G8_IO4*/
};

static constexpr Register<IOCCRBitList, IOCCRField> IOCCR{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	TSC_IOGCSR_GROUP		I/O group control status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOGCSRBitList, /**/
					Bit<8>{BitPos_t{0}},	// G1
					StatusBit<8>{BitPos_t{16}}	// G1
					)

enum class IOGCSRField {
	G1,		/*!< Analog I/O group x enable*/
	G1,		/*!< Analog I/O group x status*/
};

static constexpr Register<IOGCSRBitList, IOGCSRField> IOGCSR{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	TSC_IOG1CR_GROUP		I/O group x counter register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOG1CRBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{0}}	// CNT
					)

enum class IOG1CRField {
	CNT,		/*!< Counter value*/
};

static constexpr Register<IOG1CRBitList, IOG1CRField> IOG1CR{BASE_ADDR, 0x34U};
/**@}*/

/**
 * @defgroup	TSC_IOG2CR_GROUP		I/O group x counter register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOG2CRBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{0}}	// CNT
					)

enum class IOG2CRField {
	CNT,		/*!< Counter value*/
};

static constexpr Register<IOG2CRBitList, IOG2CRField> IOG2CR{BASE_ADDR, 0x38U};
/**@}*/

/**
 * @defgroup	TSC_IOG3CR_GROUP		I/O group x counter register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOG3CRBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{0}}	// CNT
					)

enum class IOG3CRField {
	CNT,		/*!< Counter value*/
};

static constexpr Register<IOG3CRBitList, IOG3CRField> IOG3CR{BASE_ADDR, 0x3cU};
/**@}*/

/**
 * @defgroup	TSC_IOG4CR_GROUP		I/O group x counter register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOG4CRBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{0}}	// CNT
					)

enum class IOG4CRField {
	CNT,		/*!< Counter value*/
};

static constexpr Register<IOG4CRBitList, IOG4CRField> IOG4CR{BASE_ADDR, 0x40U};
/**@}*/

/**
 * @defgroup	TSC_IOG5CR_GROUP		I/O group x counter register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOG5CRBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{0}}	// CNT
					)

enum class IOG5CRField {
	CNT,		/*!< Counter value*/
};

static constexpr Register<IOG5CRBitList, IOG5CRField> IOG5CR{BASE_ADDR, 0x44U};
/**@}*/

/**
 * @defgroup	TSC_IOG6CR_GROUP		I/O group x counter register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOG6CRBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{0}}	// CNT
					)

enum class IOG6CRField {
	CNT,		/*!< Counter value*/
};

static constexpr Register<IOG6CRBitList, IOG6CRField> IOG6CR{BASE_ADDR, 0x48U};
/**@}*/

/**
 * @defgroup	TSC_IOG7CR_GROUP		I/O group x counter register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOG7CRBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{0}}	// CNT
					)

enum class IOG7CRField {
	CNT,		/*!< Counter value*/
};

static constexpr Register<IOG7CRBitList, IOG7CRField> IOG7CR{BASE_ADDR, 0x4cU};
/**@}*/

/**
 * @defgroup	TSC_IOG8CR_GROUP		I/O group x counter register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IOG8CRBitList, /**/
					Bit<14, std::uint16_t>{BitPos_t{0}}	// CNT
					)

enum class IOG8CRField {
	CNT,		/*!< Counter value*/
};

static constexpr Register<IOG8CRBitList, IOG8CRField> IOG8CR{BASE_ADDR, 0x50U};
/**@}*/


} // cpp_stm32::tsc::reg
