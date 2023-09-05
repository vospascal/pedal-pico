## Under Development 

For now HID Resolution should be fixed at 10 bits. if you change it, it wont work. This is because of the limitations of the joystick library. In the future, I might fix it. 

Also be aware that this firmware uses the last sector of flash to emulate an EEPROM as the Pi Pico doesnt have one. But i highly advise to use an external one if you are going to use this in the long term.

Please be patient, and use the releases tab for the .uf2 file *AND* source code.

## PedalBox
- Client GUI pi pico side to found here https://github.com/vospascal/pedal-gui
- Client GUI in on the web to found here https://vospascal.github.io/pedal-gui-web works with the latest chrome version also opensource and zero install https://github.com/vospascal/svelte-webserial unlike the java version.

## Help
If you want to develop the software further, please create a pull request or create an issue.

## If you like it
Please leave a star.

## If you really like it
If you like it you can donate for further developent
https://www.paypal.com/donate?business=TBPE6XCB2XBMW&item_name=pedalbox&currency_code=EUR

## Uploading the firmware
You can either upload the .uf2 file to pico or compile it yourself

To upload the .uf2 file, simply hold BOOTSEL button while plugging the USB in. This will make a RPI-RP2 drive appear. Then drag the .uf2 file to the drive, and Pico is ready to be used as PedalBox.

Note: If there was another program in the pico, make sure to upload [flash_nuke.uf2](https://github.com/vospascal/pedal-pico/raw/main/flash_nuke.uf2) file. This will erase Pico's flash **entirely**. 
## Compiling
Open up the Arduino IDE and go to File->Preferences.

In the dialog that pops up, enter the following URL in the "Additional Boards Manager URLs" field:

`https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json`

Hit OK to close the dialog.

Go to Tools->Boards->Board Manager in the IDE

Type "pico" in the search box and select "Add":

Go to your Local Arduino installation directory.

From folder packages -> rp2040 -> hardware -> rp2040 -> [yourpackageversion] -> tools, open up makeboards.py for editing

Add this line under the Generic one:

```
# PedalBox
MakeBoard("pedalboxpico", "Vospascal", "PedalBox", "0x2e8a", "0x1069", 250, "PEDALBOX_PICO", 2, "boot2_w25q080_2_padded_checksum")
```

![Alt text](makeboards.jpeg?raw=true "Makeboards.py")

Go to the arduino-pico github page again, download the package folder and copy it to your installation directory.

Now run the makeboards.py .

Also go to the variants folder, and copy the `pedalboxpico` folder to there.

Restart Arduino IDE and youre good to go!

Now you should see "Vospascal PedalBox" as a board in the Arduino IDE.

# Pedal-Pico
It reads 0 - 3.3 volt scale. So as long as its within that range it'll work.

Measure the current, use "Raspberry Pi Pico" as to read the analogue value from the sensor

## Connectors Pedal Side
1 V5/vcc
5 GND
6 Analog/A1

2 V5/vcc
3 GND
4 Analog/A1


## One Loadcell Example

| hx711  | pi pico  | 
|---|---|
| gnd  |  gnd |
| sck  | pin 5  | 
| vcc  | vcc  |
| dt(data)  |  pin 7 |

## Multi Loadcell Example

| hx711  | pi pico  | 
|---|---|
| gnd  |  gnd |
| vcc  | vcc  |
| sck(Clock) - Thr  | pin 9  |
| sck(Clock) - Brk | pin 7  |
| sck(Clock) - Clt | pin 5  |
| dt(Data) - Thr |  pin 8 |
| dt(Data) - Brk |  pin 6 |
| dt(Data) - Clt |  pin 4 |

![Alt text](hx711_multiple.jpeg?raw=true "multi hx711")
