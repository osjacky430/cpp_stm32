#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::dma::reg {

static constexpr auto BASE_ADDR(Port const& t_dma) {
	case Port::DMA2:
		return 0x40026400U;
	case Port::DMA1:
		return 0x40026000U;
}

/**
 * @defgroup	DMA1_LISR_GROUP		low interrupt status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(LISRBitList, /**/
					Bit<4>{BitPos_t{0}},	// FEI
					Bit<4>{BitPos_t{2}},	// DMEI
					Bit<4>{BitPos_t{3}},	// TEI
					Bit<4>{BitPos_t{4}},	// HTI
					Bit<4>{BitPos_t{5}}	// TCI
					)

enum class LISRField {
	FEI,		/*!< Stream x FIFO error interrupt flag (x=3..0)*/
	DMEI,		/*!< Stream x direct mode error interrupt flag (x=3..0)*/
	TEI,		/*!< Stream x transfer error interrupt flag (x=3..0)*/
	HTI,		/*!< Stream x half transfer interrupt flag (x=3..0)*/
	TCI,		/*!< Stream x transfer complete interrupt flag (x = 3..0)*/
};

template <Port DMA>
static constexpr Register<LISRBitList, LISRField> LISR{BASE_ADDR(DMA), 0x00U};
/**@}*/

/**
 * @defgroup	DMA1_HISR_GROUP		high interrupt status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(HISRBitList, /**/
					Bit<4>{BitPos_t{0}},	// FEI
					Bit<4>{BitPos_t{2}},	// DMEI
					Bit<4>{BitPos_t{3}},	// TEI
					Bit<4>{BitPos_t{4}},	// HTI
					Bit<4>{BitPos_t{5}}	// TCI
					)

enum class HISRField {
	FEI,		/*!< Stream x FIFO error interrupt flag (x=7..4)*/
	DMEI,		/*!< Stream x direct mode error interrupt flag (x=7..4)*/
	TEI,		/*!< Stream x transfer error interrupt flag (x=7..4)*/
	HTI,		/*!< Stream x half transfer interrupt flag (x=7..4)*/
	TCI,		/*!< Stream x transfer complete interrupt flag (x=7..4)*/
};

template <Port DMA>
static constexpr Register<HISRBitList, HISRField> HISR{BASE_ADDR(DMA), 0x04U};
/**@}*/

/**
 * @defgroup	DMA1_LIFCR_GROUP		low interrupt flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(LIFCRBitList, /**/
					Bit<4>{BitPos_t{0}},	// CFEI
					Bit<4>{BitPos_t{2}},	// CDMEI
					Bit<4>{BitPos_t{3}},	// CTEI
					Bit<4>{BitPos_t{4}},	// CHTI
					Bit<4>{BitPos_t{5}}	// CTCI
					)

enum class LIFCRField {
	CFEI,		/*!< Stream x clear FIFO error interrupt flag (x = 3..0)*/
	CDMEI,		/*!< Stream x clear direct mode error interrupt flag (x = 3..0)*/
	CTEI,		/*!< Stream x clear transfer error interrupt flag (x = 3..0)*/
	CHTI,		/*!< Stream x clear half transfer interrupt flag (x = 3..0)*/
	CTCI,		/*!< Stream x clear transfer complete interrupt flag (x = 3..0)*/
};

template <Port DMA>
static constexpr Register<LIFCRBitList, LIFCRField> LIFCR{BASE_ADDR(DMA), 0x08U};
/**@}*/

/**
 * @defgroup	DMA1_HIFCR_GROUP		high interrupt flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(HIFCRBitList, /**/
					Bit<4>{BitPos_t{0}},	// CFEI
					Bit<4>{BitPos_t{2}},	// CDMEI
					Bit<4>{BitPos_t{3}},	// CTEI
					Bit<4>{BitPos_t{4}},	// CHTI
					Bit<4>{BitPos_t{5}}	// CTCI
					)

enum class HIFCRField {
	CFEI,		/*!< Stream x clear FIFO error interrupt flag (x = 7..4)*/
	CDMEI,		/*!< Stream x clear direct mode error interrupt flag (x = 7..4)*/
	CTEI,		/*!< Stream x clear transfer error interrupt flag (x = 7..4)*/
	CHTI,		/*!< Stream x clear half transfer interrupt flag (x = 7..4)*/
	CTCI,		/*!< Stream x clear transfer complete interrupt flag (x = 7..4)*/
};

template <Port DMA>
static constexpr Register<HIFCRBitList, HIFCRField> HIFCR{BASE_ADDR(DMA), 0x0cU};
/**@}*/

/**
 * @defgroup	DMA1_S0CR_GROUP		stream x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S0CRBitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// DMEIE
					Binary<>{BitPos_t{2}},	// TEIE
					Binary<>{BitPos_t{3}},	// HTIE
					Binary<>{BitPos_t{4}},	// TCIE
					Binary<>{BitPos_t{5}},	// PFCTRL
					Bit<2>{BitPos_t{6}},	// DIR
					Binary<>{BitPos_t{8}},	// CIRC
					Binary<>{BitPos_t{9}},	// PINC
					Binary<>{BitPos_t{10}},	// MINC
					Bit<2>{BitPos_t{11}},	// PSIZE
					Bit<2>{BitPos_t{13}},	// MSIZE
					Binary<>{BitPos_t{15}},	// PINCOS
					Bit<2>{BitPos_t{16}},	// PL
					Binary<>{BitPos_t{18}},	// DBM
					Binary<>{BitPos_t{19}},	// CT
					Bit<2>{BitPos_t{21}},	// PBURST
					Bit<2>{BitPos_t{23}},	// MBURST
					Bit<3>{BitPos_t{25}}	// CHSEL
					)

enum class S0CRField {
	EN,		/*!< Stream enable / flag stream ready when read low*/
	DMEIE,		/*!< Direct mode error interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	PFCTRL,		/*!< Peripheral flow controller*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral data size*/
	MSIZE,		/*!< Memory data size*/
	PINCOS,		/*!< Peripheral increment offset size*/
	PL,		/*!< Priority level*/
	DBM,		/*!< Double buffer mode*/
	CT,		/*!< Current target (only in double buffer mode)*/
	PBURST,		/*!< Peripheral burst transfer configuration*/
	MBURST,		/*!< Memory burst transfer configuration*/
	CHSEL,		/*!< Channel selection*/
};

template <Port DMA>
static constexpr Register<S0CRBitList, S0CRField> S0CR{BASE_ADDR(DMA), 0x10U};
/**@}*/

/**
 * @defgroup	DMA1_S0NDTR_GROUP		stream x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S0NDTRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class S0NDTRField {
	NDT,		/*!< Number of data items to transfer*/
};

template <Port DMA>
static constexpr Register<S0NDTRBitList, S0NDTRField> S0NDTR{BASE_ADDR(DMA), 0x14U};
/**@}*/

/**
 * @defgroup	DMA1_S0PAR_GROUP		stream x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S0PARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class S0PARField {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<S0PARBitList, S0PARField> S0PAR{BASE_ADDR(DMA), 0x18U};
/**@}*/

/**
 * @defgroup	DMA1_S0M0AR_GROUP		stream x memory 0 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S0M0ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M0A
					)

enum class S0M0ARField {
	M0A,		/*!< Memory 0 address*/
};

template <Port DMA>
static constexpr Register<S0M0ARBitList, S0M0ARField> S0M0AR{BASE_ADDR(DMA), 0x1cU};
/**@}*/

/**
 * @defgroup	DMA1_S0M1AR_GROUP		stream x memory 1 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S0M1ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M1A
					)

enum class S0M1ARField {
	M1A,		/*!< Memory 1 address (used in case of Double buffer mode)*/
};

template <Port DMA>
static constexpr Register<S0M1ARBitList, S0M1ARField> S0M1AR{BASE_ADDR(DMA), 0x20U};
/**@}*/

/**
 * @defgroup	DMA1_S0FCR_GROUP		stream x FIFO control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S0FCRBitList, /**/
					Bit<2>{BitPos_t{0}},	// FTH
					Binary<>{BitPos_t{2}},	// DMDIS
					StatusBit<3>{BitPos_t{3}},	// FS
					Binary<>{BitPos_t{7}}	// FEIE
					)

enum class S0FCRField {
	FTH,		/*!< FIFO threshold selection*/
	DMDIS,		/*!< Direct mode disable*/
	FS,		/*!< FIFO status*/
	FEIE,		/*!< FIFO error interrupt enable*/
};

template <Port DMA>
static constexpr Register<S0FCRBitList, S0FCRField> S0FCR{BASE_ADDR(DMA), 0x24U};
/**@}*/

/**
 * @defgroup	DMA1_S1CR_GROUP		stream x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S1CRBitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// DMEIE
					Binary<>{BitPos_t{2}},	// TEIE
					Binary<>{BitPos_t{3}},	// HTIE
					Binary<>{BitPos_t{4}},	// TCIE
					Binary<>{BitPos_t{5}},	// PFCTRL
					Bit<2>{BitPos_t{6}},	// DIR
					Binary<>{BitPos_t{8}},	// CIRC
					Binary<>{BitPos_t{9}},	// PINC
					Binary<>{BitPos_t{10}},	// MINC
					Bit<2>{BitPos_t{11}},	// PSIZE
					Bit<2>{BitPos_t{13}},	// MSIZE
					Binary<>{BitPos_t{15}},	// PINCOS
					Bit<2>{BitPos_t{16}},	// PL
					Binary<>{BitPos_t{18}},	// DBM
					Binary<>{BitPos_t{19}},	// CT
					Binary<>{BitPos_t{20}},	// ACK
					Bit<2>{BitPos_t{21}},	// PBURST
					Bit<2>{BitPos_t{23}},	// MBURST
					Bit<3>{BitPos_t{25}}	// CHSEL
					)

enum class S1CRField {
	EN,		/*!< Stream enable / flag stream ready when read low*/
	DMEIE,		/*!< Direct mode error interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	PFCTRL,		/*!< Peripheral flow controller*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral data size*/
	MSIZE,		/*!< Memory data size*/
	PINCOS,		/*!< Peripheral increment offset size*/
	PL,		/*!< Priority level*/
	DBM,		/*!< Double buffer mode*/
	CT,		/*!< Current target (only in double buffer mode)*/
	ACK,		/*!< ACK*/
	PBURST,		/*!< Peripheral burst transfer configuration*/
	MBURST,		/*!< Memory burst transfer configuration*/
	CHSEL,		/*!< Channel selection*/
};

template <Port DMA>
static constexpr Register<S1CRBitList, S1CRField> S1CR{BASE_ADDR(DMA), 0x28U};
/**@}*/

/**
 * @defgroup	DMA1_S1NDTR_GROUP		stream x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S1NDTRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class S1NDTRField {
	NDT,		/*!< Number of data items to transfer*/
};

template <Port DMA>
static constexpr Register<S1NDTRBitList, S1NDTRField> S1NDTR{BASE_ADDR(DMA), 0x2cU};
/**@}*/

/**
 * @defgroup	DMA1_S1PAR_GROUP		stream x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S1PARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class S1PARField {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<S1PARBitList, S1PARField> S1PAR{BASE_ADDR(DMA), 0x30U};
/**@}*/

/**
 * @defgroup	DMA1_S1M0AR_GROUP		stream x memory 0 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S1M0ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M0A
					)

enum class S1M0ARField {
	M0A,		/*!< Memory 0 address*/
};

template <Port DMA>
static constexpr Register<S1M0ARBitList, S1M0ARField> S1M0AR{BASE_ADDR(DMA), 0x34U};
/**@}*/

/**
 * @defgroup	DMA1_S1M1AR_GROUP		stream x memory 1 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S1M1ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M1A
					)

enum class S1M1ARField {
	M1A,		/*!< Memory 1 address (used in case of Double buffer mode)*/
};

template <Port DMA>
static constexpr Register<S1M1ARBitList, S1M1ARField> S1M1AR{BASE_ADDR(DMA), 0x38U};
/**@}*/

/**
 * @defgroup	DMA1_S1FCR_GROUP		stream x FIFO control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S1FCRBitList, /**/
					Bit<2>{BitPos_t{0}},	// FTH
					Binary<>{BitPos_t{2}},	// DMDIS
					StatusBit<3>{BitPos_t{3}},	// FS
					Binary<>{BitPos_t{7}}	// FEIE
					)

enum class S1FCRField {
	FTH,		/*!< FIFO threshold selection*/
	DMDIS,		/*!< Direct mode disable*/
	FS,		/*!< FIFO status*/
	FEIE,		/*!< FIFO error interrupt enable*/
};

template <Port DMA>
static constexpr Register<S1FCRBitList, S1FCRField> S1FCR{BASE_ADDR(DMA), 0x3cU};
/**@}*/

/**
 * @defgroup	DMA1_S2CR_GROUP		stream x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S2CRBitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// DMEIE
					Binary<>{BitPos_t{2}},	// TEIE
					Binary<>{BitPos_t{3}},	// HTIE
					Binary<>{BitPos_t{4}},	// TCIE
					Binary<>{BitPos_t{5}},	// PFCTRL
					Bit<2>{BitPos_t{6}},	// DIR
					Binary<>{BitPos_t{8}},	// CIRC
					Binary<>{BitPos_t{9}},	// PINC
					Binary<>{BitPos_t{10}},	// MINC
					Bit<2>{BitPos_t{11}},	// PSIZE
					Bit<2>{BitPos_t{13}},	// MSIZE
					Binary<>{BitPos_t{15}},	// PINCOS
					Bit<2>{BitPos_t{16}},	// PL
					Binary<>{BitPos_t{18}},	// DBM
					Binary<>{BitPos_t{19}},	// CT
					Binary<>{BitPos_t{20}},	// ACK
					Bit<2>{BitPos_t{21}},	// PBURST
					Bit<2>{BitPos_t{23}},	// MBURST
					Bit<3>{BitPos_t{25}}	// CHSEL
					)

enum class S2CRField {
	EN,		/*!< Stream enable / flag stream ready when read low*/
	DMEIE,		/*!< Direct mode error interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	PFCTRL,		/*!< Peripheral flow controller*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral data size*/
	MSIZE,		/*!< Memory data size*/
	PINCOS,		/*!< Peripheral increment offset size*/
	PL,		/*!< Priority level*/
	DBM,		/*!< Double buffer mode*/
	CT,		/*!< Current target (only in double buffer mode)*/
	ACK,		/*!< ACK*/
	PBURST,		/*!< Peripheral burst transfer configuration*/
	MBURST,		/*!< Memory burst transfer configuration*/
	CHSEL,		/*!< Channel selection*/
};

template <Port DMA>
static constexpr Register<S2CRBitList, S2CRField> S2CR{BASE_ADDR(DMA), 0x40U};
/**@}*/

/**
 * @defgroup	DMA1_S2NDTR_GROUP		stream x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S2NDTRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class S2NDTRField {
	NDT,		/*!< Number of data items to transfer*/
};

template <Port DMA>
static constexpr Register<S2NDTRBitList, S2NDTRField> S2NDTR{BASE_ADDR(DMA), 0x44U};
/**@}*/

/**
 * @defgroup	DMA1_S2PAR_GROUP		stream x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S2PARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class S2PARField {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<S2PARBitList, S2PARField> S2PAR{BASE_ADDR(DMA), 0x48U};
/**@}*/

/**
 * @defgroup	DMA1_S2M0AR_GROUP		stream x memory 0 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S2M0ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M0A
					)

enum class S2M0ARField {
	M0A,		/*!< Memory 0 address*/
};

template <Port DMA>
static constexpr Register<S2M0ARBitList, S2M0ARField> S2M0AR{BASE_ADDR(DMA), 0x4cU};
/**@}*/

/**
 * @defgroup	DMA1_S2M1AR_GROUP		stream x memory 1 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S2M1ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M1A
					)

enum class S2M1ARField {
	M1A,		/*!< Memory 1 address (used in case of Double buffer mode)*/
};

template <Port DMA>
static constexpr Register<S2M1ARBitList, S2M1ARField> S2M1AR{BASE_ADDR(DMA), 0x50U};
/**@}*/

/**
 * @defgroup	DMA1_S2FCR_GROUP		stream x FIFO control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S2FCRBitList, /**/
					Bit<2>{BitPos_t{0}},	// FTH
					Binary<>{BitPos_t{2}},	// DMDIS
					StatusBit<3>{BitPos_t{3}},	// FS
					Binary<>{BitPos_t{7}}	// FEIE
					)

enum class S2FCRField {
	FTH,		/*!< FIFO threshold selection*/
	DMDIS,		/*!< Direct mode disable*/
	FS,		/*!< FIFO status*/
	FEIE,		/*!< FIFO error interrupt enable*/
};

template <Port DMA>
static constexpr Register<S2FCRBitList, S2FCRField> S2FCR{BASE_ADDR(DMA), 0x54U};
/**@}*/

/**
 * @defgroup	DMA1_S3CR_GROUP		stream x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S3CRBitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// DMEIE
					Binary<>{BitPos_t{2}},	// TEIE
					Binary<>{BitPos_t{3}},	// HTIE
					Binary<>{BitPos_t{4}},	// TCIE
					Binary<>{BitPos_t{5}},	// PFCTRL
					Bit<2>{BitPos_t{6}},	// DIR
					Binary<>{BitPos_t{8}},	// CIRC
					Binary<>{BitPos_t{9}},	// PINC
					Binary<>{BitPos_t{10}},	// MINC
					Bit<2>{BitPos_t{11}},	// PSIZE
					Bit<2>{BitPos_t{13}},	// MSIZE
					Binary<>{BitPos_t{15}},	// PINCOS
					Bit<2>{BitPos_t{16}},	// PL
					Binary<>{BitPos_t{18}},	// DBM
					Binary<>{BitPos_t{19}},	// CT
					Binary<>{BitPos_t{20}},	// ACK
					Bit<2>{BitPos_t{21}},	// PBURST
					Bit<2>{BitPos_t{23}},	// MBURST
					Bit<3>{BitPos_t{25}}	// CHSEL
					)

enum class S3CRField {
	EN,		/*!< Stream enable / flag stream ready when read low*/
	DMEIE,		/*!< Direct mode error interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	PFCTRL,		/*!< Peripheral flow controller*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral data size*/
	MSIZE,		/*!< Memory data size*/
	PINCOS,		/*!< Peripheral increment offset size*/
	PL,		/*!< Priority level*/
	DBM,		/*!< Double buffer mode*/
	CT,		/*!< Current target (only in double buffer mode)*/
	ACK,		/*!< ACK*/
	PBURST,		/*!< Peripheral burst transfer configuration*/
	MBURST,		/*!< Memory burst transfer configuration*/
	CHSEL,		/*!< Channel selection*/
};

template <Port DMA>
static constexpr Register<S3CRBitList, S3CRField> S3CR{BASE_ADDR(DMA), 0x58U};
/**@}*/

/**
 * @defgroup	DMA1_S3NDTR_GROUP		stream x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S3NDTRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class S3NDTRField {
	NDT,		/*!< Number of data items to transfer*/
};

template <Port DMA>
static constexpr Register<S3NDTRBitList, S3NDTRField> S3NDTR{BASE_ADDR(DMA), 0x5cU};
/**@}*/

/**
 * @defgroup	DMA1_S3PAR_GROUP		stream x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S3PARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class S3PARField {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<S3PARBitList, S3PARField> S3PAR{BASE_ADDR(DMA), 0x60U};
/**@}*/

/**
 * @defgroup	DMA1_S3M0AR_GROUP		stream x memory 0 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S3M0ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M0A
					)

enum class S3M0ARField {
	M0A,		/*!< Memory 0 address*/
};

template <Port DMA>
static constexpr Register<S3M0ARBitList, S3M0ARField> S3M0AR{BASE_ADDR(DMA), 0x64U};
/**@}*/

/**
 * @defgroup	DMA1_S3M1AR_GROUP		stream x memory 1 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S3M1ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M1A
					)

enum class S3M1ARField {
	M1A,		/*!< Memory 1 address (used in case of Double buffer mode)*/
};

template <Port DMA>
static constexpr Register<S3M1ARBitList, S3M1ARField> S3M1AR{BASE_ADDR(DMA), 0x68U};
/**@}*/

/**
 * @defgroup	DMA1_S3FCR_GROUP		stream x FIFO control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S3FCRBitList, /**/
					Bit<2>{BitPos_t{0}},	// FTH
					Binary<>{BitPos_t{2}},	// DMDIS
					StatusBit<3>{BitPos_t{3}},	// FS
					Binary<>{BitPos_t{7}}	// FEIE
					)

enum class S3FCRField {
	FTH,		/*!< FIFO threshold selection*/
	DMDIS,		/*!< Direct mode disable*/
	FS,		/*!< FIFO status*/
	FEIE,		/*!< FIFO error interrupt enable*/
};

template <Port DMA>
static constexpr Register<S3FCRBitList, S3FCRField> S3FCR{BASE_ADDR(DMA), 0x6cU};
/**@}*/

/**
 * @defgroup	DMA1_S4CR_GROUP		stream x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S4CRBitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// DMEIE
					Binary<>{BitPos_t{2}},	// TEIE
					Binary<>{BitPos_t{3}},	// HTIE
					Binary<>{BitPos_t{4}},	// TCIE
					Binary<>{BitPos_t{5}},	// PFCTRL
					Bit<2>{BitPos_t{6}},	// DIR
					Binary<>{BitPos_t{8}},	// CIRC
					Binary<>{BitPos_t{9}},	// PINC
					Binary<>{BitPos_t{10}},	// MINC
					Bit<2>{BitPos_t{11}},	// PSIZE
					Bit<2>{BitPos_t{13}},	// MSIZE
					Binary<>{BitPos_t{15}},	// PINCOS
					Bit<2>{BitPos_t{16}},	// PL
					Binary<>{BitPos_t{18}},	// DBM
					Binary<>{BitPos_t{19}},	// CT
					Binary<>{BitPos_t{20}},	// ACK
					Bit<2>{BitPos_t{21}},	// PBURST
					Bit<2>{BitPos_t{23}},	// MBURST
					Bit<3>{BitPos_t{25}}	// CHSEL
					)

enum class S4CRField {
	EN,		/*!< Stream enable / flag stream ready when read low*/
	DMEIE,		/*!< Direct mode error interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	PFCTRL,		/*!< Peripheral flow controller*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral data size*/
	MSIZE,		/*!< Memory data size*/
	PINCOS,		/*!< Peripheral increment offset size*/
	PL,		/*!< Priority level*/
	DBM,		/*!< Double buffer mode*/
	CT,		/*!< Current target (only in double buffer mode)*/
	ACK,		/*!< ACK*/
	PBURST,		/*!< Peripheral burst transfer configuration*/
	MBURST,		/*!< Memory burst transfer configuration*/
	CHSEL,		/*!< Channel selection*/
};

template <Port DMA>
static constexpr Register<S4CRBitList, S4CRField> S4CR{BASE_ADDR(DMA), 0x70U};
/**@}*/

/**
 * @defgroup	DMA1_S4NDTR_GROUP		stream x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S4NDTRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class S4NDTRField {
	NDT,		/*!< Number of data items to transfer*/
};

template <Port DMA>
static constexpr Register<S4NDTRBitList, S4NDTRField> S4NDTR{BASE_ADDR(DMA), 0x74U};
/**@}*/

/**
 * @defgroup	DMA1_S4PAR_GROUP		stream x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S4PARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class S4PARField {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<S4PARBitList, S4PARField> S4PAR{BASE_ADDR(DMA), 0x78U};
/**@}*/

/**
 * @defgroup	DMA1_S4M0AR_GROUP		stream x memory 0 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S4M0ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M0A
					)

enum class S4M0ARField {
	M0A,		/*!< Memory 0 address*/
};

template <Port DMA>
static constexpr Register<S4M0ARBitList, S4M0ARField> S4M0AR{BASE_ADDR(DMA), 0x7cU};
/**@}*/

/**
 * @defgroup	DMA1_S4M1AR_GROUP		stream x memory 1 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S4M1ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M1A
					)

enum class S4M1ARField {
	M1A,		/*!< Memory 1 address (used in case of Double buffer mode)*/
};

template <Port DMA>
static constexpr Register<S4M1ARBitList, S4M1ARField> S4M1AR{BASE_ADDR(DMA), 0x80U};
/**@}*/

/**
 * @defgroup	DMA1_S4FCR_GROUP		stream x FIFO control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S4FCRBitList, /**/
					Bit<2>{BitPos_t{0}},	// FTH
					Binary<>{BitPos_t{2}},	// DMDIS
					StatusBit<3>{BitPos_t{3}},	// FS
					Binary<>{BitPos_t{7}}	// FEIE
					)

enum class S4FCRField {
	FTH,		/*!< FIFO threshold selection*/
	DMDIS,		/*!< Direct mode disable*/
	FS,		/*!< FIFO status*/
	FEIE,		/*!< FIFO error interrupt enable*/
};

template <Port DMA>
static constexpr Register<S4FCRBitList, S4FCRField> S4FCR{BASE_ADDR(DMA), 0x84U};
/**@}*/

/**
 * @defgroup	DMA1_S5CR_GROUP		stream x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S5CRBitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// DMEIE
					Binary<>{BitPos_t{2}},	// TEIE
					Binary<>{BitPos_t{3}},	// HTIE
					Binary<>{BitPos_t{4}},	// TCIE
					Binary<>{BitPos_t{5}},	// PFCTRL
					Bit<2>{BitPos_t{6}},	// DIR
					Binary<>{BitPos_t{8}},	// CIRC
					Binary<>{BitPos_t{9}},	// PINC
					Binary<>{BitPos_t{10}},	// MINC
					Bit<2>{BitPos_t{11}},	// PSIZE
					Bit<2>{BitPos_t{13}},	// MSIZE
					Binary<>{BitPos_t{15}},	// PINCOS
					Bit<2>{BitPos_t{16}},	// PL
					Binary<>{BitPos_t{18}},	// DBM
					Binary<>{BitPos_t{19}},	// CT
					Binary<>{BitPos_t{20}},	// ACK
					Bit<2>{BitPos_t{21}},	// PBURST
					Bit<2>{BitPos_t{23}},	// MBURST
					Bit<3>{BitPos_t{25}}	// CHSEL
					)

enum class S5CRField {
	EN,		/*!< Stream enable / flag stream ready when read low*/
	DMEIE,		/*!< Direct mode error interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	PFCTRL,		/*!< Peripheral flow controller*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral data size*/
	MSIZE,		/*!< Memory data size*/
	PINCOS,		/*!< Peripheral increment offset size*/
	PL,		/*!< Priority level*/
	DBM,		/*!< Double buffer mode*/
	CT,		/*!< Current target (only in double buffer mode)*/
	ACK,		/*!< ACK*/
	PBURST,		/*!< Peripheral burst transfer configuration*/
	MBURST,		/*!< Memory burst transfer configuration*/
	CHSEL,		/*!< Channel selection*/
};

template <Port DMA>
static constexpr Register<S5CRBitList, S5CRField> S5CR{BASE_ADDR(DMA), 0x88U};
/**@}*/

/**
 * @defgroup	DMA1_S5NDTR_GROUP		stream x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S5NDTRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class S5NDTRField {
	NDT,		/*!< Number of data items to transfer*/
};

template <Port DMA>
static constexpr Register<S5NDTRBitList, S5NDTRField> S5NDTR{BASE_ADDR(DMA), 0x8cU};
/**@}*/

/**
 * @defgroup	DMA1_S5PAR_GROUP		stream x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S5PARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class S5PARField {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<S5PARBitList, S5PARField> S5PAR{BASE_ADDR(DMA), 0x90U};
/**@}*/

/**
 * @defgroup	DMA1_S5M0AR_GROUP		stream x memory 0 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S5M0ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M0A
					)

enum class S5M0ARField {
	M0A,		/*!< Memory 0 address*/
};

template <Port DMA>
static constexpr Register<S5M0ARBitList, S5M0ARField> S5M0AR{BASE_ADDR(DMA), 0x94U};
/**@}*/

/**
 * @defgroup	DMA1_S5M1AR_GROUP		stream x memory 1 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S5M1ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M1A
					)

enum class S5M1ARField {
	M1A,		/*!< Memory 1 address (used in case of Double buffer mode)*/
};

template <Port DMA>
static constexpr Register<S5M1ARBitList, S5M1ARField> S5M1AR{BASE_ADDR(DMA), 0x98U};
/**@}*/

/**
 * @defgroup	DMA1_S5FCR_GROUP		stream x FIFO control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S5FCRBitList, /**/
					Bit<2>{BitPos_t{0}},	// FTH
					Binary<>{BitPos_t{2}},	// DMDIS
					StatusBit<3>{BitPos_t{3}},	// FS
					Binary<>{BitPos_t{7}}	// FEIE
					)

enum class S5FCRField {
	FTH,		/*!< FIFO threshold selection*/
	DMDIS,		/*!< Direct mode disable*/
	FS,		/*!< FIFO status*/
	FEIE,		/*!< FIFO error interrupt enable*/
};

template <Port DMA>
static constexpr Register<S5FCRBitList, S5FCRField> S5FCR{BASE_ADDR(DMA), 0x9cU};
/**@}*/

/**
 * @defgroup	DMA1_S6CR_GROUP		stream x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S6CRBitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// DMEIE
					Binary<>{BitPos_t{2}},	// TEIE
					Binary<>{BitPos_t{3}},	// HTIE
					Binary<>{BitPos_t{4}},	// TCIE
					Binary<>{BitPos_t{5}},	// PFCTRL
					Bit<2>{BitPos_t{6}},	// DIR
					Binary<>{BitPos_t{8}},	// CIRC
					Binary<>{BitPos_t{9}},	// PINC
					Binary<>{BitPos_t{10}},	// MINC
					Bit<2>{BitPos_t{11}},	// PSIZE
					Bit<2>{BitPos_t{13}},	// MSIZE
					Binary<>{BitPos_t{15}},	// PINCOS
					Bit<2>{BitPos_t{16}},	// PL
					Binary<>{BitPos_t{18}},	// DBM
					Binary<>{BitPos_t{19}},	// CT
					Binary<>{BitPos_t{20}},	// ACK
					Bit<2>{BitPos_t{21}},	// PBURST
					Bit<2>{BitPos_t{23}},	// MBURST
					Bit<3>{BitPos_t{25}}	// CHSEL
					)

enum class S6CRField {
	EN,		/*!< Stream enable / flag stream ready when read low*/
	DMEIE,		/*!< Direct mode error interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	PFCTRL,		/*!< Peripheral flow controller*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral data size*/
	MSIZE,		/*!< Memory data size*/
	PINCOS,		/*!< Peripheral increment offset size*/
	PL,		/*!< Priority level*/
	DBM,		/*!< Double buffer mode*/
	CT,		/*!< Current target (only in double buffer mode)*/
	ACK,		/*!< ACK*/
	PBURST,		/*!< Peripheral burst transfer configuration*/
	MBURST,		/*!< Memory burst transfer configuration*/
	CHSEL,		/*!< Channel selection*/
};

template <Port DMA>
static constexpr Register<S6CRBitList, S6CRField> S6CR{BASE_ADDR(DMA), 0xa0U};
/**@}*/

/**
 * @defgroup	DMA1_S6NDTR_GROUP		stream x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S6NDTRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class S6NDTRField {
	NDT,		/*!< Number of data items to transfer*/
};

template <Port DMA>
static constexpr Register<S6NDTRBitList, S6NDTRField> S6NDTR{BASE_ADDR(DMA), 0xa4U};
/**@}*/

/**
 * @defgroup	DMA1_S6PAR_GROUP		stream x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S6PARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class S6PARField {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<S6PARBitList, S6PARField> S6PAR{BASE_ADDR(DMA), 0xa8U};
/**@}*/

/**
 * @defgroup	DMA1_S6M0AR_GROUP		stream x memory 0 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S6M0ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M0A
					)

enum class S6M0ARField {
	M0A,		/*!< Memory 0 address*/
};

template <Port DMA>
static constexpr Register<S6M0ARBitList, S6M0ARField> S6M0AR{BASE_ADDR(DMA), 0xacU};
/**@}*/

/**
 * @defgroup	DMA1_S6M1AR_GROUP		stream x memory 1 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S6M1ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M1A
					)

enum class S6M1ARField {
	M1A,		/*!< Memory 1 address (used in case of Double buffer mode)*/
};

template <Port DMA>
static constexpr Register<S6M1ARBitList, S6M1ARField> S6M1AR{BASE_ADDR(DMA), 0xb0U};
/**@}*/

/**
 * @defgroup	DMA1_S6FCR_GROUP		stream x FIFO control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S6FCRBitList, /**/
					Bit<2>{BitPos_t{0}},	// FTH
					Binary<>{BitPos_t{2}},	// DMDIS
					StatusBit<3>{BitPos_t{3}},	// FS
					Binary<>{BitPos_t{7}}	// FEIE
					)

enum class S6FCRField {
	FTH,		/*!< FIFO threshold selection*/
	DMDIS,		/*!< Direct mode disable*/
	FS,		/*!< FIFO status*/
	FEIE,		/*!< FIFO error interrupt enable*/
};

template <Port DMA>
static constexpr Register<S6FCRBitList, S6FCRField> S6FCR{BASE_ADDR(DMA), 0xb4U};
/**@}*/

/**
 * @defgroup	DMA1_S7CR_GROUP		stream x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S7CRBitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// DMEIE
					Binary<>{BitPos_t{2}},	// TEIE
					Binary<>{BitPos_t{3}},	// HTIE
					Binary<>{BitPos_t{4}},	// TCIE
					Binary<>{BitPos_t{5}},	// PFCTRL
					Bit<2>{BitPos_t{6}},	// DIR
					Binary<>{BitPos_t{8}},	// CIRC
					Binary<>{BitPos_t{9}},	// PINC
					Binary<>{BitPos_t{10}},	// MINC
					Bit<2>{BitPos_t{11}},	// PSIZE
					Bit<2>{BitPos_t{13}},	// MSIZE
					Binary<>{BitPos_t{15}},	// PINCOS
					Bit<2>{BitPos_t{16}},	// PL
					Binary<>{BitPos_t{18}},	// DBM
					Binary<>{BitPos_t{19}},	// CT
					Binary<>{BitPos_t{20}},	// ACK
					Bit<2>{BitPos_t{21}},	// PBURST
					Bit<2>{BitPos_t{23}},	// MBURST
					Bit<3>{BitPos_t{25}}	// CHSEL
					)

enum class S7CRField {
	EN,		/*!< Stream enable / flag stream ready when read low*/
	DMEIE,		/*!< Direct mode error interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	PFCTRL,		/*!< Peripheral flow controller*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral data size*/
	MSIZE,		/*!< Memory data size*/
	PINCOS,		/*!< Peripheral increment offset size*/
	PL,		/*!< Priority level*/
	DBM,		/*!< Double buffer mode*/
	CT,		/*!< Current target (only in double buffer mode)*/
	ACK,		/*!< ACK*/
	PBURST,		/*!< Peripheral burst transfer configuration*/
	MBURST,		/*!< Memory burst transfer configuration*/
	CHSEL,		/*!< Channel selection*/
};

template <Port DMA>
static constexpr Register<S7CRBitList, S7CRField> S7CR{BASE_ADDR(DMA), 0xb8U};
/**@}*/

/**
 * @defgroup	DMA1_S7NDTR_GROUP		stream x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S7NDTRBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class S7NDTRField {
	NDT,		/*!< Number of data items to transfer*/
};

template <Port DMA>
static constexpr Register<S7NDTRBitList, S7NDTRField> S7NDTR{BASE_ADDR(DMA), 0xbcU};
/**@}*/

/**
 * @defgroup	DMA1_S7PAR_GROUP		stream x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S7PARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class S7PARField {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<S7PARBitList, S7PARField> S7PAR{BASE_ADDR(DMA), 0xc0U};
/**@}*/

/**
 * @defgroup	DMA1_S7M0AR_GROUP		stream x memory 0 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S7M0ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M0A
					)

enum class S7M0ARField {
	M0A,		/*!< Memory 0 address*/
};

template <Port DMA>
static constexpr Register<S7M0ARBitList, S7M0ARField> S7M0AR{BASE_ADDR(DMA), 0xc4U};
/**@}*/

/**
 * @defgroup	DMA1_S7M1AR_GROUP		stream x memory 1 address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S7M1ARBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// M1A
					)

enum class S7M1ARField {
	M1A,		/*!< Memory 1 address (used in case of Double buffer mode)*/
};

template <Port DMA>
static constexpr Register<S7M1ARBitList, S7M1ARField> S7M1AR{BASE_ADDR(DMA), 0xc8U};
/**@}*/

/**
 * @defgroup	DMA1_S7FCR_GROUP		stream x FIFO control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(S7FCRBitList, /**/
					Bit<2>{BitPos_t{0}},	// FTH
					Binary<>{BitPos_t{2}},	// DMDIS
					StatusBit<3>{BitPos_t{3}},	// FS
					Binary<>{BitPos_t{7}}	// FEIE
					)

enum class S7FCRField {
	FTH,		/*!< FIFO threshold selection*/
	DMDIS,		/*!< Direct mode disable*/
	FS,		/*!< FIFO status*/
	FEIE,		/*!< FIFO error interrupt enable*/
};

template <Port DMA>
static constexpr Register<S7FCRBitList, S7FCRField> S7FCR{BASE_ADDR(DMA), 0xccU};
/**@}*/


} // cpp_stm32::dma::reg
