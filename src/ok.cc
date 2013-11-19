#include "types.hh"
#include "ok.hh"

word_t *gpio_controller = (word_t *) 0x20200000;

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
