#include <time.h>
#include <dos.h>

#include "display.h"
#include "app.h"

void draw();

const float sec_per_update = 1.f / 60.f;
float previous_frame = 0;

void app_run() {
    init_display();
    init();
    
    while(true) {
        update();
        
        clear_buffer();
        
        draw();
        
        flip_buffer();
    }
    /* printf("%f second have elapsed\n", ((double)uclock() / UCLOCKS_PER_SEC)); */
}
