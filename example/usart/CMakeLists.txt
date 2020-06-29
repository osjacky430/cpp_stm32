is_periph_supported(is_supported BOARD ${TARGET_BOARD} PERIPH usart dma)

list(GET is_supported 0 usart_supported)
list(GET is_supported 1 dma_supported)
 
if (usart_supported)  
  check_config_file(BOARD ${TARGET_BOARD} FILE_DIR ${CMAKE_CURRENT_SOURCE_DIR} OVERWRITE)
  add_binary(IS_EXAMPLE TARGET_NAME virtual_comm_port)
  if (dma_supported)
    add_binary(IS_EXAMPLE TARGET_NAME rx_dma rx_dma_var_len)
  endif()
endif()
