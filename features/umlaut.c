#include "shim/qmk.h"
#include "features/unicode.h"
#include "features/umlaut.h"

bool UMLAUT_LAYER_ACTIVE;
bool UMLAUT_CAPS_ACTIVE;

#ifdef CONSOLE_ENABLE
void dbg_umlaut(void) {
   uprintf("   UMLAUT_LAYER_ACTIVE = %s\n", (UMLAUT_LAYER_ACTIVE ? "true" : "false"));
   uprintf("   UMLAUT_CAPS_ACTIVE = %s\n", (UMLAUT_CAPS_ACTIVE ? "true" : "false"));
}
#endif

// private
bool is_shift(uint16_t keycode) {
  return keycode == KC_LSFT || keycode == KC_RSFT;
}
bool print_umlaut_unicode(enum unicode_names code) {
   qmk_register_unicode(get_unicode_point(code));
   return false;
}

// public
void enter_umlaut_layer(void) {
  UMLAUT_LAYER_ACTIVE = true;
}

void leave_umlaut_layer(void) {
  UMLAUT_LAYER_ACTIVE = false;
  UMLAUT_CAPS_ACTIVE = false;
}

bool process_keyevent_umlaut(const user_keyevent_t *event) {
  static bool shift_active;
  static bool shift_tapped_down;

  if (event->pressed && is_shift(event->keycode)) {
    shift_active = true;
  }
  else if (!event->pressed && is_shift(event->keycode)) {
    shift_active = false;
  }

  if (is_shift(event->keycode)) {
    if (event->pressed) {
      shift_tapped_down = true;
    } else {
      if (shift_tapped_down) {
        shift_tapped_down = false;
        UMLAUT_CAPS_ACTIVE = !UMLAUT_CAPS_ACTIVE;
      }
    }
  } else {
    shift_tapped_down = false;
  }

  if (UMLAUT_LAYER_ACTIVE && event->pressed) {
    bool is_upper = shift_active || UMLAUT_CAPS_ACTIVE;
    switch (event->keycode) {
      case KC_A: return print_umlaut_unicode(is_upper ? U_AE : U_ae);
      case KC_O: return print_umlaut_unicode(is_upper ? U_OE : U_oe);
      case KC_U: return print_umlaut_unicode(is_upper ? U_UE : U_ue);
    }
  }
  return true;
}
