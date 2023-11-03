
// if pico doesnt upload, press bootsel and tick "show all devices" then select the uf2 devices

#include "Pedals.h"

Pedals pedals;

#define USBD_VID 0x2341 //required for PedalFx Desktop App 
#define USBD_PID 0x8037

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(115200);
  analogReadResolution(12);  //this is needed, without this you would be just reading 10 bits

/* -------------THROTTLE------------- */  
  
  pedals.setThrottleOn(true);
  pedals.setThrottleBits("12bit", "16bit"); // 1st one is ADC Resolution, second one is HID.
  pedals.setThrottleAnalogPin(A0);
//  pedals.setThrottleADSChannel(1);
//  pedals.setThrottleLoadcell(6,5);

/* --------------BRAKE--------------- */

  pedals.setBrakeOn(true);
  pedals.setBrakeBits("12bit", "16bit");
  pedals.setBrakeAnalogPin(A2);
//  pedals.setBrakeADSChannel(1);
//  pedals.setBrakeLoadcell(7,5);

/* --------------CLUTCH--------------- */

  pedals.setClutchOn(true);
  pedals.setClutchBits("12bit", "16bit");
  pedals.setClutchAnalogPin(A1);
//  pedals.setClutchADSChannel(1);
//  pedals.setClutchLoadcell(8,5);

/* ------------------------------------- */

  pedals.setup();
}

// the loop routine runs over and over again forever:
void loop() {
  //  timing
//  unsigned long start = micros();

  pedals.loop();

//  unsigned long end = micros();
//  unsigned long delta = end - start;
//  Serial.println(delta);
}
