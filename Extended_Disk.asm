[org 0x7e00]

;Main_Control_Line

mov bx, ExtendedSpaceSuccessString
call PrintString

call EnterProtectedMode

jmp $


;Prologue

ExtendedSpaceSuccessString:
	db 'Entering Extended Space , Finally Out of 512 bytes :D',0xA,0xD,0

EnterProtectedModeString:
	db 'Entering Protected Mode , finally in 32-bit :D',0xA,0xD,0

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

EnterProtectedMode:
	mov bx, EnterProtectedModeString
	call PrintString
	cli
	call EnableA20
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp codeseg:StartProtectedMode

EnableA20:
	in al, 0x92
	or al, 2
	out 0x92, al
	ret

[bits 32]

StartProtectedMode:
	
	mov ax, dataseg
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov [0xb8000], byte 'P'
	mov [0xb8002], byte 'R'
	mov [0xb8004], byte 'O'
	mov [0xb8006], byte 'T'
	mov [0xb8008], byte '-'
	mov [0xb800a], byte 'M'
	mov [0xb800c], byte 'O'
	mov [0xb800e], byte 'D'
	mov [0xb8010], byte 'E'
	mov [0xb8012], byte ' '
	mov [0xb8014], byte ' '
	mov [0xb8016], byte ' '
	jmp $

;GDT_VARIABLES

gdt_nulldesc:
	dd 0
	dd 0
gdt_codedesc:
	dw 0xFFFF
	dw 0x0000
	db 0x00
	db 10011010b
	db 11001111b
	db 0x00
gdt_datadesc:
	dw 0xFFFF
	dw 0x0000
	db 0x00
	db 10010010b
	db 11001111b
	db 0x00
gdt_end:

gdt_descriptor:
	gdt_size:
		dw gdt_end - gdt_nulldesc - 1
		dd gdt_nulldesc

codeseg equ gdt_codedesc - gdt_nulldesc
dataseg equ gdt_datadesc - gdt_nulldesc

times 2048-($-$$) db 0