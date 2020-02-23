function(add_binary src_file_name)

add_executable(${src_file_name}.elf ${src_file_name}.cpp)
target_link_libraries(${src_file_name}.elf PRIVATE cpp_stm32)
add_custom_target(${src_file_name}.bin ALL ${CMAKE_OBJCOPY} -Obinary
                  ${src_file_name}.elf ${src_file_name}.bin DEPENDS ${src_file_name}.elf)
endfunction()
