
 // if pico doesnt upload, press bootsel and tick "show all devices" then select the uf2 devices

#include "Pedals.h"

Pedals pedals;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWriteFast(LED_BUILTIN, HIGH);
  Serial.begin(115200);
  analogReadResolution(12);  //this is needed, without this you would be just reading 10 bits
  pedals.setThrottleOn(true);
  pedals.setThrottleBits("12bit", "10bit");  //1st one is raw, other is hid
  pedals.setThrottleAnalogPin(A0);
//  pedals.setThrottleADSChannel(1);
//  pedals.setThrottleLoadcell(6,5);

  pedals.setBrakeOn(true);
  pedals.setBrakeBits("12bit", "10bit");
  pedals.setBrakeAnalogPin(A2);
//  pedals.setBrakeADSChannel(1);
//  pedals.setBrakeLoadcell(7,5);

  pedals.setClutchOn(true);
  pedals.setClutchBits("12bit", "10bit");
  pedals.setClutchAnalogPin(A1);
//  pedals.setClutchADSChannel(1);
//  pedals.setClutchLoadcell(8,5);

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
