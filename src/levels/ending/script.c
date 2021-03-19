#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/area.h"
#include "game/level_update.h"
#include "menu/level_select_menu.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/ending/header.h"

const LevelScript level_ending_entry[] = {
    INIT_LEVEL(),
    LOAD_MIO0(/*seg*/ 0x07, _ending_segment_7SegmentRomStart, _ending_segment_7SegmentRomEnd),
    ALLOC_LEVEL_POOL(),
    LOAD_MODEL_FROM_GEO(MODEL_N64, n64_geo),

    AREA(/*index*/ 1, ending_geo_000050),
        OBJECT(/*model*/ MODEL_N64, /*pos*/ 420, -800, -500, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvN64Logo),
        TERRAIN(/*terrainData*/ error_seg7_collision),
    END_AREA(),

    FREE_LEVEL_POOL(),
    SET_MENU_MUSIC(/*seq*/ SEQ_ERROR_HANDLER),
    LOAD_AREA(/*area*/ 1),
    BLACKOUT(/*active*/ FALSE),
    CALL_LOOP(0, lvl_error_update),

    // L1:
    SLEEP(/*frames*/ 120),
};
