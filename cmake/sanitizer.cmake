function(enable_sanitizers project_name)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_BUILD_TYPE STREQUAL "Profile")
      set(CODE_COV_STUB_DIR
          ${CMAKE_SOURCE_DIR}/include/cpp_stm32/redirect/src/code_coverage/)

      target_sources(project_options
      INTERFACE ${CODE_COV_STUB_DIR}/sys_call.cxx)
      target_compile_options(project_options INTERFACE --coverage -O0 -g)
      target_link_options(project_options INTERFACE --coverage)
    endif()
  endif()

  # running sanitizers on bare metal are non-trivial
endfunction()
