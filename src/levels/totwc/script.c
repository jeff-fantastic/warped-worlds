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

#include "make_const_nonconst.h"
#include "levels/totwc/header.h"

const LevelScript level_totwc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _totwc_segment_7SegmentRomStart, _totwc_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _sky_mio0SegmentRomStart, _sky_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, totwc_geo_000160), 
	LOAD_MODEL_FROM_GEO(MODEL_EVIL_HEART, evilheart_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HEART_CLOCKHAND, heart_clockhand_geo), 

	AREA(1, totwc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_HEART_CLOCKHAND, -37, 647, 192, 0, 0, 0, 0x00000000, bhvHeartClock),
		OBJECT(MODEL_HEART_CLOCKHAND, -166, 533, 192, 0, -10, 0, 0x00010000, bhvHeartClock),
		OBJECT(MODEL_EVIL_HEART, 6, 264, 0, 0, 0, 0, 0x00000000, bhvHeart),
		OBJECT(MODEL_NONE, 0, 0, 2857, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, -180, 0, 0, 2857),
		TERRAIN(totwc_area_1_collision),
		MACRO_OBJECTS(totwc_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 0, 0, 2857),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
