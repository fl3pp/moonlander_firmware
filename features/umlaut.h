#ifndef UMLAUT_H
#define UMLAUT_H

#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
void dbg_umlaut(void);
#endif

void reset_umlaut(void);
bool toggle_umlaut_shift(void);
bool print_ae(void);
bool print_oe(void);
bool print_ue(void);

#endif
