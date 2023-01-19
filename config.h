/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 10

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"XNq49/jN0wo"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define RGB_MATRIX_STARTUP_SPD 60

#define UNICODE_SELECTED_MODES UC_WINC
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
