
/**
 * Behavior for bhvTTCRotatingSolid, which are the rotating cube and triangular
 * prism.
 */

/**
 * Init function for bhvTTCRotatingSolid.
 */
void bhv_spinning_cog_init(void) {
    o->oAngleVelYaw = 0x150;
}

/**
 * Update function for bhvTTCRotatingSolid.
 * Wait a bit, dip down and back up, play a sound, then rotate.
 */
//void bhv_spinning_cog_update(void) {
    // Rotate
//    o->oFaceAngleYaw += o->oAngleVelYaw;
//    load_object_collision_model();
//}

void bhv_spinning_cog_update(void) {
    cur_obj_play_sound_1(SOUND_ENV_ELEVATOR2);
    cur_obj_rotate_face_angle_using_vel();
}