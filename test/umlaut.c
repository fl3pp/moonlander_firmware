#include "shim/qmk.h"
#include "features/umlaut.c"
#include <acutest.h>

uint32_t get_unicode_point(enum unicode_names name) { return name; }
uint32_t last_registered_unicode;
void qmk_register_unicode(uint32_t code_point) {
  TEST_CHECK(last_registered_unicode == 0);
  TEST_MSG("Unasserted unicode point %i", last_registered_unicode);
  last_registered_unicode = code_point;
}
void test_test_unicode(uint32_t code_point) {
  TEST_CHECK(last_registered_unicode == code_point);
  TEST_MSG("Expected unicode point %i, got %i", code_point, last_registered_unicode);
  last_registered_unicode = 0;
}


void kc_down(uint16_t code) {
  user_keyevent_t event = { .keycode = code, .pressed = true};
  process_keyevent_umlaut(&event);
}
void kc_up(uint16_t code) {
  user_keyevent_t event = { .keycode = code, .pressed = false};
  process_keyevent_umlaut(&event);
}
void kc_down_up(uint16_t code) { kc_down(code); kc_up(code); }

void test_a(void) {
  last_registered_unicode = 0;
  kc_down_up(KC_A);
  TEST_CHECK(last_registered_unicode == 0);
}

void test_ae(void) {
  enter_umlaut_layer();
  kc_down_up(KC_A);
  leave_umlaut_layer();
  TEST_CHECK(last_registered_unicode == U_ae);
}

void test_oe(void) {
  enter_umlaut_layer();
  kc_down_up(KC_O);
  leave_umlaut_layer();
  TEST_CHECK(last_registered_unicode == U_oe);
}

void test_ue(void) {
  enter_umlaut_layer();
  kc_down_up(KC_U);
  leave_umlaut_layer();
  TEST_CHECK(last_registered_unicode == U_ue);
}

void test_shift_held(void) {
  enter_umlaut_layer();
  kc_down(KC_LSFT);
  kc_down_up(KC_A);
  kc_up(KC_LSFT);
  leave_umlaut_layer();
  TEST_CHECK(last_registered_unicode == U_AE);
}

void test_shift_held_before_enter(void) {
  kc_down(KC_LSFT);
  enter_umlaut_layer();
  kc_down_up(KC_A);
  kc_up(KC_LSFT);
  leave_umlaut_layer();
  TEST_CHECK(last_registered_unicode == U_AE);
}

void test_right_shift_held(void) {
  enter_umlaut_layer();
  kc_down(KC_RSFT);
  kc_down_up(KC_A);
  kc_up(KC_RSFT);
  leave_umlaut_layer();
  TEST_CHECK(last_registered_unicode == U_AE);
}

void test_shift_tapped_normal(void) {
  kc_down_up(KC_LSFT);
  enter_umlaut_layer();
  kc_down_up(KC_A);
  leave_umlaut_layer();
  TEST_CHECK(last_registered_unicode == U_ae);
}

void test_shift_tapped_inlayer(void) {
  enter_umlaut_layer();
  kc_down_up(KC_LSFT);
  kc_down_up(KC_A);
  leave_umlaut_layer();
  TEST_CHECK(last_registered_unicode == U_AE);
}

void test_enter_tapped_tapped(void) {
  enter_umlaut_layer();
  kc_down_up(KC_LSFT);
  kc_down_up(KC_A);
  TEST_CHECK(last_registered_unicode == U_AE);
  kc_down_up(KC_LSFT);
  kc_down_up(KC_A);
  leave_umlaut_layer();
  TEST_CHECK(last_registered_unicode == U_ae);
}

void test_enter_tapped_leave_enter(void) {
  enter_umlaut_layer();
  kc_down_up(KC_LSFT);
  leave_umlaut_layer();
  enter_umlaut_layer();
  kc_down_up(KC_A);
  leave_umlaut_layer();
  TEST_CHECK(last_registered_unicode == U_ae);
}

TEST_LIST = {
   { "test_a", test_a },
   { "test_ae", test_ae },
   { "test_oe", test_oe },
   { "test_ue", test_ue },
   { "test_shift_held", test_shift_held },
   { "test_shift_held_before_enter", test_shift_held_before_enter },
   { "test_right_shift_held", test_right_shift_held },
   { "test_shift_tapped_normal", test_shift_tapped_normal },
   { "test_shift_tapped_inlayer", test_shift_tapped_inlayer },
   { "test_enter_tapped_tapped", test_enter_tapped_tapped },
   { "test_enter_tapped_leave_enter", test_enter_tapped_leave_enter },
   { NULL, NULL }
};