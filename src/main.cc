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
    constexpr auto delay = 40000_usecs;
    for (;;) {
        ok::on();
        timer::wait(delay);
        ok::off();
        timer::wait(delay);
    }
}
