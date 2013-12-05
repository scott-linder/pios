#include "types.hh"
#include "mmio.hh"

MMIO::MMIO(reg_t *base)
    : base(base)
{}

namespace {
    /**
     * Generate a bitmask with only the given bit set.
     *
     * Ex:
     *  call    →   MSB  LSB
     *  mask(0) →   00000001
     *  mask(1) →   00000010
     *  mask(7) →   10000000
     *  …
     */
    constexpr auto mask(int bit) -> word_t {
        return static_cast<word_t>(1 << bit);
    }

    /**
     * Generate a bitmask with the given range of bits set.
     */
    constexpr auto mask(int bit, size_t len) -> word_t {
        /* XXX: Doesn't actually work; implement with the behavior that
         * the mask has `len` bits set starting at offset `bit`
         * Ex:
         *  call        →   MSB  LSB
         *  mask(0, 0)  →   00000000
         *  mask(0, 1)  →   00000001
         *  mask(0, 3)  →   00000111
         *  mask(3, 4)  →   01111000
         *  mask(0, 8)  →   11111111
         *  …
         */
        return static_cast<word_t>(((1 << bit) - 1) << len);
    }
};

/**
 * Read a given register in full.
 */
auto MMIO::read(words_t reg) -> word_t {
    return static_cast<word_t>(base[reg]);
}

/**
 * Read a given bit from a given register.
 * XXX: untested
 */
auto MMIO::read(words_t reg, int bit) -> bool {
    return static_cast<bool>(read(reg) & (1 << bit));
}

/**
 * Read a given portion of a given register.
 * XXX: untested
 */
auto MMIO::read(words_t reg, int bit, size_t len) -> word_t {
    return read(reg) | mask(bit, len);
}

/**
 * Write a given register in full.
 */
auto MMIO::write(words_t reg, word_t word) -> void {
    base[reg] = word;
}

/**
 * Write a given bit of a given register.
 * XXX: untested
 */
auto MMIO::write(words_t reg, int bit, bool set) -> void {
    auto word = read(reg);
    write(reg, set ? word | mask(bit) : word & (~mask(bit)));
}

/**
 * Write a given portion of a given register.
 * XXX: untested
 */
auto MMIO::write(words_t reg, int bit, size_t len, word_t word) -> void {
    write(reg, word | mask(bit, len));
}

