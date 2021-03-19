// 0x16000EA0
const GeoLayout star_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 100),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(16, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin1_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin1_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin2_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin2_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin3_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin3_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin4_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin4_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin5_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin5_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin6_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin6_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin7_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin7_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin8_txt),
			GEO_DISPLAY_LIST(LAYER_ALPHA, star_coin8_txt),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

const GeoLayout star_dust_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 100),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(16, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust1),
         GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust1),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust2),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust2),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust3),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust3),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust4),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust4),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust5),
         GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust5),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust6),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust6),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust7),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust7),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust8),
		 GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_star_dust8),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
