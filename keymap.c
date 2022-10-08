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
  MU_ae,
  MU_ue,
  MU_oe,
  MU_shift,
};

#define _____ KC_NO
#define KC_TRANS KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ========== BASE
  [0] = LAYOUT_moonlander(
    TO(3),        KC_GRAVE,     KC_1,       KC_2,         KC_3,         KC_4,         KC_5,                           KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_MINUS,     KC_EQUAL,
    KC_TAB,       KC_Q,         KC_W,       KC_E,         KC_R,         KC_T,         LCTL(KC_C),                     LCTL(KC_V),   KC_Z,         KC_U,         KC_I,         KC_O,         KC_P,         KC_BSLASH,
    KC_ESCAPE,    KC_A,         KC_S,       KC_D,         KC_F,         KC_G,         MO(2),                          MO(2),        KC_H,         KC_J,         KC_K,         KC_L,         KC_SCOLON,    KC_QUOTE,
    KC_LSHIFT,    KC_Y,         KC_X,       KC_C,         KC_V,         KC_B,                                                       KC_N,         KC_M,         KC_COMMA,     KC_DOT,       KC_SLASH,     KC_RSHIFT,
    KC_LCTRL,     KC_DELETE,    KC_LGUI,    KC_LALT,      MO(1),                      LALT(KC_F4),                    KC_F5,                      MO(1),        KC_LEFT,      KC_DOWN,      KC_UP,        KC_RIGHT,
                                                          KC_SPACE,     KC_DELETE,    KC_HOME,                        KC_END,       KC_BSPACE,    KC_ENTER
  ),
  // ========== DEV
  [1] = LAYOUT_moonlander(
    _____,        _____,        KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,                        KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12,
    _____,        KC_PERC,      KC_AT,        KC_LABK,      KC_RABK,      KC_AMPR,      _____,                        _____,        KC_ASTR,      KC_TILD,      KC_LCBR,      KC_RCBR,      KC_HASH,      _____,         
    _____,        KC_EXLM,      KC_UNDS,      KC_DLR,       KC_MINUS,     KC_PLUS,      _____,                        _____,        KC_PIPE,      KC_EQUAL,     KC_LPRN,      KC_RPRN,      KC_CIRC,      _____,         
    _____,        _____,        _____,        _____,        _____,        _____,                                                    _____,        _____,        KC_LBRACKET,  KC_RBRACKET,  _____,        _____,         
    _____,        _____,        _____,        _____,        _____,                      RGB_TOG,                      RESET,                      _____,        _____,        _____,        _____,        _____,         
                                                            _____,        _____,        _____,                        _____,        _____,        _____
  ),
  // ========== UMLAUTS
  [2] = LAYOUT_moonlander(
    _____,        _____,        _____,        _____,        _____,        _____,        _____,                        _____,        _____,        _____,        _____,        _____,        _____,        _____,         
    _____,        _____,        _____,        _____,        _____,        _____,        _____,                        _____,        _____,        MU_ue,        _____,        MU_oe,        _____,        _____,         
    _____,        MU_ae,        _____,        _____,        _____,        _____,        _____,                        _____,        _____,        _____,        _____,        _____,        _____,        _____,         
    MU_shift,     _____,        _____,        _____,        _____,        _____,                                                    _____,        _____,        _____,        _____,        _____,        MU_shift,
    _____,        _____,        _____,        _____,        _____,                      _____,                        _____,                      _____,        _____,        _____,        _____,        _____,         
                                                            _____,        _____,        _____,                        _____,        _____,        _____
  ),
  // ========== MOUSE
  [4] = LAYOUT_moonlander(
    TO(0),        _____,        _____,        _____,        _____,        _____,        _____,                        _____,        _____,        _____,        _____,        _____,        _____,        _____,
    _____,        _____,        _____,        KC_MS_UP,     _____,        _____,        _____,                        _____,        _____,        _____,        _____,        _____,        _____,        _____,
    _____,        _____,        KC_MS_LEFT,   KC_MS_DOWN,   KC_MS_RIGHT,  _____,        _____,                        _____,        _____,        KC_MS_LEFT,   KC_MS_DOWN,   KC_MS_UP,     KC_MS_RIGHT,  _____,
    _____,        _____,        _____,        _____,        _____,        _____,                                                    _____,        _____,        _____,        _____,        _____,        _____,
    _____,        _____,        _____,        _____,        _____,                      _____,                        _____,                      _____,        _____,        _____,        _____,        _____,
                                                            KC_MS_BTN1,   KC_MS_BTN3,   _____,                        _____,        KC_MS_BTN3,   KC_MS_BTN2
  ),
};

bool MU_shift_state = false;

// return value: Should firmware futher process key?
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  
  switch (keycode) {
    case MU_shift:
	MU_shift_state = record->event.pressed;
	return false;
  } 
  
  // if not pressed, then it's release
  if (!record->event.pressed) return true;
	
  switch (keycode) {

    case MU_ae:
	if (MU_shift_state) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_6) ));
	} else {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_8) ));
	}
	return false;

    case MU_ue:
    if (MU_shift_state) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0) ));
	} else {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_2) ));
	}
    return false;

    case MU_oe:
    if (MU_shift_state) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_4) ));
	} else {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_6) ));
	}
    return false;

    case RGB_SLD:
	rgblight_mode(1);
	return false;

  }
  return true;
}


