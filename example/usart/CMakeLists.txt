include(../build_binary.cmake)


# if (${BUILD_EXAMPLE} STREQUAL "ALL")
#   add_binary(digitalout)
#   add_binary(ll_driver)
# else()
#   foreach(src ${gpio_output_files})
#     add_binary(${src})
#   endforeach()
# endif()

add_executable(usart_rx_dma_variable_length.elf with_dma/usart_rx_dma_variable_length.cpp)
target_link_libraries(usart_rx_dma_variable_length.elf PRIVATE cpp_stm32)
add_custom_target(usart_rx_dma_variable_length.bin ALL ${CMAKE_OBJCOPY} -Obinary usart_rx_dma_variable_length.elf
                  usart_rx_dma_variable_length.bin DEPENDS usart_rx_dma_variable_length.elf)

add_executable(usart_rx_dma.elf with_dma/usart_rx_dma.cpp)
target_link_libraries(usart_rx_dma.elf PRIVATE cpp_stm32)
add_custom_target(usart_rx_dma.bin ALL ${CMAKE_OBJCOPY} -Obinary usart_rx_dma.elf usart_rx_dma.bin DEPENDS usart_rx_dma.elf)
