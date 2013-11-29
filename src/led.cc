/**
 * Quick wrapper for the OK light.
 */
#include "types.hh"
#include "addr.hh"
#include "ok.hh"
#include "led.hh"

Registers LED::regs{0x20200000_phys};

auto LED::on() -> void {
    regs.write(kSelect, 1 << 18);
    regs.write(kPullLow, 1 << 16);
}

auto LED::off() -> void {
    regs.write(kSelect, 1 << 18);
    regs.write(kPullHigh, 1 << 16);
}

