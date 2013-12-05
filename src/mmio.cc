#include <limits>
#include "types.hh"
#include "mmio.hh"

MMIO::MMIO(reg_t *base)
    : base_(base)
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
    constexpr auto mask(size_t bit) -> word_t {
        return 1U << bit;
    }

    /**
     * Generate a bitmask with the given range of bits set.
     *
     * Ex:
     *  call        →   MSB  LSB
     *  mask(0, 0)  →   00000000
     *  mask(0, 1)  →   00000001
     *  mask(0, 3)  →   00000111
     *  mask(3, 4)  →   01111000
     *  mask(0, 8)  →   11111111
     *  …
     */
    constexpr auto mask(size_t bit, size_t len) -> word_t {
        return len >= static_cast<unsigned>(std::numeric_limits<word_t>::digits)
            ? std::numeric_limits<word_t>::max() << bit
            : ((1U << len) - 1U) << bit;
    }
};

/**
 * Read a given register in full.
 */
auto MMIO::read(words_t reg) -> word_t {
    return base_[reg];
}

/**
 * Read a given bit from a given register.
 * XXX: untested
 */
auto MMIO::read(words_t reg, int bit) -> bool {
    return read(reg) & (1 << bit);
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
    base_[reg] = word;
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
