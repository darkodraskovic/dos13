#include "mode_13h/display.h"
#include "mode_13h/primitive.h"
#include "mode_13h/sprite.h"

unsigned char ball_sprite[] = {5, 0, 5, 0,        /* width 5, height 5 */
      0,  11,  11,  11,   0,
     11,  14,   3,   3,   9,
     11,   3,   3,   3,   9,
     11,   3,   3,   3,   9,
      0,   9,   9,   9,   0
};

unsigned char car_sprite[] = {21, 0, 6, 0,
    0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 4, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0,
    0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0
};

unsigned char sprite_buffer[29];

void init_draw() {
    int x = 30; int y = 45;
    draw_sprite(x, y, ball_sprite);
    read_sprite(x, y, x + 4, y + 4, sprite_buffer, clear_color, 1);    
}

void draw_primitives() {
    /* for (int x = 0; x <= 150; x++) */
    /*     for (int y = 0; y <= 150; y++) */
    /*         set_pixel(x, y, x); */
    
    for (int y = 0; y < 151; y +=2) draw_line_h(10, y, 100, y);
    for (int x = 0; x < 151; x += 2) draw_line_v(x, 10, 100, x);

    draw_line(10, 155, 190, 190, 1);

    draw_rect_line(200, 20, 260, 40, 2);

    draw_rect(200, 150, 260, 190, 3);

    draw_circle_line(200, 30, 30, 3);
    draw_circle(200, 100, 30, 3);
}

void draw_sprites() {
    /* draw_sprite(10, 10, ball_sprite); */
    draw_sprite(10, 10, sprite_buffer);
    
    static int x = 0;
    x += 1;
    draw_sprite(x, 40, car_sprite);
}
