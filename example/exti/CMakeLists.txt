is_periph_supported(is_supported BOARD ${TARGET_BOARD} PERIPH exti)

if(is_supported)
  add_binary(IS_EXAMPLE TARGET_NAME blue_button)
endif()
