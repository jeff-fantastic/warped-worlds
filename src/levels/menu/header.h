#ifndef MENU_HEADER_H
#define MENU_HEADER_H

#include "types.h"
#include "texscroll.inc.h"

// geo
extern const GeoLayout geo_menu_mario_save_button[];
extern const GeoLayout geo_menu_mario_save_button_fade[];
extern const GeoLayout geo_menu_mario_new_button[];
extern const GeoLayout geo_menu_mario_new_button_fade[];
extern const GeoLayout geo_menu_erase_button[];
extern const GeoLayout geo_menu_copy_button[];
extern const GeoLayout geo_menu_file_button[];
extern const GeoLayout geo_menu_score_button[];
extern const GeoLayout geo_menu_sound_button[];
extern const GeoLayout geo_menu_generic_button[];
extern const GeoLayout geo_menu_file_select_strings_and_menu_cursor[];
extern const GeoLayout geo_menu_act_selector_strings[];
extern const GeoLayout geo_cloud_front[];
extern u8 titlehpc_cfront_CloudTile_ia4[];
extern Vtx titlehpc_cfront_Plane_003_mesh_vtx_0[4];
extern Gfx titlehpc_cfront_Plane_003_mesh_tri_0[];
extern Gfx mat_titlehpccfront_sm64_material[];
extern Gfx mat_revert_titlehpccfront_sm64_material[];
extern Gfx titlehpc_cfront_Plane_003_mesh[];
extern Gfx titlehpccfront_material_revert_render_settings[];
extern const GeoLayout geo_cloud_back[];
extern u8 titlehpc_cback_CloudTile_ia4[];
extern Vtx titlehpc_cback_Plane_001_mesh_vtx_0[4];
extern Gfx titlehpc_cback_Plane_001_mesh_tri_0[];
extern Gfx mat_titlehpccback_sm64_material_002[];
extern Gfx mat_revert_titlehpccback_sm64_material_002[];
extern Gfx titlehpc_cback_Plane_001_mesh[];
extern Gfx titlehpccback_material_revert_render_settings[];
extern const GeoLayout geo_cloud_middle[];
extern u8 titlehpc_cmiddle_CloudTile_ia4[];
extern Vtx titlehpc_cmiddle_Plane_002_mesh_vtx_0[4];
extern Gfx titlehpc_cmiddle_Plane_002_mesh_tri_0[];
extern Gfx mat_titlehpccmiddle_sm64_material_001[];
extern Gfx mat_revert_titlehpccmiddle_sm64_material_001[];
extern Gfx titlehpc_cmiddle_Plane_002_mesh[];
extern Gfx titlehpccmiddle_material_revert_render_settings[];
extern const GeoLayout geo_background[];
extern Lights1 titlehpc_sm64_material_001_v3_001_layer4_lights;
extern u8 titlehpc_CloudTile_ia4[];
extern Vtx titlehpc_Plane_mesh_vtx_0[4];
extern Gfx titlehpc_Plane_mesh_tri_0[];
extern Vtx titlehpc_Plane_mesh_vtx_1[4];
extern Gfx titlehpc_Plane_mesh_tri_1[];
extern Vtx titlehpc_Plane_mesh_vtx_2[4];
extern Gfx titlehpc_Plane_mesh_tri_2[];
extern Vtx titlehpc_Plane_mesh_vtx_3[4];
extern Gfx titlehpc_Plane_mesh_tri_3[];
extern Gfx mat_titlehpc_sm64_material_001_v3_001_layer4[];
extern Gfx mat_revert_titlehpc_sm64_material_001_v3_001_layer4[];
extern Gfx mat_titlehpc_sm64_material_002[];
extern Gfx mat_revert_titlehpc_sm64_material_002[];
extern Gfx mat_titlehpc_sm64_material_001[];
extern Gfx mat_revert_titlehpc_sm64_material_001[];
extern Gfx mat_titlehpc_sm64_material[];
extern Gfx mat_revert_titlehpc_sm64_material[];
extern Gfx titlehpc_Plane_mesh[];
extern Gfx titlehpc_material_revert_render_settings[];

// leveldata
extern const Gfx dl_menu_mario_save_button_base[];
extern const Gfx dl_menu_mario_new_button_base[];
extern const Gfx dl_menu_save_button_back[];
extern const Gfx dl_menu_save_button_fade_back[];
extern const Gfx dl_menu_erase_button[];
extern const Gfx dl_menu_copy_button[];
extern const Gfx dl_menu_file_button[];
extern const Gfx dl_menu_score_button[];
extern const Gfx dl_menu_sound_button[];
extern const Gfx dl_menu_generic_button[];
extern const Gfx dl_menu_idle_hand[];
extern const Gfx dl_menu_grabbing_hand[];
extern const u8 *const menu_hud_lut[];
extern const u8 *const menu_font_lut[];
extern const Gfx dl_menu_ia8_text_begin[];
extern const Gfx dl_menu_ia8_text_end[];
extern const Gfx dl_menu_rgba16_wood_course[];
extern const Gfx dl_menu_texture_course_upper[];
extern const Gfx dl_menu_texture_niveau_upper[];
extern const Gfx dl_menu_texture_kurs_upper[];
extern const Collision main_menu_seg7_collision[];
#ifdef VERSION_EU
extern const u8 eu_course_strings_en_table[];
extern const u8 eu_course_strings_fr_table[];
extern const u8 eu_course_strings_de_table[];
#endif

// script
extern const LevelScript level_main_menu_entry_1[];
extern const LevelScript level_main_menu_entry_2[];
extern const LevelScript script_goto_legacy_fortress[];
extern const LevelScript script_goto_campaign[];

#endif
