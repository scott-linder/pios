/*
 * A wrapper around the timer logic.
 *
 * Authors:
 *  Scott Linder
 */

#include "mmio.hh"
#include "timer.hh"

namespace {
    constexpr mmio::reg_t
        kControlAndStatusReg    = 0x7E003000_bus,
        kCounterLowReg          = 0x7E003004_bus,
        kCounterHighReg         = 0x7E003008_bus,
        kCompare1Reg            = 0x7E003010_bus,
        /* Compare2Reg reserved by GPU */
        kCompare3Reg            = 0x7E003018_bus;
        /* Compare3Reg reserved by GPU */
}

namespace timer {
    auto wait(usecs_t delay) -> void {
        auto delta = 0U;
        auto start = mmio::read(kCounterLowReg);
        /* Spin until the time is up */
        while (delta < delay) {
            auto current = mmio::read(kCounterLowReg);
            delta = current - start;
        }
    }
}
