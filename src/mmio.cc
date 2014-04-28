#include "types.hh"
#include "mmio.hh"

namespace mmio {
    /**
     * Read a register in full.
     */
    auto read(reg_t reg) -> word_t {
        return (*reg);
    }

    /**
     * Read a portion of a register.
     */
    auto read(reg_t reg, word_t mask) -> word_t {
        return read(reg) & mask;
    }

    /**
     * Write a register in full.
     */
    auto write(reg_t reg, word_t word) -> void {
        (*reg) = word;
    }

    /**
     * Write a portion of a given register.
     */
    auto write(reg_t reg, word_t word, word_t mask) -> void {
        write(reg, (read(reg) & ~mask) | (word & mask));
    }
}
