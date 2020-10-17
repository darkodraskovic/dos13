#ifndef DISPLAY_H
#define DISPLAY_H

#define VIDEO_SEGMENT 0xa0000
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200
#define SCREEN_SIZE 64000

void set_mode_13h();
void set_text_mode();
void clear_buffer();
void flip_buffer();

void init_display();

extern char frame_buffer[SCREEN_SIZE];
extern char clear_color;

#endif /* DISPLAY_H */
