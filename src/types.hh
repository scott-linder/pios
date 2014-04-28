#ifndef TYPES_HH
#define TYPES_HH

/*
 * Typedefs common across the kernel.
 *
 * Authors:
 *  Scott Linder
 */

#include <cstdint>

/** Byte counts and sizes. */
typedef std::uint32_t size_t;
/** Word counts. */
typedef size_t words_t;
/** The word size of the BCM2835. */
typedef std::uint32_t word_t;

#endif /* TYPES_HH */

