
add_executable(main.elf main.cpp)
target_include_directories(main.elf PRIVATE ${CMAKE_SOURCE_DIR}/src/)
target_link_libraries(main.elf PRIVATE cpp_stm32 project_options)
add_custom_target(main.bin ALL ${CMAKE_OBJCOPY} -Obinary main.elf main.bin DEPENDS main.elf)
