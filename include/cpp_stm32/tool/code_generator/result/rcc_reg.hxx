#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::rcc::reg {

static constexpr auto BASE_ADDR = 0x40023800U;

/**
 * @defgroup	RCC_CR_GROUP		clock control register group
 *
 * @{
 */

enum class CRField {
	HSION,		/*!< Internal high-speed clock enable*/
	HSIRDY,		/*!< Internal high-speed clock ready flag*/
	HSITRIM,		/*!< Internal high-speed clock trimming*/
	HSICAL,		/*!< Internal high-speed clock calibration*/
	HSEON,		/*!< HSE clock enable*/
	HSERDY,		/*!< HSE clock ready flag*/
	HSEBYP,		/*!< HSE clock bypass*/
	CSSON,		/*!< Clock security system enable*/
	PLLON,		/*!< Main PLL (PLL) enable*/
	PLLRDY,		/*!< Main PLL (PLL) clock ready flag*/
	PLLI2SON,		/*!< PLLI2S enable*/
	PLLI2SRDY,		/*!< PLLI2S clock ready flag*/
};

static constexpr Register<, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	RCC_PLLCFGR_GROUP		PLL configuration register group
 *
 * @{
 */

enum class PLLCFGRField {
	PLLM,		/*!< Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock*/
	PLLN,		/*!< Main PLL (PLL) multiplication factor for VCO*/
	PLLP,		/*!< Main PLL (PLL) division factor for main system clock*/
	PLLSRC,		/*!< Main PLL(PLL) and audio PLL (PLLI2S) entry clock source*/
	PLLQ,		/*!< Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks*/
};

static constexpr Register<, PLLCFGRField> PLLCFGR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	RCC_CFGR_GROUP		clock configuration register group
 *
 * @{
 */

enum class CFGRField {
	SW,		/*!< System clock switch*/
	SWS,		/*!< System clock switch status*/
	HPRE,		/*!< AHB prescaler*/
	PPRE1,		/*!< APB Low speed prescaler (APB1)*/
	PPRE2,		/*!< APB high-speed prescaler (APB2)*/
	RTCPRE,		/*!< HSE division factor for RTC clock*/
	MCO1,		/*!< Microcontroller clock output 1*/
	I2SSRC,		/*!< I2S clock selection*/
	MCO1PRE,		/*!< MCO1 prescaler*/
	MCO2PRE,		/*!< MCO2 prescaler*/
	MCO2,		/*!< Microcontroller clock output 2*/
};

static constexpr Register<, CFGRField> CFGR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	RCC_CIR_GROUP		clock interrupt register group
 *
 * @{
 */

enum class CIRField {
	LSIRDYF,		/*!< LSI ready interrupt flag*/
	LSERDYF,		/*!< LSE ready interrupt flag*/
	HSIRDYF,		/*!< HSI ready interrupt flag*/
	HSERDYF,		/*!< HSE ready interrupt flag*/
	PLLRDYF,		/*!< Main PLL (PLL) ready interrupt flag*/
	PLLI2SRDYF,		/*!< PLLI2S ready interrupt flag*/
	PLLSAIRDYF,		/*!< PLLSAI ready interrupt flag*/
	CSSF,		/*!< Clock security system interrupt flag*/
	LSIRDYIE,		/*!< LSI ready interrupt enable*/
	LSERDYIE,		/*!< LSE ready interrupt enable*/
	HSIRDYIE,		/*!< HSI ready interrupt enable*/
	HSERDYIE,		/*!< HSE ready interrupt enable*/
	PLLRDYIE,		/*!< Main PLL (PLL) ready interrupt enable*/
	PLLI2SRDYIE,		/*!< PLLI2S ready interrupt enable*/
	PLLSAIRDYIE,		/*!< PLLSAI Ready Interrupt Enable*/
	LSIRDYC,		/*!< LSI ready interrupt clear*/
	LSERDYC,		/*!< LSE ready interrupt clear*/
	HSIRDYC,		/*!< HSI ready interrupt clear*/
	HSERDYC,		/*!< HSE ready interrupt clear*/
	PLLRDYC,		/*!< Main PLL(PLL) ready interrupt clear*/
	PLLI2SRDYC,		/*!< PLLI2S ready interrupt clear*/
	PLLSAIRDYC,		/*!< PLLSAI Ready Interrupt Clear*/
	CSSC,		/*!< Clock security system interrupt clear*/
};

static constexpr Register<, CIRField> CIR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	RCC_AHB1RSTR_GROUP		AHB1 peripheral reset register group
 *
 * @{
 */

enum class AHB1RSTRField {
	GPIOARST,		/*!< IO port A reset*/
	GPIOBRST,		/*!< IO port B reset*/
	GPIOCRST,		/*!< IO port C reset*/
	GPIODRST,		/*!< IO port D reset*/
	GPIOERST,		/*!< IO port E reset*/
	GPIOFRST,		/*!< IO port F reset*/
	GPIOGRST,		/*!< IO port G reset*/
	GPIOHRST,		/*!< IO port H reset*/
	CRCRST,		/*!< CRC reset*/
	DMA1RS,		/*!< DMA2 reset*/
	OTGHSRST,		/*!< USB OTG HS module reset*/
};

static constexpr Register<, AHB1RSTRField> AHB1RSTR{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	RCC_AHB2RSTR_GROUP		AHB2 peripheral reset register group
 *
 * @{
 */

enum class AHB2RSTRField {
	DCMIRST,		/*!< Camera interface reset*/
	OTGFSRST,		/*!< USB OTG FS module reset*/
};

static constexpr Register<, AHB2RSTRField> AHB2RSTR{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	RCC_AHB3RSTR_GROUP		AHB3 peripheral reset register group
 *
 * @{
 */

enum class AHB3RSTRField {
	QSPIRST,		/*!< QUADSPI module reset*/
	FMCRST,		/*!< Flexible memory controller module reset*/
};

static constexpr Register<, AHB3RSTRField> AHB3RSTR{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	RCC_APB1RSTR_GROUP		APB1 peripheral reset register group
 *
 * @{
 */

enum class APB1RSTRField {
	DACRST,		/*!< DAC reset*/
	PWRRST,		/*!< Power interface reset*/
	CAN2RST,		/*!< CAN2 reset*/
	CAN1RST,		/*!< CAN1 reset*/
	I2CFMP1RST,		/*!< I2CFMP1 reset*/
	I2C3RST,		/*!< I2C3 reset*/
	I2C2RST,		/*!< I2C 2 reset*/
	I2C1RST,		/*!< I2C 1 reset*/
	UART5RST,		/*!< USART 5 reset*/
	UART4RST,		/*!< USART 4 reset*/
	UART3RST,		/*!< USART 3 reset*/
	UART2RST,		/*!< USART 2 reset*/
	SPDIFRST,		/*!< SPDIF-IN reset*/
	SPI3RST,		/*!< SPI 3 reset*/
	SPI2RST,		/*!< SPI 2 reset*/
	WWDGRST,		/*!< Window watchdog reset*/
	TIM14RST,		/*!< TIM14 reset*/
	TIM13RST,		/*!< TIM13 reset*/
	TIM12RST,		/*!< TIM12 reset*/
	TIM7RST,		/*!< TIM7 reset*/
	TIM6RST,		/*!< TIM6 reset*/
	TIM5RST,		/*!< TIM5 reset*/
	TIM4RST,		/*!< TIM4 reset*/
	TIM3RST,		/*!< TIM3 reset*/
	TIM2RST,		/*!< TIM2 reset*/
};

static constexpr Register<, APB1RSTRField> APB1RSTR{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	RCC_APB2RSTR_GROUP		APB2 peripheral reset register group
 *
 * @{
 */

enum class APB2RSTRField {
	SAI2RST,		/*!< SAI2 reset*/
	SAI1RST,		/*!< SAI1 reset*/
	TIM11RST,		/*!< TIM11 reset*/
	TIM10RST,		/*!< TIM10 reset*/
	TIM9RST,		/*!< TIM9 reset*/
	SYSCFGRST,		/*!< System configuration controller reset*/
	SPI4RST,		/*!< SPI4 reset*/
	SPI1RST,		/*!< SPI 1 reset*/
	SDIORST,		/*!< SDIO reset*/
	ADCRST,		/*!< ADC interface reset (common to all ADCs)*/
	USART6RST,		/*!< USART6 reset*/
	USART1RST,		/*!< USART1 reset*/
	TIM8RST,		/*!< TIM8 reset*/
	TIM1RST,		/*!< TIM1 reset*/
};

static constexpr Register<, APB2RSTRField> APB2RSTR{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	RCC_AHB1ENR_GROUP		AHB1 peripheral clock register group
 *
 * @{
 */

enum class AHB1ENRField {
	GPIOAEN,		/*!< IO port A clock enable*/
	GPIOBEN,		/*!< IO port B clock enable*/
	GPIOCEN,		/*!< IO port C clock enable*/
	GPIODEN,		/*!< IO port D clock enable*/
	GPIOEEN,		/*!< IO port E clock enable*/
	GPIOFEN,		/*!< IO port F clock enable*/
	GPIOGEN,		/*!< IO port G clock enable*/
	GPIOHEN,		/*!< IO port H clock enable*/
	CRCEN,		/*!< CRC clock enable*/
	BKPSRAMEN,		/*!< Backup SRAM interface clock enable*/
	DMA1EN,		/*!< DMA1 clock enable*/
	DMA2EN,		/*!< DMA2 clock enable*/
	OTGHSEN,		/*!< USB OTG HS clock enable*/
	OTGHSULPIEN,		/*!< USB OTG HSULPI clock enable*/
};

static constexpr Register<, AHB1ENRField> AHB1ENR{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	RCC_AHB2ENR_GROUP		AHB2 peripheral clock enable register group
 *
 * @{
 */

enum class AHB2ENRField {
	DCMIEN,		/*!< Camera interface enable*/
	OTGFSEN,		/*!< USB OTG FS clock enable*/
};

static constexpr Register<, AHB2ENRField> AHB2ENR{BASE_ADDR, 0x34U};
/**@}*/

/**
 * @defgroup	RCC_AHB3ENR_GROUP		AHB3 peripheral clock enable register group
 *
 * @{
 */

enum class AHB3ENRField {
	QSPIEN,		/*!< QUADSPI memory controller module clock enable*/
	FMCEN,		/*!< Flexible memory controller module clock enable*/
};

static constexpr Register<, AHB3ENRField> AHB3ENR{BASE_ADDR, 0x38U};
/**@}*/

/**
 * @defgroup	RCC_APB1ENR_GROUP		APB1 peripheral clock enable register group
 *
 * @{
 */

enum class APB1ENRField {
	DACEN,		/*!< DAC interface clock enable*/
	PWREN,		/*!< Power interface clock enable*/
	CEC,		/*!< CEC interface clock enable*/
	CAN2EN,		/*!< CAN 2 clock enable*/
	CAN1EN,		/*!< CAN 1 clock enable*/
	I2CFMP1EN,		/*!< I2CFMP1 clock enable*/
	I2C3EN,		/*!< I2C3 clock enable*/
	I2C2EN,		/*!< I2C2 clock enable*/
	I2C1EN,		/*!< I2C1 clock enable*/
	UART5EN,		/*!< UART5 clock enable*/
	UART4EN,		/*!< UART4 clock enable*/
	USART3EN,		/*!< USART3 clock enable*/
	USART2EN,		/*!< USART 2 clock enable*/
	SPDIFEN,		/*!< SPDIF-IN clock enable*/
	SPI3EN,		/*!< SPI3 clock enable*/
	SPI2EN,		/*!< SPI2 clock enable*/
	WWDGEN,		/*!< Window watchdog clock enable*/
	TIM14EN,		/*!< TIM14 clock enable*/
	TIM13EN,		/*!< TIM13 clock enable*/
	TIM12EN,		/*!< TIM12 clock enable*/
	TIM7EN,		/*!< TIM7 clock enable*/
	TIM6EN,		/*!< TIM6 clock enable*/
	TIM5EN,		/*!< TIM5 clock enable*/
	TIM4EN,		/*!< TIM4 clock enable*/
	TIM3EN,		/*!< TIM3 clock enable*/
	TIM2EN,		/*!< TIM2 clock enable*/
};

static constexpr Register<, APB1ENRField> APB1ENR{BASE_ADDR, 0x40U};
/**@}*/

/**
 * @defgroup	RCC_APB2ENR_GROUP		APB2 peripheral clock enable register group
 *
 * @{
 */

enum class APB2ENRField {
	SAI2EN,		/*!< SAI2 clock enable*/
	SAI1EN,		/*!< SAI1 clock enable*/
	TIM11EN,		/*!< TIM11 clock enable*/
	TIM10EN,		/*!< TIM10 clock enable*/
	TIM9EN,		/*!< TIM9 clock enable*/
	SYSCFGEN,		/*!< System configuration controller clock enable*/
	SPI4ENR,		/*!< SPI4 clock enable*/
	SPI1EN,		/*!< SPI1 clock enable*/
	SDIOEN,		/*!< SDIO clock enable*/
	ADC3EN,		/*!< ADC3 clock enable*/
	ADC2EN,		/*!< ADC2 clock enable*/
	ADC1EN,		/*!< ADC1 clock enable*/
	USART6EN,		/*!< USART6 clock enable*/
	USART1EN,		/*!< USART1 clock enable*/
	TIM8EN,		/*!< TIM8 clock enable*/
	TIM1EN,		/*!< TIM1 clock enable*/
};

static constexpr Register<, APB2ENRField> APB2ENR{BASE_ADDR, 0x44U};
/**@}*/

/**
 * @defgroup	RCC_AHB1LPENR_GROUP		AHB1 peripheral clock enable in low power mode register group
 *
 * @{
 */

enum class AHB1LPENRField {
	OTGHSULPILPEN,		/*!< USB OTG HS ULPI clock enable during Sleep mode*/
	OTGHSLPEN,		/*!< USB OTG HS clock enable during Sleep mode*/
	DMA2LPEN,		/*!< DMA2 clock enable during Sleep mode*/
	DMA1LPEN,		/*!< DMA1 clock enable during Sleep mode*/
	BKPSRAMLPEN,		/*!< Backup SRAM interface clock enable during Sleep mode*/
	SRAM2LPEN,		/*!< SRAM 2 interface clock enable during Sleep mode*/
	SRAM1LPEN,		/*!< SRAM 1interface clock enable during Sleep mode*/
	FLITFLPEN,		/*!< Flash interface clock enable during Sleep mode*/
	CRCLPEN,		/*!< CRC clock enable during Sleep mode*/
	GPIOHLPEN,		/*!< IO port H clock enable during Sleep mode*/
	GPIOGLPEN,		/*!< IO port G clock enable during Sleep mode*/
	GPIOFLPEN,		/*!< IO port F clock enable during Sleep mode*/
	GPIOELPEN,		/*!< IO port E clock enable during Sleep mode*/
	GPIODLPEN,		/*!< IO port D clock enable during Sleep mode*/
	GPIOCLPEN,		/*!< IO port C clock enable during Sleep mode*/
	GPIOBLPEN,		/*!< IO port B clock enable during Sleep mode*/
	GPIOALPEN,		/*!< IO port A clock enable during sleep mode*/
};

static constexpr Register<, AHB1LPENRField> AHB1LPENR{BASE_ADDR, 0x50U};
/**@}*/

/**
 * @defgroup	RCC_AHB2LPENR_GROUP		AHB2 peripheral clock enable in low power mode register group
 *
 * @{
 */

enum class AHB2LPENRField {
	DCMILPEN,		/*!< Camera interface enable during Sleep mode*/
	OTGFSLPEN,		/*!< USB OTG FS clock enable during Sleep mode*/
};

static constexpr Register<, AHB2LPENRField> AHB2LPENR{BASE_ADDR, 0x54U};
/**@}*/

/**
 * @defgroup	RCC_AHB3LPENR_GROUP		AHB3 peripheral clock enable in low power mode register group
 *
 * @{
 */

enum class AHB3LPENRField {
	QSPILPEN,		/*!< QUADSPI memory controller module clock enable during Sleep mode*/
	FMCLPEN,		/*!< Flexible memory controller module clock enable during Sleep mode*/
};

static constexpr Register<, AHB3LPENRField> AHB3LPENR{BASE_ADDR, 0x58U};
/**@}*/

/**
 * @defgroup	RCC_APB1LPENR_GROUP		APB1 peripheral clock enable in low power mode register group
 *
 * @{
 */

enum class APB1LPENRField {
	DACLPEN,		/*!< DAC interface clock enable during Sleep mode*/
	PWRLPEN,		/*!< Power interface clock enable during Sleep mode*/
	CECLPEN,		/*!< CEC clock enable during Sleep mode*/
	CAN2LPEN,		/*!< CAN 2 clock enable during Sleep mode*/
	CAN1LPEN,		/*!< CAN 1 clock enable during Sleep mode*/
	I2CFMP1LPEN,		/*!< I2CFMP1 clock enable during Sleep mode*/
	I2C3LPEN,		/*!< I2C3 clock enable during Sleep mode*/
	I2C2LPEN,		/*!< I2C2 clock enable during Sleep mode*/
	I2C1LPEN,		/*!< I2C1 clock enable during Sleep mode*/
	UART5LPEN,		/*!< UART5 clock enable during Sleep mode*/
	UART4LPEN,		/*!< UART4 clock enable during Sleep mode*/
	USART3LPEN,		/*!< USART3 clock enable during Sleep mode*/
	USART2LPEN,		/*!< USART2 clock enable during Sleep mode*/
	SPDIFLPEN,		/*!< SPDIF clock enable during Sleep mode*/
	SPI3LPEN,		/*!< SPI3 clock enable during Sleep mode*/
	SPI2LPEN,		/*!< SPI2 clock enable during Sleep mode*/
	WWDGLPEN,		/*!< Window watchdog clock enable during Sleep mode*/
	TIM14LPEN,		/*!< TIM14 clock enable during Sleep mode*/
	TIM13LPEN,		/*!< TIM13 clock enable during Sleep mode*/
	TIM12LPEN,		/*!< TIM12 clock enable during Sleep mode*/
	TIM7LPEN,		/*!< TIM7 clock enable during Sleep mode*/
	TIM6LPEN,		/*!< TIM6 clock enable during Sleep mode*/
	TIM5LPEN,		/*!< TIM5 clock enable during Sleep mode*/
	TIM4LPEN,		/*!< TIM4 clock enable during Sleep mode*/
	TIM3LPEN,		/*!< TIM3 clock enable during Sleep mode*/
	TIM2LPEN,		/*!< TIM2 clock enable during Sleep mode*/
};

static constexpr Register<, APB1LPENRField> APB1LPENR{BASE_ADDR, 0x60U};
/**@}*/

/**
 * @defgroup	RCC_APB2LPENR_GROUP		APB2 peripheral clock enabled in low power mode register group
 *
 * @{
 */

enum class APB2LPENRField {
	SAI2LPEN,		/*!< SAI2 clock enable*/
	SAI1LPEN,		/*!< SAI1 clock enable*/
	TIM11LPEN,		/*!< TIM11 clock enable during Sleep mode*/
	TIM10LPEN,		/*!< TIM10 clock enable during Sleep mode*/
	TIM9LPEN,		/*!< TIM9 clock enable during sleep mode*/
	SYSCFGLPEN,		/*!< System configuration controller clock enable during Sleep mode*/
	SPI4LPEN,		/*!< SPI 4 clock enable during Sleep mode*/
	SPI1LPEN,		/*!< SPI 1 clock enable during Sleep mode*/
	SDIOLPEN,		/*!< SDIO clock enable during Sleep mode*/
	ADC3LPEN,		/*!< ADC 3 clock enable during Sleep mode*/
	ADC2LPEN,		/*!< ADC2 clock enable during Sleep mode*/
	ADC1LPEN,		/*!< ADC1 clock enable during Sleep mode*/
	USART6LPEN,		/*!< USART6 clock enable during Sleep mode*/
	USART1LPEN,		/*!< USART1 clock enable during Sleep mode*/
	TIM8LPEN,		/*!< TIM8 clock enable during Sleep mode*/
	TIM1LPEN,		/*!< TIM1 clock enable during Sleep mode*/
};

static constexpr Register<, APB2LPENRField> APB2LPENR{BASE_ADDR, 0x64U};
/**@}*/

/**
 * @defgroup	RCC_BDCR_GROUP		Backup domain control register group
 *
 * @{
 */

enum class BDCRField {
	LSEON,		/*!< External low-speed oscillator enable*/
	LSERDY,		/*!< External low-speed oscillator ready*/
	LSEBYP,		/*!< External low-speed oscillator bypass*/
	LSEMOD,		/*!< External low-speed oscillator mode*/
	RTCSEL,		/*!< RTC clock source selection*/
	RTCEN,		/*!< RTC clock enable*/
	BDRST,		/*!< Backup domain software reset*/
};

static constexpr Register<, BDCRField> BDCR{BASE_ADDR, 0x70U};
/**@}*/

/**
 * @defgroup	RCC_CSR_GROUP		clock control & status register group
 *
 * @{
 */

enum class CSRField {
	LSION,		/*!< Internal low-speed oscillator enable*/
	LSIRDY,		/*!< Internal low-speed oscillator ready*/
	RMVF,		/*!< Remove reset flag*/
	BORRSTF,		/*!< BOR reset flag*/
	PADRSTF,		/*!< PIN reset flag*/
	PORRSTF,		/*!< POR/PDR reset flag*/
	SFTRSTF,		/*!< Software reset flag*/
	WDGRSTF,		/*!< Independent watchdog reset flag*/
	WWDGRSTF,		/*!< Window watchdog reset flag*/
	LPWRRSTF,		/*!< Low-power reset flag*/
};

static constexpr Register<, CSRField> CSR{BASE_ADDR, 0x74U};
/**@}*/

/**
 * @defgroup	RCC_SSCGR_GROUP		spread spectrum clock generation register group
 *
 * @{
 */

enum class SSCGRField {
	MODPER,		/*!< Modulation period*/
	INCSTEP,		/*!< Incrementation step*/
	SPREADSEL,		/*!< Spread Select*/
	SSCGEN,		/*!< Spread spectrum modulation enable*/
};

static constexpr Register<, SSCGRField> SSCGR{BASE_ADDR, 0x80U};
/**@}*/

/**
 * @defgroup	RCC_PLLI2SCFGR_GROUP		PLLI2S configuration register group
 *
 * @{
 */

enum class PLLI2SCFGRField {
	PLLI2SR,		/*!< PLLI2S division factor for I2S clocks*/
	PLLI2SQ,		/*!< PLLI2S division factor for SAI1 clock*/
	PLLI2SP,		/*!< PLLI2S division factor for SPDIF-IN clock*/
	PLLI2SN,		/*!< PLLI2S multiplication factor for VCO*/
	PLLI2SM,		/*!< Division factor for audio PLL (PLLI2S) input clock*/
};

static constexpr Register<, PLLI2SCFGRField> PLLI2SCFGR{BASE_ADDR, 0x84U};
/**@}*/

/**
 * @defgroup	RCC_PLLSAICFGR_GROUP		PLL configuration register group
 *
 * @{
 */

enum class PLLSAICFGRField {
	PLLSAIQ,		/*!< PLLSAI division factor for SAIs clock*/
	PLLSAIP,		/*!< PLLSAI division factor for 48 MHz clock*/
	PLLSAIN,		/*!< PLLSAI division factor for VCO*/
	PLLSAIM,		/*!< Division factor for audio PLLSAI input clock*/
};

static constexpr Register<, PLLSAICFGRField> PLLSAICFGR{BASE_ADDR, 0x88U};
/**@}*/

/**
 * @defgroup	RCC_DCKCFGR_GROUP		Dedicated Clock Configuration Register group
 *
 * @{
 */

enum class DCKCFGRField {
	I2S2SRC,		/*!< I2S APB2 clock source selection*/
	I2S1SRC,		/*!< I2S APB1 clock source selection*/
	TIMPRE,		/*!< Timers clocks prescalers selection*/
	SAI2SRC,		/*!< SAI2 clock source selection*/
	SAI1SRC,		/*!< SAI1 clock source selection*/
	PLLSAIDIVQ,		/*!< PLLSAI division factor for SAIs clock*/
	PLLI2SDIVQ,		/*!< PLLI2S division factor for SAIs clock*/
};

static constexpr Register<, DCKCFGRField> DCKCFGR{BASE_ADDR, 0x8cU};
/**@}*/

/**
 * @defgroup	RCC_CKGATENR_GROUP		clocks gated enable register group
 *
 * @{
 */

enum class CKGATENRField {
	RCC_CKEN,		/*!< RCC clock enable*/
	FLITF_CKEN,		/*!< Flash Interface clock enable*/
	SRAM_CKEN,		/*!< SRQAM controller clock enable*/
	SPARE_CKEN,		/*!< Spare clock enable*/
	CM4DBG_CKEN,		/*!< Cortex M4 ETM clock enable*/
	AHB2APB2_CKEN,		/*!< AHB to APB2 Bridge clock enable*/
	AHB2APB1_CKEN,		/*!< AHB to APB1 Bridge clock enable*/
};

static constexpr Register<, CKGATENRField> CKGATENR{BASE_ADDR, 0x90U};
/**@}*/

/**
 * @defgroup	RCC_DCKCFGR2_GROUP		dedicated clocks configuration register 2 group
 *
 * @{
 */

enum class DCKCFGR2Field {
	SPDIFSEL,		/*!< SPDIF clock selection*/
	SDIOSEL,		/*!< SDIO clock selection*/
	CK48MSEL,		/*!< SDIO/USBFS/HS clock selection*/
	CECSEL,		/*!< HDMI CEC clock source selection*/
	FMPI2C1SEL,		/*!< I2C4 kernel clock source selection*/
};

static constexpr Register<, DCKCFGR2Field> DCKCFGR2{BASE_ADDR, 0x94U};
/**@}*/


} // cpp_stm32::rcc::reg
