function(enable_hard_float project_name)
  option(ENABLE_HARD_FLOAT "Use VFP extension" TRUE)
  target_compile_options(${project_name} PUBLIC $<IF:ENABLE_HARD_FLOAT,${HARD_FLOAT},${SOFT_FLOAT}>)
endfunction()

function(check_board_supported target_board)
  set(SUPPORTED_BOARD_LIST
      "stm32f446re"
      "stm32f303k8"
      "stm32l432kc"
      "stm32f746ng"
  )

  list(FIND SUPPORTED_BOARD_LIST ${target_board} out)
endfunction()
