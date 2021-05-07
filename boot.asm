[org 0x7c00]

;Main_Routine

mov bp, 0x7c00
mov sp, bp

mov bx, BootString
call PrintString

jmp $

;Prologue-Extra_Routines_and_Variables

PrintString:
	mov ah, 0x0e
	.Loop:
	cmp [bx], byte 0
	je .Exit
		mov al, [bx]
		int 0x10
		inc bx
		jmp .Loop
	.Exit:
	ret

BootString:
	db 'BootLoader Has Been Started , Fun Begins :D',0

times 510-($-$$) db 0

dw 0xaa55