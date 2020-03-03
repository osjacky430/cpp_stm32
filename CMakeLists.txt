###################################################
#                cpp_stm32 library                #
###################################################
cmake_minimum_required(VERSION 3.15.2...3.16.1 FATAL_ERROR)

set(TARGET_BOARD "stm32f446re" CACHE STRING "Target MCU")

include(${CMAKE_SOURCE_DIR}/cmake/project_settings.cmake)
include(${CMAKE_SOURCE_DIR}/board/${TARGET_BOARD}.in)

set(CMAKE_TOOLCHAIN_FILE "ARMToolchain.cmake")
project(cpp_stm32 DESCRIPTION "Pure c++17 implementation of stm32 driver"
                  HOMEPAGE_URL "https://github.com/osjacky430/cpp_stm32"
                  LANGUAGES CXX)

###################################################
#             library compile options             #
###################################################
set(OPTIMIZATION_FLAGS -ffunction-sections -fno-common -fdata-sections -Os)
set(CXX_FEATURE_FLAGS -fno-exceptions -fno-rtti)
set(UTILITY_FLAGS -g)  # verbose and debug
set(NEWLIB_FLAGS --specs=nano.specs --specs=nosys.specs)

###################################################
#          add library, target properties         #
###################################################
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

include(${CMAKE_SOURCE_DIR}/cmake/compiler_warning.cmake)
add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

add_library(cpp_stm32 STATIC) # TODO this need to change once user is allowed to use different target board via command line
target_sources(cpp_stm32
  PRIVATE
    ${TARGET_PROCESSOR}/source/vector_table.cxx
)
target_include_directories(cpp_stm32
  PUBLIC
    ${TARGET_DIR}
    ${CMAKE_SOURCE_DIR}/include/
)
target_link_directories(cpp_stm32 INTERFACE ${PROCESSOR_DIR})
target_link_libraries(cpp_stm32 PRIVATE project_warnings project_options)

target_compile_options(cpp_stm32
  PRIVATE
    ${UTILITY_FLAGS}
  PUBLIC
    ${BOARD_FLAGS}
    ${OPTIMIZATION_FLAGS}
    ${CXX_FEATURE_FLAGS}
    ${NEWLIB_FLAGS}
)

target_link_options(cpp_stm32
  INTERFACE
    ${BOARD_FLAGS}
    ${NEWLIB_FLAGS}
    -nostartfiles
    "SHELL: ${LINKER_SCRIPT}"
    "SHELL: -Xlinker --print-memory-usage"
)

###################################################
#            link library to application          #
###################################################
add_subdirectory(src)

###################################################
#               build documentation               #
###################################################
include(${CMAKE_SOURCE_DIR}/cmake/doxygen.cmake)
enable_doxygen()

###################################################
#                  build example                  #
###################################################
set(BUILD_EXAMPLE "" CACHE STRING "Build example")

if (NOT ${BUILD_EXAMPLE} STREQUAL "")
  add_subdirectory(${CMAKE_SOURCE_DIR}/example/)
endif()
