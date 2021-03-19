#include "src/game/envfx_snow.h"

const GeoLayout heart_clockhand_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, heart_clockhand_Plane_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, heart_clockhand_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
