#ifndef ADDR_HH
#define ADDR_HH

#include "types.hh"

/**
 * Literal representing a physical address.
 */
constexpr
reg_t *operator"" _phys(unsigned long long addr) {
    return reinterpret_cast<reg_t *>(addr);
}

/**
 * Literal representing a bus address.
 */
constexpr
reg_t *operator"" _bus(unsigned long long addr) {
    /*
     * The spec defines peripherals in terms of bus addresses when we want
     * physical addresses
     */
    return reinterpret_cast<reg_t *>(addr - 0x7E000000 + 0x20000000);
}

/**
 * Literal representing a byte count.
 */
constexpr
bytes_t operator"" _bytes(unsigned long long bytes) {
    return static_cast<bytes_t>(bytes);
}

/**
 * Literal representing a word count.
 */
constexpr
words_t operator"" _words(unsigned long long words) {
    return static_cast<words_t>(words);
}

/**
 * Convert a byte count into a word count.
 */
constexpr
auto words(bytes_t bytes) -> words_t {
    return bytes / sizeof(word_t);
}

/**
 * Convert a word count into a byte count.
 */
constexpr
auto bytes(words_t words) -> bytes_t {
    return words * sizeof(word_t);
}

#endif /* ADDR_HH */

