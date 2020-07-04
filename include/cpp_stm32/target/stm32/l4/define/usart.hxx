#pragma once

#include <cstdint>

namespace cpp_stm32::usart {

enum class Port : std::uint8_t { Usart1, Usart2, Total };

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
enum class DataBit : std::uint8_t { DataBit8, DataBit9, DataBit7 };

enum class HardwareFlowControl : std::uint8_t { None, CTS, RTS, Both };
enum class TransferMode : std::uint8_t { RxOnly = 1, TxOnly, TxRx };
enum class Parity : std::uint8_t { Even, Odd, None };
enum class Stopbit : std::uint8_t { Bit1, Bit0f5, Bit2, Bit1f5 };

// @todo this needs documentation, or just dont do this
enum class InterruptFlag : std::uint8_t {
	TXE		= 7,
	CTSIF = 10,
	TC		= 6,
	RXNE	= 5,
	IDLE	= 4,
	PE		= 8,
	LBDF,
	NF,
	ORE,
	FE,
	CMF		= 14,
	RTOF	= 26,
	EOBF	= 27,
	WUF		= 22,
	TCBGT = 24
};
}	 // namespace cpp_stm32::usart
