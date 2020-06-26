#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::dfsdm::reg {

static constexpr auto BASE_ADDR = 0x40016000U;

/**
 * @defgroup	DFSDM_CHCFG0R1_GROUP		channel configuration y register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG0R1BitList, /**/
					Bit<2>{BitPos_t{0}},	// SITP
					Bit<2>{BitPos_t{2}},	// SPICKSEL
					Binary<>{BitPos_t{5}},	// SCDEN
					Binary<>{BitPos_t{6}},	// CKABEN
					Binary<>{BitPos_t{7}},	// CHEN
					Binary<>{BitPos_t{8}},	// CHINSEL
					Bit<2>{BitPos_t{12}},	// DATMPX
					Bit<2>{BitPos_t{14}},	// DATPACK
					Bit<8>{BitPos_t{16}},	// CKOUTDIV
					Binary<>{BitPos_t{30}},	// CKOUTSRC
					Binary<>{BitPos_t{31}}	// DFSDMEN
					)

enum class CHCFG0R1Field {
	SITP,		/*!< SITP*/
	SPICKSEL,		/*!< SPICKSEL*/
	SCDEN,		/*!< SCDEN*/
	CKABEN,		/*!< CKABEN*/
	CHEN,		/*!< CHEN*/
	CHINSEL,		/*!< CHINSEL*/
	DATMPX,		/*!< DATMPX*/
	DATPACK,		/*!< DATPACK*/
	CKOUTDIV,		/*!< CKOUTDIV*/
	CKOUTSRC,		/*!< CKOUTSRC*/
	DFSDMEN,		/*!< DFSDMEN*/
};

static constexpr Register<CHCFG0R1BitList, CHCFG0R1Field> CHCFG0R1{BASE_ADDR, 0x00U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG0R2_GROUP		channel configuration y register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG0R2BitList, /**/
					Bit<5>{BitPos_t{3}},	// DTRBS
					Bit<24, std::uint32_t>{BitPos_t{8}}	// OFFSET
					)

enum class CHCFG0R2Field {
	DTRBS,		/*!< DTRBS*/
	OFFSET,		/*!< OFFSET*/
};

static constexpr Register<CHCFG0R2BitList, CHCFG0R2Field> CHCFG0R2{BASE_ADDR, 0x04U};
/**@}*/

/**
 * @defgroup	DFSDM_AWSCD0R_GROUP		analog watchdog and short-circuit detector register group
 *
 * @{
 */

SETUP_REGISTER_INFO(AWSCD0RBitList, /**/
					Bit<8>{BitPos_t{0}},	// SCDT
					Bit<4>{BitPos_t{12}},	// BKSCD
					Bit<5>{BitPos_t{16}},	// AWFOSR
					Bit<2>{BitPos_t{22}}	// AWFORD
					)

enum class AWSCD0RField {
	SCDT,		/*!< SCDT*/
	BKSCD,		/*!< BKSCD*/
	AWFOSR,		/*!< AWFOSR*/
	AWFORD,		/*!< AWFORD*/
};

static constexpr Register<AWSCD0RBitList, AWSCD0RField> AWSCD0R{BASE_ADDR, 0x08U};
/**@}*/

/**
 * @defgroup	DFSDM_CHWDAT0R_GROUP		channel watchdog filter data register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHWDAT0RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// WDATA
					)

enum class CHWDAT0RField {
	WDATA,		/*!< WDATA*/
};

static constexpr Register<CHWDAT0RBitList, CHWDAT0RField> CHWDAT0R{BASE_ADDR, 0x0cU};
/**@}*/

/**
 * @defgroup	DFSDM_CHDATIN0R_GROUP		channel data input register group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHDATIN0RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}},	// INDAT0
					Bit<16, std::uint16_t>{BitPos_t{16}}	// INDAT1
					)

enum class CHDATIN0RField {
	INDAT0,		/*!< INDAT0*/
	INDAT1,		/*!< INDAT1*/
};

static constexpr Register<CHDATIN0RBitList, CHDATIN0RField> CHDATIN0R{BASE_ADDR, 0x10U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG1R1_GROUP		CHCFG1R1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG1R1BitList, /**/
					Bit<2>{BitPos_t{0}},	// SITP
					Bit<2>{BitPos_t{2}},	// SPICKSEL
					Binary<>{BitPos_t{5}},	// SCDEN
					Binary<>{BitPos_t{6}},	// CKABEN
					Binary<>{BitPos_t{7}},	// CHEN
					Binary<>{BitPos_t{8}},	// CHINSEL
					Bit<2>{BitPos_t{12}},	// DATMPX
					Bit<2>{BitPos_t{14}}	// DATPACK
					)

enum class CHCFG1R1Field {
	SITP,		/*!< SITP*/
	SPICKSEL,		/*!< SPICKSEL*/
	SCDEN,		/*!< SCDEN*/
	CKABEN,		/*!< CKABEN*/
	CHEN,		/*!< CHEN*/
	CHINSEL,		/*!< CHINSEL*/
	DATMPX,		/*!< DATMPX*/
	DATPACK,		/*!< DATPACK*/
};

static constexpr Register<CHCFG1R1BitList, CHCFG1R1Field> CHCFG1R1{BASE_ADDR, 0x20U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG1R2_GROUP		CHCFG1R2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG1R2BitList, /**/
					Bit<5>{BitPos_t{3}},	// DTRBS
					Bit<24, std::uint32_t>{BitPos_t{8}}	// OFFSET
					)

enum class CHCFG1R2Field {
	DTRBS,		/*!< DTRBS*/
	OFFSET,		/*!< OFFSET*/
};

static constexpr Register<CHCFG1R2BitList, CHCFG1R2Field> CHCFG1R2{BASE_ADDR, 0x24U};
/**@}*/

/**
 * @defgroup	DFSDM_AWSCD1R_GROUP		AWSCD1R group
 *
 * @{
 */

SETUP_REGISTER_INFO(AWSCD1RBitList, /**/
					Bit<8>{BitPos_t{0}},	// SCDT
					Bit<4>{BitPos_t{12}},	// BKSCD
					Bit<5>{BitPos_t{16}},	// AWFOSR
					Bit<2>{BitPos_t{22}}	// AWFORD
					)

enum class AWSCD1RField {
	SCDT,		/*!< SCDT*/
	BKSCD,		/*!< BKSCD*/
	AWFOSR,		/*!< AWFOSR*/
	AWFORD,		/*!< AWFORD*/
};

static constexpr Register<AWSCD1RBitList, AWSCD1RField> AWSCD1R{BASE_ADDR, 0x28U};
/**@}*/

/**
 * @defgroup	DFSDM_CHWDAT1R_GROUP		CHWDAT1R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHWDAT1RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// WDATA
					)

enum class CHWDAT1RField {
	WDATA,		/*!< WDATA*/
};

static constexpr Register<CHWDAT1RBitList, CHWDAT1RField> CHWDAT1R{BASE_ADDR, 0x2cU};
/**@}*/

/**
 * @defgroup	DFSDM_CHDATIN1R_GROUP		CHDATIN1R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHDATIN1RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}},	// INDAT0
					Bit<16, std::uint16_t>{BitPos_t{16}}	// INDAT1
					)

enum class CHDATIN1RField {
	INDAT0,		/*!< INDAT0*/
	INDAT1,		/*!< INDAT1*/
};

static constexpr Register<CHDATIN1RBitList, CHDATIN1RField> CHDATIN1R{BASE_ADDR, 0x30U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG2R1_GROUP		CHCFG2R1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG2R1BitList, /**/
					Bit<2>{BitPos_t{0}},	// SITP
					Bit<2>{BitPos_t{2}},	// SPICKSEL
					Binary<>{BitPos_t{5}},	// SCDEN
					Binary<>{BitPos_t{6}},	// CKABEN
					Binary<>{BitPos_t{7}},	// CHEN
					Binary<>{BitPos_t{8}},	// CHINSEL
					Bit<2>{BitPos_t{12}},	// DATMPX
					Bit<2>{BitPos_t{14}}	// DATPACK
					)

enum class CHCFG2R1Field {
	SITP,		/*!< SITP*/
	SPICKSEL,		/*!< SPICKSEL*/
	SCDEN,		/*!< SCDEN*/
	CKABEN,		/*!< CKABEN*/
	CHEN,		/*!< CHEN*/
	CHINSEL,		/*!< CHINSEL*/
	DATMPX,		/*!< DATMPX*/
	DATPACK,		/*!< DATPACK*/
};

static constexpr Register<CHCFG2R1BitList, CHCFG2R1Field> CHCFG2R1{BASE_ADDR, 0x40U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG2R2_GROUP		CHCFG2R2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG2R2BitList, /**/
					Bit<5>{BitPos_t{3}},	// DTRBS
					Bit<24, std::uint32_t>{BitPos_t{8}}	// OFFSET
					)

enum class CHCFG2R2Field {
	DTRBS,		/*!< DTRBS*/
	OFFSET,		/*!< OFFSET*/
};

static constexpr Register<CHCFG2R2BitList, CHCFG2R2Field> CHCFG2R2{BASE_ADDR, 0x44U};
/**@}*/

/**
 * @defgroup	DFSDM_AWSCD2R_GROUP		AWSCD2R group
 *
 * @{
 */

SETUP_REGISTER_INFO(AWSCD2RBitList, /**/
					Bit<8>{BitPos_t{0}},	// SCDT
					Bit<4>{BitPos_t{12}},	// BKSCD
					Bit<5>{BitPos_t{16}},	// AWFOSR
					Bit<2>{BitPos_t{22}}	// AWFORD
					)

enum class AWSCD2RField {
	SCDT,		/*!< SCDT*/
	BKSCD,		/*!< BKSCD*/
	AWFOSR,		/*!< AWFOSR*/
	AWFORD,		/*!< AWFORD*/
};

static constexpr Register<AWSCD2RBitList, AWSCD2RField> AWSCD2R{BASE_ADDR, 0x48U};
/**@}*/

/**
 * @defgroup	DFSDM_CHWDAT2R_GROUP		CHWDAT2R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHWDAT2RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// WDATA
					)

enum class CHWDAT2RField {
	WDATA,		/*!< WDATA*/
};

static constexpr Register<CHWDAT2RBitList, CHWDAT2RField> CHWDAT2R{BASE_ADDR, 0x4cU};
/**@}*/

/**
 * @defgroup	DFSDM_CHDATIN2R_GROUP		CHDATIN2R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHDATIN2RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}},	// INDAT0
					Bit<16, std::uint16_t>{BitPos_t{16}}	// INDAT1
					)

enum class CHDATIN2RField {
	INDAT0,		/*!< INDAT0*/
	INDAT1,		/*!< INDAT1*/
};

static constexpr Register<CHDATIN2RBitList, CHDATIN2RField> CHDATIN2R{BASE_ADDR, 0x50U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG3R1_GROUP		CHCFG3R1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG3R1BitList, /**/
					Bit<2>{BitPos_t{0}},	// SITP
					Bit<2>{BitPos_t{2}},	// SPICKSEL
					Binary<>{BitPos_t{5}},	// SCDEN
					Binary<>{BitPos_t{6}},	// CKABEN
					Binary<>{BitPos_t{7}},	// CHEN
					Binary<>{BitPos_t{8}},	// CHINSEL
					Bit<2>{BitPos_t{12}},	// DATMPX
					Bit<2>{BitPos_t{14}}	// DATPACK
					)

enum class CHCFG3R1Field {
	SITP,		/*!< SITP*/
	SPICKSEL,		/*!< SPICKSEL*/
	SCDEN,		/*!< SCDEN*/
	CKABEN,		/*!< CKABEN*/
	CHEN,		/*!< CHEN*/
	CHINSEL,		/*!< CHINSEL*/
	DATMPX,		/*!< DATMPX*/
	DATPACK,		/*!< DATPACK*/
};

static constexpr Register<CHCFG3R1BitList, CHCFG3R1Field> CHCFG3R1{BASE_ADDR, 0x60U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG3R2_GROUP		CHCFG3R2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG3R2BitList, /**/
					Bit<5>{BitPos_t{3}},	// DTRBS
					Bit<24, std::uint32_t>{BitPos_t{8}}	// OFFSET
					)

enum class CHCFG3R2Field {
	DTRBS,		/*!< DTRBS*/
	OFFSET,		/*!< OFFSET*/
};

static constexpr Register<CHCFG3R2BitList, CHCFG3R2Field> CHCFG3R2{BASE_ADDR, 0x64U};
/**@}*/

/**
 * @defgroup	DFSDM_AWSCD3R_GROUP		AWSCD3R group
 *
 * @{
 */

SETUP_REGISTER_INFO(AWSCD3RBitList, /**/
					Bit<8>{BitPos_t{0}},	// SCDT
					Bit<4>{BitPos_t{12}},	// BKSCD
					Bit<5>{BitPos_t{16}},	// AWFOSR
					Bit<2>{BitPos_t{22}}	// AWFORD
					)

enum class AWSCD3RField {
	SCDT,		/*!< SCDT*/
	BKSCD,		/*!< BKSCD*/
	AWFOSR,		/*!< AWFOSR*/
	AWFORD,		/*!< AWFORD*/
};

static constexpr Register<AWSCD3RBitList, AWSCD3RField> AWSCD3R{BASE_ADDR, 0x68U};
/**@}*/

/**
 * @defgroup	DFSDM_CHWDAT3R_GROUP		CHWDAT3R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHWDAT3RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// WDATA
					)

enum class CHWDAT3RField {
	WDATA,		/*!< WDATA*/
};

static constexpr Register<CHWDAT3RBitList, CHWDAT3RField> CHWDAT3R{BASE_ADDR, 0x6cU};
/**@}*/

/**
 * @defgroup	DFSDM_CHDATIN3R_GROUP		CHDATIN3R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHDATIN3RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}},	// INDAT0
					Bit<16, std::uint16_t>{BitPos_t{16}}	// INDAT1
					)

enum class CHDATIN3RField {
	INDAT0,		/*!< INDAT0*/
	INDAT1,		/*!< INDAT1*/
};

static constexpr Register<CHDATIN3RBitList, CHDATIN3RField> CHDATIN3R{BASE_ADDR, 0x70U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG4R1_GROUP		CHCFG4R1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG4R1BitList, /**/
					Bit<2>{BitPos_t{0}},	// SITP
					Bit<2>{BitPos_t{2}},	// SPICKSEL
					Binary<>{BitPos_t{5}},	// SCDEN
					Binary<>{BitPos_t{6}},	// CKABEN
					Binary<>{BitPos_t{7}},	// CHEN
					Binary<>{BitPos_t{8}},	// CHINSEL
					Bit<2>{BitPos_t{12}},	// DATMPX
					Bit<2>{BitPos_t{14}}	// DATPACK
					)

enum class CHCFG4R1Field {
	SITP,		/*!< SITP*/
	SPICKSEL,		/*!< SPICKSEL*/
	SCDEN,		/*!< SCDEN*/
	CKABEN,		/*!< CKABEN*/
	CHEN,		/*!< CHEN*/
	CHINSEL,		/*!< CHINSEL*/
	DATMPX,		/*!< DATMPX*/
	DATPACK,		/*!< DATPACK*/
};

static constexpr Register<CHCFG4R1BitList, CHCFG4R1Field> CHCFG4R1{BASE_ADDR, 0x80U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG4R2_GROUP		CHCFG4R2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG4R2BitList, /**/
					Bit<5>{BitPos_t{3}},	// DTRBS
					Bit<24, std::uint32_t>{BitPos_t{8}}	// OFFSET
					)

enum class CHCFG4R2Field {
	DTRBS,		/*!< DTRBS*/
	OFFSET,		/*!< OFFSET*/
};

static constexpr Register<CHCFG4R2BitList, CHCFG4R2Field> CHCFG4R2{BASE_ADDR, 0x84U};
/**@}*/

/**
 * @defgroup	DFSDM_AWSCD4R_GROUP		AWSCD4R group
 *
 * @{
 */

SETUP_REGISTER_INFO(AWSCD4RBitList, /**/
					Bit<8>{BitPos_t{0}},	// SCDT
					Bit<4>{BitPos_t{12}},	// BKSCD
					Bit<5>{BitPos_t{16}},	// AWFOSR
					Bit<2>{BitPos_t{22}}	// AWFORD
					)

enum class AWSCD4RField {
	SCDT,		/*!< SCDT*/
	BKSCD,		/*!< BKSCD*/
	AWFOSR,		/*!< AWFOSR*/
	AWFORD,		/*!< AWFORD*/
};

static constexpr Register<AWSCD4RBitList, AWSCD4RField> AWSCD4R{BASE_ADDR, 0x88U};
/**@}*/

/**
 * @defgroup	DFSDM_CHWDAT4R_GROUP		CHWDAT4R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHWDAT4RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// WDATA
					)

enum class CHWDAT4RField {
	WDATA,		/*!< WDATA*/
};

static constexpr Register<CHWDAT4RBitList, CHWDAT4RField> CHWDAT4R{BASE_ADDR, 0x8cU};
/**@}*/

/**
 * @defgroup	DFSDM_CHDATIN4R_GROUP		CHDATIN4R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHDATIN4RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}},	// INDAT0
					Bit<16, std::uint16_t>{BitPos_t{16}}	// INDAT1
					)

enum class CHDATIN4RField {
	INDAT0,		/*!< INDAT0*/
	INDAT1,		/*!< INDAT1*/
};

static constexpr Register<CHDATIN4RBitList, CHDATIN4RField> CHDATIN4R{BASE_ADDR, 0x90U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG5R1_GROUP		CHCFG5R1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG5R1BitList, /**/
					Bit<2>{BitPos_t{0}},	// SITP
					Bit<2>{BitPos_t{2}},	// SPICKSEL
					Binary<>{BitPos_t{5}},	// SCDEN
					Binary<>{BitPos_t{6}},	// CKABEN
					Binary<>{BitPos_t{7}},	// CHEN
					Binary<>{BitPos_t{8}},	// CHINSEL
					Bit<2>{BitPos_t{12}},	// DATMPX
					Bit<2>{BitPos_t{14}}	// DATPACK
					)

enum class CHCFG5R1Field {
	SITP,		/*!< SITP*/
	SPICKSEL,		/*!< SPICKSEL*/
	SCDEN,		/*!< SCDEN*/
	CKABEN,		/*!< CKABEN*/
	CHEN,		/*!< CHEN*/
	CHINSEL,		/*!< CHINSEL*/
	DATMPX,		/*!< DATMPX*/
	DATPACK,		/*!< DATPACK*/
};

static constexpr Register<CHCFG5R1BitList, CHCFG5R1Field> CHCFG5R1{BASE_ADDR, 0xa0U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG5R2_GROUP		CHCFG5R2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG5R2BitList, /**/
					Bit<5>{BitPos_t{3}},	// DTRBS
					Bit<24, std::uint32_t>{BitPos_t{8}}	// OFFSET
					)

enum class CHCFG5R2Field {
	DTRBS,		/*!< DTRBS*/
	OFFSET,		/*!< OFFSET*/
};

static constexpr Register<CHCFG5R2BitList, CHCFG5R2Field> CHCFG5R2{BASE_ADDR, 0xa4U};
/**@}*/

/**
 * @defgroup	DFSDM_AWSCD5R_GROUP		AWSCD5R group
 *
 * @{
 */

SETUP_REGISTER_INFO(AWSCD5RBitList, /**/
					Bit<8>{BitPos_t{0}},	// SCDT
					Bit<4>{BitPos_t{12}},	// BKSCD
					Bit<5>{BitPos_t{16}},	// AWFOSR
					Bit<2>{BitPos_t{22}}	// AWFORD
					)

enum class AWSCD5RField {
	SCDT,		/*!< SCDT*/
	BKSCD,		/*!< BKSCD*/
	AWFOSR,		/*!< AWFOSR*/
	AWFORD,		/*!< AWFORD*/
};

static constexpr Register<AWSCD5RBitList, AWSCD5RField> AWSCD5R{BASE_ADDR, 0xa8U};
/**@}*/

/**
 * @defgroup	DFSDM_CHWDAT5R_GROUP		CHWDAT5R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHWDAT5RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// WDATA
					)

enum class CHWDAT5RField {
	WDATA,		/*!< WDATA*/
};

static constexpr Register<CHWDAT5RBitList, CHWDAT5RField> CHWDAT5R{BASE_ADDR, 0xacU};
/**@}*/

/**
 * @defgroup	DFSDM_CHDATIN5R_GROUP		CHDATIN5R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHDATIN5RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}},	// INDAT0
					Bit<16, std::uint16_t>{BitPos_t{16}}	// INDAT1
					)

enum class CHDATIN5RField {
	INDAT0,		/*!< INDAT0*/
	INDAT1,		/*!< INDAT1*/
};

static constexpr Register<CHDATIN5RBitList, CHDATIN5RField> CHDATIN5R{BASE_ADDR, 0xb0U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG6R1_GROUP		CHCFG6R1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG6R1BitList, /**/
					Bit<2>{BitPos_t{0}},	// SITP
					Bit<2>{BitPos_t{2}},	// SPICKSEL
					Binary<>{BitPos_t{5}},	// SCDEN
					Binary<>{BitPos_t{6}},	// CKABEN
					Binary<>{BitPos_t{7}},	// CHEN
					Binary<>{BitPos_t{8}},	// CHINSEL
					Bit<2>{BitPos_t{12}},	// DATMPX
					Bit<2>{BitPos_t{14}}	// DATPACK
					)

enum class CHCFG6R1Field {
	SITP,		/*!< SITP*/
	SPICKSEL,		/*!< SPICKSEL*/
	SCDEN,		/*!< SCDEN*/
	CKABEN,		/*!< CKABEN*/
	CHEN,		/*!< CHEN*/
	CHINSEL,		/*!< CHINSEL*/
	DATMPX,		/*!< DATMPX*/
	DATPACK,		/*!< DATPACK*/
};

static constexpr Register<CHCFG6R1BitList, CHCFG6R1Field> CHCFG6R1{BASE_ADDR, 0xc0U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG6R2_GROUP		CHCFG6R2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG6R2BitList, /**/
					Bit<5>{BitPos_t{3}},	// DTRBS
					Bit<24, std::uint32_t>{BitPos_t{8}}	// OFFSET
					)

enum class CHCFG6R2Field {
	DTRBS,		/*!< DTRBS*/
	OFFSET,		/*!< OFFSET*/
};

static constexpr Register<CHCFG6R2BitList, CHCFG6R2Field> CHCFG6R2{BASE_ADDR, 0xc4U};
/**@}*/

/**
 * @defgroup	DFSDM_AWSCD6R_GROUP		AWSCD6R group
 *
 * @{
 */

SETUP_REGISTER_INFO(AWSCD6RBitList, /**/
					Bit<8>{BitPos_t{0}},	// SCDT
					Bit<4>{BitPos_t{12}},	// BKSCD
					Bit<5>{BitPos_t{16}},	// AWFOSR
					Bit<2>{BitPos_t{22}}	// AWFORD
					)

enum class AWSCD6RField {
	SCDT,		/*!< SCDT*/
	BKSCD,		/*!< BKSCD*/
	AWFOSR,		/*!< AWFOSR*/
	AWFORD,		/*!< AWFORD*/
};

static constexpr Register<AWSCD6RBitList, AWSCD6RField> AWSCD6R{BASE_ADDR, 0xc8U};
/**@}*/

/**
 * @defgroup	DFSDM_CHWDAT6R_GROUP		CHWDAT6R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHWDAT6RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// WDATA
					)

enum class CHWDAT6RField {
	WDATA,		/*!< WDATA*/
};

static constexpr Register<CHWDAT6RBitList, CHWDAT6RField> CHWDAT6R{BASE_ADDR, 0xccU};
/**@}*/

/**
 * @defgroup	DFSDM_CHDATIN6R_GROUP		CHDATIN6R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHDATIN6RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}},	// INDAT0
					Bit<16, std::uint16_t>{BitPos_t{16}}	// INDAT1
					)

enum class CHDATIN6RField {
	INDAT0,		/*!< INDAT0*/
	INDAT1,		/*!< INDAT1*/
};

static constexpr Register<CHDATIN6RBitList, CHDATIN6RField> CHDATIN6R{BASE_ADDR, 0xd0U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG7R1_GROUP		CHCFG7R1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG7R1BitList, /**/
					Bit<2>{BitPos_t{0}},	// SITP
					Bit<2>{BitPos_t{2}},	// SPICKSEL
					Binary<>{BitPos_t{5}},	// SCDEN
					Binary<>{BitPos_t{6}},	// CKABEN
					Binary<>{BitPos_t{7}},	// CHEN
					Binary<>{BitPos_t{8}},	// CHINSEL
					Bit<2>{BitPos_t{12}},	// DATMPX
					Bit<2>{BitPos_t{14}}	// DATPACK
					)

enum class CHCFG7R1Field {
	SITP,		/*!< SITP*/
	SPICKSEL,		/*!< SPICKSEL*/
	SCDEN,		/*!< SCDEN*/
	CKABEN,		/*!< CKABEN*/
	CHEN,		/*!< CHEN*/
	CHINSEL,		/*!< CHINSEL*/
	DATMPX,		/*!< DATMPX*/
	DATPACK,		/*!< DATPACK*/
};

static constexpr Register<CHCFG7R1BitList, CHCFG7R1Field> CHCFG7R1{BASE_ADDR, 0xe0U};
/**@}*/

/**
 * @defgroup	DFSDM_CHCFG7R2_GROUP		CHCFG7R2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHCFG7R2BitList, /**/
					Bit<5>{BitPos_t{3}},	// DTRBS
					Bit<24, std::uint32_t>{BitPos_t{8}}	// OFFSET
					)

enum class CHCFG7R2Field {
	DTRBS,		/*!< DTRBS*/
	OFFSET,		/*!< OFFSET*/
};

static constexpr Register<CHCFG7R2BitList, CHCFG7R2Field> CHCFG7R2{BASE_ADDR, 0xe4U};
/**@}*/

/**
 * @defgroup	DFSDM_AWSCD7R_GROUP		AWSCD7R group
 *
 * @{
 */

SETUP_REGISTER_INFO(AWSCD7RBitList, /**/
					Bit<8>{BitPos_t{0}},	// SCDT
					Bit<4>{BitPos_t{12}},	// BKSCD
					Bit<5>{BitPos_t{16}},	// AWFOSR
					Bit<2>{BitPos_t{22}}	// AWFORD
					)

enum class AWSCD7RField {
	SCDT,		/*!< SCDT*/
	BKSCD,		/*!< BKSCD*/
	AWFOSR,		/*!< AWFOSR*/
	AWFORD,		/*!< AWFORD*/
};

static constexpr Register<AWSCD7RBitList, AWSCD7RField> AWSCD7R{BASE_ADDR, 0xe8U};
/**@}*/

/**
 * @defgroup	DFSDM_CHWDAT7R_GROUP		CHWDAT7R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHWDAT7RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}}	// WDATA
					)

enum class CHWDAT7RField {
	WDATA,		/*!< WDATA*/
};

static constexpr Register<CHWDAT7RBitList, CHWDAT7RField> CHWDAT7R{BASE_ADDR, 0xecU};
/**@}*/

/**
 * @defgroup	DFSDM_CHDATIN7R_GROUP		CHDATIN7R group
 *
 * @{
 */

SETUP_REGISTER_INFO(CHDATIN7RBitList, /**/
					Bit<16, std::uint16_t>{BitPos_t{0}},	// INDAT0
					Bit<16, std::uint16_t>{BitPos_t{16}}	// INDAT1
					)

enum class CHDATIN7RField {
	INDAT0,		/*!< INDAT0*/
	INDAT1,		/*!< INDAT1*/
};

static constexpr Register<CHDATIN7RBitList, CHDATIN7RField> CHDATIN7R{BASE_ADDR, 0xf0U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_CR1_GROUP		control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_CR1BitList, /**/
					Binary<>{BitPos_t{0}},	// DFEN
					Binary<>{BitPos_t{1}},	// JSWSTART
					Binary<>{BitPos_t{3}},	// JSYNC
					Binary<>{BitPos_t{4}},	// JSCAN
					Binary<>{BitPos_t{5}},	// JDMAEN
					Bit<3>{BitPos_t{8}},	// JEXTSEL
					Bit<2>{BitPos_t{13}},	// JEXTEN
					Binary<>{BitPos_t{17}},	// RSWSTART
					Binary<>{BitPos_t{18}},	// RCONT
					Binary<>{BitPos_t{19}},	// RSYNC
					Binary<>{BitPos_t{21}},	// RDMAEN
					Bit<3>{BitPos_t{24}},	// RCH
					Binary<>{BitPos_t{29}},	// FAST
					Binary<>{BitPos_t{30}}	// AWFSEL
					)

enum class DFSDM0_CR1Field {
	DFEN,		/*!< DFSDM enable*/
	JSWSTART,		/*!< Start a conversion of the injected group of channels*/
	JSYNC,		/*!< Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger*/
	JSCAN,		/*!< Scanning conversion mode for injected conversions*/
	JDMAEN,		/*!< DMA channel enabled to read data for the injected channel group*/
	JEXTSEL,		/*!< Trigger signal selection for launching injected conversions*/
	JEXTEN,		/*!< Trigger enable and trigger edge selection for injected conversions*/
	RSWSTART,		/*!< Software start of a conversion on the regular channel*/
	RCONT,		/*!< Continuous mode selection for regular conversions*/
	RSYNC,		/*!< Launch regular conversion synchronously with DFSDM0*/
	RDMAEN,		/*!< DMA channel enabled to read data for the regular conversion*/
	RCH,		/*!< Regular channel selection*/
	FAST,		/*!< Fast conversion mode selection for regular conversions*/
	AWFSEL,		/*!< Analog watchdog fast mode select*/
};

static constexpr Register<DFSDM0_CR1BitList, DFSDM0_CR1Field> DFSDM0_CR1{BASE_ADDR, 0x100U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_CR2_GROUP		control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_CR2BitList, /**/
					Binary<>{BitPos_t{0}},	// JEOCIE
					Binary<>{BitPos_t{1}},	// REOCIE
					Binary<>{BitPos_t{2}},	// JOVRIE
					Binary<>{BitPos_t{3}},	// ROVRIE
					Binary<>{BitPos_t{4}},	// AWDIE
					Binary<>{BitPos_t{5}},	// SCDIE
					Binary<>{BitPos_t{6}},	// CKABIE
					Bit<8>{BitPos_t{8}},	// EXCH
					Bit<8>{BitPos_t{16}}	// AWDCH
					)

enum class DFSDM0_CR2Field {
	JEOCIE,		/*!< Injected end of conversion interrupt enable*/
	REOCIE,		/*!< Regular end of conversion interrupt enable*/
	JOVRIE,		/*!< Injected data overrun interrupt enable*/
	ROVRIE,		/*!< Regular data overrun interrupt enable*/
	AWDIE,		/*!< Analog watchdog interrupt enable*/
	SCDIE,		/*!< Short-circuit detector interrupt enable*/
	CKABIE,		/*!< Clock absence interrupt enable*/
	EXCH,		/*!< Extremes detector channel selection*/
	AWDCH,		/*!< Analog watchdog channel selection*/
};

static constexpr Register<DFSDM0_CR2BitList, DFSDM0_CR2Field> DFSDM0_CR2{BASE_ADDR, 0x104U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_ISR_GROUP		interrupt and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_ISRBitList, /**/
					Binary<>{BitPos_t{0}},	// JEOCF
					Binary<>{BitPos_t{1}},	// REOCF
					Binary<>{BitPos_t{2}},	// JOVRF
					Binary<>{BitPos_t{3}},	// ROVRF
					Binary<>{BitPos_t{4}},	// AWDF
					Binary<>{BitPos_t{13}},	// JCIP
					Binary<>{BitPos_t{14}},	// RCIP
					Bit<8>{BitPos_t{16}},	// CKABF
					Bit<8>{BitPos_t{24}}	// SCDF
					)

enum class DFSDM0_ISRField {
	JEOCF,		/*!< End of injected conversion flag*/
	REOCF,		/*!< End of regular conversion flag*/
	JOVRF,		/*!< Injected conversion overrun flag*/
	ROVRF,		/*!< Regular conversion overrun flag*/
	AWDF,		/*!< Analog watchdog*/
	JCIP,		/*!< Injected conversion in progress status*/
	RCIP,		/*!< Regular conversion in progress status*/
	CKABF,		/*!< Clock absence flag*/
	SCDF,		/*!< short-circuit detector flag*/
};

static constexpr Register<DFSDM0_ISRBitList, DFSDM0_ISRField> DFSDM0_ISR{BASE_ADDR, 0x108U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_ICR_GROUP		interrupt flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_ICRBitList, /**/
					Binary<>{BitPos_t{2}},	// CLRJOVRF
					Binary<>{BitPos_t{3}},	// CLRROVRF
					Bit<8>{BitPos_t{16}},	// CLRCKABF
					Bit<8>{BitPos_t{24}}	// CLRSCDF
					)

enum class DFSDM0_ICRField {
	CLRJOVRF,		/*!< Clear the injected conversion overrun flag*/
	CLRROVRF,		/*!< Clear the regular conversion overrun flag*/
	CLRCKABF,		/*!< Clear the clock absence flag*/
	CLRSCDF,		/*!< Clear the short-circuit detector flag*/
};

static constexpr Register<DFSDM0_ICRBitList, DFSDM0_ICRField> DFSDM0_ICR{BASE_ADDR, 0x10cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_JCHGR_GROUP		injected channel group selection register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_JCHGRBitList, /**/
					Bit<8>{BitPos_t{0}}	// JCHG
					)

enum class DFSDM0_JCHGRField {
	JCHG,		/*!< Injected channel group selection*/
};

static constexpr Register<DFSDM0_JCHGRBitList, DFSDM0_JCHGRField> DFSDM0_JCHGR{BASE_ADDR, 0x110U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_FCR_GROUP		filter control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_FCRBitList, /**/
					Bit<8>{BitPos_t{0}},	// IOSR
					Bit<10, std::uint16_t>{BitPos_t{16}},	// FOSR
					Bit<3>{BitPos_t{29}}	// FORD
					)

enum class DFSDM0_FCRField {
	IOSR,		/*!< Integrator oversampling ratio (averaging length)*/
	FOSR,		/*!< Sinc filter oversampling ratio (decimation rate)*/
	FORD,		/*!< Sinc filter order*/
};

static constexpr Register<DFSDM0_FCRBitList, DFSDM0_FCRField> DFSDM0_FCR{BASE_ADDR, 0x114U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_JDATAR_GROUP		data register for injected group group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_JDATARBitList, /**/
					Bit<3>{BitPos_t{0}},	// JDATACH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// JDATA
					)

enum class DFSDM0_JDATARField {
	JDATACH,		/*!< Injected channel most recently converted*/
	JDATA,		/*!< Injected group conversion data*/
};

static constexpr Register<DFSDM0_JDATARBitList, DFSDM0_JDATARField> DFSDM0_JDATAR{BASE_ADDR, 0x118U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_RDATAR_GROUP		data register for the regular channel group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_RDATARBitList, /**/
					Bit<3>{BitPos_t{0}},	// RDATACH
					Binary<>{BitPos_t{4}},	// RPEND
					Bit<24, std::uint32_t>{BitPos_t{8}}	// RDATA
					)

enum class DFSDM0_RDATARField {
	RDATACH,		/*!< Regular channel most recently converted*/
	RPEND,		/*!< Regular channel pending data*/
	RDATA,		/*!< Regular channel conversion data*/
};

static constexpr Register<DFSDM0_RDATARBitList, DFSDM0_RDATARField> DFSDM0_RDATAR{BASE_ADDR, 0x11cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_AWHTR_GROUP		analog watchdog high threshold register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_AWHTRBitList, /**/
					Bit<4>{BitPos_t{0}},	// BKAWH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// AWHT
					)

enum class DFSDM0_AWHTRField {
	BKAWH,		/*!< Break signal assignment to analog watchdog high threshold event*/
	AWHT,		/*!< Analog watchdog high threshold*/
};

static constexpr Register<DFSDM0_AWHTRBitList, DFSDM0_AWHTRField> DFSDM0_AWHTR{BASE_ADDR, 0x120U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_AWLTR_GROUP		analog watchdog low threshold register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_AWLTRBitList, /**/
					Bit<4>{BitPos_t{0}},	// BKAWL
					Bit<24, std::uint32_t>{BitPos_t{8}}	// AWLT
					)

enum class DFSDM0_AWLTRField {
	BKAWL,		/*!< Break signal assignment to analog watchdog low threshold event*/
	AWLT,		/*!< Analog watchdog low threshold*/
};

static constexpr Register<DFSDM0_AWLTRBitList, DFSDM0_AWLTRField> DFSDM0_AWLTR{BASE_ADDR, 0x124U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_AWSR_GROUP		analog watchdog status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_AWSRBitList, /**/
					Bit<8>{BitPos_t{0}},	// AWLTF
					Bit<8>{BitPos_t{8}}	// AWHTF
					)

enum class DFSDM0_AWSRField {
	AWLTF,		/*!< Analog watchdog low threshold flag*/
	AWHTF,		/*!< Analog watchdog high threshold flag*/
};

static constexpr Register<DFSDM0_AWSRBitList, DFSDM0_AWSRField> DFSDM0_AWSR{BASE_ADDR, 0x128U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_AWCFR_GROUP		analog watchdog clear flag register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_AWCFRBitList, /**/
					Bit<8>{BitPos_t{0}},	// CLRAWLTF
					Bit<8>{BitPos_t{8}}	// CLRAWHTF
					)

enum class DFSDM0_AWCFRField {
	CLRAWLTF,		/*!< Clear the analog watchdog low threshold flag*/
	CLRAWHTF,		/*!< Clear the analog watchdog high threshold flag*/
};

static constexpr Register<DFSDM0_AWCFRBitList, DFSDM0_AWCFRField> DFSDM0_AWCFR{BASE_ADDR, 0x12cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_EXMAX_GROUP		Extremes detector maximum register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_EXMAXBitList, /**/
					Bit<3>{BitPos_t{0}},	// EXMAXCH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// EXMAX
					)

enum class DFSDM0_EXMAXField {
	EXMAXCH,		/*!< Extremes detector maximum data channel*/
	EXMAX,		/*!< Extremes detector maximum value*/
};

static constexpr Register<DFSDM0_EXMAXBitList, DFSDM0_EXMAXField> DFSDM0_EXMAX{BASE_ADDR, 0x130U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_EXMIN_GROUP		Extremes detector minimum register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_EXMINBitList, /**/
					Bit<3>{BitPos_t{0}},	// EXMINCH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// EXMIN
					)

enum class DFSDM0_EXMINField {
	EXMINCH,		/*!< Extremes detector minimum data channel*/
	EXMIN,		/*!< EXMIN*/
};

static constexpr Register<DFSDM0_EXMINBitList, DFSDM0_EXMINField> DFSDM0_EXMIN{BASE_ADDR, 0x134U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM0_CNVTIMR_GROUP		conversion timer register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM0_CNVTIMRBitList, /**/
					Bit<28, std::uint32_t>{BitPos_t{4}}	// CNVCNT
					)

enum class DFSDM0_CNVTIMRField {
	CNVCNT,		/*!< 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN*/
};

static constexpr Register<DFSDM0_CNVTIMRBitList, DFSDM0_CNVTIMRField> DFSDM0_CNVTIMR{BASE_ADDR, 0x138U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_CR1_GROUP		control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_CR1BitList, /**/
					Binary<>{BitPos_t{0}},	// DFEN
					Binary<>{BitPos_t{1}},	// JSWSTART
					Binary<>{BitPos_t{3}},	// JSYNC
					Binary<>{BitPos_t{4}},	// JSCAN
					Binary<>{BitPos_t{5}},	// JDMAEN
					Bit<3>{BitPos_t{8}},	// JEXTSEL
					Bit<2>{BitPos_t{13}},	// JEXTEN
					Binary<>{BitPos_t{17}},	// RSWSTART
					Binary<>{BitPos_t{18}},	// RCONT
					Binary<>{BitPos_t{19}},	// RSYNC
					Binary<>{BitPos_t{21}},	// RDMAEN
					Bit<3>{BitPos_t{24}},	// RCH
					Binary<>{BitPos_t{29}},	// FAST
					Binary<>{BitPos_t{30}}	// AWFSEL
					)

enum class DFSDM1_CR1Field {
	DFEN,		/*!< DFSDM enable*/
	JSWSTART,		/*!< Start a conversion of the injected group of channels*/
	JSYNC,		/*!< Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger*/
	JSCAN,		/*!< Scanning conversion mode for injected conversions*/
	JDMAEN,		/*!< DMA channel enabled to read data for the injected channel group*/
	JEXTSEL,		/*!< Trigger signal selection for launching injected conversions*/
	JEXTEN,		/*!< Trigger enable and trigger edge selection for injected conversions*/
	RSWSTART,		/*!< Software start of a conversion on the regular channel*/
	RCONT,		/*!< Continuous mode selection for regular conversions*/
	RSYNC,		/*!< Launch regular conversion synchronously with DFSDM0*/
	RDMAEN,		/*!< DMA channel enabled to read data for the regular conversion*/
	RCH,		/*!< Regular channel selection*/
	FAST,		/*!< Fast conversion mode selection for regular conversions*/
	AWFSEL,		/*!< Analog watchdog fast mode select*/
};

static constexpr Register<DFSDM1_CR1BitList, DFSDM1_CR1Field> DFSDM1_CR1{BASE_ADDR, 0x200U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_CR2_GROUP		control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_CR2BitList, /**/
					Binary<>{BitPos_t{0}},	// JEOCIE
					Binary<>{BitPos_t{1}},	// REOCIE
					Binary<>{BitPos_t{2}},	// JOVRIE
					Binary<>{BitPos_t{3}},	// ROVRIE
					Binary<>{BitPos_t{4}},	// AWDIE
					Binary<>{BitPos_t{5}},	// SCDIE
					Binary<>{BitPos_t{6}},	// CKABIE
					Bit<8>{BitPos_t{8}},	// EXCH
					Bit<8>{BitPos_t{16}}	// AWDCH
					)

enum class DFSDM1_CR2Field {
	JEOCIE,		/*!< Injected end of conversion interrupt enable*/
	REOCIE,		/*!< Regular end of conversion interrupt enable*/
	JOVRIE,		/*!< Injected data overrun interrupt enable*/
	ROVRIE,		/*!< Regular data overrun interrupt enable*/
	AWDIE,		/*!< Analog watchdog interrupt enable*/
	SCDIE,		/*!< Short-circuit detector interrupt enable*/
	CKABIE,		/*!< Clock absence interrupt enable*/
	EXCH,		/*!< Extremes detector channel selection*/
	AWDCH,		/*!< Analog watchdog channel selection*/
};

static constexpr Register<DFSDM1_CR2BitList, DFSDM1_CR2Field> DFSDM1_CR2{BASE_ADDR, 0x204U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_ISR_GROUP		interrupt and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_ISRBitList, /**/
					Binary<>{BitPos_t{0}},	// JEOCF
					Binary<>{BitPos_t{1}},	// REOCF
					Binary<>{BitPos_t{2}},	// JOVRF
					Binary<>{BitPos_t{3}},	// ROVRF
					Binary<>{BitPos_t{4}},	// AWDF
					Binary<>{BitPos_t{13}},	// JCIP
					Binary<>{BitPos_t{14}},	// RCIP
					Bit<8>{BitPos_t{16}},	// CKABF
					Bit<8>{BitPos_t{24}}	// SCDF
					)

enum class DFSDM1_ISRField {
	JEOCF,		/*!< End of injected conversion flag*/
	REOCF,		/*!< End of regular conversion flag*/
	JOVRF,		/*!< Injected conversion overrun flag*/
	ROVRF,		/*!< Regular conversion overrun flag*/
	AWDF,		/*!< Analog watchdog*/
	JCIP,		/*!< Injected conversion in progress status*/
	RCIP,		/*!< Regular conversion in progress status*/
	CKABF,		/*!< Clock absence flag*/
	SCDF,		/*!< short-circuit detector flag*/
};

static constexpr Register<DFSDM1_ISRBitList, DFSDM1_ISRField> DFSDM1_ISR{BASE_ADDR, 0x208U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_ICR_GROUP		interrupt flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_ICRBitList, /**/
					Binary<>{BitPos_t{2}},	// CLRJOVRF
					Binary<>{BitPos_t{3}},	// CLRROVRF
					Bit<8>{BitPos_t{16}},	// CLRCKABF
					Bit<8>{BitPos_t{24}}	// CLRSCDF
					)

enum class DFSDM1_ICRField {
	CLRJOVRF,		/*!< Clear the injected conversion overrun flag*/
	CLRROVRF,		/*!< Clear the regular conversion overrun flag*/
	CLRCKABF,		/*!< Clear the clock absence flag*/
	CLRSCDF,		/*!< Clear the short-circuit detector flag*/
};

static constexpr Register<DFSDM1_ICRBitList, DFSDM1_ICRField> DFSDM1_ICR{BASE_ADDR, 0x20cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_JCHGR_GROUP		injected channel group selection register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_JCHGRBitList, /**/
					Bit<8>{BitPos_t{0}}	// JCHG
					)

enum class DFSDM1_JCHGRField {
	JCHG,		/*!< Injected channel group selection*/
};

static constexpr Register<DFSDM1_JCHGRBitList, DFSDM1_JCHGRField> DFSDM1_JCHGR{BASE_ADDR, 0x210U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_FCR_GROUP		filter control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_FCRBitList, /**/
					Bit<8>{BitPos_t{0}},	// IOSR
					Bit<10, std::uint16_t>{BitPos_t{16}},	// FOSR
					Bit<3>{BitPos_t{29}}	// FORD
					)

enum class DFSDM1_FCRField {
	IOSR,		/*!< Integrator oversampling ratio (averaging length)*/
	FOSR,		/*!< Sinc filter oversampling ratio (decimation rate)*/
	FORD,		/*!< Sinc filter order*/
};

static constexpr Register<DFSDM1_FCRBitList, DFSDM1_FCRField> DFSDM1_FCR{BASE_ADDR, 0x214U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_JDATAR_GROUP		data register for injected group group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_JDATARBitList, /**/
					Bit<3>{BitPos_t{0}},	// JDATACH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// JDATA
					)

enum class DFSDM1_JDATARField {
	JDATACH,		/*!< Injected channel most recently converted*/
	JDATA,		/*!< Injected group conversion data*/
};

static constexpr Register<DFSDM1_JDATARBitList, DFSDM1_JDATARField> DFSDM1_JDATAR{BASE_ADDR, 0x218U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_RDATAR_GROUP		data register for the regular channel group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_RDATARBitList, /**/
					Bit<3>{BitPos_t{0}},	// RDATACH
					Binary<>{BitPos_t{4}},	// RPEND
					Bit<24, std::uint32_t>{BitPos_t{8}}	// RDATA
					)

enum class DFSDM1_RDATARField {
	RDATACH,		/*!< Regular channel most recently converted*/
	RPEND,		/*!< Regular channel pending data*/
	RDATA,		/*!< Regular channel conversion data*/
};

static constexpr Register<DFSDM1_RDATARBitList, DFSDM1_RDATARField> DFSDM1_RDATAR{BASE_ADDR, 0x21cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_AWHTR_GROUP		analog watchdog high threshold register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_AWHTRBitList, /**/
					Bit<4>{BitPos_t{0}},	// BKAWH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// AWHT
					)

enum class DFSDM1_AWHTRField {
	BKAWH,		/*!< Break signal assignment to analog watchdog high threshold event*/
	AWHT,		/*!< Analog watchdog high threshold*/
};

static constexpr Register<DFSDM1_AWHTRBitList, DFSDM1_AWHTRField> DFSDM1_AWHTR{BASE_ADDR, 0x220U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_AWLTR_GROUP		analog watchdog low threshold register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_AWLTRBitList, /**/
					Bit<4>{BitPos_t{0}},	// BKAWL
					Bit<24, std::uint32_t>{BitPos_t{8}}	// AWLT
					)

enum class DFSDM1_AWLTRField {
	BKAWL,		/*!< Break signal assignment to analog watchdog low threshold event*/
	AWLT,		/*!< Analog watchdog low threshold*/
};

static constexpr Register<DFSDM1_AWLTRBitList, DFSDM1_AWLTRField> DFSDM1_AWLTR{BASE_ADDR, 0x224U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_AWSR_GROUP		analog watchdog status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_AWSRBitList, /**/
					Bit<8>{BitPos_t{0}},	// AWLTF
					Bit<8>{BitPos_t{8}}	// AWHTF
					)

enum class DFSDM1_AWSRField {
	AWLTF,		/*!< Analog watchdog low threshold flag*/
	AWHTF,		/*!< Analog watchdog high threshold flag*/
};

static constexpr Register<DFSDM1_AWSRBitList, DFSDM1_AWSRField> DFSDM1_AWSR{BASE_ADDR, 0x228U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_AWCFR_GROUP		analog watchdog clear flag register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_AWCFRBitList, /**/
					Bit<8>{BitPos_t{0}},	// CLRAWLTF
					Bit<8>{BitPos_t{8}}	// CLRAWHTF
					)

enum class DFSDM1_AWCFRField {
	CLRAWLTF,		/*!< Clear the analog watchdog low threshold flag*/
	CLRAWHTF,		/*!< Clear the analog watchdog high threshold flag*/
};

static constexpr Register<DFSDM1_AWCFRBitList, DFSDM1_AWCFRField> DFSDM1_AWCFR{BASE_ADDR, 0x22cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_EXMAX_GROUP		Extremes detector maximum register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_EXMAXBitList, /**/
					Bit<3>{BitPos_t{0}},	// EXMAXCH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// EXMAX
					)

enum class DFSDM1_EXMAXField {
	EXMAXCH,		/*!< Extremes detector maximum data channel*/
	EXMAX,		/*!< Extremes detector maximum value*/
};

static constexpr Register<DFSDM1_EXMAXBitList, DFSDM1_EXMAXField> DFSDM1_EXMAX{BASE_ADDR, 0x230U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_EXMIN_GROUP		Extremes detector minimum register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_EXMINBitList, /**/
					Bit<3>{BitPos_t{0}},	// EXMINCH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// EXMIN
					)

enum class DFSDM1_EXMINField {
	EXMINCH,		/*!< Extremes detector minimum data channel*/
	EXMIN,		/*!< EXMIN*/
};

static constexpr Register<DFSDM1_EXMINBitList, DFSDM1_EXMINField> DFSDM1_EXMIN{BASE_ADDR, 0x234U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM1_CNVTIMR_GROUP		conversion timer register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM1_CNVTIMRBitList, /**/
					Bit<28, std::uint32_t>{BitPos_t{4}}	// CNVCNT
					)

enum class DFSDM1_CNVTIMRField {
	CNVCNT,		/*!< 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN*/
};

static constexpr Register<DFSDM1_CNVTIMRBitList, DFSDM1_CNVTIMRField> DFSDM1_CNVTIMR{BASE_ADDR, 0x238U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_CR1_GROUP		control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_CR1BitList, /**/
					Binary<>{BitPos_t{0}},	// DFEN
					Binary<>{BitPos_t{1}},	// JSWSTART
					Binary<>{BitPos_t{3}},	// JSYNC
					Binary<>{BitPos_t{4}},	// JSCAN
					Binary<>{BitPos_t{5}},	// JDMAEN
					Bit<3>{BitPos_t{8}},	// JEXTSEL
					Bit<2>{BitPos_t{13}},	// JEXTEN
					Binary<>{BitPos_t{17}},	// RSWSTART
					Binary<>{BitPos_t{18}},	// RCONT
					Binary<>{BitPos_t{19}},	// RSYNC
					Binary<>{BitPos_t{21}},	// RDMAEN
					Bit<3>{BitPos_t{24}},	// RCH
					Binary<>{BitPos_t{29}},	// FAST
					Binary<>{BitPos_t{30}}	// AWFSEL
					)

enum class DFSDM2_CR1Field {
	DFEN,		/*!< DFSDM enable*/
	JSWSTART,		/*!< Start a conversion of the injected group of channels*/
	JSYNC,		/*!< Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger*/
	JSCAN,		/*!< Scanning conversion mode for injected conversions*/
	JDMAEN,		/*!< DMA channel enabled to read data for the injected channel group*/
	JEXTSEL,		/*!< Trigger signal selection for launching injected conversions*/
	JEXTEN,		/*!< Trigger enable and trigger edge selection for injected conversions*/
	RSWSTART,		/*!< Software start of a conversion on the regular channel*/
	RCONT,		/*!< Continuous mode selection for regular conversions*/
	RSYNC,		/*!< Launch regular conversion synchronously with DFSDM0*/
	RDMAEN,		/*!< DMA channel enabled to read data for the regular conversion*/
	RCH,		/*!< Regular channel selection*/
	FAST,		/*!< Fast conversion mode selection for regular conversions*/
	AWFSEL,		/*!< Analog watchdog fast mode select*/
};

static constexpr Register<DFSDM2_CR1BitList, DFSDM2_CR1Field> DFSDM2_CR1{BASE_ADDR, 0x300U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_CR2_GROUP		control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_CR2BitList, /**/
					Binary<>{BitPos_t{0}},	// JEOCIE
					Binary<>{BitPos_t{1}},	// REOCIE
					Binary<>{BitPos_t{2}},	// JOVRIE
					Binary<>{BitPos_t{3}},	// ROVRIE
					Binary<>{BitPos_t{4}},	// AWDIE
					Binary<>{BitPos_t{5}},	// SCDIE
					Binary<>{BitPos_t{6}},	// CKABIE
					Bit<8>{BitPos_t{8}},	// EXCH
					Bit<8>{BitPos_t{16}}	// AWDCH
					)

enum class DFSDM2_CR2Field {
	JEOCIE,		/*!< Injected end of conversion interrupt enable*/
	REOCIE,		/*!< Regular end of conversion interrupt enable*/
	JOVRIE,		/*!< Injected data overrun interrupt enable*/
	ROVRIE,		/*!< Regular data overrun interrupt enable*/
	AWDIE,		/*!< Analog watchdog interrupt enable*/
	SCDIE,		/*!< Short-circuit detector interrupt enable*/
	CKABIE,		/*!< Clock absence interrupt enable*/
	EXCH,		/*!< Extremes detector channel selection*/
	AWDCH,		/*!< Analog watchdog channel selection*/
};

static constexpr Register<DFSDM2_CR2BitList, DFSDM2_CR2Field> DFSDM2_CR2{BASE_ADDR, 0x304U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_ISR_GROUP		interrupt and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_ISRBitList, /**/
					Binary<>{BitPos_t{0}},	// JEOCF
					Binary<>{BitPos_t{1}},	// REOCF
					Binary<>{BitPos_t{2}},	// JOVRF
					Binary<>{BitPos_t{3}},	// ROVRF
					Binary<>{BitPos_t{4}},	// AWDF
					Binary<>{BitPos_t{13}},	// JCIP
					Binary<>{BitPos_t{14}},	// RCIP
					Bit<8>{BitPos_t{16}},	// CKABF
					Bit<8>{BitPos_t{24}}	// SCDF
					)

enum class DFSDM2_ISRField {
	JEOCF,		/*!< End of injected conversion flag*/
	REOCF,		/*!< End of regular conversion flag*/
	JOVRF,		/*!< Injected conversion overrun flag*/
	ROVRF,		/*!< Regular conversion overrun flag*/
	AWDF,		/*!< Analog watchdog*/
	JCIP,		/*!< Injected conversion in progress status*/
	RCIP,		/*!< Regular conversion in progress status*/
	CKABF,		/*!< Clock absence flag*/
	SCDF,		/*!< short-circuit detector flag*/
};

static constexpr Register<DFSDM2_ISRBitList, DFSDM2_ISRField> DFSDM2_ISR{BASE_ADDR, 0x308U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_ICR_GROUP		interrupt flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_ICRBitList, /**/
					Binary<>{BitPos_t{2}},	// CLRJOVRF
					Binary<>{BitPos_t{3}},	// CLRROVRF
					Bit<8>{BitPos_t{16}},	// CLRCKABF
					Bit<8>{BitPos_t{24}}	// CLRSCDF
					)

enum class DFSDM2_ICRField {
	CLRJOVRF,		/*!< Clear the injected conversion overrun flag*/
	CLRROVRF,		/*!< Clear the regular conversion overrun flag*/
	CLRCKABF,		/*!< Clear the clock absence flag*/
	CLRSCDF,		/*!< Clear the short-circuit detector flag*/
};

static constexpr Register<DFSDM2_ICRBitList, DFSDM2_ICRField> DFSDM2_ICR{BASE_ADDR, 0x30cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_JCHGR_GROUP		injected channel group selection register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_JCHGRBitList, /**/
					Bit<8>{BitPos_t{0}}	// JCHG
					)

enum class DFSDM2_JCHGRField {
	JCHG,		/*!< Injected channel group selection*/
};

static constexpr Register<DFSDM2_JCHGRBitList, DFSDM2_JCHGRField> DFSDM2_JCHGR{BASE_ADDR, 0x310U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_FCR_GROUP		filter control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_FCRBitList, /**/
					Bit<8>{BitPos_t{0}},	// IOSR
					Bit<10, std::uint16_t>{BitPos_t{16}},	// FOSR
					Bit<3>{BitPos_t{29}}	// FORD
					)

enum class DFSDM2_FCRField {
	IOSR,		/*!< Integrator oversampling ratio (averaging length)*/
	FOSR,		/*!< Sinc filter oversampling ratio (decimation rate)*/
	FORD,		/*!< Sinc filter order*/
};

static constexpr Register<DFSDM2_FCRBitList, DFSDM2_FCRField> DFSDM2_FCR{BASE_ADDR, 0x314U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_JDATAR_GROUP		data register for injected group group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_JDATARBitList, /**/
					Bit<3>{BitPos_t{0}},	// JDATACH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// JDATA
					)

enum class DFSDM2_JDATARField {
	JDATACH,		/*!< Injected channel most recently converted*/
	JDATA,		/*!< Injected group conversion data*/
};

static constexpr Register<DFSDM2_JDATARBitList, DFSDM2_JDATARField> DFSDM2_JDATAR{BASE_ADDR, 0x318U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_RDATAR_GROUP		data register for the regular channel group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_RDATARBitList, /**/
					Bit<3>{BitPos_t{0}},	// RDATACH
					Binary<>{BitPos_t{4}},	// RPEND
					Bit<24, std::uint32_t>{BitPos_t{8}}	// RDATA
					)

enum class DFSDM2_RDATARField {
	RDATACH,		/*!< Regular channel most recently converted*/
	RPEND,		/*!< Regular channel pending data*/
	RDATA,		/*!< Regular channel conversion data*/
};

static constexpr Register<DFSDM2_RDATARBitList, DFSDM2_RDATARField> DFSDM2_RDATAR{BASE_ADDR, 0x31cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_AWHTR_GROUP		analog watchdog high threshold register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_AWHTRBitList, /**/
					Bit<4>{BitPos_t{0}},	// BKAWH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// AWHT
					)

enum class DFSDM2_AWHTRField {
	BKAWH,		/*!< Break signal assignment to analog watchdog high threshold event*/
	AWHT,		/*!< Analog watchdog high threshold*/
};

static constexpr Register<DFSDM2_AWHTRBitList, DFSDM2_AWHTRField> DFSDM2_AWHTR{BASE_ADDR, 0x320U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_AWLTR_GROUP		analog watchdog low threshold register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_AWLTRBitList, /**/
					Bit<4>{BitPos_t{0}},	// BKAWL
					Bit<24, std::uint32_t>{BitPos_t{8}}	// AWLT
					)

enum class DFSDM2_AWLTRField {
	BKAWL,		/*!< Break signal assignment to analog watchdog low threshold event*/
	AWLT,		/*!< Analog watchdog low threshold*/
};

static constexpr Register<DFSDM2_AWLTRBitList, DFSDM2_AWLTRField> DFSDM2_AWLTR{BASE_ADDR, 0x324U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_AWSR_GROUP		analog watchdog status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_AWSRBitList, /**/
					Bit<8>{BitPos_t{0}},	// AWLTF
					Bit<8>{BitPos_t{8}}	// AWHTF
					)

enum class DFSDM2_AWSRField {
	AWLTF,		/*!< Analog watchdog low threshold flag*/
	AWHTF,		/*!< Analog watchdog high threshold flag*/
};

static constexpr Register<DFSDM2_AWSRBitList, DFSDM2_AWSRField> DFSDM2_AWSR{BASE_ADDR, 0x328U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_AWCFR_GROUP		analog watchdog clear flag register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_AWCFRBitList, /**/
					Bit<8>{BitPos_t{0}},	// CLRAWLTF
					Bit<8>{BitPos_t{8}}	// CLRAWHTF
					)

enum class DFSDM2_AWCFRField {
	CLRAWLTF,		/*!< Clear the analog watchdog low threshold flag*/
	CLRAWHTF,		/*!< Clear the analog watchdog high threshold flag*/
};

static constexpr Register<DFSDM2_AWCFRBitList, DFSDM2_AWCFRField> DFSDM2_AWCFR{BASE_ADDR, 0x32cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_EXMAX_GROUP		Extremes detector maximum register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_EXMAXBitList, /**/
					Bit<3>{BitPos_t{0}},	// EXMAXCH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// EXMAX
					)

enum class DFSDM2_EXMAXField {
	EXMAXCH,		/*!< Extremes detector maximum data channel*/
	EXMAX,		/*!< Extremes detector maximum value*/
};

static constexpr Register<DFSDM2_EXMAXBitList, DFSDM2_EXMAXField> DFSDM2_EXMAX{BASE_ADDR, 0x330U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_EXMIN_GROUP		Extremes detector minimum register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_EXMINBitList, /**/
					Bit<3>{BitPos_t{0}},	// EXMINCH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// EXMIN
					)

enum class DFSDM2_EXMINField {
	EXMINCH,		/*!< Extremes detector minimum data channel*/
	EXMIN,		/*!< EXMIN*/
};

static constexpr Register<DFSDM2_EXMINBitList, DFSDM2_EXMINField> DFSDM2_EXMIN{BASE_ADDR, 0x334U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM2_CNVTIMR_GROUP		conversion timer register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM2_CNVTIMRBitList, /**/
					Bit<28, std::uint32_t>{BitPos_t{4}}	// CNVCNT
					)

enum class DFSDM2_CNVTIMRField {
	CNVCNT,		/*!< 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN*/
};

static constexpr Register<DFSDM2_CNVTIMRBitList, DFSDM2_CNVTIMRField> DFSDM2_CNVTIMR{BASE_ADDR, 0x338U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_CR1_GROUP		control register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_CR1BitList, /**/
					Binary<>{BitPos_t{0}},	// DFEN
					Binary<>{BitPos_t{1}},	// JSWSTART
					Binary<>{BitPos_t{3}},	// JSYNC
					Binary<>{BitPos_t{4}},	// JSCAN
					Binary<>{BitPos_t{5}},	// JDMAEN
					Bit<3>{BitPos_t{8}},	// JEXTSEL
					Bit<2>{BitPos_t{13}},	// JEXTEN
					Binary<>{BitPos_t{17}},	// RSWSTART
					Binary<>{BitPos_t{18}},	// RCONT
					Binary<>{BitPos_t{19}},	// RSYNC
					Binary<>{BitPos_t{21}},	// RDMAEN
					Bit<3>{BitPos_t{24}},	// RCH
					Binary<>{BitPos_t{29}},	// FAST
					Binary<>{BitPos_t{30}}	// AWFSEL
					)

enum class DFSDM3_CR1Field {
	DFEN,		/*!< DFSDM enable*/
	JSWSTART,		/*!< Start a conversion of the injected group of channels*/
	JSYNC,		/*!< Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger*/
	JSCAN,		/*!< Scanning conversion mode for injected conversions*/
	JDMAEN,		/*!< DMA channel enabled to read data for the injected channel group*/
	JEXTSEL,		/*!< Trigger signal selection for launching injected conversions*/
	JEXTEN,		/*!< Trigger enable and trigger edge selection for injected conversions*/
	RSWSTART,		/*!< Software start of a conversion on the regular channel*/
	RCONT,		/*!< Continuous mode selection for regular conversions*/
	RSYNC,		/*!< Launch regular conversion synchronously with DFSDM0*/
	RDMAEN,		/*!< DMA channel enabled to read data for the regular conversion*/
	RCH,		/*!< Regular channel selection*/
	FAST,		/*!< Fast conversion mode selection for regular conversions*/
	AWFSEL,		/*!< Analog watchdog fast mode select*/
};

static constexpr Register<DFSDM3_CR1BitList, DFSDM3_CR1Field> DFSDM3_CR1{BASE_ADDR, 0x400U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_CR2_GROUP		control register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_CR2BitList, /**/
					Binary<>{BitPos_t{0}},	// JEOCIE
					Binary<>{BitPos_t{1}},	// REOCIE
					Binary<>{BitPos_t{2}},	// JOVRIE
					Binary<>{BitPos_t{3}},	// ROVRIE
					Binary<>{BitPos_t{4}},	// AWDIE
					Binary<>{BitPos_t{5}},	// SCDIE
					Binary<>{BitPos_t{6}},	// CKABIE
					Bit<8>{BitPos_t{8}},	// EXCH
					Bit<8>{BitPos_t{16}}	// AWDCH
					)

enum class DFSDM3_CR2Field {
	JEOCIE,		/*!< Injected end of conversion interrupt enable*/
	REOCIE,		/*!< Regular end of conversion interrupt enable*/
	JOVRIE,		/*!< Injected data overrun interrupt enable*/
	ROVRIE,		/*!< Regular data overrun interrupt enable*/
	AWDIE,		/*!< Analog watchdog interrupt enable*/
	SCDIE,		/*!< Short-circuit detector interrupt enable*/
	CKABIE,		/*!< Clock absence interrupt enable*/
	EXCH,		/*!< Extremes detector channel selection*/
	AWDCH,		/*!< Analog watchdog channel selection*/
};

static constexpr Register<DFSDM3_CR2BitList, DFSDM3_CR2Field> DFSDM3_CR2{BASE_ADDR, 0x404U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_ISR_GROUP		interrupt and status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_ISRBitList, /**/
					Binary<>{BitPos_t{0}},	// JEOCF
					Binary<>{BitPos_t{1}},	// REOCF
					Binary<>{BitPos_t{2}},	// JOVRF
					Binary<>{BitPos_t{3}},	// ROVRF
					Binary<>{BitPos_t{4}},	// AWDF
					Binary<>{BitPos_t{13}},	// JCIP
					Binary<>{BitPos_t{14}},	// RCIP
					Bit<8>{BitPos_t{16}},	// CKABF
					Bit<8>{BitPos_t{24}}	// SCDF
					)

enum class DFSDM3_ISRField {
	JEOCF,		/*!< End of injected conversion flag*/
	REOCF,		/*!< End of regular conversion flag*/
	JOVRF,		/*!< Injected conversion overrun flag*/
	ROVRF,		/*!< Regular conversion overrun flag*/
	AWDF,		/*!< Analog watchdog*/
	JCIP,		/*!< Injected conversion in progress status*/
	RCIP,		/*!< Regular conversion in progress status*/
	CKABF,		/*!< Clock absence flag*/
	SCDF,		/*!< short-circuit detector flag*/
};

static constexpr Register<DFSDM3_ISRBitList, DFSDM3_ISRField> DFSDM3_ISR{BASE_ADDR, 0x408U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_ICR_GROUP		interrupt flag clear register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_ICRBitList, /**/
					Binary<>{BitPos_t{2}},	// CLRJOVRF
					Binary<>{BitPos_t{3}},	// CLRROVRF
					Bit<8>{BitPos_t{16}},	// CLRCKABF
					Bit<8>{BitPos_t{24}}	// CLRSCDF
					)

enum class DFSDM3_ICRField {
	CLRJOVRF,		/*!< Clear the injected conversion overrun flag*/
	CLRROVRF,		/*!< Clear the regular conversion overrun flag*/
	CLRCKABF,		/*!< Clear the clock absence flag*/
	CLRSCDF,		/*!< Clear the short-circuit detector flag*/
};

static constexpr Register<DFSDM3_ICRBitList, DFSDM3_ICRField> DFSDM3_ICR{BASE_ADDR, 0x40cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_JCHGR_GROUP		injected channel group selection register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_JCHGRBitList, /**/
					Bit<8>{BitPos_t{0}}	// JCHG
					)

enum class DFSDM3_JCHGRField {
	JCHG,		/*!< Injected channel group selection*/
};

static constexpr Register<DFSDM3_JCHGRBitList, DFSDM3_JCHGRField> DFSDM3_JCHGR{BASE_ADDR, 0x410U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_FCR_GROUP		filter control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_FCRBitList, /**/
					Bit<8>{BitPos_t{0}},	// IOSR
					Bit<10, std::uint16_t>{BitPos_t{16}},	// FOSR
					Bit<3>{BitPos_t{29}}	// FORD
					)

enum class DFSDM3_FCRField {
	IOSR,		/*!< Integrator oversampling ratio (averaging length)*/
	FOSR,		/*!< Sinc filter oversampling ratio (decimation rate)*/
	FORD,		/*!< Sinc filter order*/
};

static constexpr Register<DFSDM3_FCRBitList, DFSDM3_FCRField> DFSDM3_FCR{BASE_ADDR, 0x414U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_JDATAR_GROUP		data register for injected group group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_JDATARBitList, /**/
					Bit<3>{BitPos_t{0}},	// JDATACH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// JDATA
					)

enum class DFSDM3_JDATARField {
	JDATACH,		/*!< Injected channel most recently converted*/
	JDATA,		/*!< Injected group conversion data*/
};

static constexpr Register<DFSDM3_JDATARBitList, DFSDM3_JDATARField> DFSDM3_JDATAR{BASE_ADDR, 0x418U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_RDATAR_GROUP		data register for the regular channel group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_RDATARBitList, /**/
					Bit<3>{BitPos_t{0}},	// RDATACH
					Binary<>{BitPos_t{4}},	// RPEND
					Bit<24, std::uint32_t>{BitPos_t{8}}	// RDATA
					)

enum class DFSDM3_RDATARField {
	RDATACH,		/*!< Regular channel most recently converted*/
	RPEND,		/*!< Regular channel pending data*/
	RDATA,		/*!< Regular channel conversion data*/
};

static constexpr Register<DFSDM3_RDATARBitList, DFSDM3_RDATARField> DFSDM3_RDATAR{BASE_ADDR, 0x41cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_AWHTR_GROUP		analog watchdog high threshold register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_AWHTRBitList, /**/
					Bit<4>{BitPos_t{0}},	// BKAWH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// AWHT
					)

enum class DFSDM3_AWHTRField {
	BKAWH,		/*!< Break signal assignment to analog watchdog high threshold event*/
	AWHT,		/*!< Analog watchdog high threshold*/
};

static constexpr Register<DFSDM3_AWHTRBitList, DFSDM3_AWHTRField> DFSDM3_AWHTR{BASE_ADDR, 0x420U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_AWLTR_GROUP		analog watchdog low threshold register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_AWLTRBitList, /**/
					Bit<4>{BitPos_t{0}},	// BKAWL
					Bit<24, std::uint32_t>{BitPos_t{8}}	// AWLT
					)

enum class DFSDM3_AWLTRField {
	BKAWL,		/*!< Break signal assignment to analog watchdog low threshold event*/
	AWLT,		/*!< Analog watchdog low threshold*/
};

static constexpr Register<DFSDM3_AWLTRBitList, DFSDM3_AWLTRField> DFSDM3_AWLTR{BASE_ADDR, 0x424U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_AWSR_GROUP		analog watchdog status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_AWSRBitList, /**/
					Bit<8>{BitPos_t{0}},	// AWLTF
					Bit<8>{BitPos_t{8}}	// AWHTF
					)

enum class DFSDM3_AWSRField {
	AWLTF,		/*!< Analog watchdog low threshold flag*/
	AWHTF,		/*!< Analog watchdog high threshold flag*/
};

static constexpr Register<DFSDM3_AWSRBitList, DFSDM3_AWSRField> DFSDM3_AWSR{BASE_ADDR, 0x428U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_AWCFR_GROUP		analog watchdog clear flag register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_AWCFRBitList, /**/
					Bit<8>{BitPos_t{0}},	// CLRAWLTF
					Bit<8>{BitPos_t{8}}	// CLRAWHTF
					)

enum class DFSDM3_AWCFRField {
	CLRAWLTF,		/*!< Clear the analog watchdog low threshold flag*/
	CLRAWHTF,		/*!< Clear the analog watchdog high threshold flag*/
};

static constexpr Register<DFSDM3_AWCFRBitList, DFSDM3_AWCFRField> DFSDM3_AWCFR{BASE_ADDR, 0x42cU};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_EXMAX_GROUP		Extremes detector maximum register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_EXMAXBitList, /**/
					Bit<3>{BitPos_t{0}},	// EXMAXCH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// EXMAX
					)

enum class DFSDM3_EXMAXField {
	EXMAXCH,		/*!< Extremes detector maximum data channel*/
	EXMAX,		/*!< Extremes detector maximum value*/
};

static constexpr Register<DFSDM3_EXMAXBitList, DFSDM3_EXMAXField> DFSDM3_EXMAX{BASE_ADDR, 0x430U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_EXMIN_GROUP		Extremes detector minimum register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_EXMINBitList, /**/
					Bit<3>{BitPos_t{0}},	// EXMINCH
					Bit<24, std::uint32_t>{BitPos_t{8}}	// EXMIN
					)

enum class DFSDM3_EXMINField {
	EXMINCH,		/*!< Extremes detector minimum data channel*/
	EXMIN,		/*!< EXMIN*/
};

static constexpr Register<DFSDM3_EXMINBitList, DFSDM3_EXMINField> DFSDM3_EXMIN{BASE_ADDR, 0x434U};
/**@}*/

/**
 * @defgroup	DFSDM_DFSDM3_CNVTIMR_GROUP		conversion timer register group
 *
 * @{
 */

SETUP_REGISTER_INFO(DFSDM3_CNVTIMRBitList, /**/
					Bit<28, std::uint32_t>{BitPos_t{4}}	// CNVCNT
					)

enum class DFSDM3_CNVTIMRField {
	CNVCNT,		/*!< 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN*/
};

static constexpr Register<DFSDM3_CNVTIMRBitList, DFSDM3_CNVTIMRField> DFSDM3_CNVTIMR{BASE_ADDR, 0x438U};
/**@}*/


} // cpp_stm32::dfsdm::reg
