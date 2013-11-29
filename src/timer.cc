/*
 * A wrapper around the timer logic.
 *
 * Authors:
 *  Scott Linder
 */

#include "types.hh"
#include "addr.hh"
#include "timer.hh"

/**
 * Blocking wait for a provided number of milliseconds.
 *
 */
void Timer::wait(unsigned int usecs) {
    auto delta = 0U;
    auto start = regs.read(kCounterLower);
    /* Spin until the time is up */
    while (delta < usecs) {
        auto current = regs.read(kCounterLower);
        delta = current - start;
    }
}

