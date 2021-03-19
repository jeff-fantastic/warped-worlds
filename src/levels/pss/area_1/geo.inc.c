#include "src/game/envfx_snow.h"

const GeoLayout pss_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17, -1, 24, pss_dl_Flying_Fartress_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 17, -1, 24, pss_dl_Flying_Fartress_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -98, 1114, -4932, pss_dl_Flying_Fartress_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17, -1, 24, pss_dl_Flying_Fartress_003_mesh),
		GEO_TRANSLATE_NODE(LAYER_ALPHA, 17, -1, 24),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17, -1, 24, pss_dl_Flying_Fartress_006_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4419, 4648, -6213, pss_dl_Flying_Fartress_007_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 17, -1, 24, pss_dl_Flying_Fartress_008_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 17, -1, 24, pss_dl_Flying_Fartress_010_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 17, -1, 24, pss_dl_Flying_Fartress_011_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3632, 2622, -7501, pss_dl_Flying_Fartress_012_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17, -1, 24, pss_dl_Flying_Fartress_013_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -3094, 2603, -7496, pss_dl_Tree_Shadows_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout pss_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_ABOVE_CLOUDS, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -213, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, pss_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pss_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, pss_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pss_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
