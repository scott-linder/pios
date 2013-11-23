#ifndef REGISTERS_HH
#define REGISTERS_HH

#include "types.hh"
#include "addr.hh"

class Registers {
    public:
        Registers(reg_t *base);
        auto read(size_t word_offset) -> word_t;
        auto read(size_t word_offset, int bit) -> bool; 
        auto read(size_t word_offset, int bit_from, int bit_to) -> word_t; 
        auto write(size_t word_offset, word_t word) -> void; 
        auto write(size_t word_offset, int bit, bool bit_status) -> void; 
        auto write(size_t word_offset, int bit_from, int bit_to, word_t value) -> void; 
    private:
        reg_t *base;
};

#endif /* REGISTERS_HH */

