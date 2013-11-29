#ifndef TIMER_HH
#define TIMER_HH

#include "types.hh"
#include "addr.hh"
#include "registers.hh"

class Timer {
    public:
        /** Blocking wait. */
        void wait(unsigned int usecs);
    private:
        Registers regs{0x7E003000_bus};
        static const auto
            kControlAndStatus = words(0x00_bytes),
            kCounterLower = words(0x04_bytes),
            kCounterHigher = words(0x08_bytes),
            kCompare0 = words(0x0c_bytes), /* DO NOT USE: GPU only */
            kCompare1 = words(0x10_bytes),
            kCompare2 = words(0x14_bytes), /* DO NOT USE: GPU only */
            kCompare3 = words(0x18_bytes);
};

#endif /* TIMER_H */

