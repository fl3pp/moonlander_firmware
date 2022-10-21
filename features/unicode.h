// 'UNICODEMAP_ENABLE = yes' in 'rules.mk' required

#ifndef UNICODE_H
#define UNICODE_H

#include "shim/qmk.h"

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

uint32_t get_unicode_point(enum unicode_names name);

#endif
