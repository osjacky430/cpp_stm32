#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"
#include "cpp_stm32/target/stm32/l4/define/rcc.hxx"

namespace cpp_stm32::rcc::reg {

static constexpr auto BASE_ADDR = 0x40021000U;

/**
 * @defgroup	RCC_CR_GROUP		Clock control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList,														 /**/
										Binary<>{BitPos_t{0}},								 // MSION
										StatusBit<1>{BitPos_t{1}},						 // MSIRDY
										Binary<>{BitPos_t{2}},								 // MSIPLLEN
										Binary<BitMod::WrOnly>{BitPos_t{3}},	 // MSIRGSEL
										Bit<4, MsiRange>{BitPos_t{4}},				 // MSIRANGE
										Binary<>{BitPos_t{8}},								 // HSION
										Binary<>{BitPos_t{9}},								 // HSIKERON
										StatusBit<1>{BitPos_t{10}},						 // HSIRDY
										Binary<>{BitPos_t{11}},								 // HSIASFS
										Binary<>{BitPos_t{16}},								 // HSEON
										StatusBit<1>{BitPos_t{17}},						 // HSERDY
										Binary<>{BitPos_t{18}},								 // HSEBYP
										Binary<BitMod::WrOnly>{BitPos_t{19}},	 // CSSON
										Binary<>{BitPos_t{24}},								 // PLLON
										StatusBit<1>{BitPos_t{25}},						 // PLLRDY
										Binary<>{BitPos_t{26}},								 // PLLSAI1ON
										StatusBit<1>{BitPos_t{27}}						 // PLLSAI1RDY
)

enum class CRField {
	MSION,			/*!< MSI clock enable*/
	MSIRDY,			/*!< MSI clock ready flag*/
	MSIPLLEN,		/*!< MSI clock PLL enable*/
	MSIRGSEL,		/*!< MSI clock range selection*/
	MSIRANGE,		/*!< MSI clock ranges*/
	HSION,			/*!< HSI clock enable*/
	HSIKERON,		/*!< HSI always enable for peripheral kernels*/
	HSIRDY,			/*!< HSI clock ready flag*/
	HSIASFS,		/*!< HSI automatic start from Stop*/
	HSEON,			/*!< HSE clock enable*/
	HSERDY,			/*!< HSE clock ready flag*/
	HSEBYP,			/*!< HSE crystal oscillator bypass*/
	CSSON,			/*!< Clock security system enable*/
	PLLON,			/*!< Main PLL enable*/
	PLLRDY,			/*!< Main PLL clock ready flag*/
	PLLSAI1ON,	/*!< SAI1 PLL enable*/
	PLLSAI1RDY, /*!< SAI1 PLL clock ready flag*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	RCC_ICSCR_GROUP		Internal clock sources calibration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ICSCRBitList,								 /**/
										StatusBit<8>{BitPos_t{0}},	 // MSICAL
										Bit<8>{BitPos_t{8}},				 // MSITRIM
										StatusBit<8>{BitPos_t{16}},	 // HSICAL
										Bit<5>{BitPos_t{24}}				 // HSITRIM
)

enum class ICSCRField {
	MSICAL,	 /*!< MSI clock calibration*/
	MSITRIM, /*!< MSI clock trimming*/
	HSICAL,	 /*!< HSI clock calibration*/
	HSITRIM, /*!< HSI clock trimming*/
};

static constexpr Register<ICSCRBitList, ICSCRField> ICSCR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	RCC_CFGR_GROUP		Clock configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CFGRBitList,												/**/
										Bit<2, SysClk>{BitPos_t{0}},				// SW
										StatusBit<2, SysClk>{BitPos_t{2}},	// SWS
										Bit<4, HPRE>{BitPos_t{4}},					// HPRE
										Bit<3, PPRE>{BitPos_t{8}},					// PPRE1
										Bit<3, PPRE>{BitPos_t{11}},					// PPRE2
										Binary<>{BitPos_t{15}},							// STOPWUCK
										Bit<3>{BitPos_t{24}},								// MCOSEL
										StatusBit<3>{BitPos_t{28}}					// MCOPRE
)

enum class CFGRField {
	SW,				/*!< System clock switch*/
	SWS,			/*!< System clock switch status*/
	HPRE,			/*!< AHB prescaler*/
	PPRE1,		/*!< PB low-speed prescaler (APB1)*/
	PPRE2,		/*!< APB high-speed prescaler (APB2)*/
	STOPWUCK, /*!< Wakeup from Stop and CSS backup clock selection*/
	MCOSEL,		/*!< Microcontroller clock output*/
	MCOPRE,		/*!< Microcontroller clock output prescaler*/
};

static constexpr Register<CFGRBitList, CFGRField> CFGR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	RCC_PLLCFGR_GROUP		PLL configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PLLCFGRBitList,								/**/
										Bit<5>{BitPos_t{27}},					// PLLPDIV
										Bit<2, ClkSrc>{BitPos_t{0}},	// PLLSRC
										Bit<3, PllM>{BitPos_t{4}},		// PLLM
										Bit<7, PllN>{BitPos_t{8}},		// PLLN
										Binary<>{BitPos_t{16}},				// PLLPEN
										Bit<1, PllP>{BitPos_t{17}},		// PLLP
										Binary<>{BitPos_t{20}},				// PLLQEN
										Bit<2, PllQ>{BitPos_t{21}},		// PLLQ
										Binary<>{BitPos_t{24}},				// PLLREN
										Bit<2, PllR>{BitPos_t{25}}		// PLLR
)

enum class PLLCFGRField {
	PLLPDIV, /*!< Main PLL division factor for PLLSAI2CLK*/
	PLLSRC,	 /*!< Main PLL, PLLSAI1 and PLLSAI2 entry clock source*/
	PLLM,		 /*!< Division factor for the main PLL and audio PLL (PLLSAI1 and PLLSAI2) input clock*/
	PLLN,		 /*!< Main PLL multiplication factor for VCO*/
	PLLPEN,	 /*!< Main PLL PLLSAI3CLK output enable*/
	PLLP,		 /*!< Main PLL division factor for PLLSAI3CLK (SAI1 and SAI2 clock)*/
	PLLQEN,	 /*!< Main PLL PLLUSB1CLK output enable*/
	PLLQ,		 /*!< Main PLL division factor for PLLUSB1CLK(48 MHz clock)*/
	PLLREN,	 /*!< Main PLL PLLCLK output enable*/
	PLLR,		 /*!< Main PLL division factor for PLLCLK (system clock)*/
};

static constexpr Register<PLLCFGRBitList, PLLCFGRField> PLLCFGR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	RCC_PLLSAI1CFGR_GROUP		PLLSAI1 configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(PLLSAI1CFGRBitList,			 /**/
										Bit<5>{BitPos_t{27}},		 // PLLSAI1PDIV
										Bit<7>{BitPos_t{8}},		 // PLLSAI1N
										Binary<>{BitPos_t{16}},	 // PLLSAI1PEN
										Binary<>{BitPos_t{17}},	 // PLLSAI1P
										Binary<>{BitPos_t{20}},	 // PLLSAI1QEN
										Bit<2>{BitPos_t{21}},		 // PLLSAI1Q
										Binary<>{BitPos_t{24}},	 // PLLSAI1REN
										Bit<2>{BitPos_t{25}}		 // PLLSAI1R
)

enum class PLLSAI1CFGRField {
	PLLSAI1PDIV, /*!< PLLSAI1 division factor for PLLSAI1CLK*/
	PLLSAI1N,		 /*!< SAI1PLL multiplication factor for VCO*/
	PLLSAI1PEN,	 /*!< SAI1PLL PLLSAI1CLK output enable*/
	PLLSAI1P,		 /*!< SAI1PLL division factor for PLLSAI1CLK (SAI1 or SAI2 clock)*/
	PLLSAI1QEN,	 /*!< SAI1PLL PLLUSB2CLK output enable*/
	PLLSAI1Q,		 /*!< SAI1PLL division factor for PLLUSB2CLK (48 MHz clock)*/
	PLLSAI1REN,	 /*!< PLLSAI1 PLLADC1CLK output enable*/
	PLLSAI1R,		 /*!< PLLSAI1 division factor for PLLADC1CLK (ADC clock)*/
};

static constexpr Register<PLLSAI1CFGRBitList, PLLSAI1CFGRField> PLLSAI1CFGR{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	RCC_CIER_GROUP		Clock interrupt enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CIERBitList,						 /**/
										Binary<>{BitPos_t{10}},	 // HSI48RDYIE
										Binary<>{BitPos_t{0}},	 // LSIRDYIE
										Binary<>{BitPos_t{1}},	 // LSERDYIE
										Binary<>{BitPos_t{2}},	 // MSIRDYIE
										Binary<>{BitPos_t{3}},	 // HSIRDYIE
										Binary<>{BitPos_t{4}},	 // HSERDYIE
										Binary<>{BitPos_t{5}},	 // PLLRDYIE
										Binary<>{BitPos_t{6}},	 // PLLSAI1RDYIE
										Binary<>{BitPos_t{9}}		 // LSECSSIE
)

enum class CIERField {
	HSI48RDYIE,		/*!< HSI48 ready interrupt enable*/
	LSIRDYIE,			/*!< LSI ready interrupt enable*/
	LSERDYIE,			/*!< LSE ready interrupt enable*/
	MSIRDYIE,			/*!< MSI ready interrupt enable*/
	HSIRDYIE,			/*!< HSI ready interrupt enable*/
	HSERDYIE,			/*!< HSE ready interrupt enable*/
	PLLRDYIE,			/*!< PLL ready interrupt enable*/
	PLLSAI1RDYIE, /*!< PLLSAI1 ready interrupt enable*/
	LSECSSIE,			/*!< LSE clock security system interrupt enable*/
};

static constexpr Register<CIERBitList, CIERField> CIER{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	RCC_CIFR_GROUP		Clock interrupt flag register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CIFRBitList,						 /**/
										Binary<>{BitPos_t{10}},	 // HSI48RDYF
										Binary<>{BitPos_t{0}},	 // LSIRDYF
										Binary<>{BitPos_t{1}},	 // LSERDYF
										Binary<>{BitPos_t{2}},	 // MSIRDYF
										Binary<>{BitPos_t{3}},	 // HSIRDYF
										Binary<>{BitPos_t{4}},	 // HSERDYF
										Binary<>{BitPos_t{5}},	 // PLLRDYF
										Binary<>{BitPos_t{6}},	 // PLLSAI1RDYF
										Binary<>{BitPos_t{8}},	 // CSSF
										Binary<>{BitPos_t{9}}		 // LSECSSF
)

enum class CIFRField {
	HSI48RDYF,	 /*!< HSI48 ready interrupt flag*/
	LSIRDYF,		 /*!< LSI ready interrupt flag*/
	LSERDYF,		 /*!< LSE ready interrupt flag*/
	MSIRDYF,		 /*!< MSI ready interrupt flag*/
	HSIRDYF,		 /*!< HSI ready interrupt flag*/
	HSERDYF,		 /*!< HSE ready interrupt flag*/
	PLLRDYF,		 /*!< PLL ready interrupt flag*/
	PLLSAI1RDYF, /*!< PLLSAI1 ready interrupt flag*/
	CSSF,				 /*!< Clock security system interrupt flag*/
	LSECSSF,		 /*!< LSE Clock security system interrupt flag*/
};

static constexpr Register<CIFRBitList, CIFRField> CIFR{BASE_ADDR, 0x1cU};
/**@}*/

/**
 * @defgroup	RCC_CICR_GROUP		Clock interrupt clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CICRBitList,						 /**/
										Binary<>{BitPos_t{10}},	 // HSI48RDYC
										Binary<>{BitPos_t{0}},	 // LSIRDYC
										Binary<>{BitPos_t{1}},	 // LSERDYC
										Binary<>{BitPos_t{2}},	 // MSIRDYC
										Binary<>{BitPos_t{3}},	 // HSIRDYC
										Binary<>{BitPos_t{4}},	 // HSERDYC
										Binary<>{BitPos_t{5}},	 // PLLRDYC
										Binary<>{BitPos_t{6}},	 // PLLSAI1RDYC
										Binary<>{BitPos_t{8}},	 // CSSC
										Binary<>{BitPos_t{9}}		 // LSECSSC
)

enum class CICRField {
	HSI48RDYC,	 /*!< HSI48 oscillator ready interrupt clear*/
	LSIRDYC,		 /*!< LSI ready interrupt clear*/
	LSERDYC,		 /*!< LSE ready interrupt clear*/
	MSIRDYC,		 /*!< MSI ready interrupt clear*/
	HSIRDYC,		 /*!< HSI ready interrupt clear*/
	HSERDYC,		 /*!< HSE ready interrupt clear*/
	PLLRDYC,		 /*!< PLL ready interrupt clear*/
	PLLSAI1RDYC, /*!< PLLSAI1 ready interrupt clear*/
	CSSC,				 /*!< Clock security system interrupt clear*/
	LSECSSC,		 /*!< LSE Clock security system interrupt clear*/
};

static constexpr Register<CICRBitList, CICRField> CICR{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	RCC_AHB1RSTR_GROUP		AHB1 peripheral reset register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB1RSTRBitList,				 /**/
										Binary<>{BitPos_t{0}},	 // DMA1RST
										Binary<>{BitPos_t{1}},	 // DMA2RST
										Binary<>{BitPos_t{8}},	 // FLASHRST
										Binary<>{BitPos_t{11}},	 // CRCRST
										Binary<>{BitPos_t{16}}	 // TSCRST
)

enum class AHB1RSTRField {
	DMA1RST,	/*!< DMA1 reset*/
	DMA2RST,	/*!< DMA2 reset*/
	FLASHRST, /*!< Flash memory interface reset*/
	CRCRST,		/*!< CRC reset*/
	TSCRST,		/*!< Touch Sensing Controller reset*/
};

static constexpr Register<AHB1RSTRBitList, AHB1RSTRField> AHB1RSTR{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	RCC_AHB2RSTR_GROUP		AHB2 peripheral reset register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB2RSTRBitList,				 /**/
										Binary<>{BitPos_t{0}},	 // GPIOARST
										Binary<>{BitPos_t{1}},	 // GPIOBRST
										Binary<>{BitPos_t{2}},	 // GPIOCRST
										Binary<>{BitPos_t{3}},	 // GPIODRST
										Binary<>{BitPos_t{4}},	 // GPIOERST
										Binary<>{BitPos_t{7}},	 // GPIOHRST
										Binary<>{BitPos_t{13}},	 // ADCRST
										Binary<>{BitPos_t{16}},	 // AESRST
										Binary<>{BitPos_t{18}}	 // RNGRST
)

enum class AHB2RSTRField {
	GPIOARST, /*!< IO port A reset*/
	GPIOBRST, /*!< IO port B reset*/
	GPIOCRST, /*!< IO port C reset*/
	GPIODRST, /*!< IO port D reset*/
	GPIOERST, /*!< IO port E reset*/
	GPIOHRST, /*!< IO port H reset*/
	ADCRST,		/*!< ADC reset*/
	AESRST,		/*!< AES hardware accelerator reset*/
	RNGRST,		/*!< Random number generator reset*/
};

static constexpr Register<AHB2RSTRBitList, AHB2RSTRField> AHB2RSTR{BASE_ADDR, 0x2cU};
/**@}*/

/**
 * @defgroup	RCC_AHB3RSTR_GROUP		AHB3 peripheral reset register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB3RSTRBitList,			 /**/
										Binary<>{BitPos_t{8}}	 // QSPIRST
)

enum class AHB3RSTRField {
	QSPIRST, /*!< Quad SPI memory interface reset*/
};

static constexpr Register<AHB3RSTRBitList, AHB3RSTRField> AHB3RSTR{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	RCC_APB1RSTR1_GROUP		APB1 peripheral reset register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB1RSTR1BitList,				 /**/
										Binary<>{BitPos_t{26}},	 // USBFSRST
										Binary<>{BitPos_t{24}},	 // CRSRST
										Binary<>{BitPos_t{22}},	 // I2C2RST
										Binary<>{BitPos_t{19}},	 // USART4RST
										Binary<>{BitPos_t{0}},	 // TIM2RST
										Binary<>{BitPos_t{4}},	 // TIM6RST
										Binary<>{BitPos_t{5}},	 // TIM7RST
										Binary<>{BitPos_t{9}},	 // LCDRST
										Binary<>{BitPos_t{14}},	 // SPI2RST
										Binary<>{BitPos_t{15}},	 // SPI3RST
										Binary<>{BitPos_t{17}},	 // USART2RST
										Binary<>{BitPos_t{18}},	 // USART1RST
										Binary<>{BitPos_t{21}},	 // I2C1RST
										Binary<>{BitPos_t{23}},	 // I2C3RST
										Binary<>{BitPos_t{25}},	 // CAN1RST
										Binary<>{BitPos_t{28}},	 // PWRRST
										Binary<>{BitPos_t{29}},	 // DAC1RST
										Binary<>{BitPos_t{30}},	 // OPAMPRST
										Binary<>{BitPos_t{31}}	 // LPTIM1RST
)

enum class APB1RSTR1Field {
	USBFSRST,	 /*!< USB FS reset*/
	CRSRST,		 /*!< CRS reset*/
	I2C2RST,	 /*!< I2C2 reset*/
	USART4RST, /*!< USART4 reset.*/
	TIM2RST,	 /*!< TIM2 timer reset*/
	TIM6RST,	 /*!< TIM6 timer reset*/
	TIM7RST,	 /*!< TIM7 timer reset*/
	LCDRST,		 /*!< LCD interface reset*/
	SPI2RST,	 /*!< SPI2 reset*/
	SPI3RST,	 /*!< SPI3 reset*/
	USART2RST, /*!< USART2 reset*/
	USART1RST, /*!< USART1 reset*/
	I2C1RST,	 /*!< I2C1 reset*/
	I2C3RST,	 /*!< I2C3 reset*/
	CAN1RST,	 /*!< CAN1 reset*/
	PWRRST,		 /*!< Power interface reset*/
	DAC1RST,	 /*!< DAC1 interface reset*/
	OPAMPRST,	 /*!< OPAMP interface reset*/
	LPTIM1RST, /*!< Low Power Timer 1 reset*/
};

static constexpr Register<APB1RSTR1BitList, APB1RSTR1Field> APB1RSTR1{BASE_ADDR, 0x38U};
/**@}*/

/**
 * @defgroup	RCC_APB1RSTR2_GROUP		APB1 peripheral reset register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB1RSTR2BitList,				/**/
										Binary<>{BitPos_t{1}},	// I2C4RST
										Binary<>{BitPos_t{0}},	// LPUART1RST
										Binary<>{BitPos_t{2}},	// SWPMI1RST
										Binary<>{BitPos_t{5}}		// LPTIM2RST
)

enum class APB1RSTR2Field {
	I2C4RST,		/*!< I2C4 reset*/
	LPUART1RST, /*!< Low-power UART 1 reset*/
	SWPMI1RST,	/*!< Single wire protocol reset*/
	LPTIM2RST,	/*!< Low-power timer 2 reset*/
};

static constexpr Register<APB1RSTR2BitList, APB1RSTR2Field> APB1RSTR2{BASE_ADDR, 0x3cU};
/**@}*/

/**
 * @defgroup	RCC_APB2RSTR_GROUP		APB2 peripheral reset register group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB2RSTRBitList,				 /**/
										Binary<>{BitPos_t{24}},	 // DFSDMRST
										Binary<>{BitPos_t{0}},	 // SYSCFGRST
										Binary<>{BitPos_t{10}},	 // SDMMCRST
										Binary<>{BitPos_t{11}},	 // TIM1RST
										Binary<>{BitPos_t{12}},	 // SPI1RST
										Binary<>{BitPos_t{14}},	 // USART1RST
										Binary<>{BitPos_t{16}},	 // TIM15RST
										Binary<>{BitPos_t{17}},	 // TIM16RST
										Binary<>{BitPos_t{21}}	 // SAI1RST
)

enum class APB2RSTRField {
	DFSDMRST,	 /*!< DFSDM filter reset*/
	SYSCFGRST, /*!< System configuration (SYSCFG) reset*/
	SDMMCRST,	 /*!< SDMMC reset*/
	TIM1RST,	 /*!< TIM1 timer reset*/
	SPI1RST,	 /*!< SPI1 reset*/
	USART1RST, /*!< USART1 reset*/
	TIM15RST,	 /*!< TIM15 timer reset*/
	TIM16RST,	 /*!< TIM16 timer reset*/
	SAI1RST,	 /*!< Serial audio interface 1 (SAI1) reset*/
};

static constexpr Register<APB2RSTRBitList, APB2RSTRField> APB2RSTR{BASE_ADDR, 0x40U};
/**@}*/

/**
 * @defgroup	RCC_AHB1ENR_GROUP		AHB1 peripheral clock enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB1ENRBitList,					 /**/
										Binary<>{BitPos_t{0}},	 // DMA1EN
										Binary<>{BitPos_t{1}},	 // DMA2EN
										Binary<>{BitPos_t{8}},	 // FLASHEN
										Binary<>{BitPos_t{12}},	 // CRCEN
										Binary<>{BitPos_t{16}}	 // TSCEN
)

enum class AHB1ENRField {
	DMA1EN,	 /*!< DMA1 clock enable*/
	DMA2EN,	 /*!< DMA2 clock enable*/
	FLASHEN, /*!< Flash memory interface clock enable*/
	CRCEN,	 /*!< CRC clock enable*/
	TSCEN,	 /*!< Touch Sensing Controller clock enable*/
};

static constexpr Register<AHB1ENRBitList, AHB1ENRField> AHB1ENR{BASE_ADDR, 0x48U};
/**@}*/

/**
 * @defgroup	RCC_AHB2ENR_GROUP		AHB2 peripheral clock enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB2ENRBitList,					 /**/
										Binary<>{BitPos_t{0}},	 // GPIOAEN
										Binary<>{BitPos_t{1}},	 // GPIOBEN
										Binary<>{BitPos_t{2}},	 // GPIOCEN
										Binary<>{BitPos_t{3}},	 // GPIODEN
										Binary<>{BitPos_t{4}},	 // GPIOEEN
										Binary<>{BitPos_t{7}},	 // GPIOHEN
										Binary<>{BitPos_t{13}},	 // ADCEN
										Binary<>{BitPos_t{16}},	 // AESEN
										Binary<>{BitPos_t{18}}	 // RNGEN
)

enum class AHB2ENRField {
	GPIOAEN, /*!< IO port A clock enable*/
	GPIOBEN, /*!< IO port B clock enable*/
	GPIOCEN, /*!< IO port C clock enable*/
	GPIODEN, /*!< IO port D clock enable*/
	GPIOEEN, /*!< IO port E clock enable*/
	GPIOHEN, /*!< IO port H clock enable*/
	ADCEN,	 /*!< ADC clock enable*/
	AESEN,	 /*!< AES accelerator clock enable*/
	RNGEN,	 /*!< Random Number Generator clock enable*/
};

static constexpr Register<AHB2ENRBitList, AHB2ENRField> AHB2ENR{BASE_ADDR, 0x4cU};
/**@}*/

/**
 * @defgroup	RCC_AHB3ENR_GROUP		AHB3 peripheral clock enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB3ENRBitList,				 /**/
										Binary<>{BitPos_t{8}}	 // QSPIEN
)

enum class AHB3ENRField {
	QSPIEN, /*!< QSPIEN*/
};

static constexpr Register<AHB3ENRBitList, AHB3ENRField> AHB3ENR{BASE_ADDR, 0x50U};
/**@}*/

/**
 * @defgroup	RCC_APB1ENR1_GROUP		APB1ENR1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB1ENR1BitList,				 /**/
										Binary<>{BitPos_t{22}},	 // I2C2EN
										Binary<>{BitPos_t{19}},	 // UART4EN
										Binary<>{BitPos_t{1}},	 // TIM3EN
										Binary<>{BitPos_t{26}},	 // USBF
										Binary<>{BitPos_t{24}},	 // CRSEN
										Binary<>{BitPos_t{10}},	 // RTCAPBEN
										Binary<>{BitPos_t{0}},	 // TIM2EN
										Binary<>{BitPos_t{4}},	 // TIM6EN
										Binary<>{BitPos_t{5}},	 // TIM7EN
										Binary<>{BitPos_t{9}},	 // LCDEN
										Binary<>{BitPos_t{11}},	 // WWDGEN
										Binary<>{BitPos_t{14}},	 // SPI1EN
										Binary<>{BitPos_t{15}},	 // SPI3EN
										Binary<>{BitPos_t{17}},	 // USART2EN
										Binary<>{BitPos_t{18}},	 // USART1EN
										Binary<>{BitPos_t{21}},	 // I2C1EN
										Binary<>{BitPos_t{23}},	 // I2C3EN
										Binary<>{BitPos_t{25}},	 // CAN1EN
										Binary<>{BitPos_t{28}},	 // PWREN
										Binary<>{BitPos_t{29}},	 // DAC1EN
										Binary<>{BitPos_t{30}},	 // OPAMPEN
										Binary<>{BitPos_t{31}}	 // LPTIM1EN
)

enum class APB1ENR1Field {
	I2C2EN,		/*!< I2C2 clock enable*/
	UART4EN,	/*!< UART4 clock enable*/
	TIM3EN,		/*!< TIM3 timer clock enable*/
	USBF,			/*!< USB FS clock enable*/
	CRSEN,		/*!< CRS clock enable*/
	RTCAPBEN, /*!< RTC APB clock enable*/
	TIM2EN,		/*!< TIM2 timer clock enable*/
	TIM6EN,		/*!< TIM6 timer clock enable*/
	TIM7EN,		/*!< TIM7 timer clock enable*/
	LCDEN,		/*!< LCD clock enable*/
	WWDGEN,		/*!< Window watchdog clock enable*/
	SPI1EN,		/*!< SPI1 clock enable*/
	SPI3EN,		/*!< SPI3 clock enable*/
	USART2EN, /*!< USART2 clock enable*/
	USART1EN, /*!< USART1 clock enable*/
	I2C1EN,		/*!< I2C1 clock enable*/
	I2C3EN,		/*!< I2C3 clock enable*/
	CAN1EN,		/*!< CAN1 clock enable*/
	PWREN,		/*!< Power interface clock enable*/
	DAC1EN,		/*!< DAC1 interface clock enable*/
	OPAMPEN,	/*!< OPAMP interface clock enable*/
	LPTIM1EN, /*!< Low power timer 1 clock enable*/
};

static constexpr Register<APB1ENR1BitList, APB1ENR1Field> APB1ENR1{BASE_ADDR, 0x58U};
/**@}*/

/**
 * @defgroup	RCC_APB1ENR2_GROUP		APB1 peripheral clock enable register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB1ENR2BitList,				 /**/
										Binary<>{BitPos_t{1}},	 // I2C4EN
										Binary<>{BitPos_t{24}},	 // DFSDMEN
										Binary<>{BitPos_t{0}},	 // LPUART1EN
										Binary<>{BitPos_t{2}},	 // SWPMI1EN
										Binary<>{BitPos_t{5}}		 // LPTIM2EN
)

enum class APB1ENR2Field {
	I2C4EN,		 /*!< I2C4 clock enable*/
	DFSDMEN,	 /*!< DFSDMEN enable*/
	LPUART1EN, /*!< Low power UART 1 clock enable*/
	SWPMI1EN,	 /*!< Single wire protocol clock enable*/
	LPTIM2EN,	 /*!< LPTIM2EN*/
};

static constexpr Register<APB1ENR2BitList, APB1ENR2Field> APB1ENR2{BASE_ADDR, 0x5cU};
/**@}*/

/**
 * @defgroup	RCC_APB2ENR_GROUP		APB2ENR group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB2ENRBitList,					 /**/
										Binary<>{BitPos_t{0}},	 // SYSCFGEN
										Binary<>{BitPos_t{7}},	 // FIREWALLEN
										Binary<>{BitPos_t{10}},	 // SDMMCEN
										Binary<>{BitPos_t{11}},	 // TIM1EN
										Binary<>{BitPos_t{12}},	 // SPI1EN
										Binary<>{BitPos_t{14}},	 // USART1EN
										Binary<>{BitPos_t{16}},	 // TIM15EN
										Binary<>{BitPos_t{17}},	 // TIM16EN
										Binary<>{BitPos_t{21}}	 // SAI1EN
)

enum class APB2ENRField {
	SYSCFGEN,		/*!< SYSCFG clock enable*/
	FIREWALLEN, /*!< Firewall clock enable*/
	SDMMCEN,		/*!< SDMMC clock enable*/
	TIM1EN,			/*!< TIM1 timer clock enable*/
	SPI1EN,			/*!< SPI1 clock enable*/
	USART1EN,		/*!< USART1clock enable*/
	TIM15EN,		/*!< TIM15 timer clock enable*/
	TIM16EN,		/*!< TIM16 timer clock enable*/
	SAI1EN,			/*!< SAI1 clock enable*/
};

static constexpr Register<APB2ENRBitList, APB2ENRField> APB2ENR{BASE_ADDR, 0x60U};
/**@}*/

/**
 * @defgroup	RCC_AHB1SMENR_GROUP		AHB1 peripheral clocks enable in Sleep and Stop modes register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB1SMENRBitList,				 /**/
										Binary<>{BitPos_t{0}},	 // DMA1SMEN
										Binary<>{BitPos_t{1}},	 // DMA2SMEN
										Binary<>{BitPos_t{8}},	 // FLASHSMEN
										Binary<>{BitPos_t{9}},	 // SRAM1SMEN
										Binary<>{BitPos_t{12}},	 // CRCSMEN
										Binary<>{BitPos_t{16}}	 // TSCSMEN
)

enum class AHB1SMENRField {
	DMA1SMEN,	 /*!< DMA1 clocks enable during Sleep and Stop modes*/
	DMA2SMEN,	 /*!< DMA2 clocks enable during Sleep and Stop modes*/
	FLASHSMEN, /*!< Flash memory interface clocks enable during Sleep and Stop modes*/
	SRAM1SMEN, /*!< SRAM1 interface clocks enable during Sleep and Stop modes*/
	CRCSMEN,	 /*!< CRCSMEN*/
	TSCSMEN,	 /*!< Touch Sensing Controller clocks enable during Sleep and Stop modes*/
};

static constexpr Register<AHB1SMENRBitList, AHB1SMENRField> AHB1SMENR{BASE_ADDR, 0x68U};
/**@}*/

/**
 * @defgroup	RCC_AHB2SMENR_GROUP		AHB2 peripheral clocks enable in Sleep and Stop modes register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB2SMENRBitList,				 /**/
										Binary<>{BitPos_t{0}},	 // GPIOASMEN
										Binary<>{BitPos_t{1}},	 // GPIOBSMEN
										Binary<>{BitPos_t{2}},	 // GPIOCSMEN
										Binary<>{BitPos_t{3}},	 // GPIODSMEN
										Binary<>{BitPos_t{4}},	 // GPIOESMEN
										Binary<>{BitPos_t{7}},	 // GPIOHSMEN
										Binary<>{BitPos_t{9}},	 // SRAM2SMEN
										Binary<>{BitPos_t{13}},	 // ADCFSSMEN
										Binary<>{BitPos_t{16}},	 // AESSMEN
										Binary<>{BitPos_t{18}}	 // RNGSMEN
)

enum class AHB2SMENRField {
	GPIOASMEN, /*!< IO port A clocks enable during Sleep and Stop modes*/
	GPIOBSMEN, /*!< IO port B clocks enable during Sleep and Stop modes*/
	GPIOCSMEN, /*!< IO port C clocks enable during Sleep and Stop modes*/
	GPIODSMEN, /*!< IO port D clocks enable during Sleep and Stop modes*/
	GPIOESMEN, /*!< IO port E clocks enable during Sleep and Stop modes*/
	GPIOHSMEN, /*!< IO port H clocks enable during Sleep and Stop modes*/
	SRAM2SMEN, /*!< SRAM2 interface clocks enable during Sleep and Stop modes*/
	ADCFSSMEN, /*!< ADC clocks enable during Sleep and Stop modes*/
	AESSMEN,	 /*!< AES accelerator clocks enable during Sleep and Stop modes*/
	RNGSMEN,	 /*!< Random Number Generator clocks enable during Sleep and Stop modes*/
};

static constexpr Register<AHB2SMENRBitList, AHB2SMENRField> AHB2SMENR{BASE_ADDR, 0x6cU};
/**@}*/

/**
 * @defgroup	RCC_AHB3SMENR_GROUP		AHB3 peripheral clocks enable in Sleep and Stop modes register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AHB3SMENRBitList,			 /**/
										Binary<>{BitPos_t{8}}	 // QSPISMEN
)

enum class AHB3SMENRField {
	QSPISMEN, /*!< QSPISMEN*/
};

static constexpr Register<AHB3SMENRBitList, AHB3SMENRField> AHB3SMENR{BASE_ADDR, 0x70U};
/**@}*/

/**
 * @defgroup	RCC_APB1SMENR1_GROUP		APB1SMENR1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB1SMENR1BitList,			 /**/
										Binary<>{BitPos_t{24}},	 // CRSSMEN
										Binary<>{BitPos_t{22}},	 // I2C2SMEN
										Binary<>{BitPos_t{26}},	 // USBFSSMEN
										Binary<>{BitPos_t{10}},	 // RTCAPBSMEN
										Binary<>{BitPos_t{0}},	 // TIM2SMEN
										Binary<>{BitPos_t{4}},	 // TIM6SMEN
										Binary<>{BitPos_t{5}},	 // TIM7SMEN
										Binary<>{BitPos_t{9}},	 // LCDSMEN
										Binary<>{BitPos_t{11}},	 // WWDGSMEN
										Binary<>{BitPos_t{14}},	 // SPI2SMEN
										Binary<>{BitPos_t{15}},	 // SP3SMEN
										Binary<>{BitPos_t{17}},	 // USART1SMEN
										Binary<>{BitPos_t{18}},	 // USART2SMEN
										Binary<>{BitPos_t{21}},	 // I2C1SMEN
										Binary<>{BitPos_t{23}},	 // I2C3SMEN
										Binary<>{BitPos_t{25}},	 // CAN1SMEN
										Binary<>{BitPos_t{28}},	 // PWRSMEN
										Binary<>{BitPos_t{29}},	 // DAC1SMEN
										Binary<>{BitPos_t{30}},	 // OPAMPSMEN
										Binary<>{BitPos_t{31}}	 // LPTIM1SMEN
)

enum class APB1SMENR1Field {
	CRSSMEN,		/*!< CRS clock enable during Sleep and Stop modes*/
	I2C2SMEN,		/*!< I2C2 clocks enable during Sleep and Stop modes*/
	USBFSSMEN,	/*!< USB FS clock enable during Sleep and Stop modes*/
	RTCAPBSMEN, /*!< RTC APB clock enable during Sleep and Stop modes*/
	TIM2SMEN,		/*!< TIM2 timer clocks enable during Sleep and Stop modes*/
	TIM6SMEN,		/*!< TIM6 timer clocks enable during Sleep and Stop modes*/
	TIM7SMEN,		/*!< TIM7 timer clocks enable during Sleep and Stop modes*/
	LCDSMEN,		/*!< LCD clocks enable during Sleep and Stop modes*/
	WWDGSMEN,		/*!< Window watchdog clocks enable during Sleep and Stop modes*/
	SPI2SMEN,		/*!< SPI2 clocks enable during Sleep and Stop modes*/
	SP3SMEN,		/*!< SPI3 clocks enable during Sleep and Stop modes*/
	USART1SMEN, /*!< USART1 clocks enable during Sleep and Stop modes*/
	USART2SMEN, /*!< USART2 clocks enable during Sleep and Stop modes*/
	I2C1SMEN,		/*!< I2C1 clocks enable during Sleep and Stop modes*/
	I2C3SMEN,		/*!< I2C3 clocks enable during Sleep and Stop modes*/
	CAN1SMEN,		/*!< CAN1 clocks enable during Sleep and Stop modes*/
	PWRSMEN,		/*!< Power interface clocks enable during Sleep and Stop modes*/
	DAC1SMEN,		/*!< DAC1 interface clocks enable during Sleep and Stop modes*/
	OPAMPSMEN,	/*!< OPAMP interface clocks enable during Sleep and Stop modes*/
	LPTIM1SMEN, /*!< Low power timer 1 clocks enable during Sleep and Stop modes*/
};

static constexpr Register<APB1SMENR1BitList, APB1SMENR1Field> APB1SMENR1{BASE_ADDR, 0x78U};
/**@}*/

/**
 * @defgroup	RCC_APB1SMENR2_GROUP		APB1 peripheral clocks enable in Sleep and Stop modes register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB1SMENR2BitList,			/**/
										Binary<>{BitPos_t{0}},	// LPUART1SMEN
										Binary<>{BitPos_t{2}},	// SWPMI1SMEN
										Binary<>{BitPos_t{5}}		// LPTIM2SMEN
)

enum class APB1SMENR2Field {
	LPUART1SMEN, /*!< Low power UART 1 clocks enable during Sleep and Stop modes*/
	SWPMI1SMEN,	 /*!< Single wire protocol clocks enable during Sleep and Stop modes*/
	LPTIM2SMEN,	 /*!< LPTIM2SMEN*/
};

static constexpr Register<APB1SMENR2BitList, APB1SMENR2Field> APB1SMENR2{BASE_ADDR, 0x7cU};
/**@}*/

/**
 * @defgroup	RCC_APB2SMENR_GROUP		APB2SMENR group
 *
 * @{
 */

SETUP_REGISTER_INFO(APB2SMENRBitList,				 /**/
										Binary<>{BitPos_t{0}},	 // SYSCFGSMEN
										Binary<>{BitPos_t{10}},	 // SDMMCSMEN
										Binary<>{BitPos_t{11}},	 // TIM1SMEN
										Binary<>{BitPos_t{12}},	 // SPI1SMEN
										Binary<>{BitPos_t{14}},	 // USART1SMEN
										Binary<>{BitPos_t{16}},	 // TIM15SMEN
										Binary<>{BitPos_t{17}},	 // TIM16SMEN
										Binary<>{BitPos_t{21}}	 // SAI1SMEN
)

enum class APB2SMENRField {
	SYSCFGSMEN, /*!< SYSCFG clocks enable during Sleep and Stop modes*/
	SDMMCSMEN,	/*!< SDMMC clocks enable during Sleep and Stop modes*/
	TIM1SMEN,		/*!< TIM1 timer clocks enable during Sleep and Stop modes*/
	SPI1SMEN,		/*!< SPI1 clocks enable during Sleep and Stop modes*/
	USART1SMEN, /*!< USART1clocks enable during Sleep and Stop modes*/
	TIM15SMEN,	/*!< TIM15 timer clocks enable during Sleep and Stop modes*/
	TIM16SMEN,	/*!< TIM16 timer clocks enable during Sleep and Stop modes*/
	SAI1SMEN,		/*!< SAI1 clocks enable during Sleep and Stop modes*/
};

static constexpr Register<APB2SMENRBitList, APB2SMENRField> APB2SMENR{BASE_ADDR, 0x80U};
/**@}*/

/**
 * @defgroup	RCC_CCIPR_GROUP		CCIPR group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCIPRBitList,						/**/
										Bit<2>{BitPos_t{14}},		// I2C2SEL
										Bit<2>{BitPos_t{4}},		// USART3SEL
										Bit<2>{BitPos_t{6}},		// USART4SEL
										Bit<2>{BitPos_t{0}},		// USART1SEL
										Bit<2>{BitPos_t{2}},		// USART2SEL
										Bit<2>{BitPos_t{10}},		// LPUART1SEL
										Bit<2>{BitPos_t{12}},		// I2C1SEL
										Bit<2>{BitPos_t{16}},		// I2C3SEL
										Bit<2>{BitPos_t{18}},		// LPTIM1SEL
										Bit<2>{BitPos_t{20}},		// LPTIM2SEL
										Bit<2>{BitPos_t{22}},		// SAI1SEL
										Bit<2>{BitPos_t{26}},		// CLK48SEL
										Bit<2>{BitPos_t{28}},		// ADCSEL
										Binary<>{BitPos_t{30}}	// SWPMI1SEL
)

enum class CCIPRField {
	I2C2SEL,		/*!< I2C2 clock source selection*/
	USART3SEL,	/*!< USART3 clock source selection*/
	USART4SEL,	/*!< USART4 clock source selection*/
	USART1SEL,	/*!< USART1 clock source selection*/
	USART2SEL,	/*!< USART2 clock source selection*/
	LPUART1SEL, /*!< LPUART1 clock source selection*/
	I2C1SEL,		/*!< I2C1 clock source selection*/
	I2C3SEL,		/*!< I2C3 clock source selection*/
	LPTIM1SEL,	/*!< Low power timer 1 clock source selection*/
	LPTIM2SEL,	/*!< Low power timer 2 clock source selection*/
	SAI1SEL,		/*!< SAI1 clock source selection*/
	CLK48SEL,		/*!< 48 MHz clock source selection*/
	ADCSEL,			/*!< ADCs clock source selection*/
	SWPMI1SEL,	/*!< SWPMI1 clock source selection*/
};

static constexpr Register<CCIPRBitList, CCIPRField> CCIPR{BASE_ADDR, 0x88U};
/**@}*/

/**
 * @defgroup	RCC_BDCR_GROUP		BDCR group
 *
 * @{
 */

SETUP_REGISTER_INFO(BDCRBitList,								/**/
										Binary<>{BitPos_t{0}},			// LSEON
										StatusBit<1>{BitPos_t{1}},	// LSERDY
										Binary<>{BitPos_t{2}},			// LSEBYP
										Bit<2>{BitPos_t{3}},				// LSEDRV
										Binary<>{BitPos_t{5}},			// LSECSSON
										StatusBit<1>{BitPos_t{6}},	// LSECSSD
										Bit<2>{BitPos_t{8}},				// RTCSEL
										Binary<>{BitPos_t{15}},			// RTCEN
										Binary<>{BitPos_t{16}},			// BDRST
										Binary<>{BitPos_t{24}},			// LSCOEN
										Binary<>{BitPos_t{25}}			// LSCOSEL
)

enum class BDCRField {
	LSEON,		/*!< LSE oscillator enable*/
	LSERDY,		/*!< LSE oscillator ready*/
	LSEBYP,		/*!< LSE oscillator bypass*/
	LSEDRV,		/*!< SE oscillator drive capability*/
	LSECSSON, /*!< LSECSSON*/
	LSECSSD,	/*!< LSECSSD*/
	RTCSEL,		/*!< RTC clock source selection*/
	RTCEN,		/*!< RTC clock enable*/
	BDRST,		/*!< Backup domain software reset*/
	LSCOEN,		/*!< Low speed clock output enable*/
	LSCOSEL,	/*!< Low speed clock output selection*/
};

static constexpr Register<BDCRBitList, BDCRField> BDCR{BASE_ADDR, 0x90U};
/**@}*/

/**
 * @defgroup	RCC_CSR_GROUP		CSR group
 *
 * @{
 */

SETUP_REGISTER_INFO(CSRBitList,									 /**/
										Binary<>{BitPos_t{0}},			 // LSION
										StatusBit<1>{BitPos_t{1}},	 // LSIRDY
										Bit<4>{BitPos_t{8}},				 // MSISRANGE
										Binary<>{BitPos_t{23}},			 // RMVF
										StatusBit<1>{BitPos_t{24}},	 // FIREWALLRSTF
										StatusBit<1>{BitPos_t{25}},	 // OBLRSTF
										StatusBit<1>{BitPos_t{26}},	 // PINRSTF
										StatusBit<1>{BitPos_t{27}},	 // BORRSTF
										StatusBit<1>{BitPos_t{28}},	 // SFTRSTF
										StatusBit<1>{BitPos_t{29}},	 // IWDGRSTF
										StatusBit<1>{BitPos_t{30}},	 // WWDGRSTF
										StatusBit<1>{BitPos_t{31}}	 // LPWRSTF
)

enum class CSRField {
	LSION,				/*!< LSI oscillator enable*/
	LSIRDY,				/*!< LSI oscillator ready*/
	MSISRANGE,		/*!< SI range after Standby mode*/
	RMVF,					/*!< Remove reset flag*/
	FIREWALLRSTF, /*!< Firewall reset flag*/
	OBLRSTF,			/*!< Option byte loader reset flag*/
	PINRSTF,			/*!< Pin reset flag*/
	BORRSTF,			/*!< BOR flag*/
	SFTRSTF,			/*!< Software reset flag*/
	IWDGRSTF,			/*!< Independent window watchdog reset flag*/
	WWDGRSTF,			/*!< Window watchdog reset flag*/
	LPWRSTF,			/*!< Low-power reset flag*/
};

static constexpr Register<CSRBitList, CSRField> CSR{BASE_ADDR, 0x94U};
/**@}*/

/**
 * @defgroup	RCC_CRRCR_GROUP		Clock recovery RC register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRRCRBitList,																/**/
										StatusBit<9, std ::uint16_t>{BitPos_t{7}},	// HSI48CAL
										StatusBit<1>{BitPos_t{1}},									// HSI48RDY
										Binary<>{BitPos_t{0}}												// HSI48ON
)

enum class CRRCRField {
	HSI48CAL, /*!< HSI48 clock calibration*/
	HSI48RDY, /*!< HSI48 clock ready flag*/
	HSI48ON,	/*!< HSI48 clock enable*/
};

static constexpr Register<CRRCRBitList, CRRCRField> CRRCR{BASE_ADDR, 0x98U};
/**@}*/

}	 // namespace cpp_stm32::rcc::reg
