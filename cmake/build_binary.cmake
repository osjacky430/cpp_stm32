function(add_binary)
  set(option_value IS_EXAMPLE)
  set(single_value_arg)
  set(multi_value_arg TARGET_NAME)
  cmake_parse_arguments("TARGET" "${option_value}" "${single_value_arg}" "${multi_value_arg}" ${ARGN})

  foreach(target IN LISTS TARGET_TARGET_NAME)
    message(STATUS "Configuring build files for ${target}")
    add_executable(${target}.elf ${target}.cpp)
    target_include_directories(${target}.elf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(${target}.elf PRIVATE cpp_stm32 project_options)
    add_custom_target(${target}.bin ALL ${CMAKE_OBJCOPY} -Obinary
                      ${target}.elf ${target}.bin DEPENDS ${target}.elf)

    set_target_properties(${target}.bin
                          PROPERTIES
                          EXCLUDE_FROM_ALL ${TARGET_IS_EXAMPLE})
    set_target_properties(${target}.elf 
                          PROPERTIES 
                          EXCLUDE_FROM_ALL ${TARGET_IS_EXAMPLE})
  endforeach()

endfunction(add_binary)
