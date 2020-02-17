#pragma once

// @TODO need to deal with false case
#define COMPILE_TIME_CLOCK_CONFIG true /*!< If the project doesn't change clock speed during runtime, set to true*/

#define MHz *1000000U

#define HSE_CLK_FREQ (8 MHz)
#define HSI_CLK_FREQ (16 MHz)
#define SYS_CLK_FREQ (180 MHz)
#define AHB_CLK_FREQ (180 MHz)
#define APB1_CLK_FREQ (45 MHz)
#define APB2_CLK_FREQ (90 MHz)

#define HSE_BYPASS_CLK_SRC true
