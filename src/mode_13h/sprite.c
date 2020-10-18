#include "display.h"
#include "sprite.h"

// blit sprite[] to framebuffer
void draw_sprite(int x, int y, unsigned char sprite[])
{
    // sprite w/h is stored in first 4 little-endian bytes
    int width = sprite[0] + (sprite[1] << 8);
    int height = sprite[2] + (sprite[3] << 8);
    unsigned char *sprite_color = sprite + 4;
    
    int framebuffer_offset = GET_OFFSET(x, y);
    int x_incr = SCREEN_WIDTH - width; // new row framebuffer offset incr
    
    for (int y_count = 0; y_count < height; y_count++) {
        for (int x_count = 0; x_count < width; x_count++) {
            if (*sprite_color) SET_PIXEL_OFF(framebuffer_offset, *sprite_color); // col idx 0 transparency
            sprite_color++;
            framebuffer_offset++;
        }
        framebuffer_offset += x_incr;
    }    
}

// store framebuffer rect colors in sprite[]
void read_sprite(int x1, int y1, int x2, int y2, unsigned char sprite[],
                 unsigned char transparent_color, unsigned char convert_0_to_color) {
    int width = x2 - x1 + 1;
    int height = y2 - y1 + 1;    
    // store w/h in first 4 little-endian bytes
    sprite[0] = width & 0xFF; // lower byte
    sprite[1] = width >> 8; // higher byte
    sprite[2] = height & 0xFF;
    sprite[3] = height >> 8;
    unsigned char *sprite_color = sprite + 4;

    int framebuffer_offset = GET_OFFSET(x1, y1);
    int x_incr = SCREEN_WIDTH - width; // new row framebuffer offset incr

    unsigned char read_color;
    for (int y_count = 0; y_count < height; y_count++) {
        for (int x_count = 0; x_count < width; x_count++) {
            read_color = GET_PIXEL_OFF(framebuffer_offset++);
            if (read_color == transparent_color)  // if transparent
                *(sprite_color++) = 0;
            else if (read_color)                  // If not 0
                *(sprite_color++) = read_color;
            else                                  // if 0
                *(sprite_color++) = convert_0_to_color;
        }
        framebuffer_offset += x_incr;
    }
}
