// weak_scaffold.inc.c

void bhv_weak_scaffold_loop(void) {
    if (cur_obj_was_attacked() != 0) {
        obj_explode_and_spawn_coins(80.0f, 0);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
        play_puzzle_jingle();
    }
}
