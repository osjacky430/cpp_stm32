#include "cpp_stm32/driver/digitalout.hxx"
#include "cpp_stm32/driver/usart_serial.hxx"

#include "cpp_stm32/target/stm32/f4/gpio.hxx"
#include "cpp_stm32/target/stm32/f4/pwr.hxx"
#include "cpp_stm32/target/stm32/f4/rcc.hxx"
#include "cpp_stm32/target/stm32/f4/rtc.hxx"
#include "cpp_stm32/target/stm32/f4/sys_init.hxx"

namespace Pwr		= cpp_stm32::pwr;
namespace Rcc		= cpp_stm32::rcc;
namespace Gpio	= cpp_stm32::gpio;
namespace Sys		= cpp_stm32::sys;
namespace Usart = cpp_stm32::usart;
namespace Rtc		= cpp_stm32::rtc;

namespace Driver = cpp_stm32::driver;

using cpp_stm32::operator"" _kHz;
using Usart::operator"" _Baud;
using Rtc::operator"" _Am;

Driver::Usart const pc{Driver::UsartTx_v<Gpio::PinName::PA_2>, Driver::UsartRx_v<Gpio::PinName::PA_3>, 115200_Baud};

int main() {
	using namespace std::literals::chrono_literals;
	Sys::Clock::init<Rcc::ClkSrc::Hse>();

	Rtc::init<Rcc::RtcClk::Hse>(Rtc::Year_t{2020}, Rtc::Month::Apr, Rtc::Weekday::Sun, Rtc::Date_t{3U}, 11_Am, 21min,
															40s);

	while (true) {
		Rtc::clear_status<Rtc::Status::RSF>();
		Rtc::wait_status<Rtc::Status::RSF>(true);

		auto const [h, min, s]	= Rtc::get_time();
		auto const [y, w, m, d] = Rtc::get_date();

		// pc << d << "\n\r";
		pc << y << "_" << d << "_" << h << ':' << min << ':' << s << "\n\r";
	}
}
