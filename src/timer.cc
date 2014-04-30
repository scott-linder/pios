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
        /* Compare0Reg reserved by GPU */
        kCompare1Reg            = 0x7E003010_bus,
        /* Compare2Reg reserved by GPU */
        kCompare3Reg            = 0x7E003018_bus;
    constexpr word_t
        kCompare1Mask      = mmio::mask(1),
        kCompare1          = kCompare1Mask,
        kCompare1Reset     = ~kCompare1Mask;
}

namespace timer {
    auto wait(usecs_t delay) -> void {
        /* get current time */
        auto start = mmio::read(kCounterLowReg);
        /* compute time to stop */
        auto stop = start + delay;
     
        /* reset the timer control bit */
        mmio::write(kControlAndStatusReg, kCompare1Reset, kCompare1Mask);
        /* set the timer compare register */
        mmio::write(kCompare1Reg, stop);
     
        /* Spin until the interrupt fires */
        while (!mmio::read(kControlAndStatusReg, kCompare1Mask)) {
            ;
        }
    }
}
