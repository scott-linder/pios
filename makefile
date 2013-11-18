# # #
# OS makefile
# Authors:
# 	Scott Linder
# # #

# RPi toolchain from https://github.com/raspberrypi/tools
CC = arm-bcm2708hardfp-linux-gnueabi

# To keep things tidy
IN = src/
OUT = obj/

# Kernel binaries
ELF = $(OUT)kernel.elf
IMG = kernel.img
# Dissassembled kernel "source"
ASM = kernel.asm

# Linker Script
LDS = kernel.ld

# All objects needed to link full kernel
OBJS = bootstrap.o ok.o main.o
OBJS := $(addprefix $(OUT), $(OBJS))

# Bare `make` will produce the kernel image
all: $(IMG)

# Image is a binary copy of the ELF object (the ELF container makes no sense in
# this context)
$(IMG): $(ELF)
	$(CC)-objcopy $(ELF) -O binary $(IMG)
	# For debugging purposes, also dump assembly to a file
	$(CC)-objdump -d $(ELF) > $(ASM)

# Create the ELF with our linker script and without shared libraries
$(ELF): $(OBJS) $(LDS)
	$(CC)-ld -T $(LDS) -static -o $(ELF) $(OBJS)

# So far we have only written in C and ASM
$(OUT)%.o: $(IN)%.c
	$(CC)-gcc -c -nostdlib -I $(IN) -o $@ $<

$(OUT)%.o: $(IN)%.s
	$(CC)-as -I $(IN) -o $@ $<

clean:
	-rm -f $(OBJS)
	-rm -f $(ELF)
	-rm -f $(IMG)
	-rm -f $(ASM)
