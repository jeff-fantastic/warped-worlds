void scroll_evilheart_Sphere_mesh_vtx_0() {
	int i = 0;
	int count = 103;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(evilheart_Sphere_mesh_vtx_0);

	deltaX = (int)(1.0 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(1.0 * 0x20 * random_float() * random_sign()) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;
	currentY += deltaY;

}
void scroll_actor_geo_evilheart() {
	scroll_evilheart_Sphere_mesh_vtx_0();
}
