[![Build Status](https://travis-ci.com/osjacky430/cpp_stm32.svg?branch=master)](https://travis-ci.com/osjacky430/cpp_stm32)

# cpp_stm32
A project that implements stm32 driver using c++17, inspired by Jason Turner's talk "Rich Code for Tiny Computers: A Simple Commodore 64 Games in C++17.". This driver aims to have smaller code size, better performance,  easy to use hard to misuse, and higher level of abstraction, compare to that of driver written in C99.

Currently, the driver only tested (not fully):
- stm32f446re
- stm32l432kc
- stm32f303k8 (in the future)
- stm32f746ng (in the future)

## Getting Started
These instructions will get you a copy of the project up and running on your target board.
### Prerequisites
cpp_stm32 requires the following things to be installed:
- C++17 compiler: the driver is tested with arm-none-eabi-gcc 9.2.1 and arm-none-eabi-gcc 8.3.1, you can download the compiler from [here](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads).
- [CMake](https://cmake.org/download/) (minimum required: 3.15.2)
- [make](https://www.gnu.org/software/make/) or [ninja](https://ninja-build.org/)

### Building
Clone the repository, and then build it, make sure the toolchain path is in ```PATH```
```
export PATH="$PATH:/path/to/arm-none-eabi-gcc/bin"
git clone https://github.com/osjacky430/cpp_stm32
mkdir build && cd build
cmake -G "Unix Makefiles" ..
cmake --build ./
```
#### To build with your MCU:
Set ```TARGET_BOARD``` variable to the name of your MCU. CMake will check if the MCU is supported or not. If not supported, it will issue a fatal error.
```
export PATH="$PATH:/path/to/arm-none-eabi-gcc/bin"
mkdir build && cd build
cmake -G "Unix Makefiles" -DTARGET_BOARD="stm32f446re" ..
cmake --build .
```
#### Build Example
Set ```BUILD_EXAMPLE``` option to ```ON```, then build the desire example by specifying the name of the example source file
```
cmake -G "Unix Makefiles" -DTARGET_BOARD="stm32f446re" -DBUILD_EXAMPLE=ON ..
cmale --build . --target example_name_1.elf example_name_2.elf
```
### Tunable Options
- ```ENABLE_HARD_FLOAT```: this option is enabled by default, which links the hard float flags to the library.

### Link library to your application
Currently Under construction...

### Current Work in progress
- Code coverage
- Unit test

### System Clock Configuration File
Most of the projects have fix clock frequencies, and the clock frequencies are initialized at the beginning of ```main``` function. However, the initialization process is non-trivial, some manufactures provide code generator with GUI to config system clock, for cpp_stm32, this is done by providing system clock configuration file, ```sys_info.hpp```. For more detail description, take a look at the examples. (todo: elaboration)
