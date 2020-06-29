is_periph_supported(is_supported BOARD ${TARGET_BOARD} PERIPH spi)

if(is_supported)
  check_config_file(BOARD ${TARGET_BOARD} FILE_DIR ${CMAKE_CURRENT_SOURCE_DIR} OVERWRITE)
  add_binary(IS_EXAMPLE TARGET_NAME spi_imu spi_driver_imu)
endif()
