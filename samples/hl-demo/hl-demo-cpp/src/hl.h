#ifndef HL_DEMO_HL_H
#define HL_DEMO_HL_H

#define ZLIB_VERSION "1.2.13"

#include "hl-config.h"
#include "lcc.h"
// #include "lp.h"
#include <iostream>
ZEXTERN const char *ZEXPORT zlibVersion OF((void));
void bc();
int getPublicKeySize();
int acquire_license();

#endif