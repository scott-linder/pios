#ifndef OK_HH
#define OK_HH

#include "types.hh"
#include "registers.hh"
#include "addr.hh"

class OK {
    public:
        auto on() -> void;
        auto off() -> void;
    private:
        Registers regs{0x20200000_phys};
        static const auto
            kSelect = words(4_bytes),
            kPullHigh = words(28_bytes),
            kPullLow = words(40_bytes);
};

#endif /* OK_HH */

