#include "app.h"
#include "display.h"

void draw() {
    for (int x = 0; x <= 255; x++)
        for (int y = 0; y <= 50; y++)
            set_pixel(x, y, x);
}

int main(int argc, char **argv) {
    app_run();
    
    return 0;
}
