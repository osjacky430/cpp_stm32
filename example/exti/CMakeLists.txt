include(../build_binary.cmake)

if (${BUILD_EXAMPLE} STREQUAL "ALL")
  add_binary(blue_button)
else()
  foreach(src ${exti_files})
    add_binary(${src})
  endforeach()
endif()
