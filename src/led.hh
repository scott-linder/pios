#ifndef LED_HH
#define LED_HH

#include "types.hh"
#include "registers.hh"
#include "addr.hh"

class LED {
    public:
        auto on() -> void;
        auto off() -> void;
    private:
        static Registers regs;
        static const auto
            kSelect = words(4_bytes),
            kPullHigh = words(28_bytes),
            kPullLow = words(40_bytes);
};

#endif /* LED_HH */

