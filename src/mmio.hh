#ifndef MMIO_HH
#define MMIO_HH

#include "types.hh"
#include "addr.hh"

class MMIO {
    public:
        MMIO(reg_t *base);
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

#endif /* MMIO_HH */

