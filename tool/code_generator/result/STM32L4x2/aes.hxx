#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::aes::reg {

static constexpr auto BASE_ADDR = 0x50060000U;

/**
 * @defgroup	AES_CR_GROUP		control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CRBitList, /**/
					Binary<>{BitPos_t{0}},	// EN
					Bit<2>{BitPos_t{1}},	// DATATYPE
					Bit<2>{BitPos_t{3}},	// MODE
					Bit<2>{BitPos_t{5}},	// CHMOD
					Binary<>{BitPos_t{7}},	// CCFC
					Binary<>{BitPos_t{8}},	// ERRC
					Binary<>{BitPos_t{9}},	// CCFIE
					Binary<>{BitPos_t{10}},	// ERRIE
					Binary<>{BitPos_t{11}},	// DMAINEN
					Binary<>{BitPos_t{12}}	// DMAOUTEN
					)

enum class CRField {
	EN,		/*!< AES enable*/
	DATATYPE,		/*!< Data type selection (for data in and data out to/from the cryptographic block)*/
	MODE,		/*!< AES operating mode*/
	CHMOD,		/*!< AES chaining mode*/
	CCFC,		/*!< Computation Complete Flag Clear*/
	ERRC,		/*!< Error clear*/
	CCFIE,		/*!< CCF flag interrupt enable*/
	ERRIE,		/*!< Error interrupt enable*/
	DMAINEN,		/*!< Enable DMA management of data input phase*/
	DMAOUTEN,		/*!< Enable DMA management of data output phase*/
};

static constexpr Register<CRBitList, CRField> CR{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	AES_SR_GROUP		status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(SRBitList, /**/
					Binary<>{BitPos_t{0}},	// CCF
					Binary<>{BitPos_t{1}},	// RDERR
					Binary<>{BitPos_t{2}}	// WRERR
					)

enum class SRField {
	CCF,		/*!< Computation complete flag*/
	RDERR,		/*!< Read error flag*/
	WRERR,		/*!< Write error flag*/
};

static constexpr Register<SRBitList, SRField> SR{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	AES_DINR_GROUP		data input register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DINRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// AES_DINR
					)

enum class DINRField {
	AES_DINR,		/*!< Data Input Register*/
};

static constexpr Register<DINRBitList, DINRField> DINR{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	AES_DOUTR_GROUP		data output register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DOUTRBitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// AES_DOUTR
					)

enum class DOUTRField {
	AES_DOUTR,		/*!< Data output register*/
};

static constexpr Register<DOUTRBitList, DOUTRField> DOUTR{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	AES_KEYR0_GROUP		key register 0 group
 *
 * @{
 */

SETUP_REGISTER_INFO(KEYR0BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// AES_KEYR0
					)

enum class KEYR0Field {
	AES_KEYR0,		/*!< Data Output Register (LSB key [31:0])*/
};

static constexpr Register<KEYR0BitList, KEYR0Field> KEYR0{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	AES_KEYR1_GROUP		key register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(KEYR1BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// AES_KEYR1
					)

enum class KEYR1Field {
	AES_KEYR1,		/*!< AES key register (key [63:32])*/
};

static constexpr Register<KEYR1BitList, KEYR1Field> KEYR1{BASE_ADDR, 0x14U};
/**@}*/

/**
 * @defgroup	AES_KEYR2_GROUP		key register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(KEYR2BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// AES_KEYR2
					)

enum class KEYR2Field {
	AES_KEYR2,		/*!< AES key register (key [95:64])*/
};

static constexpr Register<KEYR2BitList, KEYR2Field> KEYR2{BASE_ADDR, 0x18U};
/**@}*/

/**
 * @defgroup	AES_KEYR3_GROUP		key register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(KEYR3BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// AES_KEYR3
					)

enum class KEYR3Field {
	AES_KEYR3,		/*!< AES key register (MSB key [127:96])*/
};

static constexpr Register<KEYR3BitList, KEYR3Field> KEYR3{BASE_ADDR, 0x1cU};
/**@}*/

/**
 * @defgroup	AES_IVR0_GROUP		initialization vector register 0 group
 *
 * @{
 */

SETUP_REGISTER_INFO(IVR0BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// AES_IVR0
					)

enum class IVR0Field {
	AES_IVR0,		/*!< initialization vector register (LSB IVR [31:0])*/
};

static constexpr Register<IVR0BitList, IVR0Field> IVR0{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	AES_IVR1_GROUP		initialization vector register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(IVR1BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// AES_IVR1
					)

enum class IVR1Field {
	AES_IVR1,		/*!< Initialization Vector Register (IVR [63:32])*/
};

static constexpr Register<IVR1BitList, IVR1Field> IVR1{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	AES_IVR2_GROUP		initialization vector register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(IVR2BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// AES_IVR2
					)

enum class IVR2Field {
	AES_IVR2,		/*!< Initialization Vector Register (IVR [95:64])*/
};

static constexpr Register<IVR2BitList, IVR2Field> IVR2{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	AES_IVR3_GROUP		initialization vector register 3 group
 *
 * @{
 */

SETUP_REGISTER_INFO(IVR3BitList, /**/
					Bit<32, std::uint32_t>{BitPos_t{0}}	// AES_IVR3
					)

enum class IVR3Field {
	AES_IVR3,		/*!< Initialization Vector Register (MSB IVR [127:96])*/
};

static constexpr Register<IVR3BitList, IVR3Field> IVR3{BASE_ADDR, 0x2cU};
/**@}*/


} // cpp_stm32::aes::reg
