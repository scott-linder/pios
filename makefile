# # #
# OS makefile
# Authors:
# 	Scott Linder
# # #

# RPi toolchain from https://github.com/raspberrypi/tools
TC = arm-bcm2708hardfp-linux-gnueabi

AS_FLAGS =
CC_FLAGS = -std=c99 -ffreestanding -O2 -Wall -Wextra -Werror
CXX_FLAGS = -std=c++11 -ffreestanding -O2 -Wall -Wextra -Werror

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
	$(TC)-objcopy $(ELF) -O binary $(IMG)
	# For debugging purposes, also dump assembly to a file
	$(TC)-objdump -d $(ELF) > $(ASM)

# Create the ELF with our linker script and without shared libraries
$(ELF): $(OBJS) $(LDS)
	$(TC)-ld -T $(LDS) -static -o $(ELF) $(OBJS)

$(OUT)%.o: $(IN)%.cc
	$(TC)-g++ $(CXX_FLAGS) -c -I $(IN) -o $@ $<

$(OUT)%.o: $(IN)%.c
	$(TC)-gcc $(CC_FLAGS) -c -I $(IN) -o $@ $<

$(OUT)%.o: $(IN)%.s
	$(TC)-as $(AS_FLAGS) -I $(IN) -o $@ $<

# Make sure our out directory exists
$(OBJS): | $(OUT)

$(OUT):
	test -d $(OUT) || mkdir $(OUT)

clean:
	-rm -f $(OBJS)
	-rmdir $(OUT)
	-rm -f $(ELF)
	-rm -f $(IMG)
	-rm -f $(ASM)
