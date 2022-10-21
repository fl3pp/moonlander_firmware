#include QMK_KEYBOARD_H
#include "version.h"

#include "features/unicode.h"
#include "features/umlaut.h"

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
  KC_UML_SHIFT,
};

enum layers {
   L_BASE,
   L_DEV,
   L_UMLAUT,
};

#define n____ KC_NO
#define KC_TRANS KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_moonlander(
    n____,        KC_GRAVE,     KC_1,       KC_2,         KC_3,         KC_4,         KC_5,                        KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         n____,        n____,
    KC_TAB,       KC_Q,         KC_W,       KC_E,         KC_R,         KC_T,         LCTL(KC_C),                  LCTL(KC_V),   KC_Z,         KC_U,         KC_I,         KC_O,         KC_P,         KC_BSLASH,
    KC_ESCAPE,    KC_A,         KC_S,       KC_D,         KC_F,         KC_G,         MO(L_UMLAUT),                MO(L_UMLAUT), KC_H,         KC_J,         KC_K,         KC_L,         KC_SCOLON,    KC_QUOTE,
    KC_LSHIFT,    KC_Y,         KC_X,       KC_C,         KC_V,         KC_B,                                                    KC_N,         KC_M,         KC_COMMA,     KC_DOT,       KC_SLASH,     KC_RSHIFT,
    KC_LCTRL,     n____,        KC_LGUI,    KC_LALT,      MO(L_DEV),                  LALT(KC_F4),                 KC_F5,                      MO(L_DEV),    KC_LEFT,      KC_DOWN,      KC_UP,        KC_RIGHT,
                                                          KC_SPACE,     KC_DELETE,    KC_HOME,                     KC_END,       KC_BSPACE,    KC_ENTER
  ),
  [L_DEV] = LAYOUT_moonlander(
    n____,        n____,        KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,                     KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12,
    n____,        n____,        KC_AT,        KC_PERC,      KC_AMPR,      n____,        n____,                     n____,        KC_ASTR,      KC_TILD,      KC_LCBR,      KC_RCBR,      KC_HASH,      n____,         
    n____,        KC_EXLM,      KC_UNDS,      KC_DLR,       KC_MINUS,     KC_PLUS,      n____,                     n____,        KC_PIPE,      KC_EQUAL,     KC_LPRN,      KC_RPRN,      KC_CIRC,      n____,         
    n____,        n____,        n____,        n____,        n____,        n____,                                                 n____,        n____,        KC_LBRACKET,  KC_RBRACKET,  n____,        n____,         
    n____,        n____,        n____,        n____,        n____,                      RGB_TOG,                   RESET,                      n____,        n____,        n____,        n____,        n____,         
                                                            n____,        n____,        n____,                     n____,        n____,        n____
  ),
  [L_UMLAUT] = LAYOUT_moonlander(
    n____,        n____,        n____,        n____,        n____,        n____,        n____,                     n____,        n____,        n____,        n____,        n____,        n____,        n____,         
    n____,        n____,        n____,        n____,        n____,        n____,        n____,                     n____,        n____,        KC_UE,        n____,        KC_OE,        n____,        n____,         
    n____,        KC_AE,        n____,        n____,        n____,        n____,        KC_TRANS,                  KC_TRANS,     n____,        n____,        n____,        n____,        n____,        n____,         
    KC_UML_SHIFT, X(U_THUMBUP), n____,        n____,        n____,        n____,                                                 n____,        X(U_THUMBDWN),n____,        n____,        n____,        KC_UML_SHIFT,
    n____,        n____,        n____,        n____,        n____,                      n____,                     n____,                      n____,        n____,        n____,        n____,        n____,         
                                                            n____,        n____,        n____,                     n____,        n____,        n____
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
  reset_umlaut();

  DBG("POST KEYBOARD INIT");
}

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t highest_layer = get_highest_layer(state);
  static uint8_t last_layer = 0;
  if (highest_layer == last_layer) return state; // layer did not change
  last_layer = highest_layer;

  DBG("LAYER SETUP: %u", get_highest_layer(state));

  switch (highest_layer) {
    case L_BASE:
    reset_umlaut();
    break;

    case L_UMLAUT:
    reset_umlaut();
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

    case KC_UML_SHIFT: return toggle_umlaut_shift();
    case KC_AE: return print_ae();
    case KC_UE: return print_ue();
    case KC_OE: return print_oe();

    case RGB_SLD:
    rgblight_mode(1);
    return false;

  }

  return true;
}
