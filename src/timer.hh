#ifndef TIMER_HH
#define TIMER_HH

#include "types.hh"
#include "addr.hh"
#include "registers.hh"

class Timer {
    public:
        /** Blocking wait. */
        void wait(unsigned int ms);
    private:
        static Registers regs;
        static const auto
            kControlAndStatus = words(0x00_bytes),
            kCounterLower = words(0x04_bytes),
            kCounterHigher = words(0x08_bytes),
            kCompare0 = words(0x0c_bytes),
            kCompare1 = words(0x10_bytes),
            kCompare2 = words(0x14_bytes),
            kCompare3 = words(0x18_bytes);
};

#endif /* TIMER_H */

