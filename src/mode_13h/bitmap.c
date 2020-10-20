#include "bitmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fskip(FILE *fp, int num_bytes) {
    for (int i=0; i < num_bytes; i++) fgetc(fp);
}

void load_bitmap(char *file, bitmap *bmp, byte *palette = nullptr) {
    FILE *fp;
    /* long index; */
    int x;

    if ((fp = fopen(file, "rb")) == NULL) {
        printf("Error opening file %s.\n", file);
        exit(1);
    }

    // check if valid bitmap file
    if (fgetc(fp) != 'B' || fgetc(fp) != 'M') {
        fclose(fp);
        printf("%s is not a bitmap file.\n", file);
        exit(1);
    }

    fskip(fp, 16);
    fread(&bmp->width, sizeof(word), 1, fp);
    fskip(fp, 2);
    fread(&bmp->height, sizeof(word), 1, fp);
    fskip(fp, 30);

    if ((bmp->data = (byte *)malloc((word)(bmp->width * bmp->height))) == NULL) {
        fclose(fp);
        printf("Error allocating memory for file %s.\n", file);
        exit(1);
    }

    /* Four bytes define each color: one byte each for blue, green, red, and one
       reserved byte. */
    if (palette) {
        /* The VGA understands color values in the order red, green, blue,
           (reverse of the BMP format) plus the program needs to change the
           palette data form 24-bit to 18-bit (divide each color by four, or
           right-shift by two). */
        for (int index = 0; index < NUM_COLORS; index++) {
            palette[index * 3 + 2] = fgetc(fp) >> 2; // red
            palette[index * 3 + 1] = fgetc(fp) >> 2; // green
            palette[index * 3 + 0] = fgetc(fp) >> 2; // blue
            x = fgetc(fp);                           // reserved byte
        }
    } else {
        fskip(fp, NUM_COLORS * 4);
    }

    // read pixel values
    for (int index = (bmp->height - 1) * bmp->width; index > -1; index -= bmp->width)
        for (x = 0; x < bmp->width; x++)
            bmp->data[(word)index + x] = (byte)fgetc(fp);

    fclose(fp);
}

void draw_bitmap(bitmap *bmp, int x, int y) {
    word screen_offset = GET_OFFSET(x, y);
    word bitmap_offset = 0;

    for(int j=0; j < bmp->height;j++) {
        memcpy(&GET_PIXEL_OFF(screen_offset), &bmp->data[bitmap_offset], bmp->width);
        bitmap_offset += bmp->width;
        screen_offset += SCREEN_WIDTH;
    }
}

void draw_bitmap_transparent(bitmap *bmp, int x, int y)
{
    word screen_offset = GET_OFFSET(x, y);
    word bitmap_offset = 0;
    byte data;

    for(int j = 0; j < bmp->height; j++) {
        for(int i = 0; i < bmp->width; i++, bitmap_offset++) {
            data = bmp->data[bitmap_offset];
            if (data) SET_PIXEL_OFF(screen_offset, data);
            screen_offset++;
        }
        screen_offset += SCREEN_WIDTH - bmp->width;
    }
}


// store framebuffer rect colors in bmp
void screen_to_bitmap(int x1, int y1, int x2, int y2, bitmap* bmp) {
    int width = x2 - x1 + 1;
    int height = y2 - y1 + 1;
    bmp->width = width;
    bmp->height = height;
    unsigned char *data = bmp->data;

    int framebuffer_offset = GET_OFFSET(x1, y1);
    int x_incr = SCREEN_WIDTH - width; // new row framebuffer offset incr

    unsigned char read_color;
    for (int y_count = 0; y_count < height; y_count++) {
        for (int x_count = 0; x_count < width; x_count++) {
            *(data++) = GET_PIXEL_OFF(framebuffer_offset++);
        }
        framebuffer_offset += x_incr;
    }
}
