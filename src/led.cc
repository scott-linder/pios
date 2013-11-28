/**
 * Quick wrapper for the OK light.
 */
#include "types.hh"
#include "addr.hh"
#include "ok.hh"
#include "led.hh"

auto LED::on() -> void {
    okLightOn();
}

auto LED::off() -> void {
    okLightOff();
}

auto LED::wait(word_t ms) -> void {
    delay(ms);
}

