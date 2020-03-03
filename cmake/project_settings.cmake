###################################################
#  Enable interprocedural optimization (aka LTO)  #
###################################################
option(ENABLE_IPO  "Enable Iterprocedural Optimization, aka Link Time Optimization (LTO)" OFF)

if(ENABLE_IPO)
    # skip the test, cause we are cross compiling, and we set CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY to skip compiler test
    # testing if lto is working for compiler or not is meaningless
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()
