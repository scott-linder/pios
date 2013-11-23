#include "types.hh"
#include "registers.hh"

Registers::Registers(reg_t *base)
    : base(base)
{}

/** Read a given register in full.
 */
auto Registers::read(size_t word_offset) -> word_t {
    return (word_t) base[word_offset];
}

/** Read a given bit from a given register.
 * XXX: stub
 */
auto Registers::read(size_t word_offset, int bit) -> bool {
    return (bool) read(word_offset) & 1 << bit;
}

/** Read a given portion of a given register.
 * XXX: stub
 */
auto Registers::read(size_t word_offset, int bit_from, int bit_to) -> word_t {
    return word_offset + bit_from + bit_to;
}

/** Write a given register in full.
 */
auto Registers::write(size_t word_offset, word_t word) -> void {
    base[word_offset] = word;
}

/** Write a given bit of a given register.
 * XXX: stub
 */
auto write(size_t word_offset, int bit, bool bit_status) -> void {
    word_offset += bit + bit_status;
}

/** Write a given portion of a given register.
 * XXX: stub
 */
auto write(size_t word_offset, int bit_from, int bit_to, word_t value) -> void {
    word_offset += bit_from + bit_to + value;
}

