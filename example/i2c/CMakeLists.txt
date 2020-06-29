is_periph_supported(is_supported BOARD ${TARGET_BOARD} PERIPH i2c)

if(is_supported)
  check_config_file(BOARD ${TARGET_BOARD} FILE_DIR ${CMAKE_CURRENT_SOURCE_DIR} OVERWRITE)
  add_binary(IS_EXAMPLE TARGET_NAME i2c_driver_imu i2c_imu)
endif()
