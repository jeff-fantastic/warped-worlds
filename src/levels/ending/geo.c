#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"

#include "game/level_geo.h"
#include "game/geo_misc.h"
#include "game/camera.h"
#include "game/moving_texture.h"
#include "game/screen_transition.h"
#include "game/paintings.h"

#include "make_const_nonconst.h"
#include "menu/level_select_menu.h"

#include "levels/ending/header.h"

// 0x0E000050
const GeoLayout ending_geo_000050[] = {
   GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
   GEO_OPEN_NODE(),
      GEO_ZBUFFER(0),
      GEO_OPEN_NODE(),
         GEO_NODE_ORTHO(100),
         GEO_OPEN_NODE(),
#ifdef VERSION_EU
            GEO_BACKGROUND_COLOR(0x0001),
#endif
            GEO_BACKGROUND_COLOR(0x0001),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(1),
      GEO_OPEN_NODE(),
         GEO_CAMERA_FRUSTUM(45, 128, 16384),
         GEO_OPEN_NODE(),
            GEO_CAMERA(0, 0, 200, 1000, 0, -200, 0, 0x00000000),
            GEO_OPEN_NODE(),
               GEO_RENDER_OBJ(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(2),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_error_strings),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

