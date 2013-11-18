@
@ OK light suite
@
@ Almost verbatim from "Baking Pi" the tutorial at
@ http://www.cl.cam.ac.uk/projects/raspberrypi/tutorials/os/
@
@ Authors:
@   Scott Linder
@

.section .text
  .globl okLightOn
  okLightOn:
    ldr r0,=0x20200000  @ loadreg magic number for gpio controller into r0
    mov r1,#1           @ fast load 1 into r1
    lsl r1,#18          @ shift register 18 bits left
    str r1,[r0,#4]      @ OK is in second bank of 4 bytes
    mov r1,#1           @ another fast load
    lsl r1,#16          @ another shift, this time 16 bits because OK is on pin 16
    str r1,[r0,#40]     @ pull the pin low
    mov pc,lr           @ return

  .globl okLightOff
  okLightOff:
    ldr r0,=0x20200000  @ loadreg magic number for gpio controller into r0
    mov r1,#1           @ fast load 1 into r1
    lsl r1,#18          @ shift register 18 bits left
    str r1,[r0,#4]      @ OK is in second bank of 4 bytes
    mov r1,#1           @ another fast load
    lsl r1,#16          @ another shift, this time 16 bits because OK is on pin 16
    str r1,[r0,#28]     @ pull the pin high
    mov pc,lr           @ return

  .globl delay
  delay:
    @ Subtract one from parameter until it is less than 0
    wait1$:
    sub r0,#1
    cmp r0,#0
    bgt wait1$
    mov pc,lr

