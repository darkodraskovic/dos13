[BITS 32]

[GLOBAL _AddFour]

[SECTION .text]

; ---------------------------------------------------------------------------
; Prototype: unsigned int AddFour(unsigned int x);
; Returns: x + 4
; ---------------------------------------------------------------------------

x_AddFour       equ 8

_AddFour:
	push ebp
	mov ebp, esp
	       
	mov eax, [ebp + x_AddFour]        
	add eax, 4

	mov esp, ebp
	pop ebp
	ret
