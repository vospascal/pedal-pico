## Under Development 
Please be patient, and use the releases tab for the .uf2 file *AND* source code.

## PedalBox
- Client GUI pi pico side to found here https://github.com/vospascal/pedal-gui
- Client GUI in on the web to found here https://vospascal.github.io/pedal-gui-web works with latest chrome version also opensource and zero install https://github.com/vospascal/svelte-webserial unlike the java version.

## Help
If you want to develop the software further please create a pull request or create an issue

## If you like it
Please leave a star

## If you really like it
If you like it you can donate further developent
https://www.paypal.com/donate?business=TBPE6XCB2XBMW&item_name=pedalbox&currency_code=EUR

## Uploading the firmware
You can either upload the .uf2 file to pico or compile it yourself

To upload the .uf2 file, simply hold BOOTSEL button while plugging the USB in. This will make a RPI-RP2 drive appear. Then drag the .uf2 file to the drive, and Pico is ready to be used as a pedal device.

Note: If there was another program in the pico, make sure to upload [flash_nuke.uf2](https://github.com/vospascal/pedal-pico/raw/main/flash_nuke.uf2) file. This will erase Pico's flash **entirely**. 
## Compiling
Open up the Arduino IDE and go to File->Preferences.

In the dialog that pops up, enter the following URL in the "Additional Boards Manager URLs" field:

`https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json`

Hit OK to close the dialog.

Go to Tools->Boards->Board Manager in the IDE

Type "pico" in the search box and select "Add":

Add this to your arduino boards.txt

> For Arduino IDE 1.x

Location example [yourinstallationdirectory]\arduino-1.8.13\hardware\arduino\avr\boards.txt

> For Arduino IDE 2.x

Location example [yourinstallationdirectory]\Arduino15\packages\rp2040\hardware\rp2040\ [yourlibraryversion] \boards.txt

```
##############################################################

micro.name=PedalBox

micro.vid.0=0x2341
micro.pid.0=0x0037
micro.vid.1=0x2341
micro.pid.1=0x8037
micro.vid.2=0x2A03
micro.pid.2=0x0037
micro.vid.3=0x2A03
micro.pid.3=0x8037
micro.vid.4=0x2341
micro.pid.4=0x0237
micro.vid.5=0x2341
micro.pid.5=0x8237

micro.upload.tool=avrdude
micro.upload.protocol=avr109
micro.upload.maximum_size=28672
micro.upload.maximum_data_size=2560
micro.upload.speed=57600
micro.upload.disable_flushing=true
micro.upload.use_1200bps_touch=true
micro.upload.wait_for_upload_port=true

micro.bootloader.tool=avrdude
micro.bootloader.low_fuses=0xff
micro.bootloader.high_fuses=0xd8
micro.bootloader.extended_fuses=0xcb
micro.bootloader.file=caterina/Caterina-Micro.hex
micro.bootloader.unlock_bits=0x3F
micro.bootloader.lock_bits=0x2F

micro.build.mcu=atmega32u4
micro.build.f_cpu=16000000L
micro.build.vid=0x2341
micro.build.pid=0x8037
micro.build.usb_product="PedalBox"
micro.build.board=AVR_MICRO
micro.build.core=arduino
micro.build.variant=micro
micro.build.extra_flags={build.usb_flags}

##############################################################
```


# pedal-pico
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
