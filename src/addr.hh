#ifndef ADDR_HH
#define ADDR_HH

/*
 * Literals and methods for dealing with addresses (particularly at
 * compile-time). 
 *
 * Authors:
 *  Scott Linder
 */

#include "types.hh"

/**
 * Literal representing a physical address.
 */
constexpr auto operator"" _phys(unsigned long long addr) -> reg_t * {
    return reinterpret_cast<reg_t *>(addr);
}

/**
 * Literal representing a bus address.
 */
constexpr auto operator"" _bus(unsigned long long addr) -> reg_t * {
    /*
     * The spec defines peripherals in terms of bus addresses when we want
     * physical addresses
     */
    return reinterpret_cast<reg_t *>(addr - 0x7E000000 + 0x20000000);
}

/**
 * Convert a byte count into a word count.
 */
constexpr auto words(size_t bytes) -> words_t {
    return static_cast<words_t>(bytes / sizeof(word_t));
}

/**
 * Convert a word count into a byte count.
 */
constexpr auto bytes(words_t words) -> size_t {
    return static_cast<size_t>(words) * sizeof(word_t);
}

/**
 * Literal representing a byte count.
 */
constexpr auto operator"" _bytes(unsigned long long bytes) -> size_t {
    return static_cast<size_t>(bytes);
}

/**
 * Literal representing a word count.
 */
constexpr auto operator"" _words(unsigned long long words) -> size_t {
    return bytes(words);
}

#endif /* ADDR_HH */

