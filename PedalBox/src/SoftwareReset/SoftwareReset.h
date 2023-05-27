//https://github.com/OrhanYigitDurmaz/rp2040-libraries
#include "pico/stdlib.h"

namespace softwareReset
{
  inline void simple()
  {
    reset_usb_boot(0, 0);
    reset_cpu();
  }

  inline void standard()
  {
    while (true)
    {
      // Perform any cleanup tasks if needed
      
      // Reset the RP2040 by calling reset_usb_boot()
      reset_usb_boot(0, 0);
    }
  }

  void disable() { }
}

