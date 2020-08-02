[![Build Status](https://travis-ci.com/osjacky430/cpp_stm32.svg?branch=master)](https://travis-ci.com/osjacky430/cpp_stm32)

# cpp_stm32
A project that implements stm32 driver using c++17, inspired by Jason Turner's talk "Rich Code for Tiny Computers: A Simple Commodore 64 Games in C++17.". This driver aims to have smaller code size, better performance,  easy to use hard to misuse, and higher level of abstraction, compare to that of drivers written in C99.

Currently, the driver is planned to test on these chips:
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
- python 3: the driver used python to generate project configuration file

### Building
Clone the repository, and then build it, make sure the toolchain path and python path is in ```PATH```:
```
export PATH="$PATH:/path/to/arm-none-eabi-gcc/bin:/path/to/python/binary"
git clone https://github.com/osjacky430/cpp_stm32
mkdir build && cd build
```
#### To build with your MCU:
Set ```TARGET_BOARD``` variable to the name of your MCU. CMake will check if the MCU is supported or not. If not supported, it will issue a fatal error.
Set ```CLOCK_FILE``` variable to let CMake generate project configuration header.
```sh
cmake -G "Unix Makefiles" -DTARGET_BOARD="stm32f446re" -DCLOCK_DIR="your_clock_config_file.yaml" ..
cmake --build .
```
***Caution: ```CLOCK_DIR``` needs to be relative to the file ```tool/clock_generator/clock_generator.py``` (todo: improve it!)***
#### Build Example
Set ```BUILD_EXAMPLE``` option to ```ON```, then build the desire example by specifying the name of the example source file
```sh
cmake -G "Unix Makefiles" -DTARGET_BOARD="stm32f446re" -DBUILD_EXAMPLE=ON -DCLOCK_DIR="your_clock_config_file.yaml" ..
cmake --build . --target example_name_1.elf example_name_2.bin
```
Notice that all the examples share the same clock configuration if there is no clock_config_file.yaml in the example file source directory (todo: implementation).

#### Link library to your application
Put your own include files in ```include``` directory and your application code in ```src``` directory. In ```src``` directory, create a CMakeLists.txt, and link target ```cpp_stm32``` to your application code:

```CMake
# in src directory

add_executable(main.elf main.cpp)
target_link_libraries(main.elf PRIVATE cpp_stm32 project_options)

# create binary file from elf file
add_custom_target(main.bin ALL ${CMAKE_OBJCOPY} -Obinary main.elf main.bin DEPENDS main.elf)  

target_include_directories(main.elf PRIVATE "path/to/your/include/files")

```
alternatively, ```cpp_stm32``` provides some handy cmake funcions, the CMakeLists above can be reduced to:

```CMake
include(build_binary)   # function add_binary

# todo: add support for user to link their source code
add_binary(TARGET_NAME main)

target_include_directories(main.elf PRIVATE "path/to/your/include/files")
```

#### Unit Testing
The unit testing framework for ```cpp_stm32``` is [Catch2](https://github.com/catchorg/Catch2) at the moment, still looking for even lighter unit testing framework (even with LTO, the test binary is still too large for some boards, mainly because of ```iostream```). Therefore, changes in unit testing framework will happen anytime in the future if more suitable one is found. 

The process for building unit test is identical to building the example, currently the library only do compile time unit testing.
```sh
cmake -G "Unix Makefiles" -DTARGET_BOARD="stm32f446re" -DENABLE_TESTING=ON -DCLOCK_DIR="your_clock_config_file.yaml" ..
cmake --build . --target test_name_1.elf test_name_2.bin ...
```

### Tunable Options
- ```ENABLE_HARD_FLOAT```: this option is enabled by default, which links the hard float flags to the library.
- ```ENABLE_IPO```: this option is disabled by default, turn this on to enable interprocedural optimization (LTO).
- ```ENABLE_RUNTIME_FREQ_CONFIG```: this option is disabled by default, turn this on if the clock frequency will change after clock initialization. If this value is set, the driver will calculate the derived clock frequency (i.e. SYS, AHB, APB1, APB2, PLL clock) every single time the clock frequency is needed.

### Current Work in progress
- [ ] Code coverage
- [ ] More unit test
- [x] Let user include their own yaml file that contains clk frequency information

### Future work
- [Support for Clang/LLVM??](https://interrupt.memfault.com/blog/arm-cortexm-with-llvm-clang)
- Support more boards

### System Clock Configuration File
Most of the projects have fix clock frequencies, and the clock frequencies are initialized at the beginning of ```main``` function. However, the initialization process is non-trivial, some manufactures provide code generator with GUI to config system clock, for cpp_stm32, this is done by providing system clock configuration file.
#### How to
The YAML file takes system variables as key, and its properties as value. Let say we want to set high speed external (HSE) oscillator to bypass clock source and the frequency be at 8 MHz:
```YAML
HSE:                  
  - BYPASS: True     
    FREQ: 8e6     # notice that there is no additional dash at this line

# those that are not specified will be assigned to its default value (see ClockFreq class in clock.hxx)
```
For all sysetem variables and its properties, refer to ```tool/clock_generator/chip/your_chip.yaml```. During the build process, CMake will execute the python script (```tool/clock_generator/clock_generator.py```) to generate ```project_config.hxx```, all you need to do is to call the system clock initialization function.

```C++
#include ...              // all other includes
#include "sys_init.hxx"   // to call the system clock initialization function

/* some global variables and free functions */

int main() {
  cpp_stm32::sys::Clock<>::init();  // initialize system clock according to the YAML file

  // the rest of the initialization

  while(true) {
    /* application code */
  }
}
```

If ```-DENABLE_RUNTIME_FREQ_CONFIG=ON```, the clock frequencies in the YAML file will be served as the initial clock frequencies of the system. (todo: support multiple clock configuration system?) To change system clock frequency during runtime, one needs to construct a ClockFreq class:

```C++
// ClockBuilder for clock frequency class generation is recommended

static constexpr auto CLOCK_FREQ_CLASS = []() {
  cpp_stm32::clock::ClockBuilder builder;
  return builder.setHSE(false, 8_MHz)
                ...                   // other setup
                .buildClock();        // create ClockFreq class
}();

// If you are doing the following initialization methods, make sure you know what you are doing
// Not recommended, for some initialization logics are separated
static constexpr auto CLOCK_FREQ_CLASS = []() {

  cpp_stm32::clock::ClockFreq ret_val;

  ret_val.bypassHSE = true;
  ret_val.bypassLSE = false;
  ret_val.freqHSE   = 8_M;
  ...                         // the rest of the assigments

  return ret_val;
}

// Highly not recommended, you can't do this while making it readable until c++2a
static constexpr auto CLOCK_FREQ_CLASS {
  true,     // bypass hse
  false,    // bypass lse
  8_M,      // freq hse
  32.768_k  // freq lse
  ...       // the rest of the value
}
```

And call the clock init function (todo: verification)
```C++
cpp_stm32::sys::Clock<CLOCK_FREQ_CLASS>::init();  // before c++2a, struct needs external linkage in order to be template parameter
                                                  // therefore it must be global variable or static local variable
                                                  // whereas c++2a compiler, you don't need to worry about it, hurray!
```

***Caution: Aggregate initialization is not recommended in this case! Prefer using builder over other initialization methods due to the complexity of the clock setup.***
