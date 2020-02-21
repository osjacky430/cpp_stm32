# @todo match regex or something
if(${BUILD_EXAMPLE} STREQUAL "ALL")
  add_subdirectory(blink)
  add_subdirectory(exti)
  add_subdirectory(usart)
endif()
