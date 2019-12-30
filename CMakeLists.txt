cmake_minimum_required(VERSION 3.11.4 FATAL_ERROR)

set(LINKER_SCRIPT "-T ${CMAKE_SOURCE_DIR}/cortex-m4.ld")
set(CMAKE_TOOLCHAIN_FILE "ARMToolchain.cmake")

project(CppForStm32 LANGUAGES CXX)

set(GENERATE_MAP_FILE "-Xlinker -Map=linker_output.map")
set(PRINT_MEM_USAGE "-Xlinker --print-memory-usage")
set(OPTIMIZE_FOR_DEBUG "-Og")
set(OPTIMIZE_FOR_SIZE "-Os")
set(OPTIMIZE_NONE "-O0")

set(CMAKE_CXX_FLAGS "-v ${CMAKE_CXX_FLAGS} ${OPTIMIZE_FOR_SIZE}" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostartfiles ${LINKER_SCRIPT} ${GENERATE_MAP_FILE} ${PRINT_MEM_USAGE}" CACHE STRING "" FORCE)

include_directories(${CMAKE_SOURCE_DIR}/include)  # cpp driver
include_directories(${CMAKE_SOURCE_DIR}/src)  # sys info header

add_library(cpp_stm32 ${CMAKE_SOURCE_DIR}/include/cpp_stm32/target/cortex_m_vector.cpp)
add_executable(main.elf src/main.cpp)
target_link_libraries(main.elf cpp_stm32)
add_custom_target(main.bin ALL ${CMAKE_OBJCOPY} -Obinary main.elf main.bin DEPENDS main.elf)
