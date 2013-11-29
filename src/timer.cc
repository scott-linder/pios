/*
 * A wrapper around the timer logic.
 *
 * Authors:
 *  Scott Linder
 */

#include "types.hh"
#include "addr.hh"
#include "timer.hh"

Registers Timer::regs{0x7E003000_phys};

/**
 * Blocking wait for a provided number of milliseconds.
 *
 * XXX: currently only a testing implementation
 */
void Timer::wait(unsigned int ms) {
    auto start = regs.read(kCounterLower);
    /* Spin until the time is up */
    while ((regs.read(kCounterLower) - start) < ms);
}

