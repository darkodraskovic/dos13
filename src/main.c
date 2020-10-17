#include <dpmi.h>
#include <stdio.h>
#include "app.h"
#include "display.h"
#include "draw.h"
#include "pc.h"

void init() {
    clear_color = 23;
}

void update() {
    asm ("nop");
}

void draw() {
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

int main(int argc, char **argv) {
    app_run();
    
    return 0;
}
