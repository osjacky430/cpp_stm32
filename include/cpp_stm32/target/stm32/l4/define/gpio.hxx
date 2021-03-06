#pragma once

#include <cstdint>

namespace cpp_stm32::gpio {

enum class Port : std::uint8_t { PortA, PortB, PortC, PortD, PortE, PortH, Total };

enum class Pin : std::uint8_t {
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7,
	Pin8,
	Pin9,
	Pin10,
	Pin11,
	Pin12,
	Pin13,
	Pin14,
	Pin15,
	Total
};

/**
 * @enum Mode
 */
enum class Mode : std::uint8_t {
	Input,	 /*!< Input mode */
	Output,	/*!< Output mode */
	AltFunc, /*!< Alternate Function mode*/
	Analog	 /*!< Analog mode*/
};

enum class Pupd : std::uint8_t { None, PullUp, PullDown };
enum class OutputType : std::uint8_t { PushPull, OpenDrain };
enum class OutputSpeed : std::uint8_t { Low, Medium, Fast, High };
enum class AltFunc : std::uint8_t {
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
};

/**
 * @enum  PinName
 */
enum class PinName {
	// clang-format off
	PA_0, PA_1, PA_2, PA_3, PA_4, PA_5, PA_6, PA_7, PA_8, PA_9, PA_10, PA_11, PA_12, PA_13, PA_14, PA_15, // GPIOA
	PB_0, PB_1, PB_2, PB_3, Total, NC
	// clang-format on
};

}	// namespace cpp_stm32::gpio
