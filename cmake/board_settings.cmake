function(check_board_supported target_board)
  set(SUPPORTED_BOARD_LIST stm32f446re stm32f303k8 stm32l432kc stm32f746ng)

  list(FIND SUPPORTED_BOARD_LIST ${target_board} out)
  if(${out} EQUAL -1)
    message(
      FATAL_ERROR
        "Target board ${target_board} is not supported yet by the driver!")
  endif()
endfunction()
