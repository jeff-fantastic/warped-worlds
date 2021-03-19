#include "src/game/envfx_snow.h"

const GeoLayout bookstack_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_CULLING_RADIUS(800),
		GEO_OPEN_NODE(),
			GEO_SHADOW(SHADOW_SQUARE_SCALABLE, 90, 150),
			GEO_OPEN_NODE(),
				GEO_SWITCH_CASE(2, geo_switch_anim_state),
				GEO_OPEN_NODE(),
					GEO_NODE_START(),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_OPAQUE, bookstack_000_displaylist_mesh),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bookstack_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
