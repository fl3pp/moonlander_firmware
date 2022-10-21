#include "features/umlaut.h"
#include "features/unicode.h"

bool UMLAUT_SHIFT_STATE;

#ifdef CONSOLE_ENABLE
void dbg_umlaut(void) {
   uprintf("   UMLAUT_SHIFT = %s\n", (UMLAUT_SHIFT_STATE ? "true" : "false"));
}
#endif

void reset_umlaut(void) {
   UMLAUT_SHIFT_STATE = false;
}

bool toggle_umlaut_shift(void) {
   UMLAUT_SHIFT_STATE = !UMLAUT_SHIFT_STATE;
   return false;
}

bool print_umlaut_unicode(enum unicode_names code) {
   register_unicode(unicode_map[code]);
   return false;
}
bool print_ae(void) { return print_umlaut_unicode(UMLAUT_SHIFT_STATE ? U_AE : U_ae); }
bool print_oe(void) { return print_umlaut_unicode(UMLAUT_SHIFT_STATE ? U_OE : U_oe); }
bool print_ue(void) { return print_umlaut_unicode(UMLAUT_SHIFT_STATE ? U_UE : U_ue); }
