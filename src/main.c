/* 
 * Entry point
 *
 * The kernel is "bootloaded" by an unconditional branch to start_kernel(). The name
 * is inconsequential, it only needs to be consistent.
 *
 * Authors:
 *  Scott Linder
 */

#include "ok.h"

void c_delay(unsigned long l) {
    while(l--);
}

void start_kernel() {
    for (;;) {
        okLightOff();
        delay(0x3F0000);
        okLightOn();
        delay(0x3F0000);
    }
}
