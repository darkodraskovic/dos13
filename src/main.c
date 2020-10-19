#include <stdio.h>
#include <dpmi.h>
#include <pc.h>

#include "mode_13h/app.h"
#include "draw_test.c"
#include "assembler_test.c"

// ================================================================

void init() {
    clear_color = 23;
    clear_buffer();

    init_draw();
}

void update() {
    /* asm ("nop"); */
}

void draw() {
    /* draw_primitives(); */
    /* draw_sprites(); */
}

int main(int argc, char **argv) {
    /* app_run(); */

    /* printf("%d\n", add_four(12)); */
    printf("AddFour(4) = %i\n", AddFour(8));

    /* /\* print_A(); *\/ */
    
    /* print_char('R'); */
    
    return 0;
}
