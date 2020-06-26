#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::exti::reg {

static constexpr auto BASE_ADDR = 0x40010400U;

/**
 * @defgroup	EXTI_IMR1_GROUP		Interrupt mask register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IMR1BitList, /**/
					Binary<>{BitPos_t{31}},	// MR31
					Binary<>{BitPos_t{30}},	// MR30
					Binary<>{BitPos_t{29}},	// MR29
					Binary<>{BitPos_t{28}},	// MR28
					Binary<>{BitPos_t{27}},	// MR27
					Binary<>{BitPos_t{26}},	// MR26
					Binary<>{BitPos_t{25}},	// MR25
					Binary<>{BitPos_t{24}},	// MR24
					Binary<>{BitPos_t{23}},	// MR23
					Binary<>{BitPos_t{22}},	// MR22
					Binary<>{BitPos_t{21}},	// MR21
					Binary<>{BitPos_t{20}},	// MR20
					Binary<>{BitPos_t{19}},	// MR19
					Binary<>{BitPos_t{18}},	// MR18
					Binary<>{BitPos_t{17}},	// MR17
					Binary<>{BitPos_t{16}},	// MR16
					Binary<>{BitPos_t{15}},	// MR15
					Binary<>{BitPos_t{14}},	// MR14
					Binary<>{BitPos_t{13}},	// MR13
					Binary<>{BitPos_t{12}},	// MR12
					Binary<>{BitPos_t{11}},	// MR11
					Binary<>{BitPos_t{10}},	// MR10
					Binary<>{BitPos_t{9}},	// MR9
					Binary<>{BitPos_t{8}},	// MR8
					Binary<>{BitPos_t{7}},	// MR7
					Binary<>{BitPos_t{6}},	// MR6
					Binary<>{BitPos_t{5}},	// MR5
					Binary<>{BitPos_t{4}},	// MR4
					Binary<>{BitPos_t{3}},	// MR3
					Binary<>{BitPos_t{2}},	// MR2
					Binary<>{BitPos_t{1}},	// MR1
					Binary<>{BitPos_t{0}}	// MR0
					)

enum class IMR1Field {
	MR31,		/*!< Interrupt Mask on line 31*/
	MR30,		/*!< Interrupt Mask on line 30*/
	MR29,		/*!< Interrupt Mask on line 29*/
	MR28,		/*!< Interrupt Mask on line 28*/
	MR27,		/*!< Interrupt Mask on line 27*/
	MR26,		/*!< Interrupt Mask on line 26*/
	MR25,		/*!< Interrupt Mask on line 25*/
	MR24,		/*!< Interrupt Mask on line 24*/
	MR23,		/*!< Interrupt Mask on line 23*/
	MR22,		/*!< Interrupt Mask on line 22*/
	MR21,		/*!< Interrupt Mask on line 21*/
	MR20,		/*!< Interrupt Mask on line 20*/
	MR19,		/*!< Interrupt Mask on line 19*/
	MR18,		/*!< Interrupt Mask on line 18*/
	MR17,		/*!< Interrupt Mask on line 17*/
	MR16,		/*!< Interrupt Mask on line 16*/
	MR15,		/*!< Interrupt Mask on line 15*/
	MR14,		/*!< Interrupt Mask on line 14*/
	MR13,		/*!< Interrupt Mask on line 13*/
	MR12,		/*!< Interrupt Mask on line 12*/
	MR11,		/*!< Interrupt Mask on line 11*/
	MR10,		/*!< Interrupt Mask on line 10*/
	MR9,		/*!< Interrupt Mask on line 9*/
	MR8,		/*!< Interrupt Mask on line 8*/
	MR7,		/*!< Interrupt Mask on line 7*/
	MR6,		/*!< Interrupt Mask on line 6*/
	MR5,		/*!< Interrupt Mask on line 5*/
	MR4,		/*!< Interrupt Mask on line 4*/
	MR3,		/*!< Interrupt Mask on line 3*/
	MR2,		/*!< Interrupt Mask on line 2*/
	MR1,		/*!< Interrupt Mask on line 1*/
	MR0,		/*!< Interrupt Mask on line 0*/
};

static constexpr Register<IMR1BitList, IMR1Field> IMR1{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	EXTI_EMR1_GROUP		Event mask register group
 *
 * @{
 */

SETUP_REGISTER_INFO(EMR1BitList, /**/
					Binary<>{BitPos_t{31}},	// MR31
					Binary<>{BitPos_t{30}},	// MR30
					Binary<>{BitPos_t{29}},	// MR29
					Binary<>{BitPos_t{28}},	// MR28
					Binary<>{BitPos_t{27}},	// MR27
					Binary<>{BitPos_t{26}},	// MR26
					Binary<>{BitPos_t{25}},	// MR25
					Binary<>{BitPos_t{24}},	// MR24
					Binary<>{BitPos_t{23}},	// MR23
					Binary<>{BitPos_t{22}},	// MR22
					Binary<>{BitPos_t{21}},	// MR21
					Binary<>{BitPos_t{20}},	// MR20
					Binary<>{BitPos_t{19}},	// MR19
					Binary<>{BitPos_t{18}},	// MR18
					Binary<>{BitPos_t{17}},	// MR17
					Binary<>{BitPos_t{16}},	// MR16
					Binary<>{BitPos_t{15}},	// MR15
					Binary<>{BitPos_t{14}},	// MR14
					Binary<>{BitPos_t{13}},	// MR13
					Binary<>{BitPos_t{12}},	// MR12
					Binary<>{BitPos_t{11}},	// MR11
					Binary<>{BitPos_t{10}},	// MR10
					Binary<>{BitPos_t{9}},	// MR9
					Binary<>{BitPos_t{8}},	// MR8
					Binary<>{BitPos_t{7}},	// MR7
					Binary<>{BitPos_t{6}},	// MR6
					Binary<>{BitPos_t{5}},	// MR5
					Binary<>{BitPos_t{4}},	// MR4
					Binary<>{BitPos_t{3}},	// MR3
					Binary<>{BitPos_t{2}},	// MR2
					Binary<>{BitPos_t{1}},	// MR1
					Binary<>{BitPos_t{0}}	// MR0
					)

enum class EMR1Field {
	MR31,		/*!< Event Mask on line 31*/
	MR30,		/*!< Event Mask on line 30*/
	MR29,		/*!< Event Mask on line 29*/
	MR28,		/*!< Event Mask on line 28*/
	MR27,		/*!< Event Mask on line 27*/
	MR26,		/*!< Event Mask on line 26*/
	MR25,		/*!< Event Mask on line 25*/
	MR24,		/*!< Event Mask on line 24*/
	MR23,		/*!< Event Mask on line 23*/
	MR22,		/*!< Event Mask on line 22*/
	MR21,		/*!< Event Mask on line 21*/
	MR20,		/*!< Event Mask on line 20*/
	MR19,		/*!< Event Mask on line 19*/
	MR18,		/*!< Event Mask on line 18*/
	MR17,		/*!< Event Mask on line 17*/
	MR16,		/*!< Event Mask on line 16*/
	MR15,		/*!< Event Mask on line 15*/
	MR14,		/*!< Event Mask on line 14*/
	MR13,		/*!< Event Mask on line 13*/
	MR12,		/*!< Event Mask on line 12*/
	MR11,		/*!< Event Mask on line 11*/
	MR10,		/*!< Event Mask on line 10*/
	MR9,		/*!< Event Mask on line 9*/
	MR8,		/*!< Event Mask on line 8*/
	MR7,		/*!< Event Mask on line 7*/
	MR6,		/*!< Event Mask on line 6*/
	MR5,		/*!< Event Mask on line 5*/
	MR4,		/*!< Event Mask on line 4*/
	MR3,		/*!< Event Mask on line 3*/
	MR2,		/*!< Event Mask on line 2*/
	MR1,		/*!< Event Mask on line 1*/
	MR0,		/*!< Event Mask on line 0*/
};

static constexpr Register<EMR1BitList, EMR1Field> EMR1{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	EXTI_RTSR1_GROUP		Rising Trigger selection register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RTSR1BitList, /**/
					Binary<>{BitPos_t{22}},	// TR22
					Binary<>{BitPos_t{21}},	// TR21
					Binary<>{BitPos_t{20}},	// TR20
					Binary<>{BitPos_t{19}},	// TR19
					Binary<>{BitPos_t{18}},	// TR18
					Binary<>{BitPos_t{16}},	// TR16
					Binary<>{BitPos_t{15}},	// TR15
					Binary<>{BitPos_t{14}},	// TR14
					Binary<>{BitPos_t{13}},	// TR13
					Binary<>{BitPos_t{12}},	// TR12
					Binary<>{BitPos_t{11}},	// TR11
					Binary<>{BitPos_t{10}},	// TR10
					Binary<>{BitPos_t{9}},	// TR9
					Binary<>{BitPos_t{8}},	// TR8
					Binary<>{BitPos_t{7}},	// TR7
					Binary<>{BitPos_t{6}},	// TR6
					Binary<>{BitPos_t{5}},	// TR5
					Binary<>{BitPos_t{4}},	// TR4
					Binary<>{BitPos_t{3}},	// TR3
					Binary<>{BitPos_t{2}},	// TR2
					Binary<>{BitPos_t{1}},	// TR1
					Binary<>{BitPos_t{0}}	// TR0
					)

enum class RTSR1Field {
	TR22,		/*!< Rising trigger event configuration of line 22*/
	TR21,		/*!< Rising trigger event configuration of line 21*/
	TR20,		/*!< Rising trigger event configuration of line 20*/
	TR19,		/*!< Rising trigger event configuration of line 19*/
	TR18,		/*!< Rising trigger event configuration of line 18*/
	TR16,		/*!< Rising trigger event configuration of line 16*/
	TR15,		/*!< Rising trigger event configuration of line 15*/
	TR14,		/*!< Rising trigger event configuration of line 14*/
	TR13,		/*!< Rising trigger event configuration of line 13*/
	TR12,		/*!< Rising trigger event configuration of line 12*/
	TR11,		/*!< Rising trigger event configuration of line 11*/
	TR10,		/*!< Rising trigger event configuration of line 10*/
	TR9,		/*!< Rising trigger event configuration of line 9*/
	TR8,		/*!< Rising trigger event configuration of line 8*/
	TR7,		/*!< Rising trigger event configuration of line 7*/
	TR6,		/*!< Rising trigger event configuration of line 6*/
	TR5,		/*!< Rising trigger event configuration of line 5*/
	TR4,		/*!< Rising trigger event configuration of line 4*/
	TR3,		/*!< Rising trigger event configuration of line 3*/
	TR2,		/*!< Rising trigger event configuration of line 2*/
	TR1,		/*!< Rising trigger event configuration of line 1*/
	TR0,		/*!< Rising trigger event configuration of line 0*/
};

static constexpr Register<RTSR1BitList, RTSR1Field> RTSR1{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	EXTI_FTSR1_GROUP		Falling Trigger selection register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FTSR1BitList, /**/
					Binary<>{BitPos_t{22}},	// TR22
					Binary<>{BitPos_t{21}},	// TR21
					Binary<>{BitPos_t{20}},	// TR20
					Binary<>{BitPos_t{19}},	// TR19
					Binary<>{BitPos_t{18}},	// TR18
					Binary<>{BitPos_t{16}},	// TR16
					Binary<>{BitPos_t{15}},	// TR15
					Binary<>{BitPos_t{14}},	// TR14
					Binary<>{BitPos_t{13}},	// TR13
					Binary<>{BitPos_t{12}},	// TR12
					Binary<>{BitPos_t{11}},	// TR11
					Binary<>{BitPos_t{10}},	// TR10
					Binary<>{BitPos_t{9}},	// TR9
					Binary<>{BitPos_t{8}},	// TR8
					Binary<>{BitPos_t{7}},	// TR7
					Binary<>{BitPos_t{6}},	// TR6
					Binary<>{BitPos_t{5}},	// TR5
					Binary<>{BitPos_t{4}},	// TR4
					Binary<>{BitPos_t{3}},	// TR3
					Binary<>{BitPos_t{2}},	// TR2
					Binary<>{BitPos_t{1}},	// TR1
					Binary<>{BitPos_t{0}}	// TR0
					)

enum class FTSR1Field {
	TR22,		/*!< Falling trigger event configuration of line 22*/
	TR21,		/*!< Falling trigger event configuration of line 21*/
	TR20,		/*!< Falling trigger event configuration of line 20*/
	TR19,		/*!< Falling trigger event configuration of line 19*/
	TR18,		/*!< Falling trigger event configuration of line 18*/
	TR16,		/*!< Falling trigger event configuration of line 16*/
	TR15,		/*!< Falling trigger event configuration of line 15*/
	TR14,		/*!< Falling trigger event configuration of line 14*/
	TR13,		/*!< Falling trigger event configuration of line 13*/
	TR12,		/*!< Falling trigger event configuration of line 12*/
	TR11,		/*!< Falling trigger event configuration of line 11*/
	TR10,		/*!< Falling trigger event configuration of line 10*/
	TR9,		/*!< Falling trigger event configuration of line 9*/
	TR8,		/*!< Falling trigger event configuration of line 8*/
	TR7,		/*!< Falling trigger event configuration of line 7*/
	TR6,		/*!< Falling trigger event configuration of line 6*/
	TR5,		/*!< Falling trigger event configuration of line 5*/
	TR4,		/*!< Falling trigger event configuration of line 4*/
	TR3,		/*!< Falling trigger event configuration of line 3*/
	TR2,		/*!< Falling trigger event configuration of line 2*/
	TR1,		/*!< Falling trigger event configuration of line 1*/
	TR0,		/*!< Falling trigger event configuration of line 0*/
};

static constexpr Register<FTSR1BitList, FTSR1Field> FTSR1{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	EXTI_SWIER1_GROUP		Software interrupt event register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SWIER1BitList, /**/
					Binary<>{BitPos_t{22}},	// SWIER22
					Binary<>{BitPos_t{21}},	// SWIER21
					Binary<>{BitPos_t{20}},	// SWIER20
					Binary<>{BitPos_t{19}},	// SWIER19
					Binary<>{BitPos_t{18}},	// SWIER18
					Binary<>{BitPos_t{16}},	// SWIER16
					Binary<>{BitPos_t{15}},	// SWIER15
					Binary<>{BitPos_t{14}},	// SWIER14
					Binary<>{BitPos_t{13}},	// SWIER13
					Binary<>{BitPos_t{12}},	// SWIER12
					Binary<>{BitPos_t{11}},	// SWIER11
					Binary<>{BitPos_t{10}},	// SWIER10
					Binary<>{BitPos_t{9}},	// SWIER9
					Binary<>{BitPos_t{8}},	// SWIER8
					Binary<>{BitPos_t{7}},	// SWIER7
					Binary<>{BitPos_t{6}},	// SWIER6
					Binary<>{BitPos_t{5}},	// SWIER5
					Binary<>{BitPos_t{4}},	// SWIER4
					Binary<>{BitPos_t{3}},	// SWIER3
					Binary<>{BitPos_t{2}},	// SWIER2
					Binary<>{BitPos_t{1}},	// SWIER1
					Binary<>{BitPos_t{0}}	// SWIER0
					)

enum class SWIER1Field {
	SWIER22,		/*!< Software Interrupt on line 22*/
	SWIER21,		/*!< Software Interrupt on line 21*/
	SWIER20,		/*!< Software Interrupt on line 20*/
	SWIER19,		/*!< Software Interrupt on line 19*/
	SWIER18,		/*!< Software Interrupt on line 18*/
	SWIER16,		/*!< Software Interrupt on line 16*/
	SWIER15,		/*!< Software Interrupt on line 15*/
	SWIER14,		/*!< Software Interrupt on line 14*/
	SWIER13,		/*!< Software Interrupt on line 13*/
	SWIER12,		/*!< Software Interrupt on line 12*/
	SWIER11,		/*!< Software Interrupt on line 11*/
	SWIER10,		/*!< Software Interrupt on line 10*/
	SWIER9,		/*!< Software Interrupt on line 9*/
	SWIER8,		/*!< Software Interrupt on line 8*/
	SWIER7,		/*!< Software Interrupt on line 7*/
	SWIER6,		/*!< Software Interrupt on line 6*/
	SWIER5,		/*!< Software Interrupt on line 5*/
	SWIER4,		/*!< Software Interrupt on line 4*/
	SWIER3,		/*!< Software Interrupt on line 3*/
	SWIER2,		/*!< Software Interrupt on line 2*/
	SWIER1,		/*!< Software Interrupt on line 1*/
	SWIER0,		/*!< Software Interrupt on line 0*/
};

static constexpr Register<SWIER1BitList, SWIER1Field> SWIER1{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	EXTI_PR1_GROUP		Pending register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PR1BitList, /**/
					Binary<>{BitPos_t{22}},	// PR22
					Binary<>{BitPos_t{21}},	// PR21
					Binary<>{BitPos_t{20}},	// PR20
					Binary<>{BitPos_t{19}},	// PR19
					Binary<>{BitPos_t{18}},	// PR18
					Binary<>{BitPos_t{16}},	// PR16
					Binary<>{BitPos_t{15}},	// PR15
					Binary<>{BitPos_t{14}},	// PR14
					Binary<>{BitPos_t{13}},	// PR13
					Binary<>{BitPos_t{12}},	// PR12
					Binary<>{BitPos_t{11}},	// PR11
					Binary<>{BitPos_t{10}},	// PR10
					Binary<>{BitPos_t{9}},	// PR9
					Binary<>{BitPos_t{8}},	// PR8
					Binary<>{BitPos_t{7}},	// PR7
					Binary<>{BitPos_t{6}},	// PR6
					Binary<>{BitPos_t{5}},	// PR5
					Binary<>{BitPos_t{4}},	// PR4
					Binary<>{BitPos_t{3}},	// PR3
					Binary<>{BitPos_t{2}},	// PR2
					Binary<>{BitPos_t{1}},	// PR1
					Binary<>{BitPos_t{0}}	// PR0
					)

enum class PR1Field {
	PR22,		/*!< Pending bit 22*/
	PR21,		/*!< Pending bit 21*/
	PR20,		/*!< Pending bit 20*/
	PR19,		/*!< Pending bit 19*/
	PR18,		/*!< Pending bit 18*/
	PR16,		/*!< Pending bit 16*/
	PR15,		/*!< Pending bit 15*/
	PR14,		/*!< Pending bit 14*/
	PR13,		/*!< Pending bit 13*/
	PR12,		/*!< Pending bit 12*/
	PR11,		/*!< Pending bit 11*/
	PR10,		/*!< Pending bit 10*/
	PR9,		/*!< Pending bit 9*/
	PR8,		/*!< Pending bit 8*/
	PR7,		/*!< Pending bit 7*/
	PR6,		/*!< Pending bit 6*/
	PR5,		/*!< Pending bit 5*/
	PR4,		/*!< Pending bit 4*/
	PR3,		/*!< Pending bit 3*/
	PR2,		/*!< Pending bit 2*/
	PR1,		/*!< Pending bit 1*/
	PR0,		/*!< Pending bit 0*/
};

static constexpr Register<PR1BitList, PR1Field> PR1{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	EXTI_IMR2_GROUP		Interrupt mask register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IMR2BitList, /**/
					Binary<>{BitPos_t{7}},	// MR39
					Binary<>{BitPos_t{6}},	// MR38
					Binary<>{BitPos_t{5}},	// MR37
					Binary<>{BitPos_t{4}},	// MR36
					Binary<>{BitPos_t{3}},	// MR35
					Binary<>{BitPos_t{2}},	// MR34
					Binary<>{BitPos_t{1}},	// MR33
					Binary<>{BitPos_t{0}}	// MR32
					)

enum class IMR2Field {
	MR39,		/*!< Interrupt Mask on external/internal line 39*/
	MR38,		/*!< Interrupt Mask on external/internal line 38*/
	MR37,		/*!< Interrupt Mask on external/internal line 37*/
	MR36,		/*!< Interrupt Mask on external/internal line 36*/
	MR35,		/*!< Interrupt Mask on external/internal line 35*/
	MR34,		/*!< Interrupt Mask on external/internal line 34*/
	MR33,		/*!< Interrupt Mask on external/internal line 33*/
	MR32,		/*!< Interrupt Mask on external/internal line 32*/
};

static constexpr Register<IMR2BitList, IMR2Field> IMR2{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	EXTI_EMR2_GROUP		Event mask register group
 *
 * @{
 */

SETUP_REGISTER_INFO(EMR2BitList, /**/
					Binary<>{BitPos_t{7}},	// MR39
					Binary<>{BitPos_t{6}},	// MR38
					Binary<>{BitPos_t{5}},	// MR37
					Binary<>{BitPos_t{4}},	// MR36
					Binary<>{BitPos_t{3}},	// MR35
					Binary<>{BitPos_t{2}},	// MR34
					Binary<>{BitPos_t{1}},	// MR33
					Binary<>{BitPos_t{0}}	// MR32
					)

enum class EMR2Field {
	MR39,		/*!< Event mask on external/internal line 39*/
	MR38,		/*!< Event mask on external/internal line 38*/
	MR37,		/*!< Event mask on external/internal line 37*/
	MR36,		/*!< Event mask on external/internal line 36*/
	MR35,		/*!< Event mask on external/internal line 35*/
	MR34,		/*!< Event mask on external/internal line 34*/
	MR33,		/*!< Event mask on external/internal line 33*/
	MR32,		/*!< Event mask on external/internal line 32*/
};

static constexpr Register<EMR2BitList, EMR2Field> EMR2{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	EXTI_RTSR2_GROUP		Rising Trigger selection register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RTSR2BitList, /**/
					Binary<>{BitPos_t{6}},	// RT38
					Binary<>{BitPos_t{5}},	// RT37
					Binary<>{BitPos_t{4}},	// RT36
					Binary<>{BitPos_t{3}}	// RT35
					)

enum class RTSR2Field {
	RT38,		/*!< Rising trigger event configuration bit of line 38*/
	RT37,		/*!< Rising trigger event configuration bit of line 37*/
	RT36,		/*!< Rising trigger event configuration bit of line 36*/
	RT35,		/*!< Rising trigger event configuration bit of line 35*/
};

static constexpr Register<RTSR2BitList, RTSR2Field> RTSR2{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	EXTI_FTSR2_GROUP		Falling Trigger selection register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FTSR2BitList, /**/
					Binary<>{BitPos_t{6}},	// FT38
					Binary<>{BitPos_t{5}},	// FT37
					Binary<>{BitPos_t{4}},	// FT36
					Binary<>{BitPos_t{3}}	// FT35
					)

enum class FTSR2Field {
	FT38,		/*!< Falling trigger event configuration bit of line 38*/
	FT37,		/*!< Falling trigger event configuration bit of line 37*/
	FT36,		/*!< Falling trigger event configuration bit of line 36*/
	FT35,		/*!< Falling trigger event configuration bit of line 35*/
};

static constexpr Register<FTSR2BitList, FTSR2Field> FTSR2{BASE_ADDR, 0x2cU};
/**@}*/

/**
 * @defgroup	EXTI_SWIER2_GROUP		Software interrupt event register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SWIER2BitList, /**/
					Binary<>{BitPos_t{6}},	// SWI38
					Binary<>{BitPos_t{5}},	// SWI37
					Binary<>{BitPos_t{4}},	// SWI36
					Binary<>{BitPos_t{3}}	// SWI35
					)

enum class SWIER2Field {
	SWI38,		/*!< Software interrupt on line 38*/
	SWI37,		/*!< Software interrupt on line 37*/
	SWI36,		/*!< Software interrupt on line 36*/
	SWI35,		/*!< Software interrupt on line 35*/
};

static constexpr Register<SWIER2BitList, SWIER2Field> SWIER2{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	EXTI_PR2_GROUP		Pending register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PR2BitList, /**/
					Binary<>{BitPos_t{6}},	// PIF38
					Binary<>{BitPos_t{5}},	// PIF37
					Binary<>{BitPos_t{4}},	// PIF36
					Binary<>{BitPos_t{3}}	// PIF35
					)

enum class PR2Field {
	PIF38,		/*!< Pending interrupt flag on line 38*/
	PIF37,		/*!< Pending interrupt flag on line 37*/
	PIF36,		/*!< Pending interrupt flag on line 36*/
	PIF35,		/*!< Pending interrupt flag on line 35*/
};

static constexpr Register<PR2BitList, PR2Field> PR2{BASE_ADDR, 0x34U};
/**@}*/


} // cpp_stm32::exti::reg
