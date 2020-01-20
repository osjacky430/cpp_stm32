#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::gpio::reg {

static constexpr auto BASE_ADDR(Port const& t_gpio) {
	case Port::GPIOH:
		return 0x40021c00U;
	case Port::GPIOG:
		return 0x40021800U;
	case Port::GPIOF:
		return 0x40021400U;
	case Port::GPIOE:
		return 0x40021000U;
	case Port::GPIOD:
		return 0x40020c00U;
	case Port::GPIOC:
		return 0x40020800U;
	case Port::GPIOB:
		return 0x40020400U;
	case Port::GPIOA:
		return 0x40020000U;
}

/**
 * @defgroup	GPIOA_MODER_GROUP		GPIO port mode register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MODERBitList, /**/
					Binary<>{BitPos_t{29}},	// SPDIFSEL
					Binary<>{BitPos_t{28}},	// SDIOSEL
					Binary<>{BitPos_t{27}},	// CK48MSEL
					Binary<>{BitPos_t{26}},	// CECSEL
					Bit<2>{BitPos_t{22}}	// FMPI2C1SEL
					)

template <Port GPIO>
static constexpr Register<MODERBitList, Pin> MODER{BASE_ADDR(GPIO), 0x00U};
/**@}*/

/**
 * @defgroup	GPIOA_OTYPER_GROUP		GPIO port output type register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OTYPERBitList, /**/
					Binary<>{BitPos_t{29}},	// SPDIFSEL
					Binary<>{BitPos_t{28}},	// SDIOSEL
					Binary<>{BitPos_t{27}},	// CK48MSEL
					Binary<>{BitPos_t{26}},	// CECSEL
					Bit<2>{BitPos_t{22}}	// FMPI2C1SEL
					)

template <Port GPIO>
static constexpr Register<OTYPERBitList, Pin> OTYPER{BASE_ADDR(GPIO), 0x04U};
/**@}*/

/**
 * @defgroup	GPIOA_OSPEEDR_GROUP		GPIO port output speed register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OSPEEDRBitList, /**/
					Binary<>{BitPos_t{29}},	// SPDIFSEL
					Binary<>{BitPos_t{28}},	// SDIOSEL
					Binary<>{BitPos_t{27}},	// CK48MSEL
					Binary<>{BitPos_t{26}},	// CECSEL
					Bit<2>{BitPos_t{22}}	// FMPI2C1SEL
					)

template <Port GPIO>
static constexpr Register<OSPEEDRBitList, Pin> OSPEEDR{BASE_ADDR(GPIO), 0x08U};
/**@}*/

/**
 * @defgroup	GPIOA_PUPDR_GROUP		GPIO port pull-up/pull-down register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PUPDRBitList, /**/
					Binary<>{BitPos_t{29}},	// SPDIFSEL
					Binary<>{BitPos_t{28}},	// SDIOSEL
					Binary<>{BitPos_t{27}},	// CK48MSEL
					Binary<>{BitPos_t{26}},	// CECSEL
					Bit<2>{BitPos_t{22}}	// FMPI2C1SEL
					)

template <Port GPIO>
static constexpr Register<PUPDRBitList, Pin> PUPDR{BASE_ADDR(GPIO), 0x0cU};
/**@}*/

/**
 * @defgroup	GPIOA_IDR_GROUP		GPIO port input data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IDRBitList, /**/
					Binary<>{BitPos_t{29}},	// SPDIFSEL
					Binary<>{BitPos_t{28}},	// SDIOSEL
					Binary<>{BitPos_t{27}},	// CK48MSEL
					Binary<>{BitPos_t{26}},	// CECSEL
					Bit<2>{BitPos_t{22}}	// FMPI2C1SEL
					)

template <Port GPIO>
static constexpr Register<IDRBitList, Pin> IDR{BASE_ADDR(GPIO), 0x10U};
/**@}*/

/**
 * @defgroup	GPIOA_ODR_GROUP		GPIO port output data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ODRBitList, /**/
					Binary<>{BitPos_t{29}},	// SPDIFSEL
					Binary<>{BitPos_t{28}},	// SDIOSEL
					Binary<>{BitPos_t{27}},	// CK48MSEL
					Binary<>{BitPos_t{26}},	// CECSEL
					Bit<2>{BitPos_t{22}}	// FMPI2C1SEL
					)

template <Port GPIO>
static constexpr Register<ODRBitList, Pin> ODR{BASE_ADDR(GPIO), 0x14U};
/**@}*/

/**
 * @defgroup	GPIOA_BSRR_GROUP		GPIO port bit set/reset register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BSRRBitList, /**/
					Binary<>{BitPos_t{29}},	// SPDIFSEL
					Binary<>{BitPos_t{28}},	// SDIOSEL
					Binary<>{BitPos_t{27}},	// CK48MSEL
					Binary<>{BitPos_t{26}},	// CECSEL
					Bit<2>{BitPos_t{22}}	// FMPI2C1SEL
					)

template <Port GPIO>
static constexpr Register<BSRRBitList, Pin> BSRR{BASE_ADDR(GPIO), 0x18U};
/**@}*/

/**
 * @defgroup	GPIOA_LCKR_GROUP		GPIO port configuration lock register group
 *
 * @{
 */

SETUP_REGISTER_INFO(LCKRBitList, /**/
					Binary<>{BitPos_t{29}},	// SPDIFSEL
					Binary<>{BitPos_t{28}},	// SDIOSEL
					Binary<>{BitPos_t{27}},	// CK48MSEL
					Binary<>{BitPos_t{26}},	// CECSEL
					Bit<2>{BitPos_t{22}}	// FMPI2C1SEL
					)

template <Port GPIO>
static constexpr Register<LCKRBitList, Pin> LCKR{BASE_ADDR(GPIO), 0x1cU};
/**@}*/

/**
 * @defgroup	GPIOA_AFRL_GROUP		GPIO alternate function low register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AFRLBitList, /**/
					Binary<>{BitPos_t{29}},	// SPDIFSEL
					Binary<>{BitPos_t{28}},	// SDIOSEL
					Binary<>{BitPos_t{27}},	// CK48MSEL
					Binary<>{BitPos_t{26}},	// CECSEL
					Bit<2>{BitPos_t{22}}	// FMPI2C1SEL
					)

template <Port GPIO>
static constexpr Register<AFRLBitList, Pin> AFRL{BASE_ADDR(GPIO), 0x20U};
/**@}*/

/**
 * @defgroup	GPIOA_AFRH_GROUP		GPIO alternate function high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AFRHBitList, /**/
					Binary<>{BitPos_t{29}},	// SPDIFSEL
					Binary<>{BitPos_t{28}},	// SDIOSEL
					Binary<>{BitPos_t{27}},	// CK48MSEL
					Binary<>{BitPos_t{26}},	// CECSEL
					Bit<2>{BitPos_t{22}}	// FMPI2C1SEL
					)

template <Port GPIO>
static constexpr Register<AFRHBitList, Pin> AFRH{BASE_ADDR(GPIO), 0x24U};
/**@}*/


} // cpp_stm32::gpio::reg
