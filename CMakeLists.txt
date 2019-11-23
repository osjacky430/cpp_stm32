cmake_minimum_required(VERSION 3.11.4 FATAL_ERROR)

set(LINKER_SCRIPT "-T ${CMAKE_SOURCE_DIR}/cortex-m4.ld")
set(CMAKE_TOOLCHAIN_FILE "ARMToolchain.cmake")

project(CppForStm32 LANGUAGES CXX)

set(GENERATE_MAP_FILE "-Xlinker -Map=linker_output.map")
set(PRINT_MEM_USAGE "-Xlinker --print-memory-usage")

set(CMAKE_CXX_FLAGS "-v ${CMAKE_CXX_FLAGS}" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostartfiles ${LINKER_SCRIPT} ${GENERATE_MAP_FILE} ${PRINT_MEM_USAGE}" CACHE STRING "" FORCE)

include_directories(${CMAKE_SOURCE_DIR})

add_library(cpp_stm32 ${CMAKE_SOURCE_DIR}/include/cortex_m_vector.cpp)
add_executable(main src/main.cpp)

target_link_libraries(main cpp_stm32)
