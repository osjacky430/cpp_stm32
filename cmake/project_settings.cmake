if(NOT CMAKE_BUILD_TYPE AND NOT GENERATOR_IS_MULTI_CONFIG)
  # For single configuration generators, consider setting CMAKE_BUILD_TYPE to a better default value if it is
  # empty. message(STATUS "Setting build type to 'RelWithDebInfo' as none was specified.")
  set(allowableBuildTypes "Debug" "Release" "MinSizeRel" "RelWithDebInfo" "Profile")
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${allowableBuildTypes}")

  if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "" FORCE)
  elseif(NOT CMAKE_BUILD_TYPE IN_LIST allowableBuildTypes)
    message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
  endif()
endif()

# ############################################################################################################
# Enable interprocedural optimization (aka LTO)  #
# ############################################################################################################
option(ENABLE_IPO "Enable Iterprocedural Optimization, aka Link Time Optimization (LTO)" OFF)

if(ENABLE_IPO)
  # skip the test, cause we are cross compiling, and we set CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY to
  # skip compiler test testing if lto is working for compiler or not is meaningless
  set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()
