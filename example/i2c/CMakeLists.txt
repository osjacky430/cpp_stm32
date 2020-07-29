is_periph_supported(is_supported BOARD ${TARGET_BOARD} PERIPH i2c)

if(is_supported)
  add_binary(IS_EXAMPLE TARGET_NAME i2c_driver_imu i2c_imu)
endif()
