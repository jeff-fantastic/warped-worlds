#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "actors/group0.h"

#include "make_const_nonconst.h"
#include "levels/wmotr/header.h"

const LevelScript level_wmotr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _wmotr_segment_7SegmentRomStart, _wmotr_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _sky_mio0SegmentRomStart, _sky_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group9_mio0SegmentRomStart, _group9_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI, luigi_geo), 

	AREA(1, wmotr_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_ENDING, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_ENDING, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 3701, 646, 1543, 0, 90, 0, 0x00070000, bhvBirdsSoundLoop),
		OBJECT(MODEL_STAR, 3666, 3913, 6754, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -2430, 19, 17, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 90, -2430, 19, 17),
		TERRAIN(wmotr_area_1_collision),
		MACRO_OBJECTS(wmotr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_HELL_AMBIANCE),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -2430, 19, 17),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
