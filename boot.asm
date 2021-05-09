[org 0x7c00]

PROGRAM_SPACE equ 0x7e00

mov [BOOT_DISK], dl

mov bp, 0x7c00
mov sp, bp

mov bx, BootString
call PrintString

call ReadDisk

jmp PROGRAM_SPACE

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

ReadDisk:
	mov ah, 0x02
	mov bx, PROGRAM_SPACE
	mov al, 4
	mov dl, [BOOT_DISK]
	mov ch, 0x00
	mov dh, 0x00
	mov cl, 0x02

	int 0x13
	ret

BootString:
	db 'Bootloader has been started',0xA,0xD,0

BOOT_DISK:
	db 0

times 510-($-$$) db 0

dw 0xaa55