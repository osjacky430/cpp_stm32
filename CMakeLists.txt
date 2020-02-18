###################################################
#                cpp_stm32 library                #
###################################################
cmake_minimum_required(VERSION 3.15.2...3.16.1 FATAL_ERROR)

option(BUILD_DOC  "Build documentation" OFF)
set(TARGET_BOARD "stm32f446re" CACHE STRING "Target MCU")
set(BUILD_EXAMPLE "" CACHE STRING "Build example")
include(${CMAKE_SOURCE_DIR}/board/${TARGET_BOARD}.in)

set(CMAKE_TOOLCHAIN_FILE "ARMToolchain.cmake")
project(cpp_stm32 DESCRIPTION "Pure c++17 implementation of stm32 driver"
                  HOMEPAGE_URL "https://github.com/osjacky430/cpp_stm32"
                  LANGUAGES CXX)

###################################################
#             library compile options             #
###################################################
set(WARNING_FLAGS -Wall -Wextra -Wredundant-decls -Wundef -Wshadow)
set(OPTIMIZATION_FLAGS -ffunction-sections -fno-common -fdata-sections -Os)
set(CXX_FEATURE_FLAGS -fno-exceptions -fno-rtti)
set(UTILITY_FLAGS -g)  # verbose and debug
set(NEWLIB_FLAGS --specs=nano.specs --specs=nosys.specs)

###################################################
#          add library, target properties         #
###################################################
add_library(cpp_stm32 STATIC) # TODO this need to change once user is allowed to use different target board via command line
target_sources(cpp_stm32
  PRIVATE
    ${TARGET_PROCESSOR}/source/vector_table.cxx
)
target_include_directories(cpp_stm32
  INTERFACE
    ${CMAKE_SOURCE_DIR}/src
  PUBLIC
    ${TARGET_DIR}
    ${CMAKE_SOURCE_DIR}/include/
)
target_link_directories(cpp_stm32 INTERFACE ${PROCESSOR_DIR})
target_compile_features(cpp_stm32 PUBLIC cxx_std_17)
target_compile_options(cpp_stm32
  PRIVATE
    ${WARNING_FLAGS}
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
#        link library to application example      #
###################################################
# add_executable(main.elf ${CMAKE_SOURCE_DIR}/src/main.cpp)
# target_link_libraries(main.elf PRIVATE cpp_stm32)
# add_custom_target(main.bin ALL ${CMAKE_OBJCOPY} -Obinary main.elf main.bin DEPENDS main.elf)

###################################################
#               build documentation               #
###################################################
if (${BUILD_DOC})
  find_package(Doxygen)
  if (DOXYGEN_FOUND)
    add_subdirectory(${CMAKE_SOURCE_DIR}/documentation/)
  endif()
endif()

###################################################
#                  build example                  #
###################################################
if (NOT ${BUILD_EXAMPLE} STREQUAL "")
  add_subdirectory(${CMAKE_SOURCE_DIR}/example/)
endif()
