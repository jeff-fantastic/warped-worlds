// king_bobomb.c.inc

// Copy of geo_update_projectile_pos_from_parent
Gfx *geo_update_held_mario_pos(s32 run, UNUSED struct GraphNode *node, Mat4 mtx) {
    Mat4 sp20;
    struct Object *sp1C;

    if (run == TRUE) {
        sp1C = (struct Object *) gCurGraphNodeObject;
        if (sp1C->prevObj != NULL) {
            create_transformation_from_matrices(sp20, mtx, *gCurGraphNodeCamera->matrixPtr);
            obj_update_pos_from_parent_transformation(sp20, sp1C->prevObj);
            obj_set_gfx_pos_from_pos(sp1C->prevObj);
        }
    }
    return NULL;
}

static s32 cur_obj_play_sound_at_anim_range(s8 arg0, s8 arg1, u32 sound) {
    s32 val04;

    if ((val04 = o->header.gfx.animInfo.animAccel / 0x10000) <= 0) {
        val04 = 1;
    }

    if (cur_obj_check_anim_frame_in_range(arg0, val04) || cur_obj_check_anim_frame_in_range(arg1, val04)) {
        cur_obj_play_sound_2(sound);
        return TRUE;
    }

    return FALSE;
}

void bhv_bobomb_anchor_mario_loop(void) {
}

s32 bobomb_spawn_shockwave(void) {
    struct Object *wave;
    wave = spawn_object(o, MODEL_BOWSER_WAVE, bhvBowserShockWave);
    wave->oPosY = o->oFloorHeight;
    return 1;
}

// Prince Bob-omb is idle
void king_bobomb_act_0(void) {

    s32 type;
    type = (o->oBehParams >> 24) & 0xFF;

    if (type == 1) {
        o->oAction = 13;
    }

    if (o->oSubAction == 0) {
        // initialize prince
        cur_obj_become_intangible();
        gSecondCameraFocus = o;
        cur_obj_init_animation_with_sound(0);
        cur_obj_set_pos_to_home();
        o->oHealth = 3;
        // look for dialogue trigger
        if (o->oDistanceToMario < 1000.0f) {
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x240);
        } 
        if (cur_obj_can_mario_activate_textbox_2(400.0f, 100.0f)) {
            o->oSubAction++;
            seq_player_lower_volume(SEQ_PLAYER_LEVEL, 60, 40);
        }
    } else if (cur_obj_update_dialog_with_cutscene(2, 1, CUTSCENE_DIALOG, DIALOG_017)) {
        // begin fight
        o->oAction = 2;
        o->oFlags |= OBJ_FLAG_HOLDABLE;
    }
}

s32 mario_is_far_below_object(f32 arg0) {
    if (arg0 < o->oPosY - gMarioObject->oPosY) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// Charge up attack
void king_bobomb_act_2(void) {
    cur_obj_become_tangible();
    if (o->oPosY - o->oHomeY < -100.0f) { // Thrown off hill
        o->oAction = 5;
        cur_obj_become_intangible();
    }
    if (o->oKingBobombUnk100 == 0) { // play charge animation
        o->oForwardVel = 0.0f;
        cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x600);
        if (cur_obj_init_animation_and_check_if_near_end(1)) {
            o->oKingBobombUnk100++; 
        }       
    } else if (o->oKingBobombUnk100 == 1) {
        cur_obj_play_sound_2(SOUND_GENERAL_CASTLE_TRAP_OPEN);
        o->oAction = 1;
        o->oKingBobombUnk100 = 2;
    }
        
    if (o->oKingBobombUnk108 == 0) {

    } else {
        o->oForwardVel = 0.0f;
        o->oKingBobombUnk108--;
    }
    if (mario_is_far_below_object(300.0f)) {
        o->oAction = 0;
        stop_background_music(SEQUENCE_ARGS(4, SEQ_BOB_BOSS));
    }
}

void king_bobomb_act_3(void) {
    if (o->oSubAction == 0) {
        o->oForwardVel = 0;
        o->oKingBobombUnk104 = 0;
        o->oKingBobombUnkFC = 0;
        if (o->oTimer == 0)
            cur_obj_play_sound_2(SOUND_OBJ_UNKNOWN3);
        if (cur_obj_init_animation_and_check_if_near_end(0)) {
            o->oSubAction++;
            cur_obj_init_animation_and_anim_frame(1, 0);
        }
    } else {
        if (o->oSubAction == 1) {
            cur_obj_init_animation_with_sound(5);
            o->oKingBobombUnkFC += player_performed_grab_escape_action();
            print_debug_bottom_up("%d", o->oKingBobombUnkFC);
            if (o->oKingBobombUnkFC > 10) {
                o->oKingBobombUnk88 = 3;
                o->oAction = 12;
                o->oKingBobombUnk108 = 35;
                o->oInteractStatus &= ~(INT_STATUS_GRABBED_MARIO);
            } else {
                o->oForwardVel = 0.0f;
                if (o->oKingBobombUnk104 > 20 && cur_obj_rotate_yaw_toward(0, 0x400)) {
                    o->oSubAction++;
                    cur_obj_init_animation_and_anim_frame(9, 22);
                }
            }
            o->oKingBobombUnk104++;
        } else {
            cur_obj_init_animation_with_sound(9);
            if (cur_obj_check_anim_frame(31)) {
                o->oKingBobombUnk88 = 2;
                cur_obj_play_sound_2(SOUND_OBJ_UNKNOWN4);
            } else if (cur_obj_check_if_near_animation_end()) {
                o->oAction = 1;
                o->oInteractStatus &= ~(INT_STATUS_GRABBED_MARIO);
            }
        }
    }
}

void king_bobomb_act_1(void) {
    cur_obj_become_tangible();
    o->oDamageOrCoinValue = 4;
    o->oInteractType = 8;
    cur_obj_init_animation_with_sound(2);
    cur_obj_play_sound_at_anim_range(5, 15, SOUND_OBJ_POUNDING1_HIGHPRIO);
    if (o->header.gfx.animInfo.animFrame == 5 || o->header.gfx.animInfo.animFrame == 15) {
        spawn_object_relative_with_scale(0, 50, 0, 0, 3.0f, o, MODEL_SMOKE, bhvWhitePuffSmoke2);
        cur_obj_shake_screen(SHAKE_POS_SMALL);
    }
    o->oForwardVel = 50.0f;
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x100);
    if (o->oMoveFlags & OBJ_MOVE_HIT_EDGE) {
        o->oKingBobombUnk100 = 0;
        o->oInteractType = 2;
        o->oAction = 9;
    }
    if (mario_is_far_below_object(300.0f)) {
        o->oAction = 0;
        stop_background_music(SEQUENCE_ARGS(4, SEQ_BOB_BOSS));
    }
}

void king_bobomb_act_6(void) {
    if (o->oSubAction == 0) {
        if (o->oTimer == 0) {
            o->oKingBobombUnk104 = 0;
            cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB);
            cur_obj_play_sound_2(SOUND_OBJ2_KING_BOBOMB_DAMAGE);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            spawn_mist_particles_variable(0, 0, 100.0f);
            o->oInteractType = 8;
            cur_obj_become_tangible();
        }
        if (cur_obj_init_animation_and_check_if_near_end(7))
            o->oKingBobombUnk104++;
        if (o->oKingBobombUnk104 > 4) {
            o->oAction = 11;
        }
    } else {
        if (o->oSubAction == 1) {
            if (cur_obj_init_animation_and_check_if_near_end(7)) {
                o->oSubAction++;
                o->oInteractType = 2;
                cur_obj_become_intangible();
            }
        } else {
            cur_obj_init_animation_with_sound(5);
            if (cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x800) == 1)
                o->oAction = 2;
        }
    }
}

void king_bobomb_act_7(void) {
    cur_obj_init_animation_with_sound(7);
    if (cur_obj_update_dialog_with_cutscene(2, 2, CUTSCENE_DIALOG, DIALOG_116)) {
        cur_obj_become_intangible();
        cur_obj_shake_screen(SHAKE_POS_SMALL);
#ifndef VERSION_JP
        spawn_default_star(o->oHomeX, 6100.0f, o->oHomeZ);
#else
        o->oPosY += 100.0f;
        spawn_default_star(2000.0f, 4500.0f, -4500.0f);
#endif
        o->oAction = 8;
    }
}

void king_bobomb_act_8(void) {
    cur_obj_become_tangible();
    o->oDamageOrCoinValue = 0;
    o->oInteractType = 8;
    cur_obj_init_animation_with_sound(11);
    if (o->oTimer == 60)
        stop_background_music(SEQUENCE_ARGS(4, SEQ_BOB_BOSS));
}

void king_bobomb_act_9(void) {
    if (cur_obj_init_animation_and_check_if_near_end(3)) {
        o->oAction = 10;
    }
}

void king_bobomb_act_10(void) {
    if (cur_obj_init_animation_and_check_if_near_end(4)) {
        o->oAction = 2;
    }
}

void king_bobomb_act_4(void) { // bobomb been thrown
    if (o->oPosY - o->oHomeY > -100.0f) { // not thrown off hill
        if (o->oMoveFlags & OBJ_MOVE_LANDED) {
            o->oHealth--;
            o->oForwardVel = 0;
            o->oVelY = 0;
            cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB);
            if (o->oHealth)
                o->oAction = 6;
            else
                o->oAction = 7;
        }
    } else {
        spawn_mist_particles_variable(0, 0, 100.0f);
        o->oAction = 5; // Go back to top of hill
        o->oSubAction++;
    }
}

void king_bobomb_act_11(void) { // bobomb jumping attack
    if (cur_obj_init_animation_and_check_if_near_end(10)) {
        o->oAction = 12;
    }
}

u8 jumpCount;

void king_bobomb_act_12(void) {
    switch (o->oSubAction) {
        case 0:
            if (o->oKingBobombUnkF8 == 0)
                cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
            o->oInteractType = 8;
            o->oDamageOrCoinValue = 2;
            o->oKingBobombUnkF8 = 1;
            cur_obj_init_animation_and_extend_if_at_end(9);
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x800);
            arc_to_goal_pos(&gMarioObject->oPosX, &o->oPosX, 100.0f, -6.0f);
            o->oSubAction++;
            break;
        case 1:
            
            if (o->oVelY < 0 && o->oPosY < o->oHomeY) {
                if (jumpCount == 2) {
                    o->oNumLootCoins = 3;
                    obj_spawn_loot_yellow_coins(o, 3, 0.0f);
                }
                o->oPosY = o->oHomeY;
                o->oVelY = 0;
                o->oForwardVel = 0;
                o->oGravity = -4.0f;
                o->oKingBobombUnkF8 = 0;
                cur_obj_init_animation_with_sound(8);
                cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB);
                cur_obj_shake_screen(SHAKE_POS_MEDIUM);
                bobomb_spawn_shockwave();
                o->oSubAction++;
            }
            break;
        case 2:
            if (mario_is_far_below_object(300.0f)) {
                cur_obj_init_animation_with_sound(0);
                o->oAction = 0;
                stop_background_music(SEQUENCE_ARGS(4, SEQ_BOB_BOSS));
            }
            if (cur_obj_init_animation_and_check_if_near_end(8))
                if (jumpCount < 2) {
                    jumpCount++;
                    o->oSubAction = 0;
                } else {
                    o->oAction = 2;
                    jumpCount = 0;
                }
                
            break;
        case 3:
            if (mario_is_far_below_object(300.0f)) {
                cur_obj_init_animation_with_sound(0);
                o->oAction = 0;
                stop_background_music(SEQUENCE_ARGS(4, SEQ_BOB_BOSS));
            }
            if (cur_obj_can_mario_activate_textbox_2(400.0f, 100.0f))
                o->oSubAction++;
            break;
        case 4:
            if (cur_obj_update_dialog_with_cutscene(2, 1, CUTSCENE_DIALOG, DIALOG_128))
                o->oAction = 2;
            break;
    }
}

void king_bobomb_act_5(void) { // bobomb returns home
    switch (o->oSubAction) {
        case 0:
            if (o->oTimer == 0)
                cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
            o->oKingBobombUnkF8 = 1;
            cur_obj_init_animation_and_extend_if_at_end(9);
            o->oMoveAngleYaw =  cur_obj_angle_to_home();
            if (o->oPosY < o->oHomeY)
                o->oVelY = 100.0f;
            else {
                arc_to_goal_pos(&o->oHomeX, &o->oPosX, 100.0f, -4.0f);
                o->oSubAction++;
            }
            break;
        case 1:
            if (o->oVelY < 0 && o->oPosY < o->oHomeY) {
                o->oPosY = o->oHomeY;
                o->oVelY = 0;
                o->oForwardVel = 0;
                o->oGravity = -4.0f;
                o->oKingBobombUnkF8 = 0;
                cur_obj_init_animation_with_sound(8);
                cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB);
                cur_obj_shake_screen(SHAKE_POS_SMALL);
                bobomb_spawn_shockwave();
                o->oSubAction++;
            }
            break;
        case 2:
            if (cur_obj_init_animation_and_check_if_near_end(8))
                o->oSubAction++;
            break;
        case 3:
            if (mario_is_far_below_object(300.0f)) {
                cur_obj_init_animation_with_sound(0);
                o->oAction = 0;
                stop_background_music(SEQUENCE_ARGS(4, SEQ_BOB_BOSS));
            } else {
                o->oAction = 2;
            }
            break;
        case 4:
            if (cur_obj_update_dialog_with_cutscene(2, 1, CUTSCENE_DIALOG, DIALOG_128))
                o->oAction = 2;
            break;
    }
}

void king_bobomb_act_13(void) {

    cur_obj_become_tangible();
    cur_obj_init_animation_with_sound(0);
    o->oInteractionSubtype |= INT_SUBTYPE_NPC;
    o->oInteractType = INTERACT_TEXT;
    o->hitboxRadius = 200;

    if (o->oDistanceToMario < 1000.0f) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x240);
    }

    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        o->oAction = 14;
    }

}

void king_bobomb_act_14(void) {
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x240);
    if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
        o->oAction = 15;
    }
}

void king_bobomb_act_15(void) {
    if (set_mario_npc_dialog(1) == 2) {
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, o->oBehParams2ndByte)) {
            set_mario_npc_dialog(0);

            o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
            o->oInteractStatus = 0;
            o->oAction = 13;
        }
    }
}

void (*sKingBobombActions[])(void) = {
    king_bobomb_act_0, king_bobomb_act_1, king_bobomb_act_2, king_bobomb_act_3, king_bobomb_act_4,
    king_bobomb_act_5, king_bobomb_act_6, king_bobomb_act_7, king_bobomb_act_8, king_bobomb_act_9,
    king_bobomb_act_10, king_bobomb_act_11, king_bobomb_act_12, king_bobomb_act_13, king_bobomb_act_14,
    king_bobomb_act_15

};
struct SoundState sKingBobombSoundStates[] = {
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
};

void king_bobomb_move(void) {
    cur_obj_update_floor_and_walls();
    if (o->oKingBobombUnkF8 == 0)
        cur_obj_move_standard(-78);
    else
        cur_obj_move_using_fvel_and_gravity();
    cur_obj_call_action_function(sKingBobombActions);
    exec_anim_sound_state(sKingBobombSoundStates);
    if (o->oDistanceToMario < 5000.0f)
        cur_obj_enable_rendering();
    else
        cur_obj_disable_rendering();
}

void bhv_king_bobomb_loop(void) {
    f32 sp34 = 20.0f;
    f32 sp30 = 50.0f;
    UNUSED u8 pad[8];
    o->oInteractionSubtype |= INT_SUBTYPE_HEAVY;
    switch (o->oHeldState) {
        case HELD_FREE:
            king_bobomb_move();
            break;
        case HELD_HELD:
            cur_obj_unrender_and_reset_state(5, 1);
            break;
        case HELD_THROWN:
        case HELD_DROPPED:
            cur_obj_get_thrown_or_placed(sp34, sp30, 4);
            cur_obj_become_intangible();
            o->oPosY += 20.0f;
            break;
    }
    o->oInteractStatus = 0;
}
