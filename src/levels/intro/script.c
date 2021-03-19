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
#include "levels/menu/header.h"
#include "src/game/main.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/intro/header.h"

#include "src/menu/intro_geo.h"

extern const GeoLayout intro_geo_0002D0_V2[];
const LevelScript level_intro_splash_screen[] = {
    INIT_LEVEL(),
    FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd),
    LOAD_RAW(/*seg*/ 0x13, _behaviorSegmentRomStart, _behaviorSegmentRomEnd),
    LOAD_MIO0(/*seg*/ 0x07, _intro_segment_7SegmentRomStart, _intro_segment_7SegmentRomEnd),

    // Load "Super Mario 64" logo
    ALLOC_LEVEL_POOL(),
    AREA(/*index*/ 1, intro_geo_0002D0),
    END_AREA(),
    FREE_LEVEL_POOL(),

    // Start animation
    LOAD_AREA(/*area*/ 1),

    CALL(/*arg*/ 0, /*func*/ lvl_intro_update),
    SLEEP(/*frames*/ 100),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ 2, script_intro_L4),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ 3, script_intro_L1),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 32, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 32),
    CMD2A(/*unk2*/ 1),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 32),
    EXIT_AND_EXECUTE(/*seg*/ 0x14, _introSegmentRomStart, _introSegmentRomEnd, level_intro_mario_head_regular),
};

const LevelScript level_intro_mario_head_regular[] = {
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 50),
    SET_REG(/*value*/ 16),
    EXIT_AND_EXECUTE(/*seg*/ 0x14, _menuSegmentRomStart, _menuSegmentRomEnd, level_main_menu_entry_1),
};

const LevelScript level_intro_mario_head_dizzy[] = {
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 50),
    SET_REG(/*value*/ 16),
    EXIT_AND_EXECUTE(/*seg*/ 0x14, _menuSegmentRomStart, _menuSegmentRomEnd, level_main_menu_entry_1),
};

const LevelScript level_intro_entry_4[] = {
    INIT_LEVEL(),
    LOAD_RAW(/*seg*/ 0x13, _behaviorSegmentRomStart, _behaviorSegmentRomEnd),
    LOAD_MIO0_TEXTURE(/*seg*/ 0x0A, _title_screen_bg_mio0SegmentRomStart, _title_screen_bg_mio0SegmentRomEnd),
    LOAD_MIO0(/*seg*/ 0x07, _debug_level_select_mio0SegmentRomStart, _debug_level_select_mio0SegmentRomEnd),
    FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd),
    ALLOC_LEVEL_POOL(),

    AREA(/*index*/ 1, intro_geo_000414),
    END_AREA(),

    FREE_LEVEL_POOL(),
    LOAD_AREA(/*area*/ 1),
    SET_MENU_MUSIC(/*seq*/ 0x0002),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CALL_LOOP(/*arg*/ 3, /*func*/ lvl_intro_update),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ -1, script_intro_L5),
    JUMP(script_intro_L3),
};

// These should be static, but C doesn't allow non-sized forward declarations of static arrays

const LevelScript script_intro_L1[] = {
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 32, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 32),
    CMD2A(/*unk2*/ 1),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 32),
    SET_REG(/*value*/ LEVEL_WMOTR),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE(/*seg*/ 0x15, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, level_main_scripts_entry),
};

const LevelScript script_intro_L2[] = {
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE(/*seg*/ 0x14, _introSegmentRomStart, _introSegmentRomEnd, level_intro_entry_4),
};

const LevelScript script_intro_L3[] = {
    STOP_MUSIC(/*fadeOutTime*/ 0x00BE),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE(/*seg*/ 0x15, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, level_main_scripts_entry),
};

const LevelScript script_intro_L4[] = {
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 32, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 32),
    CMD2A(/*unk2*/ 1),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 32),
    SET_REG(/*value*/ LEVEL_TOTWC),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE(/*seg*/ 0x15, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, level_main_scripts_entry),
};

const LevelScript script_intro_L5[] = {
    STOP_MUSIC(/*fadeOutTime*/ 0x00BE),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    EXIT_AND_EXECUTE(/*seg*/ 0x14, _introSegmentRomStart, _introSegmentRomEnd, level_intro_splash_screen),
};
