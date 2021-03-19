#include "src/game/envfx_snow.h"

const GeoLayout weakscaffold_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, weakscaffold_Flying_Fartress_009_mesh),
		GEO_DISPLAY_LIST(LAYER_ALPHA, weakscaffold_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
