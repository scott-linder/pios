#ifndef OK_HH
#define OK_HH

#include "types.hh"

extern "C" {
    void okLightOn();
    void okLightOff();
    void delay(word_t ms);
}

#endif /* OK_HH */
