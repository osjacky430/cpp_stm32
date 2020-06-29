#pragma once

#include <array>
#include <cstdint>
#include <utility>

#include "cpp_stm32/detail/algorithm.hxx"
#include "cpp_stm32/utility/macro.hxx"

namespace cpp_stm32::spi {

enum class Port : std::uint8_t { SPI1, SPI2, SPI3 };

enum class FifoLevel : std::uint8_t { Empty, Byte, Halfword, Full };
enum class FifoThreshold : std::uint8_t { Halfword = 0, Byte = 1 };
enum class CRCLen : std::uint8_t { Byte, Halfword };
enum class TransferMode : std::uint8_t { FullDuplex, TxHalfDuplex, RxHalfDuplex, TxSimplex, RxSimplex };
enum class SlaveSelectMode : std::uint8_t { Software, InputHardware, OutputHardware };
enum class DataFrameFormat : std::uint8_t { Byte, Halfword };
enum class Mode : std::uint8_t { Mode0, Mode1, Mode2, Mode3 };
enum class Status {
	FTLVL,	/*!< FIFO transmission level*/
	FRLVL,	/*!< FIFO reception level*/
	TIFRFE, /*!< TI frame format error*/
	BSY,		/*!< Busy flag*/
	OVR,		/*!< Overrun flag*/
	MODF,		/*!< Mode fault*/
	CRCERR, /*!< CRC error flag*/
	TXE,		/*!< Transmit buffer empty*/
	RXNE,		/*!< Receive buffer not empty*/
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
SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(DataSize, /**/
																		 std::pair{4U, 0b11}, std::pair{5U, 0b100}, std::pair{6U, 0b101},
																		 std::pair{7U, 0b110}, std::pair{8U, 0b111}, std::pair{9U, 0b1000},
																		 std::pair{10U, 0b1001}, std::pair{11U, 0b1010}, std::pair{12U, 0b1011},
																		 std::pair{13U, 0b1100}, std::pair{14U, 0b1101}, std::pair{15U, 0b1110},
																		 std::pair{16U, 0b1111});

}	 // namespace cpp_stm32::spi
