#ifndef UMLAUT_H
#define UMLAUT_H

#include "shim/qmk.h"

#ifdef CONSOLE_ENABLE
void dbg_umlaut(void);
#endif

void enter_umlaut_layer(void);
void leave_umlaut_layer(void);
bool process_keyevent_umlaut(const user_keyevent_t *event);

#endif
