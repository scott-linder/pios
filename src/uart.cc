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
        kAUX_EnableReg          = 0x7E215004_bus,
        /* Read and write data from UART data FIFOs. */
        kIOReg                  = 0x7E215040_bus,
        /* Enable interrupts and access MS 8 bits of baud rate. */
        kInterruptEnableReg     = 0x7E215044_bus,
        /* Shows interrupt status. */
        kInterruptIdentReg      = 0x7E215048_bus,
        /* Controls line data format. */
        kLineControlReg         = 0x7E21504C_bus,
        /* Controls 'modem' signals. */
        kModemControlReg        = 0x7E215050_bus,
        /* Shows data status. */
        kLineStatusReg          = 0x7E215054_bus,
        /* Shows 'modem' status. */
        kLineModemReg           = 0x7E215058_bus,
        /* Single byte storage. */
        kScratchReg             = 0x7E21505C_bus,
        /* Exposes some extra nice features (not found in 16550 UART). */
        kExtraControlReg        = 0x7E215060_bus,
        /* Provides info about internal status (not found in 16550 UART). */
        kExtraStatusReg         = 0x7E215064_bus,
        /* Allows direct access to 16-bit wide baudrate counter. */
        kBaudrateReg            = 0x7E215068_bus;
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
