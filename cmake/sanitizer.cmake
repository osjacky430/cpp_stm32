function(enable_sanitizers project_name)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    option(ENABLE_COVERAGE "Enable coverage reporting for gcc" FALSE)

    if(ENABLE_COVERAGE)
      target_compile_options(project_options INTERFACE --coverage -O0 -g)
      target_link_libraries(project_options INTERFACE --coverage)
    endif()
  endif()

  # running sanitizers on bare metal are non-trivial
endfunction()
