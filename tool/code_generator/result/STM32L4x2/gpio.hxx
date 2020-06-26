#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::gpio::reg {

static constexpr auto BASE_ADDR(Port const& t_gpio) {
	switch(t_gpio) {
	case Port::GPIOA:
		return 0x48000000U;
	case Port::GPIOB:
		return 0x48000400U;
	case Port::GPIOC:
		return 0x48000800U;
	case Port::GPIOD:
		return 0x48000c00U;
	case Port::GPIOE:
		return 0x48001000U;
	case Port::GPIOH:
		return 0x48001c00U;
}
	}

/**
 * @defgroup	GPIOH_MODER_GROUP		GPIO port mode register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MODERBitList, /**/
					Bit<2>{BitPos_t{30}},	// MODER15
					Bit<2>{BitPos_t{28}},	// MODER14
					Bit<2>{BitPos_t{26}},	// MODER13
					Bit<2>{BitPos_t{24}},	// MODER12
					Bit<2>{BitPos_t{22}},	// MODER11
					Bit<2>{BitPos_t{20}},	// MODER10
					Bit<2>{BitPos_t{18}},	// MODER9
					Bit<2>{BitPos_t{16}},	// MODER8
					Bit<2>{BitPos_t{14}},	// MODER7
					Bit<2>{BitPos_t{12}},	// MODER6
					Bit<2>{BitPos_t{10}},	// MODER5
					Bit<2>{BitPos_t{8}},	// MODER4
					Bit<2>{BitPos_t{6}},	// MODER3
					Bit<2>{BitPos_t{4}},	// MODER2
					Bit<2>{BitPos_t{2}},	// MODER1
					Bit<2>{BitPos_t{0}}	// MODER0
					)

template <Port GPIO>
static constexpr Register<MODERBitList, Pin> MODER{BASE_ADDR(GPIO), 0x00U};
/**@}*/

/**
 * @defgroup	GPIOH_OTYPER_GROUP		GPIO port output type register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OTYPERBitList, /**/
					Binary<>{BitPos_t{15}},	// OT15
					Binary<>{BitPos_t{14}},	// OT14
					Binary<>{BitPos_t{13}},	// OT13
					Binary<>{BitPos_t{12}},	// OT12
					Binary<>{BitPos_t{11}},	// OT11
					Binary<>{BitPos_t{10}},	// OT10
					Binary<>{BitPos_t{9}},	// OT9
					Binary<>{BitPos_t{8}},	// OT8
					Binary<>{BitPos_t{7}},	// OT7
					Binary<>{BitPos_t{6}},	// OT6
					Binary<>{BitPos_t{5}},	// OT5
					Binary<>{BitPos_t{4}},	// OT4
					Binary<>{BitPos_t{3}},	// OT3
					Binary<>{BitPos_t{2}},	// OT2
					Binary<>{BitPos_t{1}},	// OT1
					Binary<>{BitPos_t{0}}	// OT0
					)

template <Port GPIO>
static constexpr Register<OTYPERBitList, Pin> OTYPER{BASE_ADDR(GPIO), 0x04U};
/**@}*/

/**
 * @defgroup	GPIOH_OSPEEDR_GROUP		GPIO port output speed register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OSPEEDRBitList, /**/
					Bit<2>{BitPos_t{30}},	// OSPEEDR15
					Bit<2>{BitPos_t{28}},	// OSPEEDR14
					Bit<2>{BitPos_t{26}},	// OSPEEDR13
					Bit<2>{BitPos_t{24}},	// OSPEEDR12
					Bit<2>{BitPos_t{22}},	// OSPEEDR11
					Bit<2>{BitPos_t{20}},	// OSPEEDR10
					Bit<2>{BitPos_t{18}},	// OSPEEDR9
					Bit<2>{BitPos_t{16}},	// OSPEEDR8
					Bit<2>{BitPos_t{14}},	// OSPEEDR7
					Bit<2>{BitPos_t{12}},	// OSPEEDR6
					Bit<2>{BitPos_t{10}},	// OSPEEDR5
					Bit<2>{BitPos_t{8}},	// OSPEEDR4
					Bit<2>{BitPos_t{6}},	// OSPEEDR3
					Bit<2>{BitPos_t{4}},	// OSPEEDR2
					Bit<2>{BitPos_t{2}},	// OSPEEDR1
					Bit<2>{BitPos_t{0}}	// OSPEEDR0
					)

template <Port GPIO>
static constexpr Register<OSPEEDRBitList, Pin> OSPEEDR{BASE_ADDR(GPIO), 0x08U};
/**@}*/

/**
 * @defgroup	GPIOH_PUPDR_GROUP		GPIO port pull-up/pull-down register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PUPDRBitList, /**/
					Bit<2>{BitPos_t{30}},	// PUPDR15
					Bit<2>{BitPos_t{28}},	// PUPDR14
					Bit<2>{BitPos_t{26}},	// PUPDR13
					Bit<2>{BitPos_t{24}},	// PUPDR12
					Bit<2>{BitPos_t{22}},	// PUPDR11
					Bit<2>{BitPos_t{20}},	// PUPDR10
					Bit<2>{BitPos_t{18}},	// PUPDR9
					Bit<2>{BitPos_t{16}},	// PUPDR8
					Bit<2>{BitPos_t{14}},	// PUPDR7
					Bit<2>{BitPos_t{12}},	// PUPDR6
					Bit<2>{BitPos_t{10}},	// PUPDR5
					Bit<2>{BitPos_t{8}},	// PUPDR4
					Bit<2>{BitPos_t{6}},	// PUPDR3
					Bit<2>{BitPos_t{4}},	// PUPDR2
					Bit<2>{BitPos_t{2}},	// PUPDR1
					Bit<2>{BitPos_t{0}}	// PUPDR0
					)

template <Port GPIO>
static constexpr Register<PUPDRBitList, Pin> PUPDR{BASE_ADDR(GPIO), 0x0cU};
/**@}*/

/**
 * @defgroup	GPIOH_IDR_GROUP		GPIO port input data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IDRBitList, /**/
					Binary<>{BitPos_t{15}},	// IDR15
					Binary<>{BitPos_t{14}},	// IDR14
					Binary<>{BitPos_t{13}},	// IDR13
					Binary<>{BitPos_t{12}},	// IDR12
					Binary<>{BitPos_t{11}},	// IDR11
					Binary<>{BitPos_t{10}},	// IDR10
					Binary<>{BitPos_t{9}},	// IDR9
					Binary<>{BitPos_t{8}},	// IDR8
					Binary<>{BitPos_t{7}},	// IDR7
					Binary<>{BitPos_t{6}},	// IDR6
					Binary<>{BitPos_t{5}},	// IDR5
					Binary<>{BitPos_t{4}},	// IDR4
					Binary<>{BitPos_t{3}},	// IDR3
					Binary<>{BitPos_t{2}},	// IDR2
					Binary<>{BitPos_t{1}},	// IDR1
					Binary<>{BitPos_t{0}}	// IDR0
					)

template <Port GPIO>
static constexpr Register<IDRBitList, Pin> IDR{BASE_ADDR(GPIO), 0x10U};
/**@}*/

/**
 * @defgroup	GPIOH_ODR_GROUP		GPIO port output data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ODRBitList, /**/
					Binary<>{BitPos_t{15}},	// ODR15
					Binary<>{BitPos_t{14}},	// ODR14
					Binary<>{BitPos_t{13}},	// ODR13
					Binary<>{BitPos_t{12}},	// ODR12
					Binary<>{BitPos_t{11}},	// ODR11
					Binary<>{BitPos_t{10}},	// ODR10
					Binary<>{BitPos_t{9}},	// ODR9
					Binary<>{BitPos_t{8}},	// ODR8
					Binary<>{BitPos_t{7}},	// ODR7
					Binary<>{BitPos_t{6}},	// ODR6
					Binary<>{BitPos_t{5}},	// ODR5
					Binary<>{BitPos_t{4}},	// ODR4
					Binary<>{BitPos_t{3}},	// ODR3
					Binary<>{BitPos_t{2}},	// ODR2
					Binary<>{BitPos_t{1}},	// ODR1
					Binary<>{BitPos_t{0}}	// ODR0
					)

template <Port GPIO>
static constexpr Register<ODRBitList, Pin> ODR{BASE_ADDR(GPIO), 0x14U};
/**@}*/

/**
 * @defgroup	GPIOH_BSRR_GROUP		GPIO port bit set/reset register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BSRRBitList, /**/
					Binary<>{BitPos_t{31}},	// BR15
					Binary<>{BitPos_t{30}},	// BR14
					Binary<>{BitPos_t{29}},	// BR13
					Binary<>{BitPos_t{28}},	// BR12
					Binary<>{BitPos_t{27}},	// BR11
					Binary<>{BitPos_t{26}},	// BR10
					Binary<>{BitPos_t{25}},	// BR9
					Binary<>{BitPos_t{24}},	// BR8
					Binary<>{BitPos_t{23}},	// BR7
					Binary<>{BitPos_t{22}},	// BR6
					Binary<>{BitPos_t{21}},	// BR5
					Binary<>{BitPos_t{20}},	// BR4
					Binary<>{BitPos_t{19}},	// BR3
					Binary<>{BitPos_t{18}},	// BR2
					Binary<>{BitPos_t{17}},	// BR1
					Binary<>{BitPos_t{16}},	// BR0
					Binary<>{BitPos_t{15}},	// BS15
					Binary<>{BitPos_t{14}},	// BS14
					Binary<>{BitPos_t{13}},	// BS13
					Binary<>{BitPos_t{12}},	// BS12
					Binary<>{BitPos_t{11}},	// BS11
					Binary<>{BitPos_t{10}},	// BS10
					Binary<>{BitPos_t{9}},	// BS9
					Binary<>{BitPos_t{8}},	// BS8
					Binary<>{BitPos_t{7}},	// BS7
					Binary<>{BitPos_t{6}},	// BS6
					Binary<>{BitPos_t{5}},	// BS5
					Binary<>{BitPos_t{4}},	// BS4
					Binary<>{BitPos_t{3}},	// BS3
					Binary<>{BitPos_t{2}},	// BS2
					Binary<>{BitPos_t{1}},	// BS1
					Binary<>{BitPos_t{0}}	// BS0
					)

template <Port GPIO>
static constexpr Register<BSRRBitList, Pin> BSRR{BASE_ADDR(GPIO), 0x18U};
/**@}*/

/**
 * @defgroup	GPIOH_LCKR_GROUP		GPIO port configuration lock register group
 *
 * @{
 */

SETUP_REGISTER_INFO(LCKRBitList, /**/
					Binary<>{BitPos_t{16}},	// LCKK
					Binary<>{BitPos_t{15}},	// LCK15
					Binary<>{BitPos_t{14}},	// LCK14
					Binary<>{BitPos_t{13}},	// LCK13
					Binary<>{BitPos_t{12}},	// LCK12
					Binary<>{BitPos_t{11}},	// LCK11
					Binary<>{BitPos_t{10}},	// LCK10
					Binary<>{BitPos_t{9}},	// LCK9
					Binary<>{BitPos_t{8}},	// LCK8
					Binary<>{BitPos_t{7}},	// LCK7
					Binary<>{BitPos_t{6}},	// LCK6
					Binary<>{BitPos_t{5}},	// LCK5
					Binary<>{BitPos_t{4}},	// LCK4
					Binary<>{BitPos_t{3}},	// LCK3
					Binary<>{BitPos_t{2}},	// LCK2
					Binary<>{BitPos_t{1}},	// LCK1
					Binary<>{BitPos_t{0}}	// LCK0
					)

template <Port GPIO>
static constexpr Register<LCKRBitList, Pin> LCKR{BASE_ADDR(GPIO), 0x1cU};
/**@}*/

/**
 * @defgroup	GPIOH_AFRL_GROUP		GPIO alternate function low register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AFRLBitList, /**/
					Bit<4>{BitPos_t{28}},	// AFRL7
					Bit<4>{BitPos_t{24}},	// AFRL6
					Bit<4>{BitPos_t{20}},	// AFRL5
					Bit<4>{BitPos_t{16}},	// AFRL4
					Bit<4>{BitPos_t{12}},	// AFRL3
					Bit<4>{BitPos_t{8}},	// AFRL2
					Bit<4>{BitPos_t{4}},	// AFRL1
					Bit<4>{BitPos_t{0}}	// AFRL0
					)

template <Port GPIO>
static constexpr Register<AFRLBitList, Pin> AFRL{BASE_ADDR(GPIO), 0x20U};
/**@}*/

/**
 * @defgroup	GPIOH_AFRH_GROUP		GPIO alternate function high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AFRHBitList, /**/
					Bit<4>{BitPos_t{28}},	// AFRH15
					Bit<4>{BitPos_t{24}},	// AFRH14
					Bit<4>{BitPos_t{20}},	// AFRH13
					Bit<4>{BitPos_t{16}},	// AFRH12
					Bit<4>{BitPos_t{12}},	// AFRH11
					Bit<4>{BitPos_t{8}},	// AFRH10
					Bit<4>{BitPos_t{4}},	// AFRH9
					Bit<4>{BitPos_t{0}}	// AFRH8
					)

template <Port GPIO>
static constexpr Register<AFRHBitList, Pin> AFRH{BASE_ADDR(GPIO), 0x24U};
/**@}*/


} // cpp_stm32::gpio::reg
