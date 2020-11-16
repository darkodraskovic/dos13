bits 32

global _hello

segment .text

_hello:
        ; Write the "A" to the screen, using Interrupt 10 hex, Service 0A hex:
;; mov ax, 0A46h                        ; Interrupt service number 0A hex
        mov ah, 0Ah                        ; Interrupt service number 0A hex
        mov al, [char]                         ; 65 dec is the ASCII code for "A"
        mov bx, 0                          ; Screen page is 0 (default)
        mov cx, 1                          ; Write one character only
        int 10h                            ; Call the interrupt service and
        ;  write the "A" to the screen

        ; Exit the program:
        mov ax, 4C00h                      ; Interrupt service number 4C hex,
        ;  return error code 0
        int 21h                            ; Call interrupt service to end the
        ;  program        

segment .data
        char db 'e'
