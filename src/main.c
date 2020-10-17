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
    
    /* for (int y = 0; y < 151; y +=2) line_h(10, y, 100, y); */
    /* for (int x = 0; x < 151; x += 2) line_v(x, 10, 100, x); */

    line(10, 150, 200, 190, 1);
}

int main(int argc, char **argv) {
    app_run();
    
    return 0;
}
