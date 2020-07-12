
ENTRY(_Z13reset_handlerv)  /* needs to consider c++ name mangling */

SECTIONS
{
  .IrqVector :            /* */
  {
    . = ALIGN(4);         /* for 32-bit machine, insert padding until 4-byte alignment */
    KEEP(*(.IrqVector))   /* without 'KEEP' the garbage collector discards this section */
    . = ALIGN(4);
  } >rom

  .text :
  {
    . = ALIGN(4);
    *(.text)
    *(.text*)

    /**
     *  @ref https://github.com/bjornfor/stm32-test/blob/master/stm32.ld
     *  @ref https://en.wikipedia.org/wiki/ARM_architecture#Cores
     *  @ref https://developer.arm.com/docs/dui0471/k/interworking-arm-and-thumb/about-interworking
     *
     *  glue_7 and glue_7t are for thumb/arm interworking, which is automatically
     *  assumed for ARM architecture later than ARMv5T, the architecture for
     *  cortex-m series is ARMv6 ~ v8-M, which is later than ARMv5T.
     */
    *(.glue_7)
    *(.glue_7t)

    /**
     *  @ref https://ppt.cc/fX4N4x
     *  @ref https://github.com/bjornfor/stm32-test/blob/master/stm32.ld#L71
     *  @ref document [EHABI](http://docplayer.net/51529403-Exception-handling-abi-for-the-arm-architecture.html)
     *
     *  .ARM.extab (exception table) is similar to .eh_frame (exception handling),
     *  both are used for exception handling, except that the former is only used
     *  on 32-bit machine. For architecture after ARMv8, .eh_frame is used instead
     *  of .ARM.extab.
     */
    *(.eh_frame)
    . = ALIGN(4);
  } >rom

  .ARM.extab :
  {
    *(.ARM.extab*)
  } >rom

  /**
   * @ref   https://github.com/gcc-mirror/gcc/blob/master/libgcc/unwind-arm-common.inc#L104
   * @ref   https://stackoverflow.com/questions/9752000/exidx-start-and-exidx-end-what-do-they-do
   *
   * __exidx_start and __exidx_end symbols are used internally by call-chain unwinding
   *  mechanism in GCC that takes control during exception handling phase.
   */
  .ARM.exidx :
  {
    /* __exidx_start = .; */
    *(.ARM.exidx*)
    /* __exidx_end = .; */
  } >rom

  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)
    *(.rodata*)
    . = ALIGN(4);
  } >rom

   /**
    * @ref http://static.grumpycoder.net/pixel/uC-sdk-doc/initfini_8c_source.html
    * @ref https://stackoverflow.com/questions/15265295/understanding-the-libc-init-array
    * @ref https://stackoverflow.com/questions/13734745/why-do-i-have-an-undefined-reference-to-init-in-libc-init-array
    *
    * Since I am using the gcc flag -nostartfile, I need to do the initialization on my own,
    * and since these naming conventions are according to libc, I'll stick to these names.
    */
  .preinit_array :
  {
    . = ALIGN(4);
    __preinit_array_start = .;
    KEEP(*(.preinit_array))
    __preinit_array_end = .;
  } >rom

  .init_array :
  {
    . = ALIGN(4);
    __init_array_start = .;
    KEEP(*(SORT(.init_array.*)))
    KEEP(*(.init_array))
    __init_array_end = .;
  } >rom

  .fini_array :
  {
    . = ALIGN(4);
    __fini_array_start = .;
    KEEP(*(.fini_array))
    KEEP(*(SORT(.fini_array.*)))
    __fini_array_end = .;
  } >rom

  .data :
  {
    sdata_ = .;
    . = ALIGN(4);
    *(.data)
    *(.data*)
    . = ALIGN(4);
    edata_ = .;
  } >ram AT >rom
  load_data_start_addr_ = LOADADDR(.data);
  /* load_data_end_addr__ = LOADADDR(.data)  */

  .bss :
  {
    sbss_ = .;
    *(.bss)
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    ebss_ = .;
  } >ram

  . = ALIGN(4);
  heap_start_ = .;
  end = heap_start_;
}

PROVIDE(STACK = ORIGIN(ram) + LENGTH(ram));
