is_periph_supported(is_supported BOARD ${TARGET_BOARD} PERIPH spi i2c)

list(GET is_supported 0 spi_supported)
list(GET is_supported 1 i2c_supported)

if(spi_supported AND i2c_supported)
  check_config_file(BOARD ${TARGET_BOARD} FILE_DIR ${CMAKE_CURRENT_SOURCE_DIR} OVERWRITE)
  add_binary(IS_EXAMPLE TARGET_NAME spi_driver_imu)
elseif(spi_supported)
  check_config_file(BOARD ${TARGET_BOARD} FILE_DIR ${CMAKE_CURRENT_SOURCE_DIR} OVERWRITE)
  add_binary(IS_EXAMPLE TARGET_NAME spi_imu)
endif()
