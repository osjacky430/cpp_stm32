# cpp_stm32
A project that implements stm32 driver using c++17, inspired by Jason Turner's talk "Rich Code for Tiny Computers: A Simple Commodore 64 Games in C++17.". This driver aims to have smaller code size, better performance,  easy to use hard to misuse, and higher level of abstraction, compare to that of driver written in C99.

Currently, the driver only support (not fully):
- stm32f446re
- stm32l432kc
- stm32f303k8 (in the future)
- stm32f746ng (in the future)

## Getting Started
These instructions will get you a copy of the project up and running on your target board.
### Prerequisites
cpp_stm32 requires the following things to be installed:
- C++17 compiler: the driver is tested with arm-none-eabi-gcc 9.2.1 and arm-none-eabi-gcc 8.3.1, you can download the compiler from [here](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads).
- [CMake](https://cmake.org/download/)
- [make](https://www.gnu.org/software/make/)
### Building
Clone the repository, and then build it, make sure the toolchain path is in ```PATH```
```
export PATH="$PATH:/path/to/arm-none-eabi-gcc/bin"
git clone https://github.com/osjacky430/cpp_stm32
mkdir build && cd build
cmake -G "Unix Makefiles" ..
cmake --build ./
```
To build with your MCU, you need to modify the following file: (todo: config via command line input)
- CMakeLists.txt: change ```TARGET_DIR```, ```LINKER_SCRIPT``` and ```TARGET_PROCESSOR```

```
set(TARGET_DIR "${CMAKE_SOURCE_DIR}/include/cpp_stm32/target/stm32/f4")
                      Change to your target device directory ^^^^^^^^

set(LINKER_SCRIPT "-T ${TARGET_DIR}/linker_script/stm32f446xe.ld")
              Change to your target linker script ^^^^^^^^^^^^^^

set(TARGET_PROCESSOR "${PROCESSOR_DIR}/cortex_m4")
      Change to your target processor ^^^^^^^^^^
```
**UPDATE: input file is added for command line configuration, still experimenting.** The basic usage will be:
```
export PATH="$PATH:/path/to/arm-none-eabi-gcc/bin"
mkdir build && cd build
cmake -G "Unix Makefiles" -DTARGET_BOARD="stm32f446re" ..
cmake --build ./
```
(Todo: add build example)
### System Clock Configuration File
Most of the projects have fix clock frequencies, and the clock frequencies are initialized at the beginning of ```main``` function. However, the initialization process is non-trivial, some manufactures provide code generator with GUI to config system clock, for cpp_stm32, this is done by providing system clock configuration file, ```sys_info.hpp```. For more detail description, take a look at the examples. (todo: elaboration)
### Tunable Options
Currently Under construction...

### Link library to your application
Currently Under construction...
