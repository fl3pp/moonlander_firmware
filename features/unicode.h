// 'UNICODEMAP_ENABLE = yes' in 'rules.mk' required
#ifndef UNICODE_H
#define UNICODE_H

#include QMK_KEYBOARD_H

enum unicode_names {
  U_AE,
  U_ae,
  U_UE,
  U_ue,
  U_OE,
  U_oe,
  U_THUMBUP,
  U_THUMBDWN,
};

extern const uint32_t PROGMEM unicode_map[];

#endif
