#include "src/game/envfx_snow.h"

const GeoLayout koopa_cannon_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_CULLING_RADIUS(15000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, koopa_cannon_000_displaylist_mesh),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, koopa_cannon_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
