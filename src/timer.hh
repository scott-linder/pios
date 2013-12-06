#ifndef TIMER_HH
#define TIMER_HH

#include "types.hh"
#include "addr.hh"
#include "mmio.hh"

class Timer {
    public:
        /** A period of microseconds. */
        typedef unsigned int usecs_t;
        void wait(usecs_t delay);
    private:
        MMIO regs_{0x7E003000_bus};
        static const auto
            kControlAndStatusReg = words(0x00_bytes),
            kCounterLowerReg = words(0x04_bytes),
            kCounterHigherReg = words(0x08_bytes),
            /* Other compare registers are used by GPU. */
            kCompare1Reg = words(0x10_bytes),
            kCompare3Reg = words(0x18_bytes);
};

/**
 * Literal for convenient time literals.
 */
constexpr auto operator"" _usecs(unsigned long long usecs) -> Timer::usecs_t {
    return static_cast<Timer::usecs_t>(usecs);
}

#endif /* TIMER_H */

