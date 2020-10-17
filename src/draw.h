#ifndef DRAW_H
#define DRAW_H

void set_pixel(int x, int y, unsigned char color);
unsigned char get_pixel(int x, int y);

void line_h (int x1, int y, int x2, unsigned char color);
void line_v(int x, int y1, int y2, unsigned char color);
void line(int x1, int y1, int x2, int y2, unsigned char color);

void box (int x1, int y1, int x2, int y2, unsigned char color);
#endif /* DRAW_H */
