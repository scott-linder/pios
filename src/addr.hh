#ifndef ADDR_HH
#define ADDR_HH

constexpr
reg_t *operator"" _phys(unsigned long long addr) {
    return (reg_t *) addr;
}

constexpr
reg_t *operator"" _bus(unsigned long long addr) {
    /*
     * The spec defines peripherals in terms of bus addresses when we want
     * physical addresses
     */
    return (reg_t *) (addr - 0x7E000000 + 0x20000000);
}

/**
 * Convert a byte count into a word count.
 */
constexpr
auto words(size_t bytes) -> size_t {
    return bytes / sizeof(word_t);
}

/**
 * Convert a word count into a byte count.
 */
constexpr
auto bytes(size_t words) -> const size_t {
    return words * sizeof(word_t);
}

#endif /* ADDR_HH */

