function(add_binary src_file_name)

add_executable(${src_file_name}.elf ${src_file_name}.cpp)
target_link_libraries(${src_file_name}.elf PRIVATE cpp_stm32)
add_custom_target(${src_file_name}.bin ALL ${CMAKE_OBJCOPY} -Obinary
                  ${src_file_name}.elf ${src_file_name}.bin DEPENDS ${src_file_name}.elf)
endfunction(add_binary)


function(build_ex_from_arg_in example_name)
  if (${BUILD_EXAMPLE} MATCHES "${example_name}:")
    string(REGEX REPLACE "${example_name}:" "" ${example_name}_files ${BUILD_EXAMPLE})

    if (NOT DEFINED ${${example_name}_files})
      add_subdirectory(${example_name})
    else()
      string(REGEX REPLACE "," " " ${example_name}_files ${${example_name}_files})
      string(REGEX MATCHALL "[a-zA-Z0-9_]+|[a-zA-Z0-9_]+$" ${example_name}_files ${${example_name}_files})
      add_subdirectory(${example_name})
    endif()
  else()
    # message()
  endif()
endfunction(build_ex_from_arg_in)
