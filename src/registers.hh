#ifndef REGISTERS_HH
#define REGISTERS_HH

#include "types.hh"
#include "addr.hh"

class Registers {
    public:
        Registers(reg_t *base);
        auto read(words_t offset) -> word_t;
        auto read(words_t offset, int bit) -> bool; 
        auto read(words_t offset, int bit_from, int bit_to) -> word_t; 
        auto write(words_t offset, word_t word) -> void; 
        auto write(words_t offset, int bit, bool bit_status) -> void; 
        auto write(words_t offset, int bit_from, int bit_to, word_t value)
            -> void; 
    private:
        reg_t *base;
};

#endif /* REGISTERS_HH */

