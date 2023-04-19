#pragma once

// -- ZSA defaults
#include "../default/config.h"
#define FIRMWARE_VERSION u8"default/latest"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
// 

#undef DEBOUNCE
#define DEBOUNCE 10


#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
#define UNICODE_KEY_WINC KC_F13

// tapping term in ms (how long until a tap becomes a hold)
#define TAPPING_TERM 200
// Prevent rollover (n down, o down, n up, o up) to trigger mods, if duration lower than tapping term
#define IGNORE_MOD_TAP_INTERRUPT
// Undercut tapping term (n down, o down, o up, n up)
#define TAPPING_FORCE_HOLD
// SEE: https://precondition.github.io/home-row-mods#using-home-row-mods-with-qmk

// https://docs.qmk.fm/#/feature_caps_word?id=idle-timeout
#define CAPS_WORD_IDLE_TIMEOUT 5000
