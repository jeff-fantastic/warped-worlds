void scroll_wmotr_dl_Plane_002_mesh_vtx_0() {
	int i = 0;
	int count = 317;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Plane_002_mesh_vtx_0);

	deltaX = (int)(0.15000000596046448 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(0.15000000596046448 * 0x20 * random_float() * random_sign()) % height;

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
void scroll_wmotr_dl_Plane_002_mesh_vtx_1() {
	int i = 0;
	int count = 248;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Plane_002_mesh_vtx_1);

	deltaX = (int)(0.10000000149011612 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(0.10000000149011612 * 0x20 * random_float() * random_sign()) % height;

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
void scroll_wmotr_dl_Plane_002_mesh_vtx_2() {
	int i = 0;
	int count = 175;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Plane_002_mesh_vtx_2);

	deltaX = (int)(0.15000000596046448 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(0.15000000596046448 * 0x20 * random_float() * random_sign()) % height;

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
void scroll_wmotr_dl_Plane_006_mesh_vtx_0() {
	int i = 0;
	int count = 16;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.5;
	float frequencyX = 0.05000000074505806;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Plane_006_mesh_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(1.0 * 0x20) % height;

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
	timeX += 1;
	currentY += deltaY;

}
void scroll_wmotr_dl_Plane_011_mesh_vtx_1() {
	int i = 0;
	int count = 12;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.5;
	float frequencyX = 0.05000000074505806;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Plane_011_mesh_vtx_1);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(1.0 * 0x20) % height;

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
	timeX += 1;
	currentY += deltaY;

}
void scroll_wmotr() {
	scroll_wmotr_dl_Plane_002_mesh_vtx_0();
	scroll_wmotr_dl_Plane_002_mesh_vtx_1();
	scroll_wmotr_dl_Plane_002_mesh_vtx_2();
	scroll_wmotr_dl_Plane_006_mesh_vtx_0();
	scroll_wmotr_dl_Plane_011_mesh_vtx_1();
}
