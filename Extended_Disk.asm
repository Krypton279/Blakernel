[org 0x7e00]

mov bx, ExtendedSpaceSuccessString
call PrintString

jmp $


ExtendedSpaceSuccessString:
	db 'Entering Extended Space , Finally Out of 512 bytes :D',0xA,0xD,0

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

times 2048-($-$$) db 0