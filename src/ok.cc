/*
 * Quick wrapper for the OK light.
 *
 * Authors:
 *  Scott Linder
 */

#include "ok.hh"

auto OK::on() -> void {
    regs.write(kSelect1, 1 << 18);
    regs.write(kClear0, 1 << 16);
}

auto OK::off() -> void {
    regs.write(kSelect1, 1 << 18);
    regs.write(kSet0, 1 << 16);
}

