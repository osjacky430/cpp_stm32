is_periph_supported(is_supported BOARD ${TARGET_BOARD} PERIPH spi i2c)

list(GET is_supported 0 spi_supported)
list(GET is_supported 1 i2c_supported)

if(spi_supported)
  add_binary(IS_EXAMPLE TARGET_NAME spi_imu)
  
  if (i2c_supported)
    add_binary(IS_EXAMPLE TARGET_NAME spi_driver_imu)
  endif()
endif()
