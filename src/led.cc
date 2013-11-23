#include "types.hh"
#include "ok.hh"
#include "led.hh"

auto LED::on() -> void { okLightOn(); }
auto LED::off() -> void { okLightOff(); }
auto LED::wait(word_t ms) -> void { delay(ms); }
