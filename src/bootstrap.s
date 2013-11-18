@
@ Simple bootloader
@ Authors:
@   Scott Linder
@

.section .init
  .globl _start
  _start:
    b start_kernel

