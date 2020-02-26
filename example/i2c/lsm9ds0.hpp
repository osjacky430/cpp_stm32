#pragma once

#include "cpp_stm32/driver/gpio_base.hxx"
#include "cpp_stm32/driver/i2c.hxx"

namespace Lsm9ds0 {

namespace Gpio	 = cpp_stm32::gpio;
namespace Driver = cpp_stm32::driver;
namespace I2c		 = cpp_stm32::i2c;

using cpp_stm32::operator"" _kHz;
using cpp_stm32::operator"" _byte;

template <Gpio::PinName>
struct GyroCs {};

template <Gpio::PinName>
struct XMCs {};

template <Gpio::PinName>
struct SDO {};

template <Gpio::PinName>
struct SDA {};

template <Gpio::PinName>
struct SCL {};

enum class Sensor : std::uint8_t { Gyroscope, Accelerometer };

template <Gpio::PinName CS_GYRO, Gpio::PinName CS_XM, Gpio::PinName SDOPin, Gpio::PinName SCLPin, Gpio::PinName SDAPin>
class LSM9DS0 {
 private:
	enum class RegisterMap : std::uint8_t {
		WHO_AM_I = 0xF,
		/* GYRO Register map */
		/* Accelerometer Register map */
	};

	static constexpr std::array<std::uint8_t, 2> SLAVE_ADDR{0b1101010, 0b0011110};

	// using COMM_t = std::conditional_t<SDO == Gpio::PinName::NC, I2C, SPI>
	static inline auto const COMM = []() {
		// if constexpr (std::is_same_v<COMM_t, I2C>) {
		auto const comm = Driver::I2C{Driver::I2cSDA<SDAPin>{}, Driver::I2cSCL<SCLPin>{}, 400_kHz};
		// } else {
		// init spi
		// }

		return comm;
	}();

 public:
	explicit constexpr LSM9DS0(GyroCs<CS_GYRO>, XMCs<CS_XM>, SDO<SDOPin>, SCL<SCLPin>, SDA<SDAPin>) noexcept {
		if constexpr (SDOPin == Gpio::PinName::NC) {	// I2C
			Driver::GpioUtil<CS_GYRO, CS_XM>::enableAllGpioClk();
			Driver::GpioUtil<CS_GYRO, CS_XM>::modeSetup(Gpio::Mode::Output, Gpio::Pupd::None);
			Driver::GpioUtil<CS_GYRO, CS_XM>::set();	// set high to enable i2c mode

		} else {	// SPI
							// @note this part will be finished if SPI is done
		}
	}

	constexpr auto getID(Sensor const t_sensor) const noexcept {
		const std::array val{cpp_stm32::to_underlying(RegisterMap::WHO_AM_I)};
		return COMM.xfer(I2c::SlaveAddr7_t{SLAVE_ADDR[cpp_stm32::to_underlying(t_sensor)]}, 1_byte, val);
	}
};

}	 // namespace Lsm9ds0
