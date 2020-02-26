# @todo match regex or something
# @note This is first time sing regex, this will be change once I have better understanding about regex
include(build_binary.cmake)

if(${BUILD_EXAMPLE} STREQUAL "ALL")
  add_subdirectory(gpio_output)
  add_subdirectory(exti)
  add_subdirectory(usart)
  add_subdirectory(i2c)
endif()

build_ex_from_arg_in("gpio_output")
build_ex_from_arg_in("i2c")
build_ex_from_arg_in("exti")
build_ex_from_arg_in("usart")
