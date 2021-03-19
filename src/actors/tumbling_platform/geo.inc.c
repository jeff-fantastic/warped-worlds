#include "src/game/envfx_snow.h"

const GeoLayout tumbling_platform_geo[] = {
	GEO_CULLING_RADIUS(800),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tumbling_platform_group_7_001_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tumbling_platform_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
