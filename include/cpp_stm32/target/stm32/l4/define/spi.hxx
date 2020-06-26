#pragma once

#include <array>
#include <cstdint>

#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/utility/macro.hxx"

namespace cpp_stm32::spi {

enum class Port : std::uint8_t { SPI1, SPI2, SPI3, SPI4 };

enum class CRCLen : std::uint8_t { Byte, Halfword };
enum class TransferMode : std::uint8_t { FullDuplex, TxHalfDuplex, RxHalfDuplex, TxSimplex, RxSimplex };
enum class SlaveSelectMode : std::uint8_t { Software, InputHardware, OutputHardware };
enum class DataFrameFormat : std::uint8_t { Byte, Halfword };
enum class Mode : std::uint8_t { Mode0, Mode1, Mode2, Mode3 };
enum class Status : std::uint8_t {
	RXNE,		/*!< Receive buffer not empty*/
	TXE,		/*!< Transmit buffer empty*/
	CHSIDE, /*!< Channel side*/
	UDR,		/*!< Underrun flag*/
	CRCERR, /*!< CRC error flag*/
	MODF,		/*!< Mode fault*/
	OVR,		/*!< Overrun flag*/
	BSY,		/*!< Busy flag*/
	TIFRFE, /*!< TI frame format error*/
};

enum class InterruptFlag : std::uint8_t { ERRIE, RXNEIE, TXEIE };

/**
 *  @class  Baurdrate_t
 *  @brief  Utility class used to check whether baudrate prescaler is reasonable
 */
SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(Baudrate_t, /**/
																		 std::pair{2U, 0b00}, std::pair{4U, 0b01}, std::pair{8U, 0b10},
																		 std::pair{16U, 0b11}, std::pair{32U, 0b100}, std::pair{64U, 0b101},
																		 std::pair{128U, 0b110}, std::pair{256U, 0b111});
/**
 *  @class  DataSize
 *  @brief  Utility class used to check whether data size is reasonable
 */
SETUP_LOOKUP_TABLE_WITH_BOUND(DataSize, 4, 16);

}	 // namespace cpp_stm32::spi
