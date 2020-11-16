bits 32

global _hello2

section .data
        my_char db '*'
        bad_joke db "Did you hear about the thieves "
        db "who broke into the music store "
        db "and", 13, 10, "got away with "
        db "the lute?$"
        
section .text

_hello2:
        ; output a character
        ; mov dl, [my_char]
        ; mov ah, 02h             ; Service 02h ("Character Output on Screen")
        ; int 21h

        ; DS:DX -> '$'-terminated string
        mov ah, 09h
        mov edx, bad_joke
        int 21h

        ; ret
        ; mov ax, 04C00h
        ; int 21h
