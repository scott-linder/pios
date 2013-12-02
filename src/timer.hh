#ifndef TIMER_HH
#define TIMER_HH

#include "types.hh"
#include "addr.hh"
#include "registers.hh"

class Timer {
    public:
        /** A period of microseconds. */
        typedef unsigned int usecs_t;
        void wait(usecs_t delay);
    private:
        Registers regs{0x7E003000_bus};
        static const auto
            kControlAndStatus = words(0x00_bytes),
            kCounterLower = words(0x04_bytes),
            kCounterHigher = words(0x08_bytes),
            /* Other compare registers are used by GPU. */
            kCompare1 = words(0x10_bytes),
            kCompare3 = words(0x18_bytes);
};

/**
 * Literal for convenient time literals.
 */
constexpr auto operator"" _usecs(unsigned long long usecs) -> Timer::usecs_t {
    return static_cast<Timer::usecs_t>(usecs);
}

#endif /* TIMER_H */

