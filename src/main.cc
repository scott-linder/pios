/* 
 * Entry point
 *
 * The kernel is "bootloaded" by an unconditional branch to start_kernel(). The
 * name is inconsequential, it only needs to be consistent.
 *
 * Authors:
 *  Scott Linder
 */

#include "led.hh"

extern "C"
void start_kernel() {
    LED ok;
    for (;;) {
        ok.on();
        ok.wait(0x3f0000);
        ok.off();
        ok.wait(0x3f0000);
    }
}
