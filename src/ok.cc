/*
 * Quick wrapper for the OK light.
 *
 * Authors:
 *  Scott Linder
 */

#include "ok.hh"

auto OK::on() -> void {
    regs_.write(kSelect1, 1 << 18);
    regs_.write(kClear0, 1 << 16);
}

auto OK::off() -> void {
    regs_.write(kSelect1, 1 << 18);
    regs_.write(kSet0, 1 << 16);
}

