#ifndef SPRITE_H
#define SPRITE_H

void draw_sprite(int x, int y, unsigned char sprite[]);
void read_sprite(int x1, int y1, int x2, int y2, unsigned char sprite[],
                 unsigned char transparent_color,
                 unsigned char convert_0_to_color);

#endif /* SPRITE_H */
