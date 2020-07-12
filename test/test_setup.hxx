#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_DISABLE_EXCEPTIONS
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_NOSTDOUT
#define CATCH_CONFIG_COLOUR_NONE

#include "catch2/catch.hpp"

class OutBuff : public std::basic_streambuf<char> {
 private:
	// implemented in test_main
	void put_str(char const* t_str, std::streamsize t_n) noexcept;

 protected:
	std::streamsize xsputn(char const* t_str, std::streamsize t_n) override {
		put_str(t_str, t_n);
		return t_n;
	}

	int overflow(int t_ch) override {
		char val = static_cast<char>(t_ch);
		put_str(&val, 1);
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
