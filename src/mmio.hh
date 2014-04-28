#ifndef MMIO_HH
#define MMIO_HH

#include <limits>
#include "types.hh"

namespace mmio {
    /**
     * The type used to refer to a "mapped io" register.
     *
     * We use a volatile variant to make sure _all_ operations, no matter how
     * uneeded they seem, are guaranteed not to be optimized away. This is of
     * course not helpful for performance, so this type should not be used
     * _everywhere_ only where appropriate.
     */
    typedef volatile word_t *reg_t;

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
    static constexpr auto mask(size_t bit) -> word_t {
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
    static constexpr auto mask(size_t bit, size_t len) -> word_t {
        return len >= static_cast<unsigned>(std::numeric_limits<word_t>::digits)
            ? std::numeric_limits<word_t>::max() << bit
            : ((1U << len) - 1U) << bit;
    }
    auto read(reg_t reg) -> word_t;
    auto read(reg_t reg, word_t mask) -> word_t;
    auto write(reg_t reg, word_t word) -> void;
    auto write(reg_t reg, word_t word, word_t mask) -> void;
}

/**
 * Literal representing a physical address.
 */
constexpr auto operator"" _phys(unsigned long long addr) -> mmio::reg_t {
    return reinterpret_cast<mmio::reg_t>(addr);
}

/**
 * Literal representing a bus address.
 *
 * The spec defines peripherals in terms of bus addresses when we want
 * physical addresses.
 */
constexpr auto operator"" _bus(unsigned long long addr) -> mmio::reg_t {
    return reinterpret_cast<mmio::reg_t>(addr - 0x7E000000 + 0x20000000);
}

#endif /* MMIO_HH */

