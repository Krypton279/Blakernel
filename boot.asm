[org 0x7c00]

;Disk_Read_Stuff

PROGRAM_SPACE equ 0x7e00
mov [BOOT_DISK] , dl

;Main_Routine

mov bp, 0x7c00
mov sp, bp

mov bx, BootString
call PrintString


;Disk_Read
mov bx, DiskReadString
call PrintString

call ReadDisk

jmp PROGRAM_SPACE



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

ReadDisk:
	mov ah, 0x02
	mov bx, PROGRAM_SPACE
	mov al, 4
	mov dl, [BOOT_DISK]
	mov ch, 0x00
	mov dh, 0x00
	mov cl, 0x02

	int 0x13

	jc DiskReadFailed
	mov bx, DiskReadSuccessString
	call PrintString

	ret

DiskReadFailed:
	mov bx, DiskReadErrorString
	call PrintString
	jmp $


BootString:
	db 'BootLoader Has Been Started , Fun Begins :D',0xA,0xD,0

DiskReadString:
	db 'Reading Disk Space Now ...',0xA,0xD,0

DiskReadErrorString:
	db 'Disk Read Failed ...',0xA,0xD,0

DiskReadSuccessString:
	db 'Disk Read Success',0xA,0xD,0

BOOT_DISK:
	db 0

times 510-($-$$) db 0

dw 0xaa55