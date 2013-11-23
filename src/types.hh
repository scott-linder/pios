#ifndef TYPES_HH
#define TYPES_HH

#include <cstdint>

typedef std::uint32_t size_t;
/** The word size of the BCM2835 */
typedef std::uint32_t word_t;
/** The type used to refer to a "mapped io" register.
 * We use a volatile variant to make sure _all_ operations, no matter how
 * uneeded they seem, are guaranteed not to be optimized away.
 */
typedef volatile word_t reg_t;

#endif /* TYPES_H */
