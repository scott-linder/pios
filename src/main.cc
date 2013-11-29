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
#include "timer.hh"

extern "C"
void start_kernel() {
    LED ok;
    Timer timer;
    while (1) {
        ok.on();
        timer.wait(0x3f0000);
        ok.off();
        timer.wait(0x3f0000);
    }
}
