# * Add unit test download the latest version of Catch2 into the project
#
# This macro checks downloads Catch2 and returns the include directory.
#
# add_unit_test_lib()
#
# Since Catch2 is downloaded from github, git and internet connection are required.
macro(add_unit_test_lib)

  include(ExternalProject)

  find_package(Git REQUIRED)
  ExternalProject_Add(
    catch
    PREFIX ${CMAKE_BINARY_DIR}/catch
    GIT_REPOSITORY https://github.com/philsquared/Catch.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON)

  # Expose required variable (CATCH_INCLUDE_DIR) to parent scope
  ExternalProject_Get_Property(catch source_dir)
  set(CATCH_INCLUDE_DIR
      ${source_dir}/single_include
      CACHE INTERNAL "Path to include folder for Catch")
  # set(CATCH_MODULE_DIR ${source_dir}/contrib CACHE INTERNAL "Path to include CMake Catch2 integration")
endmacro()

# * Build unit test binary file
#
# This function build test file to binary, and including things that is required to compile the unit test
# code.
#
# build_test_binary(<TARGET_NAME ...>)
#
# TODO: add extra arg in the future, incorporate with ctest
function(build_test_binary)
  set(option_value)
  set(single_value_arg TEST_MAIN)
  set(multi_value_arg TARGET_NAME)
  cmake_parse_arguments("TARGET" "${option_value}" "${single_value_arg}" "${multi_value_arg}" ${ARGN})

  if(NOT TARGET_TEST_MAIN)
    message(SEND_ERROR "main not provided")
  endif()

  foreach(target IN LISTS TARGET_TARGET_NAME)
    message(STATUS "Configuring build files for test file ${target}")
    add_executable(${target}.elf ${target}.cpp)

    # target_include_directories(${target}.elf PRIVATE ${CMAKE_SOURCE_DIR})
    # target_include_directories(${target}.elf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}) # sys_info
    # target_include_directories(${target}.elf PRIVATE ${CATCH_INCLUDE_DIR}) # catch

    target_link_libraries(${target}.elf PRIVATE ${TARGET_TEST_MAIN} cpp_stm32 project_options)

    add_custom_target(
      ${target}.bin ALL
      ${CMAKE_OBJCOPY} -Obinary ${target}.elf ${target}.bin
      DEPENDS ${target}.elf)

    set_target_properties(${target}.bin PROPERTIES EXCLUDE_FROM_ALL TRUE)
    set_target_properties(${target}.elf PROPERTIES EXCLUDE_FROM_ALL TRUE)
  endforeach()
endfunction()
