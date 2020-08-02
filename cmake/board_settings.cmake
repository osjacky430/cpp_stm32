# * Import board settings checks target board validity and import related variables
#
# This macro checks if the target board is supported by cpp_stm32 and import all variables needed to
# successfully compile the library for target board.
#
# import_board_setting(<target_board>)
#
# If target_board is not supported, fatal error will occur. List of all supported boards are listed in
# board/supported_board.in
macro(import_board_setting target_board)
  include(${CMAKE_SOURCE_DIR}/board/supported_board.in)

  list(FIND LIST_OF_SUPPORTED_BOARD ${target_board} out)
  if(${out} EQUAL -1)
    message(FATAL_ERROR "Target board ${target_board} is not supported yet by the driver!")
  else()
    include(${CMAKE_SOURCE_DIR}/board/${target_board}.in)
  endif()
endmacro()

# * Check whether the peripheral is implemented/supported or not.
#
# This function checks whether the peripheral functionalities are supported by target board by checking
# register header and api header.
#
# is_periph_supported(<result> [BOARD <var>] [PERIPH <var ...>])
#
# If not supported/implemented, the result will be FALSE, otherwise TRUE. PERIPH is case insensitive, i.e.
# GPIO and gpio will have the same result. This is useful for cpp_stm32 to skip some example, or even test
# case (in the future) if the target board doesn't support such example/test case.
function(is_periph_supported result)
  set(option_arg)
  set(single_value_arg BOARD)
  set(multi_value_arg PERIPH)
  cmake_parse_arguments("TAR" "${option_arg}" "${single_value_arg}" "${multi_value_arg}" ${ARGN})

  import_board_setting(${TAR_BOARD})
  set(ret_val)
  foreach(target_periph IN LISTS TAR_PERIPH)
    string(TOLOWER ${target_periph} ${target_periph})

    set(REGISTER_HEADER ${TARGET_DIR}/register/${target_periph}.hxx)
    set(API_HEADER ${TARGET_DIR}/register/${target_periph}.hxx)

    if(NOT EXISTS ${REGISTER_HEADER} OR NOT EXISTS ${API_HEADER})
      list(APPEND ret_val FALSE)
    else()
      list(APPEND ret_val TRUE)
    endif()
  endforeach()
  set(${result}
      ${ret_val}
      PARENT_SCOPE)

endfunction()

# * Generate project configuration file
#
# This function generates the configuration file (project_config.hxx) cpp_stm32 needed to generate correct prescalers
# for the clock system, the configuration file is in the form of yaml
#
# gen_project_config_file([BOARD <var>] [CLOCK_FILE <var>])
#
# If the yaml file doesn't exist, it will issue a FATAL_ERROR.
function(gen_project_config_file)
  set(option_arg)
  set(single_value_arg BOARD CLOCK_FILE)
  set(multi_value_arg)
  cmake_parse_arguments("_" "${option_arg}" "${single_value_arg}" "${multi_value_arg}" ${ARGN})

  set(CLOCK_FILE_ABS_DIR ${CMAKE_SOURCE_DIR}/tool/clock_generator/${__CLOCK_FILE})
  if (NOT EXISTS ${CLOCK_FILE_ABS_DIR})
    message(FATAL_ERROR "clock file doesn't exist, aborted")
  endif()

  find_package(Python3 COMPONENTS Interpreter)
  if(${Python3_FOUND})
    message(STATUS "Generating project_config.hxx")
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${CLOCK_FILE_ABS_DIR})
    execute_process(
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/tool/clock_generator/clock_generator.py ${__CLOCK_FILE}
                ${__BOARD} ${CMAKE_CURRENT_BINARY_DIR}/project_config.hxx
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tool/clock_generator)
  else()
    message(FATAL_ERROR "can't find python3 to generate clock info, aborted")
  endif()

  file(READ ${CMAKE_SOURCE_DIR}/cmake/project_config.hxx.in CONFIG_H_IN)
  file(READ ${CMAKE_CURRENT_BINARY_DIR}/project_config.hxx ORIGINAL_CONTENT)
  string(CONFIGURE "${CONFIG_H_IN}" CONFIG_H_TMP)
  file(
    GENERATE
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/project_config.hxx
    CONTENT "${ORIGINAL_CONTENT}\n\n${CONFIG_H_TMP}")
endfunction()
