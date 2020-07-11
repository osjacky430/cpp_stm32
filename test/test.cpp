// #define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_DISABLE_EXCEPTIONS
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_NOSTDOUT

#include <sys/signal.h>
#include <sys/stat.h>
#include <unistd.h>
#include <array>
#include <cerrno>
#include <cstdlib>
#include <streambuf>

#include "catch2/catch.hpp"

#include "cpp_stm32/driver/digitalout.hxx"
#include "cpp_stm32/driver/usart_serial.hxx"

#include "gpio.hxx"
#include "rcc.hxx"
#include "sys_init.hxx"

namespace Rcc		= cpp_stm32::rcc;
namespace Gpio	= cpp_stm32::gpio;
namespace Sys		= cpp_stm32::sys;
namespace Usart = cpp_stm32::usart;

namespace Driver = cpp_stm32::driver;

// using cpp_stm32::operator"" _kHz;
using Usart::operator"" _Baud;

void* __dso_handle = (void*)&__dso_handle;

Driver::Usart const pc{Driver::UsartTx_v<Gpio::PinName::PA_2>, Driver::UsartRx_v<Gpio::PinName::PA_3>, 115200_Baud};

class OutBuff : public std::basic_streambuf<char> {
 protected:
	std::streamsize xsputn(char const* t_str, std::streamsize t_n) override {
		pc << t_str << "\r\n";
		return t_n;
	}

	int overflow(int t_ch) override {
		pc << t_ch;
		return 1;
	}

 public:
	OutBuff() : std::basic_streambuf<char>{} {};
};

namespace Catch {

std::ostream& cout() {
	static std::ostream ret(new OutBuff());
	return ret;
}
std::ostream& clog() {
	static std::ostream ret(new OutBuff());
	return ret;
}
std::ostream& cerr() { return clog(); }

}	// namespace Catch

unsigned int Factorial(unsigned int number) { return number <= 1 ? number : Factorial(number - 1) * number; }

TEST_CASE("Factorials are computed", "[factorial]") {
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
}

int main() {
	Sys::Clock::init<Rcc::ClkSrc::Hse>();

	Driver::DigitalOut<Gpio::PinName::PA_5> const led;
	Catch::Session().run();

	while (true) {
		for (int i = 0; i < 10000000; ++i) {
			__asm("nop");
		}

		led.toggle();
	}

	return 0;
}
