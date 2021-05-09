[org 0x7e00]
[bits 16]

mov bx, Sector2
call PrintString
call StartProtectedMode

mov ax,10h
mov ds,ax
mov es,ax
mov fs,ax
mov gs,ax
mov ss,ax
jmp codeseg:EnterProtectedMode

Sector2:
	db 'Entering Sector 2+.',0xA,0xD,0

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

StartProtectedMode:
	cli
	call EnableA20
	lgdt [gdt_descriptor]
	mov eax,cr0
	or eax,1
	mov cr0,eax
	ret

EnableA20:
	in al, 0x92
	or al, 2
	out 0x92, al
	ret

;GDT-Variables

gdt_nulldesc:
	dd 0
	dd 0	
gdt_codedesc:
	dw 0xFFFF			; Limit
	dw 0x0000			; Base (low)
	db 0x00				; Base (medium)
	db 10011010b		; Flags
	db 11001111b		; Flags + Upper Limit
	db 0x00				; Base (high)
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
		dq gdt_nulldesc

codeseg equ gdt_codedesc - gdt_nulldesc
dataseg equ gdt_datadesc - gdt_nulldesc

;32-bit

[bits 32]

EnterProtectedMode:
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
	mov [0xb8018], byte ' '
	mov [0xb802a], byte ' '
	mov [0xb802c], byte '.'
	mov eax, 1
	jmp $

times 16384-($-$$) db 0