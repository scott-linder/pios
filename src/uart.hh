#ifndef UART_HH
#define UART_HH

#include "types.hh"
#include "mmio.hh"

namespace uart {
    auto enable() -> void;
    auto write(char data) -> void;
}

#endif /* UART_HH */

