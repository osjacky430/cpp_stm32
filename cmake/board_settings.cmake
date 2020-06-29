# - Import board settings checks target board validity and import related variables
#
# This macro checks if the target board is supported by cpp_stm32 and import all
# variables needed to successfully compile the library for target board.
#   
#    import_board_setting(<target_board>)
#
# If target_board is not supported, fatal error will occur. List of all supported 
# boards are listed in board/supported_board.in
macro(import_board_setting target_board)
  include(${CMAKE_SOURCE_DIR}/board/supported_board.in)

  list(FIND LIST_OF_SUPPORTED_BOARD ${target_board} out)
  if(${out} EQUAL -1)
    message(FATAL_ERROR "Target board ${target_board} is not supported yet by the driver!")
  else()
    include(${CMAKE_SOURCE_DIR}/board/${target_board}.in)
  endif()
endmacro()

# - Check the existence of the configuration file
#
# This function checks the configuration file (sys_info.hpp) cpp_stm32 needed to  
# generate correct prescalers for the clock system
#
#     check_config_file([OVERWRITE]
#                       [BOARD <var>]
#                       [FILE_DIR <var>])
#
# If sys_info.hpp doesn't exist at FILE_DIR, it will create new one according to
# BOARD. If OVERWRITE is present, cmake will overwrite the existing sys_info.hpp
# to the default values.
function(check_config_file)
  set(option_value OVERWRITE)
  set(single_value_arg BOARD FILE_DIR)
  set(multi_value_arg)
  cmake_parse_arguments(CONFIG "${option_value}" "${single_value_arg}" "${multi_value_arg}" ${ARGN})

  if(NOT ${CONFIG_BOARD} STREQUAL "" AND NOT ${CONFIG_FILE_DIR} STREQUAL "") 
    import_board_setting(${CONFIG_BOARD})
    if(NOT EXISTS ${CONFIG_FILE_DIR}/sys_info.hpp)
       message(STATUS "Missing sys_info.hpp in ${CONFIG_FILE_DIR}, creating one with default configuration")
       file(WRITE ${CONFIG_FILE_DIR}/sys_info.hpp ${DEFAULT_SYS_CONFIG_FILE})
     elseif(${CONFIG_OVERWRITE})
       message(STATUS "Overwriting sys_info.hpp in ${CONFIG_FILE_DIR}")
       file(WRITE ${CONFIG_FILE_DIR}/sys_info.hpp ${DEFAULT_SYS_CONFIG_FILE})
    endif() 
  endif()
endfunction()

# - Check whether the peripheral is implemented/supported or not.
#
# This function checks whether the peripheral functionalities are supported by 
# target board by checking register header and api header.
#
#     is_periph_supported(<result>
#                         [BOARD <var>]
#                         [PERIPH <var ...>])
#
# If not supported/implemented, the result will be FALSE, otherwise TRUE. PERIPH
# is case insensitive, i.e. GPIO and gpio will have the same result. This is useful
# for cpp_stm32 to skip some example, or even test case (in the future) if the 
# target board doesn't support such example/test case.
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

    if (NOT EXISTS ${REGISTER_HEADER} OR NOT EXISTS ${API_HEADER})
      list(APPEND ret_val FALSE)
    else()
      list(APPEND ret_val TRUE)
    endif()
  endforeach()
  set(${result} ${ret_val} PARENT_SCOPE)

 endfunction()
