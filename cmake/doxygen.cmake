function(enable_doxygen)
  option(BUILD_DOC  "Build documentation" OFF)
  if(BUILD_DOC)
    set(DOXYGEN_CALLER_GRAPH ON)
    set(DOXYGEN_CALL_GRAPH ON)
    set(DOXYGEN_EXTRACT_ALL ON)
    find_package(Doxygen)

    if (DOXYGEN_FOUND)
      set(DOXYGEN_WORKING_DIR
        "${CMAKE_SOURCE_DIR}/include/cpp_stm32/common"
        "${CMAKE_SOURCE_DIR}/include/cpp_stm32/detail"
        "${CMAKE_SOURCE_DIR}/include/cpp_stm32/driver"
        "${CMAKE_SOURCE_DIR}/include/cpp_stm32/hal"
        "${CMAKE_SOURCE_DIR}/include/cpp_stm32/utility"
        "${TARGET_PROCESSOR}"
        "${TARGET_DIR}"
      )

      set(DOXYGEN_GENERATE_HTML YES)
      set(DOXYGEN_GENERATE_MAN YES)
      set(DOXYGEN_PROJECT_NAME  "cpp_stm32")
      set(DOXYGEN_PROJECT_BRIEF "Pure c++17 implementation of stm32 driver")
      set(DOXYGEN_RECURSIVE YES)
      set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../documentation)

      doxygen_add_docs(doxygen
        ALL
        WORKING_DIRECTORY
          ${DOXYGEN_WORKING_DIR}
        COMMENT "Generate man pages"
      )
    endif(DOXYGEN_FOUND)
    # doxygen_add_docs(doxygen-docs ${PROJECT_SOURCE_DIR})

  endif()
endfunction()
