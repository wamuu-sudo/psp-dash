#pragma once

void gfx_init();
void gfx_clear();
void gfx_flush();

void gfx_draw_title(const char* text, int x, int y);
void gfx_draw_label(const char* label, int x, int y);
void gfx_draw_value(int value, const char* unit, int x, int y);
void gfx_draw_bar(int x, int y, int value, int max);
