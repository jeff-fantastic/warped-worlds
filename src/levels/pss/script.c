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
#include "actors/common0.h"

#include "make_const_nonconst.h"
#include "levels/pss/header.h"

const LevelScript level_pss_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _pss_segment_7SegmentRomStart, _pss_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x05, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0xa, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WOODEN_PLATFORM, woodenplatform_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WATERBED, waterbed_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WEAK_SCAFFOLD, weakscaffold_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WHOMP_WAVE, invisible_bowser_accessory_geo), 

	AREA(1, pss_area_1),
		WARP_NODE(241, LEVEL_UNKNOWN_1, 1, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_UNKNOWN_1, 1, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_PSS, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_PSS, 2, 10, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -1603, 0, -5473, 0, 0, 0, 0x00060000, bhvBirdsSoundLoop),
		OBJECT(MODEL_WOODEN_PLATFORM, -5077, 619, -8912, 0, 0, 0, 0x00010000, bhvBobbingPlatform),
		OBJECT(MODEL_WOODEN_PLATFORM, -5077, 354, -9654, 0, 0, 0, 0x00000000, bhvBobbingPlatform),
		OBJECT(MODEL_WOODEN_PLATFORM, -4915, 619, -3835, 0, 0, 0, 0x00010000, bhvBobbingPlatform),
		OBJECT(MODEL_WOODEN_PLATFORM, -4915, 354, -4578, 0, 0, 0, 0x00000000, bhvBobbingPlatform),
		OBJECT(MODEL_WOODEN_PLATFORM, -4915, 828, -3122, 0, 0, 0, 0x00000000, bhvBobbingPlatform),
		OBJECT(0, -2092, 3640, -4979, 0, 0, 0, 0x00020000, bhvCoinFormation),
		OBJECT(0, -3119, 3377, -4979, 0, -180, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -3530, 2846, -4979, 0, -180, 0, 0x0, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1661, 2600, -6851, 0, -135, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -4120, 389, -5061, 0, 0, 0, 0x00020000, bhvCoinFormation),
		OBJECT(0, -4498, 389, -6275, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 463, 1089, -9369, 0, 0, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1152, 959, -3840, 0, 0, 0, 0x00020000, bhvCoinFormation),
		OBJECT(0, -3169, 2448, -8442, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(0, -3474, 3638, -6214, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_BLACK_BOBOMB, -4567, 388, -10227, 0, -90, 0, 0x00010000, bhvBobomb),
		OBJECT(38, -4034, 3640, -6216, 0, 90, 0, 0x00010000, bhvDoorWarp),
		OBJECT(137, -4120, 789, -4884, 0, 0, 0, 0x000B0000, bhvExclamationBox),
		OBJECT(0, 2088, 563, -3584, 0, 0, 0, 0x04000000, bhvHiddenRedCoinStar),
		OBJECT(0, -667, 1195, -2827, 0, 0, 0, 0x03000000, bhvHiddenStar),
		OBJECT(0, 2075, 259, -634, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(0, 2072, 259, -5602, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(0, -3631, 2600, -7487, 0, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(0, -1280, 3700, -5203, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(0, -5059, 451, -7592, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(215, 1322, 1091, -7540, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(215, 2105, 475, -4539, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(215, -4481, 2448, -8440, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3514, 3640, -4267, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN_NO_SHADOW, -2862, 2894, -3714, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2846, 752, -5404, 0, -180, 0, 0x0, bhvRedCoin),
		OBJECT(215, -5756, 388, -5240, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(215, -5313, 3640, -6205, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(0, -35, 259, -467, 0, 132, 0, 0x000a0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 132, -35, 259, -467),
		OBJECT(122, -3684, 686, -8973, 0, 0, 0, 0x0100000, bhvStar),
		OBJECT(23, 115, 259, -1062, 0, 0, 0, 0x0, bhvTree),
		OBJECT(23, -3093, 2611, -7496, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(23, -4154, 2611, -7482, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_WOODEN_SIGNPOST, -3183, 388, -9702, 0, -180, 0, 0x00B00000, bhvMessagePanel),
		OBJECT(MODEL_WATERBED, -1603, 72, -5473, 0, 0, 0, 0x00000000, bhvWaterbed),
		OBJECT(MODEL_WEAK_SCAFFOLD, -3683, 669, -9435, 0, 0, 0, 0x00000000, bhvWeakScaffold),
		OBJECT(MODEL_WOODEN_PLATFORM, -2862, 2585, -3714, 0, 0, 0, 0x00000000, bhvLFWoodPlatform),
		OBJECT(MODEL_WOODEN_PLATFORM, -2862, 934, -3291, 0, 0, 0, 0x00010000, bhvLFWoodPlatform),
		OBJECT(MODEL_WOODEN_PLATFORM, -2862, 934, -4139, 0, 0, 0, 0x00020000, bhvLFWoodPlatform),
		TERRAIN(pss_area_1_collision),
		MACRO_OBJECTS(pss_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEGACY_FORTRESS),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	AREA(2, pss_area_2),
		WARP_NODE(241, LEVEL_UNKNOWN_1, 1, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_UNKNOWN_1, 1, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_PSS, 2, 10, WARP_NO_CHECKPOINT),
		OBJECT(0, 8, 0, 2227, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(103, 0, 0, 0, 0, 0, 0, 0x01000000, bhvWhompKingBoss),
		TERRAIN(pss_area_2_collision),
		MACRO_OBJECTS(pss_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 132, -35, 259, -467),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
