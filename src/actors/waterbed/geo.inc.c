#include "src/game/envfx_snow.h"

const GeoLayout waterbed_geo[] = {
	GEO_CULLING_RADIUS(10000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waterbed_Water_Visual_001_mesh),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waterbed_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
