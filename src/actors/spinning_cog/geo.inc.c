#include "src/game/envfx_snow.h"

const GeoLayout spinning_cog_geo[] = {
	GEO_CULLING_RADIUS(1600),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spinning_cog_CogCol_mesh),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spinning_cog_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
