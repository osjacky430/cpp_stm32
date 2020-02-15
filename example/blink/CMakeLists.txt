

add_executable(digitalout.elf digitalout.cpp)
target_link_libraries(digitalout.elf PRIVATE cpp_stm32)
add_custom_target(digitalout.bin ALL ${CMAKE_OBJCOPY} -Obinary digitalout.elf digitalout.bin DEPENDS digitalout.elf)

add_executable(ll_driver.elf ll_driver.cpp)
target_link_libraries(ll_driver.elf PRIVATE cpp_stm32)
add_custom_target(ll_driver.bin ALL ${CMAKE_OBJCOPY} -Obinary ll_driver.elf ll_driver.bin DEPENDS ll_driver.elf)
