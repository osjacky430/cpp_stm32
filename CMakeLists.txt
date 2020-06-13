# ##############################################################################
# cpp_stm32 library
# ##############################################################################
cmake_minimum_required(VERSION 3.15.2...3.16.1 FATAL_ERROR)

set(TARGET_BOARD
    "stm32f446re"
    CACHE STRING "Target MCU")

set(CMAKE_TOOLCHAIN_FILE "ARMToolchain.cmake")

include(${CMAKE_SOURCE_DIR}/board/${TARGET_BOARD}.in)

project(
  cpp_stm32
  DESCRIPTION "Pure c++17 implementation of stm32 driver"
  HOMEPAGE_URL "https://github.com/osjacky430/cpp_stm32"
  LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(project_settings)
include(compiler_warning)
include(sanitizer)
include(static_analyzer)
include(doxygen)

# In practice, it is usally easier and more robust to use the variables to set
# language requirements project-wide rather than use per target properties.
set(CMAKE_CXX_STANDARD  17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ##############################################################################
# library compile options
# ##############################################################################
set(NEWLIB_FLAGS --specs=nano.specs --specs=nosys.specs)

# ##############################################################################
# add library, target properties
# ##############################################################################
add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

add_library(project_options INTERFACE)
enable_sanitizers(project_options)

add_library(cpp_stm32 STATIC) # TODO this need to change once user is allowed to
                              # use different target board via command line
target_sources(cpp_stm32 PRIVATE ${TARGET_PROCESSOR}/source/vector_table.cxx)
target_include_directories(cpp_stm32 PUBLIC ${TARGET_DIR}
                                            ${CMAKE_SOURCE_DIR}/include/)
target_link_directories(cpp_stm32 INTERFACE ${PROCESSOR_DIR})
target_link_libraries(cpp_stm32 PRIVATE project_warnings project_options)
target_compile_options(
  cpp_stm32
  PUBLIC ${BOARD_FLAGS}
         $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions -fno-rtti>
         ${NEWLIB_FLAGS})
target_link_options(
  cpp_stm32
  INTERFACE
  ${BOARD_FLAGS}
  ${NEWLIB_FLAGS}
  -nostartfiles
  "SHELL: ${LINKER_SCRIPT}"
  "SHELL: -Xlinker --gc-sections"
  "SHELL: -Xlinker --print-memory-usage")

# ##############################################################################
# link library to application
# ##############################################################################
add_subdirectory(src)

# ##############################################################################
# build documentation
# ##############################################################################
enable_doxygen()

# ##############################################################################
# build example
# ##############################################################################
set(BUILD_EXAMPLE
    ""
    CACHE STRING "Build example")

if(NOT ${BUILD_EXAMPLE} STREQUAL "")
  add_subdirectory(${CMAKE_SOURCE_DIR}/example/)
endif()
