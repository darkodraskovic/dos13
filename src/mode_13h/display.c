#include <string.h>
#include <dpmi.h>
#include <sys/nearptr.h>
#include <time.h>
#include <dos.h>

#include "display.h"

#define INPUT_STATUS 0x3DA
#define VRETRACE_BIT 0x08

char frame_buffer[SCREEN_SIZE];
char clear_color = 1;

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

void wait_v_retrace() {
}


void wait_for_retrace() {
  while(inportb( INPUT_STATUS ) & VRETRACE_BIT);
  while(!(inportb( INPUT_STATUS ) & VRETRACE_BIT));
}

void flip_buffer() {
    char *screen = (char *)VIDEO_SEGMENT + __djgpp_conventional_base;

    wait_for_retrace();
    
    // alternative 1
    memcpy(screen, frame_buffer, SCREEN_SIZE);

    // alternative 2
    /* dosmemput(backBuffer, maxScreenOffset, 0xa0000); */

    // alternative 3
    /* for(int i = 0; i < maxScreenOffset; i++) { */
    /*     screen[i] = backBuffer[i]; */
    /* } */
}

void init_display() {
    __djgpp_nearptr_enable();
    set_mode_13h();
}
