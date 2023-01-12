#include QMK_KEYBOARD_H
#include "version.h"

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

const uint32_t PROGMEM unicode_map[] = {
  [U_AE] = 0xC4,          // Ä
  [U_ae] = 0xE4,          // ä
  [U_UE] = 0xDC,          // Ü
  [U_ue] = 0xFC,          // ü
  [U_OE] = 0xD6,          // Ö
  [U_oe] = 0xF6,          // ö
  [U_THUMBUP] = 0x1F44D,  // 👍
  [U_THUMBDWN] = 0x1F44E, // 👎
};

/*
                                     keymaps layout help

        ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐          ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐
ROW 0   │  │ │  │ │  │ │  │ │  │ │  │ │  │          │  │ │  │ │  │ │  │ │  │ │  │ │  │
        └──┘ └──┘ └──┘ └──┘ └──┘ └──┘ └──┘          └──┘ └──┘ └──┘ └──┘ └──┘ └──┘ └──┘
        ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐          ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐
ROW 1   │  │ │  │ │  │ │  │ │  │ │  │ │  │          │  │ │  │ │  │ │  │ │  │ │  │ │  │
        └──┘ └──┘ └──┘ └──┘ └──┘ └──┘ └──┘          └──┘ └──┘ └──┘ └──┘ └──┘ └──┘ └──┘
        ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐          ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐
ROW 2   │  │ │  │ │  │ │  │ │__│ │  │ │  │          │  │ │  │ │__│ │  │ │  │ │  │ │  │
        └──┘ └──┘ └──┘ └──┘ └──┘ └──┘ └──┘          └──┘ └──┘ └──┘ └──┘ └──┘ └──┘ └──┘
        ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐                    ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐
ROW 3   │  │ │  │ │  │ │  │ │  │ │  │                    │  │ │  │ │  │ │  │ │  │ │  │
        └──┘ └──┘ └──┘ └──┘ └──┘ └──┘                    └──┘ └──┘ └──┘ └──┘ └──┘ └──┘
        ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐      ┌─────┐    ┌─────┐      ┌──┐ ┌──┐ ┌──┐ ┌──┐ ┌──┐
ROW 4   │  │ │  │ │  │ │  │ │  │      │  o  │    │  o  │      │  │ │  │ │  │ │  │ │  │
        └──┘ └──┘ └──┘ └──┘ └──┘      └─────┘    └─────┘      └──┘ └──┘ └──┘ └──┘ └──┘
                               ┌──┐ ┌──┐ ┌──┐    ┌──┐ ┌──┐ ┌──┐
ROW 5                          │  │ │  │ │  │    │  │ │  │ │  │
                               │  │ │  │ │  │    │  │ │  │ │  │
                               └──┘ └──┘ └──┘    └──┘ └──┘ └──┘
*/


enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  KC_AE,
  KC_UE,
  KC_OE,
};

enum layers {
   L_BASE,
   L_DEV,
   L_ARR,
   L_F,
   L_UMLAUT,
};

#define n____ KC_NO
#define _____ KC_TRANSPARENT
// #define ______ KC_TRANSPARENT (QMK default)
#define MTP_LGUI 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_moonlander(
    MO(L_F),      KC_GRAVE,     KC_1,       KC_2,         KC_3,         KC_4,         KC_5,                        KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         n____,        MO(L_F),
    KC_TAB,       KC_Q,         KC_W,       KC_E,         KC_R,         KC_T,         LCTL(KC_C),                  LCTL(KC_V),   KC_Z,         KC_U,         KC_I,         KC_O,         KC_P,         KC_BSLASH,
    KC_ESCAPE,    LGUI_T(KC_A), LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F), LT(L_ARR,KC_G),MO(L_UMLAUT),               MO(L_UMLAUT), LT(L_ARR,KC_H),RSFT_T(KC_J),RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN),KC_QUOTE,
    n____,        KC_Y,         KC_X,       KC_C,         KC_V,         KC_B,                                                    KC_N,         KC_M,         KC_COMMA,     KC_DOT,       KC_SLASH,     n____,
    n____,        n____,        n____,      n____,        MO(L_DEV),                  LALT(KC_F4),                 KC_F5,                      MO(L_DEV),    n____,        n____,        n____,        n____,
                                                          KC_SPACE,     KC_DELETE,    n____,                       n____,        KC_BSPACE,    KC_ENTER
  ),
  [L_DEV] = LAYOUT_moonlander(
    _____,        _____,        _____,        _____,        _____,        _____,        _____,                     _____,        _____,        _____,        _____,        _____,        _____,        _____,
    _____,        n____,        KC_AT,        KC_PERC,      KC_AMPR,      n____,        _____,                     _____,        KC_ASTR,      KC_TILD,      KC_LCBR,      KC_RCBR,      KC_HASH,      _____,
    _____,        KC_EXLM,      KC_UNDS,      KC_DLR,       KC_MINUS,     KC_PLUS,      _____,                     _____,        KC_PIPE,      KC_EQUAL,     KC_LPRN,      KC_RPRN,      KC_CIRC,      _____,
    _____,        n____,        n____,        n____,        n____,        n____,                                                 n____,        n____,        KC_LBRACKET,  KC_RBRACKET,  n____,        _____,
    _____,        _____,        _____,        _____,        _____,                      RGB_TOG,                   RESET,                      _____,        _____,        _____,        _____,        _____,
                                                            _____,        _____,        _____,                     _____,        _____,        _____
  ),
  [L_ARR] = LAYOUT_moonlander(
    _____,        _____,        _____,        _____,        _____,        _____,        _____,                     _____,        _____,        _____,        _____,        _____,        _____,        _____,
    _____,        _____,        KC_HOME,      KC_UP,        KC_END,       _____,        _____,                     _____,        _____,        KC_HOME,      KC_UP,        KC_END,       _____,        _____,
    _____,        _____,        KC_LEFT,      KC_DOWN,      KC_RIGHT,     _____,        _____,                     _____,        _____,        KC_LEFT,      KC_DOWN,      KC_RIGHT,     _____,        _____,
    _____,        _____,        _____,        _____,        _____,        _____,                                                 _____,        _____,        _____,        _____,        _____,        _____,
    _____,        _____,        _____,        _____,        _____,                      _____,                     _____,                      _____,        _____,        _____,        _____,        _____,
                                                            _____,        _____,        _____,                     _____,        _____,        _____
  ),
  [L_F] = LAYOUT_moonlander(
    _____,        _____,        KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,                     KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12,
    _____,        _____,        _____,        _____,        _____,        _____,        _____,                     _____,        _____,        _____,        _____,        _____,        _____,        _____,
    _____,        _____,        _____,        _____,        _____,        _____,        _____,                     _____,        _____,        _____,        _____,        _____,        _____,        _____,
    _____,        _____,        _____,        _____,        _____,        _____,                                                 _____,        _____,        _____,        _____,        _____,        _____,
    _____,        _____,        _____,        _____,        _____,                      _____,                     _____,                      _____,        _____,        _____,        _____,        _____,
                                                            _____,        _____,        _____,                     _____,        _____,        _____
  ),
  [L_UMLAUT] = LAYOUT_moonlander(
    _____,        n____,        n____,        n____,        n____,        n____,        n____,                     n____,        n____,        n____,        n____,        n____,        n____,        _____,
    _____,        n____,        n____,        n____,        n____,        n____,        n____,                     n____,        n____,        KC_UE,        n____,        KC_OE,        n____,        _____,
    _____,        KC_AE,        n____,        n____,        n____,        n____,        _____,                     _____,        n____,        n____,        n____,        n____,        n____,        _____,
    _____,        X(U_THUMBUP), n____,        n____,        n____,        n____,                                                 n____,        X(U_THUMBDWN),n____,        n____,        n____,        _____,
    _____,        _____,        n____,        n____,        n____,                      n____,                     n____,                      n____,        n____,        n____,        n____,        _____,
                                                            _____,        _____,        _____,                     _____,        _____,        _____
  ),
};

#ifdef CONSOLE_ENABLE
#define DBG(format, ...) {\
  uprintf(format, ##__VA_ARGS__); \
  uprintf("\n"); \
  dbg_umlaut(); \
}
#else
#define DBG(format, ...) {}
#endif

void keyboard_post_init_user(void) {
  DBG("POST KEYBOARD INIT");
}

// return value: Should firmware futher process key?
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  DBG((record->event.pressed ? "KEY PRESS: %u" : "KEY RELEASE: %u") , keycode);

  if (!record->event.pressed) return true;

  const bool shift = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;

  switch (keycode) {
    case RGB_SLD:
      rgblight_mode(1);
      return false;
    case KC_AE:
      register_unicode(unicode_map[shift ? U_AE : U_ae]);
      return false;
    case KC_UE:
      register_unicode(unicode_map[shift ? U_UE : U_ue]);
      return false;
    case KC_OE:
      register_unicode(unicode_map[shift ? U_OE : U_oe]);
      return false;
  }
  return true;
}
