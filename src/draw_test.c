#include "mode_13h/display.h"
#include "mode_13h/primitive.h"
#include "mode_13h/bitmap.h"

/* width 5, height 5 */
unsigned char ball_sprite[] = {
      0,  11,  11,  11,   0,
     11,  14,   3,   3,   9,
     11,   3,   3,   3,   9,
     11,   3,   3,   3,   9,
      0,   9,   9,   9,   0
};

/* width 21, height 6 */
unsigned char car_sprite[] = {
    0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 4, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0,
    0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0
};

unsigned char data_buffer[29];

bitmap ball_bitmap = {.width = 5, .height = 5, .data = ball_sprite};
bitmap car_bitmap = {
    .width = 21, .height = 6,
    .data = car_sprite
};

bitmap data_bitmap = {
    .data = data_buffer
};

void init_draw() {
    int x = 30; int y = 45;
    draw_bitmap_transparent(&car_bitmap, x, y);
    draw_bitmap(&ball_bitmap, x, y);
    screen_to_bitmap(x, y, x + 4, y + 4, &data_bitmap);
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
    /* draw_bitmap(&ball_bitmap, 10, 10); */
    draw_bitmap_transparent(&data_bitmap, 10, 10);
    
    static int x = 0;
    x += 1;
    draw_bitmap_transparent(&car_bitmap, x, 40);
}
