#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::dma::reg {

static constexpr auto BASE_ADDR(Port const& t_dma) {
	switch(t_dma) {
	case Port::DMA1:
		return 0x40020000U;
	case Port::DMA2:
		return 0x40020400U;
}
	}

/**
 * @defgroup	DMA2_ISR_GROUP		interrupt status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ISRBitList, /**/
					Bit<7>{BitPos_t{0}},	// GI
					Bit<7>{BitPos_t{1}},	// TCI
					Bit<7>{BitPos_t{2}},	// HTI
					Bit<7>{BitPos_t{3}}	// TEI
					)

enum class ISRField {
	GI,		/*!< Channel x global interrupt flag (x = 1 ..7)*/
	TCI,		/*!< Channel x transfer complete flag (x = 1 ..7)*/
	HTI,		/*!< Channel x half transfer flag (x = 1 ..7)*/
	TEI,		/*!< Channel x transfer error flag (x = 1 ..7)*/
};

template <Port DMA>
static constexpr Register<ISRBitList, ISRField> ISR{BASE_ADDR(DMA), 0x00U};
/**@}*/

/**
 * @defgroup	DMA2_IFCR_GROUP		interrupt flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IFCRBitList, /**/
					Bit<7>{BitPos_t{0}},	// CGI
					Bit<7>{BitPos_t{1}},	// CTCI
					Bit<7>{BitPos_t{2}},	// CHTI
					Bit<7>{BitPos_t{3}}	// CTEI
					)

enum class IFCRField {
	CGI,		/*!< Channel x global interrupt clear (x = 1 ..7)*/
	CTCI,		/*!< Channel x transfer complete clear (x = 1 ..7)*/
	CHTI,		/*!< Channel x half transfer clear (x = 1 ..7)*/
	CTEI,		/*!< Channel x transfer error clear (x = 1 ..7)*/
};

template <Port DMA>
static constexpr Register<IFCRBitList, IFCRField> IFCR{BASE_ADDR(DMA), 0x04U};
/**@}*/

/**
 * @defgroup	DMA2_CCR1_GROUP		channel x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCR1BitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// TCIE
					Binary<>{BitPos_t{2}},	// HTIE
					Binary<>{BitPos_t{3}},	// TEIE
					Binary<>{BitPos_t{4}},	// DIR
					Binary<>{BitPos_t{5}},	// CIRC
					Binary<>{BitPos_t{6}},	// PINC
					Binary<>{BitPos_t{7}},	// MINC
					Bit<2>{BitPos_t{8}},	// PSIZE
					Bit<2>{BitPos_t{10}},	// MSIZE
					Bit<2>{BitPos_t{12}},	// PL
					Binary<>{BitPos_t{14}}	// MEM2MEM
					)

enum class CCR1Field {
	EN,		/*!< Channel enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral size*/
	MSIZE,		/*!< Memory size*/
	PL,		/*!< Channel priority level*/
	MEM2MEM,		/*!< Memory to memory mode*/
};

template <Port DMA>
static constexpr Register<CCR1BitList, CCR1Field> CCR1{BASE_ADDR(DMA), 0x08U};
/**@}*/

/**
 * @defgroup	DMA2_CNDTR1_GROUP		channel x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CNDTR1BitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class CNDTR1Field {
	NDT,		/*!< Number of data to transfer*/
};

template <Port DMA>
static constexpr Register<CNDTR1BitList, CNDTR1Field> CNDTR1{BASE_ADDR(DMA), 0x0cU};
/**@}*/

/**
 * @defgroup	DMA2_CPAR1_GROUP		channel x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CPAR1BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class CPAR1Field {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<CPAR1BitList, CPAR1Field> CPAR1{BASE_ADDR(DMA), 0x10U};
/**@}*/

/**
 * @defgroup	DMA2_CMAR1_GROUP		channel x memory address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CMAR1BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// MA
					)

enum class CMAR1Field {
	MA,		/*!< Memory address*/
};

template <Port DMA>
static constexpr Register<CMAR1BitList, CMAR1Field> CMAR1{BASE_ADDR(DMA), 0x14U};
/**@}*/

/**
 * @defgroup	DMA2_CCR2_GROUP		channel x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCR2BitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// TCIE
					Binary<>{BitPos_t{2}},	// HTIE
					Binary<>{BitPos_t{3}},	// TEIE
					Binary<>{BitPos_t{4}},	// DIR
					Binary<>{BitPos_t{5}},	// CIRC
					Binary<>{BitPos_t{6}},	// PINC
					Binary<>{BitPos_t{7}},	// MINC
					Bit<2>{BitPos_t{8}},	// PSIZE
					Bit<2>{BitPos_t{10}},	// MSIZE
					Bit<2>{BitPos_t{12}},	// PL
					Binary<>{BitPos_t{14}}	// MEM2MEM
					)

enum class CCR2Field {
	EN,		/*!< Channel enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral size*/
	MSIZE,		/*!< Memory size*/
	PL,		/*!< Channel priority level*/
	MEM2MEM,		/*!< Memory to memory mode*/
};

template <Port DMA>
static constexpr Register<CCR2BitList, CCR2Field> CCR2{BASE_ADDR(DMA), 0x1cU};
/**@}*/

/**
 * @defgroup	DMA2_CNDTR2_GROUP		channel x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CNDTR2BitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class CNDTR2Field {
	NDT,		/*!< Number of data to transfer*/
};

template <Port DMA>
static constexpr Register<CNDTR2BitList, CNDTR2Field> CNDTR2{BASE_ADDR(DMA), 0x20U};
/**@}*/

/**
 * @defgroup	DMA2_CPAR2_GROUP		channel x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CPAR2BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class CPAR2Field {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<CPAR2BitList, CPAR2Field> CPAR2{BASE_ADDR(DMA), 0x24U};
/**@}*/

/**
 * @defgroup	DMA2_CMAR2_GROUP		channel x memory address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CMAR2BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// MA
					)

enum class CMAR2Field {
	MA,		/*!< Memory address*/
};

template <Port DMA>
static constexpr Register<CMAR2BitList, CMAR2Field> CMAR2{BASE_ADDR(DMA), 0x28U};
/**@}*/

/**
 * @defgroup	DMA2_CCR3_GROUP		channel x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCR3BitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// TCIE
					Binary<>{BitPos_t{2}},	// HTIE
					Binary<>{BitPos_t{3}},	// TEIE
					Binary<>{BitPos_t{4}},	// DIR
					Binary<>{BitPos_t{5}},	// CIRC
					Binary<>{BitPos_t{6}},	// PINC
					Binary<>{BitPos_t{7}},	// MINC
					Bit<2>{BitPos_t{8}},	// PSIZE
					Bit<2>{BitPos_t{10}},	// MSIZE
					Bit<2>{BitPos_t{12}},	// PL
					Binary<>{BitPos_t{14}}	// MEM2MEM
					)

enum class CCR3Field {
	EN,		/*!< Channel enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral size*/
	MSIZE,		/*!< Memory size*/
	PL,		/*!< Channel priority level*/
	MEM2MEM,		/*!< Memory to memory mode*/
};

template <Port DMA>
static constexpr Register<CCR3BitList, CCR3Field> CCR3{BASE_ADDR(DMA), 0x30U};
/**@}*/

/**
 * @defgroup	DMA2_CNDTR3_GROUP		channel x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CNDTR3BitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class CNDTR3Field {
	NDT,		/*!< Number of data to transfer*/
};

template <Port DMA>
static constexpr Register<CNDTR3BitList, CNDTR3Field> CNDTR3{BASE_ADDR(DMA), 0x34U};
/**@}*/

/**
 * @defgroup	DMA2_CPAR3_GROUP		channel x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CPAR3BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class CPAR3Field {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<CPAR3BitList, CPAR3Field> CPAR3{BASE_ADDR(DMA), 0x38U};
/**@}*/

/**
 * @defgroup	DMA2_CMAR3_GROUP		channel x memory address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CMAR3BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// MA
					)

enum class CMAR3Field {
	MA,		/*!< Memory address*/
};

template <Port DMA>
static constexpr Register<CMAR3BitList, CMAR3Field> CMAR3{BASE_ADDR(DMA), 0x3cU};
/**@}*/

/**
 * @defgroup	DMA2_CCR4_GROUP		channel x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCR4BitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// TCIE
					Binary<>{BitPos_t{2}},	// HTIE
					Binary<>{BitPos_t{3}},	// TEIE
					Binary<>{BitPos_t{4}},	// DIR
					Binary<>{BitPos_t{5}},	// CIRC
					Binary<>{BitPos_t{6}},	// PINC
					Binary<>{BitPos_t{7}},	// MINC
					Bit<2>{BitPos_t{8}},	// PSIZE
					Bit<2>{BitPos_t{10}},	// MSIZE
					Bit<2>{BitPos_t{12}},	// PL
					Binary<>{BitPos_t{14}}	// MEM2MEM
					)

enum class CCR4Field {
	EN,		/*!< Channel enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral size*/
	MSIZE,		/*!< Memory size*/
	PL,		/*!< Channel priority level*/
	MEM2MEM,		/*!< Memory to memory mode*/
};

template <Port DMA>
static constexpr Register<CCR4BitList, CCR4Field> CCR4{BASE_ADDR(DMA), 0x44U};
/**@}*/

/**
 * @defgroup	DMA2_CNDTR4_GROUP		channel x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CNDTR4BitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class CNDTR4Field {
	NDT,		/*!< Number of data to transfer*/
};

template <Port DMA>
static constexpr Register<CNDTR4BitList, CNDTR4Field> CNDTR4{BASE_ADDR(DMA), 0x48U};
/**@}*/

/**
 * @defgroup	DMA2_CPAR4_GROUP		channel x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CPAR4BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class CPAR4Field {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<CPAR4BitList, CPAR4Field> CPAR4{BASE_ADDR(DMA), 0x4cU};
/**@}*/

/**
 * @defgroup	DMA2_CMAR4_GROUP		channel x memory address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CMAR4BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// MA
					)

enum class CMAR4Field {
	MA,		/*!< Memory address*/
};

template <Port DMA>
static constexpr Register<CMAR4BitList, CMAR4Field> CMAR4{BASE_ADDR(DMA), 0x50U};
/**@}*/

/**
 * @defgroup	DMA2_CCR5_GROUP		channel x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCR5BitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// TCIE
					Binary<>{BitPos_t{2}},	// HTIE
					Binary<>{BitPos_t{3}},	// TEIE
					Binary<>{BitPos_t{4}},	// DIR
					Binary<>{BitPos_t{5}},	// CIRC
					Binary<>{BitPos_t{6}},	// PINC
					Binary<>{BitPos_t{7}},	// MINC
					Bit<2>{BitPos_t{8}},	// PSIZE
					Bit<2>{BitPos_t{10}},	// MSIZE
					Bit<2>{BitPos_t{12}},	// PL
					Binary<>{BitPos_t{14}}	// MEM2MEM
					)

enum class CCR5Field {
	EN,		/*!< Channel enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral size*/
	MSIZE,		/*!< Memory size*/
	PL,		/*!< Channel priority level*/
	MEM2MEM,		/*!< Memory to memory mode*/
};

template <Port DMA>
static constexpr Register<CCR5BitList, CCR5Field> CCR5{BASE_ADDR(DMA), 0x58U};
/**@}*/

/**
 * @defgroup	DMA2_CNDTR5_GROUP		channel x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CNDTR5BitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class CNDTR5Field {
	NDT,		/*!< Number of data to transfer*/
};

template <Port DMA>
static constexpr Register<CNDTR5BitList, CNDTR5Field> CNDTR5{BASE_ADDR(DMA), 0x5cU};
/**@}*/

/**
 * @defgroup	DMA2_CPAR5_GROUP		channel x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CPAR5BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class CPAR5Field {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<CPAR5BitList, CPAR5Field> CPAR5{BASE_ADDR(DMA), 0x60U};
/**@}*/

/**
 * @defgroup	DMA2_CMAR5_GROUP		channel x memory address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CMAR5BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// MA
					)

enum class CMAR5Field {
	MA,		/*!< Memory address*/
};

template <Port DMA>
static constexpr Register<CMAR5BitList, CMAR5Field> CMAR5{BASE_ADDR(DMA), 0x64U};
/**@}*/

/**
 * @defgroup	DMA2_CCR6_GROUP		channel x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCR6BitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// TCIE
					Binary<>{BitPos_t{2}},	// HTIE
					Binary<>{BitPos_t{3}},	// TEIE
					Binary<>{BitPos_t{4}},	// DIR
					Binary<>{BitPos_t{5}},	// CIRC
					Binary<>{BitPos_t{6}},	// PINC
					Binary<>{BitPos_t{7}},	// MINC
					Bit<2>{BitPos_t{8}},	// PSIZE
					Bit<2>{BitPos_t{10}},	// MSIZE
					Bit<2>{BitPos_t{12}},	// PL
					Binary<>{BitPos_t{14}}	// MEM2MEM
					)

enum class CCR6Field {
	EN,		/*!< Channel enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral size*/
	MSIZE,		/*!< Memory size*/
	PL,		/*!< Channel priority level*/
	MEM2MEM,		/*!< Memory to memory mode*/
};

template <Port DMA>
static constexpr Register<CCR6BitList, CCR6Field> CCR6{BASE_ADDR(DMA), 0x6cU};
/**@}*/

/**
 * @defgroup	DMA2_CNDTR6_GROUP		channel x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CNDTR6BitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class CNDTR6Field {
	NDT,		/*!< Number of data to transfer*/
};

template <Port DMA>
static constexpr Register<CNDTR6BitList, CNDTR6Field> CNDTR6{BASE_ADDR(DMA), 0x70U};
/**@}*/

/**
 * @defgroup	DMA2_CPAR6_GROUP		channel x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CPAR6BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class CPAR6Field {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<CPAR6BitList, CPAR6Field> CPAR6{BASE_ADDR(DMA), 0x74U};
/**@}*/

/**
 * @defgroup	DMA2_CMAR6_GROUP		channel x memory address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CMAR6BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// MA
					)

enum class CMAR6Field {
	MA,		/*!< Memory address*/
};

template <Port DMA>
static constexpr Register<CMAR6BitList, CMAR6Field> CMAR6{BASE_ADDR(DMA), 0x78U};
/**@}*/

/**
 * @defgroup	DMA2_CCR7_GROUP		channel x configuration register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CCR7BitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Binary<>{BitPos_t{1}},	// TCIE
					Binary<>{BitPos_t{2}},	// HTIE
					Binary<>{BitPos_t{3}},	// TEIE
					Binary<>{BitPos_t{4}},	// DIR
					Binary<>{BitPos_t{5}},	// CIRC
					Binary<>{BitPos_t{6}},	// PINC
					Binary<>{BitPos_t{7}},	// MINC
					Bit<2>{BitPos_t{8}},	// PSIZE
					Bit<2>{BitPos_t{10}},	// MSIZE
					Bit<2>{BitPos_t{12}},	// PL
					Binary<>{BitPos_t{14}}	// MEM2MEM
					)

enum class CCR7Field {
	EN,		/*!< Channel enable*/
	TCIE,		/*!< Transfer complete interrupt enable*/
	HTIE,		/*!< Half transfer interrupt enable*/
	TEIE,		/*!< Transfer error interrupt enable*/
	DIR,		/*!< Data transfer direction*/
	CIRC,		/*!< Circular mode*/
	PINC,		/*!< Peripheral increment mode*/
	MINC,		/*!< Memory increment mode*/
	PSIZE,		/*!< Peripheral size*/
	MSIZE,		/*!< Memory size*/
	PL,		/*!< Channel priority level*/
	MEM2MEM,		/*!< Memory to memory mode*/
};

template <Port DMA>
static constexpr Register<CCR7BitList, CCR7Field> CCR7{BASE_ADDR(DMA), 0x80U};
/**@}*/

/**
 * @defgroup	DMA2_CNDTR7_GROUP		channel x number of data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CNDTR7BitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// NDT
					)

enum class CNDTR7Field {
	NDT,		/*!< Number of data to transfer*/
};

template <Port DMA>
static constexpr Register<CNDTR7BitList, CNDTR7Field> CNDTR7{BASE_ADDR(DMA), 0x84U};
/**@}*/

/**
 * @defgroup	DMA2_CPAR7_GROUP		channel x peripheral address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CPAR7BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// PA
					)

enum class CPAR7Field {
	PA,		/*!< Peripheral address*/
};

template <Port DMA>
static constexpr Register<CPAR7BitList, CPAR7Field> CPAR7{BASE_ADDR(DMA), 0x88U};
/**@}*/

/**
 * @defgroup	DMA2_CMAR7_GROUP		channel x memory address register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CMAR7BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// MA
					)

enum class CMAR7Field {
	MA,		/*!< Memory address*/
};

template <Port DMA>
static constexpr Register<CMAR7BitList, CMAR7Field> CMAR7{BASE_ADDR(DMA), 0x8cU};
/**@}*/

/**
 * @defgroup	DMA2_CSELR_GROUP		channel selection register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CSELRBitList, /**/
					Bit<4>{BitPos_t{0}},	// C1S
					Bit<4>{BitPos_t{4}},	// C2S
					Bit<4>{BitPos_t{8}},	// C3S
					Bit<4>{BitPos_t{12}},	// C4S
					Bit<4>{BitPos_t{16}},	// C5S
					Bit<4>{BitPos_t{20}},	// C6S
					Bit<4>{BitPos_t{24}}	// C7S
					)

enum class CSELRField {
	C1S,		/*!< DMA channel 1 selection*/
	C2S,		/*!< DMA channel 2 selection*/
	C3S,		/*!< DMA channel 3 selection*/
	C4S,		/*!< DMA channel 4 selection*/
	C5S,		/*!< DMA channel 5 selection*/
	C6S,		/*!< DMA channel 6 selection*/
	C7S,		/*!< DMA channel 7 selection*/
};

template <Port DMA>
static constexpr Register<CSELRBitList, CSELRField> CSELR{BASE_ADDR(DMA), 0xa8U};
/**@}*/


} // cpp_stm32::dma::reg
