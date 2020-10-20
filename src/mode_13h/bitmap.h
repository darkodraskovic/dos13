#ifndef BITMAP_H
#define BITMAP_H

#include "display.h"

typedef struct {
    word width;
    word height;
    byte* data;
} bitmap;

void load_bitmap(char *file, bitmap *bmp, byte *palette);
void draw_bitmap(bitmap *bmp, int x, int y);
void draw_bitmap_transparent(bitmap *bmp,int x,int y);
void screen_to_bitmap(int x1, int y1, int x2, int y2, bitmap* bmp);
    
#endif /* BITMAP_H */
