// 0x16000F6C
const GeoLayout transparent_star_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 100),
   GEO_OPEN_NODE(),
//      GEO_SWITCH_CASE(16, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, transparent_star_seg3_dl_0302C560),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
