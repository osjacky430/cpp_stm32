###################################################
#                cpp_stm32 library                #
###################################################
cmake_minimum_required(VERSION 3.11.4...3.16.1 FATAL_ERROR)

set(CMAKE_TOOLCHAIN_FILE "ARMToolchain.cmake")
project(cpp_stm32 DESCRIPTION "Pure c++17 implementation of stm32 driver"
                  HOMEPAGE_URL "https://github.com/osjacky430/cpp_stm32"
                  LANGUAGES CXX)

###################################################
#                 target MCU path                 #
###################################################
set(PROCESSOR_DIR "${CMAKE_SOURCE_DIR}/include/cpp_stm32/processor")

set(TARGET_DIR "${CMAKE_SOURCE_DIR}/include/cpp_stm32/target/stm32/f4")
set(LINKER_SCRIPT "-T ${TARGET_DIR}/linker_script/stm32f446xe.ld")
set(TARGET_PROCESSOR "${PROCESSOR_DIR}/cortex_m4")

###################################################
#             library compile options             #
###################################################
# MCU specific compiler flags, see https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html
set(STM32F4_FLAGS -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -mcpu=cortex-m4)
set(WARNING_FLAGS -Wall -Wextra -Wredundant-decls -Wundef -Wshadow)
set(OPTIMIZATION_FLAGS -ffunction-sections -fno-common -fdata-sections -Os)
set(CXX_FEATURE_FLAGS -fno-exceptions -fno-rtti)
set(UTILITY_FLAGS -v -g)  # verbose and debug
set(NEWLIB_FLAGS --specs=nano.specs --specs=nosys.specs)

###################################################
#          add library, target properties         #
###################################################
add_library(cpp_stm32 STATIC)
target_sources(cpp_stm32
  PRIVATE
    ${TARGET_PROCESSOR}/source/vector_table.cxx
)
target_include_directories(cpp_stm32
  INTERFACE
    ${CMAKE_SOURCE_DIR}/../src
  PUBLIC
    ${TARGET_DIR}
    ${CMAKE_SOURCE_DIR}/../include/
)
target_link_directories(cpp_stm32 INTERFACE ${PROCESSOR_DIR})
target_compile_features(cpp_stm32 PUBLIC cxx_std_17)
target_compile_options(cpp_stm32
  PUBLIC
    ${WARNING_FLAGS}
    ${STM32F4_FLAGS}
    ${OPTIMIZATION_FLAGS}
    ${CXX_FEATURE_FLAGS}
    ${UTILITY_FLAGS}
    ${NEWLIB_FLAGS}
)
target_link_options(cpp_stm32
  INTERFACE
    ${NEWLIB_FLAGS}
    -nostartfiles
    "SHELL: ${LINKER_SCRIPT}"
    "SHELL: -Xlinker --print-memory-usage"
    "SHELL: -Xlinker -Map=linker_output.map"
)
