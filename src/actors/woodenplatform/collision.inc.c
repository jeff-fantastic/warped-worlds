const Collision woodenplatform_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(16),
	COL_VERTEX(-205, 27, -207),
	COL_VERTEX(-205, -23, 207),
	COL_VERTEX(-205, 27, 207),
	COL_VERTEX(-205, -23, -207),
	COL_VERTEX(205, 27, -207),
	COL_VERTEX(205, -23, -207),
	COL_VERTEX(205, 27, 207),
	COL_VERTEX(205, -23, 207),
	COL_VERTEX(184, -12, -186),
	COL_VERTEX(184, -12, 186),
	COL_VERTEX(184, -2325, 186),
	COL_VERTEX(184, -2325, -186),
	COL_VERTEX(-184, -12, -186),
	COL_VERTEX(-184, -2325, -186),
	COL_VERTEX(-184, -12, 186),
	COL_VERTEX(-184, -2325, 186),
	COL_TRI_INIT(SURFACE_DEFAULT, 20),
	COL_TRI(0, 1, 2),
	COL_TRI(1, 0, 3),
	COL_TRI(3, 4, 5),
	COL_TRI(5, 6, 7),
	COL_TRI(6, 5, 4),
	COL_TRI(7, 2, 1),
	COL_TRI(3, 0, 4),
	COL_TRI(7, 6, 2),
	COL_TRI(6, 4, 0),
	COL_TRI(6, 0, 2),
	COL_TRI(5, 7, 1),
	COL_TRI(5, 1, 3),
	COL_TRI(8, 9, 10),
	COL_TRI(8, 10, 11),
	COL_TRI(12, 8, 11),
	COL_TRI(12, 11, 13),
	COL_TRI(9, 14, 15),
	COL_TRI(9, 15, 10),
	COL_TRI(14, 12, 13),
	COL_TRI(14, 13, 15),
	COL_TRI_STOP(),
	COL_END()
};
