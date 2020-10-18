#ifndef PRIMITIVE_H
#define PRIMITIVE_H

void set_pixel(int x, int y, unsigned char color);
unsigned char get_pixel(int x, int y);

void draw_line_h(int x1, int y, int x2, unsigned char color);
void draw_line_v(int x, int y1, int y2, unsigned char color);
void draw_line(int x1, int y1, int x2, int y2, unsigned char color);

void draw_rect_line (int x1, int y1, int x2, int y2, unsigned char color);
void draw_rect(int x1, int y1, int x2, int y2, unsigned char color);

void draw_circle_line(int cx, int cy, int radius, unsigned char color);
void draw_circle(int cx, int cy, int radius, unsigned char color);
    
#endif /* PRIMITIVE_H */
