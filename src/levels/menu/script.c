#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/area.h"
#include "game/level_update.h"
#include "menu/file_select.h"
#include "menu/star_select.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/menu/header.h"

const LevelScript level_main_menu_entry_1[] = {
    INIT_LEVEL(),
    FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd),
    LOAD_MIO0(/*seg*/ 0x03, _common1_mio0SegmentRomStart, _common1_mio0SegmentRomEnd),
    LOAD_MIO0(/*seg*/ 0x07, _menu_segment_7SegmentRomStart, _menu_segment_7SegmentRomEnd),
    LOAD_RAW(/*seg*/ 0x13, _behaviorSegmentRomStart, _behaviorSegmentRomEnd),
    LOAD_RAW( /*seg*/ 0x16, _common1_geoSegmentRomStart, _common1_geoSegmentRomEnd),
    ALLOC_LEVEL_POOL(),
    LOAD_MODEL_FROM_GEO(MODEL_TITLESCREEN, title_geo),

    AREA(/*index*/ 1, geo_menu_file_select_strings_and_menu_cursor),
        WARP_NODE(0x0A, LEVEL_UNKNOWN_1, 1, 0x0A, WARP_NO_CHECKPOINT),
        OBJECT(/*model*/ MODEL_NONE,         /*pos*/ 0, 0, -19000, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ bhvMenuButtonManager),
        OBJECT(/*model*/ MODEL_TITLESCREEN, /*pos*/ 0, 0, -19000, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ bhvYellowBackgroundInMenu),
        TERRAIN(/*terrainData*/ main_menu_seg7_collision),
    END_AREA(),

    FREE_LEVEL_POOL(),
    LOAD_AREA(/*area*/ 1),
    SET_MENU_MUSIC(/*seq*/ 0x0028),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 32, /*color*/ 0x00, 0x00, 0x00),
    CALL(/*arg*/ 0, /*func*/ lvl_init_menu_values_and_cursor_pos),
    CALL_LOOP(/*arg*/ 0, /*func*/ lvl_update_obj_and_load_file_selected),
    GET_OR_SET(/*op*/ OP_SET, /*var*/ VAR_CURR_SAVE_FILE_NUM),
    CALL_LOOP(/*arg*/ 0, /*func*/ lvl_decider),
    JUMP_IF(OP_EQ, 1, script_goto_campaign),
    JUMP_IF(OP_EQ, -1, script_goto_legacy_fortress),
};

const LevelScript level_main_menu_entry_2[] = {
    /*0*/ CALL(/*arg*/ 0, /*func*/ lvl_set_current_level),
    /*2*/ JUMP_IF(/*op*/ OP_EQ, /*arg*/ 0, level_main_menu_entry_2 + 42),
    /*5*/ INIT_LEVEL(),
    /*6*/ FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd),
    /*10*/ LOAD_MIO0(/*seg*/ 0x07, _menu_segment_7SegmentRomStart, _menu_segment_7SegmentRomEnd),
    /*13*/ ALLOC_LEVEL_POOL(),

    /*14*/ AREA(/*index*/ 2, geo_menu_act_selector_strings),
        /*16*/ OBJECT(/*model*/ MODEL_NONE, /*pos*/ 0, -100, 0, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ bhvActSelector),
        /*22*/ TERRAIN(/*terrainData*/ main_menu_seg7_collision),
    /*24*/ END_AREA(),

    /*25*/ FREE_LEVEL_POOL(),
    /*26*/ LOAD_AREA(/*area*/ 2),
#ifdef NO_SEGMENTED_MEMORY
           // sVisibleStars is set to 0 during FIXED_LOAD above on N64, but not when NO_SEGMENTED_MEMORY is used.
           // lvl_init_act_selector_values_and_stars must be called here otherwise the previous
           // value is retained and causes incorrect drawing during the 16 transition frames.
           CALL(/*arg*/ 0, /*func*/ lvl_init_act_selector_values_and_stars),
#endif
    /*27*/ TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 32, /*color*/ 0x00, 0x00, 0x00),
    /*29*/ SLEEP(/*frames*/ 16),
    /*30*/ SET_MENU_MUSIC(/*seq*/ SEQ_STREAMED_STAR_SELECT),
#ifndef NO_SEGMENTED_MEMORY
    /*31*/ CALL(/*arg*/ 0, /*func*/ lvl_init_act_selector_values_and_stars),
#endif
    /*33*/ CALL_LOOP(/*arg*/ 0, /*func*/ lvl_update_obj_and_load_act_button_actions),
    /*35*/ GET_OR_SET(/*op*/ OP_SET, /*var*/ VAR_CURR_ACT_NUM),
    /*36*/ STOP_MUSIC(/*fadeOutTime*/ 0x00BE),
    /*37*/ TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    /*39*/ SLEEP(/*frames*/ 16),
    /*40*/ CLEAR_LEVEL(),
    /*41*/ SLEEP_BEFORE_EXIT(/*frames*/ 1),
    // L1:
    /*42*/ EXIT(),
};

const LevelScript script_goto_legacy_fortress[] = {
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 32, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 96),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    SET_REG(/*value*/ LEVEL_PSS),
    EXIT_AND_EXECUTE(/*seg*/ 0x15, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, level_main_scripts_entry),
};

const LevelScript script_goto_campaign[] = {
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 32, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 96),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    SET_REG(/*value*/ LEVEL_CASTLE),
    EXIT_AND_EXECUTE(/*seg*/ 0x15, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, level_main_scripts_entry),
};
