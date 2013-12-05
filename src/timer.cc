/*
 * A wrapper around the timer logic.
 *
 * Authors:
 *  Scott Linder
 */

#include "timer.hh"

/**
 * Blocking wait for a provided number of microseconds.
 */
auto Timer::wait(usecs_t delay) -> void {
    auto delta = 0U;
    auto start = regs_.read(kCounterLower);
    /* Spin until the time is up */
    while (delta < delay) {
        auto current = regs_.read(kCounterLower);
        delta = current - start;
    }
}

