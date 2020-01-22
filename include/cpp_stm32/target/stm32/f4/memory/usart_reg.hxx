// Copyright (c) 2020 by osjacky430.
// All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the Lesser GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// Lesser GNU General Public License for more details.
//
// You should have received a copy of the Lesser GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "cpp_stm32/common/usart.hxx"
#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/register.hxx"
#include "cpp_stm32/target/stm32/f4/memory/memory_map.hxx"

namespace cpp_stm32::usart {

enum class Port { Usart1, Usart2, Usart3, Uart4, Uart5, Usart6 };

/**
 * @enum OverSampling
 */
enum class OverSampling : std::uint8_t {
	OverSampling16,
	OverSampling8,
};

/**
 * @enum 	DataBit
 */
enum class DataBit : std::uint8_t { DataBit8, DataBit9 };

enum class HardwareFlowControl : std::uint8_t { None, CTS, RTS, Both };
enum class Mode : std::uint8_t { RxOnly = 1, TxOnly, TxRx };
enum class Parity : std::uint8_t { Even, Odd, None };
enum class Stopbit : std::uint8_t { Bit1, Bit0f5, Bit2, Bit1f5 };

}	 // namespace cpp_stm32::usart

namespace cpp_stm32::usart::reg {

static constexpr auto BASE_ADDR(Port const& t_usart_num) {
	switch (t_usart_num) {
		case Port::Usart1:
			return memory_at(PeriphAddr::Apb2Base, 0x1000U);
		case Port::Usart2:
			return memory_at(PeriphAddr::Apb1Base, 0x4400U);
		case Port::Usart3:
			return memory_at(PeriphAddr::Apb1Base, 0x4800U);
		case Port::Uart4:
			return memory_at(PeriphAddr::Apb1Base, 0x5000U);
		case Port::Uart5:
			return memory_at(PeriphAddr::Apb1Base, 0x4C00U);
		case Port::Usart6:
			return memory_at(PeriphAddr::Apb2Base, 0x1400U);
	}
}

/**
 * @defgroup SR_GROUP		USART Status Register Group
 * @{
 */

SETUP_REGISTER_INFO(UsartSrInfo, /**/
										StatusBit<1>{BitPos_t{0}}, StatusBit<1>{BitPos_t{1}}, StatusBit<1>{BitPos_t{2}},
										StatusBit<1>{BitPos_t{3}}, StatusBit<1>{BitPos_t{4}}, Binary<>{BitPos_t{5}}, Binary<>{BitPos_t{6}},
										StatusBit<1>{BitPos_t{7}}, Binary<>{BitPos_t{8}}, Binary<>{BitPos_t{9}})

enum class SrBit { PE, FE, NF, OrE, Idle, RxNE, TC, TxE, LBD, CTS };

template <Port InputPort>
static constexpr Register<UsartSrInfo, SrBit> SR{BASE_ADDR(InputPort), 0x00U};
/**@}*/

/**
 * @defgroup DR_GROUP		USART Data Register Group
 * @{
 */
SETUP_REGISTER_INFO(UsartDrInfo, Bit<8>{BitPos_t{0}})

enum class DrBit { Dr };

template <Port InputPort>
static constexpr Register<UsartDrInfo, DrBit, Access::Byte> DR{BASE_ADDR(InputPort), 0x04U};

/**@}*/

/**
 * @degroup BRR_GROUP		Usart Baud Rate Register Group
 * @{
 */

SETUP_REGISTER_INFO(UsartBrrInfo, Bit<4>{BitPos_t{0}}, Bit<12, std::uint16_t>{BitPos_t{4}})

enum class BrrBit { DivFraction, DivMantissa };

template <Port InputPort>
static constexpr Register<UsartBrrInfo, BrrBit, Access::HalfWord> BRR{BASE_ADDR(InputPort), 0x08U};
/**@}*/

/**
 * @degroup CR1_GROUP		USART Control Register 1 Group
 * @{
 */

SETUP_REGISTER_INFO(UsartCr1Info, /**/
										Binary<>{BitPos_t{0}}, Binary<>{BitPos_t{1}}, Binary<>{BitPos_t{2}}, Binary<>{BitPos_t{3}},
										Binary<>{BitPos_t{4}}, Binary<>{BitPos_t{5}}, Binary<>{BitPos_t{6}}, Binary<>{BitPos_t{7}},
										Binary<>{BitPos_t{8}}, Bit<1, usart::Parity>{BitPos_t{9}}, Binary<>{BitPos_t{10}},
										Binary<>{BitPos_t{11}}, Bit<1, usart::DataBit>{BitPos_t{12}}, Binary<>{BitPos_t{13}},
										Bit<1, usart::OverSampling>{BitPos_t{15}})

enum class Cr1Bit { SBk, RWu, RE, TE, IdleIE, RxNEIE, TCIE, TxEIE, PEIE, PS, PCE, Wake, M, UE, Over8 };

template <Port InputPort>
static constexpr Register<UsartCr1Info, Cr1Bit> CR1{BASE_ADDR(InputPort), 0x0CU};

/**@}*/

/**
 * @defgroup CR2_GROUP		USART Control Register 2 Group
 * @{
 */

SETUP_REGISTER_INFO(UsartCr2Info, /**/
										Bit<4>{BitPos_t{0}}, Binary<>{BitPos_t{5}}, Binary<>{BitPos_t{6}}, Binary<>{BitPos_t{8}},
										Binary<>{BitPos_t{9}}, Binary<>{BitPos_t{10}}, Binary<>{BitPos_t{11}},
										Bit<2, usart::Stopbit>{BitPos_t{12}}, Binary<>{BitPos_t{14}})

enum class Cr2Bit { Add, LBDL, LBDIE, LbCl, CPha, CPol, ClkEn, Stop, LINEn };

template <Port InputPort>
static constexpr Register<UsartCr2Info, Cr2Bit> CR2{BASE_ADDR(InputPort), 0x10U};
/**@}*/

/**
 * @defgroup CR3_GROUP		USART Control Register 3 Group
 * @{
 */

SETUP_REGISTER_INFO(UsartCr3Info, /**/
										Binary<>{BitPos_t{0}}, Binary<>{BitPos_t{1}}, Binary<>{BitPos_t{2}}, Binary<>{BitPos_t{3}},
										Binary<>{BitPos_t{4}}, Binary<>{BitPos_t{5}}, Binary<>{BitPos_t{6}}, Binary<>{BitPos_t{7}},
										Binary<>{BitPos_t{8}}, Binary<>{BitPos_t{9}}, Binary<>{BitPos_t{10}}, Binary<>{BitPos_t{11}})

enum class Cr3Bit { EIE, IrEn, IrLP, HDSel, NAck, SCEN, DMAR, DMAT, RTSE, CTSE, CTSIE, OneBit };

template <Port InputPort>
static constexpr Register<UsartCr3Info, Cr3Bit> CR3{BASE_ADDR(InputPort), 0x14U};

/**@}*/

/**
 * @defgroup GTPR_GROUP		USART Guard Time and Prescaler Register Group
 * @{
 */

SETUP_REGISTER_INFO(UsartGtprInfo, /**/
										Bit<8>{BitPos_t{0}}, Bit<8>{BitPos_t{8}})

enum class GtprBit { Psc, GT };

template <Port InputPort>
static constexpr Register<UsartGtprInfo, GtprBit> GTPR{BASE_ADDR(InputPort), 0x18U};

/**@}*/

}	 // namespace cpp_stm32::usart::reg
