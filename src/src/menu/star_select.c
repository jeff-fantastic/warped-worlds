#include "src/game/texscroll.h"
#include <PR/ultratypes.h>

#include "audio/external.h"
#include "behavior_data.h"
#include "engine/behavior_script.h"
#include "engine/graph_node.h"
#include "eu_translation.h"
#include "game/area.h"
#include "game/game_init.h"
#include "game/ingame_menu.h"
#include "game/level_update.h"
#include "game/memory.h"
#include "game/object_helpers.h"
#include "game/object_list_processor.h"
#include "game/print.h"
#include "game/save_file.h"
#include "game/segment2.h"
#include "game/segment7.h"
#include "game/rumble_init.h"
#include "sm64.h"
#include "src/game/main.h"
#include "star_select.h"
#include "text_strings.h"
#include "prevent_bss_reordering.h"

/**
 * @file star_select.c
 * This file implements how the star select screen (act selector) function.
 * That includes handles what stars can be selected, star selector types,
 * strings, act values, and star selector model rendering if a star is collected or not.
 */

// Star Selector count models printed in the act selector menu.
static struct Object *sStarSelectorModels[8];

// The act the course is loaded as, affects whether some objects spawn.
static s8 sLoadedActNum;

// Number of obtained stars, excluding the coin star.
static u8 sObtainedStars;

// Total number of stars that appear in the act selector menu.
static s8 sVisibleStars;

// Act selected when the act menu is first opened.
static u8 sInitSelectedActNum;

// Index value of the act selected in the act menu.
int sSelectedActIndex = 0;

// Index value of the star that is selectable in the act menu.
// Excluding the next star, it doesn't count other transparent stars.
static s8 sSelectableStarIndex = 1;

// Act Selector menu timer that keeps counting until you choose an act.
static s32 sActSelectorMenuTimer = 0;

// Star animation timer to slow down speed
s8 starAnimationTimer = 0;

int menuAmp = 500;
int joyDelay;
int menuSort;
int menuCarosuelActive = 1;
int menuMove;
int menuMoveDelay;
int sSelectedStarCache = 1;
int spookNum;

/**
 * Act Selector Star Type Loop Action
 * Defines a select type for a star in the act selector.
 */
void bhv_act_selector_star_type_loop(void) {

    // Star positions 
    gCurrentObject->oPosZ = cosf(gCurrentObject->oStarCurrentTime/6.3f) * menuAmp;
    gCurrentObject->oPosX = sinf(gCurrentObject->oStarCurrentTime/6.3f) * menuAmp;
    gCurrentObject->oPosY = -500.0;

    // Tweening formula
    gCurrentObject->oStarCurrentTime = gCurrentObject->oStarCurrentTime + (gCurrentObject->oStarTargetTime - gCurrentObject->oStarCurrentTime) * 0.1f;
    

    if (menuMove == 1) {
        gCurrentObject->oStarTargetTime -= 6.5f;
        menuMoveDelay++;
        if (menuMoveDelay >= sVisibleStars) {
            if (sSelectedStarCache > sSelectedActIndex + 1) {
                sSelectedStarCache--;
            } else if (sSelectedStarCache < sSelectedActIndex + 1) {
                sSelectedStarCache++;
            } 
            if (sSelectedStarCache == sSelectedActIndex + 1) {
                menuMove = 0; 
            }
            menuMoveDelay = 0;
        }
    } else if (menuMove == -1) {
        gCurrentObject->oStarTargetTime += 6.5f;
        menuMoveDelay++;
        if (menuMoveDelay >= sVisibleStars) {
            if (sSelectedStarCache > sSelectedActIndex + 1) {
                sSelectedStarCache--;
            } else if (sSelectedStarCache < sSelectedActIndex + 1) {
                sSelectedStarCache++;
            } 
            if (sSelectedStarCache == sSelectedActIndex + 1) {
                menuMove = 0; 
            }
            menuMoveDelay = 0;
        }
    }

    switch (gCurrentObject->oStarSelectorType) {
        starAnimationTimer += 1;
        // If a star is not selected, don't rotate or change size
        case STAR_SELECTOR_NOT_SELECTED:
            if (gCurrentObject->oStarSelectorSize > 1.0) {
                gCurrentObject->oStarSelectorSize -= 0.05;
            }
            gCurrentObject->oFaceAngleRoll = 0;
            gCurrentObject->oAnimState = -1;
            break;
        // If a star is selected, rotate and slightly increase size
        case STAR_SELECTOR_SELECTED:
            gCurrentObject->oStarSelectorSize += 0.05;
            if (gCurrentObject->oStarSelectorSize > 1.3) {
                gCurrentObject->oStarSelectorSize = 1.3;
            }
            gCurrentObject->oFaceAngleRoll = 180.0 + 500.0 * sinf(gGlobalTimer / 16.0);
            if (starAnimationTimer <= 1) {
                gCurrentObject->oAnimState += 1;
            }
            if (starAnimationTimer >= 10) {
                starAnimationTimer = 0;
            }

            break;
    }

    // Scale act selector stars depending of the type selected
    cur_obj_scale(gCurrentObject->oStarSelectorSize);
    // Unused timer, only referenced here. Probably replaced by sActSelectorMenuTimer
    gCurrentObject->oStarSelectorTimer++;
}

/**
 * Renders the 100 coin star with an special star selector type.
 */
void render_100_coin_star(u8 stars) {
    if (stars & (1 << 6)) {
        // If the 100 coin star has been collected, create a new star selector next to the coin score.
        sStarSelectorModels[6] = spawn_object_abs_with_rot(gCurrentObject, 0, MODEL_STAR,
                                                        bhvActSelectorStarType, 0, 60, -300, 0, 0, 0);
        sStarSelectorModels[6]->oStarSelectorSize = 0.8;
        sStarSelectorModels[6]->oStarSelectorType = STAR_SELECTOR_100_COINS;
    }
}

u8 menuHoldKeyTimer = 0;
u8 menuHoldKeyIndex = 0;

void handle_menu_scrolling2(s8 scrollDirection, s8 *currentIndex, s8 minIndex, s8 maxIndex) {
    u8 index = 0;

    if (scrollDirection == MENU_SCROLL_VERTICAL) {
        if (gPlayer1Controller->rawStickY > 60) {
            index++;
        }

        if (gPlayer1Controller->rawStickY < -60) {
            index += 2;
        }
    } else if (scrollDirection == MENU_SCROLL_HORIZONTAL) {
        if (gPlayer1Controller->rawStickX > 60) {
            index += 2;
        }

        if (gPlayer1Controller->rawStickX < -60) {
            index++;
        }
    }

    if (((index ^ menuHoldKeyIndex) & index) == 2) {
        if (currentIndex[0] == maxIndex) {
            //! Probably originally a >=, but later replaced with an == and an else statement.
            currentIndex[0] = maxIndex;
        } else {
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
            menuMove = 1;
            currentIndex[0]++;
        }
    }

    if (((index ^ menuHoldKeyIndex) & index) == 1) {
        if (currentIndex[0] == minIndex) {
            // Same applies to here as above
        } else {
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
            menuMove = -1;
            currentIndex[0]--;
        }
    }

    if (menuHoldKeyTimer == 10) {
        menuHoldKeyTimer = 8;
        menuHoldKeyIndex = 0;
    } else {
        menuHoldKeyTimer++;
        menuHoldKeyIndex = index;
    }

    if ((index & 3) == 0) {
        menuHoldKeyTimer = 0;
    }
}

/**
 * Act Selector Init Action
 * Checks how many stars has been obtained in a course, to render
 * the correct star models, the 100 coin star and also handles
 * checks of what star should be next in sInitSelectedActNum.
 */
void bhv_act_selector_init(void) {
    s16 i = 0;
    s32 selectorModelIDs[10];
    u8 stars = save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum - 1);


    sVisibleStars = 0;
    while (i != sObtainedStars) {
        if (stars & (1 << sVisibleStars)) { // Star has been collected
            selectorModelIDs[sVisibleStars] = MODEL_STAR;
            i++;
        } else { // Star has not been collected
            selectorModelIDs[sVisibleStars] = MODEL_TRANSPARENT_STAR;
            // If this is the first star that has not been collected, set
            // the default selection to this star.
            if (sInitSelectedActNum == 0) {
                sInitSelectedActNum = sVisibleStars + 1;
                sSelectableStarIndex = 0;
            }
        }
        sVisibleStars++;
    }

    // If the stars have been collected in order so far, show the next star.
    if (sVisibleStars == sObtainedStars && sVisibleStars != 6) {
        selectorModelIDs[sVisibleStars] = MODEL_TRANSPARENT_STAR;
        sInitSelectedActNum = sVisibleStars + 1;
        sSelectableStarIndex = 0;
        sVisibleStars++;
    }

    // If all stars have been collected, set the default selection to the last star.
    if (sObtainedStars == 6) {
        sInitSelectedActNum = sVisibleStars;
        sSelectableStarIndex = 0;
    }

    //! Useless, since sInitSelectedActNum has already been set in this
    //! scenario by the code that shows the next uncollected star.
    if (sObtainedStars == 0) {
        sInitSelectedActNum = 1;
    }

    

    // Render star selector objects
    for (i = 0; i < sVisibleStars; i++) {
        sStarSelectorModels[i] =
            spawn_object_abs_with_rot(gCurrentObject, 0, selectorModelIDs[i], bhvActSelectorStarType,
                                      0, 0, 0, 0, 0, 0);
        sStarSelectorModels[i]->oStarSelectorSize = 1.0f;
        sStarSelectorModels[i]->oStarID = i + 1;
        sStarSelectorModels[i]->oStarTargetTime += 6.5f * i;
    }

    render_100_coin_star(stars);

}

/**
 * Act Selector Loop Action
 * Handles star selector scrolling depending of what stars are
 * selectable, whenever all 6 stars are obtained or not.
 * Also handles 2 star selector types whenever the star is selected
 * or not, the types are defined in bhv_act_selector_star_type_loop.
 */
void bhv_act_selector_loop(void) {
    s8 i;
    u8 starIndexCounter;
    u8 stars = save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum - 1);

    if (sObtainedStars != 6) {
        // Sometimes, stars are not selectable even if they appear on the screen.
        // This code filters selectable and non-selectable stars.
        sSelectedActIndex = 0;
        handle_menu_scrolling2(MENU_SCROLL_HORIZONTAL, &sSelectableStarIndex, 0, sObtainedStars);
        starIndexCounter = sSelectableStarIndex;
        for (i = 0; i < sVisibleStars; i++) {
            // Can the star be selected (is it either already completed or the first non-completed mission)
            if ((stars & (1 << i)) || i + 1 == sInitSelectedActNum) {
                if (starIndexCounter == 0) { // We have reached the sSelectableStarIndex-th selectable star.
                    sSelectedActIndex = i;
                    break;
                }
                starIndexCounter--;
            }
        }
    } else {
        // If all stars are collected then they are all selectable.
        handle_menu_scrolling2(MENU_SCROLL_HORIZONTAL, &sSelectableStarIndex, 0, sVisibleStars - 1);
        sSelectedActIndex = sSelectableStarIndex;
    }

    // Star selector type handler
    for (i = 0; i < sVisibleStars; i++) {
        if (sSelectedActIndex == i) {
            sStarSelectorModels[i]->oStarSelectorType = STAR_SELECTOR_SELECTED;
        } else {
            sStarSelectorModels[i]->oStarSelectorType = STAR_SELECTOR_NOT_SELECTED;
        }
    }
}


unsigned char randomCharacters[] = {
	TEXT_VALID_CHARS
};
/**
 * Print act selector strings, some with special checks.
 */
void print_act_selector_strings(void) {
    unsigned char starMission1[] = { TEXT_MISSION1 };
    unsigned char starMission2[] = { TEXT_MISSION2 };
    unsigned char starMission3[] = { TEXT_MISSION3 };
    unsigned char starMission4[] = { TEXT_MISSION4 };
    unsigned char starMission5[] = { TEXT_MISSION5 };
    unsigned char starMission6[] = { TEXT_MISSION6 };
    u8 **levelNameTbl = segmented_to_virtual(seg2_course_name_table);
    u8 *currLevelName = segmented_to_virtual(levelNameTbl[gCurrCourseNum - 1]);
    u8 **actNameTbl = segmented_to_virtual(seg2_act_name_table);
    u8 *selectedActName;

    create_dl_ortho_matrix();

    // Print the coin highscore.
    //gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    //gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    //print_hud_my_score_coins(1, gCurrSaveFileNum - 1, gCurrCourseNum - 1, 150, 174);
    //gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 254, 254, 254, 255);

    if (aiModeSeed[2] <= 3) {	
        // Random character gen by iProgramInCPP
        unsigned char text[46];
		int i, randomLength;

        // Generated string will be 15-45 characters long.
		randomLength = 25 + (random_u16()%10);

        // Terminator
		text[randomLength]=0xFF;

        // For each character in the string...
		for (i=0; i<randomLength; i++) {
			text[i] = randomCharacters[random_u16()%64]; // Get a random character from the list of valid chars, length of TEXT_VALID_CHARS is 64.
		}
        print_generic_string(get_str_x_pos_from_center(160, text, 10.0f), 200, text); // Print the random string
    } else {
        print_generic_string(get_str_x_pos_from_center(160, currLevelName + 3, 10.0f), 200, currLevelName + 3);
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 254, 254, 254, 255);
    // Print the name of the selected act.
    if (sVisibleStars != 0) {
        selectedActName = segmented_to_virtual(actNameTbl[(gCurrCourseNum - 1) * 6 + sSelectedActIndex]);
        print_menu_generic_string(get_str_x_pos_from_center(160, selectedActName, 8.0f), 190, selectedActName);
        switch (sSelectedActIndex + 1) {
            case 1:
                print_menu_generic_string(get_str_x_pos_from_center(160, starMission1, 8.0f), 180, starMission1);
                break;
            case 2:
                print_menu_generic_string(get_str_x_pos_from_center(160, starMission2, 8.0f), 180, starMission2);
                break;
            case 3:
                print_menu_generic_string(get_str_x_pos_from_center(160, starMission3, 8.0f), 180, starMission3);
                break;
            case 4:
                print_menu_generic_string(get_str_x_pos_from_center(160, starMission4, 8.0f), 180, starMission4);
                break;
            case 5:
                print_menu_generic_string(get_str_x_pos_from_center(160, starMission5, 8.0f), 180, starMission5);
                break;
            case 6:
                print_menu_generic_string(get_str_x_pos_from_center(160, starMission6, 8.0f), 180, starMission6);
                break;
        }
    }
    gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_end);
 }

/**
 * Geo function that Print act selector strings.
 *!@bug: This geo function is missing the third param. Harmless in practice due to o32 convention.
 */
#ifdef AVOID_UB
Gfx *geo_act_selector_strings(s16 callContext, UNUSED struct GraphNode *node, UNUSED void *context) {
#else
Gfx *geo_act_selector_strings(s16 callContext, UNUSED struct GraphNode *node) {
#endif
    if (callContext == GEO_CONTEXT_RENDER) {
        print_act_selector_strings();
    }
    return NULL;
}

/**
 * Initiates act selector values before entering a main course.
 * Also load how much stars a course has, without counting the 100 coin star.
 */
s32 lvl_init_act_selector_values_and_stars(UNUSED s32 arg, UNUSED s32 unused) {
    u8 stars = save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum - 1);

    sLoadedActNum = 0;
    sInitSelectedActNum = 0;
    sVisibleStars = 0;
    sActSelectorMenuTimer = 0;
    sObtainedStars = save_file_get_course_star_count(gCurrSaveFileNum - 1, gCurrCourseNum - 1);

    // Don't count 100 coin star
    if (stars & (1 << 6)) {
        sObtainedStars--;
    }

    //! no return value
#ifdef AVOID_UB
    return 0;
#endif
}

/**
 * Loads act selector button actions with selected act value checks.
 * Also updates objects and returns act number selected after is chosen.
 */
s32 lvl_update_obj_and_load_act_button_actions(UNUSED s32 arg, UNUSED s32 unused) {
    if (sActSelectorMenuTimer >= 11) {
        // If any of these buttons are pressed, play sound and go to course act
#ifndef VERSION_EU
        if ((gPlayer3Controller->buttonPressed & A_BUTTON)
         || (gPlayer3Controller->buttonPressed & START_BUTTON)
         || (gPlayer3Controller->buttonPressed & B_BUTTON)) {
#else
        if ((gPlayer3Controller->buttonPressed & (A_BUTTON | START_BUTTON | B_BUTTON | Z_TRIG))) {
#endif
#if defined(VERSION_JP)
            play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
#else
            play_sound(SOUND_MENU_STAR_SOUND_LETS_A_GO, gGlobalSoundSource);
#endif
#ifdef VERSION_SH
            queue_rumble_data(60, 70);
            func_sh_8024C89C(1);
#endif
            if (sInitSelectedActNum >= sSelectedActIndex + 1) {
                sLoadedActNum = sSelectedActIndex + 1;
            } else {
                sLoadedActNum = sInitSelectedActNum;
            }
            gDialogCourseActNum = sSelectedActIndex + 1;
        }
    }

    area_update_objects(); scroll_textures();
    sActSelectorMenuTimer++;
    return sLoadedActNum;
}
