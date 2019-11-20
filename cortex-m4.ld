
ENTRY(_Z13reset_handlerv)  /* needs to consider c++ name mangling */

MEMORY
{
  rom (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
  ram (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
  .IrqVector :            /* */
  {
    . = ALIGN(4);         /* for 32-bit machine, insert padding until 4-byte alignment */
    KEEP(*(.IrqVector))
    . = ALIGN(4);
  } >rom

  .text :
  {
    . = ALIGN(4);
    *(.text)
    *(.text*)
    . = ALIGN(4);
  } >rom

  .data :
  {
    *(.data)
  }

  .bss :
  {
    *(.bss)
  }
}

PROVIDE(STACK = ORIGIN(ram) + LENGTH(ram));
