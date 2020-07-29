#pragma once

#include <type_traits>

#include "cpp_stm32/driver/gpio_base.hxx"
#include "cpp_stm32/driver/i2c.hxx"
#include "cpp_stm32/driver/spi.hxx"
#include "cpp_stm32/utility/integral_constant.hxx"

namespace Lsm9ds0 {

namespace Gpio	 = cpp_stm32::gpio;
namespace Driver = cpp_stm32::driver;
namespace I2c		 = cpp_stm32::i2c;
namespace Spi		 = cpp_stm32::spi;

using cpp_stm32::operator"" _k;
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

template <Gpio::PinName CsGyro, Gpio::PinName CsXm, Gpio::PinName SDOPin, Gpio::PinName SCLPin, Gpio::PinName SDAPin>
class LSM9DS0 {
 private:
	enum class RegisterMap : std::uint8_t {
		WHO_AM_I = 0xF,
		/* GYRO Register map */
		/* Accelerometer Register map */
	};

	// using I2C_t	= Driver::I2C<SDAPin, SCLPin, 400_k>;
	// using SPI_t	= Driver::SPI<5000_k, SDOPin, SDAPin, SCLPin>;
	// using COMM_t = std::conditional_t<SDOPin == Gpio::PinName::NC, I2C_t, SPI_t>;

	static constexpr std::array<std::uint8_t, 2> SLAVE_ADDR{0b1101010, 0b0011110};
	static constexpr bool IS_I2C_COMM = SDOPin == Gpio::PinName::NC;

	static inline auto const COMM = []() {
		Driver::GpioUtil<CsGyro, CsXm>::enableAllGpioClk();
		Driver::GpioUtil<CsGyro, CsXm>::modeSetup(Gpio::Mode::Output, Gpio::Pupd::None);
		Driver::GpioUtil<CsGyro, CsXm>::set();	// set high to enable i2c mode

		if constexpr (IS_I2C_COMM) {
			return Driver::I2C<SDAPin, SCLPin, 400_k>{Driver::I2cSDA<SDAPin>{}, Driver::I2cSCL<SCLPin>{}, 400_kHz};
		} else {
			return Driver::SPI(Driver::Miso<SDOPin>{}, Driver::Mosi<SDAPin>{}, Driver::Sclk<SCLPin>{}, Spi::Mode::Mode2,
												 cpp_stm32::size_c<8>{}, 500_kHz);
		}
	}();

	static constexpr auto spiStartTransfer(Sensor const t_sensor) noexcept {
		struct CommSection {
			Sensor sensor;
			CommSection(Sensor const t_in_sensor) noexcept : sensor(t_in_sensor) {
				if (sensor == Sensor::Gyroscope) {
					Driver::GpioUtil<CsGyro>::clear();
				} else {
					Driver::GpioUtil<CsXm>::clear();
				}
			}

			~CommSection() noexcept {
				if (sensor == Sensor::Gyroscope) {
					Driver::GpioUtil<CsGyro>::set();
				} else {
					Driver::GpioUtil<CsXm>::set();
				}
			}
		};

		return CommSection(t_sensor);
	}

 public:
	explicit constexpr LSM9DS0(GyroCs<CsGyro>, XMCs<CsXm>, SDO<SDOPin>, SCL<SCLPin>, SDA<SDAPin>) noexcept {}

	constexpr auto getID(Sensor const t_sensor) const noexcept {
		if constexpr (IS_I2C_COMM) {
			std::array const val{cpp_stm32::to_underlying(RegisterMap::WHO_AM_I)};
			return COMM.xfer(I2c::SlaveAddr7_t{SLAVE_ADDR[cpp_stm32::to_underlying(t_sensor)]}, 1_byte, val);
		} else {
			auto const comm_section = spiStartTransfer(t_sensor);
			std::uint8_t tx_data		= (1U << 7) | cpp_stm32::to_underlying(RegisterMap::WHO_AM_I);

			COMM.xfer(1_byte, tx_data);
			return COMM.xfer(1_byte, Driver::DUMMY_SIGNAL<std::uint8_t>);
		}
	}
};

}	// namespace Lsm9ds0
