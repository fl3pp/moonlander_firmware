/*
 * Disable word wrap before editing this file (set nowrap)
 */

#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

enum unicode_names {
  U_AE,
  U_ae,
  U_UE,
  U_ue,
  U_OE,
  U_oe,
  U_THUMBUP,
};

const uint32_t PROGMEM unicode_map[] = {
  [U_AE] = 0xC4,
  [U_ae] = 0xE4,
  [U_UE] = 0xDC,
  [U_ue] = 0xFC,
  [U_OE] = 0xD6,
  [U_oe] = 0xF6,
  [U_THUMBUP] = 0x1F44D,  // 👍
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
  MU_AE,
  MU_UE,
  MU_OE,
  MU_SHIFT,
};

enum layers {
   L_BASE,
   L_DEV,
   L_UMLAUT,
   L_MOUSE,
};

#define _____ KC_NO
#define KC_TRANS KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_moonlander(
    TO(L_MOUSE),  KC_GRAVE,     KC_1,       KC_2,         KC_3,         KC_4,         KC_5,                        KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_MINUS,     KC_EQUAL,
    KC_TAB,       KC_Q,         KC_W,       KC_E,         KC_R,         KC_T,         LCTL(KC_C),                  LCTL(KC_V),   KC_Z,         KC_U,         KC_I,         KC_O,         KC_P,         KC_BSLASH,
    KC_ESCAPE,    KC_A,         KC_S,       KC_D,         KC_F,         KC_G,         MO(L_UMLAUT),                MO(L_UMLAUT), KC_H,         KC_J,         KC_K,         KC_L,         KC_SCOLON,    KC_QUOTE,
    KC_LSHIFT,    KC_Y,         KC_X,       KC_C,         KC_V,         KC_B,                                                    KC_N,         KC_M,         KC_COMMA,     KC_DOT,       KC_SLASH,     KC_RSHIFT,
    KC_LCTRL,     _____,        KC_LGUI,    KC_LALT,      MO(L_DEV),                  LALT(KC_F4),                 KC_F5,                      MO(L_DEV),    KC_LEFT,      KC_DOWN,      KC_UP,        KC_RIGHT,
                                                          KC_SPACE,     KC_DELETE,    KC_HOME,                     KC_END,       KC_BSPACE,    KC_ENTER
  ),
  [L_DEV] = LAYOUT_moonlander(
    _____,        _____,        KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,                     KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12,
    _____,        KC_PERC,      KC_AT,        KC_LABK,      KC_RABK,      KC_AMPR,      _____,                     _____,        KC_ASTR,      KC_TILD,      KC_LCBR,      KC_RCBR,      KC_HASH,      _____,         
    _____,        KC_EXLM,      KC_UNDS,      KC_DLR,       KC_MINUS,     KC_PLUS,      _____,                     _____,        KC_PIPE,      KC_EQUAL,     KC_LPRN,      KC_RPRN,      KC_CIRC,      _____,         
    _____,        _____,        _____,        _____,        _____,        _____,                                                 _____,        _____,        KC_LBRACKET,  KC_RBRACKET,  _____,        _____,         
    _____,        _____,        _____,        _____,        _____,                      RGB_TOG,                   RESET,                      _____,        _____,        _____,        _____,        _____,         
                                                            _____,        _____,        _____,                     _____,        _____,        _____
  ),
  [L_UMLAUT] = LAYOUT_moonlander(
    _____,        _____,        _____,        _____,        _____,        _____,        _____,                     _____,        _____,        _____,        _____,        _____,        _____,        _____,         
    _____,        _____,        _____,        _____,        _____,        _____,        _____,                     _____,        _____,        MU_UE,        _____,        MU_OE,        _____,        _____,         
    _____,        MU_AE,        _____,        _____,        _____,        _____,        KC_TRANS,                  KC_TRANS,     _____,        _____,        _____,        _____,        _____,        _____,         
    MU_SHIFT,     X(U_THUMBUP), _____,        _____,        _____,        _____,                                                 _____,        _____,        _____,        _____,        _____,        MU_SHIFT,
    _____,        _____,        _____,        _____,        _____,                      _____,                     _____,                      _____,        _____,        _____,        _____,        _____,         
                                                            _____,        _____,        _____,                     _____,        _____,        _____
  ),
  [L_MOUSE] = LAYOUT_moonlander(
    TO(0),        _____,        _____,        _____,        _____,        _____,        _____,                     _____,        _____,        _____,        _____,        _____,        _____,        _____,
    _____,        _____,        _____,        KC_MS_UP,     _____,        _____,        _____,                     _____,        _____,        _____,        _____,        _____,        _____,        _____,
    _____,        _____,        KC_MS_LEFT,   KC_MS_DOWN,   KC_MS_RIGHT,  _____,        _____,                     _____,        _____,        KC_MS_LEFT,   KC_MS_DOWN,   KC_MS_UP,     KC_MS_RIGHT,  _____,
    _____,        _____,        _____,        _____,        _____,        _____,                                                 _____,        _____,        _____,        _____,        _____,        _____,
    _____,        _____,        _____,        _____,        _____,                      _____,                     _____,                      _____,        _____,        _____,        _____,        _____,
                                                            KC_MS_BTN1,   KC_MS_BTN3,   _____,                     _____,        KC_MS_BTN3,   KC_MS_BTN2
  ),
};

struct {
  bool UMLAUT_SHIFT;
} custom_state;


#ifdef CONSOLE_ENABLE
#define DBG(format, ...) {\
  uprintf(format, ##__VA_ARGS__); \
  uprintf("\n"); \
  uprintf("  UMLAUT_SHIFT = %s\n", (custom_state.UMLAUT_SHIFT ? "true" : "false")); \
}
#else
#define DBG(format, ...) {}
#endif

void keyboard_post_init_user(void) {
  custom_state.UMLAUT_SHIFT = false;

  DBG("POST KEYBOARD INIT");
}

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t highest_layer = get_highest_layer(state);
  static uint8_t last_layer = 0;

  // layer did not change
  if (highest_layer == last_layer) return state;
  last_layer = highest_layer;

  DBG("LAYER SETUP: %u", get_highest_layer(state));

  switch (highest_layer) {
    case L_BASE:
    custom_state.UMLAUT_SHIFT = false;
    break;

    case L_UMLAUT:
    custom_state.UMLAUT_SHIFT = false;
    break;
  }

  return state;
}
// return value: Should firmware futher process key?
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  DBG((record->event.pressed ? "KEY PRESS: %u" : "KEY RELEASE: %u") , keycode);

  // if not pressed, then it's release
  if (!record->event.pressed) return true;

  switch (keycode) {

    case MU_SHIFT:
    custom_state.UMLAUT_SHIFT = !custom_state.UMLAUT_SHIFT;
    return false;

    case MU_AE:
    register_unicode(unicode_map[custom_state.UMLAUT_SHIFT ? U_AE : U_ae]);
    return false;

    case MU_UE:
    register_unicode(unicode_map[custom_state.UMLAUT_SHIFT ? U_UE : U_ue]);
    return false;

    case MU_OE:
    register_unicode(unicode_map[custom_state.UMLAUT_SHIFT ? U_OE : U_oe]);
    return false;

    case RGB_SLD:
    rgblight_mode(1);
    return false;

  }
  return true;
}
