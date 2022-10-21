#include <acutest.h>
#include "features/umlaut.c"

uint32_t last_registered_point;
uint32_t get_unicode_point(enum unicode_names name) { return name; }
void qmk_register_unicode(uint32_t code_point) { last_registered_point = code_point; }

void test_ae(void)
{
  reset_umlaut();
  print_ae();
  TEST_CHECK(last_registered_point == U_ae);
}

void test_oe(void)
{
  reset_umlaut();
  print_oe();
  TEST_CHECK(last_registered_point == U_oe);
}

void test_ue(void)
{
  reset_umlaut();
  print_ue();
  TEST_CHECK(last_registered_point == U_ue);
}

void test_shift_ae(void)
{
  reset_umlaut();
  toggle_umlaut_shift();
  print_ae();
  TEST_CHECK(last_registered_point == U_AE);
}

void test_shift_oe(void)
{
  reset_umlaut();
  toggle_umlaut_shift();
  print_oe();
  TEST_CHECK(last_registered_point == U_OE);
}

void test_shift_ue(void)
{
  reset_umlaut();
  toggle_umlaut_shift();
  print_ue();
  TEST_CHECK(last_registered_point == U_UE);
}

void test_shift_shift_ae(void)
{
  reset_umlaut();
  toggle_umlaut_shift();
  toggle_umlaut_shift();
  print_ae();
  TEST_CHECK(last_registered_point == U_ae);
}

void test_shift_reset_ae(void)
{
  reset_umlaut();
  toggle_umlaut_shift();
  reset_umlaut();
  print_ae();
  TEST_CHECK(last_registered_point == U_ae);
}

TEST_LIST = {
   { "test_ae", test_ae },
   { "test_ue", test_ue },
   { "test_oe", test_oe },
   { "test_shift_ae", test_shift_ae },
   { "test_shift_ue", test_shift_ue },
   { "test_shift_oe", test_shift_oe },
   { "test_shift_shift_ae", test_shift_shift_ae },
   { "test_shift_reset_ae", test_shift_reset_ae },
   { NULL, NULL }
};