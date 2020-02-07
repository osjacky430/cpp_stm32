cmake_minimum_required(VERSION 3.11.4 FATAL_ERROR)

set(PROCESSOR_DIR "${CMAKE_SOURCE_DIR}/include/cpp_stm32/processor")

set(TARGET_DIR "${CMAKE_SOURCE_DIR}/include/cpp_stm32/target/stm32/f4")
set(LINKER_SCRIPT "-T ${TARGET_DIR}/linker_script/stm32f446xe.ld")
set(TARGET_PROCESSOR "${PROCESSOR_DIR}/cortex_m4")

# set(LINKER_SCRIPT "-T ${TARGET_DIR}/linker_script/stm32l432kc.ld")
set(CMAKE_TOOLCHAIN_FILE "ARMToolchain.cmake")

project(CppForStm32 LANGUAGES CXX)

set(GENERATE_MAP_FILE "-Xlinker -Map=linker_output.map")
set(PRINT_MEM_USAGE "-Xlinker --print-memory-usage")
set(OPTIMIZE_FOR_DEBUG "-Og")
set(OPTIMIZE_FOR_SIZE "-Os")
set(OPTIMIZE_MAX "-O3")
set(OPTIMIZE_NONE "-O0")

set(CMAKE_FLAG_SET True CACHE BOOL "" FORCE)

if (${CMAKE_FLAG_SET})
set(CMAKE_CXX_FLAGS "-v ${CMAKE_CXX_FLAGS} ${OPTIMIZE_FOR_SIZE}" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostartfiles ${LINKER_SCRIPT} ${GENERATE_MAP_FILE} ${PRINT_MEM_USAGE}" CACHE STRING "" FORCE)
endif()

include_directories(${TARGET_DIR})  # cpp driver target
include_directories(${CMAKE_SOURCE_DIR}/include/)
include_directories(${CMAKE_SOURCE_DIR}/src)  # sys info header
link_directories(${PROCESSOR_DIR}) # to link linker script

add_library(cpp_stm32 ${TARGET_PROCESSOR}/source/vector_table.cxx)
add_executable(main.elf src/main.cpp)
target_link_libraries(main.elf cpp_stm32)
add_custom_target(main.bin ALL ${CMAKE_OBJCOPY} -Obinary main.elf main.bin DEPENDS main.elf)
