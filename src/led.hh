#ifndef LED_HH
#define LED_HH

#include "types.hh"
#include "addr.hh"

class LED {
    public:
        auto on() -> void;
        auto off() -> void;
        auto wait(word_t) -> void;
    private:
};

#endif /* LED_HH */

