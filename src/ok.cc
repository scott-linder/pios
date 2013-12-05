/*
 * Quick wrapper for the OK light.
 *
 * Authors:
 *  Scott Linder
 */

#include "ok.hh"

auto OK::on() -> void {
    regs_.write(kSelect1, 18, true);
    regs_.write(kClear0, 16, true);
}

auto OK::off() -> void {
    regs_.write(kSelect1, 18, true);
    regs_.write(kSet0, 16, true);
}

