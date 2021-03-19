#include "types.h"
#include "include/segment_symbols.h"
#include "memory.h"
#include "engine/math_util.h"
#include "src/engine/behavior_script.h"
#include "texscroll.h"

#ifdef TARGET_N64
#define SCROLL_CONDITION(condition) condition
#else
#define SCROLL_CONDITION(condition) 1
#endif


#include "src/game/texscroll/wf_texscroll.inc.c"
#include "src/game/texscroll/sa_texscroll.inc.c"
#include "src/game/texscroll/castle_grounds_texscroll.inc.c"
#include "src/game/texscroll/common1_texscroll.inc.c"
#include "src/game/texscroll/bob_texscroll.inc.c"
#include "src/game/texscroll/castle_courtyard_texscroll.inc.c"
#include "src/game/texscroll/totwc_texscroll.inc.c"
#include "src/game/texscroll/pss_texscroll.inc.c"
#include "src/game/texscroll/wmotr_texscroll.inc.c"
void scroll_textures() {
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_wf_segment_7SegmentRomStart)) {
		scroll_textures_wf();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_sa_segment_7SegmentRomStart)) {
		scroll_textures_sa();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_castle_grounds_segment_7SegmentRomStart)) {
		scroll_textures_castle_grounds();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x3] == (uintptr_t)_common1_mio0SegmentRomStart)) {
		scroll_textures_common1();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bob_segment_7SegmentRomStart)) {
		scroll_textures_bob();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_castle_courtyard_segment_7SegmentRomStart)) {
		scroll_textures_castle_courtyard();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_totwc_segment_7SegmentRomStart)) {
		scroll_textures_totwc();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_pss_segment_7SegmentRomStart)) {
		scroll_textures_pss();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_wmotr_segment_7SegmentRomStart)) {
		scroll_textures_wmotr();
	}

}
