// #include "cpp_stm32/driver/digitalout.hxx"
// #include "cpp_stm32/driver/real_time_clock.hxx"
#include "cpp_stm32/driver/usart_serial.hxx"
#include "cpp_stm32/target/stm32/l4/gpio.hxx"
#include "cpp_stm32/target/stm32/l4/rcc.hxx"
//#include "cpp_stm32/target/stm32/l4/usart.hxx"
//#include "cpp_stm32/target/stm32/l4/rtc.hxx"
#include "cpp_stm32/target/stm32/l4/spi.hxx"
#include "cpp_stm32/target/stm32/l4/sys_init.hxx"
// #include "cpp_stm32/target/stm32/l4/wwdg.hxx"

namespace Pwr		= cpp_stm32::pwr;
namespace Rcc		= cpp_stm32::rcc;
namespace Gpio	= cpp_stm32::gpio;
namespace Sys		= cpp_stm32::sys;
namespace Usart = cpp_stm32::usart;
namespace Spi		= cpp_stm32::spi;
// namespace Rtc		= cpp_stm32::rtc;

namespace Driver = cpp_stm32::driver;

// using cpp_stm32::operator"" _kHz;
using Usart::operator"" _Baud;
// using Rtc::operator"" _Am;

Driver::Usart const pc{Driver::UsartTx_v<Gpio::PinName::PA_2>, Driver::UsartRx_v<Gpio::PinName::PA_3>, 115200_Baud};

constexpr void setup_spi() noexcept {
	//	Rcc::enable_periph_clk<Rcc::PeriphClk::GpioB>();
	//	Rcc::enable_periph_clk<Rcc::PeriphClk::Spi2>();
	// Gpio::mode_setup<Gpio::Port::PortB, Gpio::Pin::Pin13, Gpio::Pin::Pin14, Gpio::Pin::Pin15>(Gpio::Mode::AltFunc,
	//																																												Gpio::Pupd::None);

	// Gpio::set_alternate_function<Gpio::Port::PortB, Gpio::Pin::Pin13, Gpio::Pin::Pin14, Gpio::Pin::Pin15>(
	//	Gpio::AltFunc::AF5);

	// Spi::set_master_mode<Spi::Port::SPI2>();
	// Spi::set_baudrate_prescaler<Spi::Port::SPI2>(Spi::Baudrate_t{cpp_stm32::uint32_c<32>{}});
	Spi::set_transfer_mode<Spi::Port::SPI2, Spi::TransferMode::FullDuplex>();
	// Spi::set_mode<Spi::Port::SPI2>(Spi::Mode::Mode2);
	// Spi::set_data_frame_format<Spi::Port::SPI2>(Spi::DataFrameFormat::Byte);
	// Spi::set_msb_first<Spi::Port::SPI2>();
	Spi::set_slave_select_mode<Spi::Port::SPI2, Spi::SlaveSelectMode::OutputHardware>();

	Spi::enable<Spi::Port::SPI2>();
}

int main() {
	// using namespace std::literals::chrono_literals;
	Sys::Clock::init<Rcc::ClkSrc::Hse>();

	cpp_stm32::spi::enable<cpp_stm32::spi::Port::SPI1>();
	// Driver::RealTimeClock const rtc_clk;
	// rtc_clk.init<Rcc::RtcClk::Hse>(Rtc::Year_t{2020}, Rtc::Month::June, Rtc::Weekday::Sat, Rtc::Date_t{20U}, 10_Am,
	// 23min, 														 40s);
	// Usart::set_hardware_flow_ctl<Usart::Port::Usart1>(Usart::HardwareFlowControl::None);
	while (true) {
		// auto const [y, w, m, d, h, min, s] = rtc_clk.read_calendar();

		// pc << "1"
		//  << "\n\r";
		// pc << y << "_" << d << "_" << h << ':' << min << ':' << s << "\n\r";
	}
}
