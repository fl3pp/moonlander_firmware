#include QMK_KEYBOARD_H
#include "features/unicode.h"

const uint32_t PROGMEM unicode_map[] = {
  [U_AE] = 0xC4,
  [U_ae] = 0xE4,
  [U_UE] = 0xDC,
  [U_ue] = 0xFC,
  [U_OE] = 0xD6,
  [U_oe] = 0xF6,
  [U_THUMBUP] = 0x1F44D,  // 👍
  [U_THUMBDWN] = 0x1F44E, // 👎
};

uint32_t get_unicode_point(enum unicode_names name) {
  return unicode_map[name];
}
