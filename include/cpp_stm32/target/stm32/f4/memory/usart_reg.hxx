/**
 * @Date:   2019-12-24T14:08:01+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: usart_reg.hxx
 */

#pragma once

#include "cpp_stm32/target/memory_map.hxx"
#include "cpp_stm32/utility/bit.hxx"
#include "cpp_stm32/utility/register.hxx"

enum class UsartNum { Usart1, Usart2, Usart6 };

static constexpr auto USART_BASE(UsartNum const& t_usart_num) {
	switch (t_usart_num) {
		case UsartNum::Usart1:
			return memory_at(MemoryMap::Apb2Base, 0x1000U);
		case UsartNum::Usart2:
			return memory_at(MemoryMap::Apb1Base, 0x4400U);
		case UsartNum::Usart6:
			return memory_at(MemoryMap::Apb2Base, 0x1400U);
	}
}

/**
 * @defgroup USART_SR_GROUP
 * @{
 */

SETUP_REGISTER_INFO(UsartSrInfo, /**/
										StatusBit<1>{BitPos_t{0}}, StatusBit<1>{BitPos_t{1}}, StatusBit<1>{BitPos_t{2}},
										StatusBit<1>{BitPos_t{3}}, StatusBit<1>{BitPos_t{4}}, Binary<>{BitPos_t{5}}, Binary<>{BitPos_t{6}},
										StatusBit<1>{BitPos_t{7}}, Binary<>{BitPos_t{8}}, Binary<>{BitPos_t{9}}, )

enum class UsartSrBit { PE, FE, NF, OrE, Idle, RxNE, TC, TxE, LBD, CTS };

template <UsartNum Port>
static constexpr Register<UsartSrInfo, UsartSrBit> USART_SR{USART_BASE(Port), 0x00U};
/**@}*/

/**
 * @defgroup USART_DR_GROUP
 * @{
 */
SETUP_REGISTER_INFO(UsartDrInfo, Bit<8>{BitPos_t{0}})

enum class UsartDrBit { Dr };

template <UsartNum Port>
static constexpr Register<UsartDrInfo, UsartDrBit> USART_DR{USART_BASE(Port), 0x04U};

/**@}*/

/**
 * @degroup USART_BRR_GROUP
 * @{
 */

SETUP_REGISTER_INFO(UsartBrrInfo, Bit<4>{BitPos_t{0}}, Bit<12, std::uint16_t>{BitPos_t{4}})

enum class UsartBrrBit { DivFraction, DivMantissa };

template <UsartNum Port>
static constexpr Register<UsartBrrInfo, UsartBrrBit> USART_BRR{USART_BASE(Port), 0x08U};
/**@}*/

/**
 * @degroup USART_CR1_GROUP
 * @{
 */

enum class OverSampling : std::uint8_t;
enum class DataBit : std::uint8_t;
enum class UsartParity : std::uint8_t;

SETUP_REGISTER_INFO(UsartCr1Info, /**/
										Binary<>{BitPos_t{0}}, Binary<>{BitPos_t{1}}, Binary<>{BitPos_t{2}}, Binary<>{BitPos_t{3}},
										Binary<>{BitPos_t{4}}, Binary<>{BitPos_t{5}}, Binary<>{BitPos_t{6}}, Binary<>{BitPos_t{7}},
										Binary<>{BitPos_t{8}}, Bit<1, UsartParity>{BitPos_t{9}}, Binary<>{BitPos_t{10}},
										Binary<>{BitPos_t{11}}, Bit<1, DataBit>{BitPos_t{12}}, Binary<>{BitPos_t{13}},
										Bit<1, OverSampling>{BitPos_t{15}})

enum class UsartCr1Bit { SBk, RWu, RE, TE, IdleIE, RxNEIE, TCIE, TxEIE, PEIE, PS, PCE, Wake, M, UE, Over8 };

template <UsartNum Port>
static constexpr Register<UsartCr1Info, UsartCr1Bit> USART_CR1{USART_BASE(Port), 0x0CU};

/**@}*/

/**
 * @defgroup USART_CR2_GROUP
 * @{
 */

enum class UsartStopbit : std::uint8_t;

SETUP_REGISTER_INFO(UsartCr2Info, /**/
										Bit<4>{BitPos_t{0}}, Binary<>{BitPos_t{5}}, Binary<>{BitPos_t{6}}, Binary<>{BitPos_t{8}},
										Binary<>{BitPos_t{9}}, Binary<>{BitPos_t{10}}, Binary<>{BitPos_t{11}},
										Bit<2, UsartStopbit>{BitPos_t{12}}, Binary<>{BitPos_t{14}})

enum class UsartCr2Bit { Add, LBDL, LBDIE, LbCl, CPha, CPol, ClkEn, Stop, LINEn };

template <UsartNum Port>
static constexpr Register<UsartCr2Info, UsartCr2Bit> USART_CR2{USART_BASE(Port), 0x10U};
/**@}*/

/**
 * @defgroup USART_CR3_GROUP
 * @{
 */

SETUP_REGISTER_INFO(UsartCr3Info, /**/
										Binary<>{BitPos_t{0}}, Binary<>{BitPos_t{1}}, Binary<>{BitPos_t{2}}, Binary<>{BitPos_t{3}},
										Binary<>{BitPos_t{4}}, Binary<>{BitPos_t{5}}, Binary<>{BitPos_t{6}}, Binary<>{BitPos_t{7}},
										Binary<>{BitPos_t{8}}, Binary<>{BitPos_t{9}}, Binary<>{BitPos_t{10}}, Binary<>{BitPos_t{11}})

enum class UsartCr3Bit { EIE, IrEn, IrLP, HDSel, NAck, SCEN, DMAR, DMAT, RTSE, CTSE, CTSIE, OneBit };

template <UsartNum Port>
static constexpr Register<UsartCr3Info, UsartCr3Bit> USART_CR3{USART_BASE(Port), 0x14U};

/**@}*/

/**
 * @defgroup USART_GTPR_GROUP
 * @{
 */

SETUP_REGISTER_INFO(UsartGtprInfo, /**/
										Bit<8>{BitPos_t{0}}, Bit<8>{BitPos_t{8}})

enum class UsartGtprBit { Psc, GT };

template <UsartNum Port>
static constexpr Register<UsartGtprInfo, UsartGtprBit> USART_GTPR{USART_BASE(Port), 0x18U};

/**@}*/
