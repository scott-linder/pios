#ifndef MMIO_HH
#define MMIO_HH

#include "types.hh"
#include "addr.hh"

class MMIO {
    public:
        explicit MMIO(reg_t *base);
        auto read(words_t reg) -> word_t;
        auto read(words_t reg, int bit) -> bool; 
        auto read(words_t reg, int bit, size_t len) -> word_t; 
        auto write(words_t reg, word_t word) -> void; 
        auto write(words_t reg, int bit, bool bit_status) -> void; 
        auto write(words_t reg, int bit, size_t len, word_t value) -> void; 
    private:
        reg_t *base_;
};

#endif /* MMIO_HH */

