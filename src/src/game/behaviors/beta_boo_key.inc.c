
/**
 * Behavior for bhvAlphaBooKey and bhvBetaBooKey.
 * They were apparently intended to be a key that would be contained in boos
 * and would fall out, like coins do. There is a model, MODEL_BETA_BOO_KEY, that
 * is loaded in script_func_global_10, which contains boo-themed models used in
 * BBH and the castle courtyard. It is used in a macro preset with bhvAlphaBooKey,
 * which is also grouped near other boo/BBH-related macros. This is evidence that
 * bhvAlphaBooKey was supposed to be a key. bhvBetaBooKey has code similar to
 * bhvAlphaBooKey's for rotation and collection, and functions correctly when
 * spawned as a child of a boo (it checks the death status of the boo to know when
 * to drop, so this is almost definitely what was intended). It appears that
 * bhvAlphaBooKey was abandoned for reasons unknown and replaced with bhvBetaBooKey.
 */

/**
 * Update function for bhvAlphaBooKey.
 * It rotates the key, and deletes it when collected.
 * The code in this function is similar to that found in
 * bhvBetaBooKey code, which implies that these are 2 versions
 * of the same object. It is a less developed version of
 * bhvBetaBooKey, hence the "alpha" moniker.
 */

int startY;
int sparkleTimer = 0;

struct ObjectHitbox sKeyHitbox = {
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 1,
    /* radius: */ 100,
    /* height: */ 64,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

void bhv_key_init(void) {
    if (gCurrLevelNum == LEVEL_WF && gMarioState->numKeys == 1) {
        obj_mark_for_deletion(o);
    }
    cur_obj_set_behavior(bhvBetaBooKey);
    obj_set_hitbox(o, &sKeyHitbox);
    cur_obj_become_intangible();
    startY = o->oPosY;
}

void bhv_alpha_boo_key_loop(void) {
    // Rotate the key
    o->oFaceAngleRoll += 0x200;
    o->oFaceAngleYaw += 0x200;


    if (obj_check_if_collided_with_object(o, gMarioObject)) {
        // This line makes the object inside the key's parent boo drop.
        // Was this intended to make the boo die when the key is collected?
        // Boos don't read from oBooDeathStatus, they only set it to let the
        // objects inside them know when to drop.
        // Due to this line, the key will cause the game to crash if collected
        // when its parent object is NULL.
        // Another theory is that the boo key was intended to be spawned by a
        // spawner that used object field 0x00 for something else. This
        // is elaborated on more in beta_boo_key_dropped_loop.
        o->parentObj->oBooDeathStatus = BOO_DEATH_STATUS_DYING;

        // Delete the object and spawn sparkles
        obj_mark_for_deletion(o);
        spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
    }
}

// For some reason, the action functions for the beta boo key
// are written in reverse order.

/**
 * Update function for bhvBetaBooKey.
 */
void bhv_beta_boo_key_loop(void) {
    cur_obj_become_tangible();
    // floating movement
    o->oPosY = startY + 25.0f * sinf(gGlobalTimer / 16.0f);
    sparkleTimer++;
    // collecting
    if (obj_check_if_collided_with_object(o, gMarioObject)) {
        play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
        obj_mark_for_deletion(o);
    }
    // sparkles handler
    if (sparkleTimer == 15) {
        struct Object *sp2C;
        f32 sp24 = 32.0f;
        sp2C = spawn_object(o, MODEL_SPARKLES, bhvCoinSparkles);
        sp2C->oPosX += (random_float() * sp24) / 2;
        sp2C->oPosZ += (random_float() * sp24) / 4;
        sparkleTimer = 0;
    }
    o->oInteractStatus = 0;
}
