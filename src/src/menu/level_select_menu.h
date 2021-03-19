#ifndef LEVEL_SELECT_MENU_H
#define LEVEL_SELECT_MENU_H

#include <PR/ultratypes.h>

#include "macros.h"

s32 lvl_intro_update(s16 arg1, UNUSED s32 arg2);
s32 lvl_error_update(s16 arg1, UNUSED s32 arg2);
Gfx *geo_error_strings(s16 callContext, UNUSED struct GraphNode *node);

#endif // LEVEL_SELECT_MENU_H
