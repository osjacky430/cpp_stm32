#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::nvic::reg {

static constexpr auto BASE_ADDR = 0xe000e000U;

/**
 * @defgroup	NVIC_ICTR_GROUP		Interrupt Controller Type Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICTRBitList, /**/
					Bit<4>{BitPos_t{0}}	// INTLINESNUM
					)

enum class ICTRField {
	INTLINESNUM,		/*!< Total number of interrupt lines in groups*/
};

static constexpr Register<ICTRBitList, ICTRField> ICTR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	NVIC_STIR_GROUP		Software Triggered Interrupt Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(STIRBitList, /**/
					Bit<9, std::uint16_t>{BitPos_t{0}}	// INTID
					)

enum class STIRField {
	INTID,		/*!< interrupt to be triggered*/
};

static constexpr Register<STIRBitList, STIRField> STIR{BASE_ADDR, 0xf00U};
/**@}*/

/**
 * @defgroup	NVIC_ISER0_GROUP		Interrupt Set-Enable Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISER0BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// SETENA
					)

enum class ISER0Field {
	SETENA,		/*!< SETENA*/
};

static constexpr Register<ISER0BitList, ISER0Field> ISER0{BASE_ADDR, 0x100U};
/**@}*/

/**
 * @defgroup	NVIC_ISER1_GROUP		Interrupt Set-Enable Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISER1BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// SETENA
					)

enum class ISER1Field {
	SETENA,		/*!< SETENA*/
};

static constexpr Register<ISER1BitList, ISER1Field> ISER1{BASE_ADDR, 0x104U};
/**@}*/

/**
 * @defgroup	NVIC_ISER2_GROUP		Interrupt Set-Enable Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISER2BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// SETENA
					)

enum class ISER2Field {
	SETENA,		/*!< SETENA*/
};

static constexpr Register<ISER2BitList, ISER2Field> ISER2{BASE_ADDR, 0x108U};
/**@}*/

/**
 * @defgroup	NVIC_ICER0_GROUP		Interrupt Clear-Enable Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICER0BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CLRENA
					)

enum class ICER0Field {
	CLRENA,		/*!< CLRENA*/
};

static constexpr Register<ICER0BitList, ICER0Field> ICER0{BASE_ADDR, 0x180U};
/**@}*/

/**
 * @defgroup	NVIC_ICER1_GROUP		Interrupt Clear-Enable Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICER1BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CLRENA
					)

enum class ICER1Field {
	CLRENA,		/*!< CLRENA*/
};

static constexpr Register<ICER1BitList, ICER1Field> ICER1{BASE_ADDR, 0x184U};
/**@}*/

/**
 * @defgroup	NVIC_ICER2_GROUP		Interrupt Clear-Enable Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICER2BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CLRENA
					)

enum class ICER2Field {
	CLRENA,		/*!< CLRENA*/
};

static constexpr Register<ICER2BitList, ICER2Field> ICER2{BASE_ADDR, 0x188U};
/**@}*/

/**
 * @defgroup	NVIC_ISPR0_GROUP		Interrupt Set-Pending Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISPR0BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// SETPEND
					)

enum class ISPR0Field {
	SETPEND,		/*!< SETPEND*/
};

static constexpr Register<ISPR0BitList, ISPR0Field> ISPR0{BASE_ADDR, 0x200U};
/**@}*/

/**
 * @defgroup	NVIC_ISPR1_GROUP		Interrupt Set-Pending Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISPR1BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// SETPEND
					)

enum class ISPR1Field {
	SETPEND,		/*!< SETPEND*/
};

static constexpr Register<ISPR1BitList, ISPR1Field> ISPR1{BASE_ADDR, 0x204U};
/**@}*/

/**
 * @defgroup	NVIC_ISPR2_GROUP		Interrupt Set-Pending Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISPR2BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// SETPEND
					)

enum class ISPR2Field {
	SETPEND,		/*!< SETPEND*/
};

static constexpr Register<ISPR2BitList, ISPR2Field> ISPR2{BASE_ADDR, 0x208U};
/**@}*/

/**
 * @defgroup	NVIC_ICPR0_GROUP		Interrupt Clear-Pending Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICPR0BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CLRPEND
					)

enum class ICPR0Field {
	CLRPEND,		/*!< CLRPEND*/
};

static constexpr Register<ICPR0BitList, ICPR0Field> ICPR0{BASE_ADDR, 0x280U};
/**@}*/

/**
 * @defgroup	NVIC_ICPR1_GROUP		Interrupt Clear-Pending Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICPR1BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CLRPEND
					)

enum class ICPR1Field {
	CLRPEND,		/*!< CLRPEND*/
};

static constexpr Register<ICPR1BitList, ICPR1Field> ICPR1{BASE_ADDR, 0x284U};
/**@}*/

/**
 * @defgroup	NVIC_ICPR2_GROUP		Interrupt Clear-Pending Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICPR2BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// CLRPEND
					)

enum class ICPR2Field {
	CLRPEND,		/*!< CLRPEND*/
};

static constexpr Register<ICPR2BitList, ICPR2Field> ICPR2{BASE_ADDR, 0x288U};
/**@}*/

/**
 * @defgroup	NVIC_IABR0_GROUP		Interrupt Active Bit Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IABR0BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// ACTIVE
					)

enum class IABR0Field {
	ACTIVE,		/*!< ACTIVE*/
};

static constexpr Register<IABR0BitList, IABR0Field> IABR0{BASE_ADDR, 0x300U};
/**@}*/

/**
 * @defgroup	NVIC_IABR1_GROUP		Interrupt Active Bit Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IABR1BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// ACTIVE
					)

enum class IABR1Field {
	ACTIVE,		/*!< ACTIVE*/
};

static constexpr Register<IABR1BitList, IABR1Field> IABR1{BASE_ADDR, 0x304U};
/**@}*/

/**
 * @defgroup	NVIC_IABR2_GROUP		Interrupt Active Bit Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IABR2BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// ACTIVE
					)

enum class IABR2Field {
	ACTIVE,		/*!< ACTIVE*/
};

static constexpr Register<IABR2BitList, IABR2Field> IABR2{BASE_ADDR, 0x308U};
/**@}*/

/**
 * @defgroup	NVIC_IPR0_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR0BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR0Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR0BitList, IPR0Field> IPR0{BASE_ADDR, 0x400U};
/**@}*/

/**
 * @defgroup	NVIC_IPR1_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR1BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR1Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR1BitList, IPR1Field> IPR1{BASE_ADDR, 0x404U};
/**@}*/

/**
 * @defgroup	NVIC_IPR2_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR2BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR2Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR2BitList, IPR2Field> IPR2{BASE_ADDR, 0x408U};
/**@}*/

/**
 * @defgroup	NVIC_IPR3_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR3BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR3Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR3BitList, IPR3Field> IPR3{BASE_ADDR, 0x40cU};
/**@}*/

/**
 * @defgroup	NVIC_IPR4_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR4BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR4Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR4BitList, IPR4Field> IPR4{BASE_ADDR, 0x410U};
/**@}*/

/**
 * @defgroup	NVIC_IPR5_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR5BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR5Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR5BitList, IPR5Field> IPR5{BASE_ADDR, 0x414U};
/**@}*/

/**
 * @defgroup	NVIC_IPR6_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR6BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR6Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR6BitList, IPR6Field> IPR6{BASE_ADDR, 0x418U};
/**@}*/

/**
 * @defgroup	NVIC_IPR7_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR7BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR7Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR7BitList, IPR7Field> IPR7{BASE_ADDR, 0x41cU};
/**@}*/

/**
 * @defgroup	NVIC_IPR8_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR8BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR8Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR8BitList, IPR8Field> IPR8{BASE_ADDR, 0x420U};
/**@}*/

/**
 * @defgroup	NVIC_IPR9_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR9BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR9Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR9BitList, IPR9Field> IPR9{BASE_ADDR, 0x424U};
/**@}*/

/**
 * @defgroup	NVIC_IPR10_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR10BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR10Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR10BitList, IPR10Field> IPR10{BASE_ADDR, 0x428U};
/**@}*/

/**
 * @defgroup	NVIC_IPR11_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR11BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR11Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR11BitList, IPR11Field> IPR11{BASE_ADDR, 0x42cU};
/**@}*/

/**
 * @defgroup	NVIC_IPR12_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR12BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR12Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR12BitList, IPR12Field> IPR12{BASE_ADDR, 0x430U};
/**@}*/

/**
 * @defgroup	NVIC_IPR13_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR13BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR13Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR13BitList, IPR13Field> IPR13{BASE_ADDR, 0x434U};
/**@}*/

/**
 * @defgroup	NVIC_IPR14_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR14BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR14Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR14BitList, IPR14Field> IPR14{BASE_ADDR, 0x438U};
/**@}*/

/**
 * @defgroup	NVIC_IPR15_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR15BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR15Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR15BitList, IPR15Field> IPR15{BASE_ADDR, 0x43cU};
/**@}*/

/**
 * @defgroup	NVIC_IPR16_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR16BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR16Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR16BitList, IPR16Field> IPR16{BASE_ADDR, 0x440U};
/**@}*/

/**
 * @defgroup	NVIC_IPR17_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR17BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR17Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR17BitList, IPR17Field> IPR17{BASE_ADDR, 0x444U};
/**@}*/

/**
 * @defgroup	NVIC_IPR18_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR18BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR18Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR18BitList, IPR18Field> IPR18{BASE_ADDR, 0x448U};
/**@}*/

/**
 * @defgroup	NVIC_IPR19_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR19BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR19Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR19BitList, IPR19Field> IPR19{BASE_ADDR, 0x44cU};
/**@}*/

/**
 * @defgroup	NVIC_IPR20_GROUP		Interrupt Priority Register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IPR20BitList, /**/
					Bit<8>{BitPos_t{24}},	// IPR_N3
					Bit<8>{BitPos_t{16}},	// IPR_N2
					Bit<8>{BitPos_t{8}},	// IPR_N1
					Bit<8>{BitPos_t{0}}	// IPR_N0
					)

enum class IPR20Field {
	IPR_N3,		/*!< IPR_N3*/
	IPR_N2,		/*!< IPR_N2*/
	IPR_N1,		/*!< IPR_N1*/
	IPR_N0,		/*!< IPR_N0*/
};

static constexpr Register<IPR20BitList, IPR20Field> IPR20{BASE_ADDR, 0x450U};
/**@}*/


} // cpp_stm32::nvic::reg
