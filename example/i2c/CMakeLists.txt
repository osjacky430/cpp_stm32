

add_executable(i2c_imu.elf i2c_imu.cpp)
target_link_libraries(i2c_imu.elf PRIVATE cpp_stm32)
add_custom_target(i2c_imu.bin ALL ${CMAKE_OBJCOPY} -Obinary i2c_imu.elf i2c_imu.bin DEPENDS i2c_imu.elf)
