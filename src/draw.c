#include "display.h"
#include "draw.h"

void set_pixel(int x, int y, int c) {
    frame_buffer[x + y * SCREEN_WIDTH] = c;
}

int get_pixel(int x, int y) {
    return frame_buffer[x + y * SCREEN_WIDTH];
}

void line_h (int x1, int x2, int y, unsigned char color) {
    int offset = (y << 8) + (y << 6) + x1; // y * 320 + x1
    for (int x = x1; x <= x2; x++) frame_buffer[offset++] = color;
}

void line_v (int x, int y1, int y2, unsigned char color) {
    int offset = (y1 << 8) + (y1 << 6) + x; // y * 320 + x1
    for (int y = y1; y <= y2; y++, offset += SCREEN_WIDTH) frame_buffer[offset] = color;
}
