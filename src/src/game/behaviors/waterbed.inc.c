//waterbed.inc.c

void bhv_waterbed_loop(void) {
    o->oPosY = o->oHomeY + sinf(gGlobalTimer/16.0f) * 25;
}

void bhv_bobbing_platform_loop(void) {
    switch (o->oBehParams2ndByte) {
        case 0:
            o->oPosY = o->oHomeY + sinf(gGlobalTimer/24.0f) * 50;
            break;
        case 1:
            o->oPosY = o->oHomeY - sinf(gGlobalTimer/24.0f) * 50;
            break;
    }
}