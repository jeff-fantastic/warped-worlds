// sound_ambient.inc.c

void bhv_ambient_sounds_init(void) {
    switch (o->oBehParams2ndByte) {
        case 0:
            play_sound(SOUND_AIR_CASTLE_OUTDOORS_AMBIENT, gGlobalSoundSource);
            break;
        case 1:
            play_sound(SOUND_AIR_SHORE, gGlobalSoundSource);
            break;
    }
}
