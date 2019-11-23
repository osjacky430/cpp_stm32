/**
 * @Date:   2019-11-19T14:00:12+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: main.cpp
 * @Last modified time: 2019-11-23T22:23:27+08:00
 */

#include "include/gpio.hpp"
#include "include/nvic.hpp"

// Gpio ll;

// [[gnu::constructor(101)]] void init_test() {}

int main() {
	Interrupt<IrqNum::WindowWatchDog>::enable();

	while (true) {
	}

	return 0;
}
