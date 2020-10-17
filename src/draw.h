#ifndef DRAW_H
#define DRAW_H

void set_pixel(int x, int y, int color);
int get_pixel(int x, int y);

void line_h (int x1, int x2, int y, unsigned char color);
void line_v(int x, int y1, int y2, unsigned char color);

#endif /* DRAW_H */
