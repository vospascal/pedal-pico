#ifndef _USB_DESC_H_
#define _USB_DESC_H_

uint8_t const sixteen_bit_desc[] =
{
		    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
		    0x09, 0x04,                    // USAGE (Joystick)
		    0xa1, 0x01,                    // COLLECTION (Application)
		    0xa1, 0x00,                    //   COLLECTION (Physical)
		    0x85, 0x01,                    //     REPORT_ID (1)
        //HID_REPORT_ID(1)             //     DYNAMIC REPORT ID WITH TINYUSB
		    0x05, 0x01,                    //     USAGE_PAGE (Generic Desktop)
		    0x09, 0x33,                    //     USAGE (Rx)
		    0x09, 0x34,                    //     USAGE (Ry)
			  0x09, 0x35,                    //     USAGE (Rz)
		    0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
		    0x27, 0xff, 0xff, 0x00, 0x00,  //     LOGICAL_MAXIMUM (65535)
		    0x75, 0x10,                    //     REPORT_SIZE (16)
		    0x95, 0x03,                    //     REPORT_COUNT (3)
		    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
		    0xc0,                          //   END_COLLECTION
        0xc0                           // END_COLLECTION
      
};

struct  __attribute__((__packed__)) reportHID_t {
		uint8_t id = 1;
		int16_t RX = 0;
		int16_t RY = 0;
		int16_t RZ = 0;
};

#endif /* _USB_DESC_H_ */