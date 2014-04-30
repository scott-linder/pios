/*
 * Mini UART driver
 *
 * Authors:
 *  Scott Linder
 */

#include "types.hh"
#include "mmio.hh"
#include "uart.hh"

namespace {
    constexpr mmio::reg_t
        /* Enable and disable auxiliary devices. */
        kAUX_EnableReg  = 0x7E215004_bus,
        /* Read and write data from UART data FIFOs. */
        kIOReg          = 0x7E215040_bus;
    constexpr word_t
        kAUX_EnableUARTMask = mmio::mask(0),
        kAUX_EnableUART = kAUX_EnableUARTMask,
        kIODataMask = mmio::mask(0, 8),
        kIOData = kIODataMask;
}

namespace uart {
    auto enable() -> void {
        mmio::write(kAUX_EnableReg, kAUX_EnableUART, kAUX_EnableUARTMask);
    }

    auto write(char data) -> void {
        mmio::write(kIOReg, static_cast<word_t>(data), kIODataMask);
    }
}
