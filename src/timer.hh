#ifndef TIMER_HH
#define TIMER_HH

#include "types.hh"
#include "addr.hh"
#include "registers.hh"

class Timer {
    public:
        /* Blocking wait */
        void wait(unsigned int ms);
    private:
        /* Indexes from kBase of all System Timer registers */
        enum Register : size_t;
        /* Registers */
        Registers regs{0x7E003000_phys};
};

#endif /* TIMER_H */

