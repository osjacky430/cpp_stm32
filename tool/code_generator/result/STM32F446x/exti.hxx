#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::exti::reg {

static constexpr auto BASE_ADDR = 0x40013c00U;

/**
 * @defgroup	EXTI_IMR_GROUP		Interrupt mask register (EXTI_IMR) group
 *
 * @{
 */

SETUP_REGISTER_INFO(IMRBitList,							 /**/
										Binary<>{BitPos_t{22}},	 // MR22
										Binary<>{BitPos_t{21}},	 // MR21
										Binary<>{BitPos_t{20}},	 // MR20
										Binary<>{BitPos_t{19}},	 // MR19
										Binary<>{BitPos_t{18}},	 // MR18
										Binary<>{BitPos_t{17}},	 // MR17
										Binary<>{BitPos_t{16}},	 // MR16
										Binary<>{BitPos_t{15}},	 // MR15
										Binary<>{BitPos_t{14}},	 // MR14
										Binary<>{BitPos_t{13}},	 // MR13
										Binary<>{BitPos_t{12}},	 // MR12
										Binary<>{BitPos_t{11}},	 // MR11
										Binary<>{BitPos_t{10}},	 // MR10
										Binary<>{BitPos_t{9}},	 // MR9
										Binary<>{BitPos_t{8}},	 // MR8
										Binary<>{BitPos_t{7}},	 // MR7
										Binary<>{BitPos_t{6}},	 // MR6
										Binary<>{BitPos_t{5}},	 // MR5
										Binary<>{BitPos_t{4}},	 // MR4
										Binary<>{BitPos_t{3}},	 // MR3
										Binary<>{BitPos_t{2}},	 // MR2
										Binary<>{BitPos_t{1}},	 // MR1
										Binary<>{BitPos_t{0}}		 // MR0
)

enum class IMRField {
	MR22, /*!< Interrupt Mask on line 22*/
	MR21, /*!< Interrupt Mask on line 21*/
	MR20, /*!< Interrupt Mask on line 20*/
	MR19, /*!< Interrupt Mask on line 19*/
	MR18, /*!< Interrupt Mask on line 18*/
	MR17, /*!< Interrupt Mask on line 17*/
	MR16, /*!< Interrupt Mask on line 16*/
	MR15, /*!< Interrupt Mask on line 15*/
	MR14, /*!< Interrupt Mask on line 14*/
	MR13, /*!< Interrupt Mask on line 13*/
	MR12, /*!< Interrupt Mask on line 12*/
	MR11, /*!< Interrupt Mask on line 11*/
	MR10, /*!< Interrupt Mask on line 10*/
	MR9,	/*!< Interrupt Mask on line 9*/
	MR8,	/*!< Interrupt Mask on line 8*/
	MR7,	/*!< Interrupt Mask on line 7*/
	MR6,	/*!< Interrupt Mask on line 6*/
	MR5,	/*!< Interrupt Mask on line 5*/
	MR4,	/*!< Interrupt Mask on line 4*/
	MR3,	/*!< Interrupt Mask on line 3*/
	MR2,	/*!< Interrupt Mask on line 2*/
	MR1,	/*!< Interrupt Mask on line 1*/
	MR0,	/*!< Interrupt Mask on line 0*/
};

static constexpr Register<IMRBitList, IMRField> IMR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	EXTI_EMR_GROUP		Event mask register (EXTI_EMR) group
 *
 * @{
 */

SETUP_REGISTER_INFO(EMRBitList,							 /**/
										Binary<>{BitPos_t{22}},	 // MR22
										Binary<>{BitPos_t{21}},	 // MR21
										Binary<>{BitPos_t{20}},	 // MR20
										Binary<>{BitPos_t{19}},	 // MR19
										Binary<>{BitPos_t{18}},	 // MR18
										Binary<>{BitPos_t{17}},	 // MR17
										Binary<>{BitPos_t{16}},	 // MR16
										Binary<>{BitPos_t{15}},	 // MR15
										Binary<>{BitPos_t{14}},	 // MR14
										Binary<>{BitPos_t{13}},	 // MR13
										Binary<>{BitPos_t{12}},	 // MR12
										Binary<>{BitPos_t{11}},	 // MR11
										Binary<>{BitPos_t{10}},	 // MR10
										Binary<>{BitPos_t{9}},	 // MR9
										Binary<>{BitPos_t{8}},	 // MR8
										Binary<>{BitPos_t{7}},	 // MR7
										Binary<>{BitPos_t{6}},	 // MR6
										Binary<>{BitPos_t{5}},	 // MR5
										Binary<>{BitPos_t{4}},	 // MR4
										Binary<>{BitPos_t{3}},	 // MR3
										Binary<>{BitPos_t{2}},	 // MR2
										Binary<>{BitPos_t{1}},	 // MR1
										Binary<>{BitPos_t{0}}		 // MR0
)

enum class EMRField {
	MR22, /*!< Event Mask on line 22*/
	MR21, /*!< Event Mask on line 21*/
	MR20, /*!< Event Mask on line 20*/
	MR19, /*!< Event Mask on line 19*/
	MR18, /*!< Event Mask on line 18*/
	MR17, /*!< Event Mask on line 17*/
	MR16, /*!< Event Mask on line 16*/
	MR15, /*!< Event Mask on line 15*/
	MR14, /*!< Event Mask on line 14*/
	MR13, /*!< Event Mask on line 13*/
	MR12, /*!< Event Mask on line 12*/
	MR11, /*!< Event Mask on line 11*/
	MR10, /*!< Event Mask on line 10*/
	MR9,	/*!< Event Mask on line 9*/
	MR8,	/*!< Event Mask on line 8*/
	MR7,	/*!< Event Mask on line 7*/
	MR6,	/*!< Event Mask on line 6*/
	MR5,	/*!< Event Mask on line 5*/
	MR4,	/*!< Event Mask on line 4*/
	MR3,	/*!< Event Mask on line 3*/
	MR2,	/*!< Event Mask on line 2*/
	MR1,	/*!< Event Mask on line 1*/
	MR0,	/*!< Event Mask on line 0*/
};

static constexpr Register<EMRBitList, EMRField> EMR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	EXTI_RTSR_GROUP		Rising Trigger selection register (EXTI_RTSR) group
 *
 * @{
 */

SETUP_REGISTER_INFO(RTSRBitList,						 /**/
										Binary<>{BitPos_t{22}},	 // TR22
										Binary<>{BitPos_t{21}},	 // TR21
										Binary<>{BitPos_t{20}},	 // TR20
										Binary<>{BitPos_t{19}},	 // TR19
										Binary<>{BitPos_t{18}},	 // TR18
										Binary<>{BitPos_t{17}},	 // TR17
										Binary<>{BitPos_t{16}},	 // TR16
										Binary<>{BitPos_t{15}},	 // TR15
										Binary<>{BitPos_t{14}},	 // TR14
										Binary<>{BitPos_t{13}},	 // TR13
										Binary<>{BitPos_t{12}},	 // TR12
										Binary<>{BitPos_t{11}},	 // TR11
										Binary<>{BitPos_t{10}},	 // TR10
										Binary<>{BitPos_t{9}},	 // TR9
										Binary<>{BitPos_t{8}},	 // TR8
										Binary<>{BitPos_t{7}},	 // TR7
										Binary<>{BitPos_t{6}},	 // TR6
										Binary<>{BitPos_t{5}},	 // TR5
										Binary<>{BitPos_t{4}},	 // TR4
										Binary<>{BitPos_t{3}},	 // TR3
										Binary<>{BitPos_t{2}},	 // TR2
										Binary<>{BitPos_t{1}},	 // TR1
										Binary<>{BitPos_t{0}}		 // TR0
)

enum class RTSRField {
	TR22, /*!< Rising trigger event configuration of line 22*/
	TR21, /*!< Rising trigger event configuration of line 21*/
	TR20, /*!< Rising trigger event configuration of line 20*/
	TR19, /*!< Rising trigger event configuration of line 19*/
	TR18, /*!< Rising trigger event configuration of line 18*/
	TR17, /*!< Rising trigger event configuration of line 17*/
	TR16, /*!< Rising trigger event configuration of line 16*/
	TR15, /*!< Rising trigger event configuration of line 15*/
	TR14, /*!< Rising trigger event configuration of line 14*/
	TR13, /*!< Rising trigger event configuration of line 13*/
	TR12, /*!< Rising trigger event configuration of line 12*/
	TR11, /*!< Rising trigger event configuration of line 11*/
	TR10, /*!< Rising trigger event configuration of line 10*/
	TR9,	/*!< Rising trigger event configuration of line 9*/
	TR8,	/*!< Rising trigger event configuration of line 8*/
	TR7,	/*!< Rising trigger event configuration of line 7*/
	TR6,	/*!< Rising trigger event configuration of line 6*/
	TR5,	/*!< Rising trigger event configuration of line 5*/
	TR4,	/*!< Rising trigger event configuration of line 4*/
	TR3,	/*!< Rising trigger event configuration of line 3*/
	TR2,	/*!< Rising trigger event configuration of line 2*/
	TR1,	/*!< Rising trigger event configuration of line 1*/
	TR0,	/*!< Rising trigger event configuration of line 0*/
};

static constexpr Register<RTSRBitList, RTSRField> RTSR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	EXTI_FTSR_GROUP		Falling Trigger selection register (EXTI_FTSR) group
 *
 * @{
 */

SETUP_REGISTER_INFO(FTSRBitList,						 /**/
										Binary<>{BitPos_t{22}},	 // TR22
										Binary<>{BitPos_t{21}},	 // TR21
										Binary<>{BitPos_t{20}},	 // TR20
										Binary<>{BitPos_t{19}},	 // TR19
										Binary<>{BitPos_t{18}},	 // TR18
										Binary<>{BitPos_t{17}},	 // TR17
										Binary<>{BitPos_t{16}},	 // TR16
										Binary<>{BitPos_t{15}},	 // TR15
										Binary<>{BitPos_t{14}},	 // TR14
										Binary<>{BitPos_t{13}},	 // TR13
										Binary<>{BitPos_t{12}},	 // TR12
										Binary<>{BitPos_t{11}},	 // TR11
										Binary<>{BitPos_t{10}},	 // TR10
										Binary<>{BitPos_t{9}},	 // TR9
										Binary<>{BitPos_t{8}},	 // TR8
										Binary<>{BitPos_t{7}},	 // TR7
										Binary<>{BitPos_t{6}},	 // TR6
										Binary<>{BitPos_t{5}},	 // TR5
										Binary<>{BitPos_t{4}},	 // TR4
										Binary<>{BitPos_t{3}},	 // TR3
										Binary<>{BitPos_t{2}},	 // TR2
										Binary<>{BitPos_t{1}},	 // TR1
										Binary<>{BitPos_t{0}}		 // TR0
)

enum class FTSRField {
	TR22, /*!< Falling trigger event configuration of line 22*/
	TR21, /*!< Falling trigger event configuration of line 21*/
	TR20, /*!< Falling trigger event configuration of line 20*/
	TR19, /*!< Falling trigger event configuration of line 19*/
	TR18, /*!< Falling trigger event configuration of line 18*/
	TR17, /*!< Falling trigger event configuration of line 17*/
	TR16, /*!< Falling trigger event configuration of line 16*/
	TR15, /*!< Falling trigger event configuration of line 15*/
	TR14, /*!< Falling trigger event configuration of line 14*/
	TR13, /*!< Falling trigger event configuration of line 13*/
	TR12, /*!< Falling trigger event configuration of line 12*/
	TR11, /*!< Falling trigger event configuration of line 11*/
	TR10, /*!< Falling trigger event configuration of line 10*/
	TR9,	/*!< Falling trigger event configuration of line 9*/
	TR8,	/*!< Falling trigger event configuration of line 8*/
	TR7,	/*!< Falling trigger event configuration of line 7*/
	TR6,	/*!< Falling trigger event configuration of line 6*/
	TR5,	/*!< Falling trigger event configuration of line 5*/
	TR4,	/*!< Falling trigger event configuration of line 4*/
	TR3,	/*!< Falling trigger event configuration of line 3*/
	TR2,	/*!< Falling trigger event configuration of line 2*/
	TR1,	/*!< Falling trigger event configuration of line 1*/
	TR0,	/*!< Falling trigger event configuration of line 0*/
};
