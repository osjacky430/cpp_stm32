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

using Baudrate_t = cpp_stm32::KeyValTable<struct CPP_STM32_LUT_SPI_BAUD, /**/
																					PAIR(2, 0b00), PAIR(4, 0b01), PAIR(8, 0b10), PAIR(16, 0b11), PAIR(32, 0b100),
																					PAIR(64, 0b101), PAIR(128, 0b110), PAIR(256, 0b111)>;
/**
 *  @class  DataSize
 *  @brief  Utility class used to check whether data size is reasonable
 */

using DataSize = cpp_stm32::KeyValTable<struct CPP_STM32_LUT_SPI_DS, /**/
																				PAIR(4, 0b11), PAIR(5, 0b100), PAIR(6, 0b101), PAIR(7, 0b110), PAIR(8, 0b111),
																				PAIR(9, 0b1000), PAIR(10, 0b1001), PAIR(11, 0b1010), PAIR(12, 0b1011),
																				PAIR(13, 0b1100), PAIR(14, 0b1101), PAIR(15, 0b1110), PAIR(16, 0b1111)>;

}	 // namespace cpp_stm32::spi
