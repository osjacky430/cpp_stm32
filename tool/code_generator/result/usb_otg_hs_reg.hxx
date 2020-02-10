#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::usb_otg_hs::reg {

static constexpr auto BASE_ADDR(Port const& t_usb_otg_hs) {
	case Port::OTG_HS_GLOBAL:
		return 0x40040000U;
	case Port::OTG_HS_HOST:
		return 0x40040400U;
	case Port::OTG_HS_DEVICE:
		return 0x40040800U;
	case Port::OTG_HS_PWRCLK:
		return 0x40040e00U;
}

/**
 * @defgroup	OTG_HS_PWRCLK_OTG_HS_PCGCR_GROUP		Power and clock gating control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(OTG_HS_PCGCRBitList, /**/
					Binary<>{BitPos_t{4}},	// PHYSUSP
					Binary<>{BitPos_t{1}},	// GATEHCLK
					Binary<>{BitPos_t{0}}	// STPPCLK
					)

enum class OTG_HS_PCGCRField {
	PHYSUSP,		/*!< PHY suspended*/
	GATEHCLK,		/*!< Gate HCLK*/
	STPPCLK,		/*!< Stop PHY clock*/
};

template <Port USB_OTG_HS>
static constexpr Register<OTG_HS_PCGCRBitList, OTG_HS_PCGCRField> OTG_HS_PCGCR{BASE_ADDR(USB_OTG_HS), 0x00U};
/**@}*/


} // cpp_stm32::usb_otg_hs::reg
