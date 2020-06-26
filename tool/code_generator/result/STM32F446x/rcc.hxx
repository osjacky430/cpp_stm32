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

SETUP_REGISTER_INFO(CRBitList,									 /**/
										Binary<>{BitPos_t{0}},			 // HSION
										StatusBit<1>{BitPos_t{1}},	 // HSIRDY
										Bit<5>{BitPos_t{3}},				 // HSITRIM
										StatusBit<8>{BitPos_t{8}},	 // HSICAL
										Binary<>{BitPos_t{16}},			 // HSEON
										StatusBit<1>{BitPos_t{17}},	 // HSERDY
										Binary<>{BitPos_t{18}},			 // HSEBYP
										Binary<>{BitPos_t{19}},			 // CSSON
										Binary<>{BitPos_t{24}},			 // PLLON
										StatusBit<1>{BitPos_t{25}},	 // PLLRDY
										Binary<>{BitPos_t{26}},			 // PLLI2SON
										StatusBit<1>{BitPos_t{27}}	 // PLLI2SRDY
)

enum class CRField {
	HSION,		 /*!< Internal high-speed clock enable*/
	HSIRDY,		 /*!< Internal high-speed clock ready flag*/
	HSITRIM,	 /*!< Internal high-speed clock trimming*/
	HSICAL,		 /*!< Internal high-speed clock calibration*/
	HSEON,		 /*!< HSE clock enable*/
	HSERDY,		 /*!< HSE clock ready flag*/
	HSEBYP,		 /*!< HSE clock bypass*/
	CSSON,		 /*!< Clock security system enable*/
	PLLON,		 /*!< Main PLL (PLL) enable*/
	PLLRDY,		 /*!< Main PLL (PLL) clock ready flag*/
	PLLI2SON,	 /*!< PLLI2S enable*/
	PLLI2SRDY, /*!< PLLI2S clock ready flag*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	RCC_PLLCFGR_GROUP		PLL configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PLLCFGRBitList,											 /**/
										Bit<6>{BitPos_t{0}},								 // PLLM
										Bit<9, std::uint16_t>{BitPos_t{6}},	 // PLLN
										Bit<2>{BitPos_t{16}},								 // PLLP
										Binary<>{BitPos_t{22}},							 // PLLSRC
										Bit<4>{BitPos_t{24}}								 // PLLQ
)

enum class PLLCFGRField {
	PLLM,		/*!< Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock*/
	PLLN,		/*!< Main PLL (PLL) multiplication factor for VCO*/
	PLLP,		/*!< Main PLL (PLL) division factor for main system clock*/
	PLLSRC, /*!< Main PLL(PLL) and audio PLL (PLLI2S) entry clock source*/
	PLLQ,		/*!< Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks*/
};

static constexpr Register<PLLCFGRBitList, PLLCFGRField> PLLCFGR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	RCC_CFGR_GROUP		clock configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CFGRBitList,								/**/
										Bit<2>{BitPos_t{0}},				// SW
										StatusBit<2>{BitPos_t{2}},	// SWS
										Bit<4>{BitPos_t{4}},				// HPRE
										Bit<3>{BitPos_t{10}},				// PPRE1
										Bit<3>{BitPos_t{13}},				// PPRE2
										Bit<5>{BitPos_t{16}},				// RTCPRE
										Bit<2>{BitPos_t{21}},				// MCO1
										Binary<>{BitPos_t{23}},			// I2SSRC
										Bit<3>{BitPos_t{24}},				// MCO1PRE
										Bit<3>{BitPos_t{27}},				// MCO2PRE
										Bit<2>{BitPos_t{30}}				// MCO2
)

enum class CFGRField {
	SW,			 /*!< System clock switch*/
	SWS,		 /*!< System clock switch status*/
	HPRE,		 /*!< AHB prescaler*/
	PPRE1,	 /*!< APB Low speed prescaler (APB1)*/
	PPRE2,	 /*!< APB high-speed prescaler (APB2)*/
	RTCPRE,	 /*!< HSE division factor for RTC clock*/
	MCO1,		 /*!< Microcontroller clock output 1*/
	I2SSRC,	 /*!< I2S clock selection*/
	MCO1PRE, /*!< MCO1 prescaler*/
	MCO2PRE, /*!< MCO2 prescaler*/
	MCO2,		 /*!< Microcontroller clock output 2*/
};

static constexpr Register<CFGRBitList, CFGRField> CFGR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	RCC_CIR_GROUP		clock interrupt register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CIRBitList,														 /**/
										StatusBit<1>{BitPos_t{0}},						 // LSIRDYF
										StatusBit<1>{BitPos_t{1}},						 // LSERDYF
										StatusBit<1>{BitPos_t{2}},						 // HSIRDYF
										StatusBit<1>{BitPos_t{3}},						 // HSERDYF
										StatusBit<1>{BitPos_t{4}},						 // PLLRDYF
										StatusBit<1>{BitPos_t{5}},						 // PLLI2SRDYF
										StatusBit<1>{BitPos_t{6}},						 // PLLSAIRDYF
										StatusBit<1>{BitPos_t{7}},						 // CSSF
										Binary<>{BitPos_t{8}},								 // LSIRDYIE
										Binary<>{BitPos_t{9}},								 // LSERDYIE
										Binary<>{BitPos_t{10}},								 // HSIRDYIE
										Binary<>{BitPos_t{11}},								 // HSERDYIE
										Binary<>{BitPos_t{12}},								 // PLLRDYIE
										Binary<>{BitPos_t{13}},								 // PLLI2SRDYIE
										Binary<>{BitPos_t{14}},								 // PLLSAIRDYIE
										Binary<BitMod::WrOnly>{BitPos_t{16}},	 // LSIRDYC
										Binary<BitMod::WrOnly>{BitPos_t{17}},	 // LSERDYC
										Binary<BitMod::WrOnly>{BitPos_t{18}},	 // HSIRDYC
										Binary<BitMod::WrOnly>{BitPos_t{19}},	 // HSERDYC
										Binary<BitMod::WrOnly>{BitPos_t{20}},	 // PLLRDYC
										Binary<BitMod::WrOnly>{BitPos_t{21}},	 // PLLI2SRDYC
										Binary<BitMod::WrOnly>{BitPos_t{22}},	 // PLLSAIRDYC
										Binary<BitMod::WrOnly>{BitPos_t{23}}	 // CSSC
)

enum class CIRField {
	LSIRDYF,		 /*!< LSI ready interrupt flag*/
	LSERDYF,		 /*!< LSE ready interrupt flag*/
	HSIRDYF,		 /*!< HSI ready interrupt flag*/
	HSERDYF,		 /*!< HSE ready interrupt flag*/
	PLLRDYF,		 /*!< Main PLL (PLL) ready interrupt flag*/
	PLLI2SRDYF,	 /*!< PLLI2S ready interrupt flag*/
	PLLSAIRDYF,	 /*!< PLLSAI ready interrupt flag*/
	CSSF,				 /*!< Clock security system interrupt flag*/
	LSIRDYIE,		 /*!< LSI ready interrupt enable*/
	LSERDYIE,		 /*!< LSE ready interrupt enable*/
	HSIRDYIE,		 /*!< HSI ready interrupt enable*/
	HSERDYIE,		 /*!< HSE ready interrupt enable*/
	PLLRDYIE,		 /*!< Main PLL (PLL) ready interrupt enable*/
	PLLI2SRDYIE, /*!< PLLI2S ready interrupt enable*/
	PLLSAIRDYIE, /*!< PLLSAI Ready Interrupt Enable*/
	LSIRDYC,		 /*!< LSI ready interrupt clear*/
	LSERDYC,		 /*!< LSE ready interrupt clear*/
	HSIRDYC,		 /*!< HSI ready interrupt clear*/
	HSERDYC,		 /*!< HSE ready interrupt clear*/
	PLLRDYC,		 /*!< Main PLL(PLL) ready interrupt clear*/
	PLLI2SRDYC,	 /*!< PLLI2S ready interrupt clear*/
	PLLSAIRDYC,	 /*!< PLLSAI Ready Interrupt Clear*/
	CSSC,				 /*!< Clock security system interrupt clear*/
};

static constexpr Register<CIRBitList, CIRField> CIR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	RCC_AHB1RSTR_GROUP		AHB1 peripheral reset register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB1RSTRBitList,				 /**/
										Binary<>{BitPos_t{0}},	 // GPIOARST
										Binary<>{BitPos_t{1}},	 // GPIOBRST
										Binary<>{BitPos_t{2}},	 // GPIOCRST
										Binary<>{BitPos_t{3}},	 // GPIODRST
										Binary<>{BitPos_t{4}},	 // GPIOERST
										Binary<>{BitPos_t{5}},	 // GPIOFRST
										Binary<>{BitPos_t{6}},	 // GPIOGRST
										Binary<>{BitPos_t{7}},	 // GPIOHRST
										Binary<>{BitPos_t{12}},	 // CRCRST
										Bit<2>{BitPos_t{21}},		 // DMA1RS
										Binary<>{BitPos_t{29}}	 // OTGHSRST
)

enum class AHB1RSTRField {
	GPIOARST, /*!< IO port A reset*/
	GPIOBRST, /*!< IO port B reset*/
	GPIOCRST, /*!< IO port C reset*/
	GPIODRST, /*!< IO port D reset*/
	GPIOERST, /*!< IO port E reset*/
	GPIOFRST, /*!< IO port F reset*/
	GPIOGRST, /*!< IO port G reset*/
	GPIOHRST, /*!< IO port H reset*/
	CRCRST,		/*!< CRC reset*/
	DMA1RS,		/*!< DMA2 reset*/
	OTGHSRST, /*!< USB OTG HS module reset*/
};

static constexpr Register<AHB1RSTRBitList, AHB1RSTRField> AHB1RSTR{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	RCC_AHB2RSTR_GROUP		AHB2 peripheral reset register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB2RSTRBitList,				/**/
										Binary<>{BitPos_t{0}},	// DCMIRST
										Binary<>{BitPos_t{7}}		// OTGFSRST
)

enum class AHB2RSTRField {
	DCMIRST,	/*!< Camera interface reset*/
	OTGFSRST, /*!< USB OTG FS module reset*/
};

static constexpr Register<AHB2RSTRBitList, AHB2RSTRField> AHB2RSTR{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	RCC_AHB3RSTR_GROUP		AHB3 peripheral reset register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB3RSTRBitList,				/**/
										Binary<>{BitPos_t{1}},	// QSPIRST
										Binary<>{BitPos_t{0}}		// FMCRST
)

enum class AHB3RSTRField {
	QSPIRST, /*!< QUADSPI module reset*/
	FMCRST,	 /*!< Flexible memory controller module reset*/
};

static constexpr Register<AHB3RSTRBitList, AHB3RSTRField> AHB3RSTR{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	RCC_APB1RSTR_GROUP		APB1 peripheral reset register group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB1RSTRBitList,				 /**/
										Binary<>{BitPos_t{29}},	 // DACRST
										Binary<>{BitPos_t{28}},	 // PWRRST
										Binary<>{BitPos_t{26}},	 // CAN2RST
										Binary<>{BitPos_t{25}},	 // CAN1RST
										Binary<>{BitPos_t{24}},	 // I2CFMP1RST
										Binary<>{BitPos_t{23}},	 // I2C3RST
										Binary<>{BitPos_t{22}},	 // I2C2RST
										Binary<>{BitPos_t{21}},	 // I2C1RST
										Binary<>{BitPos_t{20}},	 // UART5RST
										Binary<>{BitPos_t{19}},	 // UART4RST
										Binary<>{BitPos_t{18}},	 // UART3RST
										Binary<>{BitPos_t{17}},	 // UART2RST
										Binary<>{BitPos_t{16}},	 // SPDIFRST
										Binary<>{BitPos_t{15}},	 // SPI3RST
										Binary<>{BitPos_t{14}},	 // SPI2RST
										Binary<>{BitPos_t{11}},	 // WWDGRST
										Binary<>{BitPos_t{8}},	 // TIM14RST
										Binary<>{BitPos_t{7}},	 // TIM13RST
										Binary<>{BitPos_t{6}},	 // TIM12RST
										Binary<>{BitPos_t{5}},	 // TIM7RST
										Binary<>{BitPos_t{4}},	 // TIM6RST
										Binary<>{BitPos_t{3}},	 // TIM5RST
										Binary<>{BitPos_t{2}},	 // TIM4RST
										Binary<>{BitPos_t{1}},	 // TIM3RST
										Binary<>{BitPos_t{0}}		 // TIM2RST
)

enum class APB1RSTRField {
	DACRST,			/*!< DAC reset*/
	PWRRST,			/*!< Power interface reset*/
	CAN2RST,		/*!< CAN2 reset*/
	CAN1RST,		/*!< CAN1 reset*/
	I2CFMP1RST, /*!< I2CFMP1 reset*/
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

static constexpr Register<APB1RSTRBitList, APB1RSTRField> APB1RSTR{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	RCC_APB2RSTR_GROUP		APB2 peripheral reset register group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB2RSTRBitList,				 /**/
										Binary<>{BitPos_t{23}},	 // SAI2RST
										Binary<>{BitPos_t{22}},	 // SAI1RST
										Binary<>{BitPos_t{18}},	 // TIM11RST
										Binary<>{BitPos_t{17}},	 // TIM10RST
										Binary<>{BitPos_t{16}},	 // TIM9RST
										Binary<>{BitPos_t{14}},	 // SYSCFGRST
										Binary<>{BitPos_t{13}},	 // SPI4RST
										Binary<>{BitPos_t{12}},	 // SPI1RST
										Binary<>{BitPos_t{11}},	 // SDIORST
										Binary<>{BitPos_t{8}},	 // ADCRST
										Binary<>{BitPos_t{5}},	 // USART6RST
										Binary<>{BitPos_t{4}},	 // USART1RST
										Binary<>{BitPos_t{1}},	 // TIM8RST
										Binary<>{BitPos_t{0}}		 // TIM1RST
)

enum class APB2RSTRField {
	SAI2RST,	 /*!< SAI2 reset*/
	SAI1RST,	 /*!< SAI1 reset*/
	TIM11RST,	 /*!< TIM11 reset*/
	TIM10RST,	 /*!< TIM10 reset*/
	TIM9RST,	 /*!< TIM9 reset*/
	SYSCFGRST, /*!< System configuration controller reset*/
	SPI4RST,	 /*!< SPI4 reset*/
	SPI1RST,	 /*!< SPI 1 reset*/
	SDIORST,	 /*!< SDIO reset*/
	ADCRST,		 /*!< ADC interface reset (common to all ADCs)*/
	USART6RST, /*!< USART6 reset*/
	USART1RST, /*!< USART1 reset*/
	TIM8RST,	 /*!< TIM8 reset*/
	TIM1RST,	 /*!< TIM1 reset*/
};

static constexpr Register<APB2RSTRBitList, APB2RSTRField> APB2RSTR{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	RCC_AHB1ENR_GROUP		AHB1 peripheral clock register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB1ENRBitList,					 /**/
										Binary<>{BitPos_t{0}},	 // GPIOAEN
										Binary<>{BitPos_t{1}},	 // GPIOBEN
										Binary<>{BitPos_t{2}},	 // GPIOCEN
										Binary<>{BitPos_t{3}},	 // GPIODEN
										Binary<>{BitPos_t{4}},	 // GPIOEEN
										Binary<>{BitPos_t{5}},	 // GPIOFEN
										Binary<>{BitPos_t{6}},	 // GPIOGEN
										Binary<>{BitPos_t{7}},	 // GPIOHEN
										Binary<>{BitPos_t{12}},	 // CRCEN
										Binary<>{BitPos_t{18}},	 // BKPSRAMEN
										Binary<>{BitPos_t{21}},	 // DMA1EN
										Binary<>{BitPos_t{22}},	 // DMA2EN
										Binary<>{BitPos_t{29}},	 // OTGHSEN
										Binary<>{BitPos_t{30}}	 // OTGHSULPIEN
)

enum class AHB1ENRField {
	GPIOAEN,		 /*!< IO port A clock enable*/
	GPIOBEN,		 /*!< IO port B clock enable*/
	GPIOCEN,		 /*!< IO port C clock enable*/
	GPIODEN,		 /*!< IO port D clock enable*/
	GPIOEEN,		 /*!< IO port E clock enable*/
	GPIOFEN,		 /*!< IO port F clock enable*/
	GPIOGEN,		 /*!< IO port G clock enable*/
	GPIOHEN,		 /*!< IO port H clock enable*/
	CRCEN,			 /*!< CRC clock enable*/
	BKPSRAMEN,	 /*!< Backup SRAM interface clock enable*/
	DMA1EN,			 /*!< DMA1 clock enable*/
	DMA2EN,			 /*!< DMA2 clock enable*/
	OTGHSEN,		 /*!< USB OTG HS clock enable*/
	OTGHSULPIEN, /*!< USB OTG HSULPI clock enable*/
};

static constexpr Register<AHB1ENRBitList, AHB1ENRField> AHB1ENR{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	RCC_AHB2ENR_GROUP		AHB2 peripheral clock enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB2ENRBitList,					/**/
										Binary<>{BitPos_t{0}},	// DCMIEN
										Binary<>{BitPos_t{7}}		// OTGFSEN
)

enum class AHB2ENRField {
	DCMIEN,	 /*!< Camera interface enable*/
	OTGFSEN, /*!< USB OTG FS clock enable*/
};

static constexpr Register<AHB2ENRBitList, AHB2ENRField> AHB2ENR{BASE_ADDR, 0x34U};
/**@}*/

/**
 * @defgroup	RCC_AHB3ENR_GROUP		AHB3 peripheral clock enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB3ENRBitList,					/**/
										Binary<>{BitPos_t{1}},	// QSPIEN
										Binary<>{BitPos_t{0}}		// FMCEN
)

enum class AHB3ENRField {
	QSPIEN, /*!< QUADSPI memory controller module clock enable*/
	FMCEN,	/*!< Flexible memory controller module clock enable*/
};

static constexpr Register<AHB3ENRBitList, AHB3ENRField> AHB3ENR{BASE_ADDR, 0x38U};
/**@}*/

/**
 * @defgroup	RCC_APB1ENR_GROUP		APB1 peripheral clock enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB1ENRBitList,					 /**/
										Binary<>{BitPos_t{29}},	 // DACEN
										Binary<>{BitPos_t{28}},	 // PWREN
										Binary<>{BitPos_t{27}},	 // CEC
										Binary<>{BitPos_t{26}},	 // CAN2EN
										Binary<>{BitPos_t{25}},	 // CAN1EN
										Binary<>{BitPos_t{24}},	 // I2CFMP1EN
										Binary<>{BitPos_t{23}},	 // I2C3EN
										Binary<>{BitPos_t{22}},	 // I2C2EN
										Binary<>{BitPos_t{21}},	 // I2C1EN
										Binary<>{BitPos_t{20}},	 // UART5EN
										Binary<>{BitPos_t{19}},	 // UART4EN
										Binary<>{BitPos_t{18}},	 // USART3EN
										Binary<>{BitPos_t{17}},	 // USART2EN
										Binary<>{BitPos_t{16}},	 // SPDIFEN
										Binary<>{BitPos_t{15}},	 // SPI3EN
										Binary<>{BitPos_t{14}},	 // SPI2EN
										Binary<>{BitPos_t{11}},	 // WWDGEN
										Binary<>{BitPos_t{8}},	 // TIM14EN
										Binary<>{BitPos_t{7}},	 // TIM13EN
										Binary<>{BitPos_t{6}},	 // TIM12EN
										Binary<>{BitPos_t{5}},	 // TIM7EN
										Binary<>{BitPos_t{4}},	 // TIM6EN
										Binary<>{BitPos_t{3}},	 // TIM5EN
										Binary<>{BitPos_t{2}},	 // TIM4EN
										Binary<>{BitPos_t{1}},	 // TIM3EN
										Binary<>{BitPos_t{0}}		 // TIM2EN
)

enum class APB1ENRField {
	DACEN,		 /*!< DAC interface clock enable*/
	PWREN,		 /*!< Power interface clock enable*/
	CEC,			 /*!< CEC interface clock enable*/
	CAN2EN,		 /*!< CAN 2 clock enable*/
	CAN1EN,		 /*!< CAN 1 clock enable*/
	I2CFMP1EN, /*!< I2CFMP1 clock enable*/
	I2C3EN,		 /*!< I2C3 clock enable*/
	I2C2EN,		 /*!< I2C2 clock enable*/
	I2C1EN,		 /*!< I2C1 clock enable*/
	UART5EN,	 /*!< UART5 clock enable*/
	UART4EN,	 /*!< UART4 clock enable*/
	USART3EN,	 /*!< USART3 clock enable*/
	USART2EN,	 /*!< USART 2 clock enable*/
	SPDIFEN,	 /*!< SPDIF-IN clock enable*/
	SPI3EN,		 /*!< SPI3 clock enable*/
	SPI2EN,		 /*!< SPI2 clock enable*/
	WWDGEN,		 /*!< Window watchdog clock enable*/
	TIM14EN,	 /*!< TIM14 clock enable*/
	TIM13EN,	 /*!< TIM13 clock enable*/
	TIM12EN,	 /*!< TIM12 clock enable*/
	TIM7EN,		 /*!< TIM7 clock enable*/
	TIM6EN,		 /*!< TIM6 clock enable*/
	TIM5EN,		 /*!< TIM5 clock enable*/
	TIM4EN,		 /*!< TIM4 clock enable*/
	TIM3EN,		 /*!< TIM3 clock enable*/
	TIM2EN,		 /*!< TIM2 clock enable*/
};

static constexpr Register<APB1ENRBitList, APB1ENRField> APB1ENR{BASE_ADDR, 0x40U};
/**@}*/

/**
 * @defgroup	RCC_APB2ENR_GROUP		APB2 peripheral clock enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB2ENRBitList,					 /**/
										Binary<>{BitPos_t{23}},	 // SAI2EN
										Binary<>{BitPos_t{22}},	 // SAI1EN
										Binary<>{BitPos_t{18}},	 // TIM11EN
										Binary<>{BitPos_t{17}},	 // TIM10EN
										Binary<>{BitPos_t{16}},	 // TIM9EN
										Binary<>{BitPos_t{14}},	 // SYSCFGEN
										Binary<>{BitPos_t{13}},	 // SPI4ENR
										Binary<>{BitPos_t{12}},	 // SPI1EN
										Binary<>{BitPos_t{11}},	 // SDIOEN
										Binary<>{BitPos_t{10}},	 // ADC3EN
										Binary<>{BitPos_t{9}},	 // ADC2EN
										Binary<>{BitPos_t{8}},	 // ADC1EN
										Binary<>{BitPos_t{5}},	 // USART6EN
										Binary<>{BitPos_t{4}},	 // USART1EN
										Binary<>{BitPos_t{1}},	 // TIM8EN
										Binary<>{BitPos_t{0}}		 // TIM1EN
)

enum class APB2ENRField {
	SAI2EN,		/*!< SAI2 clock enable*/
	SAI1EN,		/*!< SAI1 clock enable*/
	TIM11EN,	/*!< TIM11 clock enable*/
	TIM10EN,	/*!< TIM10 clock enable*/
	TIM9EN,		/*!< TIM9 clock enable*/
	SYSCFGEN, /*!< System configuration controller clock enable*/
	SPI4ENR,	/*!< SPI4 clock enable*/
	SPI1EN,		/*!< SPI1 clock enable*/
	SDIOEN,		/*!< SDIO clock enable*/
	ADC3EN,		/*!< ADC3 clock enable*/
	ADC2EN,		/*!< ADC2 clock enable*/
	ADC1EN,		/*!< ADC1 clock enable*/
	USART6EN, /*!< USART6 clock enable*/
	USART1EN, /*!< USART1 clock enable*/
	TIM8EN,		/*!< TIM8 clock enable*/
	TIM1EN,		/*!< TIM1 clock enable*/
};

static constexpr Register<APB2ENRBitList, APB2ENRField> APB2ENR{BASE_ADDR, 0x44U};
/**@}*/

/**
 * @defgroup	RCC_AHB1LPENR_GROUP		AHB1 peripheral clock enable in low power mode register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB1LPENRBitList,				 /**/
										Binary<>{BitPos_t{30}},	 // OTGHSULPILPEN
										Binary<>{BitPos_t{29}},	 // OTGHSLPEN
										Binary<>{BitPos_t{22}},	 // DMA2LPEN
										Binary<>{BitPos_t{21}},	 // DMA1LPEN
										Binary<>{BitPos_t{18}},	 // BKPSRAMLPEN
										Binary<>{BitPos_t{17}},	 // SRAM2LPEN
										Binary<>{BitPos_t{16}},	 // SRAM1LPEN
										Binary<>{BitPos_t{15}},	 // FLITFLPEN
										Binary<>{BitPos_t{12}},	 // CRCLPEN
										Binary<>{BitPos_t{7}},	 // GPIOHLPEN
										Binary<>{BitPos_t{6}},	 // GPIOGLPEN
										Binary<>{BitPos_t{5}},	 // GPIOFLPEN
										Binary<>{BitPos_t{4}},	 // GPIOELPEN
										Binary<>{BitPos_t{3}},	 // GPIODLPEN
										Binary<>{BitPos_t{2}},	 // GPIOCLPEN
										Binary<>{BitPos_t{1}},	 // GPIOBLPEN
										Binary<>{BitPos_t{0}}		 // GPIOALPEN
)

enum class AHB1LPENRField {
	OTGHSULPILPEN, /*!< USB OTG HS ULPI clock enable during Sleep mode*/
	OTGHSLPEN,		 /*!< USB OTG HS clock enable during Sleep mode*/
	DMA2LPEN,			 /*!< DMA2 clock enable during Sleep mode*/
	DMA1LPEN,			 /*!< DMA1 clock enable during Sleep mode*/
	BKPSRAMLPEN,	 /*!< Backup SRAM interface clock enable during Sleep mode*/
	SRAM2LPEN,		 /*!< SRAM 2 interface clock enable during Sleep mode*/
	SRAM1LPEN,		 /*!< SRAM 1interface clock enable during Sleep mode*/
	FLITFLPEN,		 /*!< Flash interface clock enable during Sleep mode*/
	CRCLPEN,			 /*!< CRC clock enable during Sleep mode*/
	GPIOHLPEN,		 /*!< IO port H clock enable during Sleep mode*/
	GPIOGLPEN,		 /*!< IO port G clock enable during Sleep mode*/
	GPIOFLPEN,		 /*!< IO port F clock enable during Sleep mode*/
	GPIOELPEN,		 /*!< IO port E clock enable during Sleep mode*/
	GPIODLPEN,		 /*!< IO port D clock enable during Sleep mode*/
	GPIOCLPEN,		 /*!< IO port C clock enable during Sleep mode*/
	GPIOBLPEN,		 /*!< IO port B clock enable during Sleep mode*/
	GPIOALPEN,		 /*!< IO port A clock enable during sleep mode*/
};

static constexpr Register<AHB1LPENRBitList, AHB1LPENRField> AHB1LPENR{BASE_ADDR, 0x50U};
/**@}*/

/**
 * @defgroup	RCC_AHB2LPENR_GROUP		AHB2 peripheral clock enable in low power mode register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB2LPENRBitList,				/**/
										Binary<>{BitPos_t{0}},	// DCMILPEN
										Binary<>{BitPos_t{7}}		// OTGFSLPEN
)

enum class AHB2LPENRField {
	DCMILPEN,	 /*!< Camera interface enable during Sleep mode*/
	OTGFSLPEN, /*!< USB OTG FS clock enable during Sleep mode*/
};

static constexpr Register<AHB2LPENRBitList, AHB2LPENRField> AHB2LPENR{BASE_ADDR, 0x54U};
/**@}*/

/**
 * @defgroup	RCC_AHB3LPENR_GROUP		AHB3 peripheral clock enable in low power mode register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB3LPENRBitList,				/**/
										Binary<>{BitPos_t{1}},	// QSPILPEN
										Binary<>{BitPos_t{0}}		// FMCLPEN
)

enum class AHB3LPENRField {
	QSPILPEN, /*!< QUADSPI memory controller module clock enable during Sleep mode*/
	FMCLPEN,	/*!< Flexible memory controller module clock enable during Sleep mode*/
};

static constexpr Register<AHB3LPENRBitList, AHB3LPENRField> AHB3LPENR{BASE_ADDR, 0x58U};
/**@}*/

/**
 * @defgroup	RCC_APB1LPENR_GROUP		APB1 peripheral clock enable in low power mode register group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB1LPENRBitList,				 /**/
										Binary<>{BitPos_t{29}},	 // DACLPEN
										Binary<>{BitPos_t{28}},	 // PWRLPEN
										Binary<>{BitPos_t{27}},	 // CECLPEN
										Binary<>{BitPos_t{26}},	 // CAN2LPEN
										Binary<>{BitPos_t{25}},	 // CAN1LPEN
										Binary<>{BitPos_t{24}},	 // I2CFMP1LPEN
										Binary<>{BitPos_t{23}},	 // I2C3LPEN
										Binary<>{BitPos_t{22}},	 // I2C2LPEN
										Binary<>{BitPos_t{21}},	 // I2C1LPEN
										Binary<>{BitPos_t{20}},	 // UART5LPEN
										Binary<>{BitPos_t{19}},	 // UART4LPEN
										Binary<>{BitPos_t{18}},	 // USART3LPEN
										Binary<>{BitPos_t{17}},	 // USART2LPEN
										Binary<>{BitPos_t{16}},	 // SPDIFLPEN
										Binary<>{BitPos_t{15}},	 // SPI3LPEN
										Binary<>{BitPos_t{14}},	 // SPI2LPEN
										Binary<>{BitPos_t{11}},	 // WWDGLPEN
										Binary<>{BitPos_t{8}},	 // TIM14LPEN
										Binary<>{BitPos_t{7}},	 // TIM13LPEN
										Binary<>{BitPos_t{6}},	 // TIM12LPEN
										Binary<>{BitPos_t{5}},	 // TIM7LPEN
										Binary<>{BitPos_t{4}},	 // TIM6LPEN
										Binary<>{BitPos_t{3}},	 // TIM5LPEN
										Binary<>{BitPos_t{2}},	 // TIM4LPEN
										Binary<>{BitPos_t{1}},	 // TIM3LPEN
										Binary<>{BitPos_t{0}}		 // TIM2LPEN
)

enum class APB1LPENRField {
	DACLPEN,		 /*!< DAC interface clock enable during Sleep mode*/
	PWRLPEN,		 /*!< Power interface clock enable during Sleep mode*/
	CECLPEN,		 /*!< CEC clock enable during Sleep mode*/
	CAN2LPEN,		 /*!< CAN 2 clock enable during Sleep mode*/
	CAN1LPEN,		 /*!< CAN 1 clock enable during Sleep mode*/
	I2CFMP1LPEN, /*!< I2CFMP1 clock enable during Sleep mode*/
	I2C3LPEN,		 /*!< I2C3 clock enable during Sleep mode*/
	I2C2LPEN,		 /*!< I2C2 clock enable during Sleep mode*/
	I2C1LPEN,		 /*!< I2C1 clock enable during Sleep mode*/
	UART5LPEN,	 /*!< UART5 clock enable during Sleep mode*/
	UART4LPEN,	 /*!< UART4 clock enable during Sleep mode*/
	USART3LPEN,	 /*!< USART3 clock enable during Sleep mode*/
	USART2LPEN,	 /*!< USART2 clock enable during Sleep mode*/
	SPDIFLPEN,	 /*!< SPDIF clock enable during Sleep mode*/
	SPI3LPEN,		 /*!< SPI3 clock enable during Sleep mode*/
	SPI2LPEN,		 /*!< SPI2 clock enable during Sleep mode*/
	WWDGLPEN,		 /*!< Window watchdog clock enable during Sleep mode*/
	TIM14LPEN,	 /*!< TIM14 clock enable during Sleep mode*/
	TIM13LPEN,	 /*!< TIM13 clock enable during Sleep mode*/
	TIM12LPEN,	 /*!< TIM12 clock enable during Sleep mode*/
	TIM7LPEN,		 /*!< TIM7 clock enable during Sleep mode*/
	TIM6LPEN,		 /*!< TIM6 clock enable during Sleep mode*/
	TIM5LPEN,		 /*!< TIM5 clock enable during Sleep mode*/
	TIM4LPEN,		 /*!< TIM4 clock enable during Sleep mode*/
	TIM3LPEN,		 /*!< TIM3 clock enable during Sleep mode*/
	TIM2LPEN,		 /*!< TIM2 clock enable during Sleep mode*/
};

static constexpr Register<APB1LPENRBitList, APB1LPENRField> APB1LPENR{BASE_ADDR, 0x60U};
/**@}*/

/**
 * @defgroup	RCC_APB2LPENR_GROUP		APB2 peripheral clock enabled in low power mode register group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB2LPENRBitList,				 /**/
										Binary<>{BitPos_t{23}},	 // SAI2LPEN
										Binary<>{BitPos_t{22}},	 // SAI1LPEN
										Binary<>{BitPos_t{18}},	 // TIM11LPEN
										Binary<>{BitPos_t{17}},	 // TIM10LPEN
										Binary<>{BitPos_t{16}},	 // TIM9LPEN
										Binary<>{BitPos_t{14}},	 // SYSCFGLPEN
										Binary<>{BitPos_t{13}},	 // SPI4LPEN
										Binary<>{BitPos_t{12}},	 // SPI1LPEN
										Binary<>{BitPos_t{11}},	 // SDIOLPEN
										Binary<>{BitPos_t{10}},	 // ADC3LPEN
										Binary<>{BitPos_t{9}},	 // ADC2LPEN
										Binary<>{BitPos_t{8}},	 // ADC1LPEN
										Binary<>{BitPos_t{5}},	 // USART6LPEN
										Binary<>{BitPos_t{4}},	 // USART1LPEN
										Binary<>{BitPos_t{1}},	 // TIM8LPEN
										Binary<>{BitPos_t{0}}		 // TIM1LPEN
)

enum class APB2LPENRField {
	SAI2LPEN,		/*!< SAI2 clock enable*/
	SAI1LPEN,		/*!< SAI1 clock enable*/
	TIM11LPEN,	/*!< TIM11 clock enable during Sleep mode*/
	TIM10LPEN,	/*!< TIM10 clock enable during Sleep mode*/
	TIM9LPEN,		/*!< TIM9 clock enable during sleep mode*/
	SYSCFGLPEN, /*!< System configuration controller clock enable during Sleep mode*/
	SPI4LPEN,		/*!< SPI 4 clock enable during Sleep mode*/
	SPI1LPEN,		/*!< SPI 1 clock enable during Sleep mode*/
	SDIOLPEN,		/*!< SDIO clock enable during Sleep mode*/
	ADC3LPEN,		/*!< ADC 3 clock enable during Sleep mode*/
	ADC2LPEN,		/*!< ADC2 clock enable during Sleep mode*/
	ADC1LPEN,		/*!< ADC1 clock enable during Sleep mode*/
	USART6LPEN, /*!< USART6 clock enable during Sleep mode*/
	USART1LPEN, /*!< USART1 clock enable during Sleep mode*/
	TIM8LPEN,		/*!< TIM8 clock enable during Sleep mode*/
	TIM1LPEN,		/*!< TIM1 clock enable during Sleep mode*/
};

static constexpr Register<APB2LPENRBitList, APB2LPENRField> APB2LPENR{BASE_ADDR, 0x64U};
/**@}*/

/**
 * @defgroup	RCC_BDCR_GROUP		Backup domain control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BDCRBitList, /**/
					Binary<>{BitPos_t{0}},	// LSEON
					StatusBit<1>{BitPos_t{1}},	// LSERDY
					Binary<>{BitPos_t{2}},	// LSEBYP
					Binary<>{BitPos_t{3}},	// LSEMOD
					Bit<2>{BitPos_t{8}},	// RTCSEL
