

add_executable(blue_button.elf blue_button.cpp)
target_link_libraries(blue_button.elf PRIVATE cpp_stm32)
add_custom_target(blue_button.bin ALL ${CMAKE_OBJCOPY} -Obinary blue_button.elf blue_button.bin DEPENDS blue_button.elf)
