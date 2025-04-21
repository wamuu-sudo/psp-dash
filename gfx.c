#include <pspgu.h>
#include <pspdisplay.h>
#include <pspdebug.h>
#include <stdio.h>
#include "gfx.h"

void gfx_init() {
    pspDebugScreenSetBackColor(0x000000);
    pspDebugScreenSetTextColor(0xFFFFFF);
    pspDebugScreenClear();
}

void gfx_clear() {
    pspDebugScreenSetXY(0, 0);
    pspDebugScreenClear();
}

void gfx_flush() {
    sceDisplayWaitVblankStart();
}

void gfx_draw_title(const char* text, int x, int y) {
    pspDebugScreenSetXY(x / 8, y / 8);
    pspDebugScreenSetTextColor(0x00FFFF);
    pspDebugScreenPrintf("%s", text);
}

void gfx_draw_label(const char* label, int x, int y) {
    pspDebugScreenSetXY(x / 8, y / 8);
    pspDebugScreenSetTextColor(0x00FF00);
    pspDebugScreenPrintf("%s:", label);
}

void gfx_draw_value(int value, const char* unit, int x, int y) {
    pspDebugScreenSetXY(x / 8, y / 8);
    pspDebugScreenSetTextColor(0xFFFFFF);
    pspDebugScreenPrintf("%d %s", value, unit);
}



void gfx_draw_bar(int x, int y, int value, int max) {
    int width = 40;
    int filled = (value * width) / max;
    if (filled > width) filled = width;

    pspDebugScreenSetXY(x / 8, y / 8);
    pspDebugScreenSetTextColor(0x00FF00);
    for (int i = 0; i < filled; i++) {
        pspDebugScreenPrintf("|");
    }

    pspDebugScreenSetTextColor(0x444444);
    for (int i = filled; i < width; i++) {
        pspDebugScreenPrintf(".");
    }
}

