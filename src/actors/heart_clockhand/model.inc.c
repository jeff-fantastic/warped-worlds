Vtx heart_clockhand_Plane_mesh_vtx_0[4] = {
	{{{-8, -8, 2},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{8, -8, 2},0, {1008, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{3, 66, 3},0, {1008, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, 66, 3},0, {-16, -16},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx heart_clockhand_Plane_mesh_tri_0[] = {
	gsSPVertex(heart_clockhand_Plane_mesh_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_heart_clockhand_sm64_material_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, PRIMITIVE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, PRIMITIVE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 141, 17, 0, 255),
	gsSPEndDisplayList(),
};

Gfx heart_clockhand_Plane_mesh[] = {
	gsSPDisplayList(mat_heart_clockhand_sm64_material_002),
	gsSPDisplayList(heart_clockhand_Plane_mesh_tri_0),
	gsSPEndDisplayList(),
};

Gfx heart_clockhand_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

