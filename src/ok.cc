/*
 * Quick wrapper for the OK light.
 *
 * Authors:
 *  Scott Linder
 */

#include "types.hh"
#include "mmio.hh"
#include "ok.hh"

namespace {
    constexpr mmio::reg_t
        kSelect1Reg = 0x20200004_phys,
        kSet0Reg    = 0x2020001c_phys,
        kClear0Reg  = 0x20200028_phys;
    constexpr word_t
        kSelectOKMask = mmio::mask(18),
        kSelectOK     = kSelectOKMask,
        kSetOKMask    = mmio::mask(16),
        kSetOK        = kSetOKMask;
}

namespace ok {
    auto on() -> void {
        mmio::write(kSelect1Reg, kSelectOK, kSelectOKMask);
        mmio::write(kClear0Reg, kSetOK, kSetOKMask);
    }

    auto off() -> void {
        mmio::write(kSelect1Reg, kSelectOK, kSelectOKMask);
        mmio::write(kSet0Reg, kSetOK, kSetOKMask);
    }
}
