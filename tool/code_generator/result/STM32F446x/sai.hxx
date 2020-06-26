#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::sai::reg {

static constexpr auto BASE_ADDR(Port const& t_sai) {
	switch (t_sai) {
		case Port::SAI1:
			return 0x40015800U;
		case Port::SAI2:
			return 0x40015c00U;
	}
}

/**
 * @defgroup	SAI2_BCR1_GROUP		BConfiguration register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BCR1BitList,						 /**/
										Bit<2>{BitPos_t{0}},		 // MODE
										Bit<2>{BitPos_t{2}},		 // PRTCFG
										Bit<3>{BitPos_t{5}},		 // DS
										Binary<>{BitPos_t{8}},	 // LSBFIRST
										Binary<>{BitPos_t{9}},	 // CKSTR
										Bit<2>{BitPos_t{10}},		 // SYNCEN
										Binary<>{BitPos_t{12}},	 // MONO
										Binary<>{BitPos_t{13}},	 // OutDri
										Binary<>{BitPos_t{16}},	 // SAIBEN
										Binary<>{BitPos_t{17}},	 // DMAEN
										Binary<>{BitPos_t{19}},	 // NODIV
										Bit<4>{BitPos_t{20}}		 // MCJDIV
)

enum class BCR1Field {
	MODE,			/*!< Audio block mode*/
	PRTCFG,		/*!< Protocol configuration*/
	DS,				/*!< Data size*/
	LSBFIRST, /*!< Least significant bit first*/
	CKSTR,		/*!< Clock strobing edge*/
	SYNCEN,		/*!< Synchronization enable*/
	MONO,			/*!< Mono mode*/
	OutDri,		/*!< Output drive*/
	SAIBEN,		/*!< Audio block B enable*/
	DMAEN,		/*!< DMA enable*/
	NODIV,		/*!< No divider*/
	MCJDIV,		/*!< Master clock divider*/
};

template <Port SAI>
static constexpr Register<BCR1BitList, BCR1Field> BCR1{BASE_ADDR(SAI), 0x24U};
/**@}*/

/**
 * @defgroup	SAI2_BCR2_GROUP		BConfiguration register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BCR2BitList,						 /**/
										Bit<3>{BitPos_t{0}},		 // FTH
										Binary<>{BitPos_t{3}},	 // FFLUS
										Binary<>{BitPos_t{4}},	 // TRIS
										Binary<>{BitPos_t{5}},	 // MUTE
										Binary<>{BitPos_t{6}},	 // MUTEVAL
										Bit<6>{BitPos_t{7}},		 // MUTECN
										Binary<>{BitPos_t{13}},	 // CPL
										Bit<2>{BitPos_t{14}}		 // COMP
)

enum class BCR2Field {
	FTH,		 /*!< FIFO threshold*/
	FFLUS,	 /*!< FIFO flush*/
	TRIS,		 /*!< Tristate management on data line*/
	MUTE,		 /*!< Mute*/
	MUTEVAL, /*!< Mute value*/
	MUTECN,	 /*!< Mute counter*/
	CPL,		 /*!< Complement bit*/
	COMP,		 /*!< Companding mode*/
};

template <Port SAI>
static constexpr Register<BCR2BitList, BCR2Field> BCR2{BASE_ADDR(SAI), 0x28U};
/**@}*/

/**
 * @defgroup	SAI2_BFRCR_GROUP		BFRCR group
 *
 * @{
 */

SETUP_REGISTER_INFO(BFRCRBitList,						 /**/
										Bit<8>{BitPos_t{0}},		 // FRL
										Bit<7>{BitPos_t{8}},		 // FSALL
										Binary<>{BitPos_t{16}},	 // FSDEF
										Binary<>{BitPos_t{17}},	 // FSPOL
										Binary<>{BitPos_t{18}}	 // FSOFF
)

enum class BFRCRField {
	FRL,	 /*!< Frame length*/
	FSALL, /*!< Frame synchronization active level length*/
	FSDEF, /*!< Frame synchronization definition*/
	FSPOL, /*!< Frame synchronization polarity*/
	FSOFF, /*!< Frame synchronization offset*/
};

template <Port SAI>
static constexpr Register<BFRCRBitList, BFRCRField> BFRCR{BASE_ADDR(SAI), 0x2cU};
/**@}*/

/**
 * @defgroup	SAI2_BSLOTR_GROUP		BSlot register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BSLOTRBitList,												/**/
										Bit<5>{BitPos_t{0}},									// FBOFF
										Bit<2>{BitPos_t{6}},									// SLOTSZ
										Bit<4>{BitPos_t{8}},									// NBSLOT
										Bit<16, std::uint16_t>{BitPos_t{16}}	// SLOTEN
)

enum class BSLOTRField {
	FBOFF,	/*!< First bit offset*/
	SLOTSZ, /*!< Slot size*/
	NBSLOT, /*!< Number of slots in an audio frame*/
	SLOTEN, /*!< Slot enable*/
};

template <Port SAI>
static constexpr Register<BSLOTRBitList, BSLOTRField> BSLOTR{BASE_ADDR(SAI), 0x30U};
/**@}*/

/**
 * @defgroup	SAI2_BIM_GROUP		BInterrupt mask register2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(BIMBitList,							/**/
										Binary<>{BitPos_t{0}},	// OVRUDRIE
										Binary<>{BitPos_t{1}},	// MUTEDET
										Binary<>{BitPos_t{2}},	// WCKCFG
										Binary<>{BitPos_t{3}},	// FREQIE
										Binary<>{BitPos_t{4}},	// CNRDYIE
										Binary<>{BitPos_t{5}},	// AFSDETIE
										Binary<>{BitPos_t{6}}		// LFSDETIE
)

enum class BIMField {
	OVRUDRIE, /*!< Overrun/underrun interrupt enable*/
	MUTEDET,	/*!< Mute detection interrupt enable*/
	WCKCFG,		/*!< Wrong clock configuration interrupt enable*/
	FREQIE,		/*!< FIFO request interrupt enable*/
	CNRDYIE,	/*!< Codec not ready interrupt enable*/
	AFSDETIE, /*!< Anticipated frame synchronization detection interrupt enable*/
	LFSDETIE, /*!< Late frame synchronization detection interrupt enable*/
};

template <Port SAI>
static constexpr Register<BIMBitList, BIMField> BIM{BASE_ADDR(SAI), 0x34U};
/**@}*/

/**
 * @defgroup	SAI2_BSR_GROUP		BStatus register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BSRBitList,							/**/
										Binary<>{BitPos_t{0}},	// OVRUDR
										Binary<>{BitPos_t{1}},	// MUTEDET
										Binary<>{BitPos_t{2}},	// WCKCFG
										Binary<>{BitPos_t{3}},	// FREQ
										Binary<>{BitPos_t{4}},	// CNRDY
										Binary<>{BitPos_t{5}},	// AFSDET
										Binary<>{BitPos_t{6}},	// LFSDET
										Bit<3>{BitPos_t{16}}		// FLVL
)

enum class BSRField {
	OVRUDR,	 /*!< Overrun / underrun*/
	MUTEDET, /*!< Mute detection*/
	WCKCFG,	 /*!< Wrong clock configuration flag*/
	FREQ,		 /*!< FIFO request*/
	CNRDY,	 /*!< Codec not ready*/
	AFSDET,	 /*!< Anticipated frame synchronization detection*/
	LFSDET,	 /*!< Late frame synchronization detection*/
	FLVL,		 /*!< FIFO level threshold*/
};

template <Port SAI>
static constexpr Register<BSRBitList, BSRField> BSR{BASE_ADDR(SAI), 0x38U};
/**@}*/

/**
 * @defgroup	SAI2_BCLRFR_GROUP		BClear flag register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BCLRFRBitList,					/**/
										Binary<>{BitPos_t{0}},	// OVRUDR
										Binary<>{BitPos_t{1}},	// MUTEDET
										Binary<>{BitPos_t{2}},	// WCKCFG
										Binary<>{BitPos_t{4}},	// CNRDY
										Binary<>{BitPos_t{5}},	// CAFSDET
										Binary<>{BitPos_t{6}}		// LFSDET
)

enum class BCLRFRField {
	OVRUDR,	 /*!< Clear overrun / underrun*/
	MUTEDET, /*!< Mute detection flag*/
	WCKCFG,	 /*!< Clear wrong clock configuration flag*/
	CNRDY,	 /*!< Clear codec not ready flag*/
	CAFSDET, /*!< Clear anticipated frame synchronization detection flag*/
	LFSDET,	 /*!< Clear late frame synchronization detection flag*/
};

template <Port SAI>
static constexpr Register<BCLRFRBitList, BCLRFRField> BCLRFR{BASE_ADDR(SAI), 0x3cU};
/**@}*/

/**
 * @defgroup	SAI2_BDR_GROUP		BData register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BDRBitList,													 /**/
										Bit<32, std::uint32_t>{BitPos_t{0}}	 // DATA
)

enum class BDRField {
	DATA, /*!< Data*/
};

template <Port SAI>
static constexpr Register<BDRBitList, BDRField> BDR{BASE_ADDR(SAI), 0x40U};
/**@}*/

/**
 * @defgroup	SAI2_ACR1_GROUP		AConfiguration register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(ACR1BitList,						 /**/
										Bit<2>{BitPos_t{0}},		 // MODE
										Bit<2>{BitPos_t{2}},		 // PRTCFG
										Bit<3>{BitPos_t{5}},		 // DS
										Binary<>{BitPos_t{8}},	 // LSBFIRST
										Binary<>{BitPos_t{9}},	 // CKSTR
										Bit<2>{BitPos_t{10}},		 // SYNCEN
										Binary<>{BitPos_t{12}},	 // MONO
										Binary<>{BitPos_t{13}},	 // OutDri
										Binary<>{BitPos_t{16}},	 // SAIAEN
										Binary<>{BitPos_t{17}},	 // DMAEN
										Binary<>{BitPos_t{19}},	 // NODIV
										Bit<4>{BitPos_t{20}}		 // MCJDIV
)

enum class ACR1Field {
	MODE,			/*!< Audio block mode*/
	PRTCFG,		/*!< Protocol configuration*/
	DS,				/*!< Data size*/
	LSBFIRST, /*!< Least significant bit first*/
	CKSTR,		/*!< Clock strobing edge*/
	SYNCEN,		/*!< Synchronization enable*/
	MONO,			/*!< Mono mode*/
	OutDri,		/*!< Output drive*/
	SAIAEN,		/*!< Audio block A enable*/
	DMAEN,		/*!< DMA enable*/
	NODIV,		/*!< No divider*/
	MCJDIV,		/*!< Master clock divider*/
};

template <Port SAI>
static constexpr Register<ACR1BitList, ACR1Field> ACR1{BASE_ADDR(SAI), 0x04U};
/**@}*/

/**
 * @defgroup	SAI2_ACR2_GROUP		AConfiguration register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(ACR2BitList,						 /**/
										Bit<3>{BitPos_t{0}},		 // FTH
										Binary<>{BitPos_t{3}},	 // FFLUS
										Binary<>{BitPos_t{4}},	 // TRIS
										Binary<>{BitPos_t{5}},	 // MUTE
										Binary<>{BitPos_t{6}},	 // MUTEVAL
										Bit<6>{BitPos_t{7}},		 // MUTECN
										Binary<>{BitPos_t{13}},	 // CPL
										Bit<2>{BitPos_t{14}}		 // COMP
)

enum class ACR2Field {
	FTH,		 /*!< FIFO threshold*/
	FFLUS,	 /*!< FIFO flush*/
	TRIS,		 /*!< Tristate management on data line*/
	MUTE,		 /*!< Mute*/
	MUTEVAL, /*!< Mute value*/
	MUTECN,	 /*!< Mute counter*/
	CPL,		 /*!< Complement bit*/
	COMP,		 /*!< Companding mode*/
};

template <Port SAI>
static constexpr Register<ACR2BitList, ACR2Field> ACR2{BASE_ADDR(SAI), 0x08U};