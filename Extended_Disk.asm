[org 0x7e00]

mov bx, ExtendedMessage
call PrintString

call EnterProtectedMode

jmp $

[bits 16]

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

ExtendedMessage:
	db 'Now Entering Extended Memory',0xA,0xD,0

ExtendedSpaceSuccessString:
	db 'Entering Extended Space , Finally Out of 512 bytes :D',0xA,0xD,0

EnterProtectedModeString:
	db 'Entering Protected Mode , finally in 32-bit :D',0xA,0xD,0

PageTableEntry equ 0x1000

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
	call DetectCPUID
	call DetectLongMode
	call SetupPaging
	%include "new_code.asm"
	db 0xea
	dd NewCode
	dw codeseg 

;64

[bits 32]

SetupPaging:
	mov edi, PageTableEntry
	mov cr3, edi
	mov dword [edi], 0x2003
	add edi, 0x1000
	mov dword [edi], 0x3003
	add edi, 0x1000
	mov dword [edi], 0x4003
	add edi, 0x1000

	mov ebx, 0x00000003
	mov ecx, 512

	.Entries:
		mov dword [edi], ebx
		add ebx, 0x1000
		add edi, 8
		loop .Entries

	mov eax, cr4
	or eax, 1 << 5
	mov cr4, eax

	mov ecx, 0xC0000080
	rdmsr
	or eax, 1 << 8
	wrmsr

	mov eax, cr0
	or eax, 1 << 31
	mov cr0, eax
	call EditGDT
	ret 

DetectCPUID:
	pushfd
	pop eax
	mov ecx, eax
	xor eax, 1 << 21
	push eax
	popfd
	pushfd
	pop eax
	push ecx
	popfd
	xor eax,ecx
	jz NoCPUID
	ret

NoCPUID:
	hlt ;No_CPUID_Support

DetectLongMode:
	mov eax, 0x80000001
	cpuid
	test edx, 1 << 29
	jz NoLongMode
	ret

NoLongMode:
	hlt ;No_Long_Mode_Support


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
		dq gdt_nulldesc

codeseg equ gdt_codedesc - gdt_nulldesc
dataseg equ gdt_datadesc - gdt_nulldesc

[bits 32]

EditGDT:
	mov [gdt_codedesc + 6], byte 10101111b
	mov [gdt_datadesc + 6], byte 10101111b
	ret

[bits 16]

times 2048-($-$$) db 0