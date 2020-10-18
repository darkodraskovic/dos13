#include <stdlib.h>
#include "display.h"
#include "primitive.h"

void set_pixel(int x, int y, unsigned char color) {
    SET_PIXEL_XY(x, y, color);
}

unsigned char get_pixel(int x, int y) {
    return GET_PIXEL_XY(x, y);
}

void draw_line_h(int x1, int y, int x2, unsigned char color) {
    int offset = GET_OFFSET(x1, y);
    for (int x = x1; x <= x2; x++) SET_PIXEL_OFF(offset++, color);
}

void draw_line_v(int x, int y1, int y2, unsigned char color) {
    int offset = GET_OFFSET(x, y1);
    for (int y = y1; y <= y2; y++, offset += SCREEN_WIDTH) SET_PIXEL_OFF(offset, color);
}

void draw_rect_line(int x1, int y1, int x2, int y2, unsigned char color) {
    int x, y, tmp;

    // horizontal lines
    int offset_1 = GET_OFFSET(x1, y1);
    int offset_2 = GET_OFFSET(x1, y2);
    for (x = x1; x <= x2; x++) {
        SET_PIXEL_OFF(offset_1++, color);
        SET_PIXEL_OFF(offset_2++, color);
    }

    // vertical lines
    offset_1 = GET_OFFSET(x1, y1);
    offset_2 = GET_OFFSET(x2, y1);
    for (y = y1; y <= y2; y++) {
        SET_PIXEL_OFF(offset_1, color);
        SET_PIXEL_OFF(offset_2, color);
        offset_1 += SCREEN_WIDTH;
        offset_2 += SCREEN_WIDTH;
    }
}

void draw_rect(int x1, int y1, int x2, int y2, unsigned char color) {
    int x_incr, x, y;

    int offset = GET_OFFSET(x1, y1);
    x_incr = SCREEN_WIDTH - (x2 - x1) - 1;

    for (y = y1; y <= y2; y++) {
        for (x = x1; x <= x2; x++)
            SET_PIXEL_OFF(offset++, color);
        offset += x_incr;
    }
}

void draw_line(int x1, int y1, int x2, int y2, unsigned char color) {
    int x, y, delta_x, delta_y, d, incr_same, incr_new, temp;

    delta_x = x2 - x1;
    delta_y = y2 - y1;

    if (delta_x == 0) {
        draw_line_v (x1, y1, y2, color);
        return;
    } else if (delta_y == 0) {
        draw_line_h (x1, y1, x2, color);
        return;
    }

    if (abs(delta_x) >= abs(delta_y)) {             // if x is the major axis
        if (x2 < x1) {                              // if coordinates are out of order
            temp = x2;
            x2 = x1;
            x1 = temp;
            delta_x = -delta_x;

            temp = y2;
            y2 = y1;
            y1 = temp;
            delta_y = -delta_y;
        }
        if (y2 > y1) {                              // if y2 > y1, y should be incremented
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

void draw_circle_line(int cx, int cy, int radius, unsigned char color) {
    int x, y, d, delta_e, delta_se;

    x = -1;
    y = radius;
    d = 1 - radius;
    delta_e = -1;
    delta_se = (-radius << 1) + 3;

    while (y > x) {
        delta_e += 2;
        x++;

        if (d < 0) {
            d += delta_e;
            delta_se += 2;
        } else {
            d += delta_se;
            delta_se += 4;
            y--;
        }

        SET_PIXEL_XY(cx + x, cy + y, color);
        SET_PIXEL_XY(cx + y, cy + x, color);
        SET_PIXEL_XY(cx + y, cy - x, color);
        SET_PIXEL_XY(cx + x, cy - y, color);

        SET_PIXEL_XY(cx - x, cy - y, color);
        SET_PIXEL_XY(cx - y, cy - x, color);
        SET_PIXEL_XY(cx - y, cy + x, color);
        SET_PIXEL_XY(cx - x, cy + y, color);
    }
}

void draw_circle(int cx, int cy, int radius, unsigned char color) {
    int x, y, d, delta_e, delta_se;

    x = -1;
    y = radius;
    d = 1 - radius;
    delta_e = -1;
    delta_se = (-radius << 1) + 3;

    while (y > x) {
        delta_e += 2;
        x++;

        if (d < 0) {
            d += delta_e;
            delta_se += 2;
        } else {
            d += delta_se;
            delta_se += 4;
            y--;
        }

        draw_line_h(cx - x, cy + y, cx + x, color);
        draw_line_h(cx - y, cy - x, cx + y, color);
        draw_line_h(cx - y, cy + x, cx + y, color);
        draw_line_h(cx - x, cy - y, cx + x, color);
    }
}
