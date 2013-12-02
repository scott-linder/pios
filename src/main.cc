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
auto start_kernel() -> void {
    OK ok;
    Timer timer;
    const auto kDelay = 40000_usecs;
    while (1) {
        ok.on();
        timer.wait(kDelay);
        ok.off();
        timer.wait(kDelay);
    }
}
