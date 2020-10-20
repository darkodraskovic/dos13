#include <string.h>
#include <dpmi.h>
#include <sys/nearptr.h>
#include <time.h>
#include <dos.h>

#include "display.h"

#define INPUT_STATUS 0x03da
#define VRETRACE 0x08
#define PALETTE_INDEX 0x03c8
#define PALETTE_DATA 0x03c9

char frame_buffer[SCREEN_SIZE];
char clear_color = 0;

void set_mode_13h()
{
    __dpmi_regs r;

    r.x.ax = 0x13; //19 
    __dpmi_int(0x10, &r);

}

void set_text_mode()
{
    __dpmi_regs r;

    r.x.ax = 3;
    __dpmi_int(0x10, &r);
}

void clear_buffer() {
    char *screen = (char *)VIDEO_SEGMENT + __djgpp_conventional_base;
    memset(frame_buffer, clear_color, SCREEN_SIZE);
}

void set_palette(byte *palette) {
    outp(PALETTE_INDEX,0);
    for(int i=0; i < PALETTE_SIZE; i++) outp(PALETTE_DATA, palette[i]);
}

void wait_vretrace() {
    // The VGA refreshes the screen 70 times a second, or 70hz.
    // function is called twice -> the loop cycles at 35 times a second
    
    /* wait until done with vertical retrace */
    while  ((inp(INPUT_STATUS) & VRETRACE));
    /* wait until done refreshing */
    while (!(inp(INPUT_STATUS) & VRETRACE));
}

void flip_buffer() {
    char *screen = (char *)VIDEO_SEGMENT + __djgpp_conventional_base;

    wait_vretrace();
    
    memcpy(screen, frame_buffer, SCREEN_SIZE);
}

void init_display() {
    __djgpp_nearptr_enable();
    set_mode_13h();
}
