cmake_minimum_required(VERSION 3.11.4 FATAL_ERROR)

set(LINKER_SCRIPT "-T ${CMAKE_SOURCE_DIR}/cortex-m4.ld")
set(CMAKE_TOOLCHAIN_FILE "ARMToolchain.cmake")

project(CppForStm32 LANGUAGES CXX)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LINKER_SCRIPT} -nostartfiles" CACHE STRING "" FORCE)

include_directories(${CMAKE_SOURCE_DIR})

add_library(cpp_stm32 ${CMAKE_SOURCE_DIR}/include/cortex_m_vector.cpp)
add_executable(main src/main.cpp)

target_link_libraries(main cpp_stm32)
