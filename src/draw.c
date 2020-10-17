#include <stdlib.h>
#include "display.h"
#include "draw.h"

#define SET_PIXEL_XY(x, y, c) frame_buffer[x + y * SCREEN_WIDTH] = c
#define GET_PIXEL_XY(x, y) frame_buffer[x + y * SCREEN_WIDTH]
#define SET_PIXEL_OFF(offset, c) frame_buffer[offset] = c
#define GET_PIXEL_OFF(offset) frame_buffer[offset]

void set_pixel(int x, int y, unsigned char color) {
    SET_PIXEL_XY(x, y, color);
}

unsigned char get_pixel(int x, int y) {
    return GET_PIXEL_XY(x, y);
}

void line_h (int x1, int y, int x2, unsigned char color) {
    int offset = (y << 8) + (y << 6) + x1; // y * 320 + x1
    for (int x = x1; x <= x2; x++) SET_PIXEL_OFF(offset++, color);
}

void line_v (int x, int y1, int y2, unsigned char color) {
    int offset = (y1 << 8) + (y1 << 6) + x; // y * 320 + x1
    for (int y = y1; y <= y2; y++, offset += SCREEN_WIDTH) SET_PIXEL_OFF(offset, color);
}

void line (int x1, int y1, int x2, int y2, unsigned char color)
{
    int x, y, delta_x, delta_y, d, incr_same, incr_new, temp;

    delta_x = x2 - x1;
    delta_y = y2 - y1;

    if (delta_x == 0) {
        line_v (x1, y1, y2, color);
        return;
    } else if (delta_y == 0) {
        line_h (x1, y1, x2, color);
        return;
    }

    if (abs(delta_x) >= abs(delta_y)) {       // if x is the major axis
        if (x2 < x1) {                // if coordinates are out of order
            temp = x2;
            x2 = x1;
            x1 = temp;
            delta_x = -delta_x;

            temp = y2;
            y2 = y1;
            y1 = temp;
            delta_y = -delta_y;
        }
        if (y2 > y1) {              // if y2 > y1, y should be incremented
            incr_same = delta_y << 1;
            d = incr_same - delta_x;
            incr_new = (delta_y - delta_x) << 1;

            y = y1;
            for (x = x1; x <= x2; x++) {
                if (d > 0) {
                    y++;
                    d += incr_new;
                }
                else
                    d += incr_same;
                SET_PIXEL_XY(x, y, color);
            }
        }
        else {
            incr_same = delta_y << 1;
            d = incr_same + delta_x;
            incr_new = (delta_y + delta_x) << 1;

            y = y1;
            for (x = x1; x <= x2; x++) {
                if (d < 0) {
                    y--;
                    d += incr_new;
                }
                else
                    d += incr_same;
                SET_PIXEL_XY(x, y, color);
            }
        }
    }
    else {
        if (y2 < y1) {
            temp = y2;
            y2 = y1;
            y1 = temp;
            delta_y = -delta_y;

            temp = x2;
            x2 = x1;
            x1 = temp;
            delta_x = -delta_x;
        }
        if (x2 > x1) {
            incr_same = delta_x << 1;
            d = incr_same - delta_y;
            incr_new = (delta_x - delta_y) << 1;

            x = x1;
            for (y = y1; y <= y2; y++) {
                if (d > 0) {
                    x++;
                    d += incr_new;
                }
                else
                    d += incr_same;
                SET_PIXEL_XY(x, y, color);
            }
        }
        else {
            incr_same = delta_x << 1;
            d = incr_same + delta_y;
            incr_new = (delta_x + delta_y) << 1;

            x = x1;
            for (y = y1; y <= y2; y++) {
                if (d < 0) {
                    x--;
                    d += incr_new;
                }
                else
                    d += incr_same;
                SET_PIXEL_XY(x, y, color);
            }
        }
    }
}
