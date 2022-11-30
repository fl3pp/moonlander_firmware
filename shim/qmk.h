#ifndef QMK_SHIM_H
#define QMK_SHIM_H

#include <stdint.h>
#include <stdbool.h>
#include <keycode.h>

typedef struct {
   uint16_t keycode;
   bool pressed;
} user_keyevent_t;

void qmk_register_unicode(uint32_t code_point);

#endif
