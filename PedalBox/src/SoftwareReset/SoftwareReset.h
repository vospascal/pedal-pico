#include "pico/stdlib.h"
#include "hardware/watchdog.h"

namespace softwareReset
{
    inline void simple()
    {
        asm volatile(" jmp 0");
    }

    inline void standard()
    {
        do
        {
            watchdog_enable(15 * 1000, true); // Enable the watchdog with a timeout of 15 milliseconds
            sleep_ms(UINT32_MAX);       // Enter an infinite sleep loop

        } while (0);
    }

    void disable()
    {
        watchdog_reboot(0, 0, 0); // Reset the watchdog timer
        watchdog_enable(0, false); // Disable the watchdog
    }
}