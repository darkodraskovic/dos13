#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dpmi.h>
#include <pc.h>
#include <dos.h>

#include "mode_13h/app.h"
#include "mode_13h/bitmap.h"
#include "mode_13h/display.h"
#include "draw_test.c"
#include "assembler_test.c"


// ================================================================

byte palette[PALETTE_SIZE];

bitmap b;

void init() {
    clear_color = 0;
    clear_buffer();

    init_draw();

    char file[] = "art11.bmp";
    
    load_bitmap(file, &b, palette);
    set_palette(palette);
}

void update() {
    /* asm ("nop"); */
}

void draw() {
    draw_primitives();
    draw_sprites();
    /* draw_bitmap(&b, 40, 30); */
    /* draw_bitmap(&b, 20, 10); */
    draw_bitmap_transparent(&b, 20, 10);
    draw_bitmap_transparent(&b, 35, 20);
}

int main(int argc, char **argv) {
    app_run();

    /* printf("%d\n", add_four(12)); */
    /* printf("AddFour(4) = %i\n", AddFour(8)); */

    /* /\* print_A(); *\/ */
    
    /* print_char('R'); */

    return 0;
}
