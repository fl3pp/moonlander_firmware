/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define IGNORE_MOD_TAP_INTERRUPT
#undef DEBOUNCE
#define DEBOUNCE 10

#undef TAPPING_TERM
#define TAPPING_TERM 0

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1500

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"XNq49/jN0wo"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define RGB_MATRIX_STARTUP_SPD 60

#define UNICODE_SELECTED_MODES UC_WINC
#define UNICODE_KEY_WINC KC_F13
