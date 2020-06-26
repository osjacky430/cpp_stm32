#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::lcd::reg {

static constexpr auto BASE_ADDR = 0x40002400U;

/**
 * @defgroup	LCD_CR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{8}},	// BUFEN
					Binary<>{BitPos_t{7}},	// MUX_SEG
					Binary<>{BitPos_t{0}},	// LCDEN
					Binary<>{BitPos_t{1}},	// VSEL
					Bit<3>{BitPos_t{2}},	// DUTY
					Bit<2>{BitPos_t{5}}	// BIAS
					)

enum class CRField {
	BUFEN,		/*!< Voltage output buffer enable*/
	MUX_SEG,		/*!< Mux segment enable*/
	LCDEN,		/*!< LCD controller enable*/
	VSEL,		/*!< Voltage source selection*/
	DUTY,		/*!< Duty selection*/
	BIAS,		/*!< Bias selector*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	LCD_FCR_GROUP		frame control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FCRBitList, /**/
					Binary<>{BitPos_t{0}},	// HD
					Binary<>{BitPos_t{1}},	// SOFIE
					Binary<>{BitPos_t{3}},	// UDDIE
					Bit<3>{BitPos_t{4}},	// PON
					Bit<3>{BitPos_t{7}},	// DEAD
					Bit<3>{BitPos_t{10}},	// CC
					Bit<3>{BitPos_t{13}},	// BLINKF
					Bit<2>{BitPos_t{16}},	// BLINK
					Bit<4>{BitPos_t{18}},	// DIV
					Bit<4>{BitPos_t{22}}	// PS
					)

enum class FCRField {
	HD,		/*!< High drive enable*/
	SOFIE,		/*!< Start of frame interrupt enable*/
	UDDIE,		/*!< Update display done interrupt enable*/
	PON,		/*!< Pulse ON duration*/
	DEAD,		/*!< Dead time duration*/
	CC,		/*!< Contrast control*/
	BLINKF,		/*!< Blink frequency selection*/
	BLINK,		/*!< Blink mode selection*/
	DIV,		/*!< DIV clock divider*/
	PS,		/*!< PS 16-bit prescaler*/
};

static constexpr Register<FCRBitList, FCRField> FCR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	LCD_SR_GROUP		status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					StatusBit<1>{BitPos_t{0}},	// ENS
					StatusBit<1>{BitPos_t{1}},	// SOF
					Binary<BitMod::WrOnly>{BitPos_t{2}},	// UDR
					StatusBit<1>{BitPos_t{3}},	// UDD
					StatusBit<1>{BitPos_t{4}},	// RDY
					StatusBit<1>{BitPos_t{5}}	// FCRSF
					)

enum class SRField {
	ENS,		/*!< ENS*/
	SOF,		/*!< Start of frame flag*/
	UDR,		/*!< Update display request*/
	UDD,		/*!< Update Display Done*/
	RDY,		/*!< Ready flag*/
	FCRSF,		/*!< LCD Frame Control Register Synchronization flag*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	LCD_CLR_GROUP		clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CLRBitList, /**/
					Binary<>{BitPos_t{1}},	// SOFC
					Binary<>{BitPos_t{3}}	// UDDC
					)

enum class CLRField {
	SOFC,		/*!< Start of frame flag clear*/
	UDDC,		/*!< Update display done clear*/
};

static constexpr Register<CLRBitList, CLRField> CLR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	LCD_RAM_COM0_GROUP		display memory group
 *
 * @{
 */

SETUP_REGISTER_INFO(RAM_COM0BitList, /**/
					Binary<>{BitPos_t{0}},	// S00
					Binary<>{BitPos_t{1}},	// S01
					Binary<>{BitPos_t{2}},	// S02
					Binary<>{BitPos_t{3}},	// S03
					Binary<>{BitPos_t{4}},	// S04
					Binary<>{BitPos_t{5}},	// S05
					Binary<>{BitPos_t{6}},	// S06
					Binary<>{BitPos_t{7}},	// S07
					Binary<>{BitPos_t{8}},	// S08
					Binary<>{BitPos_t{9}},	// S09
					Binary<>{BitPos_t{10}},	// S10
					Binary<>{BitPos_t{11}},	// S11
					Binary<>{BitPos_t{12}},	// S12
					Binary<>{BitPos_t{13}},	// S13
					Binary<>{BitPos_t{14}},	// S14
					Binary<>{BitPos_t{15}},	// S15
					Binary<>{BitPos_t{16}},	// S16
					Binary<>{BitPos_t{17}},	// S17
					Binary<>{BitPos_t{18}},	// S18
					Binary<>{BitPos_t{19}},	// S19
					Binary<>{BitPos_t{20}},	// S20
					Binary<>{BitPos_t{21}},	// S21
					Binary<>{BitPos_t{22}},	// S22
					Binary<>{BitPos_t{23}},	// S23
					Binary<>{BitPos_t{24}},	// S24
					Binary<>{BitPos_t{25}},	// S25
					Binary<>{BitPos_t{26}},	// S26
					Binary<>{BitPos_t{27}},	// S27
					Binary<>{BitPos_t{28}},	// S28
					Binary<>{BitPos_t{29}},	// S29
					Binary<>{BitPos_t{30}}	// S30
					)

enum class RAM_COM0Field {
	S00,		/*!< S00*/
	S01,		/*!< S01*/
	S02,		/*!< S02*/
	S03,		/*!< S03*/
	S04,		/*!< S04*/
	S05,		/*!< S05*/
	S06,		/*!< S06*/
	S07,		/*!< S07*/
	S08,		/*!< S08*/
	S09,		/*!< S09*/
	S10,		/*!< S10*/
	S11,		/*!< S11*/
	S12,		/*!< S12*/
	S13,		/*!< S13*/
	S14,		/*!< S14*/
	S15,		/*!< S15*/
	S16,		/*!< S16*/
	S17,		/*!< S17*/
	S18,		/*!< S18*/
	S19,		/*!< S19*/
	S20,		/*!< S20*/
	S21,		/*!< S21*/
	S22,		/*!< S22*/
	S23,		/*!< S23*/
	S24,		/*!< S24*/
	S25,		/*!< S25*/
	S26,		/*!< S26*/
	S27,		/*!< S27*/
	S28,		/*!< S28*/
	S29,		/*!< S29*/
	S30,		/*!< S30*/
};

static constexpr Register<RAM_COM0BitList, RAM_COM0Field> RAM_COM0{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	LCD_RAM_COM1_GROUP		display memory group
 *
 * @{
 */

SETUP_REGISTER_INFO(RAM_COM1BitList, /**/
					Binary<>{BitPos_t{0}},	// S00
					Binary<>{BitPos_t{1}},	// S01
					Binary<>{BitPos_t{2}},	// S02
					Binary<>{BitPos_t{3}},	// S03
					Binary<>{BitPos_t{4}},	// S04
					Binary<>{BitPos_t{5}},	// S05
					Binary<>{BitPos_t{6}},	// S06
					Binary<>{BitPos_t{7}},	// S07
					Binary<>{BitPos_t{8}},	// S08
					Binary<>{BitPos_t{9}},	// S09
					Binary<>{BitPos_t{10}},	// S10
					Binary<>{BitPos_t{11}},	// S11
					Binary<>{BitPos_t{12}},	// S12
					Binary<>{BitPos_t{13}},	// S13
					Binary<>{BitPos_t{14}},	// S14
					Binary<>{BitPos_t{15}},	// S15
					Binary<>{BitPos_t{16}},	// S16
					Binary<>{BitPos_t{17}},	// S17
					Binary<>{BitPos_t{18}},	// S18
					Binary<>{BitPos_t{19}},	// S19
					Binary<>{BitPos_t{20}},	// S20
					Binary<>{BitPos_t{21}},	// S21
					Binary<>{BitPos_t{22}},	// S22
					Binary<>{BitPos_t{23}},	// S23
					Binary<>{BitPos_t{24}},	// S24
					Binary<>{BitPos_t{25}},	// S25
					Binary<>{BitPos_t{26}},	// S26
					Binary<>{BitPos_t{27}},	// S27
					Binary<>{BitPos_t{28}},	// S28
					Binary<>{BitPos_t{29}},	// S29
					Binary<>{BitPos_t{30}},	// S30
					Binary<>{BitPos_t{31}}	// S31
					)

enum class RAM_COM1Field {
	S00,		/*!< S00*/
	S01,		/*!< S01*/
	S02,		/*!< S02*/
	S03,		/*!< S03*/
	S04,		/*!< S04*/
	S05,		/*!< S05*/
	S06,		/*!< S06*/
	S07,		/*!< S07*/
	S08,		/*!< S08*/
	S09,		/*!< S09*/
	S10,		/*!< S10*/
	S11,		/*!< S11*/
	S12,		/*!< S12*/
	S13,		/*!< S13*/
	S14,		/*!< S14*/
	S15,		/*!< S15*/
	S16,		/*!< S16*/
	S17,		/*!< S17*/
	S18,		/*!< S18*/
	S19,		/*!< S19*/
	S20,		/*!< S20*/
	S21,		/*!< S21*/
	S22,		/*!< S22*/
	S23,		/*!< S23*/
	S24,		/*!< S24*/
	S25,		/*!< S25*/
	S26,		/*!< S26*/
	S27,		/*!< S27*/
	S28,		/*!< S28*/
	S29,		/*!< S29*/
	S30,		/*!< S30*/
	S31,		/*!< S31*/
};

static constexpr Register<RAM_COM1BitList, RAM_COM1Field> RAM_COM1{BASE_ADDR, 0x1cU};
/**@}*/

/**
 * @defgroup	LCD_RAM_COM2_GROUP		display memory group
 *
 * @{
 */

SETUP_REGISTER_INFO(RAM_COM2BitList, /**/
					Binary<>{BitPos_t{0}},	// S00
					Binary<>{BitPos_t{1}},	// S01
					Binary<>{BitPos_t{2}},	// S02
					Binary<>{BitPos_t{3}},	// S03
					Binary<>{BitPos_t{4}},	// S04
					Binary<>{BitPos_t{5}},	// S05
					Binary<>{BitPos_t{6}},	// S06
					Binary<>{BitPos_t{7}},	// S07
					Binary<>{BitPos_t{8}},	// S08
					Binary<>{BitPos_t{9}},	// S09
					Binary<>{BitPos_t{10}},	// S10
					Binary<>{BitPos_t{11}},	// S11
					Binary<>{BitPos_t{12}},	// S12
					Binary<>{BitPos_t{13}},	// S13
					Binary<>{BitPos_t{14}},	// S14
					Binary<>{BitPos_t{15}},	// S15
					Binary<>{BitPos_t{16}},	// S16
					Binary<>{BitPos_t{17}},	// S17
					Binary<>{BitPos_t{18}},	// S18
					Binary<>{BitPos_t{19}},	// S19
					Binary<>{BitPos_t{20}},	// S20
					Binary<>{BitPos_t{21}},	// S21
					Binary<>{BitPos_t{22}},	// S22
					Binary<>{BitPos_t{23}},	// S23
					Binary<>{BitPos_t{24}},	// S24
					Binary<>{BitPos_t{25}},	// S25
					Binary<>{BitPos_t{26}},	// S26
					Binary<>{BitPos_t{27}},	// S27
					Binary<>{BitPos_t{28}},	// S28
					Binary<>{BitPos_t{29}},	// S29
					Binary<>{BitPos_t{30}},	// S30
					Binary<>{BitPos_t{31}}	// S31
					)

enum class RAM_COM2Field {
	S00,		/*!< S00*/
	S01,		/*!< S01*/
	S02,		/*!< S02*/
	S03,		/*!< S03*/
	S04,		/*!< S04*/
	S05,		/*!< S05*/
	S06,		/*!< S06*/
	S07,		/*!< S07*/
	S08,		/*!< S08*/
	S09,		/*!< S09*/
	S10,		/*!< S10*/
	S11,		/*!< S11*/
	S12,		/*!< S12*/
	S13,		/*!< S13*/
	S14,		/*!< S14*/
	S15,		/*!< S15*/
	S16,		/*!< S16*/
	S17,		/*!< S17*/
	S18,		/*!< S18*/
	S19,		/*!< S19*/
	S20,		/*!< S20*/
	S21,		/*!< S21*/
	S22,		/*!< S22*/
	S23,		/*!< S23*/
	S24,		/*!< S24*/
	S25,		/*!< S25*/
	S26,		/*!< S26*/
	S27,		/*!< S27*/
	S28,		/*!< S28*/
	S29,		/*!< S29*/
	S30,		/*!< S30*/
	S31,		/*!< S31*/
};

static constexpr Register<RAM_COM2BitList, RAM_COM2Field> RAM_COM2{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	LCD_RAM_COM3_GROUP		display memory group
 *
 * @{
 */

SETUP_REGISTER_INFO(RAM_COM3BitList, /**/
					Binary<>{BitPos_t{0}},	// S00
					Binary<>{BitPos_t{1}},	// S01
					Binary<>{BitPos_t{2}},	// S02
					Binary<>{BitPos_t{3}},	// S03
					Binary<>{BitPos_t{4}},	// S04
					Binary<>{BitPos_t{5}},	// S05
					Binary<>{BitPos_t{6}},	// S06
					Binary<>{BitPos_t{7}},	// S07
					Binary<>{BitPos_t{8}},	// S08
					Binary<>{BitPos_t{9}},	// S09
					Binary<>{BitPos_t{10}},	// S10
					Binary<>{BitPos_t{11}},	// S11
					Binary<>{BitPos_t{12}},	// S12
					Binary<>{BitPos_t{13}},	// S13
					Binary<>{BitPos_t{14}},	// S14
					Binary<>{BitPos_t{15}},	// S15
					Binary<>{BitPos_t{16}},	// S16
					Binary<>{BitPos_t{17}},	// S17
					Binary<>{BitPos_t{18}},	// S18
					Binary<>{BitPos_t{19}},	// S19
					Binary<>{BitPos_t{20}},	// S20
					Binary<>{BitPos_t{21}},	// S21
					Binary<>{BitPos_t{22}},	// S22
					Binary<>{BitPos_t{23}},	// S23
					Binary<>{BitPos_t{24}},	// S24
					Binary<>{BitPos_t{25}},	// S25
					Binary<>{BitPos_t{26}},	// S26
					Binary<>{BitPos_t{27}},	// S27
					Binary<>{BitPos_t{28}},	// S28
					Binary<>{BitPos_t{29}},	// S29
					Binary<>{BitPos_t{30}},	// S30
					Binary<>{BitPos_t{31}}	// S31
					)

enum class RAM_COM3Field {
	S00,		/*!< S00*/
	S01,		/*!< S01*/
	S02,		/*!< S02*/
	S03,		/*!< S03*/
	S04,		/*!< S04*/
	S05,		/*!< S05*/
	S06,		/*!< S06*/
	S07,		/*!< S07*/
	S08,		/*!< S08*/
	S09,		/*!< S09*/
	S10,		/*!< S10*/
	S11,		/*!< S11*/
	S12,		/*!< S12*/
	S13,		/*!< S13*/
	S14,		/*!< S14*/
	S15,		/*!< S15*/
	S16,		/*!< S16*/
	S17,		/*!< S17*/
	S18,		/*!< S18*/
	S19,		/*!< S19*/
	S20,		/*!< S20*/
	S21,		/*!< S21*/
	S22,		/*!< S22*/
	S23,		/*!< S23*/
	S24,		/*!< S24*/
	S25,		/*!< S25*/
	S26,		/*!< S26*/
	S27,		/*!< S27*/
	S28,		/*!< S28*/
	S29,		/*!< S29*/
	S30,		/*!< S30*/
	S31,		/*!< S31*/
};

static constexpr Register<RAM_COM3BitList, RAM_COM3Field> RAM_COM3{BASE_ADDR, 0x2cU};
/**@}*/

/**
 * @defgroup	LCD_RAM_COM4_GROUP		display memory group
 *
 * @{
 */

SETUP_REGISTER_INFO(RAM_COM4BitList, /**/
					Binary<>{BitPos_t{0}},	// S00
					Binary<>{BitPos_t{1}},	// S01
					Binary<>{BitPos_t{2}},	// S02
					Binary<>{BitPos_t{3}},	// S03
					Binary<>{BitPos_t{4}},	// S04
					Binary<>{BitPos_t{5}},	// S05
					Binary<>{BitPos_t{6}},	// S06
					Binary<>{BitPos_t{7}},	// S07
					Binary<>{BitPos_t{8}},	// S08
					Binary<>{BitPos_t{9}},	// S09
					Binary<>{BitPos_t{10}},	// S10
					Binary<>{BitPos_t{11}},	// S11
					Binary<>{BitPos_t{12}},	// S12
					Binary<>{BitPos_t{13}},	// S13
					Binary<>{BitPos_t{14}},	// S14
					Binary<>{BitPos_t{15}},	// S15
					Binary<>{BitPos_t{16}},	// S16
					Binary<>{BitPos_t{17}},	// S17
					Binary<>{BitPos_t{18}},	// S18
					Binary<>{BitPos_t{19}},	// S19
					Binary<>{BitPos_t{20}},	// S20
					Binary<>{BitPos_t{21}},	// S21
					Binary<>{BitPos_t{22}},	// S22
					Binary<>{BitPos_t{23}},	// S23
					Binary<>{BitPos_t{24}},	// S24
					Binary<>{BitPos_t{25}},	// S25
					Binary<>{BitPos_t{26}},	// S26
					Binary<>{BitPos_t{27}},	// S27
					Binary<>{BitPos_t{28}},	// S28
					Binary<>{BitPos_t{29}},	// S29
					Binary<>{BitPos_t{30}},	// S30
					Binary<>{BitPos_t{31}}	// S31
					)

enum class RAM_COM4Field {
	S00,		/*!< S00*/
	S01,		/*!< S01*/
	S02,		/*!< S02*/
	S03,		/*!< S03*/
	S04,		/*!< S04*/
	S05,		/*!< S05*/
	S06,		/*!< S06*/
	S07,		/*!< S07*/
	S08,		/*!< S08*/
	S09,		/*!< S09*/
	S10,		/*!< S10*/
	S11,		/*!< S11*/
	S12,		/*!< S12*/
	S13,		/*!< S13*/
	S14,		/*!< S14*/
	S15,		/*!< S15*/
	S16,		/*!< S16*/
	S17,		/*!< S17*/
	S18,		/*!< S18*/
	S19,		/*!< S19*/
	S20,		/*!< S20*/
	S21,		/*!< S21*/
	S22,		/*!< S22*/
	S23,		/*!< S23*/
	S24,		/*!< S24*/
	S25,		/*!< S25*/
	S26,		/*!< S26*/
	S27,		/*!< S27*/
	S28,		/*!< S28*/
	S29,		/*!< S29*/
	S30,		/*!< S30*/
	S31,		/*!< S31*/
};

static constexpr Register<RAM_COM4BitList, RAM_COM4Field> RAM_COM4{BASE_ADDR, 0x34U};
/**@}*/

/**
 * @defgroup	LCD_RAM_COM5_GROUP		display memory group
 *
 * @{
 */

SETUP_REGISTER_INFO(RAM_COM5BitList, /**/
					Binary<>{BitPos_t{0}},	// S00
					Binary<>{BitPos_t{1}},	// S01
					Binary<>{BitPos_t{2}},	// S02
					Binary<>{BitPos_t{3}},	// S03
					Binary<>{BitPos_t{4}},	// S04
					Binary<>{BitPos_t{5}},	// S05
					Binary<>{BitPos_t{6}},	// S06
					Binary<>{BitPos_t{7}},	// S07
					Binary<>{BitPos_t{8}},	// S08
					Binary<>{BitPos_t{9}},	// S09
					Binary<>{BitPos_t{10}},	// S10
					Binary<>{BitPos_t{11}},	// S11
					Binary<>{BitPos_t{12}},	// S12
					Binary<>{BitPos_t{13}},	// S13
					Binary<>{BitPos_t{14}},	// S14
					Binary<>{BitPos_t{15}},	// S15
					Binary<>{BitPos_t{16}},	// S16
					Binary<>{BitPos_t{17}},	// S17
					Binary<>{BitPos_t{18}},	// S18
					Binary<>{BitPos_t{19}},	// S19
					Binary<>{BitPos_t{20}},	// S20
					Binary<>{BitPos_t{21}},	// S21
					Binary<>{BitPos_t{22}},	// S22
					Binary<>{BitPos_t{23}},	// S23
					Binary<>{BitPos_t{24}},	// S24
					Binary<>{BitPos_t{25}},	// S25
					Binary<>{BitPos_t{26}},	// S26
					Binary<>{BitPos_t{27}},	// S27
					Binary<>{BitPos_t{28}},	// S28
					Binary<>{BitPos_t{29}},	// S29
					Binary<>{BitPos_t{30}},	// S30
					Binary<>{BitPos_t{31}}	// S31
					)

enum class RAM_COM5Field {
	S00,		/*!< S00*/
	S01,		/*!< S01*/
	S02,		/*!< S02*/
	S03,		/*!< S03*/
	S04,		/*!< S04*/
	S05,		/*!< S05*/
	S06,		/*!< S06*/
	S07,		/*!< S07*/
	S08,		/*!< S08*/
	S09,		/*!< S09*/
	S10,		/*!< S10*/
	S11,		/*!< S11*/
	S12,		/*!< S12*/
	S13,		/*!< S13*/
	S14,		/*!< S14*/
	S15,		/*!< S15*/
	S16,		/*!< S16*/
	S17,		/*!< S17*/
	S18,		/*!< S18*/
	S19,		/*!< S19*/
	S20,		/*!< S20*/
	S21,		/*!< S21*/
	S22,		/*!< S22*/
	S23,		/*!< S23*/
	S24,		/*!< S24*/
	S25,		/*!< S25*/
	S26,		/*!< S26*/
	S27,		/*!< S27*/
	S28,		/*!< S28*/
	S29,		/*!< S29*/
	S30,		/*!< S30*/
	S31,		/*!< S31*/
};

static constexpr Register<RAM_COM5BitList, RAM_COM5Field> RAM_COM5{BASE_ADDR, 0x3cU};
/**@}*/

/**
 * @defgroup	LCD_RAM_COM6_GROUP		display memory group
 *
 * @{
 */

SETUP_REGISTER_INFO(RAM_COM6BitList, /**/
					Binary<>{BitPos_t{0}},	// S00
					Binary<>{BitPos_t{1}},	// S01
					Binary<>{BitPos_t{2}},	// S02
					Binary<>{BitPos_t{3}},	// S03
					Binary<>{BitPos_t{4}},	// S04
					Binary<>{BitPos_t{5}},	// S05
					Binary<>{BitPos_t{6}},	// S06
					Binary<>{BitPos_t{7}},	// S07
					Binary<>{BitPos_t{8}},	// S08
					Binary<>{BitPos_t{9}},	// S09
					Binary<>{BitPos_t{10}},	// S10
					Binary<>{BitPos_t{11}},	// S11
					Binary<>{BitPos_t{12}},	// S12
					Binary<>{BitPos_t{13}},	// S13
					Binary<>{BitPos_t{14}},	// S14
					Binary<>{BitPos_t{15}},	// S15
					Binary<>{BitPos_t{16}},	// S16
					Binary<>{BitPos_t{17}},	// S17
					Binary<>{BitPos_t{18}},	// S18
					Binary<>{BitPos_t{19}},	// S19
					Binary<>{BitPos_t{20}},	// S20
					Binary<>{BitPos_t{21}},	// S21
					Binary<>{BitPos_t{22}},	// S22
					Binary<>{BitPos_t{23}},	// S23
					Binary<>{BitPos_t{24}},	// S24
					Binary<>{BitPos_t{25}},	// S25
					Binary<>{BitPos_t{26}},	// S26
					Binary<>{BitPos_t{27}},	// S27
					Binary<>{BitPos_t{28}},	// S28
					Binary<>{BitPos_t{29}},	// S29
					Binary<>{BitPos_t{30}},	// S30
					Binary<>{BitPos_t{31}}	// S31
					)

enum class RAM_COM6Field {
	S00,		/*!< S00*/
	S01,		/*!< S01*/
	S02,		/*!< S02*/
	S03,		/*!< S03*/
	S04,		/*!< S04*/
	S05,		/*!< S05*/
	S06,		/*!< S06*/
	S07,		/*!< S07*/
	S08,		/*!< S08*/
	S09,		/*!< S09*/
	S10,		/*!< S10*/
	S11,		/*!< S11*/
	S12,		/*!< S12*/
	S13,		/*!< S13*/
	S14,		/*!< S14*/
	S15,		/*!< S15*/
	S16,		/*!< S16*/
	S17,		/*!< S17*/
	S18,		/*!< S18*/
	S19,		/*!< S19*/
	S20,		/*!< S20*/
	S21,		/*!< S21*/
	S22,		/*!< S22*/
	S23,		/*!< S23*/
	S24,		/*!< S24*/
	S25,		/*!< S25*/
	S26,		/*!< S26*/
	S27,		/*!< S27*/
	S28,		/*!< S28*/
	S29,		/*!< S29*/
	S30,		/*!< S30*/
	S31,		/*!< S31*/
};

static constexpr Register<RAM_COM6BitList, RAM_COM6Field> RAM_COM6{BASE_ADDR, 0x44U};
/**@}*/

/**
 * @defgroup	LCD_RAM_COM7_GROUP		display memory group
 *
 * @{
 */

SETUP_REGISTER_INFO(RAM_COM7BitList, /**/
					Binary<>{BitPos_t{0}},	// S00
					Binary<>{BitPos_t{1}},	// S01
					Binary<>{BitPos_t{2}},	// S02
					Binary<>{BitPos_t{3}},	// S03
					Binary<>{BitPos_t{4}},	// S04
					Binary<>{BitPos_t{5}},	// S05
					Binary<>{BitPos_t{6}},	// S06
					Binary<>{BitPos_t{7}},	// S07
					Binary<>{BitPos_t{8}},	// S08
					Binary<>{BitPos_t{9}},	// S09
					Binary<>{BitPos_t{10}},	// S10
					Binary<>{BitPos_t{11}},	// S11
					Binary<>{BitPos_t{12}},	// S12
					Binary<>{BitPos_t{13}},	// S13
					Binary<>{BitPos_t{14}},	// S14
					Binary<>{BitPos_t{15}},	// S15
					Binary<>{BitPos_t{16}},	// S16
					Binary<>{BitPos_t{17}},	// S17
					Binary<>{BitPos_t{18}},	// S18
					Binary<>{BitPos_t{19}},	// S19
					Binary<>{BitPos_t{20}},	// S20
					Binary<>{BitPos_t{21}},	// S21
					Binary<>{BitPos_t{22}},	// S22
					Binary<>{BitPos_t{23}},	// S23
					Binary<>{BitPos_t{24}},	// S24
					Binary<>{BitPos_t{25}},	// S25
					Binary<>{BitPos_t{26}},	// S26
					Binary<>{BitPos_t{27}},	// S27
					Binary<>{BitPos_t{28}},	// S28
					Binary<>{BitPos_t{29}},	// S29
					Binary<>{BitPos_t{30}},	// S30
					Binary<>{BitPos_t{31}}	// S31
					)

enum class RAM_COM7Field {
	S00,		/*!< S00*/
	S01,		/*!< S01*/
	S02,		/*!< S02*/
	S03,		/*!< S03*/
	S04,		/*!< S04*/
	S05,		/*!< S05*/
	S06,		/*!< S06*/
	S07,		/*!< S07*/
	S08,		/*!< S08*/
	S09,		/*!< S09*/
	S10,		/*!< S10*/
	S11,		/*!< S11*/
	S12,		/*!< S12*/
	S13,		/*!< S13*/
	S14,		/*!< S14*/
	S15,		/*!< S15*/
	S16,		/*!< S16*/
	S17,		/*!< S17*/
	S18,		/*!< S18*/
	S19,		/*!< S19*/
	S20,		/*!< S20*/
	S21,		/*!< S21*/
	S22,		/*!< S22*/
	S23,		/*!< S23*/
	S24,		/*!< S24*/
	S25,		/*!< S25*/
	S26,		/*!< S26*/
	S27,		/*!< S27*/
	S28,		/*!< S28*/
	S29,		/*!< S29*/
	S30,		/*!< S30*/
	S31,		/*!< S31*/
};

static constexpr Register<RAM_COM7BitList, RAM_COM7Field> RAM_COM7{BASE_ADDR, 0x4cU};
/**@}*/


} // cpp_stm32::lcd::reg
