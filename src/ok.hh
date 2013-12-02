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
            kSelect1 = words(0x04_bytes),
            kSet0 = words(0x1c_bytes),
            kClear0 = words(0x28_bytes);
};

#endif /* OK_HH */

