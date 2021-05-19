#ifndef _MAIN_H_
#define _MAIN_H_


// Logitech vendor ID
#define HID_VENDOR_ID_LOGITECH (__u32) 0x046d

// Logitech K810
#define HID_DEVICE_ID_K810 (__s16)0xb319
#define HID_DEVICE_ID_K480 (__s16)0xb330
#define HID_DEVICE_ID_K480_ALT (__s16)0xb33c

// Keyboards of type HID_DEVICE_ID_K480_ALT2
// are using the same key sequence as the
// Logitech K380 does.
#define HID_DEVICE_ID_K480_ALT2 (__s16) 0xb33d

const char k480_cmd_fn_keys_on[] = {0x10, 0xff, 0x08, 0x1c, 0x00, 0x00, 0x00};
const char k480_cmd_fn_keys_off[] = {0x10, 0xff, 0x08, 0x1c, 0x01, 0x00, 0x00};

// https://github.com/jergusg/k380-function-keys-conf/blob/master/k380_conf.c
const char k380_cmd_fn_keys_on[] = {0x10, 0xff, 0x0b, 0x1e, 0x00, 0x00, 0x00};
const char k380_cmd_fn_keys_off[] = {0x10, 0xff, 0x0b, 0x1e, 0x01, 0x00, 0x00};

const char k810_cmd_fn_keys_on[] = {0x10, 0xff, 0x06, 0x15, 0x00, 0x00, 0x00};
const char k810_cmd_fn_keys_off[] = {0x10, 0xff, 0x06, 0x15, 0x01, 0x00, 0x00};

#endif //_MAIN_H_