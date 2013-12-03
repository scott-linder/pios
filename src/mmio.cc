#include "types.hh"
#include "mmio.hh"

MMIO::MMIO(reg_t *base)
    : base_(base)
{}

/**
 * Read a given register in full.
 */
auto MMIO::read(words_t offset) -> word_t {
    return static_cast<word_t>(base_[offset]);
}

/**
 * Read a given bit from a given register.
 * XXX: untested
 */
auto MMIO::read(words_t offset, int bit) -> bool {
    return static_cast<bool>(read(offset) & (1 << bit));
}

/**
 * Read a given portion of a given register.
 * XXX: stub
 */
auto MMIO::read(words_t offset, int bit_from, int bit_to) -> word_t {
    return offset + bit_from + bit_to;
}

/**
 * Write a given register in full.
 */
auto MMIO::write(words_t offset, word_t word) -> void {
    base_[offset] = word;
}

/**
 * Write a given bit of a given register.
 * XXX: stub
 */
auto MMIO::write(words_t offset, int bit, bool bit_status) -> void {
    offset += bit + bit_status;
}

/**
 * Write a given portion of a given register.
 * XXX: stub
 */
auto MMIO::write(words_t offset, int bit_from, int bit_to, word_t value)
        -> void {
    offset += bit_from + bit_to + value;
}

