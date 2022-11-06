#include QMK_KEYBOARD_H
#include "shim/qmk.h"

void qmk_register_unicode(uint32_t code_point) {
  register_unicode(code_point);
}
