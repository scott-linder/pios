/* 
 * Kernel linker script 
 *
 * This is largely cherry-picked from the Linux kernel sources and the
 * "Baking Pi" tutorial series by the University of Cambridge
 *
 * XXX: There is probably a lot left to be desired in here, but as long as it
 * gets us a working kernel it is fine for now.
 *
 * Authors:
 *  Scott Linder
 */

OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS {

    . = 0;
    .init 0x0000 : {
        *(.init)
    }

    /* Space for ATAGS and stack here */

    .text 0x8000 : {
        *(.text)
        *(.text.*)
    }

    .rodata : {
        *(.rodata)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(COMMON)
        *(.bss)
    }

    /DISCARD/ : {
        *(*)
    }
}
