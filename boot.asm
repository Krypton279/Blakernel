[org 0x7c00]

mov bx, BootString
call PrintString
call ReadSectors

jmp 0x7e00

BootString:
	db 'Bootloader Has been Started.',0xA,0xD,0

BootDisk:
	db 0


PrintString:
	push ax
	push bx

	mov ah, 0x0e
	.Loop:
	cmp [bx], byte 0
	je .Exit
		mov al, [bx]
		int 0x10
		inc bx
		jmp .Loop
	.Exit:

	pop ax
	pop bx
	ret

ReadSectors:
	mov ah, 0x02
	mov al, 32
	mov ch, 0x00
	mov cl, 0x02
	mov dh, 0x00
	mov dl, [BootDisk]
	mov bx, 0x7e00

	int 0x13

	jc ReadSectorError
	ret

ReadSectorError:
	mov bx, ReadError
	call PrintString
	jmp $

ReadError:
	db 'Read Failed',0xA,0xD,0

times 510-($-$$) db 0

dw 0xaa55