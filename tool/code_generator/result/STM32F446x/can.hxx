#pragma once

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"

namespace cpp_stm32::can::reg {

static constexpr auto BASE_ADDR(Port const& t_can) {
	switch (t_can) {
		case Port::CAN1:
			return 0x40006400U;
		case Port::CAN2:
			return 0x40006800U;
	}
}

/**
 * @defgroup	CAN2_MCR_GROUP		master control register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MCRBitList,							 /**/
										Binary<>{BitPos_t{0}},	 // INRQ
										Binary<>{BitPos_t{1}},	 // SLEEP
										Binary<>{BitPos_t{2}},	 // TXFP
										Binary<>{BitPos_t{3}},	 // RFLM
										Binary<>{BitPos_t{4}},	 // NART
										Binary<>{BitPos_t{5}},	 // AWUM
										Binary<>{BitPos_t{6}},	 // ABOM
										Binary<>{BitPos_t{7}},	 // TTCM
										Binary<>{BitPos_t{15}},	 // RESET
										Binary<>{BitPos_t{16}}	 // DBF
)

enum class MCRField {
	INRQ,	 /*!< INRQ*/
	SLEEP, /*!< SLEEP*/
	TXFP,	 /*!< TXFP*/
	RFLM,	 /*!< RFLM*/
	NART,	 /*!< NART*/
	AWUM,	 /*!< AWUM*/
	ABOM,	 /*!< ABOM*/
	TTCM,	 /*!< TTCM*/
	RESET, /*!< RESET*/
	DBF,	 /*!< DBF*/
};

template <Port CAN>
static constexpr Register<MCRBitList, MCRField> MCR{BASE_ADDR(CAN), 0x00U};
/**@}*/

/**
 * @defgroup	CAN2_MSR_GROUP		master status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(MSRBitList,									 /**/
										StatusBit<1>{BitPos_t{0}},	 // INAK
										StatusBit<1>{BitPos_t{1}},	 // SLAK
										Binary<>{BitPos_t{2}},			 // ERRI
										Binary<>{BitPos_t{3}},			 // WKUI
										Binary<>{BitPos_t{4}},			 // SLAKI
										StatusBit<1>{BitPos_t{8}},	 // TXM
										StatusBit<1>{BitPos_t{9}},	 // RXM
										StatusBit<1>{BitPos_t{10}},	 // SAMP
										StatusBit<1>{BitPos_t{11}}	 // RX
)

enum class MSRField {
	INAK,	 /*!< INAK*/
	SLAK,	 /*!< SLAK*/
	ERRI,	 /*!< ERRI*/
	WKUI,	 /*!< WKUI*/
	SLAKI, /*!< SLAKI*/
	TXM,	 /*!< TXM*/
	RXM,	 /*!< RXM*/
	SAMP,	 /*!< SAMP*/
	RX,		 /*!< RX*/
};

template <Port CAN>
static constexpr Register<MSRBitList, MSRField> MSR{BASE_ADDR(CAN), 0x04U};
/**@}*/

/**
 * @defgroup	CAN2_TSR_GROUP		transmit status register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TSRBitList,									 /**/
										Binary<>{BitPos_t{0}},			 // RQCP0
										Binary<>{BitPos_t{1}},			 // TXOK0
										Binary<>{BitPos_t{2}},			 // ALST0
										Binary<>{BitPos_t{3}},			 // TERR0
										Binary<>{BitPos_t{7}},			 // ABRQ0
										Binary<>{BitPos_t{8}},			 // RQCP1
										Binary<>{BitPos_t{9}},			 // TXOK1
										Binary<>{BitPos_t{10}},			 // ALST1
										Binary<>{BitPos_t{11}},			 // TERR1
										Binary<>{BitPos_t{15}},			 // ABRQ1
										Binary<>{BitPos_t{16}},			 // RQCP2
										Binary<>{BitPos_t{17}},			 // TXOK2
										Binary<>{BitPos_t{18}},			 // ALST2
										Binary<>{BitPos_t{19}},			 // TERR2
										Binary<>{BitPos_t{23}},			 // ABRQ2
										StatusBit<2>{BitPos_t{24}},	 // CODE
										StatusBit<2>{BitPos_t{26}},	 // TM
										StatusBit<2>{BitPos_t{27}},	 // TM
										StatusBit<2>{BitPos_t{28}}	 // TM
)

enum class TSRField {
	RQCP0, /*!< RQCP0*/
	TXOK0, /*!< TXOK0*/
	ALST0, /*!< ALST0*/
	TERR0, /*!< TERR0*/
	ABRQ0, /*!< ABRQ0*/
	RQCP1, /*!< RQCP1*/
	TXOK1, /*!< TXOK1*/
	ALST1, /*!< ALST1*/
	TERR1, /*!< TERR1*/
	ABRQ1, /*!< ABRQ1*/
	RQCP2, /*!< RQCP2*/
	TXOK2, /*!< TXOK2*/
	ALST2, /*!< ALST2*/
	TERR2, /*!< TERR2*/
	ABRQ2, /*!< ABRQ2*/
	CODE,	 /*!< CODE*/
	TM,		 /*!< Lowest priority flag for mailbox 0*/
	TM,		 /*!< Lowest priority flag for mailbox 1*/
	TM,		 /*!< Lowest priority flag for mailbox 2*/
};

template <Port CAN>
static constexpr Register<TSRBitList, TSRField> TSR{BASE_ADDR(CAN), 0x08U};
/**@}*/

/**
 * @defgroup	CAN2_RF0R_GROUP		receive FIFO 0 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RF0RBitList,								/**/
										StatusBit<2>{BitPos_t{0}},	// FMP0
										Binary<>{BitPos_t{3}},			// FULL0
										Binary<>{BitPos_t{4}},			// FOVR0
										Binary<>{BitPos_t{5}}				// RFOM0
)

enum class RF0RField {
	FMP0,	 /*!< FMP0*/
	FULL0, /*!< FULL0*/
	FOVR0, /*!< FOVR0*/
	RFOM0, /*!< RFOM0*/
};

template <Port CAN>
static constexpr Register<RF0RBitList, RF0RField> RF0R{BASE_ADDR(CAN), 0x0cU};
/**@}*/

/**
 * @defgroup	CAN2_RF1R_GROUP		receive FIFO 1 register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RF1RBitList,								/**/
										StatusBit<2>{BitPos_t{0}},	// FMP1
										Binary<>{BitPos_t{3}},			// FULL1
										Binary<>{BitPos_t{4}},			// FOVR1
										Binary<>{BitPos_t{5}}				// RFOM1
)

enum class RF1RField {
	FMP1,	 /*!< FMP1*/
	FULL1, /*!< FULL1*/
	FOVR1, /*!< FOVR1*/
	RFOM1, /*!< RFOM1*/
};

template <Port CAN>
static constexpr Register<RF1RBitList, RF1RField> RF1R{BASE_ADDR(CAN), 0x10U};
/**@}*/

/**
 * @defgroup	CAN2_IER_GROUP		interrupt enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(IERBitList,							 /**/
										Binary<>{BitPos_t{0}},	 // TMEIE
										Binary<>{BitPos_t{1}},	 // FMPIE0
										Binary<>{BitPos_t{2}},	 // FFIE0
										Binary<>{BitPos_t{3}},	 // FOVIE0
										Binary<>{BitPos_t{4}},	 // FMPIE1
										Binary<>{BitPos_t{5}},	 // FFIE1
										Binary<>{BitPos_t{6}},	 // FOVIE1
										Binary<>{BitPos_t{8}},	 // EWGIE
										Binary<>{BitPos_t{9}},	 // EPVIE
										Binary<>{BitPos_t{10}},	 // BOFIE
										Binary<>{BitPos_t{11}},	 // LECIE
										Binary<>{BitPos_t{15}},	 // ERRIE
										Binary<>{BitPos_t{16}},	 // WKUIE
										Binary<>{BitPos_t{17}}	 // SLKIE
)

enum class IERField {
	TMEIE,	/*!< TMEIE*/
	FMPIE0, /*!< FMPIE0*/
	FFIE0,	/*!< FFIE0*/
	FOVIE0, /*!< FOVIE0*/
	FMPIE1, /*!< FMPIE1*/
	FFIE1,	/*!< FFIE1*/
	FOVIE1, /*!< FOVIE1*/
	EWGIE,	/*!< EWGIE*/
	EPVIE,	/*!< EPVIE*/
	BOFIE,	/*!< BOFIE*/
	LECIE,	/*!< LECIE*/
	ERRIE,	/*!< ERRIE*/
	WKUIE,	/*!< WKUIE*/
	SLKIE,	/*!< SLKIE*/
};

template <Port CAN>
static constexpr Register<IERBitList, IERField> IER{BASE_ADDR(CAN), 0x14U};
/**@}*/

/**
 * @defgroup	CAN2_ESR_GROUP		interrupt enable register group
 *
 * @{
 */

SETUP_REGISTER_INFO(ESRBitList,									 /**/
										StatusBit<1>{BitPos_t{0}},	 // EWGF
										StatusBit<1>{BitPos_t{1}},	 // EPVF
										StatusBit<1>{BitPos_t{2}},	 // BOFF
										Bit<3>{BitPos_t{4}},				 // LEC
										StatusBit<8>{BitPos_t{16}},	 // TEC
										StatusBit<8>{BitPos_t{24}}	 // REC
)

enum class ESRField {
	EWGF, /*!< EWGF*/
	EPVF, /*!< EPVF*/
	BOFF, /*!< BOFF*/
	LEC,	/*!< LEC*/
	TEC,	/*!< TEC*/
	REC,	/*!< REC*/
};

template <Port CAN>
static constexpr Register<ESRBitList, ESRField> ESR{BASE_ADDR(CAN), 0x18U};
/**@}*/

/**
 * @defgroup	CAN2_BTR_GROUP		bit timing register group
 *
 * @{
 */

SETUP_REGISTER_INFO(BTRBitList,														/**/
										Bit<10, std::uint16_t>{BitPos_t{0}},	// BRP
										Bit<4>{BitPos_t{16}},									// TS1
										Bit<3>{BitPos_t{20}},									// TS2
										Bit<2>{BitPos_t{24}},									// SJW
										Binary<>{BitPos_t{30}},								// LBKM
										Binary<>{BitPos_t{31}}								// SILM
)

enum class BTRField {
	BRP,	/*!< BRP*/
	TS1,	/*!< TS1*/
	TS2,	/*!< TS2*/
	SJW,	/*!< SJW*/
	LBKM, /*!< LBKM*/
	SILM, /*!< SILM*/
};

template <Port CAN>
static constexpr Register<BTRBitList, BTRField> BTR{BASE_ADDR(CAN), 0x1cU};
/**@}*/

/**
 * @defgroup	CAN2_TI0R_GROUP		TX mailbox identifier register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TI0RBitList,													/**/
										Binary<>{BitPos_t{0}},								// TXRQ
										Binary<>{BitPos_t{1}},								// RTR
										Binary<>{BitPos_t{2}},								// IDE
										Bit<18, std::uint32_t>{BitPos_t{3}},	// EXID
										Bit<11, std::uint16_t>{BitPos_t{21}}	// STID
)

enum class TI0RField {
	TXRQ, /*!< TXRQ*/
	RTR,	/*!< RTR*/
	IDE,	/*!< IDE*/
	EXID, /*!< EXID*/
	STID, /*!< STID*/
};

template <Port CAN>
static constexpr Register<TI0RBitList, TI0RField> TI0R{BASE_ADDR(CAN), 0x180U};
/**@}*/

/**
 * @defgroup	CAN2_TDT0R_GROUP		mailbox data length control and time stamp register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TDT0RBitList,													/**/
										Bit<4>{BitPos_t{0}},									// DLC
										Binary<>{BitPos_t{8}},								// TGT
										Bit<16, std::uint16_t>{BitPos_t{16}}	// TIME
)

enum class TDT0RField {
	DLC,	/*!< DLC*/
	TGT,	/*!< TGT*/
	TIME, /*!< TIME*/
};

template <Port CAN>
static constexpr Register<TDT0RBitList, TDT0RField> TDT0R{BASE_ADDR(CAN), 0x184U};
/**@}*/

/**
 * @defgroup	CAN2_TDL0R_GROUP		mailbox data low register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TDL0RBitList,					 /**/
										Bit<8>{BitPos_t{0}},	 // DATA0
										Bit<8>{BitPos_t{8}},	 // DATA1
										Bit<8>{BitPos_t{16}},	 // DATA2
										Bit<8>{BitPos_t{24}}	 // DATA3
)

enum class TDL0RField {
	DATA0, /*!< DATA0*/
	DATA1, /*!< DATA1*/
	DATA2, /*!< DATA2*/
	DATA3, /*!< DATA3*/
};

template <Port CAN>
static constexpr Register<TDL0RBitList, TDL0RField> TDL0R{BASE_ADDR(CAN), 0x188U};
/**@}*/

/**
 * @defgroup	CAN2_TDH0R_GROUP		mailbox data high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TDH0RBitList,					 /**/
										Bit<8>{BitPos_t{0}},	 // DATA4
										Bit<8>{BitPos_t{8}},	 // DATA5
										Bit<8>{BitPos_t{16}},	 // DATA6
										Bit<8>{BitPos_t{24}}	 // DATA7
)

enum class TDH0RField {
	DATA4, /*!< DATA4*/
	DATA5, /*!< DATA5*/
	DATA6, /*!< DATA6*/
	DATA7, /*!< DATA7*/
};

template <Port CAN>
static constexpr Register<TDH0RBitList, TDH0RField> TDH0R{BASE_ADDR(CAN), 0x18cU};
/**@}*/

/**
 * @defgroup	CAN2_TI1R_GROUP		mailbox identifier register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TI1RBitList,													/**/
										Binary<>{BitPos_t{0}},								// TXRQ
										Binary<>{BitPos_t{1}},								// RTR
										Binary<>{BitPos_t{2}},								// IDE
										Bit<18, std::uint32_t>{BitPos_t{3}},	// EXID
										Bit<11, std::uint16_t>{BitPos_t{21}}	// STID
)

enum class TI1RField {
	TXRQ, /*!< TXRQ*/
	RTR,	/*!< RTR*/
	IDE,	/*!< IDE*/
	EXID, /*!< EXID*/
	STID, /*!< STID*/
};

template <Port CAN>
static constexpr Register<TI1RBitList, TI1RField> TI1R{BASE_ADDR(CAN), 0x190U};
/**@}*/

/**
 * @defgroup	CAN2_TDT1R_GROUP		mailbox data length control and time stamp register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TDT1RBitList,													/**/
										Bit<4>{BitPos_t{0}},									// DLC
										Binary<>{BitPos_t{8}},								// TGT
										Bit<16, std::uint16_t>{BitPos_t{16}}	// TIME
)

enum class TDT1RField {
	DLC,	/*!< DLC*/
	TGT,	/*!< TGT*/
	TIME, /*!< TIME*/
};

template <Port CAN>
static constexpr Register<TDT1RBitList, TDT1RField> TDT1R{BASE_ADDR(CAN), 0x194U};
/**@}*/

/**
 * @defgroup	CAN2_TDL1R_GROUP		mailbox data low register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TDL1RBitList,					 /**/
										Bit<8>{BitPos_t{0}},	 // DATA0
										Bit<8>{BitPos_t{8}},	 // DATA1
										Bit<8>{BitPos_t{16}},	 // DATA2
										Bit<8>{BitPos_t{24}}	 // DATA3
)

enum class TDL1RField {
	DATA0, /*!< DATA0*/
	DATA1, /*!< DATA1*/
	DATA2, /*!< DATA2*/
	DATA3, /*!< DATA3*/
};

template <Port CAN>
static constexpr Register<TDL1RBitList, TDL1RField> TDL1R{BASE_ADDR(CAN), 0x198U};
/**@}*/

/**
 * @defgroup	CAN2_TDH1R_GROUP		mailbox data high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TDH1RBitList,					 /**/
										Bit<8>{BitPos_t{0}},	 // DATA4
										Bit<8>{BitPos_t{8}},	 // DATA5
										Bit<8>{BitPos_t{16}},	 // DATA6
										Bit<8>{BitPos_t{24}}	 // DATA7
)

enum class TDH1RField {
	DATA4, /*!< DATA4*/
	DATA5, /*!< DATA5*/
	DATA6, /*!< DATA6*/
	DATA7, /*!< DATA7*/
};

template <Port CAN>
static constexpr Register<TDH1RBitList, TDH1RField> TDH1R{BASE_ADDR(CAN), 0x19cU};
/**@}*/

/**
 * @defgroup	CAN2_TI2R_GROUP		mailbox identifier register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TI2RBitList,													/**/
										Binary<>{BitPos_t{0}},								// TXRQ
										Binary<>{BitPos_t{1}},								// RTR
										Binary<>{BitPos_t{2}},								// IDE
										Bit<18, std::uint32_t>{BitPos_t{3}},	// EXID
										Bit<11, std::uint16_t>{BitPos_t{21}}	// STID
)

enum class TI2RField {
	TXRQ, /*!< TXRQ*/
	RTR,	/*!< RTR*/
	IDE,	/*!< IDE*/
	EXID, /*!< EXID*/
	STID, /*!< STID*/
};

template <Port CAN>
static constexpr Register<TI2RBitList, TI2RField> TI2R{BASE_ADDR(CAN), 0x1a0U};
/**@}*/

/**
 * @defgroup	CAN2_TDT2R_GROUP		mailbox data length control and time stamp register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TDT2RBitList,													/**/
										Bit<4>{BitPos_t{0}},									// DLC
										Binary<>{BitPos_t{8}},								// TGT
										Bit<16, std::uint16_t>{BitPos_t{16}}	// TIME
)

enum class TDT2RField {
	DLC,	/*!< DLC*/
	TGT,	/*!< TGT*/
	TIME, /*!< TIME*/
};

template <Port CAN>
static constexpr Register<TDT2RBitList, TDT2RField> TDT2R{BASE_ADDR(CAN), 0x1a4U};
/**@}*/

/**
 * @defgroup	CAN2_TDL2R_GROUP		mailbox data low register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TDL2RBitList,					 /**/
										Bit<8>{BitPos_t{0}},	 // DATA0
										Bit<8>{BitPos_t{8}},	 // DATA1
										Bit<8>{BitPos_t{16}},	 // DATA2
										Bit<8>{BitPos_t{24}}	 // DATA3
)

enum class TDL2RField {
	DATA0, /*!< DATA0*/
	DATA1, /*!< DATA1*/
	DATA2, /*!< DATA2*/
	DATA3, /*!< DATA3*/
};

template <Port CAN>
static constexpr Register<TDL2RBitList, TDL2RField> TDL2R{BASE_ADDR(CAN), 0x1a8U};
/**@}*/

/**
 * @defgroup	CAN2_TDH2R_GROUP		mailbox data high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(TDH2RBitList,					 /**/
										Bit<8>{BitPos_t{0}},	 // DATA4
										Bit<8>{BitPos_t{8}},	 // DATA5
										Bit<8>{BitPos_t{16}},	 // DATA6
										Bit<8>{BitPos_t{24}}	 // DATA7
)

enum class TDH2RField {
	DATA4, /*!< DATA4*/
	DATA5, /*!< DATA5*/
	DATA6, /*!< DATA6*/
	DATA7, /*!< DATA7*/
};

template <Port CAN>
static constexpr Register<TDH2RBitList, TDH2RField> TDH2R{BASE_ADDR(CAN), 0x1acU};
/**@}*/

/**
 * @defgroup	CAN2_RI0R_GROUP		receive FIFO mailbox identifier register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RI0RBitList,													/**/
										Binary<>{BitPos_t{1}},								// RTR
										Binary<>{BitPos_t{2}},								// IDE
										Bit<18, std::uint32_t>{BitPos_t{3}},	// EXID
										Bit<11, std::uint16_t>{BitPos_t{21}}	// STID
)

enum class RI0RField {
	RTR,	/*!< RTR*/
	IDE,	/*!< IDE*/
	EXID, /*!< EXID*/
	STID, /*!< STID*/
};

template <Port CAN>
static constexpr Register<RI0RBitList, RI0RField> RI0R{BASE_ADDR(CAN), 0x1b0U};
/**@}*/

/**
 * @defgroup	CAN2_RDT0R_GROUP		mailbox data high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RDT0RBitList,													/**/
										Bit<4>{BitPos_t{0}},									// DLC
										Bit<8>{BitPos_t{8}},									// FMI
										Bit<16, std::uint16_t>{BitPos_t{16}}	// TIME
)

enum class RDT0RField {
	DLC,	/*!< DLC*/
	FMI,	/*!< FMI*/
	TIME, /*!< TIME*/
};

template <Port CAN>
static constexpr Register<RDT0RBitList, RDT0RField> RDT0R{BASE_ADDR(CAN), 0x1b4U};
/**@}*/

/**
 * @defgroup	CAN2_RDL0R_GROUP		mailbox data high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RDL0RBitList,					 /**/
										Bit<8>{BitPos_t{0}},	 // DATA0
										Bit<8>{BitPos_t{8}},	 // DATA1
										Bit<8>{BitPos_t{16}},	 // DATA2
										Bit<8>{BitPos_t{24}}	 // DATA3
)

enum class RDL0RField {
	DATA0, /*!< DATA0*/
	DATA1, /*!< DATA1*/
	DATA2, /*!< DATA2*/
	DATA3, /*!< DATA3*/
};

template <Port CAN>
static constexpr Register<RDL0RBitList, RDL0RField> RDL0R{BASE_ADDR(CAN), 0x1b8U};
/**@}*/

/**
 * @defgroup	CAN2_RDH0R_GROUP		receive FIFO mailbox data high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RDH0RBitList,					 /**/
										Bit<8>{BitPos_t{0}},	 // DATA4
										Bit<8>{BitPos_t{8}},	 // DATA5
										Bit<8>{BitPos_t{16}},	 // DATA6
										Bit<8>{BitPos_t{24}}	 // DATA7
)

enum class RDH0RField {
	DATA4, /*!< DATA4*/
	DATA5, /*!< DATA5*/
	DATA6, /*!< DATA6*/
	DATA7, /*!< DATA7*/
};

template <Port CAN>
static constexpr Register<RDH0RBitList, RDH0RField> RDH0R{BASE_ADDR(CAN), 0x1bcU};
/**@}*/

/**
 * @defgroup	CAN2_RI1R_GROUP		mailbox data high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RI1RBitList,													/**/
										Binary<>{BitPos_t{1}},								// RTR
										Binary<>{BitPos_t{2}},								// IDE
										Bit<18, std::uint32_t>{BitPos_t{3}},	// EXID
										Bit<11, std::uint16_t>{BitPos_t{21}}	// STID
)

enum class RI1RField {
	RTR,	/*!< RTR*/
	IDE,	/*!< IDE*/
	EXID, /*!< EXID*/
	STID, /*!< STID*/
};

template <Port CAN>
static constexpr Register<RI1RBitList, RI1RField> RI1R{BASE_ADDR(CAN), 0x1c0U};
/**@}*/

/**
 * @defgroup	CAN2_RDT1R_GROUP		mailbox data high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RDT1RBitList,													/**/
										Bit<4>{BitPos_t{0}},									// DLC
										Bit<8>{BitPos_t{8}},									// FMI
										Bit<16, std::uint16_t>{BitPos_t{16}}	// TIME
)

enum class RDT1RField {
	DLC,	/*!< DLC*/
	FMI,	/*!< FMI*/
	TIME, /*!< TIME*/
};

template <Port CAN>
static constexpr Register<RDT1RBitList, RDT1RField> RDT1R{BASE_ADDR(CAN), 0x1c4U};
/**@}*/

/**
 * @defgroup	CAN2_RDL1R_GROUP		mailbox data high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RDL1RBitList,					 /**/
										Bit<8>{BitPos_t{0}},	 // DATA0
										Bit<8>{BitPos_t{8}},	 // DATA1
										Bit<8>{BitPos_t{16}},	 // DATA2
										Bit<8>{BitPos_t{24}}	 // DATA3
)

enum class RDL1RField {
	DATA0, /*!< DATA0*/
	DATA1, /*!< DATA1*/
	DATA2, /*!< DATA2*/
	DATA3, /*!< DATA3*/
};

template <Port CAN>
static constexpr Register<RDL1RBitList, RDL1RField> RDL1R{BASE_ADDR(CAN), 0x1c8U};
/**@}*/

/**
 * @defgroup	CAN2_RDH1R_GROUP		mailbox data high register group
 *
 * @{
 */

SETUP_REGISTER_INFO(RDH1RBitList,					 /**/
										Bit<8>{BitPos_t{0}},	 // DATA4
										Bit<8>{BitPos_t{8}},	 // DATA5
										Bit<8>{BitPos_t{16}},	 // DATA6
										Bit<8>{BitPos_t{24}}	 // DATA7
)

enum class RDH1RField {
	DATA4, /*!< DATA4*/
	DATA5, /*!< DATA5*/
	DATA6, /*!< DATA6*/
	DATA7, /*!< DATA7*/
};

template <Port CAN>
static constexpr Register<RDH1RBitList, RDH1RField> RDH1R{BASE_ADDR(CAN), 0x1ccU};
/**@}*/

/**
 * @defgroup	CAN2_FMR_GROUP		filter master register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FMRBitList,							/**/
										Binary<>{BitPos_t{0}},	// FINIT
										Bit<6>{BitPos_t{8}}			// CAN2SB
)

enum class FMRField {
	FINIT,	/*!< FINIT*/
	CAN2SB, /*!< CAN2SB*/
};

template <Port CAN>
static constexpr Register<FMRBitList, FMRField> FMR{BASE_ADDR(CAN), 0x200U};
/**@}*/

/**
 * @defgroup	CAN2_FM1R_GROUP		filter mode register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FM1RBitList,													/**/
										Bit<28, std::uint32_t>{BitPos_t{27}}	// FBM
)

enum class FM1RField {
	FBM, /*!< Filter mode*/
};

template <Port CAN>
static constexpr Register<FM1RBitList, FM1RField> FM1R{BASE_ADDR(CAN), 0x204U};
/**@}*/

/**
 * @defgroup	CAN2_FS1R_GROUP		filter scale register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FS1RBitList,													/**/
										Bit<28, std::uint32_t>{BitPos_t{27}}	// FSC
)

enum class FS1RField {
	FSC, /*!< Filter scale configuration*/
};

template <Port CAN>
static constexpr Register<FS1RBitList, FS1RField> FS1R{BASE_ADDR(CAN), 0x20cU};
/**@}*/

/**
 * @defgroup	CAN2_FFA1R_GROUP		filter FIFO assignment register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FFA1RBitList,						 /**/
										Binary<>{BitPos_t{27}},	 // FFA27
										Binary<>{BitPos_t{26}},	 // FFA26
										Binary<>{BitPos_t{25}},	 // FFA25
										Binary<>{BitPos_t{24}},	 // FFA24
										Binary<>{BitPos_t{23}},	 // FFA23
										Binary<>{BitPos_t{22}},	 // FFA22
										Binary<>{BitPos_t{21}},	 // FFA21
										Binary<>{BitPos_t{20}},	 // FFA20
										Binary<>{BitPos_t{19}},	 // FFA19
										Binary<>{BitPos_t{18}},	 // FFA18
										Binary<>{BitPos_t{17}},	 // FFA17
										Binary<>{BitPos_t{16}},	 // FFA16
										Binary<>{BitPos_t{15}},	 // FFA15
										Binary<>{BitPos_t{14}},	 // FFA14
										Binary<>{BitPos_t{13}},	 // FFA13
										Binary<>{BitPos_t{12}},	 // FFA12
										Binary<>{BitPos_t{11}},	 // FFA11
										Binary<>{BitPos_t{10}},	 // FFA10
										Binary<>{BitPos_t{9}},	 // FFA9
										Binary<>{BitPos_t{8}},	 // FFA8
										Binary<>{BitPos_t{7}},	 // FFA7
										Binary<>{BitPos_t{6}},	 // FFA6
										Binary<>{BitPos_t{5}},	 // FFA5
										Binary<>{BitPos_t{4}},	 // FFA4
										Binary<>{BitPos_t{3}},	 // FFA3
										Binary<>{BitPos_t{2}},	 // FFA2
										Binary<>{BitPos_t{1}},	 // FFA1
										Binary<>{BitPos_t{0}}		 // FFA0
)

enum class FFA1RField {
	FFA27, /*!< Filter FIFO assignment for filter 27*/
	FFA26, /*!< Filter FIFO assignment for filter 26*/
	FFA25, /*!< Filter FIFO assignment for filter 25*/
	FFA24, /*!< Filter FIFO assignment for filter 24*/
	FFA23, /*!< Filter FIFO assignment for filter 23*/
	FFA22, /*!< Filter FIFO assignment for filter 22*/
	FFA21, /*!< Filter FIFO assignment for filter 21*/
	FFA20, /*!< Filter FIFO assignment for filter 20*/
	FFA19, /*!< Filter FIFO assignment for filter 19*/
	FFA18, /*!< Filter FIFO assignment for filter 18*/
	FFA17, /*!< Filter FIFO assignment for filter 17*/
	FFA16, /*!< Filter FIFO assignment for filter 16*/
	FFA15, /*!< Filter FIFO assignment for filter 15*/
	FFA14, /*!< Filter FIFO assignment for filter 14*/
	FFA13, /*!< Filter FIFO assignment for filter 13*/
	FFA12, /*!< Filter FIFO assignment for filter 12*/
	FFA11, /*!< Filter FIFO assignment for filter 11*/
	FFA10, /*!< Filter FIFO assignment for filter 10*/
	FFA9,	 /*!< Filter FIFO assignment for filter 9*/
	FFA8,	 /*!< Filter FIFO assignment for filter 8*/
	FFA7,	 /*!< Filter FIFO assignment for filter 7*/
	FFA6,	 /*!< Filter FIFO assignment for filter 6*/
	FFA5,	 /*!< Filter FIFO assignment for filter 5*/
	FFA4,	 /*!< Filter FIFO assignment for filter 4*/
	FFA3,	 /*!< Filter FIFO assignment for filter 3*/
	FFA2,	 /*!< Filter FIFO assignment for filter 2*/
	FFA1,	 /*!< Filter FIFO assignment for filter 1*/
	FFA0,	 /*!< Filter FIFO assignment for filter 0*/
};

template <Port CAN>
static constexpr Register<FFA1RBitList, FFA1RField> FFA1R{BASE_ADDR(CAN), 0x214U};
/**@}*/

/**
 * @defgroup	CAN2_FA1R_GROUP		filter activation register group
 *
 * @{
 */

SETUP_REGISTER_INFO(FA1RBitList,													/**/
										Bit<28, std::uint32_t>{BitPos_t{27}}	// FACT
)

enum class FA1RField {
	FACT, /*!< Filter active*/
};

template <Port CAN>
static constexpr Register<FA1RBitList, FA1RField> FA1R{BASE_ADDR(CAN), 0x21cU};
/**@}*/

/**
 * @defgroup	CAN2_F0R1_GROUP		Filter bank 0 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F0R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F0R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F0R1BitList, F0R1Field> F0R1{BASE_ADDR(CAN), 0x240U};
/**@}*/

/**
 * @defgroup	CAN2_F0R2_GROUP		Filter bank 0 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F0R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F0R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F0R2BitList, F0R2Field> F0R2{BASE_ADDR(CAN), 0x244U};
/**@}*/

/**
 * @defgroup	CAN2_F1R1_GROUP		Filter bank 1 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F1R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F1R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F1R1BitList, F1R1Field> F1R1{BASE_ADDR(CAN), 0x248U};
/**@}*/

/**
 * @defgroup	CAN2_F1R2_GROUP		Filter bank 1 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F1R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F1R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F1R2BitList, F1R2Field> F1R2{BASE_ADDR(CAN), 0x24cU};
/**@}*/

/**
 * @defgroup	CAN2_F2R1_GROUP		Filter bank 2 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F2R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F2R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F2R1BitList, F2R1Field> F2R1{BASE_ADDR(CAN), 0x250U};
/**@}*/

/**
 * @defgroup	CAN2_F2R2_GROUP		Filter bank 2 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F2R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F2R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F2R2BitList, F2R2Field> F2R2{BASE_ADDR(CAN), 0x254U};
/**@}*/

/**
 * @defgroup	CAN2_F3R1_GROUP		Filter bank 3 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F3R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F3R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F3R1BitList, F3R1Field> F3R1{BASE_ADDR(CAN), 0x258U};
/**@}*/

/**
 * @defgroup	CAN2_F3R2_GROUP		Filter bank 3 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F3R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F3R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F3R2BitList, F3R2Field> F3R2{BASE_ADDR(CAN), 0x25cU};
/**@}*/

/**
 * @defgroup	CAN2_F4R1_GROUP		Filter bank 4 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F4R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F4R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F4R1BitList, F4R1Field> F4R1{BASE_ADDR(CAN), 0x260U};
/**@}*/

/**
 * @defgroup	CAN2_F4R2_GROUP		Filter bank 4 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F4R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F4R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F4R2BitList, F4R2Field> F4R2{BASE_ADDR(CAN), 0x264U};
/**@}*/

/**
 * @defgroup	CAN2_F5R1_GROUP		Filter bank 5 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F5R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F5R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F5R1BitList, F5R1Field> F5R1{BASE_ADDR(CAN), 0x268U};
/**@}*/

/**
 * @defgroup	CAN2_F5R2_GROUP		Filter bank 5 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F5R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F5R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F5R2BitList, F5R2Field> F5R2{BASE_ADDR(CAN), 0x26cU};
/**@}*/

/**
 * @defgroup	CAN2_F6R1_GROUP		Filter bank 6 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F6R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F6R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F6R1BitList, F6R1Field> F6R1{BASE_ADDR(CAN), 0x270U};
/**@}*/

/**
 * @defgroup	CAN2_F6R2_GROUP		Filter bank 6 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F6R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F6R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F6R2BitList, F6R2Field> F6R2{BASE_ADDR(CAN), 0x274U};
/**@}*/

/**
 * @defgroup	CAN2_F7R1_GROUP		Filter bank 7 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F7R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F7R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F7R1BitList, F7R1Field> F7R1{BASE_ADDR(CAN), 0x278U};
/**@}*/

/**
 * @defgroup	CAN2_F7R2_GROUP		Filter bank 7 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F7R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F7R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F7R2BitList, F7R2Field> F7R2{BASE_ADDR(CAN), 0x27cU};
/**@}*/

/**
 * @defgroup	CAN2_F8R1_GROUP		Filter bank 8 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F8R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F8R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F8R1BitList, F8R1Field> F8R1{BASE_ADDR(CAN), 0x280U};
/**@}*/

/**
 * @defgroup	CAN2_F8R2_GROUP		Filter bank 8 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F8R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F8R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F8R2BitList, F8R2Field> F8R2{BASE_ADDR(CAN), 0x284U};
/**@}*/

/**
 * @defgroup	CAN2_F9R1_GROUP		Filter bank 9 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F9R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F9R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F9R1BitList, F9R1Field> F9R1{BASE_ADDR(CAN), 0x288U};
/**@}*/

/**
 * @defgroup	CAN2_F9R2_GROUP		Filter bank 9 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F9R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F9R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F9R2BitList, F9R2Field> F9R2{BASE_ADDR(CAN), 0x28cU};
/**@}*/

/**
 * @defgroup	CAN2_F10R1_GROUP		Filter bank 10 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F10R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F10R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F10R1BitList, F10R1Field> F10R1{BASE_ADDR(CAN), 0x290U};
/**@}*/

/**
 * @defgroup	CAN2_F10R2_GROUP		Filter bank 10 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F10R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F10R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F10R2BitList, F10R2Field> F10R2{BASE_ADDR(CAN), 0x294U};
/**@}*/

/**
 * @defgroup	CAN2_F11R1_GROUP		Filter bank 11 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F11R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F11R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F11R1BitList, F11R1Field> F11R1{BASE_ADDR(CAN), 0x298U};
/**@}*/

/**
 * @defgroup	CAN2_F11R2_GROUP		Filter bank 11 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F11R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F11R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F11R2BitList, F11R2Field> F11R2{BASE_ADDR(CAN), 0x29cU};
/**@}*/

/**
 * @defgroup	CAN2_F12R1_GROUP		Filter bank 4 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F12R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F12R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F12R1BitList, F12R1Field> F12R1{BASE_ADDR(CAN), 0x2a0U};
/**@}*/

/**
 * @defgroup	CAN2_F12R2_GROUP		Filter bank 12 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F12R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F12R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F12R2BitList, F12R2Field> F12R2{BASE_ADDR(CAN), 0x2a4U};
/**@}*/

/**
 * @defgroup	CAN2_F13R1_GROUP		Filter bank 13 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F13R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F13R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F13R1BitList, F13R1Field> F13R1{BASE_ADDR(CAN), 0x2a8U};
/**@}*/

/**
 * @defgroup	CAN2_F13R2_GROUP		Filter bank 13 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F13R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F13R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F13R2BitList, F13R2Field> F13R2{BASE_ADDR(CAN), 0x2acU};
/**@}*/

/**
 * @defgroup	CAN2_F14R1_GROUP		Filter bank 14 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F14R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F14R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F14R1BitList, F14R1Field> F14R1{BASE_ADDR(CAN), 0x2b0U};
/**@}*/

/**
 * @defgroup	CAN2_F14R2_GROUP		Filter bank 14 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F14R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F14R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F14R2BitList, F14R2Field> F14R2{BASE_ADDR(CAN), 0x2b4U};
/**@}*/

/**
 * @defgroup	CAN2_F15R1_GROUP		Filter bank 15 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F15R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F15R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F15R1BitList, F15R1Field> F15R1{BASE_ADDR(CAN), 0x2b8U};
/**@}*/

/**
 * @defgroup	CAN2_F15R2_GROUP		Filter bank 15 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F15R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F15R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F15R2BitList, F15R2Field> F15R2{BASE_ADDR(CAN), 0x2bcU};
/**@}*/

/**
 * @defgroup	CAN2_F16R1_GROUP		Filter bank 16 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F16R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F16R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F16R1BitList, F16R1Field> F16R1{BASE_ADDR(CAN), 0x2c0U};
/**@}*/

/**
 * @defgroup	CAN2_F16R2_GROUP		Filter bank 16 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F16R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F16R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F16R2BitList, F16R2Field> F16R2{BASE_ADDR(CAN), 0x2c4U};
/**@}*/

/**
 * @defgroup	CAN2_F17R1_GROUP		Filter bank 17 register 1 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F17R1BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F17R1Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F17R1BitList, F17R1Field> F17R1{BASE_ADDR(CAN), 0x2c8U};
/**@}*/

/**
 * @defgroup	CAN2_F17R2_GROUP		Filter bank 17 register 2 group
 *
 * @{
 */

SETUP_REGISTER_INFO(F17R2BitList,													/**/
										Bit<32, std::uint32_t>{BitPos_t{31}}	// FB
)

enum class F17R2Field {
	FB, /*!< Filter bits*/
};

template <Port CAN>
static constexpr Register<F17R2BitList, F17R2Field> F17R2{BASE_ADDR(CAN), 0x2ccU};
/**@}*/

/**
 * @defgroup	CAN2_F18R1_GROUP		Filter bank 18 register 1 group
 *
 * @{
 */
