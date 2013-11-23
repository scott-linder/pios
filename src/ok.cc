#include "types.hh"
#include "addr.hh"
#include "ok.hh"

auto gpio_controller = 0x20200000_bus;

void okLightOn() {
    gpio_controller[1] = 1 << 18;
    gpio_controller[10] = 1 << 16;
}

void okLightOff() {
    gpio_controller[1] = 1 << 18;
    gpio_controller[7] = 1 << 16;
}

void delay(unsigned long l) {
    while(l--);
}
