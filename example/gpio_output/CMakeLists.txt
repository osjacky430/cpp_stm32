is_periph_supported(is_supported BOARD ${TARGET_BOARD} PERIPH gpio)

if(is_supported)
  add_binary(IS_EXAMPLE TARGET_NAME digitalout ll_driver)
endif()
