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

Driver::Usart const pc{Driver::UsartTx_v<Gpio::PinName::PA_2>, Driver::UsartRx_v<Gpio::PinName::PA_3>, 115200_Baud};

int main() {
	using namespace std::literals::chrono_literals;
	Sys::Clock::init<Rcc::ClkSrc::Hse>();

	Pwr::unlock_write_protection();
	Rcc::hold_reset_backup_domain();
	Rcc::release_reset_backup_domain();
	Rcc::set_rtc_prescaler(Rcc::RTCPRE{Rcc::DivisionFactor_v<8>});
	Rcc::set_rtc_clk_src<Rcc::RtcClk::Hse>();
	Rcc::enable_rtc();

	Rtc::set_hour_format(Rtc::HourFormat::TwentyFour);

	Rtc::unlock_write_protection();
	Rtc::enable_init_mode();
	Rtc::wait_status<Rtc::Status::INITF>(true);
	Rtc::set_async_prescaler(Rtc::AsyncPrescaler_t{124});
	Rtc::set_sync_prescaler(Rtc::SyncPrescaler_t{7999});
	Rtc::set_time_format_24_hour();
	Rtc::set_time(13h, 21min, 40s);
	Rtc::set_date(Rtc::Year_t{2020}, Rtc::Month::Apr, Rtc::Weekday::Sun, Rtc::Date_t{3U});

	Rtc::disable_init_mode();
	Rtc::lock_write_protection();

	while (true) {
		Rtc::clear_status<Rtc::Status::RSF>();
		Rtc::wait_status<Rtc::Status::RSF>(true);

		auto const [y, w, m, d] = Rtc::get_date();
		auto const [h, min, s]	= Rtc::get_time();

		pc << y << "_" << h << ':' << min << ':' << s << "\n\r";
	}
}
