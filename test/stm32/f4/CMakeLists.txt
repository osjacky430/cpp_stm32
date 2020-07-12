
# TODO:
#   handle command line arguement by cmake, use target_compile_definitions to add defines to the target
#   then Catch run session with the given defines?

# if enable test compile time
add_library(test_entry OBJECT test_main.cpp)
target_include_directories(test_entry PUBLIC ${CMAKE_SOURCE_DIR}/test)
target_include_directories(test_entry PUBLIC ${CATCH_INCLUDE_DIR})
target_include_directories(test_entry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_entry PUBLIC cpp_stm32)
# target_compile_definitions(test_entry PUBLIC -DCATCH_CONFIG_RUNTIME_STATIC_REQUIRE)

add_subdirectory(compile_time)
