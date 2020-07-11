
add_executable(test.elf test.cpp)
target_link_libraries(test.elf PRIVATE cpp_stm32)
target_include_directories(test.elf PRIVATE ${CATCH_INCLUDE_DIR})
target_include_directories(test.elf PRIVATE ${CMAKE_SOURCE_DIR}/test)

add_custom_target(test.bin ALL ${CMAKE_OBJCOPY} -Obinary test.elf test.bin DEPENDS test.elf)
