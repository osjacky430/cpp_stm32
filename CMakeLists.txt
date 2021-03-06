# ############################################################################################################
# cpp_stm32 library
# ############################################################################################################
cmake_minimum_required(VERSION 3.15.2 FATAL_ERROR)

set(CMAKE_TOOLCHAIN_FILE "ARMToolchain.cmake")

# ############################################################################################################
# command line options (not skippable)
# ############################################################################################################
set(TARGET_BOARD
    ""
    CACHE STRING "Target MCU")
set(CLOCK_FILE
    ""
    CACHE STRING "System Clock information")

project(
  cpp_stm32
  DESCRIPTION "Pure c++17 implementation of stm32 driver"
  HOMEPAGE_URL "https://github.com/osjacky430/cpp_stm32"
  LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(project_settings)
include(compiler_warning)
include(static_analyzer)
include(board_settings)
include(sanitizer)
include(doxygen)

import_board_setting(${TARGET_BOARD})

# ############################################################################################################
# some tunable options
# ############################################################################################################
option(ENABLE_RUNTIME_FREQ_CONFIG
       "Set to ON if the project doesn't change the clock frequency after initialization" OFF)
option(ENABLE_HARD_FLOAT "Use VFP extension" ON)

# ############################################################################################################
# Generate project configuration variables
# ############################################################################################################
gen_project_config_file(CLOCK_FILE ${CLOCK_FILE} BOARD ${TARGET_BOARD})

# In practice, it is usally easier and more robust to use the variables to set language requirements
# project-wide rather than use per target properties.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ############################################################################################################
# library compile options
# ############################################################################################################
set(NEWLIB_FLAGS --specs=nano.specs --specs=nosys.specs)

# ############################################################################################################
# add library, target properties
# ############################################################################################################
add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

add_library(project_options INTERFACE)
enable_sanitizers(project_options)

add_library(cpp_stm32 STATIC)
target_sources(cpp_stm32 PRIVATE ${TARGET_PROCESSOR}/source/vector_table.cxx)
target_include_directories(cpp_stm32 PUBLIC ${TARGET_DIR} ${CMAKE_SOURCE_DIR}/include/
                                            ${CMAKE_CURRENT_BINARY_DIR})
target_link_directories(cpp_stm32 INTERFACE ${PROCESSOR_DIR})
target_link_libraries(cpp_stm32 PRIVATE project_warnings project_options)

target_compile_options(
  cpp_stm32
  PUBLIC ${BOARD_FLAGS} ${NEWLIB_FLAGS} $<IF:$<BOOL:${ENABLE_HARD_FLOAT}>,${HARD_FLOAT},${SOFT_FLOAT}>
         $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions -fno-rtti>)

target_link_options(
  cpp_stm32
  INTERFACE
  ${BOARD_FLAGS}
  ${NEWLIB_FLAGS}
  $<IF:$<BOOL:${ENABLE_HARD_FLOAT}>,${HARD_FLOAT},${SOFT_FLOAT}>
  -nostartfiles
  "SHELL: ${LINKER_SCRIPT}"
  "SHELL: -Xlinker --gc-sections"
  "SHELL: -Xlinker --print-memory-usage")

# ############################################################################################################
# build example
# ############################################################################################################
option(ENABLE_TESTING "Build unit test" OFF)

if(ENABLE_TESTING)
  if(TEST_DIR)
    include(unit_test)
    add_unit_test_lib(project_options)
    add_subdirectory(${CMAKE_SOURCE_DIR}/test/)
  else()
    message(SEND_ERROR "No test for current chip ${TARGET_BOARD}")
  endif()
endif()

# ############################################################################################################
# link library to application
# ############################################################################################################
add_subdirectory(src)

# ############################################################################################################
# build documentation
# ############################################################################################################
enable_doxygen()

# ############################################################################################################
# build example
# ############################################################################################################
option(BUILD_EXAMPLE "Build example" OFF)

if(BUILD_EXAMPLE)
  add_subdirectory(${CMAKE_SOURCE_DIR}/example/)
endif()
