#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::usb_otg_fs::reg {

static constexpr auto BASE_ADDR(Port const& t_usb_otg_fs) {
	case Port::OTG_FS_GLOBAL:
		return 0x50000000U;
	case Port::OTG_FS_HOST:
		return 0x50000400U;
	case Port::OTG_FS_DEVICE:
		return 0x50000800U;
	case Port::OTG_FS_PWRCLK:
		return 0x50000e00U;
}

/**
 * @defgroup	OTG_FS_PWRCLK_FS_PCGCCTL_GROUP		OTG_FS power and clock gating control register (OTG_FS_PCGCCTL) group
 *
 * @{
 */

SETUP_REGISTER_INFO(FS_PCGCCTLBitList, /**/
					Binary<>{BitPos_t{4}},	// PHYSUSP
					Binary<>{BitPos_t{1}},	// GATEHCLK
					Binary<>{BitPos_t{0}}	// STPPCLK
					)

enum class FS_PCGCCTLField {
	PHYSUSP,		/*!< PHY Suspended*/
	GATEHCLK,		/*!< Gate HCLK*/
	STPPCLK,		/*!< Stop PHY clock*/
};

template <Port USB_OTG_FS>
static constexpr Register<FS_PCGCCTLBitList, FS_PCGCCTLField> FS_PCGCCTL{BASE_ADDR(USB_OTG_FS), 0x00U};
/**@}*/


} // cpp_stm32::usb_otg_fs::reg
