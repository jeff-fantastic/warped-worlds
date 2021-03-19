#include "src/game/envfx_snow.h"

const GeoLayout woodenplatform_geo[] = {
	GEO_CULLING_RADIUS(2128),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, woodenplatform_Flying_Fartress_003_mesh),
		GEO_DISPLAY_LIST(LAYER_ALPHA, woodenplatform_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
