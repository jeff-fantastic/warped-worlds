#include "src/game/envfx_snow.h"

const GeoLayout n64_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, n64_N_square_mesh),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, n64_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
