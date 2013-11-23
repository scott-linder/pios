/*
 * A wrapper around the timer logic.
 *
 * Authors:
 *  Scott Linder
 */

#include "types.hh"
#include "addr.hh"
#include "timer.hh"

enum Timer::Register : size_t {
    ControlAndStatus = words(0x00),
    CounterLower = words(0x04),
    CounterHigher = words(0x08),
    Compare0 = words(0x0c),
    Compare1 = words(0x10),
    Compare2 = words(0x14),
    Compare3 = words(0x18)
};

/**
 * Blocking wait for a provided number of milliseconds.
 *
 * XXX: currently only a testing implementation
 */
void Timer::wait(unsigned int ms) {
    auto start = regs.read(CounterLower);
    /* Spin until the time is up */
    while ((regs.read(CounterLower) - start) < ms);
}

