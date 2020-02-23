# @todo match regex or something
# @note This is first time using regex, this will be change once I have better understanding about regex 
if(${BUILD_EXAMPLE} STREQUAL "ALL")
  add_subdirectory(gpio_output)
  add_subdirectory(exti)
  add_subdirectory(usart)
  add_subdirectory(i2c)
endif()

if (${BUILD_EXAMPLE} MATCHES "gpio_output:")
  string(REGEX REPLACE "gpio_output:" "" gpio_output_files ${BUILD_EXAMPLE})
  string(REGEX REPLACE "," " " gpio_output_files ${gpio_output_files})
  string(REGEX MATCHALL "[a-zA-Z0-9_]+|[a-zA-Z0-9_]+$" gpio_output_files ${gpio_output_files})
  add_subdirectory(gpio_output)
endif()

if (${BUILD_EXAMPLE} MATCHES "i2c:")
  string(REGEX REPLACE "i2c:" "" i2c_files ${BUILD_EXAMPLE})
  string(REGEX REPLACE "," " " i2c_files ${i2c_files})
  string(REGEX MATCHALL "[a-zA-Z0-9_]+|[a-zA-Z0-9_]+$" i2c_files ${i2c_files})
  add_subdirectory(i2c)
endif()

if (${BUILD_EXAMPLE} MATCHES "exti:")
  string(REGEX REPLACE "exti:" "" exti_files ${BUILD_EXAMPLE})
  string(REGEX REPLACE "," " " exti_files ${exti_files})
  string(REGEX MATCHALL "[a-zA-Z0-9_]+|[a-zA-Z0-9_]+$" exti_files ${exti_files})
  add_subdirectory(exti)
endif()
