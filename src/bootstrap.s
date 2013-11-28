@
@ Simple bootloader
@ Authors:
@   Scott Linder
@

.section .init
  .globl _start
  _start:
    ldr sp, =stack_top
    b start_kernel

.section .bootstack
    stack_bottom:
    .skip 16384 @ 16 KiB
    stack_top:
