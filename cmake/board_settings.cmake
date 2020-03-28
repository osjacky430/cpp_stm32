function(enable_hard_float project_name)
  option(ENABLE_HARD_FLOAT "Use VFP extension" TRUE)
  target_compile_options(${project_name} PUBLIC $<IF:ENABLE_HARD_FLOAT,${HARD_FLOAT},${SOFT_FLOAT}>)
endfunction()
