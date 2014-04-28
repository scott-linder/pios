#ifndef TIMER_HH
#define TIMER_HH

namespace timer {
    /** A period of microseconds. */
    typedef unsigned int usecs_t;
    /** Wait a period of microseconds. */
    auto wait(usecs_t delay) -> void;
}

/**
 * Literal for convenient time literals.
 */
constexpr auto operator"" _usecs(unsigned long long usecs) -> timer::usecs_t {
    return static_cast<timer::usecs_t>(usecs);
}

#endif /* TIMER_H */
