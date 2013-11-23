/* 
 * Entry point
 *
 * The kernel is "bootloaded" by an unconditional branch to start_kernel(). The
 * name is inconsequential, it only needs to be consistent.
 *
 * Authors:
 *  Scott Linder
 */

#include "ok.hh"
#include "timer.hh"

extern "C"
void start_kernel() {
    Timer timer;
    for (;;) {
        okLightOff();
        timer.wait(1000);
        okLightOn();
        timer.wait(1000);
    }
}
