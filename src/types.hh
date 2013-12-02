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
/**
 * The type used to refer to a "mapped io" register.
 *
 * We use a volatile variant to make sure _all_ operations, no matter how
 * uneeded they seem, are guaranteed not to be optimized away. This is of
 * course not helpful for performance, so this type should not be used
 * _everywhere_ only where appropriate.
 */
typedef volatile word_t reg_t;

#endif /* TYPES_HH */

